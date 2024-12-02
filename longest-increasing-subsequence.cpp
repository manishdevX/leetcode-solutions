// LINK - https://leetcode.com/problems/longest-increasing-subsequence/description/

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            int maxsf = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    maxsf = max(maxsf, dp[j]);
                }
            }
            dp[i] = maxsf + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Solution 2 TC = O(n^2), SC = O(n^2)
class Solution
{
private:
    int lengthOfLISHelper(vector<int> &nums, int ind, int prevind,
                          vector<vector<int>> &dp)
    {
        if (ind == nums.size())
        {
            return 0;
        }
        if (dp[ind][prevind + 1] != -1)
        {
            return dp[ind][prevind + 1];
        }

        int ans = lengthOfLISHelper(nums, ind + 1, prevind, dp);
        if (prevind == -1 || nums[ind] > nums[prevind])
        {
            ans = max(ans, 1 + lengthOfLISHelper(nums, ind + 1, ind, dp));
        }
        dp[ind][prevind + 1] = ans;
        return ans;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lengthOfLISHelper(nums, 0, -1, dp);
    }
};

// Solution 3 TC = O(nlogn), SC = O(n)
class Solution
{
private:
    int getCeilInd(vector<int> &vec, int num)
    {
        int lo = 0, hi = vec.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (vec[mid] < num)
            {
                lo = mid + 1;
            }
            else if (vec[mid] > num)
            {
                hi = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return lo;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int ind = getCeilInd(vec, nums[i]);
            if (ind == vec.size())
            {
                vec.push_back(nums[i]);
            }
            else
            {
                vec[ind] = nums[i];
            }
        }
        return vec.size();
    }
};
