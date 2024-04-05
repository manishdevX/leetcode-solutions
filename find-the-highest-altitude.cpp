// LINK - https://leetcode.com/problems/find-the-highest-altitude

// TC = O(n), SC = O(1)
// solution 1
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int res = max(0, gain[0]);
        for (int i = 1; i < gain.size(); i++)
        {
            gain[i] = gain[i] + gain[i - 1];
            res = max(res, gain[i]);
        }
        return res;
    }
};

// TC = O(n), SC = O(1)
// solution 2
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int max_altitude = 0, current_altitude = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            current_altitude += gain[i];
            max_altitude = max(max_altitude, current_altitude);
        }
        return max_altitude;
    }
};