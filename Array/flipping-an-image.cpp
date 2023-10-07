// LINK - https://leetcode.com/problems/flipping-an-image/

// TC = O(n^2), SC = O(1)
// Solution
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (auto &&row : image)
        {
            reverse(row.begin(), row.end());
            for (auto &&col : row)
            {
                col ^= 1;
            }
        }

        return image;
    }
};