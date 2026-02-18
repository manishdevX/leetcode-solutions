// LINK - https://leetcode.com/problems/number-of-senior-citizens

// n = size of details

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int count = 0;
        for (auto &&str : details)
        {
            if (str[11] >= '6' && str[12] > '0' || str[11] >= '7')
            {
                count++;
            }
        }
        return count;
    }
};