#include<cstdio>

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%(m+1))
            printf("A\n");
        else
            printf("B\n");
    }

    return 0;
}