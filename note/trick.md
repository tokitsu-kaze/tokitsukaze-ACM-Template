[TOC]

## dp

1.一个东西方案数的x次方和，可以转化成选x个这样的东西的方案数 [abc330_g](https://www.luogu.com.cn/problem/AT_abc330_g) , [hdu 7438](https://acm.hdu.edu.cn/showproblem.php?pid=7438) , [P1758 [NOI2009] 管道取珠](https://www.luogu.com.cn/problem/P1758) , 

2.多个子序列可以考虑以子序列结尾为状态 [CF1799D1](https://www.luogu.com.cn/problem/CF1799D1) , [hdu 7438](https://acm.hdu.edu.cn/showproblem.php?pid=7438) ,



## 数据结构

1.对整体加时考虑用开个数组打tag，元素加入时减掉tag，删除时加上tag [hdu 7436](https://acm.hdu.edu.cn/showproblem.php?pid=7436) , [CF1638E](https://www.luogu.com.cn/problem/CF1638E) , 

2.颜色段均摊，线段树相关各种均摊分析

3.遇到删边加边维护连通性的问题，考虑线段树分治，线段树维护时间轴



## 树上问题

1.子树相关计数类问题，考虑做这样一个差分：进子树前减掉当前贡献，出子树后加上当前贡献 [P3605](https://www.luogu.com.cn/problem/P3605) , 

2.求子树节点交的个数，用dfs序转化成偏序问题 [hdu 7084](https://acm.hdu.edu.cn/showproblem.php?pid=7084) , 



## 图论

1.竞赛图三元环个数 $C^{3}_{n}-\sum C^{2}_{in_i}$



## 杂项

1.枚举中点，前后拼起来

2.遇到数据随机时需要挖掘性质 [hdu 7442](https://acm.hdu.edu.cn/showproblem.php?pid=7442) , [hdu 6797](https://acm.hdu.edu.cn/showproblem.php?pid=6797) , [hdu 6635](https://acm.hdu.edu.cn/showproblem.php?pid=6635) , 

3.1-n排列，LIS长度期望是 $O(\sqrt n)$

4.需要多次情况一个大数组（比如树状数组），可以记录下插入了哪些位置，清空时直接清空那些位置即可

5.

