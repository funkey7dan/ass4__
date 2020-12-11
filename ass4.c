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
char boxArr[SIZE*SIZE][SIZE*SIZE];
void replaceAll(char board[][SIZE * SIZE], char toReplace, char replaceWith);
int isStrLgl(char str[]);
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
void squaresToArr(char box[][SIZE*SIZE],char board[][SIZE * SIZE]);
void boxify(char board[][SIZE*SIZE]);
/*******************
 * Function Name: addSpaces
 *	Input:num - number of spaces to add
 *	Output:
 *	Function Operation: add spaces to a string from a given index
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
 *	Input:
 *	Output:
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
 *	Input:
 *	Output:
 *	Function Operation: find small letters which need to be replaced by spaces
*******************/
int countConvertibles(char token[], int len)
{
//find small letters in order to stop the script from padding the string if they exist
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
 *	Input:
 *	Output:
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
 *	Input:
 *	Output:
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
 *	Input:
 *	1
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
 *	Input:
 *	Output:
 *	Function Operation: check whether there are empty lines given
*******************/
//helper function to find lone slashes and pad them with spaces
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
 *	Input:
 *	Output:
 *	Function Operation: check if str is legal
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
    /*int tester = isStrLgl(str);
    if(tester == 1)
    {
        //char tokenCopy[(SIZE*SIZE)];
        initArr(tokenCopy,SIZE*SIZE);
        char strCopy[BOARDSIZE]; //TODO check for SIZE cases
        strcpy(strCopy, str);
        checkLoneSlashes(strCopy);
        int i = 0, len = 0, index = 0,replacedLetters=0,len2;//i=board rows j=board columns
        char *token = strtok(strCopy, "/");
        len = strlen(token);
        len+=countConvertibles(token,len);
        if (len>(SIZE*SIZE))//TODO check if not code duplication
        {
            printf("Error\n");
            return;
        }
        while ((token != NULL))
        {

            len = strlen(token);
            len2= strlen(token);
            len+=countConvertibles(token,len);
            if (len>(SIZE*SIZE))
            {
                printf("Error\n");
                return;
            }
            initArr(tokenCopy,SIZE*SIZE);
            strncpy(tokenCopy,token,strlen(token));

            if(
                    replaceLetters(tokenCopy,(SIZE*SIZE)-1,(SIZE*SIZE)-len2)
                    )
            {
                strncpy(*board + i, tokenCopy, SIZE*SIZE);
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
                index++;//TODO CHANGE MY NAME and FIXME last line is not adressed
                i += (SIZE * SIZE);
            }
        }

    }
    else
    {
        printf("Error\n");
        return;
    }
*/
}

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
            for (int k = 0; k < (SIZE * SIZE); k++)
            {
                printf(" ");
            }
            printf("\n");
        }
    }
}

void deleteChar(char board[][SIZE * SIZE], char locationRow, char locationCol)
{

    if((board[ locationRow ][ locationCol ]) == ' ')
    {
        printf("Error\n");
        return;
    }
    else
    {
        board[ locationRow ][ locationCol ] = ' ';
    }
}

void addChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char toAdd)
{

    if((board[ locationRow ][ locationCol ]) != ' ') //TODO add check for letters
    {
        printf("Error\n");
        return;
    }
    else
    {
        board[ locationRow ][ locationCol ] = toAdd;
    }
}

void changeChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char replaceWith)
{

    if((board[ locationRow ][ locationCol ]) == ' ')
    {
        printf("Error\n");
        return;
    }
    else
    {
        board[ locationRow ][ locationCol ] = replaceWith;
    }
}

void replaceAll(char board[][SIZE * SIZE], char toReplace, char replaceWith)
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

