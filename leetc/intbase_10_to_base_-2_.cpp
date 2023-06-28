#include<iostream>
#include<string>
using namespace std;

int main(){
	if(n==0){return 0;}
	int n = 1652421;
	string a = string(30,'0');
	cout<<a<<endl;
	int i = 29;
	for(;n!=0;i--){
		if(n%(-2)<0){a[i]+=-n%(-2);n=1+n/(-2);}
		else{a[i]+=n%(-2);n/=-2;}
		cout<<n<<endl;
	}
    cout<<a<<endl;
    return 0;
}
