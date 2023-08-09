// LINK - https://leetcode.com/problems/left-and-right-sum-differences/

// TC = O(n), SC = O(n)

// solution 1
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        vector<int> answer(n, 0);

        for (int i = 1; i < n; i++)
        {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            anwer[i] = abs(leftSum[i] - rightSum[i]);
        }
        return answer;
    }
};

// TC = O(n), SC = O(n)

// solution 2
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        int rightSum = 0;
        int leftSum = 0;
        vector<int> answer(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] = rightSum;
            rightSum += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            answer[i] = abs(leftSum - answer[i]);
            leftSum += nums[i];
        }
        return answer;
    }
};
