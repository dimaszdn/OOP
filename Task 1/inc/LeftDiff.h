#pragma once
#include<Diff.h>

class LeftDiff : public Diff
{
public:
    double calc(const std::function<double(double)>& f, double x0) override
    {
        return (f(x0) - f(x0 - m_dx)) / m_dx;
    }
};