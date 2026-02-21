// LINK - https://leetcode.com/problems/split-strings-by-separator

// n = size of words, m = avg length of a words[i]

// Solution 1, TC = O(n*m), SC = O(m)
class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words,
                                         char separator)
    {
        vector<string> ans;
        for (auto &&word : words)
        {
            string s = "";
            for (auto &&ch : word)
            {
                if (ch != separator)
                {
                    s += ch;
                }
                else
                {
                    if (s.size())
                    {
                        ans.push_back(s);
                    }
                    s = "";
                }
            }
            if (s.size())
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};