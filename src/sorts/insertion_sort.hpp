#ifndef ALGORITHM_INSERTION_SORT
#define ALGORITHM_INSERTION_SORT

namespace algorithm {

    // insertion sort operating in O(nlog(n))
    template <typename ContainerT>
    inline void insertion_sort(ContainerT& container) noexcept {
        const size_t containerSize = container.size();

        if (containerSize < 2) {
            return;
        }

        for (int i = 1; i < containerSize; ++i) {
            auto key = container.at(i);

            // binary search for insert position
            int r = i;
            int q = r / 2;
            while (q < r) {
                auto &elem = container.at(q);

                if (key == elem) {
                    break;
                }

                if (key > elem) {
                    q = (q + 1 + r) / 2;
                }

                if (key < elem) {
                    r = q;
                    q = q / 2;
                }
            }

            int j;
            for (j = i - 1; j >= q; --j) {
                container.at(j + 1) = container.at(j);
            }

            container.at(j + 1) = key;
        }
    }

} // algorithm

#endif // ALGORITHM_INSERTION_SORT
