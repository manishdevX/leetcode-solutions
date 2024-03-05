// LINK - https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

// n = size of nums

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = 0;
        for (auto &&num : nums)
        {
            mp[num]++;
            n = max(n, mp[num]);
        }
        vector<vector<int>> ans(n);
        for (auto &&num : nums)
        {
            ans[mp[num] - 1].push_back(num);
            mp[num]--;
        }
        return ans;
    }
};

// TC = O(n^2), SC = O(n)
// Solution 2
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for (auto &&num : nums)
        {
            bool flag = true;
            for (auto &&v : ans)
            {
                if (find(v.begin(), v.end(), num) == v.end())
                {
                    v.push_back(num);
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back({num});
            }
        }
        return ans;
    }
};