// LINK - https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order

// n = size of nums

// Solution 1 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (sum2 > sum1)
            {
                break;
            }
            ans.push_back(nums[i]);
            sum1 -= nums[i];
            sum2 += nums[i];
        }
        return ans;
    }
};