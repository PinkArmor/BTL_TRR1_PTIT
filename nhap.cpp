#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n; 
		map<int,int> mp;
		int a[n];
		for(int i=0; i<n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		int ok=0;
		int ans=0;
		for(int i=0; i<n; i++){
			if(mp[a[i]]>1 && !ok){
				ok=1;
				ans = a[i];
			}
		}
		if(ok) cout << ans << endl;
		else cout << "NO\n";
	}
}
