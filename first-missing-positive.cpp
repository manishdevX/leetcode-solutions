// LINK - https://leetcode.com/problems/first-missing-positive

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        bool contains1 = false;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                contains1 = true;
            }
            if (nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = 1;
            }
        }
        if (!contains1)
        {
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            int ind = abs(nums[i]) - 1;
            if (nums[ind] > 0)
            {
                nums[ind] *= -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};
