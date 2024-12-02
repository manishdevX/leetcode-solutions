// LINK - https://leetcode.com/problems/permutations/description/

// n = size of nums

// Solution 1 TC = O(n!), SC = O(n!)
class Solution
{
private:
    vector<vector<int>> ans;
    void permuteHelper(vector<int> &nums, vector<int> &temp,
                       vector<bool> &visited)
    {
        int n = nums.size();
        if (temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                permuteHelper(nums, temp, visited);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(nums[i]);
            visited[i] = true;
            permuteHelper(nums, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }

        return ans;
    }
};

// Solution 2 TC = O(n!), SC = O(n!)
class Solution
{
private:
    vector<vector<int>> ans;
    void permuteHelper(vector<int> &nums, int ind)
    {
        int n = nums.size();
        if (ind == n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            swap(nums[ind], nums[i]);
            permuteHelper(nums, ind + 1);
            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        permuteHelper(nums, 0);
        return ans;
    }
};