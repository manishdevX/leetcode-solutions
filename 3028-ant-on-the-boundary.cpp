// LINK - https://leetcode.com/problems/ant-on-the-boundary

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int count = 0, sum = 0;
        for (auto &&num : nums)
        {
            sum += num;
            if (!sum)
            {
                count++;
            }
        }
        return count;
    }
};