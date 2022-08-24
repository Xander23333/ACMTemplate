
def solve(s):
    q = ''
    for c in s:
        if c in char_dic:
            q += c
        else:
            if q != '' and char_dic[q[-1]] == c:
                q = q[:-1]
            else:
                return False
    return q == ''

if __name__ == '__main__':
    chars = r'<>[]{}()'
    char_dic = {}
    for i in range(0,8,2):
        char_dic[chars[i]] = chars[i+1]

    s = input()
    if s.startswith("s = "):
        s = s[4:]
    print(solve(s))
