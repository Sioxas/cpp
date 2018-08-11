/*查找关键字*/
#include <stdio.h>
#include <string.h>

void replaceQuoia(char *buf) {
	int n=strlen(buf);
	bool open=false;
	for(int i=0; i<n; i++) {
		if(buf[i]=='"') {
			open=(!open);
		} else if(open) {
			buf[i]='#';
		}
	}
}

bool isdelim(char c) {
	char delim[]=" ,();\".+-*/=<>?:#[]{}'";
	int n=strlen(delim);
	for(int i=0; i<n; i++) {
		if(delim[i]==c)return true;
	}
	return false;
}

int get_word(char *str,int pos,char *word) {
	int n=strlen(str);
	int b_pos=pos;
	int w_pos=0;
	bool open=false;
	for(; b_pos<n; b_pos++) {
		if(isdelim(str[b_pos])) {
			if(open) {
				break;
			}
		} else {
			open=true;
			word[w_pos]=str[b_pos];
			w_pos++;
		}
	}
	word[w_pos]='\0';
	return b_pos;
}

int main(int argc, char** argv) {
	freopen("in.txt","r",stdin);
	char input[300];
	char word[30];
	int pos=0;
	gets(input);
	int n=strlen(input);
	replaceQuoia(input);
	int t;
	while(pos<n) {
		t=get_word(input,pos,word);
		if(strcmp("if",word)==0||strcmp("while",word)==0||strcmp("for",word)==0){
			printf("%s %d\n",word,t-strlen(word));
		}
		pos=t;
	}
	return 0;
}
