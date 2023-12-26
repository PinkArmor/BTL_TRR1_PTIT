#include<bits/stdc++.h>
using namespace std;
int n,b;
int a[100];
int c[100];
int x[100]={};
int xopt[100];
int fopt=-1e9;
void input(){
	cout << "Nhap so luong do vat: ";
	cin >> n;
	cout << "Nhap khoi luong tui: ";
	cin >> b;
	for(int i=1;i<=n;i++){
		cout << "Nhap khoi luong va gia tri cua vat " << i << ":";
		cin >> a[i] >> c[i]; 
	} 
}
bool checkWeight(){
	int m=0;
	for(int i=1;i<=n;i++){
		m+=a[i]*x[i];
	}
	return m<=b;
}
int totalValue(){
	int value=0;
	for(int i=1;i<=n;i++){
		value+=c[i]*x[i];
	}
	return value;
}
void update(int value){
	for(int i=1;i<=n;i++){
		xopt[i]=x[i];
	}
	fopt=value;
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			if(checkWeight()){
				if(totalValue() > fopt){
					update(totalValue());
				}
			}
		}
		else Try(i+1);
	}
}
void output(){
	cout << "Phuong an toi uu la: ";
	for(int i=1;i<=n;i++){
		if(xopt[i]!=0) cout << i << " ";
	}
	cout << endl;
	cout << "Gia tri toi uu la: " << fopt;
}
int main(){
	input();
	Try(1);
	output();
	return 0;
}