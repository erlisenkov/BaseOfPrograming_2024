#include "classes.h"

#include <iostream>


int main() {
    Vect first = Vect(3, new double[3] {1, 2,3});
    Vect second = Vect(3, new double[3] {1, 2,3});
    Vect third = Vect(3, new double[3]);
    //double scalar=2;
    third = first-second;
    third.printV();
    //third.printV();


//    Mat matrix1(2, 2);
//    matrix1.Value(0, 0, 1.0);
//    matrix1.Value(0, 1, 2.0);
//    matrix1.Value(1, 0, 3.0);
//    matrix1.Value(1, 1, 4.0);
//
//
//    Mat matrix2(2, 2);
//    matrix2.Value(0, 0, 1.0);
//    matrix2.Value(0, 1, 2.0);
//    matrix2.Value(1, 0, 3.0);
//    matrix2.Value(1, 1, 4.0);

//    Mat matrix2(3, 3);
//    matrix2.Value(0, 0, 9);
//    matrix2.Value(0, 1, 8);
//    matrix2.Value(0, 2, 7);
//    matrix2.Value(1, 0, 6);
//    matrix2.Value(1, 1, 5);
//    matrix2.Value(1, 2, 4);
//    matrix2.Value(2, 0, 3);
//    matrix2.Value(2, 1, 2);
//    matrix2.Value(2, 2, 1);

    //Mat matrix3(2, 2);
    //Mat matrix3 = matrix1 + matrix2;
    //Vect third=first*matrix1;

    //matrix1=matrix2;


 //Вывод значений элементов матрицы
//    std::cout << "Matrix 3:" << std::endl;
//    for (int i = 0; i < matrix3.getCols(); i++) {
//        for (int j = 0; j < matrix3.getRows(); j++) {
//             matrix3.print(i,j);
//        }
//        std::cout << std::endl;
//    }


    return 0;


}