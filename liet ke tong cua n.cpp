#include <bits/stdc++.h>
using namespace std;
int n,x[100],a[100];
void init(){
	for(int i=1;i<=n;i++){
		x[i]=0;
	}
}
void sinh(){
	int i=n;
	while(i>0 && x[i]==1){
		x[i]=0;
		i--;
	}
	x[i]=1;
}
bool check(){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1){
			sum+=i;
		}
	}
	if(sum==n) return true;
	return false;
}
bool check2(){
	if(x[n]==1){
		for(int i = 1; i <= n -1 ;i++){
			if(x[i] == 1)return true;
		}
		return false;
	}
	return true;
}
void display(){
	if(check() && check2()){
		vector<int> v;
		for(int i=n;i>=1;i--){
			if(x[i]==1){
				v.push_back(i);
				cout << i << " ";
			}	
		}
		cout << endl;
		for(int x : v){
			cout << x << " ";
		}
		cout << "0" << endl;
	}
}
bool isFinal(){
	for(int i=1;i<=n;i++){
		if(x[i]!=1) return false;
	}
	return true;
}
int main(){
	cin >> n;
	init();
	while(!isFinal()){
		display();
		sinh();
	}
	display();
	return 0;
}
