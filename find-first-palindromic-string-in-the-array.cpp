// LINK - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// TC = O(n^2), SC = O(1)

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto &&word : words)
        {
            string new_word = word;
            reverse(new_word.begin(), new_word.end());

            if (new_word == word)
            {
                return word;
            }
        }
        return "";
    }
};