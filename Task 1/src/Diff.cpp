#include<Diff.h>

void Diff::calcDx(const std::vector<double>& points)
{
    if (!points.empty())
        setDx( (points[points.size() - 1] - points[0]) / static_cast<double>(points.size() - 1) );
    else if (points.empty() || m_dx == 0)
        throw "Points is empty or m_dx = 0!";
}

double Diff::calc(const std::function<double(double)> &f, double x0)
{
    return 0.0;
}