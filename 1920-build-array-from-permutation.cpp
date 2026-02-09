// LINK - https://leetcode.com/problems/build-array-from-permutation/

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[nums[i]]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] + (nums[nums[i]] % n) * n;
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] / n;
        }

        return nums;
    }
};
