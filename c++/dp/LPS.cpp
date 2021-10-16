//最长回文子序列
//dp[i][j] 表示s[i..j] 最长回文子序列的长度 
int dp[2222][2222];
void LPS(char *s,int n)
{
	int i,j,len;
	for(i=1;i<=n;i++) dp[i][i]=1;
	for(len=2;len<=n;len++)
	{
		for(i=1;i<=n-len+1;i++)
		{
			j=i+len-1;
			if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=max({dp[i+1][j],dp[i][j-1],dp[i+1][j-1]});
		}
	}
}
