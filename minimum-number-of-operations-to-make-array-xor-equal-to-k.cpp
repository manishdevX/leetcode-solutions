// LINK - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int xr = k, ans = 0;
        for (auto &&num : nums)
        {
            xr ^= num;
        }
        while (xr)
        {
            ans += (xr & 1);
            xr >>= 1;
        }
        return ans;
    }
};
