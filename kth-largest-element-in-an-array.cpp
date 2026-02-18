// LINK - https://leetcode.com/problems/kth-largest-element-in-an-array

// n = size of nums

// Solution 1 TC = O(nlogn), SC = O(1)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Solution 2 TC = O(nlogn), SC = O(n)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int> pq;
        for (auto &&num : nums)
        {
            pq.push(num);
        }
        while (--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};

// Solution 3 TC = O(nlogk), SC = O(k)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &&num : nums)
        {
            if (pq.size() == k)
            {
                if (num > pq.top())
                {
                    pq.pop();
                    pq.push(num);
                }
            }
            else
            {
                pq.push(num);
            }
        }
        return pq.top();
    }
};

// Solution 4 TC = O(n), SC = O(n) TLE
class Solution
{
private:
    int partition(vector<int> &nums, int pivot, int lo, int hi)
    {
        int i = lo, j = lo;
        while (i <= hi)
        {
            if (nums[i] > pivot)
            {
                i++;
            }
            else
            {
                swap(nums[i++], nums[j++]);
            }
        }

        return j - 1;
    }

    int quickSelect(vector<int> &nums, int i, int j, int k)
    {
        int ind = partition(nums, nums[j], i, j);
        if (ind < k)
        {
            return quickSelect(nums, ind + 1, j, k);
        }
        else if (ind > k)
        {
            return quickSelect(nums, i, ind - 1, k);
        }
        return nums[ind];
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int a = quickSelect(nums, 0, n - 1, n - k);
        return a;
    }
};

// Solution 5 TC = O(n^2), SC = O(n)
class Solution
{
private:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];

        int i = low + 1;
        int j = high;

        while (i <= j)
        {
            if (nums[i] < pivot && pivot < nums[j])
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= pivot)
            {
                i++;
            }
            if (pivot >= nums[j])
            {
                j--;
            }
        }

        swap(nums[low], nums[j]);
        return j;
    }

    int quickSelect(vector<int> &nums, int i, int j, int k)
    {
        int ind = partition(nums, i, j);
        if (ind < k)
        {
            return quickSelect(nums, ind + 1, j, k);
        }
        else if (ind > k)
        {
            return quickSelect(nums, i, ind - 1, k);
        }
        return nums[ind];
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, k - 1);
    }
};