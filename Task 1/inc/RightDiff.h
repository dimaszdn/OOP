#pragma once
#include<Diff.h>

class RightDiff : public Diff
{
public:
    double calc(const std::function<double(double)>& f, double x0) override
    {
        return (f(x0 + m_dx) - f(x0)) / m_dx;
    }
};