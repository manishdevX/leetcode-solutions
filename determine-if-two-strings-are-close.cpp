// LINK - https://leetcode.com/problems/determine-if-two-strings-are-close/description/

// m = size of word1, n = size of word2

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
        {
            return false;
        }
        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < word1.length(); i++)
        {
            v1[word1[i] - 'a']++;
            v2[word2[i] - 'a']++;
        }
        for (int i = 0; i < v1.size(); i++)
        {
            if ((v1[i] == 0 && v2[i] == 0) || (v1[i] != 0 && v2[i] != 0))
            {
                continue;
            }
            return false;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};
