#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return false;
	}
	return n>1;
}
int tong(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	return sum;
}
int tong1(vector<int> &v){
	int sum=0;
	for(int i=0; i<v.size(); i++){
		sum += v[i];
	}
	return sum;
}
void thu(int s,vector<vector<int>> &v, vector<int> &hang, vector<int> &cot){
	 if(hang == 5 && cot ==0){
	 	for(int i=0; i<5 ; i++){
	 		int sum =0;
	 		for(int j=0; j<5; j++){
	 			sum += v[i][j];
			 }
			 if(sum != tong1(v)){
			 	return 0;
			 }
	    }
	 }
	 
	
	
}
int main(){
	int n; cin >> n;
	vector<int> v1;
	vector<int> v2;
	int a[5][5];
	for(int i=10000; i<=99999; i++){
		if(tong(i)==n && prime(i))
		v1.push_back(i);
	}
	
	for(int i=0; i< v1.size(); i++){
		cout << v1[i] << " ";
	}
	
}
