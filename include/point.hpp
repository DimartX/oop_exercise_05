#pragma once

#include <iostream>

template<class T>
struct Point {
    T x, y;

    Point(T x, T y) : x(x), y(y) {};
    Point() = default;
};

template<class T>
std::istream& operator>> (std::istream& in, Point<T>& pt) {
    in >> pt.x >> pt.y;
    return in;
}

template<class T>
std::ostream& operator<< (std::ostream& out, Point<T> const& pt) {
    out << pt.x << ' ' << pt.y;
    return out;
}

template<class T>
Point<T> operator+ (Point<T> const& a, Point<T> const& b) {
    return Point<T>{a.x + b.x, a.y + b.y};
}

template<class T>
Point<T> operator- (Point<T> const& a, Point<T> const& b) {
    return Point<T>{a.x - b.x, a.y - b.y};
}

template<class T>
Point<T> operator* (Point<T> const& a, double const& b) {
    return Point<T>{a.x * b, a.y * b};
}

template<class T>
Point<T> operator/ (Point<T> const& a, double const& b) {
    return Point<T>{a.x / b, a.y / b};
}

