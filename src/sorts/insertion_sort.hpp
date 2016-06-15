#ifndef ALGORITHM_INSERTION_SORT
#define ALGORITHM_INSERTION_SORT

namespace algorithm {

    // insertion sort operating in O(n^2)
    template <typename ContainerT>
    inline void insertion_sort(ContainerT& container) noexcept {
        const size_t containerSize = container.size();

        if (containerSize < 2) {
            return;
        }

        for (size_t i = 1; i < containerSize; ++i) {
            auto key = container.at(i);

            // binary search range until element that is smaller or equal
            // insert element and add shift all succeding elements by 1

            size_t p = 0;
            size_t r = i;
            size_t q = r / 2;
            while (q < r) {
                auto &elem = container.at(p);

                // if greater
                if (elem > key) {

                }

                // if smaller
                if (elem < key) {

                }

                q = (p + r) / 2;
            }

            int j;
            for (j = static_cast<int>(i - 1); j >= 0 && container.at(j) > key; --j) {
                container.at(j + 1) = container.at(j);
            }

            container.at(j + 1) = key;
        }
    }

} // algorithm

#endif // ALGORITHM_INSERTION_SORT
