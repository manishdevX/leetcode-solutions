// LINK - https://leetcode.com/problems/partition-array-according-to-given-pivot

// n = size of nums

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int left = count_if(nums.begin(), nums.end(),
                            [&](int num)
                            { return num < pivot; }) -
                   1;
        int n = nums.size(), center = left + 1, right = n - 1;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < pivot)
            {
                ans[left--] = nums[i];
            }
            else if (nums[i] > pivot)
            {
                ans[right--] = nums[i];
            }
            else
            {
                ans[center++] = nums[i];
            }
        }
        return ans;
    }
};