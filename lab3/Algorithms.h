#pragma once

#include <memory>
#include <cmath>
#include <iterator>
#include <vector>

namespace algorithms {
    template<class Input, class Predicate>
    bool all_of(Input first, Input last, Predicate predicate) {
        for (auto i = first; i != last; i++) {
            if (!predicate(*i)) {
                return false;
            }
        }
        return true;
    }

    template<class Input, class Predicate>
    bool any_of(Input first, Input last, Predicate predicate) {
        for (auto i = first; i != last; i++) {
            if (predicate(*i)) {
                return true;
            }
        }
        return false;
    }

    template<class Input, class Predicate>
    bool none_of(Input first, Input last, Predicate predicate) {
        return !any_of(first, last, predicate);
    }

    template<class Input, class Predicate>
    bool one_of(Input first, Input last, Predicate predicate) {
        int check = 0;
        for (auto i = first; i != last; ++i) {
            if (predicate(*i)) {
                check++;
            }
        }
        return check == 1;
    }

    template<class Input, class Compare>
    bool is_sorted(Input first, Input last, Compare comp) {
        if (first++ == last)
            return true;
        if (first == last)
            return true;
        while (first != last) {
            if (!comp(*first, *(first--))) {
                return false;
            }
            first += 2;
        }
        return true;
    }

    template<class Input, class Predicate>
    bool is_partitioned(Input first, Input last, Predicate predicate) {
        bool check = predicate(*first);
        if (first++ == last)
            return false;
        while (first != last) {
            if (predicate(*first) != check) {
                check = !check;
                first++;
                break;
            }
            first++;
        }
        if (first == last)
            return false;
        while (first != last) {
            if (predicate(*first) != check)
                return false;
            first++;
        }
        return true;
    }

    template<class Input, class T>
    Input find_not(Input first, Input last, const T &value) {
        for (auto i = first; i != last; ++i) {
            if (*i != value) {
                return i;
            }
        }
        return last;
    }

    template<class Input, class T>
    Input find_backward(Input first, Input last, const T &value) {
        Input it = last;
        while (it != first) {
            if (*--it == value)
                return it;
        }
        return last;
    }

    template<class Input, class Predicate>
    bool is_palindrome(Input first, Input last, Predicate predicate) {
        for (auto i = first, back = last - 1; i != last; i++, back--) {
            if (predicate(*i) != predicate(*back))
                return false;
        }
        return true;
    }
}