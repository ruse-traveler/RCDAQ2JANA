#!/usr/bin/env ruby
# =============================================================================
# @file   RunGenerateRandomHits.rb
# @author Derek Anderson
# @date   04.26.2025
# -----------------------------------------------------------------------------
# An easy script to run the `GenerateRandomHits.cxx` macro.
# =============================================================================

require 'optparse'
require 'ostruct'

# create an open struct to hold options
pars = OpenStruct.new

# set parameters (can also be set from
# command line)
pars.file     = "test_stage1_set.root"
pars.collect  = "HcalBarrelRandomRawHits"
pars.nframes  = 100
pars.nhits    = 10
pars.seed     = 0
pars.mean     = 40
pars.progress = true

# now parse any provided command line options 
OptionParser.new do |opt|
  opt.on('-f FILE') { |val| pars.file     = val }
  opt.on('-c COLL') { |val| pars.collect  = val }
  opt.on('-r FRAM') { |val| pars.nframes  = val }
  opt.on('-h HITS') { |val| pars.nhits    = val }
  opt.on('-s SEED') { |val| pars.seed     = val }
  opt.on('-m MEAN') { |val| pars.mean     = val }
  opt.on('-p PROG') { |val| pars.progress = val } 
end.parse!


# bundle options and form command
bundle = <<STR
  {\
    .out_file    = "#{pars.file}",\
    .out_collect = "#{pars.collect}",\
    .nframes     = #{pars.nframes},\
    .nhits       = #{pars.nhits},\
    .seed        = #{pars.seed},\
    .mean        = #{pars.mean},\
    .progress    = #{pars.progress}\
  }
STR
command = "root -b -q \'GenerateRandomHits.cxx(#{bundle.gsub(/\s+/, "")})\'"

# run macro
exec(command);

# end =========================================================================

