#include "libackermann/steering_ratio.hpp"

ack::Ratio ack::get_steering_ratio(Project project) {
    constexpr Ratio steering_ratios[] = {
            // Project Phoenix steering ratio as measured with the stock wheel and rack.
            [](float steering) -> float { return 0.04572763f * steering + -0.014521139f; },
    };

    return steering_ratios[static_cast<uintmax_t>(project)];
}

ack::Ratio ack::get_inverse_steering_ratio(ack::Project project) {
    constexpr Ratio inverse_steering_ratios[] = {
            // Project Phoenix steering ratio as measured with the stock wheel and rack.
            [](float ack) -> float { return (ack + 0.014521139f) / 0.04572763f; },
    };

    return inverse_steering_ratios[static_cast<uintmax_t>(project)];
}
