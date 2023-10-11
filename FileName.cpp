#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Инициализация генератора случайных чисел
    // Вводим переменные 
    int choice;
    char operation;
    int num1;
    double num2, result;

    do {
        cout << "А как насчёт: \n" << "1 - Базовые операции \n" << "2 Сумма матриц \n" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            do {
                cout << "Введите операцию (+, -, *, /, ^, !) или q для выхода: ";
                cin >> operation;

                if (operation == 'q') {
                    break;
                }

                cout << "Введите первое число: ";
                cin >> num1;

                if (operation != '!') {
                    cout << "Введите второе число: ";
                    cin >> num2;
                }

                switch (operation) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0) {
                        result = num1 / num2;
                    }
                    else {
                        cout << "Ошибка: деление на ноль" << endl;
                        continue;
                    }
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
                case '!':
                    if (num1 < 0) {
                        cout << "Ошибка: факториал отрицательного числа" << endl;
                        continue;
                    }
                    result = 1;
                    for (int i = 1; i <= num1; i++) {
                        result *= i;
                    }
                    break;
                default:
                    cout << "Ошибка: недопустимая операция" << endl;
                    continue;
                }

                cout << "Результат: " << result << endl;
            } while (true);

            break; // Выходим из цикла выбора и возвращаемся к главному меню

        case 2:
            // Инициализация генератора случайных чисел
            srand(time(NULL));

            // Создание и заполнение первой матрицы случайными значениями
            double matrix1[3][3]{};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    matrix1[i][j] = rand() % 100; // Генерируем случайное целое число от 0 до 99
                }
            }

            // Создание и заполнение второй матрицы случайными значениями
            double matrix2[3][3]{};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    matrix2[i][j] = rand() % 100; // Генерируем случайное целое число от 0 до 99
                }
            }

            // Вывод первой матрицы
            cout << "Первая матрица:" << endl;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << matrix1[i][j] << " ";
                }
                cout << endl;
            }

            // Вывод второй матрицы
            cout << "Вторая матрица:" << endl;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << matrix2[i][j] << " ";
                }
                cout << endl;
            }

            // Сложение матриц
            double resultMatrix[3][3]{};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }

            // Вывод результата
            cout << "Результат сложения матриц:" << endl;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << resultMatrix[i][j] << " ";
                }
                cout << endl;
            }
            break; // Выходим из цикла выбора и возвращаемся к главному меню
        }
    } while (true);

    return 0;
}
