// LINK - https://leetcode.com/problems/kth-distinct-string-in-an-array

// n = size of arr

// Solution 1 TC = O(n), SC = O(n)
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        string ans = "";
        unordered_map<string, int> mp;
        for (auto &&st : arr)
        {
            mp[st]++;
        }

        for (auto &&st : arr)
        {
            if (mp[st] == 1 && k)
            {
                ans = st;
                k--;
            }
        }
        return k ? "" : ans;
    }
};

// TC = O(n^2), SC = O(1)
// Solution 2
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        string ans = "";
        int n = arr.size();
        for (auto &&st : arr)
        {
            int c = count(arr.begin(), arr.end(), st);
            if (c == 1 && k)
            {
                ans = st;
                k--;
            }
        }
        return k ? "" : ans;
    }
};