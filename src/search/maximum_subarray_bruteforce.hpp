#ifndef ALGORITHMS_MAXIMUM_SUBARRAY_BRUTEFORCE_HPP
#define ALGORITHMS_MAXIMUM_SUBARRAY_BRUTEFORCE_HPP

#include <tuple>

namespace algorithm {

    // O(n^2)
    template <typename ContainerT>
    std::tuple<size_t, size_t, typename ContainerT::value_type> maximum_subarray_bruteforce(const ContainerT& container) {
        int sum = std::numeric_limits<int>::min();
        int left_index = 0;
        int right_index = 0;

        for (int i = 0; i < container.size(); ++i) {
            if (container.at(i) > sum) {
                sum = container.at(i);
                left_index = i;
                right_index = i;
            }

            int tmp_sum = container.at(i);

            for (int j = i + 1; j < container.size(); ++j) {
                tmp_sum += container.at(j);
                if (tmp_sum > sum) {
                    left_index = i;
                    right_index = j;
                    sum = tmp_sum;
                }
            }
        }
        return std::make_tuple(left_index, right_index, sum);
    }

} // algorithm

#endif //ALGORITHMS_MAXIMUM_SUBARRAY_BRUTEFORCE_HPP
