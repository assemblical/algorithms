#include <iostream>
#include <vector>
#include "src/math/binomial.hpp"
#include "src/math/gauss_elimination.hpp"

using namespace std;

int main() {
    std::vector<std::vector<double>> points  = {{4, 2}, {3, 1}};
    auto result = algorithm::gauss_elimination<double>(points);

//    for (auto &  elem : result) {
//        cout << elem << endl;
//    }

    return 0;
}
