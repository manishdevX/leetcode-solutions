// LINK - https://leetcode.com/problems/reduce-array-size-to-the-half/description/

// n = size of arr

// Solution 1 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        vector<int> vec;
        int n = arr.size(), half_size = n / 2, count = 0;
        for (auto &&num : arr)
        {
            mp[num]++;
        }
        for (auto &&it : mp)
        {
            vec.push_back(it.second);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        while (n > half_size)
        {
            n -= vec[count++];
        }
        return count;
    }
};
