// LINK - https://leetcode.com/problems/queries-on-a-permutation-with-key

// n = size of queries

// Solution 1 TC = O(m*n), SC = O(m+n)
class Solution
{
private:
    void processQueriesHelper(vector<int> &arr, int k)
    {
        int temp = arr[k];
        while (k)
        {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = temp;
    }

public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        int n = queries.size();
        vector<int> perm, ans;
        for (int i = 1; i <= m; i++)
        {
            perm.push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            int ind = find(perm.begin(), perm.end(), queries[i]) - perm.begin();
            processQueriesHelper(perm, ind);
            ans.push_back(ind);
        }
        return ans;
    }
};
