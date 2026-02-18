// LINK - https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

// n = size of arr

// Solution 1 TC = O(n^4), SC = O(1) TLE
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int count = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j; k < n; k++)
                {
                    int a = 0, b = 0;
                    for (int ti = i; ti < j; ti++)
                    {
                        a ^= arr[ti];
                    }

                    for (int tj = j; tj <= k; tj++)
                    {
                        b ^= arr[tj];
                    }
                    a == b ? count++ : count;
                }
            }
        }
        return count;
    }
};
