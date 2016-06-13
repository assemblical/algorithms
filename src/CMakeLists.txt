SET(SORT_HPP_FILES sorts/insertion_sort.hpp sorts/insertion_sort_recursive.hpp sorts/selection_sort.hpp sorts/merge_sort.hpp)
SET(UTIL_HPP_FILES util.hpp)

ADD_LIBRARY(algorithm ${SORT_HPP_FILES} ${UTIL_HPP_FILES})    
SET_TARGET_PROPERTIES(algorithm PROPERTIES LINKER_LANGUAGE CXX)
