// LINK - https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

// n = size of garbage, m = avg size of garbage[i]

// Solution 1, TC = O(m*n), SC = O(1)
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int ans = 0, n = garbage.size(), md = 0, pd = 0, gd = 0;
        for (int i = 0; i < n; i++)
        {
            int mc = count(garbage[i].begin(), garbage[i].end(), 'M');
            int pc = count(garbage[i].begin(), garbage[i].end(), 'P');
            int gc = count(garbage[i].begin(), garbage[i].end(), 'G');
            if (mc)
            {
                ans += mc + md;
                md = 0;
            }
            if (pc)
            {
                ans += pc + pd;
                pd = 0;
            }
            if (gc)
            {
                ans += gc + gd;
                gd = 0;
            }
            if (i < n - 1)
            {
                md += travel[i];
                pd += travel[i];
                gd += travel[i];
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(m*n), SC = O(n)
class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int ans = 0, n = garbage.size();
        vector<int> prefix_sum(n, 0);
        unordered_map<char, int> gc;
        unordered_map<char, int> gli;
        for (int i = 0; i < n - 1; i++)
        {
            prefix_sum[i + 1] += prefix_sum[i] + travel[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < garbage[i].size(); j++)
            {
                if (garbage[i][j] == 'M')
                {
                    gc['M']++;
                    gli['M'] = i;
                }
                else if (garbage[i][j] == 'P')
                {
                    gc['P']++;
                    gli['P'] = i;
                }
                else if (garbage[i][j] == 'G')
                {
                    gc['G']++;
                    gli['G'] = i;
                }
            }
        }
        for (auto &&it : gc)
        {
            ans += it.second + prefix_sum[gli[it.first]];
        }
        return ans;
    }
};
