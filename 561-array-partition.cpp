// LINK - https://leetcode.com/problems/array-partition/description/

// n = size of nums

// Solution 1, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            ans += nums[i];
        }
        return ans;
    }
};
