#ifndef ALGORITHMS_GAUSS_ELIMINATION_HPP
#define ALGORITHMS_GAUSS_ELIMINATION_HPP

#include <list>
#include <vector>

namespace algorithm {

    template <typename NumberT>
    using Matrix = std::vector<std::vector<NumberT>>;

    template  <typename NumberT>
    using InterpolatedPolynomial = std::vector<NumberT>;

    namespace detail {

        template <typename NumberT>
        inline void _gauss_elimination(Matrix<NumberT> polynomialMatrix,
                                       InterpolatedPolynomial<NumberT>& interpolatedPolynomial)
        {
            auto rowCount = polynomialMatrix.size();

            if (rowCount < 2) {
                interpolatedPolynomial.insert(interpolatedPolynomial.begin(), polynomialMatrix[0][1] / polynomialMatrix[0][0]);
                return;
            }

            Matrix<NumberT> resultMatrix = {};

            for (int i = 1; i < rowCount; ++i) {
                resultMatrix.push_back({});

                double fac1 = polynomialMatrix[i - 1][0];
                double fac2 = polynomialMatrix[i][0];
                double fac = fac1 / fac2;

                auto columnCount = polynomialMatrix[i].size();
                for (int j = 1; j < columnCount; ++j) {
                    double newValue = polynomialMatrix[i - 1][j] - polynomialMatrix[i][j] * fac;
                    resultMatrix[i - 1].emplace_back(newValue);
                }
            }

            _gauss_elimination(resultMatrix, interpolatedPolynomial);
            auto resultFunctionValuePos = resultMatrix[0].size() - 1;
            double resultFunctionValue = 0;
            for (int k = interpolatedPolynomial.size(); k > 0; --k) {
                resultFunctionValue -= polynomialMatrix[0][k] * interpolatedPolynomial[k];
            }
            interpolatedPolynomial.insert(interpolatedPolynomial.begin(),
                                          resultFunctionValue / polynomialMatrix[0][resultFunctionValuePos - 1]);
        }
    } // detail

    // solve a linear equation system for unknown coefficients
    template <typename NumberT>
    inline InterpolatedPolynomial<NumberT> gauss_elimination(Matrix<NumberT> points)
    {
        // a0 + a1 x1 + a2 x1 ^ 2... = y1
        // a0 + a1 x2 + a2 x2 ^ 2... = y2
        // matrix format = {{ x1, x1 ^ 2,... y1 },
        //                  { x2, x2 ^ 2,... y2 }}
        Matrix<NumberT> polynomialMatrix;

        // rows (+1) specify the number of coefficients
        size_t pointCount = points.size() + 1;

        for (int i = 0; i < pointCount - 1; ++i) {
            //columns
            // first coefficient ist just multiplied by 1
            polynomialMatrix.push_back({1});
            for (int j = 0; j < pointCount - 2; ++j) {
                polynomialMatrix[i].emplace_back(std::pow(points[i][0], j + 1));
            }
            // emplace function value
            polynomialMatrix[i].emplace_back(points[i][1]);
        }

        InterpolatedPolynomial<NumberT> interpolatedPolynomial;
        detail::_gauss_elimination(polynomialMatrix, interpolatedPolynomial);

        return interpolatedPolynomial;
    }

} // algorithm

#endif //ALGORITHMS_GAUSS_ELIMINATION_HPP
