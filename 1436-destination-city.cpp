// LINK - https://leetcode.com/problems/destination-city/

// n = size of paths

// Solution 1, TC = O(n), SC = O(n)
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        string dest;
        unordered_set<string> s;
        for (auto &&path : paths)
        {
            s.insert(path[0]);
        }

        for (auto &&path : paths)
        {
            if (s.find(path[1]) == s.end())
            {
                dest = path[1];
                break;
            }
        }
        return dest;
    }
};
