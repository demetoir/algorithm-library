w,h = map(int,raw_input().split())

if w==1 and h==1:
    print "YES"
    print 1,1
    exit()
if w==1 or h==1:
    print "NO"
    exit()

print "YES"
print w,1
print 1,h
#x,y


for x in range(1,w+1):
    for y in range(1,h+1):
        if (x,y) == (w,1) or (x,y) == (1,h):
            continue
        print x,y

