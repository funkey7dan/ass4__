//
// Created by funke on 11/30/2020.
//
/******************
* Daniel Bronfman
* 315901173
* 01
* ass4.c
******************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MOVESIZE 16
#define BOARDSIZE (SIZE*SIZE*SIZE*SIZE+SIZE*SIZE)
#define RPLCLEN 14
#define CHGLEN 12
#define ADDLEN 9
#define DLTLEN 10
char boxArr[SIZE * SIZE][SIZE * SIZE];
int charExist(char board[][SIZE * SIZE], char toFind);
void replaceAll(char board[][SIZE * SIZE], char toReplace, char replaceWith);
int isStrLgl(char str[]);
int isLglMove(char input);
int countSigns(char str[], char sign);
void checkLoneSlashes(char str[]);
int countConvertibles(char token[], int len);
void changeChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char replaceWith);
void deleteChar(char board[][SIZE * SIZE], char locationRow, char locationCol);
int replaceLetters(char str[], int len, int freeSlots);
void moveAllRight(char str[], int len, int index, int num);
void initArr(char str[], int len);
void addSpaces(char str[], int index, int num);
void myCreateBoard(char board[][SIZE * SIZE], char str[], char tokenCopy[]);
int isSudoku(char board[][SIZE * SIZE]);
int findDups(char box[][SIZE * SIZE]);
int findSign(char toFind, int index);
int checkRowSpaces(char board[][SIZE * SIZE]);
int checkColSpaces(char board[][SIZE * SIZE]);
void squaresToArr(char box[][SIZE * SIZE], char board[][SIZE * SIZE]);
void boxify(char board[][SIZE * SIZE]);

/*******************
 * Function Name: addSpaces
 *	Input:char str[]-the string where we add the spaces, int index - where to put the spaces, int num-number of
 *	spaces to add
 *	Output:None
 *	Function Operation: add spaces to a string starting from a given index
*******************/
void addSpaces(char str[], int index, int num)
{

    for (int i = 0; i < num; i++)
    {
        str[ index + i ] = ' ';
    }
}

/*******************
 * Function Name: initArr
 *	Input:char str[]-the array to fill, int len-length of the array
 *	Output:None
 *	Function Operation: fills array with spaces
*******************/
void initArr(char str[], int len)
{

    for (int i = 0; i < len; i++)
    {
        str[ i ] = ' ';
    }
}

/*******************
 * Function Name: countConvertibles
 *	Input: char token[] - the string we search in, int len -length of token
 *	Output: int total - the total numver of convertible chars we found
 *	Function Operation: find and count small letters which need to be replaced by spaces
*******************/
int countConvertibles(char token[], int len)
{

    int total = 0;
    for (int i = 0; i < len; i++)
    {
        switch (SIZE)
        {
            case 1:
            {
                {
                    if(token[ i ] == 'a')
                    {
                        total += 0;
                    }
                }
                break;
            }
            case 2:
            {
                {
                    if(token[ i ] == 'a')
                    {
                        total += 0;
                    }
                    if(token[ i ] == 'b')
                    {
                        total += 1;
                    }
                    if(token[ i ] == 'c')
                    {
                        total += 2;
                    }
                    if(token[ i ] == 'd')
                    {
                        total += 3;
                    }
                }
                break;
            }
            case 3:
            {
                {
                    if(token[ i ] == 'a')
                    {
                        total += 0;
                    }
                    if(token[ i ] == 'b')
                    {
                        total += 1;
                    }
                    if(token[ i ] == 'c')
                    {
                        total += 2;
                    }
                    if(token[ i ] == 'd')
                    {
                        total += 3;
                    }
                    if(token[ i ] == 'e')// 5 spaces
                    {
                        total += 4;
                    }
                    if(token[ i ] == 'f')//6 spaces
                    {
                        total += 5;
                    }
                    if(token[ i ] == 'g')//7 spaces
                    {
                        total += 6;
                    }
                    if(token[ i ] == 'h')//8 spaces
                    {
                        total += 7;
                    }
                    if(token[ i ] == 'i')//9 spaces
                    {
                        total += 8;
                    }
                }
                break;
            }
        }
    }
    return total;
}

