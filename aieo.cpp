#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>> t;
	while(t--){
		int a,b;
		double a1=0,b1=0;
		double c,d;
		cin >> a>>b>>c>>d;
		if(a>=3 && a<=4){
			a1 += 2.5;
		}
		else if(5<=a&&a<=6){
			a1 += 3.5;
		}
		else if(7<=a&&a<=9){
			a1 += 3.5;
		}
		else if(10<=a&&a<=12){
			a1 += 4.0;
		}
		else if(13<=a&&a<=15){
			a1 += 4.5;
		}
		else if(16<=a&&a<=19){
			a1 += 5.0;
		}
		else if(20<=a&&a<=22){
			a1 += 5.5;
		}
		else if(23<=a&&a<=26){
			a1 += 6.0;
		}
	    else if(27<=a&&a<=29){
			a1 += 6.5;
		}
		else if(30<=a&&a<=32){
			a1 += 7.0;
		}
		else if(33<=a&&a<=34){
			a1 += 7.5;
		}
		else if(35<=a&&a<=36){
			a1 += 8.0;
		}
		else if(37<=a&&a<=38){
			a1 += 8.5;
		}
		else if(39<=a&&a<=40){
			a1 += 9.0;
		}
        if(b>=3 && b<=4){
			b1 += 2.5;
		}
		else if(5<=b&&b<=6){
			b1 += 3.5;
		}
		else if(7<=b&&b<=9){
			b1 += 3.5;
		}
		else if(10<=b&&b<=12){
			b1 += 4.0;
		}
		else if(13<=b&&b<=15){
			b1 += 4.5;
		}
		else if(16<=b&&b<=19){
			b1 += 5.0;
		}
		else if(20<=b&&b<=22){
			b1 += 5.5;
		}
		else if(23<=b&&b<=26){
			b1 += 6.0;
		}
	    else if(27<=b&&b<=29){
			b1 += 6.5;
		}
		else if(30<=b&&b<=32){
			b1 += 7.0;
		}
		else if(33<=b&&b<=34){
			b1 += 7.5;
		}
		else if(35<=b&&b<=36){
			b1 += 8.0;
		}
		else if(37<=b&&b<=38){
			b1 += 8.5;
		}
		else if(39<=b&&b<=40){
			b1 += 9.0;
		}
        double tb = (a1+b1+c+d)/4;
        double rtb = round(tb*2.0) /2.0;
        cout << fixed<<setprecision(1)<<rtb<<endl;
	}
}
