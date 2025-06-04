#!/usr/bin/env ruby
# =============================================================================
# @file   RunProcessRandomHits.rb
# @author Derek Anderson
# @date   06.04.2025
# -----------------------------------------------------------------------------
# An easy script to run the `ProcessRandomHits` plugin
# in EICrecon.
# =============================================================================

require 'optparse'
require 'ostruct'

# create an open struct to hold options
pars = OpenStruct.new

# set parameters (can also be set from
# command line)
pars.in  = "../Stage1/test_stage1_set.root"
pars.out = "test_stage2_set.root"

# now parse any provided command line options 
OptionParser.new do |opt|
  opt.on('-i IN')  { |val| pars.in  = val }
  opt.on('-o OUT') { |val| pars.out = val }
end.parse!

# output collections from EICrecon
collections = [
  "EventHeader",
  "HcalBarrelRandomRawHits",
  "HcalBarrelRandomRecHits",
  "HcalBarrelRandomMergedHits",
  "HcalBarrelRandomHitClusters"
].compact.reject(&:empty?).join(',')

# plugins to run in EICrecon
plugins = [
  "ProcessRandomHits"
].compact.reject(&:empty?).join(',')

# and now run eicrecon 
exec("eicrecon -Pplugins=#{plugins} -Ppodio:output_collections=#{collections} -Ppodio:output_file=#{pars.out} #{pars.in}")

# end =========================================================================
