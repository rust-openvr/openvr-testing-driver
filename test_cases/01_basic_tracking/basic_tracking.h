#ifndef BASIC_TRACKING_TEST
#define BASIC_TRACKING_TEST

#include <case.h>
#include <factory.h>
#include <hooks.h>

#define BASIC_TRACKING_FULFILLMENT_ASKED_FOR_POSITION 1
#define BASIC_TRACKING_FULFILLMENT_ASKED_FOR_DEVICES 2

class BasicTrackingTestCase : TestCase {

public:
    virtual void setup();
};

void BasicTrackingScenario::setup() {
    this->addTestFulfillment(BASIC_TRACKING_FULFILLMENT_ASKED_FOR_POSITION, 0, 1, FULFILLMENT_TYPE_BIGGER_THAN);
    this->addTestFulfillment(BASIC_TRACKING_FULFILLMENT_ASKED_FOR_DEVICES, 0, 0, FULFILLMENT_TYPE_BIGGER_THAN);

    TestHooks::getInstance()->registerHook(HOOK_ASKED_FOR_DEVICES, []() {
        this->incTestFulfillmentState(BASIC_TRACKING_FULFILLMENT_ASKED_FOR_DEVICES);
    });

    TestFactory::getInstance()->registerTrackedDevice(TrackedDeviceClass::TrackingReference, "", []() {
        this->incTestFulfillmentState(BASIC_TRACKING_FULFILLMENT_ASKED_FOR_POSITION);

        // return constant position
    });
    TestFactory::getInstance()->registerTrackedDevice(TrackedDeviceClass::Controller, "", []() {
        this->incTestFulfillmentState(BASIC_TRACKING_FULFILLMENT_ASKED_FOR_POSITION);

        // return random position
    });
}


#endif /* end of include guard: BASIC_TRACKING_TEST */