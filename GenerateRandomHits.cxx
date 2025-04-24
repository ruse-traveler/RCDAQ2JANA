/// ==========================================================================
/*! \file   GenerateRandomHits.cxx
 *  \author Derek Anderson
 *  \date   04.24.2025
 *
 *  A short ROOT+PODIO macro to randomly generate
 *  edm4hep::RawCalorimeterHit objects and save
 *  them to an output.
 *
 *  This is the 1st stage of development towards
 *  a RCDAQ2JANA prototype.
 */
/// ==========================================================================

#ifndef RCDAQ2JANA_GENERATERANDOMHITS_CXX
#define RCDAQ2JANA_GENERATERANDOMHITS_CXX

// edm4hep types
#include <edm4hep/RawCalorimeterHitCollection.h>
// podio libraries
#include <podio/CollectionBase.h>
#include <podio/Frame.h>
#include <podio/ROOTWriter.h>
// root libraries
#include <TDatime.h>
#include <TRandom3.h>
// c++ utilities
#include <iostream>
#include <string>



// ============================================================================
//! Struct to consolidate user options
// ============================================================================
struct Options {
  std::string out_file;     //!< output file name
  std::string out_collect;  //!< output collection (branch) name
  uint64_t    nframes;      //!< number of frames to generate
  uint16_t    seed;         //!< seed mode (0 = fixed seed, 1 = date/time)
  bool        progress;     //!< turn on/off frame loop progress
} DefaultOptions = {
  "test_stage1.root",
  "HcalBarrelRandomRawHits",
  100,
  0
};



// ============================================================================
//! Macro to generate random raw calorimeter hits
// ============================================================================
void GenerateRandomHits(const Options& opt = DefaultOptions) {

  // announce start
  std::cout << "\n Beginning stage 1 test: generating random raw hits..." << std::endl;

  // open output file
  podio::ROOTWriter writer( opt.out_file );
  std::cout << "    Opened ROOT writer.\n"
            << "      out file = " << opt.out_file
            << std::endl;

  // initialize rng
  TDatime*  time  = new TDatime();
  TRandom3* rando = new TRandom3();

  // set appropriate seed
  switch (opt.seed) {
    case 0:
      rando -> SetSeed(opt.seed);
      break;
    case 1:
      [[fallthrough]];
    default:
      rando -> SetSeed(time -> Get());
      break;
  }
  std::cout << "    Initialized RNG.\n"
            << "      seed = " << opt.seed << "\n"
            << "    Starting frame loop: " << opt.nframes << " to generate."
            << std::endl;

  // begin frame loop
  for (uint64_t iframe = 0; iframe < opt.nframes; ++iframe) {

    // print progess if need be
    if (opt.progress) {
      const uint64_t iprog = iframe + 1;
      if (iprog == opt.nframes) {
        std::cout << "      Processing frame " << iprog << "/" << opt.nframes << "..." << std::endl;
      } else {
        std::cout << "      Processing frame " << iprog << "/" << opt.nframes << "...\r" << flush;
      }
    }

    /* TODO
     *   - create(?) hit collection
     *   - populate it with some randomly generated hits
     *   - write frame
     */ 


  }  // end frame loop
  std::cout << "    Finished frame loop!

  // close writer
  writer -> finish();
  std::cout << "    Completed writing." << std::endl;

  // announce end and exit
  std::cout << "  Finished stage 1 test!" << std::endl;
  return;

}

#endif

/// end =======================================================================
