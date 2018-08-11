//扩展字符串 
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv) {
	freopen("in.txt","r",stdin);
	char str[200];
	cin>>str;
	int n=strlen(str);
	char new_str[200];
	int j=0;
	for(int i=0; i<n; i++) {
		if(str[i]=='-') {
			char b=str[i-1];
			char e=str[i+1];
			if((b>='0'&&e<='9')||(b>='A'&&e<='Z')||(b>='a'&&e<='z')) {
				for(char m=b+1; m<e; m++) {
					new_str[j]=m;
					j++;
				}
			} else {
				new_str[j]=str[i];
				j++;
			}

		} else {
			new_str[j]=str[i];
			j++;
		}
	}
	new_str[j]='\0';
	cout<<new_str;
	return 0;
}
