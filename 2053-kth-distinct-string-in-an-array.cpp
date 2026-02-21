// LINK - https://leetcode.com/problems/kth-distinct-string-in-an-array

// n = size of arr, m = avg length of arr[i]

// Solution 1, TC = O(n*m), SC = O(n*m)
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

// Solution 2, TC = O(n^2*m), SC = O(1)
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