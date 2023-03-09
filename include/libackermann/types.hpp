#pragma once

/// A command in the form of axial velocities.
struct TwistCommand {
    /// Desired linear velocity in the x-axis
    float v_linear_x;
    /// Desired angular velocity
    float v_angular_yaw;

    bool operator==(const TwistCommand &rhs) const {
        return v_linear_x == rhs.v_linear_x &&
               v_angular_yaw == rhs.v_angular_yaw;
    }

    bool operator!=(const TwistCommand &rhs) const {
        return !(rhs == *this);
    }
};

/// A command in the form of ackermann steering.
struct AckermannCommand {
    /// Desired vehicle speed.
    float speed;
    /// Desired virtual ackermann wheel angle.
    float ackermann_angle;

    bool operator==(const AckermannCommand &rhs) const {
        return speed == rhs.speed &&
               ackermann_angle == rhs.ackermann_angle;
    }

    bool operator!=(const AckermannCommand &rhs) const {
        return !(rhs == *this);
    }
};