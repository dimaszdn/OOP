#pragma once
#include<iostream>
#include<functional>
#include<vector>

class Diff
{
protected:
    double m_dx{};

public:
    void setDx(double dx);

    virtual double getDx() { return m_dx; }

    void calcDx(const std::vector<double>& points);

    virtual double calc(const std::function<double(double)>& f, double x0) { return 0.0; }
};
