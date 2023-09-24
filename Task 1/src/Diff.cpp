#include<Diff.h>

void Diff::calcDx(const std::vector<double>& points)
{
    if (points.empty())
        throw std::out_of_range("Points is empty!");
    if ((points[points.size() - 1] - points[0]) / static_cast<double>(points.size() - 1) == 0)
        throw std::logic_error("m_dx is zero!");
    setDx( (points[points.size() - 1] - points[0]) / static_cast<double>(points.size() - 1) );
}

double Diff::calc(const std::function<double(double)> &f, double x0)
{
    return 0.0;
}