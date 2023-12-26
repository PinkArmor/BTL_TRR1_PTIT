#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100001];
bool check(){
    int sum=0;
    for(int i=1; i<=n; i++){
        sum+=a[i];
    }
    return sum==k;
}
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        a[i]=0;
    }
    int ok=1;
    while(ok){
        if(check()){
            for(int i=1; i<=n; i++){
                cout<<a[i];
            }
            cout<<endl;
        }
        int i=n;
        while(i>=1 && a[i]==1){
            a[i]=0;
            --i;
        }
        if(i==0){
            ok=0;
        }
        else {
            a[i]=1;
        }
    }
}
