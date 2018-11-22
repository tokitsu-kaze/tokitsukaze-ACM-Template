//sg函数
//f[m]:可改变当前状态的方式，N为方式的种类，要先从小到大sort 
//sg[]:0~n的sg函数值
//flag[m]:为x后继状态的集合

//sg表 
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

//记忆化搜索求sg表
int f[105],sg[MAX],m;
int dfs(int x)
{
	int i,j,flag[105];
	if(sg[x]!=-1) return sg[x];
	mem(flag,0);
	for(i=1;i<=m;i++)
	{
		if(x>=f[i])
		{
			dfs(x-f[i]);
			flag[sg[x-f[i]]]=1;
		}
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}

