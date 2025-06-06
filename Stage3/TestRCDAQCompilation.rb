#!/usr/bin/env ruby
# =============================================================================
# @file   TestRCDAQCompilation.rb
# @author Derek Anderson
# @date   06.05.2025
# -----------------------------------------------------------------------------
# An easy script to run the various stages of
# installing RCDAQ, the event libraries, and
# pmonitor in the eic-shell.
#
# This is the 3rd stage towards the development
# of an RCDAQ2JANA prototype.
# =============================================================================

system("./get-rcdaq")
system("./switch-to-epic-branch")
system("./apply-patches")
system(". ./build-rcdaq")
system(". ./set-environment")

# end =========================================================================
