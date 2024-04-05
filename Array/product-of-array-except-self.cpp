// LINK - https://leetcode.com/problems/product-of-array-except-self/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pp(n, 1);
        vector<int> sp(n, 1);
        vector<int> ans(n);
        for (int i = 1; i < n; i++)
        {
            pp[i] = pp[i - 1] * nums[i - 1];
            sp[n - i - 1] = sp[n - i] * nums[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = pp[i] * sp[i];
        }
        return ans;
    }
};