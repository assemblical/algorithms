#ifndef ALGORITHM_MERGE_SORT
#define ALGORITHM_MERGE_SORT

namespace algorithm {
namespace detail {

    // merge sort operating in O(n log(n))
    template <typename ContainerT>
    inline void merge(ContainerT& container, size_t p, size_t q, size_t r) {
        size_t n1 = q - p + 1;
        size_t n2 = r - q;

        ContainerT left(n1);
        ContainerT right(n2);

        for (size_t i = 0; i < n1; ++i) {
            left.at(i) = container.at(p + i);
        }

        for (size_t j = 0; j < n2; ++j) {
            right.at(j) = container.at(q + j + 1);
        }

        for (size_t k = p, i = 0, j = 0; k <= r; ++k) {

            if (left.at(i) <= right.at(j)) {
                container.at(k) = left.at(i++);
            } else {
                container.at(k) = right.at(j++);
            }

            if (i == n1) {
                for (++k; j < n2; ++k) {
                    container.at(k) = right.at(j++);
                }
                break;
            } else if (j == n2) {
                for (++k; i < n1; ++k) {
                    container.at(k) = left.at(i++);
                }
                break;
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
} // detail

    template <typename ContainerT>
    inline void merge_sort(ContainerT& container) {
        detail::_merge_sort(container, 0, container.size() - 1);
    }

} // algorithm

#endif // ALGORITHM_MERGE_SORT
