// TC = MC = O(n)
class Solution {
public:
    // node ta left node kina r leaf node kina ei duita condition check kora lgbe. Jodi hoy taile oi node er value add korbo
    int getLeftLeafSum(TreeNode* root, bool isLeft) {
        if (!root) return 0;
        if (isLeft && !root->left && !root->right) return root->val;
        int left =  getLeftLeafSum(root->left, true);
        int right = getLeftLeafSum(root->right, false);
        return left + right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return getLeftLeafSum(root, false);
    }
};


class Solution {
public:
    // node ta left node kina r leaf node kina ei duita condition check kora lgbe. Jodi hoy taile oi node er value add korbo
    // condition same but implementation different

    int getLeftLeafSum(TreeNode* root) {
        if (!root) return 0;
        int left = 0;
        if (root->left) {// left node exists kore kina check korchi
            // leaf node kina check korchi. leaf node er both side NULL hbe
            if (!root->left->left && !root->left->right) { // test case-1 er left side dekho
                left += root->left->val;
            }
            else { // leaf node na hole
                left += getLeftLeafSum(root->left);
            }
        }
        int right = getLeftLeafSum(root->right);
        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return getLeftLeafSum(root);
    }
};