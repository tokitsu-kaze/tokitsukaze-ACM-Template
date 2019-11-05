int nex[MAX][26];
void work(char *s,int len)
{
	mem(nex[len],0);
	for(int i=len;i;i--)
	{
		for(int j=0;j<26;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]-'a']=i;
	}
}
