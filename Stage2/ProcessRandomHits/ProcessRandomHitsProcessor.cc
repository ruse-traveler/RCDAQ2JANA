/// ===========================================================================
/*! \file    ProcessRandomHitsProcessor.cc
 *  \authors Derek Anderson
 *  \date    06.04.2025
 *
 *  A small EICrecon plugin to "reconstruct" and
 *  cluster random hits generated in development
 *  stage 1.
 */
/// ===========================================================================

// plugin definition
#include "ProcessRandomHitsProcessor.h"

// general dependencies
#include <edm4eic/EDM4eicVersion.h>
#include <Evaluator/DD4hepUnits.h>
#include <JANA/JApplication.h>
#include <memory>

// eicrecon-specific components
#include <extensions/jana/JOmniFactoryGeneratorT.h>
#include <factories/calorimetry/CalorimeterClusterRecoCoG_factory.h>
#include <factories/calorimetry/CalorimeterClusterShape_factory.h>
#include <factories/calorimetry/CalorimeterHitReco_factory.h>
#include <factories/calorimetry/CalorimeterHitsMerger_factory.h>
#include <factories/calorimetry/CalorimeterIslandCluster_factory.h>
#include <services/rootfile/RootFile_service.h>



// the following makes this a JANA plugin and adds relevant factories
extern "C" {

  // --------------------------------------------------------------------------
  //! Initialize plugin and add to app
  // --------------------------------------------------------------------------
  /*! This initializes the plugins and wires in
   *  the following factories:
   *    - HcalBarrelRandomRecHits
   *    - HcalBarrelRandomHitIslandProtoClusters
   *    - HcalBarrelRandomHitClustersWithoutShapes
   *    - HcalBarrelRandomHitClusters
   */ 
  void InitPlugin(JApplication *app) {

    // supress eicrecon namespace
    using namespace eicrecon;

    // initialize, add to app 
    InitJANAPlugin(app);
    app -> Add(new ProcessRandomHitsProcessor);

    // reconstruct random hits
    app -> Add(
      new JOmniFactoryGeneratorT<CalorimeterHitReco_factory>(
         "HcalBarrelRandomRecHits",
        {"HcalBarrelRandomRawHits"},
        {"HcalBarrelRandomRecHits"},
        {
          .capADC = 65536,  // 16 bit ADC
          .dyRangeADC = 1.0 * dd4hep::GeV,
          .pedMeanADC = 300,
          .pedSigmaADC = 2,  // not used; relying on energy cut
          .resolutionTDC = 1 * dd4hep::picosecond,
          .thresholdFactor = 0.0,  // not used; relying on flat ADC cut
          .thresholdValue = 33,  // pedSigmaADC + thresholdValue = half-MIP (333 ADC)
          .sampFrac = "0.033", // average, from sPHENIX simulations
          .readout = "HcalBarrelHits",
          .layerField = "",
          .sectorField = "",
        },
        app  // TODO remove me once fixed
      )
    );

    // merge random hits to match sPHENIX geometry
    app -> Add(
      new JOmniFactoryGeneratorT<CalorimeterHitsMerger_factory>(
         "HcalBarrelRandomMergedHits",
        {"HcalBarrelRandomRecHits"},
        {"HcalBarrelRandomMergedHits"},
        {
          .readout = "HcalBarrelHits",
          .fieldTransformations = {"phi:phi-(5*((phi/5)-floor(phi/5)))"}
        },
        app  // TODO remove me once fixed
      )
    );

    // run island clustering on merged random hits
    app -> Add(
      new JOmniFactoryGeneratorT<CalorimeterIslandCluster_factory>(
         "HcalBarrelRandomHitIslandProtoClusters",
        {"HcalBarrelRandomMergedHits"},
        {"HcalBarrelRandomHitIslandProtoClusters"},
        {
          .adjacencyMatrix =
            "("
            "  ( (abs(eta_1 - eta_2) == 5) && (abs(phi_1 - phi_2) == 0) ) ||"
            "  ( (abs(eta_1 - eta_2) == 0) && (abs(phi_1 - phi_2) == 5) ) ||"
            "  ( (abs(eta_1 - eta_2) == 0) && (abs(phi_1 - phi_2) == (320 - 5)) )"
            ") == 1",
          .readout = "HcalBarrelHits",
          .sectorDist = 5.0 * dd4hep::cm,
          .splitCluster = false,
          .minClusterHitEdep = 5.0 * dd4hep::MeV,
          .minClusterCenterEdep = 30.0 * dd4hep::MeV,
          .transverseEnergyProfileMetric = "globalDistEtaPhi",
          .transverseEnergyProfileScale = 1.,
        },
        app  // TODO remove me once fixed
      )
    );

    // run CoG reconstruction on random hit clusters
    app -> Add(
      new JOmniFactoryGeneratorT<CalorimeterClusterRecoCoG_factory>(
         "HcalBarrelRandomHitClustersWithoutShapes",
        {"HcalBarrelRandomHitIslandProtoClusters",
         "HcalBarrelRandomHitAssociations"},
        {"HcalBarrelRandomHitClustersWithoutShapes",
         "HcalBarrelRandomHitClusterAssociationsWithoutShapes"},
        {
          .energyWeight = "log",
          .sampFrac = 1.0,
          .logWeightBase = 6.2,
          .enableEtaBounds = false
        },
        app  // TODO remove me once fixed
      )
    );

    // run cluster shape calculation on random hit clusters
    app -> Add(
      new JOmniFactoryGeneratorT<CalorimeterClusterShape_factory>(
         "HcalBarrelRandomHitClusters",
        {"HcalBarrelRandomHitClustersWithoutShapes",
         "HcalBarrelRandomHitClusterAssociationsWithoutShapes"},
        {"HcalBarrelRandomHitClusters",
         "HcalBarrelRandomHitClusterAssociations"},
        {
          .energyWeight = "log",
          .logWeightBase = 6.2
        },
        app  // TODO remove me once fixed
      )
    );

  }  // end 'InitPlugin(JApplication*)'

}  // end extern "C"

/// end =======================================================================
