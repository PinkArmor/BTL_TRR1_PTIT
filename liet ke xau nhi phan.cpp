#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >>n;
		int a[n+1];
		for(int i=1; i<=n; i++){
			a[i]=0;
		}
		int ok=1;
		while(ok){
			for(int i=1; i<=n; i++){
				cout<<a[i];
			}
			cout<<" ";
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
		cout << endl;
	}
}
