// LINK - https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column

// m = size of grid, n = size of grid[i]

// Solution 1, TC = O(mn*(m+n)), SC = O(1), TLE
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int onesRowi = 0, onesColj = 0, zerosRowi = 0, zerosColj = 0;
                for (int k = 0; k < n; k++)
                {
                    grid[i][k] ? onesRowi++ : zerosRowi++;
                }
                for (int k = 0; k < m; k++)
                {
                    grid[k][j] ? onesColj++ : zerosColj++;
                }

                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
            }
        }
        return diff;
    }
};

// Solution 2, TC = O(m*n), SC = O(m*n)
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n));
        unordered_map<int, int> rones;
        unordered_map<int, int> cones;
        unordered_map<int, int> rzeros;
        unordered_map<int, int> czeros;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    rones[i]++;
                    cones[j]++;
                }
                else
                {
                    rzeros[i]++;
                    czeros[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                diff[i][j] = rones[i] + cones[j] - rzeros[i] - czeros[j];
            }
        }
        return diff;
    }
};

// Solution 3, TC = O(m*n), SC = O(m*n)
class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> diff(m, vector<int>(n));
        vector<int> rones(m, 0);
        vector<int> cones(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    rones[i]++;
                    cones[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                diff[i][j] = 2 * (rones[i] + cones[j]) - m - n;
            }
        }
        return diff;
    }
};