// LINK - https://leetcode.com/problems/n-repeated-element-in-size-2n-array

// n = size of nums

// Solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int ans;
        for (auto &&num : nums)
        {
            if (count(nums.begin(), nums.end(), num) > 1)
            {
                ans = num;
                break;
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(n)
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans;
        for (auto &&num : nums)
        {
            if (mp[num] == 1)
            {
                ans = num;
                break;
            }
            mp[num]++;
        }
        return ans;
    }
};

// Solution 3, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};