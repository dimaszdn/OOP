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
    Array3D()
    {
        m_v.resize(m_size);
    }

    explicit Array3D(const std::vector<T>& v)
    {
        if (v.size() > m_size)
            throw std::out_of_range("Dimensions do not match!");
        m_v = v;
    }

    //return vec2d
    std::vector<std::vector<T>> getValue0(int i) //0
    {
        std::vector<std::vector<T>> vec2d;
        std::vector<T> vec1d;
        for (int a = 0; a < y; ++a)
        {
            if (!vec1d.empty())
                vec1d.clear();
            for (int b = 0; b < z; ++b)
            {
                vec1d.push_back(this->getValue(i, a, b));
            }
            vec2d.push_back(vec1d);
        }
        return vec2d;
    }

    //return vec2d
    std::vector<std::vector<T>> getValue1(int j) //1
    {
        std::vector<std::vector<T>> vec2d;
        std::vector<T> vec1d;
        for (int a = 0; a < x; ++a)
        {
            if (!vec1d.empty())
                vec1d.clear();
            for (int b = 0; b < z; ++b)
            {
                vec1d.push_back(this->getValue(a, j, b));
            }
            vec2d.push_back(vec1d);
        }
        return vec2d;
    }

    //return vec2d
    std::vector<std::vector<T>> getValue2(int k) //1
    {
        std::vector<std::vector<T>> vec2d;
        std::vector<T> vec1d;
        for (int a = 0; a < x; ++a)
        {
            if (!vec1d.empty())
                vec1d.clear();
            for (int b = 0; b < y; ++b)
            {
                vec1d.push_back(this->getValue(a, b, k));
            }
            vec2d.push_back(vec1d);
        }
        return vec2d;
    }

    //return vec1d
    std::vector<T> getValues01(int i, int j) //1 1
    {
        std::vector<T> vec1d;
        for (int c = 0; c < z; ++c)
            vec1d.push_back(this->getValue(i, j, c));
        return vec1d;
    }

    //return vec1d
    std::vector<T> getValues02(int i, int k) // 1 1
    {
        std::vector<T> vec1d;
        for (int b = 0; b < y; ++b)
            vec1d.push_back(this->getValue(i, b, k));
        return vec1d;
    }

    //return vec1d
    std::vector<T> getValues12(int j, int k) // 1 1
    {
        std::vector<T> vec1d;
        for (int a = 0; a < x; ++a)
            vec1d.push_back(this->getValue(a, j, k));
        return vec1d;
    }

    //set vec2d
    void setValue0(const std::vector<std::vector<T>>& vec2d, int i) //1 {A} = {{0, 0, 0}, {0, 0}};  C = {{500, 600}, {700}};
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; ++k)
            {
                if (j < vec2d.size() && k < vec2d[j].size())
                    this->setValue(i, j, k, vec2d[j][k]);
            }
        }
    }

    //set vec2d
    void setValue1(const std::vector<std::vector<T>>& vec2d, int j) //0 A
    {
        for (int i = 0; i < x; ++i)
        {
            for (int k = 0; k < z; ++k)
            {
                if (i < vec2d.size() && k < vec2d[i].size())
                    this->setValue(i, j, k, vec2d[i][k]);
            }
        }
    }

    //set vec2d
    void setValue2(const std::vector<std::vector<T>>& vec2d, int k) // C 2
    {
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                if (i < vec2d.size() && j < vec2d[i].size())
                    this->setValue(i, j, k, vec2d[i][j]);
            }
        }
    }

    //set vec1d
    void setValue01(const std::vector<T>& vec1d, int i, int j) // B = {0, 0, 0, 0}; D = {500, 600, 700, 800, 900}; B 1 0
    {
        for (int k = 0; k < z; ++k)
        {
            if (k < vec1d.size())
                this->setValue(i, j, k, vec1d[k]);
        }
    }

    //set vec1d
    void setValue02(const std::vector<T>& vec1d, int i, int k) // B 0 1
    {
        for (int j = 0; j < y; ++j)
        {
            if (j < vec1d.size())
                this->setValue(i, j, k, vec1d[j]);
        }
    }

    //set vec1d
    void setValue12(const std::vector<T>& vec1d, int j, int k) // D 1 1
    {
        for (int i = 0; i < x; ++i)
        {
            if (i < vec1d.size())
                this->setValue(i, j, k, vec1d[i]);
        }
    }

    static Array3D* createFill(T value)
    {
        auto* object = new Array3D<T, x, y, z>();
        object->fillVec(value);
        return object;
    }

    void print()
    {
        bool flag;
        for (int i = 0; i < m_v.size(); ++i)
        {
            flag = true;
            if (i % (m_size / z) == 0 && i != 0)
            {
                std::cout << "| ";
                flag = false;
            }
            if (flag && i % x == 0 && i != 0)
            {
                std::cout << ", ";
            }
            std::cout << m_v[i] << " ";
        }

        std::cout << "\n";
    }

private:
    int getValue(int i, int j, int k)
    {
        int index = (m_size / x) * i + (m_size / (x * y)) * j + k;
        if (index >= m_size)
            throw std::out_of_range("Invalid index!");
        return m_v[index];
    }

    void setValue(int i, int j, int k, T value)
    {
        int index = (m_size / x) * i + (m_size / (x * y)) * j + k;
        if (index >= m_size)
            throw std::out_of_range("Invalid index!");
        m_v[index] = value;
    }

    void fillVec(T value)
    {
        std::fill(m_v.begin(), m_v.end(), value);
    }
};