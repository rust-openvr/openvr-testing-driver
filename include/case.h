#pragma once

#define FULFILLMENT_TYPE_EQUALS 0
#define FULFILLMENT_TYPE_BIGGER_THAN 1
#define FULFILLMENT_TYPE_SMALLER_THAN 2

class TestCase {

public:
    virtual const char* name() = 0;
    virtual void setup() = 0;

    void addTestFulfillment(int id, int initial_state, int desired_state, int type);
    void setTestFulfillmentState(int id, int state);
    void incTestFulfillmentState(int id);
};