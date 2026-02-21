// LINK - https://leetcode.com/problems/sum-of-unique-elements

// n = size of nums

// Solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int sum = 0;
        for (auto &&num : nums)
        {
            if (count(nums.begin(), nums.end(), num) == 1)
            {
                sum += num;
            }
        }
        return sum;
    }
};

// Solution 2, TC = O(n), SC = O(n)
class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int sum = 0;
        unordered_map<int, int> mp;
        for (auto &&num : nums)
        {
            mp[num]++;
        }

        for (auto &&num : nums)
        {
            if (mp[num] == 1)
            {
                sum += num;
            }
        }
        return sum;
    }
};