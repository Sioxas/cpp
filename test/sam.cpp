#include<iostream>
using namespace std;
struct SAM {
    SAM *pre,*son[26];
    int len,g;
} que[N],*root,*tail;
int tot;
void add(int c,int l) {
    SAM *p=tail,*np=&que[tot++];
    np->len=l;
    tail=np;
    while(p&&p->son[c]==NULL) p->son[c]=np,p=p->pre;
    if(p==NULL) np->pre=root;
    else {
        SAM *q=p->son[c];
        if(p->len+1==q->len) np->pre=q;
        else {
            SAM *nq=&que[tot++];
            *nq=*q;
            nq->len=p->len+1;
            np->pre=q->pre=nq;
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;
        }
    }
}
char a[N/2],b[N/2];
int lcs(char a[],char b[]) {
    memset(que,0,sizeof(que));
    tot=0;
    root=tail=&que[tot++];
    for(int i=0; a[i]; i++) add(a[i]-'a',i+1);
    SAM *p=root;
    int ans=0;
    for(int i=0,l=0; b[i]; i++,ans=max(ans,l)) {
        int c=b[i]-'a';
        if(p->son[c]) p=p->son[c],l++;
        else {
            while(p&&p->son[c]==NULL) p=p->pre;
            if(p==NULL) p=root,l=0;
            else l=p->len+1,p=p->son[c];
        }
    }
    return ans;
}