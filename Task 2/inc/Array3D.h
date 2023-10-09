#pragma once
#include<vector>
#include<iostream>

template<typename T, int x, int y, int z>
class Array3D
{
private:
    int m_size = x * y * z;
    std::vector<T> m_v;
public:
    Array3D(const std::vector<T>& v)
    {
        if (v.size() > m_size) //Дабы вектор сам не расширился
            throw std::out_of_range("dimensions do not match!");
        m_v = v;
    }

    int getIndex(int i, int j, int k)
    {
        return (i + j * x) + (k * x * y);
    }

    //return 2d vec
    std::vector<std::vector<T>> getValue0(int k)
    {
        std::vector<std::vector<T>> vec2d(x, std::vector<T>(y));
        int begin = this->getIndex(0, 0, k);
        int end = begin + (m_v.size() / z);
        int row = 0, col = 0;
        while (begin < end)
        {
            if (col >= y)
            {
                ++row;
                col = 0;
            }
            vec2d[row][col] = m_v[begin];
            ++col;
            ++begin;
        }
        return vec2d;
    }

    //return 1d vec
    std::vector<T> getValue1(int j) //think
    {
        std::vector<T> vec1d(y);
        int begin = this->getIndex(0, j, 0);
        int end = begin + y;
        std::copy(m_v.begin() + begin, m_v.begin + end, vec1d.begin());
//        int col = 0;
//        while (begin < end)
//        {
//            vec1d[col] = m_v[begin];
//            ++begin;
//            ++col;
//        }
        return vec1d;
    }

    int getX() { return x; }

    int getY() { return y; }

    int getZ() { return z; }
};

//template<typename T, int x = 0, int y = 0, int z = 0>
//class Array3D
//{
//private:
//    int m_cap = x * y * z;
//    T m_mas[x * y * z];
//
//public:
//    Array3D(const T(&mas)[x * y * z])
//    {
//        for (int i = 0; i < x * y * z; ++i)
//        {
//            m_mas[i] = mas[i];
//        }
//    }
//
//    T* GetValue0(int i)
//    {
//        T tmp[x * y];
//        T* pointer = this->getValue(0, 0, i);
//        std::copy(pointer, pointer + m_cap / z, tmp);
//        return tmp;
//    }
//
//    //GetValue1(int y)
//
//    //GetValue2(int z)
//
//    static void creatteFill()
//    {
//
//    }
//
//private:
//    T* getValue(int i, int j, int k)
//    {
//        return &m_mas[(i + j * x) + (k * x * y)];
//    }
//
//};