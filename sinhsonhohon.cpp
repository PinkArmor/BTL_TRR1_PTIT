#include <bits/stdc++.h>
using namespace std;
int n,k,x[100],a[100];
void init(){
	for(int i=1;i<=k;i++){
		x[i]=i;
	}
}
bool check(){
	for(int i=1;i<=k-1;i++){
		if(a[x[i]] <= a[x[i+1]]){
			return false;
		}
	}
	return true;
}
void sinh(){
	int i=k;
	while(i>0 && x[i]==n-k+i){
		i--;
	}
	x[i]++;
	int j=i+1;
	while(j<=k){
		x[j]=x[j-1]+1;
		j++;
	}
}
void display(){
	if(check()){
		for(int i=1;i<=k;i++){
			cout << a[x[i]] << " ";
		}
		cout << endl;
	}
}
bool isFinal(){
	for(int i=1;i<=k;i++){
		if(x[i]!=n-k+i){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	init();
	while(!isFinal()){
		display();
		sinh();
	}

	return 0;
}
