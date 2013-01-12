**Algebra 代数**
================

----------

# Sums of Consecutive Powers 连续整数幂求和 #

- 连续平凡和有几种有趣的证明
- 利用x^(n+1)-x^n必然可以推导，不过很麻烦 
- 利用Bernoulli Polynomia
	- https://math.rutgers.edu/~erowland/sumsofpowers.html 

# Fast Exponentiation 快速取幂 #

* 递归
    
    double pow(double a, int n) {
	    if(n == 0) return 1;
	    if(n == 1) return a;
	    double t = pow(a, n/2);
	    return t * t * pow(a, n%2);
    }

* 迭代

`
double pow(double a, int n) {
	double ret = 1;
	while(n) {
		if(n%2 == 1) ret *= a;
		a *= a; n /= 2;
	}
	return ret;
}
`
# Linear Algebra 线性代数 #
* Gaussian Elimination 高斯消元法
	* 解线性方程组
	* 矩阵转置
	* 矩阵的秩
	* determinant of a matrix，求行列式
* Cramer’s Rule 克莱姆法则 



**Number Theory 数论**
=====================
----------


# Greatest Common Divisor (GCD) 公约数 #
 辗转相除法，O(log(a+b))

' 
int gcd(int a, int b) {
	while(b){int r = a % b; a = b; b = r;}
	return a;
}
'

# Congruence & Modulo Operation 全等和求模 #

# Extended Euclidean Algorithm 扩展欧几里德算法 #

# Chinese Remainder Theorem 中国剩余定理 #


**Combinatorics 组合**
==================

# Binomial Coefficients 二项式系数 # 

# Fibonacci sequence  斐波纳契数列 #
 * O(log(n))算法


**(non-computational) Geometry 几何**
=================================

# 注意事项 #
 * 使用double
 * 避免除法
 * 精度控制； if(x == 0) 要写成if(abs(x) < EPS)
 * pi用acos(-1)计算出来
# 2D Vector Operations 二维向量操作 #
 * 逆时针旋转，矩阵法的 
 * 通过看每个原始向量的对新向量的贡献可以推导
 	* 注意单位统一：弧度，角度

# Line-Line Intersection 两线交点 #
 * 用矩阵法的
 * 说白了就是解线性方程组
	* 主意两线重合的情况

# Circumcircle of a Triangle 三角形的外接圆#
 * 求 二等分线，再求交点
 * 正弦定理 R=a/sin(A)=b/sin(B)=c/sin(C)

# Area of a Triangle 三角形面积 # 
 * 海伦公式 S^2 = p(p-a)(p-b)(p-c), p = (a+b+c)/2
 * 用叉积；2*area  = |(B-A)*(C-A)|
 * 画出坐标后，用正方型减去3个三角形可以推导
	* (x1*y1)*(x2,y2) = x1*y2-x2*y1
 * 右手螺旋法则

# Area of a Simple Polygon 简单凸包面积 #
 * 叉积的和
 
Emphasis on “how to compute” 重点在于“如何计算”
=============================================