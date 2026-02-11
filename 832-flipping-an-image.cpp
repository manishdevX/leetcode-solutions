// LINK - https://leetcode.com/problems/flipping-an-image/

// n = size of nums and nums[i]

// Solution 1, TC = O(n^2), SC = O(1)
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