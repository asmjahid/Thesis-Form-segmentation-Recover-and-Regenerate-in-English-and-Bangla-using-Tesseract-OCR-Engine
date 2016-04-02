f=open("formBen_01.txt")
D=dict()
for l in f:
    for c in l:
        if c in D:
            X,Y=D[c]
            D[c]=(X+1,Y)
        else:
            D[c]=(1,0)

for c in s:
    print(c)
