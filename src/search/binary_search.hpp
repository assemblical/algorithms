#ifndef ALGORITHM_BINARY_SEARCH_HPP
#define ALGORITHM_BINARY_SEARCH_HPP

namespace algorithm {

    template <typename ContainerT>
    inline bool binary_search(ContainerT& container, const typename ContainerT::value_type& searchValue) noexcept {

        size_t p = 0;
        size_t q = container.size() / 2;
        size_t r = container.size() - 1;

        while () {
            
        }
        // if groesser
        // if kleiner
    }

} // algorithm

#endif // ALGORITHM_BINARY_SEARCH_HPP