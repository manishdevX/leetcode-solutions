// LINK - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

// n = size of mat, m = size of mat[i]

// Solution 1 TC = TC = O(n*m), SC = O(n*m)
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < mat.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (!mat[i][j])
                {
                    break;
                }
                count++;
            }
            pq.push({count, i});
        }

        vector<int> ans;
        while (k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};

// Solution 2 TC = O(n*m), SC = O(n*m)
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        multimap<int, int> mp;
        vector<int> ans(k);
        for (int i = 0; i < mat.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (!mat[i][j])
                {
                    break;
                }
                count++;
            }
            mp.insert({count, i});
        }
        auto it = mp.begin();
        for (int i = 0; i < k; i++)
        {
            ans[i] = it->second;
            it++;
        }
        return ans;
    }
};

// Solution 3 TC = O(n*m), SC = O(n*m)
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        set<pair<int, int>> s;
        vector<int> ans(k);
        for (int i = 0; i < mat.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (!mat[i][j])
                {
                    break;
                }
                count++;
            }
            s.insert({count, i});
        }
        auto it = s.begin();
        for (int i = 0; i < k; i++)
        {
            ans[i] = it->second;
            it++;
        }
        return ans;
    }
};