// LINK - https://leetcode.com/problems/combination-sum

// T = Value of target

// Solution 1 TC = O(2^T), SC = O(2^T)
class Solution
{
private:
    vector<vector<int>> ans;
    void combinationSumHelper(vector<int> &candidates, vector<int> &res,
                              int target, int ind)
    {
        if (target == 0)
        {
            ans.push_back(res);
        }
        if (target < 0)
        {
            return;
        }
        for (int i = ind; i < candidates.size(); i++)
        {
            res.push_back(candidates[i]);
            combinationSumHelper(candidates, res, target - candidates[i], i);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> res;
        combinationSumHelper(candidates, res, target, 0);
        return ans;
    }
};

// n(n)