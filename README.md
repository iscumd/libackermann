# libackermann

General purpose Ackermann steering utilities for ISC projects

This library does not use ROS directly, so it should be usable on
constrained platforms.

Features:
- Ackermann to twist conversion
- Twist to ackermann conversion
- (Inverse) Steering ratio functions for ISC projects

## Units

This library uses the convention of:
- distances in meters
- angles in radians, where left is positive


## Use in your Cmake project

To use libackermann in your Cmake projects (ROS included),
add to your CmakeLists.txt:

```cmake
include(FetchContent)
FetchContent_Declare(
        libackermann
        GIT_REPOSITORY https://github.com/iscumd/libackermann.git
)
FetchContent_MakeAvailable(libackermann)

target_link_libraries({$PROJECT} libackermann)
```

## Headers

| Header                          | contains                                           |
|---------------------------------|----------------------------------------------------|
| libackermann/libackermann.hpp   | Meta header than includes all others.              |
| libackermann/types.hpp          | Command type definitions.                          |
| libackermann/conversions.hpp    | Conversions between command types.                 |
| libackermann/steering_ratio.hpp | Steering ratio functions for various ISC projects. |

See tests for example use cases.


