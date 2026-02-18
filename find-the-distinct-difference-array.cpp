// LINK - https://leetcode.com/problems/find-the-distinct-difference-array

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        vector<int> diff;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> prefix;
            unordered_set<int> suffix;
            for (int j = 0; j < n; j++)
            {
                if (j <= i)
                {
                    prefix.insert(nums[j]);
                }
                else
                {
                    suffix.insert(nums[j]);
                }
            }
            diff.push_back(prefix.size() - suffix.size());
        }
        return diff;
    }
};

// TC = O(n), SC = O(n)
// Solution 2
class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        vector<int> diff;
        unordered_map<int, int> prefix, suffix;
        for (auto &&num : nums)
        {
            suffix[num]++;
        }
        for (auto &&num : nums)
        {
            suffix[num]--;
            if (!suffix[num])
            {
                suffix.erase(num);
            }
            prefix[num]++;
            diff.push_back(prefix.size() - suffix.size());
        }
        return diff;
    }
};