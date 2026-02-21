// LINK - https://leetcode.com/problems/unique-number-of-occurrences

// n = size of arr

// Solution 1, TC = O(n), SC = O(n)
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        for (auto &&num : arr)
        {
            mp[num]++;
        }
        for (auto &&it : mp)
        {
            s.insert(it.second);
        }
        return mp.size() == s.size();
    }
};