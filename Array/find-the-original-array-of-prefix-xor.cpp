// LINK - https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/

// n = size of pref

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> arr;
        for (int i = 0; i < pref.size(); i++)
        {
            int num = pref[i];
            for (int j = 0; j < arr.size(); j++)
            {
                num ^= arr[j];
            }
            arr.push_back(num);
        }
        return arr;
    }
};

// TC = O(n), SC = O(n)
// Solution 2
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size(), x = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = x ^ pref[i];
            x ^= arr[i];
        }
        return arr;
    }
};