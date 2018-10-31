#include<iostream>
#include<string>
using namespace std;

int main(){
	string a;
	string b;
	
	cin>>a;
	cin>>b;
	int aSize = a.size();
	int bSize = b.size();
	int cSize = a.size()+b.size();
	int aa[aSize];
	int bb[bSize];
	int result[cSize];
	
	for(int i = 0 ; i < aSize ; i++){
		aa[i] = 0;
	}
	for(int i = 0 ; i < bSize ; i++){
		bb[i] = 0;
	}
	for(int i = 0 ; i < cSize ; i++){
		result[i] = 0;
	}
	for(int i = 0;i<aSize;i++){
		aa[i] = a[i] - '0';
	}
	for(int i = 0;i<bSize;i++){
		bb[i] = b[i] - '0';
	}
	
	for(int i = 0;i<aSize;i++){
		for(int j = 0;j<bSize;j++){
			result[cSize-i-j-2] = result[cSize-i-j-2] + aa[i]*bb[j];
		}
	}
	
	for(int i = 0;i<cSize;i++){
		int temp1 = result[i]%10;
		int temp2 = result[i]/10;
		result[i+1] = result[i+1] + temp2;
		result[i] = temp1;
	}
	
	int first = 1;
	for(int i = cSize-1;i>=0;i--){
		if(result[i] == 0 && first){
			first = 0;
		}else{
	
		cout<<result[i];
		}
	}
}
