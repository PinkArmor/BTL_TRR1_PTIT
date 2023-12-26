#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[n+1]; // x1x2...xn
    for(int i=1; i<=n; i++){
        a[i] =0; // cau hinh dau tien
    }
    int ok=1;
    while(ok){ // lap cau hinh chua phai cuoi cung 
        for(int i=1; i<=n; i++){
            cout << a[i] ;
        }
        int i=n; // bat dau tu bit cuoi cung 
        // tim bit 0 dau tien
        while(i >=1 && a[i]==1){
            
            a[i] = 0;
            i--;
        }
        if(i==0){
            ok=0; //da tim dc cau hinh cuoi cung
            // ok=0 de thoat khoi while
        }
        else {
            a[i] = 1;
        }
        cout << endl;
    }
}
