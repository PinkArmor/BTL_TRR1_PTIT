#include <bits/stdc++.h>
using namespace std;
int n, k, ok=1; 
int a[1000];
void sinh(){
	int i=n;
	while(i>=1 && a[i]==1){
		a[i] = 0;
		--i;
	}
	if(i==0) ok =0;
	else a[i] = 1;
}
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
int main(){
	cin >> n >> k; 
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
		sinh();
	}
	cout << endl;
	
}
