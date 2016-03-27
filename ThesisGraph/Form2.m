% Make some play data:
x = [
        2  , 1;
 5  , 7;
 3 , 3;
 2  , 2; 
 2 , 2;
 0 , 4;
 10 , 10;
 1 , 1;
 4 , 4;
 1 , 1;
 2 , 1;
 1 , 1;
 1 , 2;
 0 , 2;
 2 , 2;
 0 , 1;
 1 , 1;
 2 , 2;
 5 , 5;
 2 , 2;
 1 , 1;
 0 , 2;
 1 , 2;
 7 , 8;
 6 , 6;
 4 , 4;
 21 , 21;
 9 , 7;
 4 , 1;
 7 , 7;
 7 , 7;
 8 , 8;
 3 , 3;
 9 , 9;
 5 , 5;
 9 , 9;
 1 , 1;
 1 , 1;

    ]
str=['0';'1';'2';'4';'6';'8';':';'B';'C';'D';'E';'F';'H';'I';'N';'O';'P';'R';'S';'T';'U';'V';'Y';'a';'c';'d';'e';'i';'l';'m';'n';'o';'p';'r';'s';'t';'u';'y';]

bar(x,2,'group'), xlabel('Character'),ylabel('Frequency'),title('Sample Form 3'),grid on,axis equal
set(gca, 'XTickLabel',str, 'XTick',1:numel(str))
legend('Input Frequency','Output Frequency', 'Location','NorthWest', 'Color','r')