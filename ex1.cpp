#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    const int INF = 1e9;

    int maxPathSum(TreeNode* root) {
        int maxSum = -INF;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode *curr, int& maxSum) {
        if (curr == NULL) return 0;

        int leftSum = max(0, dfs(curr->left, maxSum));
        int rightSum = max(0, dfs(curr->right, maxSum));

        int pathSum = curr->val + leftSum + rightSum;
        maxSum = max(maxSum, pathSum);

        return curr->val + max(leftSum, rightSum);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;

    cout << "Max Path Sum: " << solution.maxPathSum(root) << endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
