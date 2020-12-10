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


void replaceAll(char board[][SIZE * SIZE], char toReplace, char replaceWith);
int isStrLgl(char str[]);
int countSigns(char str[], char sign);
void checkLoneSlashes(char str[]);
int countConvertibles(char token[], int len);
void changeChar(char board[][SIZE * SIZE], char locationRow, char locationCol,char replaceWith);
void deleteChar(char board[][SIZE * SIZE], char locationRow, char locationCol);
int replaceLetters(char str[],int len,int freeSlots);
void moveAllRight(char str[],int len,int index,int num);
void initArr(char str[],int len);
void addSpaces(char str[],int index,int num);
void myCreateBoard(char board[][SIZE * SIZE], char str[],char tokenCopy[]);
/*******************
 * Function Name: addSpaces
 *	Input:num - number of spaces to add
 *	Output:
 *	Function Operation: add spaces to a string from a given index
*******************/
void addSpaces(char str[],int index,int num)
{
    for (int i=0;i<num;i++)
    {
        str[index+i]=' ';
    }

}
/*******************
 * Function Name: initArr
 *	Input:
 *	Output:
 *	Function Operation: fills array with spaces
*******************/
void initArr(char str[],int len)
{
    for (int i=0;i<len;i++)
    {
        str[i]=' ';
    }
}
/*******************
 * Function Name: countConvertibles
 *	Input:
 *	Output:
 *	Function Operation: find small letters which need to be replaced by spaces
*******************/
int countConvertibles(char token[],int len)
{
//TODO finish me. find small letters in order to stop the script from padding the string if they exist
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
void moveAllRight(char str[],int len,int index,int num)
{

    for (int i = 0; i < num; i++)
    {
        for (int j = (len-1+i); j > index; j--)//we move the whole string to the right
        {
            str[ j + 1 ] = str[ j ];
            str[j] = ' ';

        }
    }
    str[SIZE*SIZE]='\0';

}
/*******************
 * Function Name: replaceLetters
 *	Input:
 *	Output:
 *	Function Operation: find small letters and replace by spaces
*******************/
int replaceLetters(char str[],int len,int freeSlots)
{
    int isReplaced=0;
    for(int i=0;i<len;i++)
    {
        switch (SIZE)
        {
            case 1:
                if (str[i]=='a')
                {
                    str[i]=' ';
                    isReplaced++;
                }
                break;
            case 2:
                if (str[i]=='a')
                {
                    str[i]=' ';
                    isReplaced++;
                }
                else if(str[i]=='b')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,2);
                    isReplaced++;
                }
                else if(str[i]=='c')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,3);
                    isReplaced++;
                }
                else if(str[i]=='d')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,4);
                    isReplaced++;
                }
                break;
            case 3:
                if (str[i]=='a')
                {
                    str[i]=' ';
                    isReplaced++;
                }
                else if(str[i]=='b')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,2);
                    isReplaced++;
                }
                else if(str[i]=='c')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,3);
                    isReplaced++;
                }
                else if(str[i]=='d')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,4);
                    isReplaced++;
                }
                else if(str[i]=='e')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,5);
                    isReplaced++;
                }
                else if(str[i]=='f')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,6);
                    isReplaced++;
                }
                else if(str[i]=='g')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,7);
                    isReplaced++;
                }
                else if(str[i]=='h')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,8);
                    isReplaced++;
                }
                else if(str[i]=='i')
                {
                    moveAllRight(str,len,i,freeSlots);
                    addSpaces(str,i,9);
                    isReplaced++;
                }
                break;
        }
    }
    if (isReplaced!=0)
        return 1;
    else
        return 0;
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
            str[ i + 1 ]=' ';
            str[i+2]='\0';
        }
    }

}

