# LeetCode Problems

I will record some valuable problems.

## Contents

### [Offer收割]编程练习赛8
Link: http://hihocoder.com/contest/offers8
- (A). 小Ho的强迫症
	- Solution: 由题意有 ``Dx mod L <= L - F``，先求 D 和 L 的 gcd, 然后判断 gcd 是否大于 F。
- (B). 拆字游戏
	- Solution: dfs 寻找八连快，注意代表点为最左上包含 1 的点。
- (C). 数组分拆
	- Solution: 动态规划。f[sum] 表示遍历前 i 个数的过程中，前缀和为 sum 的方案数，注意如果当前在第 i 个数，则仅存在一段这样的 ``j~i(0<=j<=i)`` 区间和为 0，因此可以直接用前面所有方案数之和减去当前前缀和的方案数。
- (D). 矩形计数
	- Solution: 容斥原理。总的方案数为 n*(n-1)/2*m*(m-1)/2，然后枚举黑块出现的情况，利用容斥原理加加减减。

