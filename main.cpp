#include <iostream>
#include <vector>
#include "src/sorts/insertion_sort_recursive.hpp"

using namespace std;

int main() {
    std::vector<int> vec = {5,4,3,2,1};
    algorithm::insertion_sort_recursive(vec);

    for (auto &  elem : vec) {
        std::cout << elem << std::endl;
    }

    return 0;
}
