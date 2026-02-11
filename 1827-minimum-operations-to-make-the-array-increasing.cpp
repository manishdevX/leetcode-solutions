// LINK - https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0, num = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= num)
            {
                ans += num++ - nums[i] + 1;
            }
            else
            {
                num = nums[i];
            }
        }
        return ans;
    }
};
