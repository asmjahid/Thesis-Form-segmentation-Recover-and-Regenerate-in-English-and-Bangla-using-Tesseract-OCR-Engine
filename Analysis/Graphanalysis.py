#!/usr/bin/env python
# -*- coding: utf-8 -*-
import xlsxwriter
def GetData(Fname1,Fname2):
    f1=open(Fname1).read().decode('utf8')
    D=dict()
    for line in f1:
        for c in line:
            if c == ' ' or c=='\n':continue
            if c in D.keys():
                X,Y=D[c]
                D[c]=(X+1,Y)
            else:
                D[c]=(1,0)
    
    f2=open(Fname2).read().decode('utf8')
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
def GenTable(F1,F2):
    x,y,z=GetData(F1,F2)
    for i in range(0,len(x)):
        print x[i] + " & "+str(y[i]) + " & "+str(z[i])+"\\\\"
        print "\hline"

GenTable("form5.in","form5.out")
def GenXLfile(F1,F2,XlName):

    # Create a workbook and add a worksheet.
    workbook = xlsxwriter.Workbook(XlName+'.xlsx')
    worksheet = workbook.add_worksheet()

    # Some data we want to write to the worksheet.
    A,X,Y=GetData(F1,F2)

    # Start from the first cell. Rows and columns are zero indexed.
    row = col = 0
    # Iterate over the data and write it out row by row.
    for i in range(len(A)):
        worksheet.write(row, col,     A[i])
        worksheet.write(row, col + 1, X[i])
        worksheet.write(row, col + 2, Y[i])
        row += 1
    workbook.close()

#GenXLfile("Bform1.in","Bform1.out","Bform1")
#GenXLfile("Bform2.in","Bform2.out","Bform2")
#GenXLfile("Bform3.in","Bform3.out","Bform3")
#GenXLfile("Bform4.in","Bform4.out","Bform4")
#GenXLfile("Bform5.in","Bform5.out","Bform5")
