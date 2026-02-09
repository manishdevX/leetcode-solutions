// LINK - https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

// n = size of arr

// solution 1, TC = O(n^3), SC = O(1)
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int sum = 0;
        int n = arr.size();
        int len = 1;
        while (len <= n)
        {
            for (int i = 0; i <= n - len; i++)
            {
                for (int j = i; j < i + len; j++)
                {
                    sum += arr[j];
                }
            }
            len += 2;
        }
        return sum;
    }
};
