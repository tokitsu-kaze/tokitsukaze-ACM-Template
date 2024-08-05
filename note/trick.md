[TOC]

## dp

1.一个东西方案数的x次方和，可以转化成选x个这样的东西的方案数。可以这么理解：比如子序列出现次数的 2 次方和，等价于先选一个子序列，再选一个相同的子序列，这样方案数就是乘法原理成起来。 [abc330_g](https://www.luogu.com.cn/problem/AT_abc330_g) , [hdu 7438](https://acm.hdu.edu.cn/showproblem.php?pid=7438) , [P1758 [NOI2009] 管道取珠](https://www.luogu.com.cn/problem/P1758) , 

2.多个子序列的 dp 可以考虑以子序列结尾为状态 [CF1799D1](https://www.luogu.com.cn/problem/CF1799D1) , [hdu 7438](https://acm.hdu.edu.cn/showproblem.php?pid=7438) ,

3.当不关心两个维度的具体数值，只关心这两个维度的大小时，考虑作差后放入一个维度，从而优化时空复杂度（差值dp）



## 数据结构

1.对整体加时考虑用开个数组打tag，元素加入时减掉tag，删除时加上tag [hdu 7436](https://acm.hdu.edu.cn/showproblem.php?pid=7436) , [CF1638E](https://www.luogu.com.cn/problem/CF1638E) , 

2.颜色段均摊，线段树相关各种均摊分析

3.遇到删边加边维护连通性的问题，考虑线段树分治，线段树维护时间轴



## 树上问题

1.子树相关计数类问题，考虑做这样一个差分：进子树前减掉当前贡献，出子树后加上当前贡献 [P3605](https://www.luogu.com.cn/problem/P3605) , 

2.求子树节点交的个数，用dfs序转化成偏序问题 [hdu 7084](https://acm.hdu.edu.cn/showproblem.php?pid=7084) , 



## 字符串

1.查询串总长固定，那么不同种类的长度只有 $\sqrt n$ 种 [小白97 F](https://ac.nowcoder.com/acm/contest/85347/F) , 



## 图论

1.竞赛图三元环个数 $C^{3}_{n}-\sum C^{2}_{in_i}$ 其中 $in_i$ 为点 $i$ 的入度。



## 组合数学

1.范德蒙德卷积能够把组合数中的 $i$ 和 $j$ 分开

2.组合数转路径计数的套路：考虑 $\binom{x+y}{x}$ 的几何意义，表示坐标轴从 $(0,0)$ 走到 $(x,y)$ 每次只能向右或向上的路径条数  [agc001e - BBQ Hard](https://atcoder.jp/contests/agc001/tasks/agc001_e) ,



## 杂项

1.枚举中点，前后拼起来

2.遇到数据随机时需要挖掘性质 [hdu 7442](https://acm.hdu.edu.cn/showproblem.php?pid=7442) , [hdu 6797](https://acm.hdu.edu.cn/showproblem.php?pid=6797) , [hdu 6635](https://acm.hdu.edu.cn/showproblem.php?pid=6635) , 

3.1-n 排列，LIS 长度期望是 $O(\sqrt n)$

4.需要多次情况一个大数组（比如树状数组），可以记录下插入了哪些位置，清空时直接清空那些位置即可

5.绝对众数：众数且出现次数超过一半。可以考虑随机化 [abc272_g](https://www.luogu.com.cn/problem/AT_abc272_g) , 还可以考虑摩尔投票

6.中位数相关，可以考虑把小于中位数的数变成 -1，大于中位数的数变成 1  [lc 3134](https://leetcode.cn/problems/find-the-median-of-the-uniqueness-array/description/) ,

7.求前k大，考虑构造不重不漏并且最值一定进队列的方案，优先队列推一推 [P2048 [NOI2010] 超级钢琴](https://www.luogu.com.cn/problem/P2048) , [P5283 [十二省联考 2019] 异或粽子](https://www.luogu.com.cn/problem/P5283) , 

8.在某些计数取模题做逆元时，要考虑取模后的值是否可能等于0



## OI考试技巧

1.一个题会做之后，不碰键盘，想清楚后再写

2.写 subtask 需要用 namespace 框起来

3.如果暴力好写，必写暴力；再加上如果数据好造，必写对拍

4.对拍需要拍一组极限数据，用于测试是否MLE或者RE；再就是拍小数据

5.写 subtask 的好处：如果多个 subtask 有交集，可以互相对拍

6.贪心策略：开场先读完所有题，每个题都先大概想想，然后优先去写自己有把握的，好写的，拿分又多的 题/subtask 

7.保守策略：如果你会这题的 100 分做法，但感觉有很多细节容易写错，而 70 分做法是保证不会写错的，那么可以考虑放弃这 30 分（在没有时间的情况下，如果有时间，当然是都写然后对拍）



## 训练方法

1.思维训练：做 agc，把思考内容记下来，然后看题解对一下哪些没想到，最后补题写总结。

2.代码能力训练：做 cf 限时训练，比如在稳定 2 小时 4 题后，试着把时间压缩到 1.5 小时 4 题，稳定后再尝试压缩时间。

3.模拟赛训练：赛后写总结。补题不需要一定补满分，可以去问老师补到多少分。要重视模拟赛，因为模拟赛会做平时刷题时不会做的事，会考虑平时刷题时不会考虑的事。

