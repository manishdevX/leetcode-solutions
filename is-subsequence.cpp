// LINK - https://leetcode.com/problems/is-subsequence

// n1 = length of s, n2 = length of t

// Solution 1 TC = O(n1), SC = O(1)
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int ind = s.size() - 1, n = t.size() - 1;
        while (n >= 0 && ind >= 0)
        {
            if (s[ind] == t[n])
            {
                ind--;
            }
            n--;
        }
        return ind < 0;
    }
};