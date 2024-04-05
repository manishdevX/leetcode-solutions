// LINK - https://leetcode.com/problems/minimum-time-visiting-all-points/description/

// n = size of points

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 1; i < points.size(); i++)
        {
            int xd = abs(points[i][0] - points[i - 1][0]);
            int yd = abs(points[i][1] - points[i - 1][1]);
            ans += xd + yd - min(xd, yd);
        }
        return ans;
    }
};

// TC = O(n), SC = O(1)
// Solution 2
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 1; i < points.size(); i++)
        {
            int xd = abs(points[i][0] - points[i - 1][0]);
            int yd = abs(points[i][1] - points[i - 1][1]);
            ans += max(xd, yd);
        }
        return ans;
    }
};