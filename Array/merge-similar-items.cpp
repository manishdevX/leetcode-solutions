// LINK - https://leetcode.com/problems/merge-similar-items/description/

// n1 = size of items1, n2 = size of items2

// Solution 1 TC = O(n1*n2), SC = O(n1+n2)
class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                          vector<vector<int>> &items2)
    {
        vector<vector<int>> ret;

        for (auto &&item1 : items1)
        {
            int wt = item1[1];
            for (auto &&item2 : items2)
            {
                if (item1[0] == item2[0])
                {
                    wt += item2[1];
                    break;
                }
            }
            ret.push_back({item1[0], wt});
        }

        for (auto &&item2 : items2)
        {
            int flag = true;
            for (auto &&item : ret)
            {
                if (item[0] == item2[0])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ret.push_back(item2);
            }
        }
        sort(ret.begin(), ret.end(),
             [](const vector<int> v1, const vector<int> v2)
             {
                 return v1[0] < v2[0];
             });
        return ret;
    }
};

// TC = O(n1+n2), SC = O(n1+n2)
// Solution 2
class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                          vector<vector<int>> &items2)
    {
        map<int, int> mp;
        vector<vector<int>> ret;
        for (auto &&item : items1)
        {
            mp[item[0]] += item[1];
        }
        for (auto &&item : items2)
        {
            mp[item[0]] += item[1];
        }

        for (auto &&it : mp)
        {
            ret.push_back({it.first, it.second});
        }
        return ret;
    }
};
