// LINK - https://leetcode.com/problems/sort-the-matrix-diagonally

// m = size of mat, n = size of mat[0]

// Solution 1 TC = O(mnlogmin(m,n)), SC = O(min(m,n))
class Solution
{
private:
    void diagonalSortHelper(vector<vector<int>> &mat, int start_row,
                            int start_col, int m, int n)
    {
        int row = start_row, col = start_col;
        vector<int> arr;
        while (row < m && col < n)
        {
            arr.push_back(mat[row++][col++]);
        }
        sort(arr.begin(), arr.end());
        row = start_row, col = start_col;
        for (int i = 0; i < arr.size(); i++)
        {
            mat[row++][col++] = arr[i];
        }
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        for (int col = 0; col < n; col++)
        {
            diagonalSortHelper(mat, 0, col, m, n);
        }
        for (int row = 1; row < m; row++)
        {
            diagonalSortHelper(mat, row, 0, m, n);
        }
        return mat;
    }
};

// Solution 2 TC = O(mnlogmin(m,n)), SC = O(m*n)
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i - j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = mp[i - j].top();
                mp[i - j].pop();
            }
        }
        return mat;
    }
};
