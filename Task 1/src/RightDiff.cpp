#include<RightDiff.h>

double RightDiff::calc(const std::function<double(double)> &f, double x0)
{
    return (f(x0 + m_dx) - f(x0)) / m_dx;
}
