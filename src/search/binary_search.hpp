#ifndef ALGORITHM_BINARY_SEARCH_HPP
#define ALGORITHM_BINARY_SEARCH_HPP

namespace algorithm {
namespace detail {

    // search for a value in a sorted container in O(log(n))
    template <typename ContainerT>
    inline bool _binary_search(ContainerT& container, const typename ContainerT::value_type& searchValue, size_t p, size_t r) {
        size_t q = (p + r) / 2;
        
        if (container.at(q) == searchValue) {
            return true;
        }

        if (q == r) {
            return false;
        }

        auto& currentValue = container.at(q);

        if (searchValue < currentValue) {
            return _binary_search(container, searchValue, p, q - 1);
        }
        
        if (searchValue > currentValue) {
            return _binary_search(container, searchValue, q + 1, r);
        }
    }
}

    template <typename ContainerT>
    inline bool binary_search(ContainerT& container, const typename ContainerT::value_type& searchValue) {
        return detail::_binary_search(container, searchValue, 0, container.size() - 1);
    }

} // algorithm

#endif // ALGORITHM_BINARY_SEARCH_HPP
