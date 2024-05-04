//
#ifndef POINT_PHASE_h
#define POINT_PHASE_h

#include "phase.h"

class PointPhase : public Phase {
private:
    int point;
public:
    PointPhase(int p) : point(p) {}
    RollOutcome get_outcome(Roll* roll) override;

};

#endif // POINT_PHASE_h