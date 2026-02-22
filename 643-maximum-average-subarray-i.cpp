// LINK - https://leetcode.com/problems/maximum-average-subarray-i

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int j = 0, sum = 0, max_sum = INT32_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k)
            {
                sum += nums[i];
            }
            else
            {
                max_sum = max(max_sum, sum);
                sum += (nums[i] - nums[j++]);
            }
        }
        max_sum = max(max_sum, sum);
        return (double)max_sum / k;
    }
};