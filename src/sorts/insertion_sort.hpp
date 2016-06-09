namespace algorithm {
    namespace sort {

        // insertion sort operating in O(n^2)
        template <typename container_t>
        inline void insertion_sort(container_t& container) noexcept {
            const size_t containerSize = container.size();

            if (containerSize < 2) {
                return;
            }

            for (size_t i = 1; i < containerSize; ++i) {
                auto key = container.at(i);

                int j;
                for (j = i - 1; j >= 0 && container.at(j) > key; --j) {
                    container.at(j + 1) = container.at(j);
                }

                container.at(j + 1) = key;
            }
        }

    } // namespaces
}
