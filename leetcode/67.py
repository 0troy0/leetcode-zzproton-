class Solution:
    def addBinary(self, a: str, b: str) -> str:
        x, y=int(a, 2), int(b, 2)
        while y:
            x, y=x^y, (x&y)<<1
        return bin(x)[2:]

#int(str, sys) 将字符串转为sys进制的数字 >>>int('18', 16)  :24
#bin() 将整数转为二进制表示 >>>bin(23)  :0a11000  [2:]的作用是切片 将0a去除