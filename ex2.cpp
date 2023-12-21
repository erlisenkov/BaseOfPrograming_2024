#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// Функция containsNearbyAlmostDuplicate проверяет, существует ли пара индексов (i, j) такая, что
// i != j, abs(i - j) <= indexDiff, abs(nums[i] - nums[j]) <= valueDiff
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
//     Проверка на некорректные значения indexDiff и valueDiff
    if (indexDiff <= 0 || valueDiff < 0)
        return false;

//     Множество для хранения уникальных значений в окне размера indexDiff
    set<int> numSet;

//     Проход по элементам вектора nums
    for (int i = 0; i < nums.size(); ++i) {
//         Если текущий индекс больше indexDiff, удаляем значение, которое выходит за пределы окна
        if (i > indexDiff) {
            numSet.erase(nums[i - indexDiff - 1]);
        }

//         Ищем элемент в numSet, который не меньше (>=) nums[i] - valueDiff
        auto it = numSet.lower_bound(nums[i] - valueDiff);
//         Если такой элемент найден и разность между ним и nums[i] не превышает valueDiff, возвращаем true
        if (it != numSet.end() && abs(*it - nums[i]) <= valueDiff) {
            return true;
        }

//         Вставляем текущий элемент в numSet
        numSet.insert(nums[i]);
    }

//     Если не найдена пара, удовлетворяющая условиям, возвращаем false
    return false;
}

int main() {
     // Исходные данные
    vector<int> nums = {1,2,3,1};
    int indexDiff = 2;
    int valueDiff = 3;

//     Вызываем функцию containsNearbyAlmostDuplicate
    bool result = containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

//     Выводим результат в стандартный вывод
    cout << boolalpha << result << endl;

    return 0;
}
