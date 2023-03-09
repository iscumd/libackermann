#pragma once

namespace ack {
    /// Steering ratios take steering wheel rad, and return ackermann wheel rad
    typedef float (*Ratio)(float);

    /// Enumeration of all ISC projects that have a steering ratio defined
    enum class Project : uintmax_t {
        Phoenix = 0
    };

    /// Array of steering ratios per project.
    /// Index this with the projects enum.
    constexpr Ratio steering_ratios[] = {
            // Project Phoenix steering ratio as measured with the stock wheel and rack.
            [](float steering) -> float { return 0.04572763f * steering + -0.014521139f; },
    };

    /// Array of inverse steering ratios per project.
    /// Index this with the projects enum.
    ///
    /// This is needed since our ratios are actually a function.
    constexpr Ratio inverse_steering_ratios[] = {
            // Project Phoenix steering ratio as measured with the stock wheel and rack.
            [](float ack) -> float { return (ack + 0.014521139f) / 0.04572763f; },
    };

    /// Gets the steering ratio function for a given project.
    ///
    /// \param project Project to get the steering ratio for.
    /// \return A function pointer to the steering ratio. This is a function that takes the steering wheel input angle,
    /// and returns the resulting virtual ackermann wheel angle.
    Ratio get_steering_ratio(Project project) {
        return steering_ratios[static_cast<uintmax_t>(project)];
    }

    /// Gets the inverse steering ratio function for a given project.
    ///
    /// \param project Project to get the inverse steering ratio for.
    /// \return A function pointer to the inverse steering ratio. This is a function that takes the virtual ackermann wheel angle,
    /// and returns the current steering wheel position.
    Ratio get_inverse_steering_ratio(Project project) {
        return inverse_steering_ratios[static_cast<uintmax_t>(project)];
    }
}
