#include "gtest/gtest.h"

using namespace std;

template<int T>
class Polynomial {
private:
    int coefficients[T]{};
public:
    constexpr Polynomial(initializer_list<int> temp) {
        int n = 0;
        for (int i: temp) {
            coefficients[n] = i;
            n++;
        }
    }

    constexpr int Calculate(int x) const {
        cout << "Value of polynomial in point X:\n";
        int value = 0;
        for (int i = 0; i < T; i++) {
            int temp = 1;
            for (int j = 0; j < i; j++)
                temp *= x;
            value += temp * coefficients[i];
        }
        return value;
    }

    friend ostream &operator<<(ostream &output, const Polynomial &polynomial) {
        output << "Given polynomial:\n";
        for (int i = 0; i < T; i++)
            output << polynomial.coefficients[i] << "*" << "x" << "(" << i << ") ";
        return output;
    };
};


TEST(Polynomial, test) {
    Polynomial<5> pol = {1, 0, 2, 0, 1};
    EXPECT_EQ(pol.Calculate(3), 100);
}


int main() {
    constexpr Polynomial<5> polynomial({1, 0, 2, 0, 1});
    cout << polynomial << "\n" << polynomial.Calculate(3) << "\n";

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}