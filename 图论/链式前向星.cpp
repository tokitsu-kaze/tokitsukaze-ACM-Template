//链式前向星 
//注意 这里MAX指的是边数 双向边要*2 
int head[MAX],tot;
struct node
{
	int to,v,next;
}mp[MAX<<1];
void init()
{
	mem(head,-1);
	tot=0;
}
void add(int x,int y,int v)
{  
	mp[tot].v=v;  
	mp[tot].to=y;
	mp[tot].next=head[x];  
	head[x]=tot++;
}

