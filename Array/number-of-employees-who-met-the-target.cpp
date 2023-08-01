// TC = O(n), SC = O(1)

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