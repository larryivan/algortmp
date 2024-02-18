#include <iostream>
#include <vector>
using namespace std;
inline string getstr()
{
    char ch = getchar();
    string str = "";
    while (ch == ' ' || ch == '\n' || ch == '\r')
        ch = getchar();
    while (ch != ' ' && ch != '\n' && ch != '\r')
        str += ch, ch = getchar();
    return str;
}
vector<int> add(vector<int> a, vector<int> b)
{
    if (a.size() < b.size())
        return add(b, a);
    vector<int> res;
    char t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size())
            t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t)
        res.push_back(t);
    return res;
}
// To check whether b is bigger than a. If so, return 1.
char cmp(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
        return 0;
    else if (a.size() < b.size())
        return 1;
    else if (a.size() == b.size())
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (b[i] > a[i])
                return 1;
            else if (a[i] > b[i])
                return 0;
        }
        return 2;
    }
}
vector<int> sub(vector<int> a, vector<int> b)
{
    vector<int> res;
    if (cmp(a, b) == 1)
        return sub(b, a);
    else if (cmp(a, b) == 2)
    {
        res.push_back(0);
        return res;
    }
    else
    {
        char t = 0;
        for (int i = 0; i < a.size(); i++)
        {
            t = a[i] - t;
            if (i < b.size())
                t = t - b[i];
            res.push_back((t + 10) % 10);
            if (t < 0)
                t = 1;
            else
                t = 0;
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        return res;
    }
}
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
}
inline int getnum()
{
    int x = 1, t = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        x = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        t = t * 10 + ch - '0';
        ch = getchar();
    }
    return t;
}
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
int main()
{
    string a = getstr();
    string b = getstr();
    vector<int> A;
    vector<int> B;
    for (int i = int(a.size()) - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = int(b.size()) - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    return 0;
}