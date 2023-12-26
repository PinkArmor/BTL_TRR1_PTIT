#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; 
	getline(cin,s);
	string res="";
	for(int i=0; i<s.size(); i++){
		if(s[i]== toupper(s[i])){
			if(s[i]!= 'Z' && s[i]!='Y') s[i] += 2;
			if(s[i]== 'Z'){
				s[i] = 'B';
			}
			if(s[i]=='Y'){
				s[i] = 'A';
			}
		}
		if(s[i] == tolower(s[i])){
			if(s[i]!='a' && s[i] != 'b') s[i]-=2;
			if(s[i] == 'a'){
				s[i] = 'y';
			}
			if(s[i] == 'b'){
				s[i] = 'z';
			}
		}
	}
	cout << s;
}
