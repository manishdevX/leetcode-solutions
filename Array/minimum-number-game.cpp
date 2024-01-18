// LINK - https://leetcode.com/problems/minimum-number-game/description/

// n = size of nums

// Solution 1 TC = O(n^2), SC = O(n)
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> arr;
        while (nums.size())
        {
            auto min_itr1 = min_element(nums.begin(), nums.end());
            int min1 = *min_itr1;
            nums.erase(min_itr1);
            auto min_itr2 = min_element(nums.begin(), nums.end());
            int min2 = *min_itr2;
            arr.push_back(min2);
            arr.push_back(min1);
            nums.erase(min_itr2);
        }
        return arr;
    }
};

// Solution 2 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> arr;
        int ind = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        while (ind < n)
        {
            arr.push_back(nums[ind + 1]);
            arr.push_back(nums[ind]);
            ind += 2;
        }
        return arr;
    }
};

// Solution 3 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> arr;
        for (auto &&num : nums)
        {
            pq.push(num);
        }
        while (!pq.empty())
        {
            int min1 = pq.top();
            pq.pop();
            int min2 = pq.top();
            pq.pop();
            arr.push_back(min2);
            arr.push_back(min1);
        }
        return arr;
    }
};

// Solution 4 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();)
        {
            swap(nums[i++], nums[i++]);
        }
        return nums;
    }
};