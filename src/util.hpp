namespace algorithm {

    template <typename T>
    inline void swap(T& first, T& second) {
        T tmp(first);
        first = second;
        second = tmp;
    }
    
}
