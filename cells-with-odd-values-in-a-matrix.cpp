// LINK - https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

// TC = O(m*n), SC = O(m*n)

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < indices.size(); i++)
        {
            int r = indices[i][0];
            int c = indices[i][1];

            for (int j = 0; j < n; j++)
            {
                matrix[r][j]++;
            }

            for (int j = 0; j < m; j++)
            {
                matrix[j][c]++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] % 2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};