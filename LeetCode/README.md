# LeetCode Problems

I will record some valuable problems.

## Contents

### LeetCode Weekly Contest 12
Link: https://leetcode.com/contest/leetcode-weekly-contest-12
- (A). Heaters
	- Solution: 遍历 house，每个 house 最近的 heater 距离为 minL，所有 minL 的最大值。
- (B). Validate IP Address
	- Solution: 直接判断
- (C). Ones and Zeroes 
	- Solution: 动态规划。cnt[i][0] 表示第 i 个字符串字符'0'的个数，cnt[i][1] 表示第 i 个字符串字符'1'的个数。状态方程 f[k][i][j] 表示加前 k 个字符串，最多 i 个 0 和 j 个 1 的条件下最大的字符串数目。

		```c
		转移方程：
		f[k][i][j] = max(f[k][i][j], f[k-1][i - cnt[i][0]][j - cnt[j][1]] + 1);
		```
	- Note: 可以使用滚动数组优化内存：

		```c
		(i, j) = (m, n) -> (cnt[i][0], cnt[j][1]):
			f[i][j] = max(f[i][j], f[i - cnt[i][0]][j - cnt[j][1]] + 1);
		```
- (D). Encode String with Shortest Length
	- Solution: 递归枚举。根据当前的字串 s，依次从长度 1 开始枚举字符串 substr1，并且递归剩下的字符串 substr2，即 s = substr1 + substr2 。假设 substr1 的循环节为 subcycle1，循环节个数为k，更新如下：

		```c
		1). 如果 substr1 字串不存在循环节：
			ret = substr1 + encode(substr2);
		2). 如果 substr1 字串存在循环节：
			ret = to_string(k) + "[" + encode(subcycle1) + "]" + encode(substr2);
		```	
	- Note: 在递归的过程中会有很多重复的状态，用 map<string, string> 来保存状态剪枝。
