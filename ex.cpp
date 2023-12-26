#include<bits/stdc++.h>
using namespace std;
struct chuSo{
	int x[5];
};
vector<chuSo> ds;

// day so nguyen to co tong bang s 
void ds_nto(int s){
	int prime[100000];
	for(int i = 2 ; i <= 99999 ; i++){
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i = 2; i < sqrt(100000); i++){
		if(prime[i]){
			for(int j = i*i ; j < 100000 ; j += i){
				prime[j] = 0; // sang so nguyen to
			}
		}
	}

	// so co tong chu so bang s
	for(int i = 10000 ; i < 100000 ; i++){
		if(prime[i]){
			int t  = i;
			chuSo c;
			for(int j = 4; j >= 0 ; j--){
				c.x[j] = t % 10;
				t/=10;
			}
			if(c.x[0] + c.x[1] + c.x[2] + c.x[3] +  c.x[4] == s){
				ds.push_back(c);
			}
		}
	}
} 

// kiem tra ma tran 
bool ktra(int A[5][5]  , int s){
	int cnt = 0;
	if(A[0][0] + A[1][1] + A[2][2] + A[3][3] + A[4][4] != s){
		cnt++;
	}
	if(A[0][4] + A[1][4] + A[2][4] + A[3][4] + A[4][4] != s) cnt++;
	if(cnt == 0) return true;
	else return false;
}

int main(){
	int A[5][5];
	int s;
	cout << "Nhap tong S: ";
	cin>>s;
	ds_nto(s);
	int &a1 =A[0][0] , &a2 = A[0][1] , &a3=A[0][2] , &a4=A[0][3], &a5=A[0][4],
	&a6=A[1][0] , &a13 =A[1][1] , &a14 =A[1][2] , &a12=A[1][3] , &a15 =A[1][4],
	&a7=A[2][0] , &a16 =A[2][1] , &a11 =A[2][2] , &a18=A[2][3] , &a19 =A[2][4],
	&a8=A[3][0] , &a10 =A[3][1] , &a20 =A[3][2] , &a22=A[3][3] , &a23 =A[3][4],
	&a9=A[4][0] , &a17 =A[4][1] , &a21 =A[4][2] , &a24=A[4][3] , &a25 =A[4][4];
	// lap day hang 1 cot 1
	int H1C1 = 0;
	
	for(;H1C1 < ds.size() ; H1C1++){
		if(ds[H1C1].x[0] != 0 && ds[H1C1].x[1] != 0 && ds[H1C1].x[2] != 0 && ds[H1C1].x[3] != 0 && ds[H1C1].x[4] != 0){
			a1 = ds[H1C1].x[0];
			a2 = a6 = ds[H1C1].x[1];
			a3 = a7 = ds[H1C1].x[2];
			a4 = a8 = ds[H1C1].x[3];
			a5 = a9 = ds[H1C1].x[4];
			H1C1++;
			break;
		}
}
if(H1C1 == ds.size()){
	return 1;
}

// lap day duong cheo nguoc
int X = 0;
X:
	for(; X < ds.size() ; X++){
		if(ds[X].x[0] == a9 && ds[X].x[4] == a5){
			a10 = ds[X].x[1];
			a11 =ds[X].x[2];
			a12 =ds[X].x[3];
			X++;
			break;
		}
	}
	if(X == ds.size()){
		goto C1H1;
	}

	// lap day hang 2
	int H2 = 0;
H2:
	for(; H2 < ds.size() ; H2++){
		if(ds[H2].x[0] == a6 && ds[H2].x[3] == a12){
			a13 = ds[H2].x[1];
			a14 = ds[H2].x[2];
			a15 = ds[H2].x[4];
			H2++;
			break;
		}
	}
	if(H2 == ds.size()){
		goto X;
	}

	// lap day cot 2
	int C2 = 0;
C2:
	for(; C2 < ds.size() ; C2++){
		if(ds[C2].x[0] == a2 && ds[C2].x[1] == a13 && ds[C2].x[3] == a10){
			a16 = ds[C2].x[2];
			a17 = ds[C2].x[4];
			C2++;
			break;
		}
	}
	if(C2 == ds.size()){
		goto H2;
	}

	//  lap day hang 3
	int H3 = 0 ;
H3:
	for(; H3 < ds.size() ; H3++){
		if(ds[H3].x[0] == a7 && ds[H3].x[1] == a16 && ds[H3].x[2] == a11){
			a18 = ds[H3].x[3];
			a19 = ds[H3].x[4];
			H3++;
			break;
		}
	}
	if(H3 == ds.size()){
		goto C2;
	}
// lap day cot 3
int C3 = 0 ;
C3:
	for(; C3 < ds.size() ; C3++){
		if(ds[C3].x[0] == a3 && ds[C3].x[1] == a14 && ds[C3].x[2] == a11){
			a20 = ds[C3].x[3];
			a21 = ds[C3].x[4];
			C3++;
			break;
		}
	}
	if(C3 == ds.size()){
		goto H3;
	}

	// lap day hang 4
	int H4 = 0;
H4:
	for(; H4 < ds.size() ; H4++){
		if(ds[H4].x[0] == a8 && ds[H4].x[1] == a10 && ds[H4].x[2] == a20){
			a22 = ds[H4].x[3];
			a23 = ds[H4].x[4];
			H4++;
			break;
		}
	}
	if(H4 == ds.size()){
		goto C3;
	}

	// lap day cot 4
	int C4 = 0;
C4:
	for(; C4 < ds.size() ; C4++){
		if(ds[C4].x[0] == a4 && ds[C4].x[1] == a12 && ds[C4].x[2] == a18 && ds[C4].x[3] == a22){
			a24 = ds[C4].x[4];
			C4++;
			break;
		} 
	}
	if(C4 == ds.size()){
		goto H4;
	}

	// lap day cot 5
	int C5 = 0;
C5:
	for(; C5 < ds.size() ; C5++){
		if(ds[C5].x[0] == a5 && ds[C5].x[1] == a15 && ds[C5].x[2] == a19 && ds[C5].x[3] == a23){
			a25 = ds[C5].x[4];
			C5++;
			break;
		}
	}
	if(C5 == ds.size()){
		goto C4;
	}

	// neu ma tran khong thoa man quay ve buoc C5
	if(ktra(A , s) == false){
		goto C5;
	}

	 //neu thoa man in ra roi quay lai buoc lap day C5
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 5 ; j++){
			cout<<A[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	goto C5;
}

