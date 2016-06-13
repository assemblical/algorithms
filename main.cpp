#include <iostream>
#include <vector>
#include "src/sorts/merge_sort.hpp"

using namespace std;

int main() {
    std::vector<int> vec = {5,4,3,2};
    algorithm::merge_sort(vec);

    for (auto &  elem : vec) {
        std::cout << elem << std::endl;
    }

    return 0;
}
