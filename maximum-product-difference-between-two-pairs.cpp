// LINK - https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

// TC = O(nlogn), SC = O(1)
// Solution 1
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n - 1] * nums[n - 2]) - (nums[1] * nums[0]);
    }
};

// TC = O(n), SC = O(1)
// Solution 2
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        partial_sort(nums.begin(), nums.begin() + 2, nums.end());
        int firstmin = nums[0], secmin = nums[1];

        partial_sort(nums.begin(), nums.begin() + 2, nums.end(), greater<int>());
        int firstmax = nums[0], secmax = nums[1];

        return firstmax * secmax - firstmin * secmin;
    }
};

// TC = O(n), SC = O(1)
// Solution 3
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int firstmin = INT16_MAX, secmin = INT16_MAX, firstmax = INT16_MIN, secmax = INT16_MIN;

        for (auto &&num : nums)
        {
            if (num < firstmin)
            {
                secmin = firstmin;
                firstmin = num;
            }
            else if (num < secmin)
            {
                secmin = num;
            }

            else if (num > firstmax)
            {
                secmax = firstmax;
                firstmax = num;
            }
            else if (num > secmax)
            {
                secmax = num;
            }
        }

        return firstmax * secmax - firstmin * secmin;
    }
};