// LINK - https://leetcode.com/problems/reverse-words-in-a-string

// n = length of s

// Solution 1, TC = O(n^2), SC = O(n)
class Solution
{
public:
    string reverseWords(string s)
    {
        int lo = 0, hi = s.length() - 1;
        string ans = "", ssf = "", sp = " ";
        while (s[lo] == ' ')
        {
            lo++;
        }
        while (s[hi] == ' ')
        {
            hi--;
        }
        while (lo <= hi)
        {
            if (s[lo] == ' ')
            {
                if (ssf != "")
                {
                    ans = sp + ssf + ans;
                }
                ssf = "";
            }
            else
            {
                ssf += s[lo];
            }
            lo++;
        }
        if (ssf != "")
        {
            ans = ssf + ans;
        }
        return ans;
    }
};