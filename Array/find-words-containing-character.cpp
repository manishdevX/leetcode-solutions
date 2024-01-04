// LINK - https://leetcode.com/problems/find-words-containing-character/

// TC = O(size of words*avg length of words), SC = O(size of words)
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> indices;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(x) != string::npos)
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};
