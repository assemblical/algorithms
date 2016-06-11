#ifndef ALGORITHM_MERGE_SORT
#define ALGORITHM_MERGE_SORT

#include <limits>

namespace algorithm {
    template <typename ContainerT>
    inline void merge(ContainerT& container, size_t p, size_t q, size_t r) {
        size_t n1 = q - p + 1;
        size_t n2 = r - q;

        ContainerT left(n1 + 2);
        ContainerT right(n2 + 2);

        for (size_t i = 1; i <= n1; ++i) {
            left.at(i) = container.at(p + i - 1);
        }

        for (size_t j = 1; j <= n2; ++j) {
            right.at(j) = container.at(q + j);
        }
        left[n1 + 1] = std::numeric_limits<typename ContainerT::value_type>::max();
        right[n2 + 1] = std::numeric_limits<typename ContainerT::value_type>::max();

        for (size_t k = p, i = 1, j = 1; k <= r; ++k) {

            if (left.at(i) <= right.at(j)) {
                container.at(k) = left.at(i++);
            } else {
                container.at(k) = right.at(j++);
            }
        }
    }

    template <typename ContainerT>
    inline void _merge_sort(ContainerT& container, size_t p, size_t r) {
        if (p < r) {
            size_t q = (p + r) / 2;
            _merge_sort(container, p, q);
            _merge_sort(container, q + 1, r);
            merge(container, p, q, r);
        }
    }

    template <typename ContainerT>
    inline void merge_sort(ContainerT& container) {
        // insert dummy element for 0 indexed containers
        container.insert(container.begin(), std::numeric_limits<typename ContainerT::value_type>::lowest());
        _merge_sort(container, 1, container.size() - 1);
        container.erase(container.begin());
    }

} // algorithm

#endif // ALGORITHM_MERGE_SORT