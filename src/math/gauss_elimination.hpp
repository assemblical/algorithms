#ifndef ALGORITHMS_GAUSS_ELIMINATION_HPP
#define ALGORITHMS_GAUSS_ELIMINATION_HPP

#include <forward_list>
#include <vector>

namespace algorithm {

    template <typename NumberT>
    using Matrix = std::vector<std::vector<NumberT>>;

    namespace detail {

        template <typename NumberT>
        inline std::forward_list<NumberT> _gauss_elimination(Matrix<NumberT> polynomialMatrix,
                                                             std::forward_list<NumberT>& resultList)
        {
            if (polynomialMatrix[0].size() < 2) {
                return resultList;
            }

            Matrix<NumberT> resultMatrix = {};

            auto rowSize = polynomialMatrix.size();
            for (int i = 1; i < rowSize; ++i) {
                resultMatrix.push_back({});

                printf("%i,%i,%i\n", polynomialMatrix[i][0],polynomialMatrix[i - 1][0],polynomialMatrix[i][0]);
                NumberT factor = polynomialMatrix[i - 1][0] / polynomialMatrix[i][0];

                auto columnSize = polynomialMatrix[i].size();
                for (int j = 1; j < columnSize; ++j) {
                    resultMatrix[i - 1][j] = polynomialMatrix[i][j] * factor;
                }
        }

            return resultList;

        }
    } // detail

    // solves a linear system of equations with the gauss elimination
    template <typename NumberT>
    inline std::forward_list<NumberT> gauss_elimination(Matrix<NumberT> polynomialMatrix)
    {
        std::forward_list<NumberT> resultList;
        detail::_gauss_elimination(polynomialMatrix, resultList);
//        auto tmpMat = polynomialMatrix;
//
//        auto rowSize = polynomialMatrix.size();
//        for (int i = 1; i < rowSize; ++i) {
//
//            auto columnSize = polynomialMatrix[i].size();
//            for (int j = 1; j < columnSize; ++j) {
//                NumberT factor = polynomialMatrix[i][0] * (polynomialMatrix[i - 1][0] / polynomialMatrix[i][0]);
//            }
//        }
        return resultList;
    }

} // algorithm

#endif //ALGORITHMS_GAUSS_ELIMINATION_HPP
