// LINK - https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/

// n = size of words, m = avg size of words[i]

// Solution 1 TC = O(n), SC = O(m)
class Solution
{
public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int count = 0;
        string vowels = "aeiou";
        while (left <= right)
        {
            string st = words[left];
            if (vowels.find(st[0]) != string::npos &&
                vowels.find(st[st.size() - 1]) != string::npos)
            {
                count++;
            }
            left++;
        }
        return count;
    }
};