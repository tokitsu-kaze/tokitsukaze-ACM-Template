int f[111],sg[MAX];
void SG(int n,int m)
{
	int i,j,flag[111];
	mem(sg,0);
	for(i=1;i<=n;i++)
	{
		mem(flag,0);
		for(j=0;f[j]<=i&&j<m;j++)
		{
			flag[sg[i-f[j]]]=1;
		}
		for(j=0;;j++)
		{
			if(!flag[j])
			{
				sg[i]=j;
				break;
			}
		}
	}
}