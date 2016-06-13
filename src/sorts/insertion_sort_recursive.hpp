#ifndef ALGORITHM_INSERTION_SORT_RECURSIVE_HPP
#define ALGORITHM_INSERTION_SORT_RECURSIVE_HPP

namespace algorithm {
namespace detail {

    template<typename ContainerT>
    inline void _insertion_sort_recursive(ContainerT &container, size_t p, size_t q) noexcept {
        if (p > 0) {
            _insertion_sort_recursive(container, p - 1, q);

            auto key = container.at(p);

            int j;
            for (j = static_cast<int>(p - 1); j >= 0 && container.at(j) > key; --j) {
                container.at(j + 1) = container.at(j);
            }
            container.at(j + 1) = key;
        }
    }
} // detail

    template<typename ContainerT>
    inline void insertion_sort_recursive(ContainerT &container) noexcept {
        detail::_insertion_sort_recursive(container, container.size() - 1, container.size() - 1);;
    }
} // algorithm

#endif // ALGORITHM_INSERTION_SORT_RECURSIVE_HPP
