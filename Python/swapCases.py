# https://www.hackerrank.com/challenges/swap-case/problem

def swap_case(s):
    for i in s:
        if((ord(i) > 64) and (ord(i) < 91)):
            print(chr(ord(i) + 32),end="")
        elif((ord(i) > 96) and (ord(i) < 123)):
            print(chr(ord(i) - 32),end="")
        else:
            print(i,end="")
    return '\n'
