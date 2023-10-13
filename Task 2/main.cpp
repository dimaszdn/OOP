#include <iostream>
#include<Array3D.h>
#include<vector>

template<typename T>
void print_vec2d(const std::vector<std::vector<T>>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            std::cout << v[i][j] << " ";
        if (i != v.size() - 1)
            std::cout << "| ";
    }
    std::cout << "\n";
}

template<typename T>
void print_vec1d(const std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    try
    {
        Array3D<int, 3, 2, 3> a1({1, 4, 80, 5, 6, 2, 3, 0, 7, 8, 13, 12, 10, 11, 9, 76, 45, 30});
        Array3D<int, 2, 2, 2> a2({1, 4, 5, 6, 2, 3, 7, 8});

        std::cout << "Getters" << "\n";

        std::cout << "[Array3D]: ";
        a1.print();
        std::vector<std::vector<int>> v1 = a1.getValue0(0);
        std::cout << "[getValue0]: ";
        print_vec2d(v1);

        std::vector<std::vector<int>> v2 = a1.getValue1(1);
        std::cout << "[getValue1]: ";
        print_vec2d(v2);

        std::vector<std::vector<int>> v3 = a1.getValue2(1);
        std::cout << "[getValue2]: ";
        print_vec2d(v3);

        std::cout << "\n";

        std::vector<int> v4 = a1.getValues01(1, 1);
        std::cout << "[getValues01]: ";
        print_vec1d(v4);

        std::vector<int> v5 = a1.getValues02(1, 1);
        std::cout << "[getValues02]: ";
        print_vec1d(v5);

        std::vector<int> v6 = a1.getValues12(1, 1);
        std::cout << "[getValues12]: ";
        print_vec1d(v6);

        std::cout << "\n";
        //####################################

        std::cout << "Setters" << "\n";

        std::vector<std::vector<int>> A = {{0, 0, 0}, {0, 0}};
        std::vector<std::vector<int>> C = {{500, 600}, {700}};

        std::cout << "[Array3D]: "; a1.print();

        a1.setValue0(A, 1);
        std::cout << "[setValue0]: ";
        a1.print();

        a1.setValue1(A, 0);
        std::cout << "[setValue1]: ";
        a1.print();

        a1.setValue2(C, 2);
        std::cout << "[setValue2]: ";
        a1.print();

        std::cout << "\n";

        std::vector<int> B = {0, 0, 0, 0};
        std::vector<int> D = {500, 600, 700, 800, 900};

        std::cout << "[Array3D]: "; a2.print();

        a2.setValue01(B, 1, 0);
        std::cout << "[setValue01]: ";
        a2.print();

        a2.setValue02(B, 0, 1);
        std::cout << "[setValue02]: ";
        a2.print();

        a2.setValue12(D, 1, 1);
        std::cout << "[setValue12]: ";
        a2.print();

        auto* a3 = Array3D<int, 4, 3, 2>::createFill(5);
        a3->print();
        delete a3;
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
