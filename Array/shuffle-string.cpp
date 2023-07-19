// TC = O(n), SC = O(n)

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