#ifndef ALGORITHMS_MAXIMUM_SUBARRAY_LINEAR_HPP
#define ALGORITHMS_MAXIMUM_SUBARRAY_LINEAR_HPP

#include <tuple>

namespace algorithm {

    // O(n)
    template <typename ContainerT>
    std::tuple<size_t, size_t, typename ContainerT::value_type> maximum_subarray_linear(const ContainerT& container) {

        if (container.size() == 1) {
            return std::make_tuple(0, 0, container.at(0));
        }

        auto max_subarray = std::make_tuple(0, 0, container.at(0));
        auto tmp_subarray = std::make_tuple(0, 0, container.at(0));

        for (int i = 1; i < container.size(); ++i) {
            auto& elem = container.at(i);

            std::get<2>(tmp_subarray) += elem;

            if (elem > std::get<2>(tmp_subarray)) {
                std::get<0>(tmp_subarray) = i;
                std::get<2>(tmp_subarray) = elem;
            } else {
                std::get<1>(tmp_subarray) = i;
            }

            if (std::get<2>(tmp_subarray) > std::get<2>(max_subarray)) {
                std::get<0>(max_subarray) = std::get<0>(tmp_subarray);
                std::get<1>(max_subarray) = std::get<1>(tmp_subarray);
                std::get<2>(max_subarray) = std::get<2>(tmp_subarray);
            }

        }
        return max_subarray;
    };

} // algorithm

#endif //ALGORITHMS_MAXIMUM_SUBARRAY_LINEAR_HPP
