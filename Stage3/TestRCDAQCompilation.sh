#!/bin/bash
# =============================================================================
# @file   TestRCDAQCompilation.sh
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

# set your installation path
ONLINE_MAIN=~/install
if [ ! -z "$1" ] ; then
  ONLINE_MAIN=$1
fi

. ./unzip-input
. ./get-rcdaq
. ./switch-to-epic-branch
. ./apply-patches
. ./build-rcdaq $ONLINE_MAIN
. ./set-environment

# end =========================================================================
