#ifndef ALGORITHM_MERGE_SORT
#define ALGORITHM_MERGE_SORT

namespace algorithm {
    template <typename ContainerT>
    inline void merge(ContainerT& container, size_t p, size_t q, size_t r) {
        size_t n1 = q - p;
        size_t n2 = r - q;

        ContainerT left(n1);
        ContainerT right(n2);

    }

    template <typename ContainerT>
    inline void merge_sort(ContainerT& container) {
    }
} // algorithm

#endif // ALGORITHM_MERGE_SORT