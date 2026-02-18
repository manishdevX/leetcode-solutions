// LINK - https://leetcode.com/problems/set-matrix-zeroes

// n = size of matrix, m = size of matrix[i]

// Solution 1 TC = O((m+n)*m*n), SC = O(m*n)
class Solution
{
public:
    void setRowZero(vector<vector<int>> &matrix, int row)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            matrix[row][col] = 0;
        }
    }
    void setColZero(vector<vector<int>> &matrix, int col)
    {
        for (int row = 0; row < matrix.size(); row++)
        {
            matrix[row][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> mat(matrix);
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!mat[i][j])
                {
                    setRowZero(matrix, i);
                    setColZero(matrix, j);
                }
            }
        }
    }
};