/*******************
 * Function Name: moveAllRight
 *	Input:char str[] - the string in which we move the chars, int len - length of str,
 *	int index - the place in the string we move right, int num - number of places we move the chars
 *	Output:None
 *	Function Operation: move all the chars starting from the index to the right
*******************/
void moveAllRight(char str[], int len, int index, int num)
{

    for (int i = 0; i < num; i++)
    {
        for (int j = (len - 1 + i); j > index; j--)//we move the whole string to the right
        {
            str[ j + 1 ] = str[ j ];
            str[ j ] = ' ';
        }
    }
    str[ SIZE * SIZE ] = '\0';
}

/*******************
 * Function Name: replaceLetters
 *	Input:char str[]- the string we replace letters in, int len- length of string,
 *	int freeSlots - the number of free slots we have in the array
 *	Output: int 1 or int 0 - if we changed letters to spaces we return 1, else 0.
 *	Function Operation: find small letters and replace by spaces
*******************/
int replaceLetters(char str[], int len, int freeSlots)
{

    int isReplaced = 0;
    for (int i = 0; i < len; i++)
    {
        switch (SIZE)
        {
            case 1:
                if(str[ i ] == 'a')
                {
                    str[ i ] = ' ';
                    isReplaced++;
                }
                break;
            case 2:
                if(str[ i ] == 'a')
                {
                    str[ i ] = ' ';
                    isReplaced++;
                }
                else if(str[ i ] == 'b')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 2);
                    isReplaced++;
                }
                else if(str[ i ] == 'c')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 3);
                    isReplaced++;
                }
                else if(str[ i ] == 'd')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 4);
                    isReplaced++;
                }
                break;
            case 3:
                if(str[ i ] == 'a')
                {
                    str[ i ] = ' ';
                    isReplaced++;
                }
                else if(str[ i ] == 'b')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 2);
                    isReplaced++;
                }
                else if(str[ i ] == 'c')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 3);
                    isReplaced++;
                }
                else if(str[ i ] == 'd')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 4);
                    isReplaced++;
                }
                else if(str[ i ] == 'e')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 5);
                    isReplaced++;
                }
                else if(str[ i ] == 'f')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 6);
                    isReplaced++;
                }
                else if(str[ i ] == 'g')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 7);
                    isReplaced++;
                }
                else if(str[ i ] == 'h')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 8);
                    isReplaced++;
                }
                else if(str[ i ] == 'i')
                {
                    moveAllRight(str, len, i, freeSlots);
                    addSpaces(str, i, 9);
                    isReplaced++;
                }
                break;
        }
    }
    if(isReplaced != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*******************
 * Function Name: countSigns
 *	Input: char str[] - the string we are searching in, char sign - the sign we are looking for
 *	Output: int counter - the number of occurrences we found of the sign
 *	Function Operation: count number of chosen signs in a string
*******************/
int countSigns(char str[], char sign)
{

    int counter = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if(str[ i ] == sign)
        {
            counter++;
        }
    }
    return counter;
}

/*******************
 * Function Name: checkLoneSlashes
 *	Input: char str[]-the string we are browsing
 *	Output: None
 *	Function Operation: the function checks if the string we received contains adjacent slashes,
 *	and if so inserts a space between them.
*******************/
void checkLoneSlashes(char str[])
{

    if(str[ 0 ] == '/')//if the slash comes first, the first line is empty and we need to pad it for strtok
    {
        for (int j = strlen(str) + 1; j > 0; j--)//we move the whole string to the right
        {
            str[ j + 1 ] = str[ j ];
        }
        str[ 0 ] = ' ';
        str[ 1 ] = '/';
    }
    for (int i = 1; i < strlen(str); i++)
    {
        if((str[ i ] == '/') && (str[ i + 1 ] == '/'))
        {
            for (int k = strlen(str) + 1; k > 0; k--)//we move the whole string to the right
            {
                str[ k + 1 ] = str[ k ];
                if(k == i)
                {
                    str[ k + 1 ] = ' ';
                    break;
                }
            }
        }
        if((str[ i ] == '/') && (str[ i + 1 ] == '\0'))
        {
            str[ i + 1 ] = ' ';
            str[ i + 2 ] = '\0';
        }
    }
}

