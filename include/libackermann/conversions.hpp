#pragma once

#include "types.hpp"
#include "cmath"
#include "cassert"

namespace ack {
    /// Converts an ackermann command to an equivalent twist command.
    ///
    /// \param ack Ackermann command to convert.
    /// \param wheelbase Wheelbase of vehicle. Must be greater than 0.
    /// \return Twist command with equivalent effect to ack.
    TwistCommand ackermann_to_twist(const AckermannCommand &ack, float wheelbase) {
        assert(wheelbase > 0);

        auto ang_yaw = 0.0f;

        if (ack.speed != 0 && ack.ackermann_angle != 0) {
            // Just an inversion of the twist to ackermann formula
            ang_yaw = (fabsf(ack.speed) * tanf(ack.ackermann_angle)) / wheelbase;

            return TwistCommand{ack.speed, ang_yaw};
        } else {
            return TwistCommand{ack.speed, ang_yaw};
        }
    }

    /// Converts a twist command to an equivalent ackermann command.
    ///
    /// \param tw Twist command to convert.
    /// \param wheelbase Wheelbase of vehicle. Must be > 0.
    /// \return Ackermann command with equivalent effect to twist.
    AckermannCommand twist_to_ackermann(const TwistCommand &tw, float wheelbase) {
        assert(wheelbase > 0);

        auto ack_ang = 0.0f;

        if (tw.v_angular_yaw != 0 && tw.v_linear_x != 0) {
            // Remove negative so steering doesn't reverse when reversing.
            auto vel = fabsf(tw.v_linear_x);

            auto radius = vel / tw.v_angular_yaw;

            // Calculate virtual ackermann wheel angle
            ack_ang = std::atan(wheelbase / radius);

            return AckermannCommand{tw.v_linear_x, ack_ang};
        } else {
            return AckermannCommand{tw.v_linear_x, ack_ang};
        }
    }
}