# RCDAQ2JANA

**Contributors:** Derek Anderson, Martin Purschke

This is the development repository for the RCDAQ2JANA proof-of-concept, a suite of tools
to work through the details and demonstrate the feasibility of getting data out of
RCDAQ and running it through EICrecon. In other words, to demonstrate a full EIC analysis
chain for data collected via RCDAQ.

This demonstration is done with standalone cosmics data recorded by the sPHENIX OHCal shortly
after it was constructed.

## Development Stages

Development will proceed in several stages, increasing the complexity at each step.

1. :white_check_mark: Confirm we can generate random hits and save them to an output tree,
2. Confirm that we can process the saved random hits in EICrecon,
3. Confirm that we can run pmonitor in the EIC environment,
4. Confirm that we can create hits from pmonitor output and save them to an output tree,
5. Confirm that we can process the saved pmonitor hits in EICrecon.
