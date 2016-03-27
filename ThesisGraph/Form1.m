% Make some play data:
x = [
       2 , 1;
 5 , 7;
 3 , 3;
 4 , 4;
 0 , 4;
 10 , 10;
 1 , 1;
 2 , 2;
 3 , 3;
 1 , 1;
 2 , 1;
 2 , 2;
 0 , 1;
 0 , 4;
 2 , 2;
 1 , 1;
 0 , 1;
 1 , 1;
 2 , 2;
 1 , 3;
 2 , 2;
 1 , 2;
 7 , 8;
 4 , 5;
 3 , 3;
 18 , 18;
 10 , 7;
 5 , 1;
 7 , 7;
 7 , 6;
 5 , 6;
 12 , 4;
 1 , 10;
 3 , 4;
 9 , 10;
 3 , 3;
    ]
str=['0';'1';'2';'3';'8';':';'A';'B';'C';'D';'E';'F';'H';'I';'K';'N';'O';'P';'R';'S';'T';'Y';'a';'c';'d';'e';'i';'l';'m';'n';'o';'p';'r';'s';'t';'u';]


bar(x,2,'group'), xlabel('Character'),ylabel('Frequency'),title('Sample Form 2'),grid on,axis equal
set(gca, 'XTickLabel',str, 'XTick',1:numel(str))
legend('Input Frequency','Output Frequency', 'Location','NorthWest', 'Color','r')