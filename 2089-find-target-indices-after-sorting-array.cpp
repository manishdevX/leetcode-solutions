// LINK - https://leetcode.com/problems/find-target-indices-after-sorting-array

// n = size of nums

// Solution 1, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(nlogn), SC = O(1)
class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
            {
                return ans;
            }

            if (nums[i] == target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 3, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        int less = 0, matches = 0;
        for (auto &&num : nums)
        {
            if (num < target)
            {
                less++;
            }
            else if (num == target)
            {
                matches++;
            }
        }
        vector<int> ans(matches);
        for (int i = 0; i < matches; i++)
        {
            ans[i] = less + i;
        }

        return ans;
    }
};