//
#ifndef PHASE_H
#define PHASE_H

#include "roll.h"

enum class RollOutcome {
    natural,
    craps,
    point,
    seven_out,
    nopoint

};


class Phase {
public:
    virtual ~Phase() = default;
    virtual RollOutcome get_outcome(Roll* roll) = 0;
};

#endif // PHASE_H