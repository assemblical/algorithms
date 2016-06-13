#include <iostream>
#include <vector>
#include "src/sorts/merge_sort.hpp"
#include "src/search/binary_search.hpp"

using namespace std;

int main() {
    std::vector<int> vec = {5,4,3,2,1};
    algorithm::merge_sort(vec);
    bool result = algorithm::binary_search(vec, 5);

    std::cout << result << std::endl;

    for (auto &  elem : vec) {
        std::cout << elem << std::endl;
    }

    return 0;
}
