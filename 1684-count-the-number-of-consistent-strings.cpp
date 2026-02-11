// LINK - https://leetcode.com/problems/count-the-number-of-consistent-strings

// n = size of words, m = avg length of words[i], k = length of allowed

// solution 1, TC = O(n*m*k), SC = O(1)
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
