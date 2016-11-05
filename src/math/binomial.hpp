#ifndef ALGORITHMS_BINOM_HPP
#define ALGORITHMS_BINOM_HPP

namespace algorithm {

    // returns the resulting binomial as a string as well as its result
    template <typename NumberT>
    inline std::pair<NumberT, std::string> binom(size_t potency, NumberT summand1, NumberT summand2) {

        std::string resultStr = "(a + b)^" + std::to_string(potency) + " = ";

        if (potency == 0) {
            return std::make_pair(1, std::string());
        }

        NumberT result = 0;
        for (size_t i = 0; i <= potency; ++i) {

            // binomial coefficient
            NumberT coefficientNumerator = 1;
            NumberT coefficientDenominator = 1;

            for (int j = 1; j <= i; ++j) {
                coefficientNumerator *= potency - (j - 1);
                coefficientDenominator *= j;
            }
            NumberT binomialCoefficient = coefficientNumerator / coefficientDenominator;

            // binomial coefficient
            if (binomialCoefficient != 1) {
                resultStr += std::to_string(binomialCoefficient);
            }

            //binomial factor "a"
            resultStr += "a";
            if ((potency - i) != 1) {
                resultStr += "^" + std::to_string(potency - i);
            }
            if (i != 0) {
                resultStr += " * b";
                if (i != 1) {
                    resultStr += "^" + std::to_string(i);
                }
            }

            if (i != potency) {
                resultStr += " + ";
            }

            NumberT factor1 = std::pow(summand1, potency - i);
            NumberT factor2 = std::pow(summand2, i);
            result +=  binomialCoefficient * factor1 * factor2;
        }
        return std::make_pair(result, resultStr);
    }
}

#endif //ALGORITHMS_BINOM_HPP
