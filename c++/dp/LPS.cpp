int dp[105][105];
void LPS(char *s,int n) // s[1..n]
{
	int i,len,l,r;
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=1;
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1]+2;
			else dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
		}
	}
}
