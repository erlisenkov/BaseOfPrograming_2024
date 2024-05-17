
#include "classes.h"
#include "iostream"
using namespace std;

int main() {
  Square square(
      Point(0, 0), Point(40, 0), Point(40, 40),
      Point(0,
            40)); // Создание объекта square типа Square с координатами вершин.
  square.move(2, 2); // Вызов метода move для перемещения квадрата на 2 единицы
                     // по осям x и y.
  square.rotate(
      90); // Вызов метода rotate для поворота квадрата на 90 градусов.
  square.erase(); // Вызов метода erase для стирания квадрата.

  Rectangle rectangle(Point(5, 5), Point(25, 5), Point(25, 15),
                      Point(5, 15)); // Создание объекта rectangle типа
                                     // Rectangle с координатами вершин.
  rectangle.move(2, 2); // Вызов метода move для перемещения прямоугольника на 2
                        // единицы по осям x и y.
  rectangle.rotate(
      180); // Вызов метода rotate для поворота прямоугольника на 180 градусов.

  Parallelogram parallelogram(
      Point(5, 5), Point(25, 5), Point(30, 15),
      Point(10, 15)); // Создание объекта parallelogram типа Parallelogram с
                      // координатами вершин.
  parallelogram.move(2, 2); // Вызов метода move для перемещения параллелограмма
                            // на 2 единицы по осям x и y.
  parallelogram.rotate(
      90); // Вызов метода rotate для поворота параллелограмма на 90 градусов.

  Rhombus Rhombus(
      Point(20, 10), Point(10, 30), Point(20, 50),
      Point(
          30,
          30)); // Создание объекта rhombus типа Rhombus с координатами вершин.
  Rhombus.move(
      2,
      2); // Вызов метода move для перемещения ромба на 2 единицы по осям x и y.
  Rhombus.rotate(90); // Вызов метода rotate для поворота ромба на 90 градусов.
}