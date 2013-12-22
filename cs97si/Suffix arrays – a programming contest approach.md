* Task 1: hidden password (ACM 2003, abridged) 
  * zoj1729
  * 最小的rank
  * 最小表示法可解

* Problem 2: array (training camp 2004) 
  * 最小的rank
  * 最小表示法可解
  
* Problem 3: substr (training camp 2003)
  * 最少出现K次的最长子串
  * 后缀数组，two-pointer
  * 哈希，二分更好写

* Problem 4: guess (training camp 2003) 
  * 查询，求是否是子串
  * 后缀数组，二分
  * 后缀树也可解

* Problem 5: seti (ONI 2002 – abridged)
  * 查血，求子串出现次数，子串最长为64
  * 后缀数组，只sort到第6步（2^6 = 64)，二分lower_bound和upper_bound
  
* Problem 6: common subsequence (Polish Olympiad 2001 and Top Coder 2004 - abridged)
  * 求3个长串的公共子串
  * DP或KMP都是N^2
  * 后缀数组，two-pointer

* Problem 7: the longest palindrome (USACO training gate) 
  * 求最长回文子串
  * Manacher是最优解法
  * 原串S和逆串S'拼接，后缀数组，高度数组rmq，求S[i]和S'[n-i]的最大高度。记得回文长度可以为奇数和偶数
  
* Problem 8: template (Polish Olympiad of Informatics 2004, abridged) 
  * 求短模板串，模板串拼接时可重叠
  * 好题，值得一做
  * 不断枚举S[1..i]，使用堆+平衡树检查是否符合要求
  * 枚举长度，从大到小，（KMP+线段树）也可解

* Problem 9: (Baltic Olympiad of Informatics 2004)
  *  spoj REPEATS
  * 求重复次数最多的连续重复子串
  * 难题
  * 枚举长度L（复杂度是调和数），在枚举S[L*i]和S[L * (i + 1)]的匹配长度

* Problem 10: (ACM SEER 2004) 
  * 循环串求所有的循环节
  * KMP解更简单
