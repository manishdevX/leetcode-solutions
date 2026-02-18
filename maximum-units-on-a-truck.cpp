// LINK - https://leetcode.com/problems/maximum-units-on-a-truck

// n = size of boxTypes

// Solution 1 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int ans = 0, idx = 0;
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        while (truckSize && idx < boxTypes.size())
        {
            if (truckSize >= boxTypes[idx][0])
            {
                ans += boxTypes[idx][0] * boxTypes[idx][1];
                truckSize -= boxTypes[idx][0];
            }
            else
            {
                ans += truckSize * boxTypes[idx][1];
                truckSize = 0;
            }
            idx++;
        }
        return ans;
    }
};