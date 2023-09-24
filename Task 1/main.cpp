#include<Diff.h>
#include<LeftDiff.h>
#include<RightDiff.h>
#include<CentralDiff.h>
#include<Func.h>
#include <iostream>

int main()
{
    std::vector<double> points1 = {5.4, 7.2, 9.3, 11.55, 13};
    std::vector<double> points2 = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<double> points3 = {6.630,7.405,8.032,8.198,8.290,8.845,9.642,10.204,10.948,11.495};
    std::vector<double> points4 = {};

    auto L = new LeftDiff;
    auto R = new RightDiff;
    auto C = new CentralDiff;
    try
    {
        L->calcDx(points4);
        R->calcDx(points4);
        C->calcDx(points4);
        std::cout << "LeftDiff: " << L->calc(func, 7) << "; dx = " << L->getDx() << "\n";
        std::cout << "RightDiff: " << R->calc(func, 7) << "; dx = " << R->getDx() << "\n";
        std::cout << "CentralDiff: " << C->calc(func, 7) << "; dx = " << C->getDx() << "\n";
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
