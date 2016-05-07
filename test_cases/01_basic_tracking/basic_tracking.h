#ifndef BASIC_TRACKING_TEST
#define BASIC_TRACKING_TEST

#include <factory.h>

class BasicTrackingTestCase {
public:
    virtual void setup();
};

void BasicTrackingScenario::setup() {
    TestFactory::getInstance()->registerTrackedDevice(TrackedDeviceClass::TrackingReference, "", []() {
        // return constant position
    });
    TestFactory::getInstance()->registerTrackedDevice(TrackedDeviceClass::Controller, "", []() {
        // return random position
    });
}


#endif /* end of include guard: BASIC_TRACKING_TEST */