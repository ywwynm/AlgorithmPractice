# 20200616, leetcode-cn

class Solution:

  def __init__(self):
    self.results = dict()

  def numDecodings(self, s: str) -> int:
    # 26 -> B,F or Z, [2,6], [26]
    # 216 -> [2,1,6], [21,6], [2,16]
    # 2124 -> [2,1,2,4], [2,12,4], [2,1,24], [21,2,4], [21,24]
    # 71221 -> [7,1,2,2,1], [7,12,2,1], [7,12,21], [7,1,22,1], [7,1,2,21]
    if s.startswith('0'):
      return 0
    L = len(s)
    if s.endswith('0') and L >= 2:
      if int(s[-2]) > 2:
        return 0
    if L == 1:
      if s == '0':
        return 0
      return 1
    elif L == 2:
      s_int = int(s)
      if s_int > 26 or s_int % 10 == 0:
        return 1
      else:
        return 2
    else:
      s_int_2 = int(s[:2])
      if s_int_2 % 10 == 0:
        if s_int_2 >= 30:
          return 0
        key = s[2:]
        if key not in self.results:
          self.results[key] = self.numDecodings(key)
        return self.results[key]
      elif s_int_2 > 26:
        key = s[1:]
        if key not in self.results:
          self.results[key] = self.numDecodings(key)
        return self.results[key]
      else:
        key1 = s[1:]
        if key1 not in self.results:
          self.results[key1] = self.numDecodings(key1)
        key2 = s[2:]
        if key2 not in self.results:
          self.results[key2] = self.numDecodings(key2)
        return self.results[key1] + self.results[key2]


class SolutionBetter:
  def numDecodings(self, s: str) -> int:
    if s[0] == '0':
      return 0

    L = len(s)

    dp = [None] * L
    dp[0] = 1
    
    # 1223
    for i in range(1, L):
      c = int(s[i])
      if c == 0 and int(s[i-1]) not in [1,2]:
        return 0
      
      if c == 0:
        dp[i] = dp[i-2]
        if i == 1:
          dp[i] = 1
      else:
        dp[i] = dp[i-1]
        if i == 1 and int(s[:2]) <= 26:
          dp[i] = 2
        elif s[i-1] != '0' and int(s[i-1:i+1]) <= 26:
          dp[i] += dp[i-2]

    return dp[-1]


if __name__ == "__main__":
  s = SolutionBetter()
  print(s.numDecodings('30'))
  print(s.numDecodings('301'))
  print(s.numDecodings('10'))
  print(s.numDecodings('100'))
  print(s.numDecodings('101'))
  print(s.numDecodings('110'))
  print(s.numDecodings('230'))
  print(s.numDecodings('26'))
  print(s.numDecodings('216'))
  print(s.numDecodings('2124'))
  print(s.numDecodings('1221'))
  print(s.numDecodings('71221'))
  print(s.numDecodings('11221'))
