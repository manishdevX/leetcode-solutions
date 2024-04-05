// LINK - https://leetcode.com/problems/two-sum/description/

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.assign({i, j});
                    return ans;
                }
            }
        }
        return ans;
    }
};

// TC = O(n), SC = O(n)
// Solution 2
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for (auto &&num : nums)
        {
            int comp = target - num;
            if (comp == num)
            {
                if (mp[comp].size() == 2)
                {
                    ans.push_back(mp[comp].front());
                    ans.push_back(mp[comp].back());
                    return ans;
                }
            }
            else if (mp.find(comp) != mp.end())
            {
                ans.push_back(mp[num].front());
                ans.push_back(mp[comp].front());
                return ans;
            }
        }
        return ans;
    }
};

// TC = O(n), SC = O(n)
// Solution 3
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int comp = target - nums[i];
            if (mp.find(comp) != mp.end() && mp[comp] != i)
            {
                ans.assign({mp[comp], i});
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};