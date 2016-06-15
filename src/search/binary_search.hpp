#ifndef ALGORITHM_BINARY_SEARCH_HPP
#define ALGORITHM_BINARY_SEARCH_HPP

namespace algorithm {

    template <typename ContainerT>
    inline bool binary_search(ContainerT& container, const typename ContainerT::value_type& searchValue) noexcept {

        int q = container.size() / 2;
        int r = container.size();

        while (q < r) {
            auto& currentElement = container.at(q);

            if (currentElement == searchValue) {
                return true;
            }
            if (searchValue < currentElement) {
                r = q;
                q = q / 2;
            }
            if (searchValue > currentElement) {
                q = (q + 1 + r) / 2;
            }
        }
        return false;
    }

} // algorithm

#endif // ALGORITHM_BINARY_SEARCH_HPP