// LINK - https://leetcode.com/problems/maximum-binary-tree

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    TreeNode *binaryTreeHelper(vector<int> &nums, auto start, auto end)
    {
        if (end == start)
        {
            return NULL;
        }

        auto it = max_element(start, end);
        TreeNode *left = binaryTreeHelper(nums, start, it);
        TreeNode *right = binaryTreeHelper(nums, it + 1, end);
        TreeNode *node = new TreeNode(*it, left, right);
        return node;
    }
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return binaryTreeHelper(nums, nums.begin(), nums.end());
    }
};

// Solution 2 TC = O(n), SC = O(n)
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        stack<TreeNode *> st;
        for (auto &&num : nums)
        {
            TreeNode *node = new TreeNode(num);
            while (st.size() && st.top()->val < num)
            {
                node->left = st.top();
                st.pop();
            }
            if (st.size())
            {
                st.top()->right = node;
            }
            st.push(node);
        }
        while (st.size() != 1)
        {
            st.pop();
        }
        return st.top();
    }
};