#pragma once

#include <iostream>
#include <tuple>
#include <cmath>

// read tuple
template<size_t I, class... Ts>
struct reader {
    static void read(std::istream& i, std::tuple<Ts...>& t) {
        i >> std::get<I>(t);
        reader<I - 1, Ts...>::read(i, t);
    }
};

template<class... Ts>
struct reader<0, Ts...> {
    static void read(std::istream& i, std::tuple<Ts...>& t) {
        i >> std::get<0>(t);
    }
};

template<class... Ts>
void read(std::istream& i, std::tuple<Ts...>& t) {
    reader<sizeof...(Ts) - 1, Ts...>::read(i, t);
}
// end read tuple

// point functions
template<class T>
T crossProd(Point<T> b, Point<T> a, Point<T> c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

template<class T>
T scalarProd(Point<T> b, Point<T> a, Point<T> c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.x - a.x);
}

template<class T>
T dist(Point<T> a, Point<T> b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
// end point functions
