// LINK - https://leetcode.com/problems/unique-morse-code-words/

// TC = O(n*m), SC = O(n)
// solution 1
class Solution
{
public:
    unordered_map<char, string> umap;

    Solution()
    {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string marr[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        for (int i = 0; i < 26; i++)
        {
            umap[alpha[i]] = marr[i];
        }
    }

    int uniqueMorseRepresentations(vector<string> &words)
    {
        int n = words.size();
        unordered_set<string> res;

        for (int i = 0; i < n; i++)
        {
            string st = morseCode(words[i]);
            res.insert(st);
        }
        return res.size();
    }

    string morseCode(string str)
    {
        string st = "";
        for (auto &&c : str)
        {
            st += umap[c];
        }
        return st;
    }
};

// TC = O(n*m), SC = O(n)
// solution 2
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> res;
        string arr[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        for (auto &&word : words)
        {
            string st = "";
            for (auto &&c : word)
            {
                st += arr[c - 'a'];
            }
            res.insert(st);
        }
        return res.size();
    }
};