/*******************
 * Function Name: isStrLgl
 *	Input:char str[]
 *	Output: int 1 or int 0 - if the string is legal we return 1, else 0.
 *	Function Operation: check if str is legal - if there is no less or more slashes, and if the board
 *	can contain that much characters
*******************/
int isStrLgl(char str[])
{

    int tempLength = strlen(str);
    tempLength += countConvertibles(str, tempLength);
    //we test whether the length of the string is greater than the size of the board for our given SIZE
    if((tempLength < BOARDSIZE) && ((countSigns(str, '/') == SIZE * SIZE - 1)))//we check the amount of slashes
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*******************
 * Function Name: myCreateBoard
 *	Input: char board[][SIZE * SIZE] - the board we will fill, char str[] - the string we will fill the board with,
 *	char tokenCopy[] - a copy of the token we receive
 *	Output: None
 *	Function Operation: fill the array we are given with the string given.
*******************/
void myCreateBoard(char board[][SIZE * SIZE], char str[], char tokenCopy[])
{

    int tester = isStrLgl(str);
    if(tester == 1)
    {
        //char tokenCopy[(SIZE*SIZE)];
        //initArr(tokenCopy,SIZE*SIZE);
        char strCopy[BOARDSIZE]; //TODO check for SIZE cases
        strcpy(strCopy, str);
        checkLoneSlashes(strCopy);
        int i = 0, len = 0, index = 0, replacedLetters = 0;//i=board rows j=board columns
        char *token = strtok(strCopy, "/");
        len = strlen(token);
        //len+=countConvertibles(token,len);
        if((len + countConvertibles(token, len))
           > (SIZE * SIZE))//TODO check if not code duplication
        {
            printf("Error\n");
            return;
        }
        while ((token != NULL))
        {
            len = strlen(token);
            //len+=countConvertibles(token,len);
            if((len + countConvertibles(token, len))
               > (SIZE * SIZE))
            {
                printf("Error\n");
                return;
            }
            initArr(tokenCopy, (SIZE * SIZE));
            if(tokenCopy != NULL)
            {
                strncpy(tokenCopy, token, strlen(token));
            }
            if(
                    replaceLetters(tokenCopy, (SIZE * SIZE), (SIZE * SIZE) - len)
                    )
            {
                strncpy(*board + i, tokenCopy, SIZE * SIZE);
                token = strtok(NULL, "/");
                index++;
                i += (SIZE * SIZE);
            }
            else
            {
                if(len < (SIZE * SIZE))//if we are working with token
                {
                    for (int k = len; k < (SIZE * SIZE); k++)
                    {
                        board[ index ][ k ] = ' ';
                    }
                }
                strncpy(*board + i, token, len);
                token = strtok(NULL, "/");
                index++;//TODO CHANGE MY NAME and
                i += (SIZE * SIZE);
            }
        }
    }
    else
    {
        printf("Error\n");
        return;
    }
};

/*******************
 * Function Name: createBoard
 *	Input:char board[][SIZE * SIZE] - the board we will fill, char str[] - the string we will fill the board with
 *	Output:None
 *	Function Operation: creates a tokenCopy of the apprropriate size, and invokes myCreateBoard with it.
*******************/
void createBoard(char board[][SIZE * SIZE], char str[])
{

    switch (SIZE)
    {
        case 1:
        {
            char tokenCopy[] = "  ";
            myCreateBoard(board, str, tokenCopy);
        }
            break;
        case 2:
        {
            char tokenCopy[] = "     ";
            myCreateBoard(board, str, tokenCopy);
        }
            break;
        case 3:
        {
            char tokenCopy[] = "          ";
            myCreateBoard(board, str, tokenCopy);
        }
            break;
    }
}

/*******************
 * Function Name: printBoard
 *	Input:char board[][SIZE * SIZE] - the board we will print
 *	Output:None
 *	Function Operation: prints the board
*******************/
void printBoard(char board[][SIZE * SIZE])
{//"12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679"
    for (int i = 0; i < (SIZE * SIZE); i++)
    {
        for (int j = 0; j < (SIZE * SIZE); j++)
        {
            if(j == ((SIZE * SIZE) - 1))
            {
                printf("%c\n", board[ i ][ j ]);
            }
            else if((j == SIZE - 1) || (j == 2 * SIZE - 1))//if we reach the separation line
            {
                printf("%c | ", board[ i ][ j ]);
            }
            else
            {
                printf("%c", board[ i ][ j ]);
            }
        }
        if((i == SIZE - 1) || (i == 2 * SIZE - 1))//print spacers
        {
            /*for (int k = 0; k < (SIZE * SIZE); k++)
            {
                printf(" ");
            }*/
            printf("\n");
        }
    }
    printf("\n");
}

/*******************
 * Function Name: isLglMove
 *	Input:char input - the move the legality of which we are checking
 *	Output: int 1 or int 0, if the move is legal, we return 1. else 0
 *	Function Operation: check if the move is legal - if the coordinates we were given are withing the bounds,
 *	and that are not forbidden symbols
*******************/
int isLglMove(char input) //we check if the input in the string is
{

    if((input >= '0') && (input <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*******************
 * Function Name: charExist
 *	Input:char board[][SIZE * SIZE] - the board we are searching in, char toFind-  the char we are looking for
 *	Output: int 1 or int 0, if the char exists in the board, we return 1. else 0
 *	Function Operation: check if the char exists in the board
*******************/
int charExist(char board[][SIZE * SIZE], char toFind)//check if a char exists in the array
{

    for (int i = 0; i < (SIZE * SIZE); i++)
    {
        for (int j = 0; j < (SIZE * SIZE); j++)
        {
            if(board[ i ][ j ] == toFind)
            {
                return 1;
            }
        }
    }
    return 0;
}

/*******************
 * Function Name: deleteChar
 *	Input:char board[][SIZE * SIZE] - the board in which we operate, char locationRow - what row to look in,
 *	char locationCol - what column to look in
 *	Output: None
 *	Function Operation: delete the char at the location given
*******************/
void deleteChar(char board[][SIZE * SIZE], char locationRow, char locationCol)
{

    if(isLglMove(locationCol) && isLglMove(locationRow))
    {
        if((board[ locationRow - '0' ][ locationCol - '0' ]) == ' ')
        {
            printf("Error\n");
            return;
        }
        else
        {
            board[ locationRow - '0' ][ locationCol - '0' ] = ' ';
        }
    }
    else
    {
        printf("Error\n");
        return;
    }
}

/*******************
 * Function Name: addChar
 *	Input:char board[][SIZE * SIZE] - the board in which we operate, char locationRow - what row to look in,
 *	char locationCol - what column to look in, char toAdd - the char we want to add
 *	Output:None
 *	Function Operation: adds the char to the location
*******************/
void addChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char toAdd)
{

    if(isLglMove(locationCol) && isLglMove(locationRow))
    {
        if((board[ locationRow - '0' ][ locationCol - '0' ]) != ' ')
        {
            printf("Error\n");
            return;
        }
        else
        {
            board[ locationRow - '0' ][ locationCol - '0' ] = toAdd;
        }
    }
    else
    {
        printf("Error\n");
        return;
    }
}

/*******************
 * Function Name: changeChar
 *	Input:char board[][SIZE * SIZE] - the board in which we operate, char locationRow - what row to look in,
 *	char locationCol - what column to look in, char toAdd - the char we want to change
 *	Output:None
 *	Function Operation: changes the char at the location
*******************/
void changeChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char replaceWith)
{

    if(isLglMove(locationCol) && isLglMove(locationRow))
    {
        if((board[ locationRow - '0' ][ locationCol - '0' ]) == ' ')
        {
            printf("Error\n");
            return;
        }
        else
        {
            board[ locationRow - '0' ][ locationCol - '0' ] = replaceWith;
        }
    }
    else
    {
        printf("Error\n");
        return;
    }
}

/*******************
 * Function Name: replaceAll
 *	Input:board[][SIZE * SIZE] - the board in which we operate, char toReplace - the char we want to replace,
 *	char replaceWith - the char we replace with
 *	Output: None
 *	Function Operation: replaces all the ooccurrences of the char in the board
*******************/
void replaceAll(char board[][SIZE * SIZE], char toReplace, char replaceWith)
{

    if((toReplace != ' ') && (charExist(board, toReplace)))
    {
        for (int i = 0; i < (SIZE * SIZE); i++)
        {
            for (int j = 0; j < (SIZE * SIZE); j++)
            {
                if(board[ i ][ j ] == toReplace)
                {
                    board[ i ][ j ] = replaceWith;
                }
            }
        }
    }
    else
    {
        printf("Error\n");
        return;
    }
}

/*******************
 * Function Name: makeMove
 *	Input:char board[][SIZE * SIZE] - the board in which we operate - the string containing the move we want to make
 *	Output: None
 *	Function Operation: makes the requested move
*******************/
void makeMove(char board[][SIZE * SIZE], char move[])
{

    char strCopy[MOVESIZE], myMove[MOVESIZE], toReplace, replaceWith, locationRow, locationCol, toAdd;
    char *token = NULL;
    strcpy(strCopy, move);//we copy the given move the our array
    token = strtok(strCopy, ",");
    strcpy(myMove, token);
    if((strcmp(myMove, "replaceAll") == 0) && (strlen(move) == RPLCLEN))
    {
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        toReplace = *token;
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        replaceWith = *token;
        replaceAll(board, toReplace, replaceWith);
    }
    else if((strcmp(myMove, "change") == 0) && (strlen(move) == CHGLEN))
    {
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        locationRow = *token;
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        locationCol = *token;
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        replaceWith = *token;
        changeChar(board, locationRow, locationCol, replaceWith);
    }
    else if((strcmp(myMove, "add") == 0) && (strlen(move) == ADDLEN))
    {
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        locationRow = *token;
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        locationCol = *token;
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        toAdd = *token;
        addChar(board, locationRow, locationCol, toAdd);
    }
    else if((strcmp(myMove, "delete") == 0) && (strlen(move) == DLTLEN))
    {
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        locationRow = *token;
        token = strtok(NULL, ",");
        if(token == NULL)
        {
            printf("Error\n");
            return;
        }
        locationCol = *token;
        deleteChar(board, locationRow, locationCol);
    }
    else
    {
        printf("Error\n");
        return;
    }
}

/*******************
 * Function Name: isSudoku
 *	Input:board[][SIZE * SIZE] - the board in which we operate
 *	Output: int 0 - if there are signs other than spaces or 1-9. int 1 - if the board is sudoku legal.
 *	Function Operation: checks if the board is "sudoku" legal
*******************/
int isSudoku(char board[][SIZE * SIZE])
{

    for (int i = 0; i < SIZE * SIZE; ++i)
    {
        for (int j = 0; j < SIZE * SIZE; ++j)
        {
            if((board[ i ][ j ] != ' ') && (((board[ i ][ j ]) < '1') || ((board[ i ][ j ]) > '9')))
            {
                return 1;
            }
        }
    }
    return 0;
}

/*******************
 * Function Name: checkRowGlob
 *	Input:board[][SIZE * SIZE] - the board in which we operate
 *	Output: int 0 if there are no duplicate numbers int 1 if there are duplicates
 *	Function Operation: checks the whole row of the whole board for duplicate chars
*******************/
int checkRowGlob(char board[][SIZE * SIZE])
{

    char firstChar;
    int k = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        do
        {
            firstChar = board[ i ][ k ];
            k++;
        } while (firstChar == ' ');
        for (int j = k; j < SIZE * SIZE; j++)
        {
            if(board[ i ][ j ] == firstChar)
            {
                return 1;
            }
        }
    }
    return 0;
}

/*******************
 *  Function Name: checkColGlob
 *  Input:board[][SIZE * SIZE] - the board in which we operate
 *	Output: int 0 if there are no duplicate numbers int 1 if there are duplicates
 *	Function Operation: checks the whole column of the whole board for duplicate chars
*******************/
int checkColGlob(char board[][SIZE * SIZE])
{

    char firstChar;
    int k = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        do
        {
            firstChar = board[ k ][ i ];
            k++;
        } while (firstChar == ' ');
        for (int j = k; j < SIZE * SIZE; j++)
        {
            if(board[ j ][ i ] == firstChar)
            {
                return 1;
            }
        }
    }
    return 0;
}

