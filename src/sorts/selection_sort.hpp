#include "../util.hpp"

namespace algorithm {
    namespace sort {

        // selection sort operating in O(n^2)
        template <typename container_t>
        inline void selection_sort(container_t &container) noexcept {
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

    } // namespaces
}
