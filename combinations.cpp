// LINK - https://leetcode.com/problems/combinations/description/

// n = size of res

// Solution 1 TC = O(C(n,k)⋅k), SC = O(C(n,k)⋅k) MLE
class Solution
{
private:
    vector<vector<int>> ans;
    void combineHelper(int n, int k, int num, vector<int> res)
    {
        if (res.size() == k)
        {
            ans.push_back(res);
            return;
        }
        if (num > n)
        {
            return;
        }
        combineHelper(n, k, num + 1, res);
        res.push_back(num);
        combineHelper(n, k, num + 1, res);
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        combineHelper(n, k, 1, {});
        return ans;
    }
};

// Solution 2 TC = O(C(n,k)⋅k), SC = O(C(n,k)⋅k)
class Solution
{
private:
    vector<vector<int>> ans;
    void combineHelper(int n, int k, int num, vector<int> &res)
    {
        if (res.size() == k)
        {
            ans.push_back(res);
            return;
        }
        if (num > n)
        {
            return;
        }
        combineHelper(n, k, num + 1, res);
        res.push_back(num);
        combineHelper(n, k, num + 1, res);
        res.pop_back();
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> res;
        combineHelper(n, k, 1, res);
        return ans;
    }
};