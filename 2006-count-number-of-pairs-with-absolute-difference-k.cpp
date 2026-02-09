// LINK - https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

// n = size of nums

// solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
