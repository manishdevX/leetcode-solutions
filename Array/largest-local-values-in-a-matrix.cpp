// LINK - https://leetcode.com/problems/largest-local-values-in-a-matrix/

// TC = O(n^2), SC = O(n)

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                int max1 = max({grid[i][j], grid[i][j + 1], grid[i][j + 2]});
                int max2 = max({grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2]});
                int max3 = max({grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]});
                maxLocal[i][j] = max({max1, max2, max3});
            }
        }
        return maxLocal;
    }
};