// LINK - https://leetcode.com/problems/count-the-number-of-consistent-strings

// TC = O(n*m*k), SC = O(1)

// solution 1
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int count = 0;
        bool flag;
        for (auto word : words)
        {
            flag = true;
            for (auto c : word)
            {
                if (allowed.find(c) == npos)
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
        return count;
    }
};
