[TOC]

# 字符串

border，周期，循环节

性质 p是周期，q是border q=|S|-p

border 没有单调性：abab  ab是border但b不是

border 传递性：S的border的border也是S的border



## KMP

预处理每个前缀最大border（去掉本身）

势能分析



## hash

多项式hash：将字符串看做 base 进制下的数字串

base>字符集

mod>=base^2

根据生日悖论，mod最好超过检测次数的平方

自然溢出容易构造hash冲突：bzoj 3097

mod应该是质数：选合数相当于选很多小质数，

mod^2 不爆 ll

双模：不泄露模数的前提下，无法构造hash冲突，bzoj 3099 无人ac

多模冲突概率：相乘 P(mod1)*P(mod2) 

应用

快速计算子串hash

二分+hash求LCP



## AC自动机

推广border概念：广义border -> S串的前缀与T串的后缀相等

AC自动机的fail指针：对于trie中每一个点（某个字典串的前缀），它与trie中所有串的最大border。求法原理与kmp求border原理一样，遍历父节点的fail指针，所以要求所有长度小于这个点的适配指针都求好了才能求它，所以用bfs求

![image-20240426092413871](D:\打包\image-20240426092413871.png)

复杂度类似KMP的势能分析

trie图：有边直接走，没边走fail



## SAM

right/endpos集合：endpos(t)表示在字符串s中，t的所有结束位置的集合。如下图

字符串s：aababa

![img](D:\打包\48736.png)



后缀自动机构造：[后缀自动机多图详解（代码实现） - maomao9173 - 博客园 (cnblogs.com)](https://www.cnblogs.com/maomao9173/p/10447821.html)



# 数学

## 概率期望

期望线性性质：和的期望=期望的和

例题 [P1297 \[国家集训队] 单选错位](https://www.luogu.com.cn/problem/P1297)





# 数论

## gcd

- Q：如何理解 gcd(a,b)=gcd(b,a%b)？

  A：a=b\*q+r, r=a%b，设 g=gcd(a,b)，g 肯定是 b 的因数，那么 b\*q%g==0，需要让 g 为 a 的因数，所以 g 一定是 r 的因数

- Q：时间复杂度？

  A：a%b 会让 a 至少减小一半，所以复杂度是 log

## 线性筛

- Q：为什么不用写 ```j<tot``` ?

  A：如果 i 是质数，则当前质数表里肯定有 i；如果 i 是合数，i 肯定是被当前质数表中某个质数筛出来的。所以一定存在 ```i%p[j]==0``` 

## 区间筛

筛区间 [L,R] 中的质数。是埃筛变形。

[L,R] 中的合数必定至少有一个质因子是 <=sqrt(R)，所以先筛 sqrt(R) 内的质数。

然后做埃筛，枚举在区间 [L,R] 中的倍数 

## CRT

```cpp
ll CRT(int n,ll *a,ll *m)
{
	int i;
	ll p,mi,res,invmi;
	p=1;
	res=0;
	for(i=1;i<=n;i++) a[i]=(a[i]%m[i]+m[i])%m[i];
	for(i=1;i<=n;i++) p*=m[i];
	for(i=1;i<=n;i++)
	{
		mi=p/m[i];
		invmi=inv_exgcd(mi,m[i]);
		res=(res+qmul(a[i]*mi,invmi,p))%p;
    }
    return res;
}
```

- Q：为什么求 ```invmi``` 不需要判逆元是否存在？

  A：因为 m 互质，mi 是用 m 的乘积 p 除以 m[i] 得到，所以 mi 一定与 m[i] 互质

- Q：为什么 ```a[i]*mi``` 不用对 p 取模？

  A：因为第一个循环保证了 a[i] 一定是正数且一定小于 m[i] ，p 除以 m[i] 再乘上比 m[i] 小的数，结果一定小于 p

## 扩展欧拉定理（欧拉降幂公式）

$$a^b\equiv\begin{cases}a^b &b<\varphi(m)\\a^{b\bmod\varphi(m)+\varphi(m)} &b\ge\varphi(m)\end{cases}\pmod m$$

证明：不会。

# dp

## 概率dp

初始化考虑哪些状态概率为1

## 树形dp

- 子树合并类型的树上背包复杂度证明

状态形如 $f[x][j]$ 表示 $x$ 子树内选了 $j$ 个，转移形如$f[x][j+k]=∑f[x][j]∗f[y][k]$

假设树上有n个点，第二维限制为k（最多选k个）我们熟知，这样dp复杂度上界是 $n^2$ 的。因为合并大小为a,b的子树复杂度是a*b，可以看成a子树内任选一点，b子树内任选一点进行匹配，不管怎么合并任意两个点只会在其lca匹配一次，所以是 $n^2$ 的。

但是严格分析一下复杂度，可以得到更好的上界：O(nk)

首先，定义大小超过k的子树为大子树，小于k的为小子树。

一个极小的大子树一定是由若干个极大的小子树合并而成的，而且合并的过程中就会从极大的小子树变成极小的大子树。假设所有的极大的小子树的大小分别为x1,x2,x3…..xm，显然x1+x2+…+xm<=n，将这些小子树并入大子树的复杂度为k*(x1+x2+…+xm)<=nk，可以认为是每个极大的小子树被消灭掉所产生的总时间代价不超过nk

考虑一个极大的小子树（大小x<=k）内部合并上来的复杂度，由上面的分析知是x^2的
因此每个小子树内部合并的复杂度就是x1^2+x2^2+…+xm^2，xi<=k，显然当尽量多的xi取到k这个值才会更大，因为假设∑xi=n
为定值，x1>x2，如果让x1++,x2–，上面那个值会变大。这样复杂度就是n/k*k^2=nk

最后，考虑将所有的极小大子树合并成整棵树的复杂度，显然极小的大子树互不包含，因此极小的大子树个数不会超过n/k个，而每合并两个的时间开销是k^2，因此这部分复杂度是n/k*k^2=nk

综上，复杂度上界为O(nk)

link: [子树合并背包类型的dp的复杂度证明_关于子树合并背包类型的dp的复杂度-CSDN博客](https://blog.csdn.net/lyd_7_29/article/details/79854245)



