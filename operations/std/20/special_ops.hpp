#pragma once
#include <iostream>
#include "cmat.hpp"

template <typename T>
concept Printable = requires(T a)
{
    {std::cout << a} -> std::same_as<std::ostream &>;
};

namespace mat
{
    template <Matrix M>
    requires Printable<typename M::type>
    std::ostream &operator<<(std::ostream &os, const M &mat)
    {
        for (size_t i = 0; i < mat.Height(); ++i)
        {
            for (size_t j = 0; j < mat.Width(); ++j)
            {
                os << mat.At(j, i) << ' ';
            }
            os << '\n';
        }
        return os;
    }
};