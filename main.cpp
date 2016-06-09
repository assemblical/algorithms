#include <iostream>
#include <vector>
#include "src/sorts/insertion_sort.hpp"
#include "src/sorts/selection_sort.hpp"

using namespace std;

int main() {
    std::vector<int> vec = {5,4,3,2,0};
    algorithm::sort::selection_sort(vec);

    for (auto &  elem : vec) {
        std::cout << elem << std::endl;
}

    return 0;
}