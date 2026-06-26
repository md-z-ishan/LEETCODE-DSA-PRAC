/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()) {

            int n = q.size();
            vector<int> level(n);
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                int index = flag ? i : n - 1 - i;
                // or
                //  if(flag==true){
                //      //left to right
                //      index=i;
                //  }else{
                //      //right to left
                //      index=n-1-i;
                //  }
                level[index] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};

// flag ka hi hai jo hai isme