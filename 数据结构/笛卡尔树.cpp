/*
O(n)构造笛卡尔树 返回根 
性质:
1.树中的元素满足二叉搜索树性质，要求按照中序遍历得到的序列为原数组序列
2.树中节点满足堆性质，节点的key值要大于其左右子节点的key值
*/
namespace Cartesian_Tree
{
	int l[MAX],r[MAX],vis[MAX],stk[MAX];
	int build(int *a,int n)
	{
		int i,top=0;
		for(i=1;i<=n;i++) l[i]=0,r[i]=0,vis[i]=0;
		for(i=1;i<=n;i++)
		{
			int k=top;
			while(k>0&&a[stk[k-1]]>a[i]) k--;
			if(k) r[stk[k-1]]=i;
			if(k<top) l[i]=stk[k];
			stk[k++]=i;
			top=k;
		}
		for(i=1;i<=n;i++) vis[l[i]]=vis[r[i]]=1;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) return i;
		}
	}
}
