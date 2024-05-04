//
#ifndef DIE_H
#define DIE_H

class Die {
public:
    Die();
    int roll() const;
    void set_value(int value);

private:
    const int sides = 6;
    int current_value;
};

#endif