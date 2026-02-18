// LINK - https://leetcode.com/problems/find-triangular-sum-of-an-array

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        while (nums.size() > 1)
        {
            int n = nums.size() - 1;
            vector<int> newNums(n);
            for (int i = 0; i < n; i++)
            {
                newNums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums = newNums;
        }
        return nums[0];
    }
};

// Solution 2 TC = O(n^2), SC = O(1)
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        while (n > 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--;
        }
        return nums[0];
    }
};

// Solution 3 TC = O(n^2), SC = O(n)
class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int n = nums.size();
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(nums[i]);
        }
        while (q.size() > 1)
        {
            for (int i = 0; i < q.size() - 1; i++)
            {
                int a = q.front();
                q.pop();
                int b = q.front();
                q.push((a + b) % 10);
            }
            q.pop();
        }
        return q.front();
    }
};