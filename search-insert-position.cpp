// LINK - https://leetcode.com/problems/search-insert-position/description/

// n = size of nums

// Solution 1 TC = O(logn), SC = O(1)

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1;
        if (target < nums[l])
        {
            return l;
        }
        if (target > nums[h])
        {
            return h + 1;
        }

        while (l <= h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else if (nums[m] > target)
            {
                h = m - 1;
            }
            else
            {
                return m;
            }
        }
        return l;
    }
};