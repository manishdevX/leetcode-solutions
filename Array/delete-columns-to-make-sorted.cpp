// LINK - https://leetcode.com/problems/delete-columns-to-make-sorted/description/

// n = size of strs, m = size of strs[i]

// Solution 1 TC = O(n*m), SC = O(1)
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        for (int col = 0; col < strs[0].size(); col++)
        {
            for (int row = 1; row < strs.size(); row++)
            {
                if (strs[row][col] < strs[row - 1][col])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};