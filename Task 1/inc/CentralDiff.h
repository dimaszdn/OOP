#pragma once
#include<Diff.h>

class CentralDiff : public Diff
{
public:
    double calc(const std::function<double(double)>& f, double x0) override;

    double getDx() override;
};