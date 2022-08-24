class Solution:
    def chipGame(self, nums: List[int], kind: int) -> float:
        nums = [0] * (kind-len(nums)) + sorted(nums)
        @cache
        def getRes(status, tmp):
            if tmp == 0: return 0
            status = list(status)
            cnt = 0
            ans = 0
            i = 0
            while i < kind:
                # 相当于用 idx 找这个数出现的最后位置
                idx = bisect.bisect_right(status, status[i]) - 1
                status[idx] += 1
                for x, y in zip(status, nums):
                    if x > y:
                        break
                else:
                    cnt += idx - i + 1 # 分母 * kind 的累加
                    ans += getRes(tuple(status), tmp-1) * (idx - i + 1) # 概率为 (idx-i+1)/kind
                status[idx] -= 1
                i = idx + 1
            return (ans + kind) / cnt
        return getRes(tuple([0] * kind), sum(nums))
    
    