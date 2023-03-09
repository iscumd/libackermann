#include "gtest/gtest.h"
#include "libackermann/libackermann.hpp"

TEST(ConversionTests, isomorphic) {
    // Ensure conversions are exact inverse operations
    AckermannCommand comm{10, 0.33};
    auto tw = ack::ackermann_to_twist(comm, 3.0);
    EXPECT_EQ(ack::twist_to_ackermann(tw, 3.0), comm);

    TwistCommand t_comm{3.3233, 0.34};
    auto ack = ack::twist_to_ackermann(t_comm, 0.323);
    EXPECT_EQ(ack::ackermann_to_twist(ack, 0.323), t_comm);
} //TODO make test to see if the conversion is actually correct (we know tta is correct, and att is an exact inverse, so in theory this is correct, but it would be nice to verify one or the other)

TEST(RatioTests, pheonix) {
    // Just make sure we don't segfault for now
    auto fn = ack::get_steering_ratio(ack::Project::Phoenix);
    float ack = fn(10);
    EXPECT_EQ(ack::get_inverse_steering_ratio(ack::Project::Phoenix)(ack), 10);
}
