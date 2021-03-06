# LeetCode Problems

I will record some valuable problems.

## Contents

### LeetCode Weekly Contest 24
Link: https://leetcode.com/contest/leetcode-weekly-contest-24/
- (A). Diameter of Binary Tree
	- Solution: dfs 求解。
- (B). Convert BST to Greater Tree
	- Solution: 平衡二叉树，优先遍历右子树即可。
- (C). 01 Matrix
	- Solution: 多源路径的 BFS 求最短路，对于每个源点入队列，然后求最短路即可。
- (D). Output Contest Matches
	- Solution: 排序求解合并即可。

### LeetCode Weekly Contest 23
Link: https://leetcode.com/contest/leetcode-weekly-contest-23/
- (A). Reverse String II
	- Solution: 用 reverse 处理一下。
- (B). Minimum Time Difference
	- Solution: 转化成分钟，然后排序，求相邻时间的差值最小。
- (C). Construct Binary Tree from String
	- Solution: dfs 处理。
- (D). Word Abbreviation
	- Solution: 扫描 dict，对每个字符串压缩，对于压缩编码相同的所用字符串，进行排序，相邻两个字符串的最长公共前缀就是压缩后的前缀。这里求前缀也可以用字典树处理。
	- Node: 题目没有说得很清楚，这里解释一下：给 n 个字符串，对每个字符串进行压缩，压缩的规则：1. 只保留第一个字符和最后一个字符，中间的字符串压缩为其长度，用数字表示。2. 根据第一条规则压缩后，会有些字符串的压缩编码相同。对于这些字符串，要把第一个字母变为更长的前缀，使得压缩后，每个字符串的前缀都不相同。

### LeetCode Weekly Contest 22
Link: https://leetcode.com/contest/leetcode-weekly-contest-22/
- (A). K-diff Pairs in an Array
	- Solution: 直接用 set 处理一下。
- (B). Lonely Pixel I
	- Solution: 数组计数，然后暴力枚举。
- (C). Lonely Pixel II
	- Solution: 数组技术，然后暴力枚举，需要预处理一下。
- (D). Freedom Trail
	- Solution: 可以用搜索，也可以DP。f[i][j] 表示 ring 中的第 i 个字符在 12 点钟方向且已匹配 key 中 j 个字符所需要的最少的步数。``f[i][j] = Min(f[i][j], f[k][j-1] + min_step, k=0~n)``

### LeetCode Weekly Contest 21
Link: https://leetcode.com/contest/leetcode-weekly-contest-21/
- (A). Minimum Absolute Difference in BST
	- Solution: 遍历 BST，保存节点值，然后排序求最小。或者中序遍历 BST 直接求最小。
- (B). Continuous Subarray Sum
	- Solution: 求前缀和，前缀和单调递增，遍历前缀和，对于每个区间值，二分查找。还有 O(n) 的做法，求前缀和，对前缀和除 k 取余，遍历前缀和，看前面是否出现过相同的余数即可。
- (C). Longest Word in Dictionary through Deleting
	- Solution: 对于每个 dictionary 判断一下，符合要求的保存下来，然后按照规则排序。
- (D). Minesweeper
	- Solution: 按照规则 dfs 遍历。

### LeetCode Weekly Contest 20
Link: https://leetcode.com/contest/leetcode-weekly-contest-20/
- (A). Detect Capital
	- Solution: 直接判断。
- (B). Beautiful Arrangement
	- Solution: 递归枚举，或者可以用位运算枚举。
- (C). Contiguous Array
	- Solution: 把 0 修改为 -1, 然后求数组的前缀和。遍历前缀和，对于当前和 s，求前面出现过的最远的ｓ，两个位置相减，即为当前最长子串，最后取所有字串长度的最大值。
- (D). Super Washing Machines
	- Solution: 很有思维的一道题，目的是要把所有数字变成相同的数字(value)。对于每个位置上的数字，每次只能同时由旁边的数字 +-1 得到一个新的数字，但是这里 +-1 可以在数字间传递。从前往后遍历数组，对于当前数字 machine[i]分两种情况讨论：

		```c
		cnt[i] 表示第 i 个数需要移动的次数。
		1). machine[i] < value:
			当前位置的数需要向右边的数字借 1，说明需要由右边的数字移动 machine[i] - vaue 次.
			cnt[i+1] = value - machine[i];
			machine[i+1] -= value; - machine[i];
		2). machine[i] > value:
			当前位置的数多出了 1，需要把多出的 1 往右移动。
			cnt[i] += machine[i] - value;
			machine[i+1] += machine[i] - value;
		```	
	最后求 cnt 的最大值。

### LeetCode Weekly Contest 19
Link: https://leetcode.com/contest/leetcode-weekly-contest-19/
- (A). Base 7
	- Solution: 进制转化，直接循环取余。
- (B). Find Bottom Left Tree Value
	- Solution: 递归查找即可。
- (C). Find Largest Value in Each Tree Row
	- Solution: 递归查找，全局记录最优值。
- (D). Reverse Pairs
	- Solution: 对于数组中的每个数，查找前面比它的数的个数，然后求和。遍历数组，对于前面的树，用平衡树保存，然后就可以在 O(log n) 的时间内查找比当前数大的个数。或者离散化然后用线段树 or 树状数组处理。代码最短的写法就是用 vector 维护单调数列，然后 lower_bound() 直接查找。
	- Note: ``nums[i] > 2*nums[j]``可能会溢出，改为``(nums[i]+1)/2 > nums[j]``。

### LeetCode Weekly Contest 18B
Link: https://leetcode.com/contest/leetcode-weekly-contest-18b/
- (A). Next Greater Element I
	- Solution: 暴力枚举查找。
- (B). Relative Ranks
	- Solution: 排序记录位置。
- (C). Next Greater Element II
	- Solution: 单调栈维护。
- (D). Diagonal Traverse
	- Solution: 遍历每个斜串的起始位置，奇偶处理。

### LeetCode Weekly Contest 18A
Link: https://leetcode.com/contest/leetcode-weekly-contest-18a/
- (A). Keyboard Row
	- Solution: 字符串映射处理。
- (B). Most Frequent Subtree Sum
	- Solution: dfs 递归树，求子树和，然后更新最优值。
- (C). IPO
	- Solution: 优先队列搞之。

### LeetCode Weekly Contest 17
Link: https://leetcode.com/contest/leetcode-weekly-contest-17/
- (A). Find Mode in Binary Search Tree
	- Solution: dfs 中序遍历二叉树，然后判断最优值。
- (B). Teemo Attacking
	- Solution: 遍历数组，求区间覆盖长度。
- (C). ``i'cant touch the problem``

### LeetCode Weekly Contest 16B
Link: https://leetcode.com/contest/leetcode-weekly-contest-16b/
- (A). Construct the Rectangle
	- Solution: 直接枚举判断。
- (B). Predict the Winner
	- Solution: dfs 构造博弈树。
- (C). Smallest Good Base
	- Solution: 二分枚举。

### LeetCode Weekly Contest 16A
Link: https://leetcode.com/contest/leetcode-weekly-contest-16a/
- (A). ``i'cant touch the problem``
- (B). Target Sum
	- Solution: dfs 枚举。
- (C). Increasing Subsequences
	- Solution: dfs 枚举。

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
