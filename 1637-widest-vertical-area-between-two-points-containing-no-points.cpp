// LINK - https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

// n = size of points

// Solution 1, TC = O(nlogn), SC = O(logn)
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int ans = 0;
        sort(points.begin(), points.end(),
             [](vector<int> v1, vector<int> v2)
             { return v1[0] < v2[0]; });

        for (int i = 1; i < points.size(); i++)
        {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};