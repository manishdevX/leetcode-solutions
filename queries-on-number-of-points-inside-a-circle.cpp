// LINK - https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

// m = size of points, n = size of queries

// Solution 1 TC = O(m*n), SC = O(n)
class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points,
                            vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int r = pow(queries[i][2], 2);
            for (auto &&p : points)
            {
                if (pow(p[0] - queries[i][0], 2) +
                        pow(p[1] - queries[i][1], 2) <=
                    r)
                {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};
