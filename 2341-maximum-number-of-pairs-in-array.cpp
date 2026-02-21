// LINK - https://leetcode.com/problems/maximum-number-of-pairs-in-array

// n = size of nums

// Solution 1, TC = O(nlogn), SC = O(logn)
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans(2, 0);
        ans[1] = nums.size();
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                ans[0]++;
                i++;
                ans[1] -= 2;
            }
            i++;
        }
        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        vector<int> ans(2, 0);
        unordered_map<int, int> mp;
        for (auto &&num : nums)
        {
            mp[num]++;
        }

        for (auto &&it : mp)
        {
            ans[0] += it.second / 2;
            ans[1] += it.second % 2;
        }
        return ans;
    }
};

// Solution 3, TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        vector<int> ans(2, 0);
        unordered_set<int> s;
        for (auto &&num : nums)
        {
            if (s.find(num) != s.end())
            {
                ans[0]++;
                s.erase(num);
            }
            else
            {
                s.insert(num);
            }
        }
        ans[1] = s.size();
        return ans;
    }
};