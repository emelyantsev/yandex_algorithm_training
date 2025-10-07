
s1 = set(map(int, input().split() ))
s2 = set(map(int, input().split() ))

print(  sum( [ 1 if si in s2 else 0 for si in s1  ]  )  )