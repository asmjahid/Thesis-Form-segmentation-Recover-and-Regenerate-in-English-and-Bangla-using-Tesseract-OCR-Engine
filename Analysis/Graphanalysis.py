from Bar import *
def GetData(Fname1,Fname2):
    f1=open(Fname1)
    D=dict()
    for line in f1:
        for c in line:
            if c == ' ' or c=='\n':continue
            if c in D.keys():
                X,Y=D[c]
                D[c]=(X+1,Y)
            else:
                D[c]=(1,0)
    
    f2=open(Fname2)
    for line in f2:
        for c in line:
            if c==' ' or c=='\n':continue
            if c in D.keys():
                X,Y=D[c]
                D[c]=(X,Y+1)
            else:
                D[c]=(0,1)
    F1Value=list()
    F2Value=list()
    X=D.keys()
    for x in X:
        v1,v2=D[x]
        F1Value.append(v1)
        F2Value.append(v2)
    return (X,F1Value,F2Value)

#BarchartPlot(N,X,Y,xticks,title,xlabel,ylabel,xlegend,ylegend)

def DrawFig(F1,F2):
    x,y,z=GetData(F1,F2)
    BarchartPlot(len(x),y,z,x,"Input Output Frequency","","Frequency","Input","Output")
