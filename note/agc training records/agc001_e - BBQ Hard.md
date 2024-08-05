# [AGC001E] BBQ Hard

## 题面翻译

有 $n$ 个数对 $(a_i, b_i)$，求出

$$\sum_{i=1}^{n}\sum_{j=i + 1}^{n}{a_i+b_i+a_j+b_j \choose a_i+a_j}$$

答案对 $10 ^ 9 + 7$ 取模。

$2 \leq n \leq 2\cdot 10^5, 1 \leq a_i,b_i \leq2000 $

https://atcoder.jp/contests/agc001/tasks/agc001_e

## 想法

- 2024.07.28
- 想办法把 $i$ 和 $j$ 分开
- 考虑用范德蒙德卷积分开 $i$ 和 $j$ ，但第一次用不太会推
- 注意到 $a_i, b_i \leq 2000$，不过好像用不上

## 题解

### 代数做法

题目等价于求：
$$
\sum_{i=1}^{n}\sum_{j=1}^n\binom{t_i+t_j}{a_i+a_j}
$$
其中 $t_i=a_i+b_i$。

我们希望把 $i$ 与 $j$ 拆开，利用范德蒙德卷积后，显然可以交换求和次序：
$$
\begin{aligned}
\sum_{i=1}^{n}\sum_{j=1}^n\binom{t_i+t_j}{a_i+a_j} 
&=\sum_{i=1}^{n}\sum_{j=1}^n\sum_k\binom{t_i}{a_i-k}\binom{t_j}{a_j+k} \\
&=\sum_k\sum_{i=1}^{n}\sum_{j=1}^n\binom{t_i}{a_i-k}\binom{t_j}{a_j+k} \\
&=\sum_k\left(\sum_{i=1}^{n}\binom{t_i}{a_i-k}\right)\left(\sum_{j=1}^n\binom{t_j}{a_j+k}\right) \\
&=\sum_{k}F(k)F(-k)
\end{aligned}
$$
问题转为求解 $F(k)$。

然后要考虑生成函数，不太会了。

### 组合数的几何意义

- 原式变为 $\frac{1}{2}(\sum^{n}_{i=1}\sum^{n}_{j=1} {a_i + b_i + a_j + b_j \choose a_i + a_j} - \sum_{i=1}^{n}{2a_i + 2b_i \choose 2a_i})$ , 后面部分可以 $O(n)$ 求
- 考虑 $\binom{x+y}{x}$ 的几何意义，表示坐标轴从 $(0,0)$ 走到 $(x,y)$ 每次只能向右或向上的路径条数
- 那么原式可以看成从 $(0,0)$ 走到 $(a_i+a_j,b_i+b_j)$ 的方案数
- 这样还是不好求，考虑把这个矩形平移
- 平移后转化成从 $(-a_i,-b_i)$ 走到 $(a_j,b_j)$ 的方案数
- 记录每个格子作为起点的方案数，即 $dp_{-a_i,-b_i}+=1$ ，然后做dp
- $\sum^{n}_{i=1}\sum^{n}_{j=1} {a_i + b_i + a_j + b_j \choose a_i + a_j}=\sum_{i=1}^{n} dp_{a_i,b_i}$ 

## 总结

- 范德蒙德卷积能够把组合数中的 $i$ 和 $j$ 分开
- 有多个求和时，求和顺序能不能交换
- 组合数转路径计数的套路