// LINK -https://leetcode.com/problems/pascals-triangle

// n = numRows

// Solution 1 TC = O(n^2), SC = O(n^2)
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> tri(numRows);
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row(i, 1);
            for (int j = 1; j < i - 1; j++)
            {
                row[j] = tri[i - 2][j - 1] + tri[i - 2][j];
            }
            tri[i - 1] = row;
        }
        return tri;
    }
};

// TC = O(n^2), SC = O(n^2)
// Solution 2
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        if (numRows == 1)
        {
            ans.push_back({1});
            return ans;
        }
        ans = generate(numRows - 1);
        vector<int> vec(numRows, 1);
        for (int i = 1; i < numRows - 1; i++)
        {
            vec[i] = ans.back()[i - 1] + ans.back()[i];
        }
        ans.push_back(vec);
        return ans;
    }
};