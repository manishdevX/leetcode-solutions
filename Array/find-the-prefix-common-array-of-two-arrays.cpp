// LINK - https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

// n = size of A

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size(), val = 0;
        vector<int> ans;
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < n; i++)
        {
            mp1[A[i]] = i;
            mp2[B[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp2[A[i]] <= i)
            {
                val++;
            }
            if (mp1[B[i]] < i)
            {
                val++;
            }

            ans.push_back(val);
        }
        return ans;
    }
};