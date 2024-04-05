// LINK - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0, left = 0, right = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (!nums[i])
            {
                ans = max(ans, left + right);
                left = right;
                right = 0;
            }
            else
            {
                right++;
            }
        }
        ans = max(ans, left + right);
        ans == n ? ans-- : ans;
        return ans;
    }
};
