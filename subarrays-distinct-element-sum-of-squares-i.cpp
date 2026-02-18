// LINK - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i

// n = size of nums

// Solution 1 TC = O(n^3), SC = O(n)
class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                unordered_set<int> s;
                for (int k = i; k <= j; k++)
                {
                    s.insert(nums[k]);
                }
                ans += s.size() * s.size();
            }
        }
        return ans;
    }
};

// TC = O(n^2), SC = O(n)
// Solution 2
class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = i; j < n; j++)
            {
                s.insert(nums[j]);
                ans += s.size() * s.size();
            }
        }
        return ans;
    }
};