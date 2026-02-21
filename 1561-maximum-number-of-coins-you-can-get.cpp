// LINK - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

// n = size of piles

// Solution 1, TC = O(nlogn), SC = O(logn)
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int sum = 0, n = piles.size() / 3, idx = piles.size() - 2;

        while (n)
        {
            sum += piles[idx];
            idx -= 2;
            n--;
        }
        return sum;
    }
};