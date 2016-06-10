#ifndef ALGORITHM_SELECTION_SORT
#define ALGORITHM_SELECTION_SORT

#include "../util.hpp"

namespace algorithm {

    // selection sort operating in O(n^2)
    template <typename ContainerT>
    inline void selection_sort(ContainerT &container) noexcept {
        const size_t containerSize = container.size();

        for (size_t i = 0; i < containerSize - 1; ++i) {

            size_t elemIndex = i;
            for (int j = i; j < containerSize; ++j) {
                if (container.at(elemIndex) > container.at(j)) {
                    elemIndex = j;
                }
            }
            algorithm::swap(container.at(i), container.at(elemIndex));
        }
    }

} // algorithm

#endif // ALGORITHM_SELECTION_SORT
