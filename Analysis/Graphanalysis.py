from Bar import *
import xlsxwriter
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
def GenTable(F1,F2):
    x,y,z=GetData(F1,F2)
    for i in range(0,len(x)):
        print str(x[i]) + " & "+str(y[i]) + " & "+str(z[i])+"\\\\"
        print "\hline"
def DrawFig(F1,F2):
    x,y,z=GetData(F1,F2)
    BarchartPlot(len(x),y,z,x,"Input Output Frequency","","Frequency","Input","Output")

#GenTable("form1.in","form2.out")
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
#GenXLfile("form1.in","form1.out","form1")
#GenXLfile("form2.in","form2.out","form2")
#GenXLfile("form3.in","form3.out","form3")
#GenXLfile("form4.in","form4.out","form4")
#GenXLfile("form5.in","form5.out","form5")
