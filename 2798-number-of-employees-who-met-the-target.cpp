// LINK - https://leetcode.com/problems/number-of-employees-who-met-the-target/

// n = size of hours

// solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int count = 0;
        for (auto hrs : hours)
        {
            if (hrs >= target)
            {
                count++;
            }
        }
        return count;
    }
};