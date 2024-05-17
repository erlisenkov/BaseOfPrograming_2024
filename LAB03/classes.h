#include "cmath"
#include "iostream"

using namespace std;

//   3  Point класс представляет точку на плоскости с координатами x и y. У
//   класса есть конструктор, который задает начальные значения координат, а
//   также метод move, который перемещает точку на заданное расстояние по осям x
//   и y.

//   2  IBaseShape это абстрактный класс, который определяет базовые методы для
//   всех геометрических фигур. Он имеет чисто виртуальные методы для отрисовки
//   (draw), стирания (erase), перемещения (move) и вращения (rotate) фигуры, а
//   также виртуальный деструктор.

//    1 Line, Square, Rectangle, Parallelogram и Rhombus являются классами,
//    которые наследуются от IBaseShape.
// В каждом из этих классов определены массивы points, представляющие вершины
// фигуры. У каждого класса есть конструктор, который инициализирует вершины
// фигуры. Классы реализуют виртуальные методы draw, erase, move и rotate для
// конкретной обработки каждого типа фигуры.

class Point {
public:
  double x, y;

  Point(double x = 0, double y = 0);

  void move(double dx, double dy);
};

class IBaseShape {
public:
  virtual void draw() = 0;

  virtual void erase() = 0;

  virtual void move(double dx, double dy) = 0;

  virtual void rotate(double angle) = 0;

  virtual ~IBaseShape() {}
};

class Line : public IBaseShape {
protected:
  Point points[2];

public:
  Line(Point p1, Point p2);

  void erase() override;

  void draw() override;

  void move(double dx, double dy) override;

  void rotate(double angle) override;
};

class Square : public IBaseShape {
public:
  Point points[4];

public:
  Square(Point p1, Point p2, Point p3, Point p4);

  void draw() override;

  void erase() override;

  void move(double dx, double dy) override;

  void rotate(double angle);
};

class Rectangle : public IBaseShape {
public:
  Point points[4];

public:
  Rectangle(Point p1, Point p2, Point p3, Point p4);

  void erase() override;

  void draw() override;

  void move(double dx, double dy) override;

  void rotate(double angle) override;
};

class Parallelogram : public IBaseShape {
public:
  Point points[4];

public:
  Parallelogram(Point p1, Point p2, Point p3, Point p4);

  void erase() override;

  void draw() override;

  void move(double dx, double dy) override;

  void rotate(double angle) override;
};

class Rhombus : public IBaseShape {
public:
  Point points[4];

public:
  Rhombus(Point p1, Point p2, Point p3, Point p4);

  void erase() override;

  void draw() override;

  void move(double dx, double dy) override;

  void rotate(double angle) override;
};
