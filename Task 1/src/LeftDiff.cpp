#include<LeftDiff.h>

double LeftDiff::calc(const std::function<double(double)> &f, double x0)
{
    return (f(x0) - f(x0 - m_dx)) / m_dx;
}