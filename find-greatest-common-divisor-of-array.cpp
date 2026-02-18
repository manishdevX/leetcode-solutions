// LINK - https://leetcode.com/problems/find-greatest-common-divisor-of-array

// n = size of nums

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int findGCDHelper(int a, int b)
    {
        if (!b)
        {
            return a;
        }
        return findGCDHelper(b, a % b);
    }
    int findGCD(vector<int> &nums)
    {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        return findGCDHelper(maxi, mini);
    }
};

// Solution 2 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int findGCDHelper(int a, int b)
    {
        if (!b)
        {
            return a;
        }
        return findGCDHelper(b, a % b);
    }
    int findGCD(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return findGCDHelper(nums[nums.size() - 1], nums[0]);
    }
};
