// LINK - https://leetcode.com/problems/find-and-replace-pattern/description/

// m = size of pattern, n = size of words

// Solution 1 TC = O(m*n), SC = O(n+m)
class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words,
                                         string pattern)
    {
        int m = pattern.size();
        bool flag;
        vector<string> ans;
        for (auto &&word : words)
        {
            flag = true;
            unordered_map<char, char> mp1, mp2;
            for (int i = 0; i < m; i++)
            {
                char pch = pattern[i], wch = word[i];
                if (mp1.find(pch) != mp1.end() && mp1[pch] != wch)
                {
                    flag = false;
                    break;
                }
                if (mp2.find(wch) != mp2.end() && mp2[wch] != pch)
                {
                    flag = false;
                    break;
                }
                mp1[pch] = wch;
                mp2[wch] = pch;
            }
            if (flag)
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
