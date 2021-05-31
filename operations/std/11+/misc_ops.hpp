#pragma once
#include <iostream>
#include "cmat.hpp" 
#include "copy_fast.hpp"

namespace mat
{
    //Print
    template <typename M>
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

    //Fill
    template <typename M, typename T = typename M::type>
    constexpr void Fill(M &mat, copy_fast_cv_t<T> v)
    {
        for (auto &e : mat)
        {
            e = v;
        }
    }

    //ForEach
    template <Matrix M, typename F>
    constexpr void ForEach(M &mat, F &&func)
    {
        for (typename M::type &e : mat)
        {
            func(e);
        }
    }
};
