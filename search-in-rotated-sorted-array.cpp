// LINK - https://leetcode.com/problems/search-in-rotated-sorted-array

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};

// Solution 2 TC = O(logn), SC = O(1)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[lo] <= nums[mid])
            {
                if (target >= nums[lo] && target < nums[mid])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else if (nums[hi] >= nums[mid])
            {
                if (target > nums[mid] && target <= nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};