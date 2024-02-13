#include<iostream>
using namespace std;
inline int getnum(){
    int x = 1, res = 0;
    char ch = getchar();
    while (ch>'9' || ch<'0')
    {
        x = -1;
        ch = getchar();
    }
    while (ch>='0' && ch<='9')
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res*x;   
}
inline string getstr(){
    char ch = getchar();
    string str = "";
    while (ch == '\n' || ch == '\r' || ch == ' ')
        ch = getchar();
    while (ch != '\n' && ch != '\r' && ch != ' ')
    {
        str += ch;
        ch = getchar();
    }
    return str;
}
void putnum(int x){
    if (x<0)
    {
        putchar('-');
        x = -x;
    }
    if(x>9){
        putnum(x/10);
    }
    putchar(x%10+'0');
    return;
}
void putstr(string& a){
    for(int i = 0; a[i]!='\0'; i++)
    putchar(a[i]);
}
int main(){
    int a = getnum();
    putnum(a);
    string str = getstr();
    putstr(str);
    return 0;
}
