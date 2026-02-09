// LINK - https://leetcode.com/problems/shuffle-string/

// n = size of indices

// solution 1, TC = O(n), SC = O(n)
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string st = s;
        for (int i = 0; i < indices.size(); i++)
        {
            st[indices[i]] = s[i];
        }
        return st;
    }
};