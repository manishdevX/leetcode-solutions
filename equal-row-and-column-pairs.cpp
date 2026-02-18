// LINK - https://leetcode.com/problems/equal-row-and-column-pairs

// n = size of grid

// Solution 1 TC = O(n^3), SC = O(1)
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool flag = true;
                for (int k = 0; k < n; k++)
                {
                    if (grid[i][k] != grid[k][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Solution 2 TC = O(n^2), SC = O(n^2)
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size();
        unordered_map<string, int> fr, fc;
        for (int i = 0; i < n; i++)
        {
            string key = "";
            for (int j = 0; j < n; j++)
            {
                key += "," + to_string(grid[i][j]);
            }
            fr[key]++;
        }
        for (int i = 0; i < n; i++)
        {
            string key = "";
            for (int j = 0; j < n; j++)
            {
                key += "," + to_string(grid[j][i]);
            }
            fc[key]++;
        }
        for (auto &&it : fr)
        {
            if (fc[it.first])
            {
                ans += it.second * fc[it.first];
            }
        }
        return ans;
    }
};

// Solution 3 TC = O(n^2logn), SC = O(n^2)
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size();
        map<vector<int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[grid[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> vec;
            for (int j = 0; j < n; j++)
            {
                vec.push_back(grid[j][i]);
            }
            ans += mp[vec];
        }
        return ans;
    }
};
