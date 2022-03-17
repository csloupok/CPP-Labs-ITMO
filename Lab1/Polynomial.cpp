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
    Polynomial(const CoefficientList &c) : coefficients{c} {}

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

    Polynomial operator+(const Polynomial &polynomial) const {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        Polynomial sum = *this;
        for (size_t i = 0; i < min_size; i++)
            sum.coefficients[i] += polynomial.coefficients[i];
    }

    Polynomial operator-(const Polynomial &polynomial) const {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        Polynomial difference = *this;
        for (size_t i = 0; i < min_size; i++)
            difference.coefficients[i] -= polynomial.coefficients[i];
    }

    Polynomial operator*(const Polynomial &polynomial) const {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        Polynomial composition = *this;
        for (size_t i = 0; i < min_size; i++)
            composition.coefficients[i] *= polynomial.coefficients[i];
    }

    Polynomial operator/(double denominator) const {
        if (denominator != 0) {
            Polynomial result = *this;
            for (size_t i = 0; i < result.coefficients.size(); ++i) {
                result.coefficients[i] /= denominator;
            }
            return result;
        } else
            return *this;
    }

    Polynomial &operator+=(const Polynomial &polynomial) {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        for (size_t i = 0; i < min_size; i++)
            coefficients[i] += polynomial.coefficients[i];
        return *this;
    }

    Polynomial &operator-=(const Polynomial &polynomial) {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        for (size_t i = 0; i < min_size; i++)
            coefficients[i] -= polynomial.coefficients[i];
        return *this;
    }

    Polynomial &operator*=(const Polynomial &polynomial) {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        for (size_t i = 0; i < min_size; i++)
            coefficients[i] *= polynomial.coefficients[i];
        return *this;
    }

    Polynomial &operator/=(double denominator) {
        if (denominator != 0) {
            for (size_t i = 0; i < coefficients.size(); ++i)
                coefficients[i] /= denominator;
            return *this;
        } else
            return *this;
    }

    Polynomial operator<<(uint8_t shift) const;

    Polynomial operator>>(uint8_t shift) const;
};

int main() {
//    Polynomial first{CoefficientList{0, 7, -5, 10}};
}