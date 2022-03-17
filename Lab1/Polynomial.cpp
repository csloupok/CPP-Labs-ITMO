#include <vector>
#include <string>
#include <iostream>

using CoefficientList = std::vector<double>;

//1. =
//2. ==, !=
//3. +, - (унарный и бинарный), +=, -=
//4. * , / (на число), *=, /=
//5. <<, >>
//6. [] (для получения коэффициента i-го члена)

class Polynomial {
private:
    CoefficientList coefficients;
public:
    Polynomial(const std::vector<double> &c) : coefficients{c} {}

    Polynomial(const Polynomial &polynomial) : coefficients(polynomial.coefficients) {}

    Polynomial &operator=(const Polynomial &polynomial) {
        if (this == &polynomial)
            return *this;
        coefficients = polynomial.coefficients;
        return *this;
    }

    bool operator==(const Polynomial &polynomial) const {
        return (coefficients.size() == polynomial.coefficients.size() &&
                std::equal(coefficients.begin(), coefficients.end(), polynomial.coefficients.begin()));
    }

    bool operator!=(const Polynomial &polynomial) const {
        return !operator==(polynomial);
    }

    Polynomial operator-() const {

    }

};

int main() {
//    Polynomial first{CoefficientList{0, 7, -5, 10}};
}