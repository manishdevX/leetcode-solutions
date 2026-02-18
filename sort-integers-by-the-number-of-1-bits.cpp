// LINK - https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

// n = size of arr

// Solution 1 TC = O(nlogn), SC = O(1)
bool compare(int a, int b)
{
    int count_a = 0, count_b = 0;
    int num1 = a, num2 = b;
    while (num1)
    {
        count_a += num1 % 2;
        num1 /= 2;
    }
    while (num2)
    {
        count_b += num2 % 2;
        num2 /= 2;
    }
    if (count_a == count_b)
    {
        return a < b;
    }
    return count_a < count_b;
}

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

// TC = O(nlogn), SC = O(1)
// Solution 2
bool compare(int a, int b)
{
    int count_a = __builtin_popcount(a);
    int count_b = __builtin_popcount(b);
    if (count_a == count_b)
    {
        return a < b;
    }
    return count_a < count_b;
}

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

// TC = O(nlogn), SC = O(n)
// Solution 3
class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<pair<int, int>> vec;
        vector<int> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0, x = arr[i];
            while (x)
            {
                x &= x - 1;
                cnt++;
            }
            vec.push_back({cnt, arr[i]});
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++)
        {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};