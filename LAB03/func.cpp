#include "classes.h"
#include "cmath"
#include "iostream"

using namespace std;
// тут находится код с изменениями

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

void Point::move(double dx, double dy) {
  x += dx;
  y += dy;
}

Line::Line(Point p1, Point p2) {
  points[0] = p1;
  points[1] = p2;
}

void Line::draw() { cout << "Line was drew" << endl; }

void Line::erase() { cout << "Line was erased" << endl; }

void Line::move(double dx, double dy) {
  for (auto &point : points) {
    point.move(dx, dy);
  }
}

void Line::rotate(double angle) {
  double angleR = angle * M_PI / 180;
  double centerX, centerY;
  for (auto &point : points) {
    centerX += point.x;
    centerY += point.y;
  }
  centerX /= 2;
  centerY /= 2;
  for (auto &point : points) {
    double oldX = point.x;
    point.x = (point.x - centerX) * cos(angleR) -
              (point.y - centerY) * sin(angleR) + centerX;
    point.y = (oldX - centerX) * sin(angleR) +
              (point.y - centerY) * cos(angleR) + centerX;
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}

Square::Square(Point p1, Point p2, Point p3, Point p4) {
  points[0] = p1;
  points[1] = p2;
  points[2] = p3;
  points[3] = p4;
}

void Square::draw() { cout << "The square is drew" << endl; }

void Square::erase() { cout << "The square is erased" << endl; }

void Square::move(double dx, double dy) {
  for (auto &point : points) {
    point.move(dx, dy);
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}

void Square::rotate(double angle) {
  double angleR = angle * M_PI / 180;
  double centerX, centerY;
  centerX = (points[0].x + points[2].x) / 2;
  centerY = (points[0].y + points[2].y) / 2;
  double sinA = sin(angleR);
  double cosA = cos(angleR);
  for (auto &point : points) {
    double oldX = point.x;
    double oldY = point.y;
    point.x = (oldX - centerX) * cosA - (oldY - centerY) * sinA + centerX;
    point.y = (oldX - centerX) * sinA + (oldY - centerY) * cosA + centerY;
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
  points[0] = p1;
  points[1] = p2;
  points[2] = p3;
  points[3] = p4;
}

void Rectangle::draw() { cout << "Rectangle was drew" << endl; }

void Rectangle::erase() { cout << "Rectangle was erased" << endl; }

void Rectangle::move(double dx, double dy) {
  for (auto &point : points) {
    point.move(dx, dy);
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}

void Rectangle::rotate(double angle) {
  double angleR = angle * M_PI / 180;
  double centerX, centerY;
  centerX = (points[0].x + points[2].x) / 2;
  centerY = (points[0].y + points[2].y) / 2;
  double sinA = sin(angleR);
  double cosA = cos(angleR);
  for (auto &point : points) {
    double oldX = point.x;
    double oldY = point.y;
    point.x = (oldX - centerX) * cosA - (oldY - centerY) * sinA + centerX;
    point.y = (oldX - centerX) * sinA + (oldY - centerY) * cosA + centerY;
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
  cout << centerX << endl;
  cout << centerY;
}

Parallelogram::Parallelogram(Point p1, Point p2, Point p3, Point p4) {
  points[0] = p1;
  points[1] = p2;
  points[2] = p3;
  points[3] = p4;
}

void Parallelogram::draw() { cout << "Parallelogram was drew" << endl; }

void Parallelogram::erase() { cout << "Parallelogram was erased" << endl; }

void Parallelogram::move(double dx, double dy) {
  for (auto &point : points) {
    point.move(dx, dy);
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}
void Parallelogram::rotate(double angle) {
  double angleR = angle * M_PI / 180;
  double centerX, centerY;
  centerX = (points[0].x + points[2].x) / 2;
  centerY = (points[0].y + points[2].y) / 2;
  double sinA = sin(angleR);
  double cosA = cos(angleR);
  for (auto &point : points) {
    double oldX = point.x;
    double oldY = point.y;
    point.x = (oldX - centerX) * cosA - (oldY - centerY) * sinA + centerX;
    point.y = (oldX - centerX) * sinA + (oldY - centerY) * cosA + centerY;
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}

Rhombus::Rhombus(Point p1, Point p2, Point p3, Point p4) {
  points[0] = p1;
  points[1] = p2;
  points[2] = p3;
  points[3] = p4;
}

void Rhombus::draw() { cout << "Parallelogram was drew" << endl; }

void Rhombus::erase() { cout << "Parallelogram was erased" << endl; }

void Rhombus::move(double dx, double dy) {
  for (auto &point : points) {
    point.move(dx, dy);
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}
void Rhombus::rotate(double angle) {
  double angleR = angle * M_PI / 180;
  double centerX, centerY;
  centerX = (points[0].x + points[2].x) / 2;
  centerY = (points[0].y + points[2].y) / 2;
  double sinA = sin(angleR);
  double cosA = cos(angleR);
  for (auto &point : points) {
    double oldX = point.x;
    double oldY = point.y;
    point.x = (oldX - centerX) * cosA - (oldY - centerY) * sinA + centerX;
    point.y = (oldX - centerX) * sinA + (oldY - centerY) * cosA + centerY;
    cout << "(" << point.x << ", " << point.y << ")" << endl;
  }
}
