// LINK - https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = 0;
        for (auto &&num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};

// Solution 2 TC = O(logn), SC = O(1)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid > 0 && nums[mid - 1] == nums[mid])
            {
                (mid - 1) % 2 ? hi = mid - 2 : lo = mid + 1;
            }
            else if (mid < n - 1 && nums[mid] == nums[mid + 1])
            {
                (mid) % 2 ? hi = mid - 1 : lo = mid + 2;
            }
            else
            {
                return nums[mid];
            }
        }
        return -1;
    }
};

// Solution 3 TC = O(logn), SC = O(1)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            int num = mid % 2 ? mid - 1 : mid + 1;
            nums[mid] == nums[num] ? lo = mid + 1 : hi = mid;
        }
        return nums[lo];
    }
};