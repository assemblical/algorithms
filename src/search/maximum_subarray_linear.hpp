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

        int sum = container.at(0);
        int tmp_sum = sum;
        int left_index = 0;
        int right_index = 0;

        for (int i = 1; i < container.size(); ++i) {
            if (tmp_sum + container.at(i) > container.at(i)) {
                tmp_sum += container.at(i);
                if (tmp_sum > sum) {
                    sum = tmp_sum;
                    right_index = i;
                }
            } else {
                tmp_sum = container.at(i);
                if (tmp_sum > sum) {
                    sum = tmp_sum;
                    left_index = i;
                }
            }
        }
        return std::make_tuple(left_index, right_index, sum);
    };

} // algorithm

#endif //ALGORITHMS_MAXIMUM_SUBARRAY_LINEAR_HPP
