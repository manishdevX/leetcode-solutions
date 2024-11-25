// LINK - https://leetcode.com/problems/merge-intervals/description/

// n = size of intervals

// Solution 1 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
