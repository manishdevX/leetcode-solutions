// LINK - https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

// n = size of groupSizes

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            vector<int> arr;
            for (int j = i; j < n; j++)
            {
                if (!visited[j] && groupSizes[i] == groupSizes[j])
                {
                    if (arr.size() < groupSizes[j])
                    {
                        arr.push_back(j);
                        visited[j] = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            ans.push_back(arr);
        }

        return ans;
    }
};

// TC = O(n^2), SC = O(n)
// Solution 2
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        for (auto &&it : mp)
        {
            vector<int> arr(it.first);
            for (int i = 0; i < it.second.size(); i++)
            {
                int idx = i % it.first;
                arr[idx] = it.second[i];
                if (arr.size() - 1 == idx)
                {
                    ans.push_back(arr);
                }
            }
        }
        return ans;
    }
};