/*******************
 * Function Name: isStrLgl
 *	Input:
 *	Output:
 *	Function Operation: check if str is legal
*******************/
int isStrLgl(char str[])//TODO add check for multiple /// , add check for token length
{

    int tempLength = strlen(str);
    tempLength+=countConvertibles(str,tempLength);
    //int boardSize = ((SIZE * SIZE) * (SIZE * SIZE)) + (SIZE * SIZE);//TODO DELETE ME
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


void myCreateBoard(char board[][SIZE * SIZE], char str[],char tokenCopy[])
        {
                int tester = isStrLgl(str);
                if(tester == 1)
                {
                    //char tokenCopy[(SIZE*SIZE)];
                    //initArr(tokenCopy,SIZE*SIZE);
                    char strCopy[BOARDSIZE]; //TODO check for SIZE cases
                    strcpy(strCopy, str);
                    checkLoneSlashes(strCopy);
                    int i = 0, len = 0, index = 0,replacedLetters=0;//i=board rows j=board columns
                    char *token = strtok(strCopy, "/");
                    len = strlen(token);
                    //len+=countConvertibles(token,len);
                    if ((len+countConvertibles(token,len))
                    >(SIZE*SIZE))//TODO check if not code duplication
                    {
                        printf("Error\n");
                        return;
                    }
                    while ((token != NULL))
                    {

                        len = strlen(token);
                        //len+=countConvertibles(token,len);
                        if ((len+countConvertibles(token,len))
                            >(SIZE*SIZE))
                        {
                            printf("Error\n");
                            return;
                        }
                        initArr(tokenCopy,(SIZE*SIZE));
                        if (tokenCopy!=NULL)
                            strncpy(tokenCopy,token,strlen(token));


                        if(
                                replaceLetters(tokenCopy,(SIZE*SIZE),(SIZE*SIZE)-len)
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
            char tokenCopy[]="  ";
            myCreateBoard(board,str,tokenCopy);
        }
            break;
        case 2:
        {
            char tokenCopy[]="     ";
            myCreateBoard(board,str,tokenCopy);
        }
            break;
        case 3:
        {
            char tokenCopy[]="          ";
            myCreateBoard(board,str,tokenCopy);
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
                printf("%c\n",board[ i ][ j ]);
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
    if((board[locationRow][locationCol])==' ')
    {
        printf("Error\n");
        return;
    }
    else
    {
        board[locationRow][locationCol]=' ';
    }
}
void addChar(char board[][SIZE * SIZE], char locationRow, char locationCol,char toAdd)
{
    if((board[locationRow][locationCol])!=' ') //TODO add check for letters
    {
        printf("Error\n");
        return;
    }
    else
    {
        board[locationRow][locationCol]=toAdd;
    }
}
void changeChar(char board[][SIZE * SIZE], char locationRow, char locationCol,char replaceWith)
{
    if((board[locationRow][locationCol])==' ')
    {
        printf("Error\n");
        return;
    }
    else
    {
        board[locationRow][locationCol]=replaceWith;
    }
}
void replaceAll(char board[][SIZE * SIZE], char toReplace, char replaceWith)
{
    for(int i=0;i<(SIZE*SIZE);i++)
    {
        for(int j=0;j<(SIZE*SIZE);j++)
        {
            if (board[i][j]==toReplace)
                board[i][j]=replaceWith;
        }

    }
}

void makeMove(char board[][SIZE * SIZE], char move[])
{
//TODO ADD CHECK IF LEGAL
    char strCopy[MOVESIZE], myMove[MOVESIZE],toReplace,replaceWith,locationRow,locationCol,toAdd;
    char *token = NULL;
    strcpy(strCopy, move);
    token = strtok(strCopy, ",");
    strcpy(myMove, token);
    if(strcmp(myMove, "replaceAll") == 0)
    {
        token = strtok(NULL, ",");
        toReplace=*token;
        token = strtok(NULL, ",");
        replaceWith=*token;
        replaceAll(board,toReplace,replaceWith);
    }
    else if (strcmp(myMove, "change") == 0)
    {
        token = strtok(NULL, ",");
        locationRow=*token;
        token = strtok(NULL, ",");
        locationCol=*token;
        token = strtok(NULL, ",");
        replaceWith=*token;
        changeChar(board,locationRow,locationCol,replaceWith);
    }
    else if (strcmp(myMove, "add") == 0)
    {
        token = strtok(NULL, ",");
        locationRow=*token;
        token = strtok(NULL, ",");
        locationCol=*token;
        token = strtok(NULL, ",");
        toAdd=*token;
        addChar(board,locationRow,locationCol,toAdd);
    }
    else if (strcmp(myMove, "delete") == 0)
    {
        token = strtok(NULL, ",");
        locationRow=*token;
        token = strtok(NULL, ",");
        locationCol=*token;
        deleteChar(board,locationRow,locationCol);
    }
}

int isSameBoard(char board[][SIZE * SIZE], char board1[][SIZE * SIZE])//TODO
{

    if((strcmp(board, board1)) == 0)
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

void completeBoard(char board[][SIZE * SIZE])
{}

int testBoard(char board[][SIZE * SIZE])
{}