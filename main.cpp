#include <iostream>
#include <vector>
#include "src/sorts/merge_sort.hpp"
#include "src/search/binary_search_recursive.hpp"
#include "src/sorts/insertion_sort.hpp"

using namespace std;

int main() {
    vector<int> vec = {5,4,3,2,1};
    algorithm::merge_sort(vec);
    auto b = algorithm::binary_search_recursive(vec, 6);
    cout << b << endl;

    for (auto &  elem : vec) {
        cout << elem << endl;
    }

    return 0;
}