void makeMove(char board[][SIZE * SIZE], char move[])
{
//TODO ADD CHECK IF LEGAL
    char strCopy[MOVESIZE], myMove[MOVESIZE], toReplace, replaceWith, locationRow, locationCol, toAdd;
    char *token = NULL;
    strcpy(strCopy, move);
    token = strtok(strCopy, ",");
    strcpy(myMove, token);
    if(strcmp(myMove, "replaceAll") == 0)
    {
        token = strtok(NULL, ",");
        toReplace = *token;
        token = strtok(NULL, ",");
        replaceWith = *token;
        replaceAll(board, toReplace, replaceWith);
    }
    else if(strcmp(myMove, "change") == 0)
    {
        token = strtok(NULL, ",");
        locationRow = *token;
        token = strtok(NULL, ",");
        locationCol = *token;
        token = strtok(NULL, ",");
        replaceWith = *token;
        changeChar(board, locationRow, locationCol, replaceWith);
    }
    else if(strcmp(myMove, "add") == 0)
    {
        token = strtok(NULL, ",");
        locationRow = *token;
        token = strtok(NULL, ",");
        locationCol = *token;
        token = strtok(NULL, ",");
        toAdd = *token;
        addChar(board, locationRow, locationCol, toAdd);
    }
    else if(strcmp(myMove, "delete") == 0)
    {
        token = strtok(NULL, ",");
        locationRow = *token;
        token = strtok(NULL, ",");
        locationCol = *token;
        deleteChar(board, locationRow, locationCol);
    }
}

int isSudoku(char board[][SIZE * SIZE])//if not sudoku return 1, if sudoku return 0
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
void boxify(char board[][SIZE*SIZE])
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

int checkSquares(char board[][SIZE * SIZE])
{

    /*int k = 0, num = 0;
    char box[SIZE * SIZE][SIZE * SIZE];//we break the board into boxes
    for (int si = 0; si < SIZE; si++)
    {
        for (int sj = 0; sj < SIZE; sj++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    //printf("%c", board[si*3+i][sj*3+j]);//TODO DELETE

                    box[ k ][ num % (SIZE * SIZE) ] = board[ si * SIZE + i ][ sj * SIZE + j ];
                    num++;
                }
            }
            k++;
        }
    }*/
    boxify(board);
    return findDups(boxArr);
}

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

int checkRowSpaces(char board[][SIZE * SIZE])
{

    int occurences = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        occurences = 0;
        for (int j = 0; j < SIZE * SIZE; j++)
        {
            if(board[i][j]==' ')
                occurences++;
        }
        if (occurences>1)
            return 0;
    }
    return 1;
}

int checkColSpaces(char board[][SIZE * SIZE])
{

    int occurences = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        occurences = 0;
        for (int j = 0; j < SIZE * SIZE; j++)
        {
            if(board[j][i]==' ')
                occurences++;
        }
        if (occurences>1)
            return 0;
    }
    return 1;
}

int findSign(char toFind, int index)//check the index box to find the space
{

    int occurences = 0;
    /*char box[SIZE * SIZE][SIZE * SIZE];
    for (int si = 0; si < SIZE; si++)
    {
        for (int sj = 0; sj < SIZE; sj++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    //printf("%c", board[si*3+i][sj*3+j]);//TODO DELETE

                    box[ k ][ num % (SIZE * SIZE) ] = board[ si * SIZE + i ][ sj * SIZE + j ];
                    num++;
                }
            }
            k++;
        }
    }*/
    for (int r = 0; r < SIZE * SIZE; r++)
    {
        if(boxArr[ index ][ r ] == toFind)
        {
            occurences++;
        }
    }
    //printf("DEBUG:Box %d has %d '%c's\n", index, occurences, toFind);//TODO delete
    return occurences;
}
void squaresToArr(char box[][SIZE*SIZE],char board[][SIZE * SIZE])
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

                     board[ si * SIZE + i ][ sj * SIZE + j ]=boxArr[ k ][ num % (SIZE * SIZE) ];
                    num++;
                }
            }
            k++;
        }
    }

}
void completeBoard(char board[][SIZE * SIZE])
{
    //int a=findSign(board,' ',1);
    if((testBoard(board) == 1) && (checkRowSpaces(board) == 1) && (checkColSpaces(board) == 1))
    {
        for (int i = 0; i < SIZE * SIZE; i++)//check each box for empty spaces i=box index
        {
            for (int j = 0; j < SIZE * SIZE; j++)//j= chars in box
            if(boxArr[i][j]==' ')
            {
                for(int k=1;k<=SIZE*SIZE;k++)
                {
                    boxArr[i][j]=k+'0';
                    if(findSign(boxArr[i][j],i)==1)//if the number doesn't break the box rules
                        break;
                }
            }
        }
        squaresToArr(boxArr,board);
    }
    else
    {
        printf("Error\n");
        return;
    }
}

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
