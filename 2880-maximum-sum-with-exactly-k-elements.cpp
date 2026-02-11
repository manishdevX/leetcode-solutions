// LINK - https://leetcode.com/problems/maximum-sum-with-exactly-k-elements

// n = size of nums

// solution 1, TC = O(n+k), SC = O(1)
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int score = *max_element(nums.begin(), nums.end());
        int final_score = score;
        for (int i = 1; i < k; i++)
        {
            final_score += score + i;
        }
        return final_score;
    }
};

// solution 2, TC = O(n), SC = O(1)
class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int score = *max_element(nums.begin(), nums.end());

        return score * k + (k * (k - 1)) / 2;
    }
};