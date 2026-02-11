// LINK - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// n = size of nums

// Solution 1, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        partial_sort(nums.begin(), nums.begin() + 2, nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};

// Solution 3, TC = O(n), SC = O(1)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int max1 = INT16_MIN;
        int max2 = INT16_MIN;
        for (auto &&num : nums)
        {
            if (num > max1)
            {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};