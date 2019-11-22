#pragma once

#include <iostream>

#include "template.hpp"
#include "point.hpp"

template<typename T, size_t S>
class Figure {
public:
    Figure (std::istream& in) {
        std::cout << "Enter figure (6 ints)" << std::endl;
        for (size_t i = 0; i < S; i++) {
            in >> pts[i];
        }
    }
    int double_area() const;
    Point<double> center() const;
    void print(std::ostream& out) const;
    
    Point<T>& operator[] (size_t id) {
        return pts[id];
    }
    const Point<T>& operator[] (size_t id) const {
        return pts[id];
    }
    
    virtual ~Figure() {};
protected:
    Point<T> pts[S];
};

template<typename T, size_t S>
int Figure<T, S>::double_area() const {
    double ans = 0;
    for (size_t i = 1; i < S; i++) {
        ans += crossProd(pts[0], pts[i], pts[i-1]);
    }
    return std::abs(ans);
}


template<typename T, size_t S>
Point<double> Figure<T, S>::center() const {
    Point<double> ans{0, 0};
    for (size_t i = 1; i < S; i++) {
        ans += pts;
    }
    return ans / (double)(S);
}




