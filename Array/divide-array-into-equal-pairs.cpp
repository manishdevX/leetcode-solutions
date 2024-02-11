// LINK - https://leetcode.com/problems/divide-array-into-equal-pairs/description/

// n = size of nums

// Solution 1 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i] != nums[i + 1])
            {
                return false;
            }
            i += 2;
        }
        return true;
    }
};

// Solution 2 TC = O(n), SC = O(n)
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &&num : nums)
        {
            mp[num]++;
        }
        for (auto &&it : mp)
        {
            if (it.second % 2)
            {
                return false;
            }
        }
        return true;
    }
};

// Solution 3 TC = O(n), SC = O(n)
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto &&num : nums)
        {
            if (s.find(num) != s.end())
            {
                s.erase(num);
            }
            else
            {
                s.insert(num);
            }
        }
        if (s.size())
        {
            return false;
        }
        return true;
    }
};