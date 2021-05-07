#pragma once
#include <ostream>
#include "cmat.hpp"

namespace mat
{
    //Print
    template <Matrix M>
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

    //Add
    template <Matrix M, Matrix M2, Matrix M3 = M>
    constexpr M3 Add(const M& a, const M2& b)
    {
        M3 res(a.SizeCopy());
        for(size_t i = 0; i < a.Area(); ++i)
        {
            res.FastAt(i) = a.FastAt(i) + b.FastAt(i);
        }
        return res;
    }
    template <Matrix M, Matrix M2>
    constexpr void AddMut(M& a, const M2& b)
    {
        for(size_t i = 0; i < a.Area(); ++i)
        {
            a.FastAt(i) += b.FastAt(i);
        }
    }
    template <Matrix M>
    constexpr M ScalarAdd(const M& mat, copy_fast_t<typename M::type> v)
    {
        M res(mat.SizeCopy());
        for(size_t i = 0; i < mat.Area(); ++i)
        {
            res.FastAt(i) = mat.FastAt(i) + v;
        }
        return res;
    }
    template <Matrix M>
    constexpr void ScalarAddM(M& mat, copy_fast_t<typename M::type> v)
    {
        for(typename M::type& e : mat)
        {
            e += v;
        }
    }

    //Sub
    template <Matrix M, Matrix M2, Matrix M3 = M>
    constexpr M3 Sub(const M& a, const M2& b)
    {
        M3 res(a.SizeCopy());
        for(size_t i = 0; i < a.Area(); ++i)
        {
            res.FastAt(i) = a.FastAt(i) - b.FastAt(i);
        }
        return res;
    }
    template <Matrix M, Matrix M2>
    constexpr void SubMut(M& a, const M2& b)
    {
        for(size_t i = 0; i < a.Area(); ++i)
        {
            a.FastAt(i) -= b.FastAt(i);
        }
    }
    template <Matrix M>
    constexpr M ScalarSub(const M& mat, copy_fast_t<typename M::type> v)
    {
        M res(mat.SizeCopy());
        for(size_t i = 0; i < mat.Area(); ++i)
        {
            res.FastAt(i) = mat.FastAt(i) - v;
        }
        return res;
    }
    template <Matrix M>
    constexpr void ScalarSubM(M& mat, copy_fast_t<typename M::type> v)
    {
        for(typename M::type& e : mat)
        {
            e -= v;
        }
    }

    //Mul
    template <Matrix M, Matrix M2, Matrix M3 = M>
    constexpr M3 Mul(const M& a, const M2& b)
    {
        M3 res(a.SizeCopy());
        for(size_t i = 0; i < a.Area(); ++i)
        {
            res.FastAt(i) = a.FastAt(i) * b.FastAt(i);
        }
        return res;
    }
    template <Matrix M, Matrix M2>
    constexpr void MulMut(M& a, const M2& b)
    {
        for(size_t i = 0; i < a.Area(); ++i)
        {
            a.FastAt(i) *= b.FastAt(i);
        }
    }
    template <Matrix M>
    constexpr M ScalarMul(const M& mat, copy_fast_t<typename M::type> v)
    {
        M res(mat.SizeCopy());
        for(size_t i = 0; i < mat.Area(); ++i)
        {
            res.FastAt(i) = mat.FastAt(i) * v;
        }
        return res;
    }
    template <Matrix M>
    constexpr void ScalarMulM(M& mat, copy_fast_t<typename M::type> v)
    {
        for(typename M::type& e : mat)
        {
            e *= v;
        }
    }

    //Div
    template <Matrix M, Matrix M2, Matrix M3 = M>
    constexpr M3 Div(const M& a, const M2& b)
    {
        M3 res(a.SizeCopy());
        for(size_t i = 0; i < a.Area(); ++i)
        {
            res.FastAt(i) = a.FastAt(i) / b.FastAt(i);
        }
        return res;
    }
    template <Matrix M, Matrix M2>
    constexpr void DivMut(M& a, const M2& b)
    {
        for(size_t i = 0; i < a.Area(); ++i)
        {
            a.FastAt(i) /= b.FastAt(i);
        }
    }
    template <Matrix M>
    constexpr M ScalarDiv(const M& mat, copy_fast_t<typename M::type> v)
    {
        M res(mat.SizeCopy());
        for(size_t i = 0; i < mat.Area(); ++i)
        {
            res.FastAt(i) = mat.FastAt(i) / v;
        }
        return res;
    }
    template <Matrix M>
    constexpr void ScalarDivM(M& mat, copy_fast_t<typename M::type> v)
    {
        for(typename M::type& e : mat)
        {
            e /= v;
        }
    }

};
