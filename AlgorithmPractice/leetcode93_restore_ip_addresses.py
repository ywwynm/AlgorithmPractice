class Solution:
  def restoreIpAddresses(self, s: str):

    ret = []

    def is_valid_ip_part(s_: str):
      return 0 <= int(s_) <= 255 and len(s_) == len(str(int(s_)))

    def restore_part(s_: str, seg_count: int, ip: str):
      if seg_count == 1:
        if is_valid_ip_part(s_):
          ret.append(ip + '.' + s_)
      else:
        for n in range(1, 4):
          ip_ = ip
          if len(s_) > n and is_valid_ip_part(s_[:n]):
            if seg_count == 4:
              ip_ += s_[:n]
            else:
              ip_ += '.' + s_[:n]
            if len(s_) > n:
              restore_part(s_[n:], seg_count - 1, ip_)
        
    restore_part(s, 4, "")

    return ret


if __name__ == "__main__":
  s = Solution()
  print(s.restoreIpAddresses("01111"))