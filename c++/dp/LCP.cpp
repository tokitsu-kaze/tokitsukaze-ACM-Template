int lcp[MAX][MAX];
void LCP(char *s,int n) // s[1..n]
{
	int i,j;
	for(i=1;i<=n;i++) lcp[n][i]=(s[n]==s[i]);
	for(i=1;i<=n;i++) lcp[i][n]=(s[i]==s[n]);
	for(i=n-1;i;i--)
	{
		for(j=n-1;j>=i;j--)
		{
			if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
		}
	}
}
/*
lcp[i][j]: longest common prefix of s[1..i] and s[1..j] (i<j)
*/
