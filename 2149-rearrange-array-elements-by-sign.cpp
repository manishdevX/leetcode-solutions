// LINK - https://leetcode.com/problems/rearrange-array-elements-by-sign

// n = size of nums

// Solution 1, TC = O(n^2), SC = O(1), TLE
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            if (i % 2 && nums[i] > 0)
            {
                while (nums[j] > 0)
                {
                    swap(nums[i], nums[j++]);
                }
                swap(nums[i], nums[j]);
            }
            else if (i % 2 == 0 && nums[i] < 0)
            {
                while (nums[j] < 0)
                {
                    swap(nums[i], nums[j++]);
                }
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int pos = 0, neg = 1, n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                ans[pos] = nums[i];
                pos += 2;
            }
            else
            {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};