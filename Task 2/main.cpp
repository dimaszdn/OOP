#include <iostream>
#include<Array3D.h>
#include<vector>

template<typename T>
void print_vec(std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            std::cout << v[i][j] << " ";
        std::cout << "\n";
    }
}

int main()
{
//    // { { {1, 4}, {5, 6} },| { {2, 3}, {7, 8} } }
////    Array3D<int, 2, 2, 2> a({1, 4, 5, 6, 2, 3, 7, 8});
//    Array3D<int, 3, 2, 3> a({1, 4, 80, 5, 6, 2, 3, 0, 7, 8, 13, 12, 10, 11, 9, 76, 45});
//    int* mas = a.GetValue0(1);
//    for (int i = 0; i < 6; ++i)
//        std::cout << mas[i] << " ";
//
////    std::cout << N;
    try
    {
        Array3D<int, 3, 2, 3> a({1, 4, 80, 5, 6, 2, 3, 0, 7, 8, 13, 12, 10, 11, 9, 76, 45});
        Array3D<int, 3, 2, 3> a1({});
//        std::vector<std::vector<int>> v = a.getValue0(0);
//        print_vec(v);
        std::vector<std::vector<int>> v = {{1, 2}, {3}};
        std::vector<std::vector<int>> v1 = a1.getValue0(0);
//        std::vector<int> v2 = a.getValue1(1);
        print_vec(v1);

    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
