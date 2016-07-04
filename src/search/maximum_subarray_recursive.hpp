#ifndef ALGORITHMS_MAXIMUM_SUBARRAY_RECURSIVE_HPP
#define ALGORITHMS_MAXIMUM_SUBARRAY_RECURSIVE_HPP

#include <limits>
#include <tuple>
#include <cmath>

namespace algorithm {

    namespace detail {
    
        template <typename ContainerT>
        inline std::tuple<size_t, size_t, int> max_crossing_subarray(const ContainerT& container, int low, int mid, int high) {
            int left_sum = std::numeric_limits<int>::min();
            int right_sum = std::numeric_limits<int>::min();
            int sum = 0;
            int max_left = 0;
            int max_right = 0;

            for (int i = mid; i >= low; --i) {
                sum += container.at(i);
                if (sum > left_sum) {
                    left_sum = sum;
                    max_left = i;
                }
            }

            sum = 0;

            for (int i = mid + 1; i <= high; ++i) {
                sum += container.at(i);
                if (sum > right_sum) {
                    right_sum = sum;
                    max_right = i;
                }
            }

            return std::make_tuple(max_left, max_right, left_sum + right_sum);
        }

        template <typename ContainerT>
        inline std::tuple<size_t, size_t, typename ContainerT::value_type> _maximum_subarray(const ContainerT& container, size_t low, size_t high) {
            if (high == low) {
                return std::make_tuple(low, high, container.at(low));
            }
            else {
                int mid = std::floor((low + high) / 2);
                auto left = _maximum_subarray(container, low, mid);
                auto right = _maximum_subarray(container, mid + 1, high);
                auto cross = max_crossing_subarray(container, low, mid, high);

                if (std::get<2>(left) >= std::get<2>(right) && std::get<2>(left) >= std::get<2>(cross)) {
                    return left;
                } else if (std::get<2>(right) >= std::get<2>(left) && std::get<2>(right) >= std::get<2>(cross)) {
                    return right;
                } else {
                    return cross;
                }
            }
        }
        
    } // detail

    template <typename ContainerT>
    std::tuple<size_t, size_t, typename ContainerT::value_type> maximum_subarray(const ContainerT& container) {
        return detail::_maximum_subarray(container, 0, container.size() - 1);
    }
    
} // algorithm

#endif //ALGORITHMS_MAXIMUM_SUBARRAY_RECURSIVE_HPP
