/*Лабораторная работа №7 №8
«Перегрузка операторов»
«Шаблоны и тестирование»*/



#include <iostream>
#include <cassert>
#include "matrix.h"

using namespace math;

int main()
{
    std::cout << "=== Test 1 ===" << std::endl; {
    Mat22i A({ {
                       {1,2},
                       {3,4}
               } });



    Vec2d X({ {
                      {1},
                      {1}
              } });

    auto B = A * X;

    assert(B.get(0, 0) == 3);
    assert(B.get(1, 0) == 7); }


    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 2 ===" << std::endl; {
        Mat22d A({ {
                           {1.6,2.3},
                           {3.3,4.9}
                   } });

        Mat33i B({ {
                           {1,1,2},
                           {3,1,2},
                           {2,3,2}
                   } });
        auto a = A.getDet();
        auto b = B.getDet();

        assert(abs(a - 0.25) < 0.01);
        assert(abs(b - 8) < 0.01);

    } std::cout << "Done!" << std::endl;

    std::cout << "=== Test 3 ===" << std::endl; {
        Mat22d A({ {
                           {1.2,2.2},
                           {3.3,4.4}
                   } });

        Mat33i B({ {
                           {1,1,3},
                           {1,1,2},
                           {2,3,2}
                   } });

        auto C = A.transpose();
        auto D = B.transpose();

        assert(abs(C.get(0, 1) - 3.3) < 0.01);
        assert(D.get(1, 1) == 1);


    }  std::cout << "Done!" << std::endl;

    std::cout << "=== Test 4 ===" << std::endl; {
        Mat22d A({ {
                           {1.6,2.3},
                           {3.3,4.9}
                   } });

        Mat22i B({ {
                           {1,4},
                           {3,4}
                   } });
        try {
            auto C = A.getInverseMatrix<double>();
            auto D = B.getInverseMatrix<double>();

            assert(abs(C.get(0, 1) + 9.2) < 0.01);
            assert(abs(D.get(0, 1) - 0.5) < 0.01);

        } catch (const std::logic_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }  std::cout << "Done!" << std::endl;


    std::cout << "=== Test 5 ===" << std::endl; {
        Mat22d A({ {
                           {1,1},
                           {1,1}
                   } });


        Vec2d X({ {
                          {1},
                          {1}
                  } });

        auto B = A * X;

        assert(B.get(0, 0) == 2);
        assert(B.get(1, 0) == 2);
    }

    std::cout << "Done!" << std::endl;

    return 0;
}
