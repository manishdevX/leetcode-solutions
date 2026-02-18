// LINK - https://leetcode.com/problems/plus-one

// n = size of digits

// Solution 1 TC = O(n), SC = O(1)
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        if (digits[n - 1] < 9)
        {
            digits[n - 1]++;
            return digits;
        }
        int c = 1;
        digits[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (!c)
            {
                break;
            }
            int num = digits[i] + c;
            digits[i] = num % 10;
            c = num / 10;
        }
        if (c)
        {
            digits.insert(digits.begin(), c);
        }

        return digits;
    }
};