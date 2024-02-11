// LINK - https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/description/

// n = size of startTime

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime,
                    int queryTime)
    {
        int count = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
            {
                count++;
            }
        }
        return count;
    }
};