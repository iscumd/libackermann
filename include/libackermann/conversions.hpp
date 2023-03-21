#pragma once

#include <cmath>

#include "types.hpp"
#include "cassert"

namespace ack {
    /// Converts an ackermann command to an equivalent twist command.
    ///
    /// \param ack Ackermann command to convert.
    /// \param wheelbase Wheelbase of vehicle. Must be greater than 0.
    /// \return Twist command with equivalent effect to ack.
    TwistCommand ackermann_to_twist(const AckermannCommand &ack, float wheelbase);

    /// Converts a twist command to an equivalent ackermann command.
    ///
    /// \param tw Twist command to convert.
    /// \param wheelbase Wheelbase of vehicle. Must be > 0.
    /// \return Ackermann command with equivalent effect to twist.
    AckermannCommand twist_to_ackermann(const TwistCommand &tw, float wheelbase);
}