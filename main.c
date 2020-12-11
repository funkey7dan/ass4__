//
// Created by asraf on 09/11/2020.
//
#include "ass4.h"
void f1();
void f2();
void f3();
void f4();
void f5();

int main() {
    printf("f1:  *************************\n");
    f1();
    printf("f2:  *************************\n");
    f2();
    printf("f3:  *************************\n");
    f3();
    printf("f4:  *************************\n");
    f4();
    printf("f5:  *************************\n");
    f5();
    return 0;
}
void f1(){
    char board [SIZE*SIZE][SIZE*SIZE];
//    char str[] ="12a345679//12a345679///12a345978/12a345879/12a385679/18a345679";

    char tBoard1[SIZE*SIZE][SIZE*SIZE] = {' ','9','8','1','5','4','6','2','3','2','1','6',' ','3','8','4',
                                          '5','7','4','5','3','2','6','7','8','9',' ','6','8','9','7','2',' ',
                                          '5','3','4','1','3','2','4','8','5','9',' ','6','5','4',' ','3','9',
                                          '6','1','8','2','9','6','1','8','7','3',' ','4','5','8','7','4','5',
                                          ' ','2','3','6','9','3',' ','5','6','4','9','7','1','8'};
    //char str[] = "/123456789/12a456789/123b6789/1234c89/12345d/12345678*//A23456789";
    char str[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679";
    createBoard(board,str);
    printBoard(board);
//    printf("*************************\n");
//    printBoard(tBoard1);
}
void f4(){
    char board [SIZE*SIZE][SIZE*SIZE];
    char str[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679";
    char board2 [SIZE*SIZE][SIZE*SIZE];
    char str1[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345678";
    createBoard(board,str);
    printBoard(board);
   printf("*************************\n");
    createBoard(board2,str1);
    printBoard(board2);
    printf("%d\n",isSameBoard(board,board2));
}
void f5(){
    char board [SIZE*SIZE][SIZE*SIZE];
    //char str[] = "95a843672/4386271a9/276a95834/195384726/a27519348/843762591/762951483/384276915/519438267";
    //char str[] = "827154396/965327148/341689752/593468271/472513689/618972435/786235914/154796823/239841567";
    char str[] = "95a843672/4386271a9/276a95834/195384726/a27519348/843762591/762951483/384276915/519438267";
    createBoard(board,str);
    completeBoard(board);
    printf("%d\n",testBoard(board));
    printBoard(board);

}


void f3(){
    char board [SIZE*SIZE][SIZE*SIZE];
    char str[] = "95a843672/438627159/276195834/195384726/627519348/843762591/762951483/384276915/519438267";
    createBoard(board,str);
    printBoard(board);
    printf("%d\n",testBoard(board));
}


void f2(){
    char board [SIZE*SIZE][SIZE*SIZE];
    char str[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679";
    createBoard(board,str);
    char str1[]="replaceAll,1,@";
    makeMove(board,str1);
    printBoard(board);
    printf("**********************************\n");
    char str2[]="change,0,1,@";
    makeMove(board,str2);
    printBoard(board);
    printf("**********************************\n");
    char str3[]="add,0,2,@";
    makeMove(board,str3);
    printBoard(board);
    printf("**********************************\n");
    char str4[]="delete,20,1";
    makeMove(board,str4);
    printBoard(board);


}

