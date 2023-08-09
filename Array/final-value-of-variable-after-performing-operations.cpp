// LINK - https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

// TC = O(n), SC = O(1)

// Solution 1
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int x = 0;
        for (string st : operations)
        {
            if (st == "++X" || st == "X++")
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        return x;
    }
};

// Solution 2
class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int x = 0;
        for (string st : operations)
        {
            x += 44 - st[1];
        }
        return x;
    }
};
