

l = []

elem = int( input())

while (  elem != 0 ) :
    l.append(elem)
    elem = int( input())

max_elem = max(l)

count = sum(1 if elem == max_elem else 0 for elem in l)

print(count)