/*******************
 *  Function Name: boxify
 *	Input:board[][SIZE * SIZE] - the board in which we operate
 *	Output:none
 *	Function Operation: separates the board into boxes/squares
*******************/
void boxify(char board[][SIZE * SIZE])
{

    int k = 0, num = 0;
    //we break the board into boxes
    for (int si = 0; si < SIZE; si++)
    {
        for (int sj = 0; sj < SIZE; sj++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    //printf("%c", board[si*3+i][sj*3+j]);//TODO DELETE

                    boxArr[ k ][ num % (SIZE * SIZE) ] = board[ si * SIZE + i ][ sj * SIZE + j ];
                    num++;
                }
            }
            k++;
        }
    }
}

/*******************
 * Function Name: findDups
 *	Input: board[][SIZE * SIZE] - the board in which we operate
 *	Output:int dups - the number of duplicate number we found
 *	Function Operation: find duplicate chars in a box
*******************/
int findDups(char boxArr[][SIZE * SIZE])//find if there is more than 1 occurence of char per square
{

    int dups = 0;
    for (int k = 0; k < SIZE * SIZE; k++)
    {
        for (int i = 0; i < SIZE * SIZE; i++)
        {
            for (int j = i + 1; j < SIZE * SIZE; j++)
            {
                if((boxArr[ k ][ i ] == boxArr[ k ][ j ]) && (boxArr[ k ][ i ] != ' '))
                {
                    dups++;
                }
            }
        }
    }
    return dups;
}

