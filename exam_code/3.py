def solve():
    s = input()
    nums = eval(s)
    if len(nums) < 2:
        return nums[0]
    dp = [nums[0],nums[1]]
    for i in range(2,len(nums)):
        dp.append(dp[i-2] + nums[i])
    return max(dp)

if __name__ == '__main__':
    print(solve())