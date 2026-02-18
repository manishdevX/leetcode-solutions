// LINK - https://leetcode.com/problems/can-place-flowers

// n = size of flowerbed

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int sz = flowerbed.size();
        for (int i = 0; i < sz; i++)
        {
            if (flowerbed[i] || (i > 0 && flowerbed[i - 1]) ||
                (i < sz - 1 && flowerbed[i + 1]))
            {
                continue;
            }
            flowerbed[i]++;
            n--;
        }
        return n <= 0;
    }
};