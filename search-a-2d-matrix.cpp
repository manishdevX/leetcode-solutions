// LINK - https://leetcode.com/problems/search-a-2d-matrix/description/

// m = size of matrix, n = size of matrix[0]

// Solution 1 TC = O(m+n), SC = O(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), row = 0, col = n - 1;
        while (row < m && col >= 0)
        {
            if (matrix[row][col] < target)
            {
                row++;
            }
            else if (matrix[row][col] > target)
            {
                col--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// Solution 2 TC = O(logm+logn), SC = O(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = (m * n) - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2, val = matrix[mid / n][mid % n];
            if (val < target)
            {
                lo = mid + 1;
            }
            else if (val > target)
            {
                hi = mid - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// Solution 3 TC = O(logm+logn), SC = O(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m - 1, row,
            mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (matrix[mid][0] > target)
            {
                hi = mid - 1;
            }
            else if (matrix[mid].back() < target)
            {
                lo = mid + 1;
            }
            else
            {
                row = mid;
                break;
            }
        }

        lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (matrix[row][mid] > target)
            {
                hi = mid - 1;
            }
            else if (matrix[row][mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};