#pragma once

#include "cstdint"

namespace ack {
    /// Steering ratios take steering wheel rad, and return ackermann wheel rad
    typedef float (*Ratio)(float);

    /// Enumeration of all ISC projects that have a steering ratio defined
    enum class Project : uintmax_t {
        Phoenix = 0
    };

    /// Gets the steering ratio function for a given project.
    ///
    /// \param project Project to get the steering ratio for.
    /// \return A function pointer to the steering ratio. This is a function that takes the steering wheel input angle,
    /// and returns the resulting virtual ackermann wheel angle.
    Ratio get_steering_ratio(Project project);

    /// Gets the inverse steering ratio function for a given project.
    ///
    /// \param project Project to get the inverse steering ratio for.
    /// \return A function pointer to the inverse steering ratio. This is a function that takes the virtual ackermann wheel angle,
    /// and returns the current steering wheel position.
    Ratio get_inverse_steering_ratio(Project project);
}
