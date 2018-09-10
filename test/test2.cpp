// 链接：https://www.nowcoder.com/questionTerminal/7f24eb7266ce4b0792ce8721d6259800?orderByHotValue=1&questionTypes=000100&page=2&onlyReference=false
// 来源：牛客网

//递归会超时，只能过40%，用dp. dp[i][j]表示用前i个值组成和为j的方案个数（相比一维的，更容易理解一些）
#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1000][1000];
int main()
{
    int n,sum;
    cin>>n>>sum;
 
    int p[1000];
    for(int i = 1 ; i <= n ; i++)
        cin>>p[i];
    for (int i = 0 ; i < n ;i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1 ; j < sum ;j++)
    {
        dp[0][j] = 0;
    }
 
    for (int i = 1 ; i <= n ;i++)
    {
        for (int j = 0 ; j<=sum ;j++)
        {
            if(p[i]<=j) dp[i][j] = dp[i-1][j]+dp[i-1][j-p[i]];
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][sum]<<endl;
    return 0;
}