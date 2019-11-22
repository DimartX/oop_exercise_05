#pragma once

#include <iostream>

#include "point.hpp"
#include "figure.hpp"

template<class T>
class Triangle : public Figure<T, 3> {
public:
    Triangle() = default;
    Triangle(std::istream& in) : Figure<T, 3>(in) {};

    void print(std::ostream& out) const {
        out << "Triangle: " << std::endl;
        for (int i = 0; i < 3; i++) {
            out << Figure<T, 3>::pts[i] << std::endl;
        }
    }
    ~Triangle() {};
};

template<class T>
std::ostream& operator<< (std::ostream& out, const Triangle<T>& tri) {
    tri.print(out);
    return out;
}
