const int K=26;
int nex[MAX][K];
void work(char *s,int len)
{
	for(int i=0;i<K;i++) nex[len][i]=len+1;
	for(int i=len;i;i--)
	{
		for(int j=0;j<26;j++)
		{
			nex[i-1][j]=nex[i][j];
		}
		nex[i-1][s[i]-'a']=i;
	}
}
