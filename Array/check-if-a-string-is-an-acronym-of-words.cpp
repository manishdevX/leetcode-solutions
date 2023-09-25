// LINK - https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words

// TC = O(n), SC = O(1)
// solution
class Solution
{
public:
    bool isAcronym(vector<string> &words, string s)
    {
        if (s.size() != words.size())
        {
            return false;
        }
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i][0] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};