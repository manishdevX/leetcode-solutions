// LINK - https://leetcode.com/problems/finding-the-users-active-minutes/description/

// n = size of logs

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        vector<int> ans(k, 0);
        unordered_map<int, unordered_set<int>> mp;
        for (auto &&log : logs)
        {
            mp[log[0]].insert(log[1]);
        }
        for (auto &&it : mp)
        {
            ans[it.second.size() - 1]++;
        }
        return ans;
    }
};