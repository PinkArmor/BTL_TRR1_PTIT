#include<bits/stdc++.h>

using namespace std;

// ki?m tra xem s? d� c� ph?i s? nguy�n t? hay kh�ng
int nguyen_to(int n){
    if(n<2) return 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return n>1;
}
// ki?m tra xem t?ng c�c ch? s? c?a s? d� c� ph?i l� s? k nh?p t? b�n ph�m kh�ng
int kiem_tong(int n){
    int tong=0;
    while(n>0){
        tong+=n%10;
        n/=10;
    }
    return tong;
}

string snt[1000];// kh?i t?o m?ng 1 chi?u luu c�c s? nguy�n t? th?a m�n 2 di?u ki?n d? b�i
int cnt=0;// d?m s? ph?n t? c?a m?ng s? nguy�n t? v?a luu

string cheo[200];// m?ng luu c�c ph?n t? du?ng ch�o th?a m�n
string h1[200];//luu c�c ph?n t? thu?c h�ng 1 th?a m�n
string c1[200];//luu c�c ph?n t? thu?c c?t 1 th?a m�n
string h2[200];//luu c�c ph?n t? thu?c h�ng 2 th?a m�n
string c2[200];//luu c�c ph?n t? thu?c c?t 2 th?a m�n
string h3[200];//luu c�c ph?n t? thu?c h�ng 3 th?a m�n
string c3[200];//luu c�c ph?n t? thu?c c?t 3 th?a m�n

//ki?m tra xem s? d� c� ch? s? 0 kh�ng
int check(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') return 0;
    }
    return 1;
}

//ki?m tra c�c ph?n t? th?a m�n thu?c du?ng ch�o ch�nh
int check1(char l, char r)
{
     int dem=0;
     for(int i=0;i<cnt;i++){
       string sao=snt[i];
       if(sao[0]==l && sao[4]==r){
        cheo[dem]=sao;
        dem++;
       }
     }
    return dem;
}

//ki?m tra c�c ph?n t? th?a m�n thu?c h�ng 1
int check2(char l, char r)
{
     int dem=0;
     for(int i=0;i<cnt;i++){
       string sao=snt[i];
       if(sao[0]==l && sao[3]==r){
        h1[dem]=sao;
        dem++;
       }
     }
    return dem;
}

//ki?m tra c�c ph?n t? th?a m�n thu?c c?t 1
int check3(char l, char m, char r){
    int dem=0;
    for(int i=0;i<cnt;i++){
        string sao=snt[i];
        if(sao[0]==l && sao[1]==m && sao[3]==r){
            c1[dem]=sao;
            dem++;
        }
    }
    return dem;
}

// ki?m tra c�c ph?n t? th?a m�n thu?c h�ng 2
int check4(char l,char m, char r){
    int dem=0;
    for(int i=0;i<cnt;i++){
        string sao=snt[i];
        if(sao[0]==l && sao[1]==m && sao[2]==r){
            h2[dem]=sao;
            dem++;
        }
    }
    return dem;

}

//ki?m tra c�c ph?n t? th?a m�n thu?c c?t 2
int check5(char l,char m, char r){
    int dem=0;
    for(int i=0;i<cnt;i++){
        string sao=snt[i];
        if(sao[0]==l && sao[1]==m && sao[2]==r){
            c2[dem]=sao;
            dem++;
        }
    }
    return dem;

}

//ki?m tra c�c ph?n t? th?a m�n thu?c h�ng 3
int check6(char l,char m, char r){
    int dem=0;
    for(int i=0;i<cnt;i++){
        string sao=snt[i];
        if(sao[0]==l && sao[1]==m && sao[2]==r){
            h3[dem]=sao;
            dem++;
        }
    }
    return dem;

}

//ki?m tra c�c ph?n t? th?a m�n thu?c c?t 3
int check7(char l,char m, char r, char t){
    int dem=0;
    for(int i=0;i<cnt;i++){
        string sao=snt[i];
        if(sao[0]==l && sao[1]==m && sao[2]==r && sao[3]==t){
            c3[dem]=sao;
            dem++;
        }
    }
    return dem;

}

