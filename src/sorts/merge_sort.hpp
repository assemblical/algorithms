#ifndef ALGORITHM_MERGE_SORT
#define ALGORITHM_MERGE_SORT

namespace algorithm {
    template <typename ContainerT>
    inline void merge(ContainerT& container, size_t p, size_t q, size_t r) {
        size_t n1 = q - p;
        size_t n2 = r - q;

        ContainerT left(n1);
        ContainerT right(n2);

        // todo inserter
        for (size_t i = 0; i < n1; ++i) {
            left.at(i) = container.at(p + i);
        }

        for (size_t j = 0; j < n2; ++j) {
            right.at(j) = container.at(q + j);
        }

        for (size_t k = p, i = 0, j = 0; k < r; ++k) {
            if (left.at(k) <= right.at(k)) {
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
        _merge_sort(container, 0, container.size());
    }

} // algorithm

#endif // ALGORITHM_MERGE_SORT