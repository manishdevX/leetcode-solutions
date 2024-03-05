// LINK - https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/

// m = size of score, n = size of score[i]

// Solution 1 TC = O(mlogm), SC = O(1)
class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        sort(score.begin(), score.end(),
             [&](vector<int> v1, vector<int> v2)
             { return v1[k] > v2[k]; });
        return score;
    }
};

// TC = O(m^2), SC = O(1)
// Solution 2
class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        int m = score.size();
        for (int i = 0; i < m; i++)
        {
            int ind = i;
            for (int j = i + 1; j < m; j++)
            {
                if (score[j][k] > score[ind][k])
                {
                    ind = j;
                }
            }
            if (ind != i)
            {
                score[i].swap(score[ind]);
            }
        }
        return score;
    }
};

// TC = O(m), SC = O(m)
// Solution 3
class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        int m = score.size(), n = score[0].size();
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++)
        {
            pq.push({score[i][k], i});
        }

        while (pq.size())
        {
            int row = pq.top().second;
            pq.pop();
            res.push_back(score[row]);
        }
        return res;
    }
};