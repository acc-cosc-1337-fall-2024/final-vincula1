//
#ifndef DIE_H
#define DIE_H

class Die {
public:
    Die();
    int roll() const;

private:
    const int sides = 6;
};

#endif