% Make some play data:
x = [
        3  , 3;
        5  , 7;
        3  , 3;
        2  , 2;
        0  , 4;
        10  , 10;
        1  , 1;
        1  , 1;
        3  , 3;
        1  , 1;
        2  , 1;
        2  , 2;
        1  , 2;
        0  , 2;
        1  , 1;
        1  , 1;
        2  , 2;
        3  , 3;
        3  , 3;
        2  , 2;
        9  , 9;
        5  , 5;
        3  , 3;
        18  , 18;
        10  , 8;
        2  , 1;
        6  , 6;
        8  , 7;
        6  , 6;
        3  , 3;
        11  , 11;
        5  , 5;
        10  , 10;
        1  , 1;
        1  , 1;
    ]
str=['0';'1';'2';'5';'8';':';'A';'B';'C';'D';'E';'F';'H';'I';'N';'P';'R';'S';'T';'Y';'a';'c';'d';'e';'i';'l';'m';'n';'o';'p';'r';'s';'t';'u';'v';]




bar(x,2,'group'), xlabel('Character'),ylabel('Frequency'),title('Sample Form 1'),grid on,axis equal
set(gca, 'XTickLabel',str, 'XTick',1:numel(str))
legend('Input Frequency','Output Frequency', 'Location','NorthWest', 'Color','r')