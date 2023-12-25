#include <iostream>
#include <queue>
using namespace std;

// Класс для нахождения медианы из потока чисел
class MedianFinder {
public:
    priority_queue<int> decreasing;  // Очередь с приоритетом для убывающих значений
    priority_queue<int, std::vector<int>, std::greater<int>> increasing;  // Очередь с приоритетом для возрастающих значений
    bool even = true;  // Флаг для отслеживания четности/нечетности текущего размера потока

    // Конструктор класса
    MedianFinder() {
    }

    // Метод для добавления числа в поток
    void addNum(int num) {
        even = !even;  // Переключение флага четности/нечетности

        // Если размер потока нечетный
        if (!even) {
            decreasing.push(num);
            increasing.push(decreasing.top());
            decreasing.pop();
        } else {  // Если размер потока четный
            increasing.push(num);
            decreasing.push(increasing.top());
            increasing.pop();
        }
    }

    // Метод для нахождения медианы
    double findMedian() {
        // Если размер потока нечетный, возвращаем верхний элемент из очереди с приоритетом для возрастающих значений
        if (!even) return increasing.top();
        
        // Если размер потока четный, возвращаем среднее значение двух верхних элементов
        return (decreasing.top() + increasing.top()) / 2.0;
    }
};

// Точка входа в программу
int main() {
    // Создание объекта класса MedianFinder
    MedianFinder mf;

    // Добавление чисел в поток и вывод медианы
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << std::endl;
    mf.addNum(3);
    cout << mf.findMedian() << std::endl;

    return 0;
}
