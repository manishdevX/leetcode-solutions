// LINK - https://leetcode.com/problems/smallest-index-with-equal-value

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 10 == nums[i])
            {
                return i;
            }
        }
        return -1;
    }
};