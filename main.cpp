#include <iostream>
#include <vector>
#include "src/sorts/merge_sort.hpp"
#include "src/search/binary_search_recursive.hpp"
#include "src/search/binary_search.hpp"
#include "src/sorts/insertion_sort.hpp"
#include "src/search/maximum_subarray_recursive.hpp"
#include "src/search/maximum_subarray_bruteforce.hpp"
#include "src/search/maximum_subarray_linear.hpp"
#include "src/math/binomial.hpp"

using namespace std;

int main() {
//    vector<int> vec = {6,5,-20,3,8,-30,1,14};
    auto pair = algorithm::binom(4, 1, 1);
    cout << pair.second << endl << pair.first;

//    for (auto &  elem : vec) {
//        cout << elem << endl;
//    }

    return 0;
}
