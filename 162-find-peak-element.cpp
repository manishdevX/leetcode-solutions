// LINK - https://leetcode.com/problems/find-peak-element

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return i;
            }
        }
        return n - 1;
    }
};

// Solution 2, TC = O(logn), SC = O(1)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size(), l = 0, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (m > 0 && nums[m - 1] > nums[m])
            {
                r = m - 1;
            }
            else if (m < n - 1 && nums[m + 1] > nums[m])
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
};

// Solution 3, TC = O(logn), SC = O(1)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > nums[m + 1])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};

// Solution 4, TC = O(logn), SC = O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        int lo = 1, hi = n - 2;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};