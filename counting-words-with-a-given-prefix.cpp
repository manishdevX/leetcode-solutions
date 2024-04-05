// LINK - https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

// n = size of words, m = length of pref

// Solution 1 TC = O(n*m), SC = O(1)
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        bool flag;
        for (auto &&word : words)
        {
            if (word.length() >= pref.length())
            {
                flag = true;
                for (int i = 0; i < pref.length(); i++)
                {
                    if (word[i] != pref[i])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// Solution 2 TC = O(n*m), SC = O(m)
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        bool flag;
        string st;
        for (auto &&word : words)
        {
            if (word.length() >= pref.length())
            {
                st = word.substr(0, pref.length());
                if (st == pref)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
