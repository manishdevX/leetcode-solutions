// LINK - https://leetcode.com/problems/maximum-strong-pair-xor-i

// n = size of nums

// Solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                {
                    ans = max(ans, nums[i] ^ nums[j]);
                }
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(n^2), SC = O(n^2)
class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                {
                    mp[nums[i]].push_back(nums[i] ^ nums[j]);
                }
            }
        }
        for (auto &&x : mp)
        {
            ans = max(ans, *max_element(x.second.begin(), x.second.end()));
        }
        return ans;
    }
};