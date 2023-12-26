#include <bits/stdc++.h>
using namespace std;
int n, k; 
int a[1000];

bool check(){
	int cnt=0, ans=0;
	for(int i=1; i<=n; i++){
		if(a[i]==0){
			++cnt;
		}
		else {
			cnt=0;
		}
		if(cnt>k){
			return false;
		}
		if(cnt==k){
			++ans;
		}
	}
	return ans==1;
}
/*/bool check(){
	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=a[i];
	}
	return sum==k;
}/*/
int main(){
	cin >> n >> k; 
	int ok=1;
	for(int i=1; i<=n; i++){
		a[i] = 0;
	}
	while(ok){
		if(check()){
			for(int i=1; i<=n; i++){
				if(a[i]) cout << "B";
				else cout << "A";
			}
			cout << endl;
		}
		int i=n;
	while(i>=1 && a[i]==1){
		a[i] = 0;
		--i;
	}
	if(i==0) ok =0;
	else a[i] = 1;
	}
	cout << endl;
	
}
