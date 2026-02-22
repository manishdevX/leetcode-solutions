// LINK - https://leetcode.com/problems/increasing-triplet-subsequence

// n = size of nums

// Solution 1, TC = O(n), SC = O(n)
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size(), mini = nums[0], maxi = nums[n - 1];
        vector<int> lsi(n), rli(n);

        for (int i = 0; i < n; i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[n - i - 1]);
            lsi[i] = mini;
            rli[n - i - 1] = maxi;
        }
        for (int i = 0; i < n; i++)
        {
            if (lsi[i] < nums[i] && nums[i] < rli[i])
            {
                return true;
            }
        }
        return false;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first = nums[0], second = INT32_MAX;

        for (auto third : nums)
        {
            if (third > second)
            {
                return true;
            }
            else if (third > first)
            {
                second = third;
            }
            else
            {
                first = third;
            }
        }
        return false;
    }
};
