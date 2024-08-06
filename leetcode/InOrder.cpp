#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* curr = root;

        while (curr != nullptr || !stack.empty()) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(result,root);
        return result;
    }

private:
    void inorder(vector<int>& result,TreeNode* node){
        if(!node){
            return;
        }
        inorder(result, node->left);
        result.push_back(node->val);
        inorder(result,node->right);
    }
};
