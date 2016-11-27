#include <iostream>
#include <vector>
#include "src/math/binomial.hpp"
#include "src/math/gauss_elimination.hpp"

using namespace std;

int main() {
    std::vector<std::vector<int>> mat  = {{4, 2, 1}, {2, 3, 5}};
    auto result = algorithm::gauss_elimination(mat);

    for (auto &  elem : result) {
        cout << elem << endl;
    }

    return 0;
}
