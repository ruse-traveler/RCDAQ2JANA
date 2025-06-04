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
// dd4hep libraries
#include <DD4hep/Detector.h>
#include <DD4hep/IDDescriptor.h>
// root libraries
#include <TDatime.h>
#include <TRandom3.h>
// c++ utilities
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>



// ============================================================================
//! Parameters for stage 1 of development
// ============================================================================
namespace Stage1 {

  // ----------------------------------------------------------------------------
  //! Struct to consolidate user options
  // ----------------------------------------------------------------------------
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
    0,
    true
  };

  // --------------------------------------------------------------------------
  //! Struct to consolidate routine constants
  // --------------------------------------------------------------------------
  struct Constants {
    uint32_t nhits;  //!< number of hits per frame to generate
    float    mean;   //!< mean hit "amplitude" in [ADC]
  } DefaultConsts = {
    10,
    40.
  };

}  // end Stage1 namespace



// ============================================================================
//! Macro to run stage 1: generate random raw calorimeter hits
// ============================================================================
void GenerateRandomHits(
  const Stage1::Options& opt = Stage1::DefaultOptions,
  const Stage1::Constants& con = Stage1::DefaultConsts 
) {

  // announce start
  std::cout << "\n Beginning stage 1 test: generating random raw hits..." << std::endl;

  // initialize interfaces ----------------------------------------------------

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
            << "      seed = " << opt.seed
            << std::endl;

  // initialize detector interface
  auto detector = dd4hep::Detector::make_unique("");

  // set geometry to compact specified by environment
  try {
    auto* dconfig = std::getenv("DETECTOR_CONFIG");
    auto* dpath   = std::getenv("DETECTOR_PATH");
    if (dconfig && dpath) {
      detector -> fromCompact(
        std::string(dpath) + "/" + std::string(dconfig) + ".xml"
      );
    } else {
      std::cerr << "PANIC: check that DETECTOR_CONFIG and DETECTOR_PATH are set!\n" << std::endl;
      exit(-1);
    }
  } catch(std::runtime_error& err) {
    std::cerr << "PANIC: error initializing detector!\n" << std::endl;
    exit(-1);
  }
  std::cout << "    Initialized detector." << std::endl;

  // make sure BHCal readout is available
  dd4hep::IDDescriptor descriptor;
  try {
    descriptor = detector -> readout("HcalBarrelHits").idSpec();
  } catch (const std::runtime_error &err) {
    std::cerr << "PANIC: readout class is not in output!\n" << std::endl;;
    exit(-1);
  }
  std::cout << "    Initialized ID descriptor." << std::endl;

  // generate random hits -----------------------------------------------------

  // announce loop start
  std::cout << "    Starting frame loop: " << opt.nframes << " to generate." << std::endl;

  // hit loop
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

    // create frame & hit collection
    auto frame = podio::Frame();
    auto hits  = std::make_unique<edm4hep::RawCalorimeterHitCollection>();

    // now generate nhits random hits per frame
    for (std::size_t ihit = 0; ihit < con.nhits; ++ihit) {

      // get random values
      int32_t  ieta = rando -> Uniform(0, 24);
      int32_t  iphi = rando -> Uniform(0, 320);
      uint32_t amp  = rando -> Poisson(con.mean);

      // encode hit position into a cell id
      int32_t cell = descriptor.encode(
        {
          {"system", 111},
          {"eta", ieta},
          {"phi", iphi}
        }
      );

      // create hit (ignore time stamp)
      auto hit = hits -> create();
      hit.setCellID(cell);
      hit.setAmplitude(amp);

    }  // end hit loop

    // place hits in frame and write out
    //   - n.b. frame category is "events" for compatibility
    //     with EICrecon until we go to frames-in-events-out
    frame.put(std::move(hits), opt.out_collect);
    writer.writeFrame(frame, "events");

  }  // end frame loop
  std::cout << "    Finished frame loop!" << std::endl;

  // close interfaces ---------------------------------------------------------

  // close writer & announce end
  writer.finish();
  std::cout << "    Completed writing.\n"
            << "  Finished stage 1 test!\n"
            << std::endl;

  // exit
  return;

}

#endif

/// end =======================================================================
