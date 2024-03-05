// LINK - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = -1, end = -1, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (start != -1 && end != -1)
            {
                return {start, end};
            }
            if (nums[i] == target && start == -1)
            {
                start = i;
            }
            if (nums[n - i - 1] == target && end == -1)
            {
                end = n - i - 1;
            }
        }
        return {start, end};
    }
};

// TC = O(logn), SC = O(1)
// Solution 2
class Solution
{
public:
    int lowerBound(vector<int> &nums, int l, int h, int target)
    {
        while (l <= h)
        {
            int m = (h - l) / 2 + l;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int startpos = lowerBound(nums, 0, n - 1, target);
        int endpos = lowerBound(nums, 0, n - 1, target + 1);
        if (startpos < n && nums[startpos] == target)
        {
            return {startpos, endpos - 1};
        }
        return {-1, -1};
    }
};

// TC = O(logn), SC = O(1)
// Solution 3
class Solution
{
public:
    int getPos(vector<int> &nums, int l, int h, int target, string pos)
    {
        int res = -1;
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
                res = m;
                if (pos == "start")
                {
                    h = m - 1;
                }
                else if (pos == "end")
                {
                    l = m + 1;
                }
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int startpos = getPos(nums, 0, n - 1, target, "start");
        int endpos = getPos(nums, 0, n - 1, target, "end");
        return {startpos, endpos};
    }
};