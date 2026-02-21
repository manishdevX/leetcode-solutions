// LINK - https://leetcode.com/problems/neither-minimum-nor-maximum

// n = size of nums

// Solution 1, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() > 2)
        {
            return nums[1];
        }
        return -1;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        for (auto &&num : nums)
        {
            if (num != mini && num != maxi)
            {
                return num;
            }
        }
        return -1;
    }
};