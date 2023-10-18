#include <iostream>
#include <cmath>
#include <string>  


using namespace std;

// Функция для проверки, является ли символ числом
bool isNumber(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

// Функция для ввода числа с предупреждением
double inputNumber() {
    string input;
    while (true) {
        cin >> input;

        // Проверяем каждый символ в строке
        bool valid = true;
        for (char c : input) {
            if (!isNumber(c)) {
                valid = false;
                cout << "Ошибка: Введите допустимое число: ";
                break;
            }
        }

        if (valid) {
            return stod(input);  // Преобразуем строку в число
        }
    }
}

// Функция для выполнения базовых операций
double performBasicOperation(char operation, double num1, double num2) {
    switch (operation) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0) {
            return num1 / num2;
        }
        else {
            cout << "Ошибка: деление на ноль" << endl;
            return 0;
        }
    case '^':
        return pow(num1, num2);
    default:
        cout << "Ошибка: недопустимая операция" << endl;
        return 0;
    }
}

int main() {
    while (true) {
        link:
        cout << "А как насчёт: \n" << "1 - Базовые операции \n" << "2 Сумма матриц \n" << endl;
        string choice;
        int choice2;
        eror1:
        cin >> choice;

        try {
            // Пытаемся преобразовать строку в целое число
            choice2 = stoi(choice);
        }
        catch (const invalid_argument& e) {
            // Обрабатываем ошибку, если введенная строка не может быть преобразована в целое число
            cerr << "Ошибка: Введенная строка не является целым числом." << endl;
            goto link;
        }
        
        while (true) {
           

            if (choice2 == 1 || choice2 == 2) {
                break; // Если введено 1 или 2, выходим из цикла
            }
            else {
                std::cout << "Пожалуйста, введите 1 или 2." << std::endl;
                goto eror1;
            }
        }
            
 
        switch (choice2) {
        case 1:
            while (true) {
                cout << "Введите операцию (+, -, *, /, ^, !) или q для выхода: ";
                char operation;
                cin >> operation;

                if (operation == 'q') {
                    break;
                }

                cout << "Введите первое число: ";
                double num1 = inputNumber();

                double result = 0;

                if (operation != '!') {
                    cout << "Введите второе число: ";
                    double num2 = inputNumber();
                    result = performBasicOperation(operation, num1, num2);
                }
                else {
                    if (num1 < 0) {
                        cout << "Ошибка: факториал отрицательного числа" << endl;
                    }
                    else {
                        result = 1;
                        for (int i = 1; i <= num1; i++) {
                            result *= i;
                        }
                    }
                }

                cout << "Результат: " << result << endl;
            }
            break;

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
            break;
        }
    }

    return 0;
}