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

//                printf("%i,%i,%i\n", polynomialMatrix[i][0],polynomialMatrix[i - 1][0],polynomialMatrix[i][0]);
                double fac1 = polynomialMatrix[i - 1][0];
                double fac2 = polynomialMatrix[i][0];
                double fac = fac1 / fac2;

                auto columnCount = polynomialMatrix[i].size();
                for (int j = 1; j < columnCount; ++j) {
                    double newValue = polynomialMatrix[i - 1][j] - polynomialMatrix[i][j] * fac;
                    resultMatrix[i - 1].emplace_back(newValue);
                }
            }

            return resultList;

        }
    } // detail

    // solve a linear equation system for unknown coefficients
    template <typename NumberT>
    inline std::forward_list<NumberT> gauss_elimination(Matrix<NumberT> points)
    {
        // a0 + a1 x1 + a2 x1 ^ 2... = y1
        // a0 + a1 x2 + a2 x2 ^ 2... = y2
        // matrix format = {{ x1, x1 ^ 2, y1 },
        //                  { x2, x2 ^ 2, y2 }}
        Matrix<NumberT> polynomialMatrix;
        std::forward_list<NumberT> resultList;

        // rows specify the number of coefficients (-1)
        size_t pointCount = points.size();

        for (int i = 0; i < pointCount; ++i) {
            //columns
            polynomialMatrix.push_back({});
            for (int j = 0; j < pointCount; ++j) {
                polynomialMatrix[i].emplace_back(std::pow(points[i][0], j + 1));
            }
            // emplace function value
            polynomialMatrix[i].emplace_back(points[i][1]);
        }
        detail::_gauss_elimination(polynomialMatrix, resultList);
        return resultList;
    }

} // algorithm

#endif //ALGORITHMS_GAUSS_ELIMINATION_HPP
