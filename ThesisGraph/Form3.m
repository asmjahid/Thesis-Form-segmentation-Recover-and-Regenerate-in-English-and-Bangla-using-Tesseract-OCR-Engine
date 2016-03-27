% Make some play data:
x = [
        4  , 10;
5  , 5;
2  , 2;
0  , 4;
10  , 10;
1  , 1;
2  , 2;
3  , 3;
1  , 1;
1  , 1;
1  , 1;
1  , 1;
2  , 2;
1  , 1;
2  , 2;
1  , 1;
3  , 3;
5  , 5;
2  , 2;
2  , 2;
8  , 8;
1  , 1;
6  , 6;
4  , 4;
17  , 19;
1  , 1;
6  , 6;
1  , 1;
7  , 7;
6  , 6;
2  , 8;
3  , 3;
8  , 8;
3  , 3;
9  , 10;
3  , 3;


    ]
str=['1';'2';'3';'8';':';'A';'B';'C';'D';'E';'F';'H';'I';'N';'O';'P';'R';'S';'T';'Y';'a';'b';'c';'d';'e';'f';'i';'l';'m';'n';'o';'p';'r';'s';'t';'u';]

bar(x,2,'group'), xlabel('Character'),ylabel('Frequency'),title('Sample Form 4'),grid on,axis equal
set(gca, 'XTickLabel',str, 'XTick',1:numel(str))
legend('Input Frequency','Output Frequency', 'Location','NorthWest', 'Color','r')