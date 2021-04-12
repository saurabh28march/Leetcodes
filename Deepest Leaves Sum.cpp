/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int sum = root->val;
        int ans = sum;
        while (!q.empty())
        {
            int cnt = q.size();
            ans = sum;
            sum = 0;
            while (cnt--)
            {
                TreeNode *temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }

        return sum;
    }
};