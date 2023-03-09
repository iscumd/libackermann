#pragma once

/// A command in the form of axial velocities.
struct TwistCommand {
    /// Desired linear velocity in the x-axis
    float v_linear_x;
    /// Desired angular velocity
    float v_angular_yaw;
};

/// A command in the form of ackermann steering.
struct AckermannCommand {
    /// Desired vehicle speed.
    float speed;
    /// Desired virtual ackermann wheel angle.
    float ackermann_angle;
};