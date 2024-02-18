#include<iostream>
#include<cstdio>
#define swap std::swap
inline int getnum(){
    int x = 1, res = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        x = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        res = res*10 + ch-'0';
        ch = getchar();
    }
    return res*x;
}
inline void putnum(int x){
    if(x<0){
        putchar('-');
        x = -x;
    }
    if(x>9){
        putnum(x/10);
    }
    putchar(x%10+'0');
}
inline void quick_sort(int q[], int l, int r){
    if(l>=r) return ;
    int i = l-1, j = r+1, mid = q[(l+r)>>1];
    while(i<j){
        do i++; while(q[i]<mid);
        do j--; while(q[j]>mid);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}
int main(){
    int n = getnum();
    int arr[n];
    for(int i = 0; i<=n-1; i++) arr[i] = getnum();
    quick_sort(arr, 0, n-1);
    for(int i = 0; i<=n-1; i++){
        putnum(arr[i]);
        putchar(' ');
    } 
    return 0;
}