// LINK - https://leetcode.com/problems/combination-sum

// n = size of candidates, m = minimum candidate value, t = value of target

// Solution 1, TC = O(n^(t/m)), SC = O(t/m)
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

// Solution 2, TC = O((t/m)*n^(t/m)), SC = O((t/m)*n^(t/m))
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        unordered_map<int, vector<vector<int>>> mp;
        mp[0] = {{}};
        for (auto &&candidate : candidates)
        {
            for (int num = 1; num <= target; num++)
            {
                int comp = num - candidate;
                if (mp.find(comp) != mp.end())
                {
                    for (auto vec : mp[comp])
                    {
                        vec.push_back(candidate);
                        mp[num].push_back(vec);
                    }
                }
            }
        }

        return mp[target];
    }
};