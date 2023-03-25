#include <vector>
#include <iostream>

using CoefficientList = std::vector<double>;

//1. =
//2. ==, !=
//3. +, - (унарный и бинарный), +=, -=
//4. * , / (на число), *=, /=
//5. <<, >>
//6. [] (для получения коэффициента i-го члена)

class Polynomial {
public:
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
        return sum;
    }

    Polynomial operator-(const Polynomial &polynomial) const {
        size_t const min_size = std::min(coefficients.size(), polynomial.coefficients.size());
        Polynomial difference = *this;
        for (size_t i = 0; i < min_size; i++)
            difference.coefficients[i] -= polynomial.coefficients[i];
        return difference;
    }

    Polynomial operator*(const Polynomial &polynomial) const {
        size_t pol_size = coefficients.size() + polynomial.coefficients.size();
        std::vector<double> pol(pol_size);
        for (size_t i = 0; i != coefficients.size(); ++i) {
            for (size_t j = 0; j != polynomial.coefficients.size(); ++j)
                pol[i + j + 1] += (*this)[i] * polynomial[j];
        }
        return Polynomial{pol};
    }

    Polynomial operator/(double denominator) const {
        if (denominator != 0) {
            Polynomial quotient = *this;
            for (size_t i = 0; i < quotient.coefficients.size(); ++i) {
                quotient.coefficients[i] /= denominator;
            }
            return quotient;
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

    double operator[](size_t number) const {
        if (number >= 0 && number < coefficients.size())
            return coefficients[number];
        else
            throw std::logic_error("Wrong number!");
    }
};

std::istream &operator >> (std::istream &input, Polynomial &a)
{
    int index;
    while (index >= a.coefficients.size());
    {
        std::cin >> index;
        if (index >= a.coefficients.size())
            std::cout << "Wrong argument!" << "\n";
    }
    int number;
    if (input >> number) {
        a.coefficients[index - 1] = number;
    } else {
        std::cout << "Error" << "\n";
        exit(1);
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, Polynomial &a) {
    for (int i = 0; i < a.coefficients.size(); ++i) {
        if (a[i] == 0)
            i++;
        output << a[i] << "x" << i + 1;
        if ((i + 1) != a.coefficients.size()) {
            output << " + ";
        }
    }
    return output;
}

int main() {
    Polynomial p1{CoefficientList{2, 2, 44, 2}};
    std::cout << p1 << std::endl;

    Polynomial p2{{1, 22, 4, 1}};
    std::cout << p2 << std::endl;

    Polynomial p3 = p1 * p2;
    std::cout << p3 << std::endl;

    Polynomial p4 = p1 + p2;
    std::cout << p4 << std::endl;

    Polynomial p5 = p2 - p1;
    std::cout << p5 << std::endl;

    Polynomial p6 = p1 / 2;
    std::cout << p6 << std::endl;
    std::cin >> p6;
    std::cout << p6 << std::endl;
    return 0;
}