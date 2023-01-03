#pragma once

class PlayerActionCondition {
public:
    virtual ~PlayerActionCondition() { }
    virtual bool check() = 0;
    virtual void setup();
};
