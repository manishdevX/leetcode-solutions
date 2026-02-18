// LINK - https://leetcode.com/problems/di-string-match

// n = length of s

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        vector<int> ans;
        int n = s.size();
        int d = n, i = 0;
        for (auto &&ch : s)
        {
            if (ch == 'D')
            {
                ans.push_back(d);
                d--;
            }
            else
            {
                ans.push_back(i);
                i++;
            }
        }
        ans.push_back(d);
        return ans;
    }
};