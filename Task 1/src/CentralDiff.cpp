#include<CentralDiff.h>

double CentralDiff::calc(const std::function<double(double)> &f, double x0)
{
    return (f(x0 + m_dx) - f(x0 - m_dx)) / (2 * m_dx);
}

double CentralDiff::getDx()
{
    return pow(m_dx, 2);
}