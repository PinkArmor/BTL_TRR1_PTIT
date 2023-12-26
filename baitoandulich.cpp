#include <bits/stdc++.h>
using namespace std;
int n;
int c[10][10];
int x[100];
bool unused[10];
int xopt[100];
int fopt=1e9;
void init(){
	cout << "Nhap so thanh pho: ";
	cin >> n;
	for(int i=1;i<=n;i++){
		unused[i]=1;
		for(int j=1;j<=n;j++){
			if(i!=j){
				cout << "Nhap chi phi di tu thanh pho "<< i << " den thanh pho "<< j << ":";
				cin >> c[i][j];
			}
		}
	}
}
int totalcost(){
	int cost=0;
	for(int i=1;i<=n-1;i++){
		cost+=c[x[i]][x[i+1]];
	}
	return cost+c[x[n]][x[1]];
}
void update(int value){
	for(int i=1;i<=n;i++){
		xopt[i]=x[i];
	}
	fopt=value;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(unused[j]){
			x[i]=j;
			unused[j]=0;
			if(i==n){
				if(totalcost() < fopt){
					update(totalcost());
				}
			}
			else Try(i+1);
			unused[j]=1;
		}
	}
}
void display(){
	cout << "Phuong an toi uu la: " ;
	for(int i=1;i<=n;i++){
		if(xopt[i]!=0) cout << i << " ";
	}
	cout << endl;
	cout << "Tong chi phi toi uu la: " << fopt;
}
int main(){
	init();
	Try(1);
	display();
}