// LINK - https://leetcode.com/problems/3sum

// n = size of nums

// Solution 1 TC = O(n^3logn), SC = O(n^3) TLE
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> arr = {{nums[i], nums[j], nums[k]}};
                        sort(arr.begin(), arr.end());
                        s.insert(arr);
                    }
                }
            }
        }
        for (auto &&it : s)
        {
            ans.push_back(it);
        }

        return ans;
    }
};

// Solution 2 TC = O(n^2logn), SC = O(n^2) TLE
class Solution
{
public:
    vector<vector<int>> threeSumHelper(vector<int> &nums, int target, int ind)
    {
        vector<vector<int>> ans;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == ind)
            {
                continue;
            }
            else if (s.find(target - nums[i]) != s.end())
            {
                ans.push_back({nums[i], target - nums[i]});
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<vector<int>> temp = threeSumHelper(nums, nums[i] * -1, i);
            for (auto &&vec : temp)
            {
                vec.push_back(nums[i]);
                sort(vec.begin(), vec.end());
                s.insert(vec);
            }
        }
        for (auto &&it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

// Solution 3 TC = O(n^2logn), SC = O(n^2) TLE
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> us;
            for (int j = i + 1; j < n; j++)
            {
                int tar = 0 - (nums[i] + nums[j]);
                if (us.find(tar) != us.end())
                {
                    vector<int> temp = {nums[i], nums[j], tar};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                us.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

// Solution 4 TC = O(n^2logn), SC = O(n^2)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            int tar = 0 - nums[i], lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] < tar)
                {
                    lo++;
                }
                else if (nums[lo] + nums[hi] > tar)
                {
                    hi--;
                }
                else
                {
                    vector<int> v = {nums[i], nums[lo], nums[hi]};
                    sort(v.begin(), v.end());
                    if (s.find(v) == s.end())
                    {
                        ans.push_back(v);
                        s.insert(v);
                    }

                    lo++;
                    hi--;
                }
            }
        }
        return ans;
    }
};

// Solution 5 TC = O(n^2), SC = O(n^2)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int tar = 0 - nums[i], j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] < tar)
                {
                    j++;
                }
                else if (nums[j] + nums[k] > tar)
                {
                    k--;
                }
                else
                {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
