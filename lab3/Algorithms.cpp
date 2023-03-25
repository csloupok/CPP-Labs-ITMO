#include <iostream>
#include <vector>
#include <cassert>
#include "Algorithms.h"

using namespace std;

bool is_even(int elem) {
    return (elem) % 2 == 0;
}

int main() {
    std::vector<int> v(5);
    for (int i = 0; i < 5; ++i) {
        v.push_back(i);
    }
    assert(algorithms::all_of(v.begin(), v.end(), is_even) == 0);
    v.clear();
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    assert(algorithms::all_of(v.begin(), v.end(), is_even) == 1);
    return 0;
}




