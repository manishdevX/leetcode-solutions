// LINK - https://leetcode.com/problems/arithmetic-subarrays

// n = size of nums, m = size of l and r

// Solution 1 TC = O(m*nlogn), SC = O(n)
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                          vector<int> &r)
    {
        int m = l.size();
        vector<bool> ans;
        for (int i = 0; i < m; i++)
        {
            vector<int> vec(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(vec.begin(), vec.end());
            int diff = vec[1] - vec[0];
            bool val = true;
            for (int i = 2; i < vec.size(); i++)
            {
                if (vec[i] - vec[i - 1] != diff)
                {
                    val = false;
                    break;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};

// Solution 2 TC = O(m*n), SC = O(n)

class Solution
{
public:
    bool check(vector<int> &arr)
    {
        int maxi = INT16_MIN, mini = INT16_MAX, n = arr.size();
        unordered_set<int> s;
        for (auto &&num : arr)
        {
            maxi = max(maxi, num);
            mini = min(mini, num);
            s.insert(num);
        }
        if ((maxi - mini) % (n - 1))
        {
            return false;
        }

        int diff = (maxi - mini) / (n - 1);
        int num = mini + diff;
        while (num < maxi)
        {
            if (s.find(num) == s.end())
            {
                return false;
            }
            num += diff;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                          vector<int> &r)
    {
        int m = l.size();
        vector<bool> ans;
        for (int i = 0; i < m; i++)
        {
            vector<int> arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            bool res = check(arr);
            ans.push_back(res);
        }
        return ans;
    }
};