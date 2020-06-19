class Solution:
  def numTrees(self, n: int) -> int:
    dp = [1]*(n+2)

    if n > 1:
      for i in range(2, n+1):
        dp_i = 0
        for j in range(1, i + 1):
          dp_i += dp[j-1] * dp[i-j]
        dp[i] = dp_i

    return dp[n]


if __name__ == "__main__":
  s = Solution()
  print(s.numTrees(10))