/*******************
 *  Function Name: checkSquares
 *	Input: board[][SIZE * SIZE] - the board in which we operate
 *	Output: int findDups(boxArr) - the number of duplicates found
 *	Function Operation: turns the board to square and checks if the all the squares of the board are legal
*******************/
int checkSquares(char board[][SIZE * SIZE])
{

    boxify(board);
    return findDups(boxArr);
}

/*******************
 * Function Name: testBoard
 *	Input:char board[][SIZE * SIZE] the board in which we operate
 *	Output: int 1 if the are no duplicate numbers in each row/column/square int 0 if there are
 *	Function Operation: tests whether the board is sudoku legal
 *	no recurring numbers in the same row column or square
*******************/
int testBoard(char board[][SIZE * SIZE])
{

    int counter = 0;
    if(isSudoku(board) == 0)
    {
        counter += checkSquares(board);
        counter += checkRowGlob(board);
        counter += checkColGlob(board);
        if(counter == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

/*******************
 * Function Name: checkRowSpaces
 *	Input:char board[][SIZE * SIZE] the board in which we operate
 *	Output: int 0 if there is more than 1 space per row int 1 if there arent
 *	Function Operation: checks that there a no more than 1 space in a row
*******************/
int checkRowSpaces(char board[][SIZE * SIZE])
{

    int occurrences = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        occurrences = 0;
        for (int j = 0; j < SIZE * SIZE; j++)
        {
            if(board[ i ][ j ] == ' ')
            {
                occurrences++;
            }
        }
        if(occurrences > 1)
        {
            return 0;
        }
    }
    return 1;
}

/*******************
 * Function Name: checkColSpaces
 *	Input:char board[][SIZE * SIZE] the board in which we operate
 *	Output: int 0 if there is more than 1 space per column  int 1 if there arent
 *	Function Operation: checks that there a no more than 1 space in a Column
*******************/
int checkColSpaces(char board[][SIZE * SIZE])
{

    int occurrences = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        occurrences = 0;
        for (int j = 0; j < SIZE * SIZE; j++)
        {
            if(board[ j ][ i ] == ' ')
            {
                occurrences++;
            }
        }
        if(occurrences > 1)
        {
            return 0;
        }
    }
    return 1;
}

/*******************
 * Function Name: findSign
 *	Input:char toFind - the character we want to find, int index - the box we will be looking in
 *	Output:int occurrences   - the number of times the char is in the box
 *	Function Operation: counts the number of occurrences of a char in a square
*******************/
int findSign(char toFind, int index)//check the index box to find the space
{

    int occurrences = 0;
    for (int r = 0; r < SIZE * SIZE; r++)
    {
        if(boxArr[ index ][ r ] == toFind)
        {
            occurrences++;
        }
    }
    return occurrences;
}

/*******************
 * Function Name: squaresToArr
 *	Input:char box[][SIZE * SIZE] - the array of boxes we will be turning into a board,
 *	char board[][SIZE * SIZE] the board we will store in
 *	Output: none
 *	Function Operation: turns an array of changed boxes back into the board array
*******************/
void squaresToArr(char box[][SIZE * SIZE], char board[][SIZE * SIZE])
{

    int k = 0, num = 0;
    //char box[SIZE * SIZE][SIZE * SIZE];//we break the board into boxes
    for (int si = 0; si < SIZE; si++)
    {
        for (int sj = 0; sj < SIZE; sj++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    //printf("%c", board[si*3+i][sj*3+j]);//TODO DELETE

                    board[ si * SIZE + i ][ sj * SIZE + j ] = boxArr[ k ][ num % (SIZE * SIZE) ];
                    num++;
                }
            }
            k++;
        }
    }
}

