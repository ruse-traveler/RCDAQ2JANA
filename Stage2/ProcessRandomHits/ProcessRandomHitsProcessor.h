/// ===========================================================================
/*! \file    ProcessRandomHitsProcessor.h
 *  \authors Derek Anderson
 *  \date    06.04.2025
 *
 *  A small EICrecon plugin to "reconstruct" and
 *  cluster random hits generated in development
 *  stage 1.
 *
 *  This is the 2nd stage of development
 *  towards an RCDAQ2JANA prototype.
 */
/// ===========================================================================

#include <JANA/JEventProcessorSequentialRoot.h>
#include <TH2D.h>
#include <TFile.h>


// ============================================================================
//! Process random raw hits
// ============================================================================
/*! A small EICrecon plugin to "reconstruct"
 *  and cluster the random hits generaetd in
 *  development stage 1.
 */
class ProcessRandomHitsProcessor : public JEventProcessorSequentialRoot {

  public:

    // ctor
    ProcessRandomHitsProcessor() { SetTypeName(NAME_OF_THIS); }

};  // end ProcessRandomHitsProcessor

/// end =======================================================================
