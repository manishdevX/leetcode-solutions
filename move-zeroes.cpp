// LINK - https://leetcode.com/problems/move-zeroes

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int ind = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                swap(nums[i], nums[ind++]);
            }
        }
    }
};