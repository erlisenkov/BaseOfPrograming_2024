#include <iostream>
#include <algorithm>
using namespace std;

// Структура для представления узла бинарного дерева
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Класс решения задачи
class Solution {
public:
    const int INF = 1e9;

    // Функция для нахождения максимальной суммы пути в бинарном дереве
    int maxPathSum(TreeNode* root) {
        int maxSum = -INF;  // Инициализация переменной для хранения максимальной суммы
        dfs(root, maxSum);  // Вызов рекурсивной функции для обхода дерева и поиска максимальной суммы
        return maxSum;      // Возвращение результата
    }

    // Рекурсивная функция для обхода дерева и поиска максимальной суммы
    int dfs(TreeNode *curr, int& maxSum) {
        // Базовый случай: если текущий узел равен NULL, возвращаем 0
        if (curr == NULL) return 0;

        // Рекурсивный вызов для левого поддерева и правого поддерева
        int leftSum = max(0, dfs(curr->left, maxSum));
        int rightSum = max(0, dfs(curr->right, maxSum));

        // Вычисление суммы пути, проходящего через текущий узел
        int pathSum = curr->val + leftSum + rightSum;

        // Обновление максимальной суммы, если текущая сумма больше
        maxSum = max(maxSum, pathSum);

        // Возвращение максимальной суммы, которую можно использовать для расчета выше
        return curr->val + max(leftSum, rightSum);
    }
};

// Точка входа в программу
int main() {
    // Создание простого бинарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Создание объекта класса Solution
    Solution solution;

    // Вывод максимальной суммы пути в дереве
    cout << "Max Path Sum: " << solution.maxPathSum(root) << endl;

    // Освобождение выделенной памяти
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
