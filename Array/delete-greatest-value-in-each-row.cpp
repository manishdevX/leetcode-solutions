// LINK - https://leetcode.com/problems/delete-greatest-value-in-each-row/description/

// m = size of grid, n = size of grid[0]

// Solution 1 TC = O(n*(n*m)), SC = O(1)
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int ans = 0, m = grid.size();
        while (grid[0].size())
        {
            int maxr = INT16_MIN;
            for (int i = 0; i < m; i++)
            {
                int maxc = grid[i][0], idx = 0;
                for (int j = 1; j < grid[i].size(); j++)
                {
                    if (grid[i][j] > maxc)
                    {
                        maxc = grid[i][j];
                        idx = j;
                    }
                }
                maxr = max(maxr, maxc);
                grid[i].erase(grid[i].begin() + idx);
            }
            ans += maxr;
        }
        return ans;
    }
};

// TC = O(n^2), SC = O(n)
// Solution 2
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int idx, ans = 0;
        unordered_map<int, unordered_set<int>> mp;

        while (mp[0].size() < grid[0].size())
        {
            int maxr = INT16_MIN;
            for (int i = 0; i < grid.size(); i++)
            {
                int maxc = INT16_MIN;
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (mp[i].find(j) == mp[i].end() && grid[i][j] > maxc)
                    {
                        maxc = grid[i][j];
                        idx = j;
                    }
                }
                maxr = max(maxr, maxc);
                mp[i].insert(idx);
            }
            ans += maxr;
        }
        return ans;
    }
};

// TC = O(m*nlogn), SC = O(1)
// Solution 3
class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int idx, ans = 0, m = grid.size(), n = grid[0].size();
        for (auto &&row : grid)
        {
            sort(row.begin(), row.end());
        }
        for (int c = grid[0].size() - 1; c >= 0; c--)
        {
            int maxi = grid[0][c];
            for (int r = 1; r < m; r++)
            {
                maxi = max(maxi, grid[r][c]);
            }
            ans += maxi;
        }
        return ans;
    }
};