/*******************
 * Function Name: completeBoard
 *	Input:char board[][SIZE * SIZE] - the arrays containing the almost finished board
 *	Output:
 *	Function Operation: solves an almost finished sudoku board
*******************/
void completeBoard(char board[][SIZE * SIZE])
{
    //int a=findSign(board,' ',1);
    if((testBoard(board) == 1) && (checkRowSpaces(board) == 1) && (checkColSpaces(board) == 1))
    {
        for (int i = 0; i < SIZE * SIZE; i++)//check each box for empty spaces i=box index
        {
            for (int j = 0; j < SIZE * SIZE; j++)//j= chars in box
                if(boxArr[ i ][ j ] == ' ')
                {
                    for (int k = 1; k <= SIZE * SIZE; k++)
                    {
                        boxArr[ i ][ j ] = k + '0';
                        if(findSign(boxArr[ i ][ j ], i) == 1)
                        {//if the number doesn't break the box rules
                            break;
                        }
                    }
                }
        }
        squaresToArr(boxArr, board);
    }
    else
    {
        printf("Error\n");
        return;
    }
}

/*******************
 * Function Name: isSameBoard
 *	Input:
 *	Output: int 1 if the board are identical and int 0 if not
 *	Function Operation: checks whether the given board are identical
*******************/
int isSameBoard(char board[][SIZE * SIZE], char board1[][SIZE * SIZE])//TODO
{

    if((strcmp(*board, *board1)) == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < (SIZE * SIZE); i++)
        {
            for (int j = 0; j < (SIZE * SIZE); j++)
            {
                if(board[ i ][ j ] != board1[ i ][ j ])
                {
                    //printf("board1:%c board2:%c\n", board[ i ][ j ], board1[ i ][ j ]);//
                    printf("Found inequality on row %d col %d.\n", (i), (j));
                    return 0;
                }
            }
        }
    }
    return 1;
}
