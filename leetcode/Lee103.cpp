#include <vector>
#include <queue>
using std::vector;
using std::queue;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for(int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight? i : levelSize - 1 - i;
                currentLevel[index] = node -> val;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }

            result.push_back(currentLevel);
            leftToRight = !leftToRight;
        }

        return result;
    }
};