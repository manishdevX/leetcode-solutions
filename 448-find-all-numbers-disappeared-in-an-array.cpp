// LINK - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

// n = size of nums

// Solution 1, TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans, vec(n + 1, 0);
        for (auto &&num : nums)
        {
            vec[num]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vec[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (auto &&num : nums)
        {
            int ind = abs(num) - 1;
            if (nums[ind] > 0)
            {
                nums[ind] *= -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
