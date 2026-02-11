// LINK - https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

// n = size of nums

// Solution 1, TC = O(n), SC = O(1)
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (auto &&num : nums)
        {
            int d = log10(num) + 1;
            if (d % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};

// Solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int d = log10(nums[i]) + 1;
            if (d % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};

// Solution 3, TC = O(n), SC = O(1)
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (auto &&n : nums)
        {
            if ((n >= 10 && n <= 99) || (n >= 1000 && n <= 9999) ||
                (n == 100000))
            {
                count++;
            }
        }
        return count;
    }
};