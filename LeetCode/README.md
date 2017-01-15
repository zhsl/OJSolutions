# LeetCode Problems

I will record some valuable problems.

## Contents

### LeetCode Weekly Contest 15
Link: https://leetcode.com/contest/leetcode-weekly-contest-15/
- (A). Max Consecutive Ones
	- Solution: 循环遍历计数
- (B). Max Consecutive Ones II
	- Solution: 先预处理，对于每个数，找到左右最远的1, 然后相减求最大值即可。
- (C). Zuma Game
	- Solution: 搜索＋贪心。对于 hand 中的每个字符 x，每次插入 board 的时候，肯定优先插入与 x 相同的位置然后搜索即可，注意插入完之后要删除字符串。

### LeetCode Weekly Contest 14
Link: https://leetcode.com/contest/leetcode-weekly-contest-14
- (A). Number Complement
	- Solution: Easy Problem
- (B). Magical String
	- Solution: 直接循环即可
- (C). License Key Formatting
	- Solution: 遍历判断一下
- (D). Sliding Window Median
	- Solution: 维护两个堆，一个大顶堆，一个小顶堆。对于一个区间的数列，一半放在小顶堆，另一半放在大顶堆上，保证小顶堆的最小值大于大顶堆的最大值。然后动态维护这两个堆，堆顶元素即为中位数。

### LeetCode Weekly Contest 13
Link: https://leetcode.com/contest/leetcode-weekly-contest-13
- (A). Hamming Distance
	- Solution: 循环判断计数即可
- (B). Total Hamming Distance
	- Solution: 对于每一位 bit，在数组中，求 0 的个数以及 1 的个数，则答案为 ∑ (cnt_0 * cnt_1)。
- (C). Matchsticks to Square
	- Solution: 数据很小，直接暴力 dfs 枚举即可。
	- Note: 需要先逆序排序剪枝优化。
- (D). Concatenated Words
	- Solution: 首先对字符串序列按字典序排序，然后对于每个字符串 dfs 查找。对于当前字符串，从头开始查找每个子串看是否存在序列中，这里用二分查找，如果存在，继续查找下一个子串。
	- Note: 也可以用字典树来查找，或者直接用 set 容器。

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
		1). 如果 substr1 子串不存在循环节：
			ret = substr1 + encode(substr2);
		2). 如果 substr1 子串存在循环节：
			ret = to_string(k) + "[" + encode(subcycle1) + "]" + encode(substr2);
		```	
	- Note: 在递归的过程中会有很多重复的状态，用 map<string, string> 来保存状态剪枝。
