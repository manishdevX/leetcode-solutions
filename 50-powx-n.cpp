// LINK - https://leetcode.com/problems/powx-n

// Solution 1, TC = O(logn), SC = O(logn)
class Solution
{
private:
    double myPowHelper(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        double res = myPowHelper(x, n / 2);
        return n % 2 ? res * res * x : res * res;
    }

public:
    double myPow(double x, int n)
    {
        double res = myPowHelper(x, abs(n));
        return n < 0 ? 1 / res : res;
    }
};