int main(){
   int k; cin>>k;
   char a[5][5];
   int count=0;      // luu s? lu?ng c�c ph?n t? th?a thu?c du?ng  ch�o ch�nh
   int hang1=0;      // luu s? lu?ng c�c ph?n t? th?a m�n thu?c h�ng 1
   int cot1=0;       // ;uu s? lu?ng c�c ph?n t? th?a m�n thu?c c?t 1
   int hang2=0;      // luu s? lu?ng c�c ph?n t? th?a m�n thu?c h�ng 2
   int cot2=0;       // luu s? lu?ng c�c ph?n t? th?a m�n thu?c c?t 2
   int hang3=0;      // luu s? lu?ng c�c ph?n t? th?a m�n thu?c h�ng 3
   int cot3=0;       // ;uu s? lu?ng c�c ph?n t? th?a m�n thu?c c?t 3
   int q=0,w=0,e=0;  //q luu ph?n t? thu?c du?ng ch�o ch�nh th? 2 , w luu ph?n t? thu?c c?t 4, e luu ph?n t? thu?c h�ng 4
  
   //kh?i t?o m?ng 5*5 
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++) a[i][j]='0';
    }

   //luu c�c ph?n t? v?a l� s? nguy�n t? v?a c� t?ng c�c ch? s? b?ng s? k
    for(int i=10000;i<=99999;i++){
        if(nguyen_to(i) && kiem_tong(i)==k ){
            string s=to_string(i);
             snt[cnt]=s;
             cnt++;
        }
    }
    
    for(int i=0;i<cnt;i++){          //duy?t qua t?ng ph?n t? t? c?a m?ng s? nguy�n t? d? luu v�o h�ng 0
        string tmp1=snt[i];
        if(check(tmp1))               // ki?m tra s? d� c� ch? s? 0 trong d� hay kh�ng
             for(int j=0;j<cnt;j++){   // duy?t t?ng ph?n t? c?a m?ng s? nguy�n t? d? luu v�o c?t 0
            string tmp2=snt[j];
            if(tmp1[0]==tmp2[0] && check(tmp2)==1){
                for(int k=0;k<5;k++){
                    a[0][k]=tmp1[k];
                    a[k][0]=tmp2[k];      //luu c�c ph?n t? v�o h�ng 0 v� c?t 0
                }

               count=check1(a[4][0],a[0][4]);   // s? lu?ng ph?n t? thu?c du?ng ch�o ch�nh
                int chay=0;                      // bi?n ch?y d? duy?t qua t?ng ph?n t? c?a du?ng ch�o ch�nh
                while(chay<count)               // l?p qua c�c ph?n t? c?a du?ng ch�o
                {
                   string minh=cheo[chay];
                   a[3][1]=minh[1];
                   a[2][2]=minh[2];            // g�n c�c ph?n t? v�o du?ng ch�o ch�nh
                   a[1][3]=minh[3];
                   
                   hang1=check2(a[1][0],a[1][3]);     // d?m s? lu?ng c�c ph?n t? c?a h�ng 1
                   int chayh1=0;                      // bi?n chayh1 d? duy?t qua c�c ph?n t? c?a h�ng 1
                   while(chayh1<hang1){
                       string tam_hang1=h1[chayh1];
                       a[1][1]=tam_hang1[1];          // g�n c�c ph?n t? v�o h�ng 1
                       a[1][2]=tam_hang1[2];
                       a[1][4]=tam_hang1[4];
                        cot1=check3(a[0][1], a[1][1], a[3][1]); // s? ph?n t? c?a c?t 1
                       int chay_cot1=0;                         // bi?n chay_cot1 d? duy?t qua c�c ph?n t? c?a c?t 1
                       while(chay_cot1<cot1){
                           string tam_cot1=c1[chay_cot1];
                           a[2][1]=tam_cot1[2];                 // g�n c�c ph?n t? v�o c?t 1
                           a[4][1]=tam_cot1[4];
                           hang2=check4(a[2][0], a[2][1], a[2][2]);    // s? ph?n t? c?a h�ng 2
                           int chay_hang2=0;                           // bi?n chay_hang2 d? duy?t qua c�c ph?n t? c?a h�ng 2
                           while(chay_hang2<hang2){
                            string tam_hang2=h2[chay_hang2];
                            a[2][3]=tam_hang2[3];                      // g�n c�c ph?n t? v�o h�ng 2
                            a[2][4]=tam_hang2[4];
                            cot2=check5(a[0][2],a[1][2],a[2][2]);      // s? lu?ng c�c ph�n t? c?a c?t 2
                            int chay_cot2=0;                           // bi?n chay_cot2 d? duy?t qua c�c ph?n t?
                            while(chay_cot2<cot2){
                                string tam_cot2=c2[chay_cot2];
                                a[3][2]=tam_cot2[3];                   // g�n c�c ph?n t? v�o c?t 2
                                a[4][2]=tam_cot2[4];
                                hang3=check6(a[3][0],a[3][1], a[3][2]);    // s? lu?ng c�c ph?n t? c?a h�ng 3
                                int chay_hang3=0;                     // bi?n  chay_hang 3 d? duy?t qua c�c ph?n t? c?a h�ng 3
                                while(chay_hang3<hang3){
                                    string tam_hang3=h3[chay_hang3];
                                    a[3][3]=tam_hang3[3];             // g�n c�c ph?n t? v�o h�ng 3
                                    a[3][4]=tam_hang3[4];
                                    cot3=check7(a[0][3],a[1][3],a[2][3],a[3][3]);  // s? lu?ng c�c ph?n t? c?a c?t 3
                                    int chay_cot3=0;                      // bi?n ch?y_cot3 d? duy?t qua c�c ph?n t? c?a c?t 3
                                    while(chay_cot3<cot3){
                                        string tam_cot3=c3[chay_cot3];
                                        a[3][3]=tam_cot3[3];            // g�n c�c ph?n t? v�o c?t 3
                                        a[4][3]=tam_cot3[4];
                                        
                                        // cho a[4][4] l?n lu?t b?ng c�c gi� tr? 1,3,7,9 v� ki?m tra xem du?ng ch�o c�n l?i v?i h�ng 4,
                                        // c?t 4 c� th?a m�n v?a l� snt v� v?a c� t?ng b?ng k hay kh�ng
                                        // n?u th?a m�n th� in ra gi� tr? c?a m?ng a 
                                        // n?u kh�ng th?a m�n th� tang bi?n chay_cot3 v� ti?p t?c t�m s?
                                            a[4][4]='1';
                                            q=(a[0][0]-'0')*10000+(a[1][1]-'0')*1000+(a[2][2]-'0')*100+(a[3][3]-'0')*10+(a[4][4]-'0');
                                            w=(a[0][4]-'0')*10000+(a[1][4]-'0')*1000+(a[2][4]-'0')*100+(a[3][4]-'0')*10+(a[4][4]-'0');
                                            e=(a[4][0]-'0')*10000+(a[4][1]-'0')*1000+(a[4][2]-'0')*100+(a[4][3]-'0')*10+(a[4][4]-'0');
                                            if(nguyen_to(q) && kiem_tong(q)==k && nguyen_to(w) && nguyen_to(e) && kiem_tong(w)==k && kiem_tong(e)==k){
                                                for(int v=0;v<5;v++){
                                                    for(int c=0;c<5;c++){
                                                        cout<<a[v][c]<<" ";
                                                    }
                                                    cout<<endl;         
                                            }
                                            cout<<"......................"<<endl; 
                                            }

                                          a[4][4]='3';
                                             q=(a[0][0]-'0')*10000+(a[1][1]-'0')*1000+(a[2][2]-'0')*100+(a[3][3]-'0')*10+(a[4][4]-'0');
                                             w=(a[0][4]-'0')*10000+(a[1][4]-'0')*1000+(a[2][4]-'0')*100+(a[3][4]-'0')*10+(a[4][4]-'0');
                                             e=(a[4][0]-'0')*10000+(a[4][1]-'0')*1000+(a[4][2]-'0')*100+(a[4][3]-'0')*10+(a[4][4]-'0');
                                            if(nguyen_to(q) && kiem_tong(q)==k && nguyen_to(w) && nguyen_to(e) && kiem_tong(w)==k && kiem_tong(e)==k){
                                                for(int v=0;v<5;v++){
                                                    for(int c=0;c<5;c++){
                                                        cout<<a[v][c]<<" ";
                                                    }
                                                    cout<<endl;
                                                }  
                                                cout<<"......................"<<endl;
                                            }
                                        
                                         a[4][4]='7';
                                            q=(a[0][0]-'0')*10000+(a[1][1]-'0')*1000+(a[2][2]-'0')*100+(a[3][3]-'0')*10+(a[4][4]-'0');
                                            w=(a[0][4]-'0')*10000+(a[1][4]-'0')*1000+(a[2][4]-'0')*100+(a[3][4]-'0')*10+(a[4][4]-'0');
                                            e=(a[4][0]-'0')*10000+(a[4][1]-'0')*1000+(a[4][2]-'0')*100+(a[4][3]-'0')*10+(a[4][4]-'0');
                                            if(nguyen_to(q) && kiem_tong(q)==k && nguyen_to(w) && nguyen_to(e) && kiem_tong(w)==k && kiem_tong(e)==k){
                                                for(int v=0;v<5;v++){
                                                    for(int c=0;c<5;c++){
                                                        cout<<a[v][c]<<" ";
                                                    }
                                                    cout<<endl;                                
                                            }
                                            cout<<"......................"<<endl; 
                                            }
                                        
                                        a[4][4]='9';
                                             q=(a[0][0]-'0')*10000+(a[1][1]-'0')*1000+(a[2][2]-'0')*100+(a[3][3]-'0')*10+(a[4][4]-'0');
                                             w=(a[0][4]-'0')*10000+(a[1][4]-'0')*1000+(a[2][4]-'0')*100+(a[3][4]-'0')*10+(a[4][4]-'0');
                                             e=(a[4][0]-'0')*10000+(a[4][1]-'0')*1000+(a[4][2]-'0')*100+(a[4][3]-'0')*10+(a[4][4]-'0');
                                            if(nguyen_to(q) && kiem_tong(q)==k && nguyen_to(w) && nguyen_to(e) && kiem_tong(w)==k && kiem_tong(e)==k){
                                                for(int v=0;v<5;v++){
                                                    for(int c=0;c<5;c++){
                                                        cout<<a[v][c]<<" ";
                                                    }
                                                    cout<<endl;
                                                }   
                                                 cout<<"......................"<<endl;
                                            }

                                        chay_cot3++;    // ti?p t?c l?p c�c ph?n t? c?a c?t 3

                                    }

                                    if(chay_cot3==cot3){     // n?u duy?t qua h?t c�c ph?n t? c?a c?t 3 th� kh?i t?o l?i m?ng c3
                                        //cout<<"minh";
                                        for(int y=0;y<cot3;y++){  
                                            c3[y]="";
                                        }
                                    }

                                  chay_hang3++;       // ti?p t?c duy?t qua c�c ph?n t? c?a h�ng 3

                                }

                                if(chay_hang3==hang3){   // n?u duy?t qua h?t c�c ph?n t? c?a h�ng 3 th� kh?i t?o l?i gi� tr? c?a m?ng h3
                                    for(int y=0;y<hang3;y++){
                                        h3[y]="";
                                    }
                                }

                                    chay_cot2++;     // ti?p t?c duy?t qua c�c ph?n t? c?a c?t 2
                            }

                            if(chay_cot2==cot2){    // n?u duy?t h?t c�c ph?n t? c?a c?t 2 th� kh?i t?o l?i gi� tr? c?a m?ng c2
                                for(int y=0;y<cot2;y++){  
                                    c2[y]="";
                                }
                            }

                            chay_hang2++;          // ti?p t?c duy?t qua c�c ph?n t? c?a h�ng 2

                           }
                           if(chay_hang2==hang2){    //n?u duy?t qua h?t c�c ph?n t? c?a h�ng 2 th� kh?i t?o l?i gi� tr? c?a m?ng h2
                            for(int y=0;y<hang2;y++){
                                h2[y]="";
                            }
                           }

                        chay_cot1++;              // ti?p t?c duy?t qua c�c ph?n t? c?a c?t 1
                       }
                       if(chay_cot1==cot1){       // kh?i t?o l?i gi� tr? c?a m?ng c1
                        for(int y=0;y<cot1;y++){
                            c1[y]="";
                        }
                       }

                    chayh1++;                  // ti?p t?c duy?t qua c�c ph?n t? c?a h�ng 1
                   }
                   if(chayh1==hang1){         // kh?i t?o l?i gi� tr? c?a m?ng h1
                    for(int y=0;y<hang1;y++){
                        h1[y]="";
                    }
                   }

                    chay++;                  // ti?p t?c duy?t qua c�c ph?n t? du?ng ch�o

                }
               if(chay==count){              // kh?i t?o l?i gi� tr? c?a du?ng ch�o
                 for(int y=0;y<count;y++){
                    cheo[y]="";
                }  

               }   

            }

        } 
        
    }
    return 0;
}
