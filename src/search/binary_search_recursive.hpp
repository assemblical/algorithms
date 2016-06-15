#ifndef ALGORITHM_BINARY_SEARCH_RECURSIVE_HPP
#define ALGORITHM_BINARY_SEARCH_RECURSIVE_HPP

namespace algorithm {
namespace detail {

    // search for a value in a sorted container in O(log(n))
    template <typename ContainerT>
    inline bool _binary_search_recursive(ContainerT &container, const typename ContainerT::value_type &searchValue,
                                         int p, int r) noexcept {
        if (p > r) {
            return false;
        }

        int q = (p + r) / 2;
        
        if (container.at(q) == searchValue) {
            return true;
        }

        auto& currentValue = container.at(q);

        if (searchValue < currentValue) {
            return _binary_search_recursive(container, searchValue, p, q - 1);
        }
        
        if (searchValue > currentValue) {
            return _binary_search_recursive(container, searchValue, q + 1, r);
        }
    }
} // detail

    template <typename ContainerT>
    inline bool binary_search_recursive(ContainerT& container, const typename ContainerT::value_type& searchValue) {
        return detail::_binary_search_recursive(container, searchValue, 0, container.size() - 1);
    }

} // algorithm

#endif // ALGORITHM_BINARY_SEARCH_RECURSIVE_HPP
