// LINK - https://leetcode.com/problems/running-sum-of-1d-array/

// n = size of nums

// solution 1, TC = O(n^2), SC = O(1)
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < i + 1; j++)
            {
                sum += nums[j];
            }
            result.push_back(sum);
        }
        return result;
    }
};

// solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result;
        result.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            result.push_back(result[i - 1] + nums[i]);
        }
        return result;
    }
};