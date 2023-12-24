#include<Diff.h>
#include<LeftDiff.h>
#include<RightDiff.h>
#include<CentralDiff.h>
#include<Func.h>
#include <iostream>

void test1(double x0, const std::vector<double>& points, LeftDiff* L, RightDiff* R, CentralDiff* C)
{
    L->calcDx(points); R->calcDx(points); C->calcDx(points);
    std::cout << "LeftDiff: " << L->calc(f1, x0) << "; dx = " << L->getDx() << "\n";
    std::cout << "RightDiff: " << R->calc(f1, x0) << "; dx = " << R->getDx() << "\n";
    std::cout << "CentralDiff: " << C->calc(f1, x0) << "; dx = " << C->getDx() << "\n";
}

void test2(double x0, double dx, LeftDiff* L, RightDiff* R, CentralDiff* C)
{
    L->setDx(dx); R->setDx(dx); C->setDx(dx);
    std::cout << "LeftDiff: " << L->calc(f1, x0) << "; dx = " << L->getDx() << "\n";
    std::cout << "RightDiff: " << R->calc(f1, x0) << "; dx = " << R->getDx() << "\n";
    std::cout << "CentralDiff: " << C->calc(f1, x0) << "; dx = " << C->getDx() << "\n";
}

int main()
{
    std::vector<double> points1 = {5.4, 7.2, 9.3, 11.55, 13};
    std::vector<double> points2 = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<double> points3 = {6.630,7.405,8.032,8.198,8.290,8.845,9.642,10.204,10.948,11.495};
    std::vector<double> points4 = {4};

    auto L = new LeftDiff;
    auto R = new RightDiff;
    auto C = new CentralDiff;
    try
    {
//        test1(7, points4, L, R, C);
        test2(7, 0.0324, L, R, C);
    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch (std::logic_error& ex)
    {
        std::cout << ex.what() << "\n";
    }

    delete L;
    delete R;
    delete C;

    return 0;
}
