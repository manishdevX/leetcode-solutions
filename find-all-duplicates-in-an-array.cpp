// LINK - https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        unordered_set<int> s;
        for (auto &&num : nums)
        {
            if (s.find(num) != s.end())
            {
                ans.push_back(num);
            }
            s.insert(num);
        }
        return ans;
    }
};

// Solution 2 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (auto &&num : nums)
        {
            int val = abs(num);
            if (nums[val - 1] < 0)
            {
                ans.push_back(val);
            }
            else
            {
                nums[val - 1] *= -1;
            }
        }
        return ans;
    }
};
