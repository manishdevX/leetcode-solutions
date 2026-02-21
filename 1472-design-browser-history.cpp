// LINK - https://leetcode.com/problems/design-browser-history

// n = no of inputs

// Solution 1, TC = O(n), SC = O(n) for vec and visit worst case
class BrowserHistory
{
private:
    vector<string> vec;
    int cur_pos;

public:
    BrowserHistory(string homepage)
    {
        vec.push_back(homepage);
        cur_pos = 0;
    }

    void visit(string url)
    {
        cur_pos++;
        vec.erase(vec.begin() + cur_pos, vec.end());
        vec.push_back(url);
    }

    string back(int steps)
    {
        cur_pos = steps > cur_pos ? 0 : cur_pos - steps;
        return vec[cur_pos];
    }

    string forward(int steps)
    {
        int n = vec.size();
        cur_pos = steps >= n - cur_pos ? n - 1 : cur_pos + steps;
        return vec[cur_pos];
    }
};

// Solution 2, TC = O(1), SC = O(n) for vec in worst case
class BrowserHistory
{
private:
    vector<string> vec;
    int cur_ind, end;

public:
    BrowserHistory(string homepage)
    {
        vec.push_back(homepage);
        cur_ind = 0;
        end = 0;
    }

    void visit(string url)
    {
        int new_ind = cur_ind + 1;
        if (new_ind == vec.size())
        {
            vec.push_back(url);
        }
        else
        {
            vec[new_ind] = url;
        }
        cur_ind = new_ind;
        end = new_ind;
    }

    string back(int steps)
    {
        int new_ind = cur_ind - steps;
        cur_ind = new_ind < 0 ? 0 : new_ind;
        return vec[cur_ind];
    }

    string forward(int steps)
    {
        int new_ind = cur_ind + steps;
        cur_ind = new_ind > end ? end : new_ind;
        return vec[cur_ind];
    }
};

// Solution 3, TC = O(n), SC = O(n) for history in worst case
class BrowserHistory
{
private:
    stack<string> history;
    stack<string> future;

public:
    BrowserHistory(string homepage) { history.push(homepage); }

    void visit(string url)
    {
        history.push(url);
        future = stack<string>();
    }

    string back(int steps)
    {
        while (steps-- && history.size() > 1)
        {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }

    string forward(int steps)
    {
        while (steps-- && future.size())
        {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};