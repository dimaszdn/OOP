#include<Diff.h>

void Diff::setDx(double dx)
{
    if (dx == 0)
        throw std::logic_error("dx is zero!");
    m_dx = dx;
}

void Diff::calcDx(const std::vector<double>& points)
{
    if (points.empty())
        throw std::out_of_range("Points is empty!");

    double dx = (points[points.size() - 1] - points[0]) / static_cast<double>(points.size());
    this->setDx(dx);
}