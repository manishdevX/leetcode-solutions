// LINK - https://leetcode.com/problems/subsets/description/

// n = size of nums

// Solution 1 TC = O(n*2^n), SC = O(n*2^n)
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int p = pow(2, n);
        vector<vector<int>> ans(p);
        for (int i = 0; i < p; i++)
        {
            int temp = i;
            for (int j = 0; j < n; j++)
            {
                int r = temp % 2;
                temp /= 2;
                if (r)
                {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};

// Solution 2 TC = O(n*2^n), SC = O(n*2^n)
class Solution
{
private:
    vector<vector<int>> subsetsHelper(vector<int> &nums, int ind)
    {
        if (ind < 0)
        {
            return {{}};
        }
        vector<vector<int>> vec = subsetsHelper(nums, ind - 1);
        int n = vec.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> arr(vec[i]);
            arr.push_back(nums[ind]);
            vec.push_back(arr);
        }
        return vec;
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        return subsetsHelper(nums, n - 1);
    }
};

// Solution 3 TC = O(n*2^n), SC = O(n*2^n)
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans = {{}};
        for (int i = 0; i < n; i++)
        {
            int s = ans.size();
            for (int j = 0; j < s; j++)
            {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
};

// Solution 4 TC =  O(n*2^n), SC = O(n*2^n)
class Solution
{
private:
    void subsetsHelper(vector<int> &nums, int ind, vector<int> &temp,
                       vector<vector<int>> &ans)
    {
        if (ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        subsetsHelper(nums, ind + 1, temp, ans);
        temp.push_back(nums[ind]);
        subsetsHelper(nums, ind + 1, temp, ans);
        temp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsetsHelper(nums, 0, temp, ans);
        return ans;
    }
};