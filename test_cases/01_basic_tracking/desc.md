# 01_basic_tracking

## Hardware
- 1 tracking reference
- 1 tracked controller

## Test requirements

Driver level:
0 - Should have been asked for a device pose at least twice (for tracking reference and for controller)
1 - Should have been asked for a list of devices

Application level:
- Given hardware should be detected
- Controller should randomly change it's positions
- Tracking reference should have a constant position
