#coding=utf-8

print "Ready!:"
N = int(raw_input())

def sol(M, s):
	s = ' ' + s
	dp = [0 for i in range(len(s)+1)]
	dp[0] = 1;
	for i in range(1,len(s)):
		if s[i] == ' ':
			dp[i] = dp[i-1]
			continue
		j = i
		while True:
			if s[j] != '0':				
				l = i - j +	 1
				t = int(s[j:i+1])
			#	print "==",i,j,t
				if 1 <= t and t <= M:
					dp[i] += dp[j-1]
				if t > M:
					break
			j-=1
			if s[j] == ' ':
				break
	return dp[len(s)-1]


for

 i in range(N):
	M = int(raw_input())
	s = raw_input()
	r = sol(M, s)
	print "Case #%d: "%(i+1), r