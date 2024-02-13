#include<iostream>
#include<vector>
using namespace std;
inline string getstr(){
    char ch = getchar();
    string str = "";
    while(ch == ' ' || ch == '\n' || ch == '\r')
        ch = getchar();
    while(ch != ' ' && ch != '\n' && ch != '\r')
        str += ch, ch = getchar();
    return str;
}
vector<char> add(vector<char> a, vector<char> b){
    if(a.size()<b.size()) return add(b, a);
    vector<char> res;
    char t = 0;
    for(int i = 0; i<a.size(); i++){
        t += a[i];
        if(i<b.size()) t += b[i];
        res.push_back(t%10);
        t /= 10;
    }
    if(t) res.push_back(t);
    return res;
}
int main(){
    string a = getstr();
    string b = getstr();
    vector<char> A;
    vector<char> B;
    for(int i = int(a.size())-1; i>=0; i--) A.push_back(a[i]-'0');
    for(int i = int(b.size())-1; i>=0; i--) B.push_back(b[i]-'0');
    auto res = add(A, B);
    for(int i = int(res.size())-1; i>=0; i--) putchar(res[i]+'0');
    return 0;
}