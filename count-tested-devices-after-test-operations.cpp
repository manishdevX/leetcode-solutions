// LINK - https://leetcode.com/problems/count-tested-devices-after-test-operations/

// Solution 1 TC = O(size of batteryPercentages * 2), SC = O(1)
class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int count = 0;
        int n = batteryPercentages.size();
        for (int i = 0; i < n; i++)
        {
            if (batteryPercentages[i] > 0)
            {
                count++;
                for (int j = i + 1; j < n; j++)
                {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }
        return count;
    }
};

// Solution 2 TC = O(size of batteryPercentages), SC = O(1)
class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int count = 0;
        int n = batteryPercentages.size();
        for (int i = 0; i < n; i++)
        {
            if (batteryPercentages[i] > count)
            {
                count++;
            }
        }
        return count;
    }
};
