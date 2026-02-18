// LINK - https://leetcode.com/problems/count-common-words-with-one-occurrence

// n1 = size of words1, n2 = size of words2

// Solution 1 TC = O(n1*(n1+n2)), SC = O(1)
class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        int total = 0;
        for (auto &&word : words1)
        {
            if (count(words1.begin(), words1.end(), word) == 1 && count(words2.begin(), words2.end(), word) == 1)
            {
                total++;
            }
        }
        return total;
    }
};

// Solution 2 TC = O(n1+n2), SC = O(n1+n2)
class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        int total = 0;

        for (auto &&word : words1)
        {
            mp1[word]++;
        }
        for (auto &&word : words2)
        {
            mp2[word]++;
        }

        for (auto &&word : words1)
        {
            if (mp1[word] == 1 && mp2[word] == 1)
            {
                total++;
            }
        }
        return total;
    }
};
