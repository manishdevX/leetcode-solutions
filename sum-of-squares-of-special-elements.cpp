// LINK - https://leetcode.com/problems/sum-of-squares-of-special-elements/

// TC = O(n), SC = O(1)
// Solution 1

class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int idx = 1, sum = 0, n = nums.size();
        for (auto &&num : nums)
        {
            if (n % idx == 0)
            {
                sum += num * num;
            }
            idx++;
        }
        return sum;
    }
};

// TC = O(sqrt(n)), SC = O(1)
// Solution 2

class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {

        int idx = 1, sum = 0, n = nums.size();

        while (idx * idx <= n)
        {
            if (n % idx == 0)
            {
                sum += nums[idx - 1] * nums[idx - 1];
                int div = n / idx;
                if (idx != div)
                {
                    sum += nums[div - 1] * nums[div - 1];
                }
            }
            idx++;
        }
        return sum;
    }
};
