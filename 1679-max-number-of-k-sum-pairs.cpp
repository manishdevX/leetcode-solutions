// LINK - https://leetcode.com/problems/max-number-of-k-sum-pairs

// n = size of nums

// Solution 1, TC = O(n), SC = O(n)
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto &&num : nums)
        {
            int comp = k - num;
            if (mp[comp])
            {
                mp[comp]--;
                ans++;
            }
            else
            {
                mp[num]++;
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(nlogn), SC = O(logn)
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int s = nums[lo] + nums[hi];
            if (s < k)
            {
                lo++;
            }
            else if (s == k)
            {
                ans++;
                lo++;
                hi--;
            }
            else
            {
                hi--;
            }
        }
        return ans;
    }
};