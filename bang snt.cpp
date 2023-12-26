#include<bits/stdc++.h>
using namespace std;
 
char matran[5][5];
int dem = 0;
 
bool checksnt(int a){
    if (a<2) return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if(a%i==0) return false;
    }
    return true;
}
 
bool checktong(int a, int s){
    int temp = 0;
    while (a>0)
    {
        temp += a%10;
        a=a/10;
    }
    if(temp==s) return true;
    return false;
}
 
void printmt(char matran[5][5]){
	cout << "Ma tran " << dem << ":" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matran[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

void check11(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[0][0]==so[i][0] && matran[1][1]==so[i][1] && matran[2][2]==so[i][2] && matran[3][3]==so[i][3] && matran[4][4]==so[i][4]){
            dem ++;
        }
    }
    for (int i = 0; i < so.size(); i++)  {
        if(matran[0][0]==so[i][0] && matran[1][1]==so[i][1] && matran[2][2]==so[i][2] && matran[3][3]==so[i][3] && matran[4][4]==so[i][4]){
            printmt(matran);
        }
    }
}
 
void check10(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[4][0]==so[i][0] && matran[4][1]==so[i][1] && matran[4][2]==so[i][2] && matran[4][3]==so[i][3] && matran[4][4]==so[i][4]){
            check11(so);
        }
    }
}
 
void check9(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[0][4]==so[i][0] && matran[1][4]==so[i][1] && matran[2][4]==so[i][2] && matran[3][4]==so[i][3]){
            for (int j = 0; j < 5; j++)
            {
                matran[j][4]=so[i][j];
            }
            check10(so);
        }
    }
}
 
void check8(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[0][3]==so[i][0] && matran[1][3]==so[i][1] && matran[2][3]==so[i][2] && matran[3][3]==so[i][3]){
            for (int j = 0; j < 5; j++)
            {
                matran[j][3]=so[i][j];
            }
            check9(so);
        }
    }
}
 
void check7(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[3][0]==so[i][0] && matran[3][1]==so[i][1] && matran[3][2]==so[i][2]){
            for (int j = 0; j < 5; j++)
            {
                matran[3][j]=so[i][j];
            }
            check8(so);
        }
    }
}
 
void check6(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[0][2]==so[i][0] && matran[1][2]==so[i][1] && matran[2][2]==so[i][2]){
            for (int j = 0; j < 5; j++)
            {
                matran[j][2]=so[i][j];
            }
            check7(so);
        }
    }
}
 
void check5(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[2][0]==so[i][0] && matran[2][1]==so[i][1] && matran[2][2]==so[i][2]){
            for (int j = 0; j < 5; j++)
            {
                matran[2][j]=so[i][j];
            }
            check6(so);
        }
    }
}
 
void check4(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[0][1]==so[i][0] && matran[1][1]==so[i][1] && matran[3][1]==so[i][3]){
            for (int j = 0; j < 5; j++)
            {
                matran[j][1]=so[i][j];
            }
            check5(so);
        }
    }
}
 
void check3(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[1][0]==so[i][0] && matran[1][3]==so[i][3]){
            for (int j = 0; j < 5; j++)
            {
                matran[1][j]=so[i][j];
            }
            check4(so);
        }
    }
}
 
void check2(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[4][0]==so[i][4] && matran[0][4]==so[i][0]){
            for (int j = 0; j < 5; j++)
            {
                matran[j][4-j]=so[i][j];
            }
            check3(so);
        }
    }
}
 
void check1(const vector<string> so ){
    for (int i = 0; i < so.size(); i++)
    {
        if(matran[0][0] == so[i][0]){
            for (int j = 0; j < 5; j++)
            {
                matran[j][0]=so[i][j];
            }
            check2(so);
        }
    }
    return;
}
 
int main(){
    vector<string> so;
    int s; 
	cout << "Nhap tong S: ";
    cin >> s;
    for (int i = 10001; i < 100000; i++)
    {
        if(checksnt(i) && checktong(i,s))
        {
            string new_i = to_string(i);
            so.push_back(new_i);
        }
    }
 
    for (int i = 0; i < so.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matran[0][j]=so[i][j];
        }
 
        check1(so);
    }
    if(dem<1){
        cout << "Khong co ma tran thoa man\n";
    }
    else cout << "So truong hop thoa man la: " << dem << endl;
    
}

