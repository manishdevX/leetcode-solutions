// LINK - https://leetcode.com/problems/sort-the-people/

// n = size of names and heights

// Solution 1, TC = O(nlogn+n^2), SC = O(1)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<int> new_heights = heights;
        vector<string> new_names(n);
        sort(new_heights.rbegin(), new_heights.rend());

        for (int i = 0; i < n; i++)
        {
            int ind = find(heights.begin(), heights.end(), new_heights[i]) - heights.begin();
            new_names[i] = names[ind];
        }
        return new_names;
    }
};

// Solution 2, TC = O(n^2), SC = O(1)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        for (int i = 0; i < n - 1; i++)
        {
            int ind = i;
            for (int j = i + 1; j < n; j++)
            {
                if (heights[j] > heights[ind])
                {
                    ind = j;
                }
            }
            swap(heights[i], heights[ind]);
            swap(names[i], names[ind]);
        }

        return names;
    }
};

// Solution 3, TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        map<int, string> mp;
        for (int i = 0; i < n; i++)
        {
            mp[heights[i]] = names[i];
        }

        auto it = mp.rbegin();
        for (int i = 0; i < n; i++)
        {
            names[i] = it->second;
            it++;
        }

        return names;
    }
};

// Solution 4, TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        vector<pair<int, string>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {heights[i], names[i]};
        }

        sort(arr.rbegin(), arr.rend());

        for (int i = 0; i < n; i++)
        {
            names[i] = arr[i].second;
        }

        return names;
    }
};