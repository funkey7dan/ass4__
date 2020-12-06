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
void convertChars(char number);
int isStrLgl(char str[]);//TODO
int countSigns(char str[], char sign);

/*******************
 * Function Name: countSlash
 *	Input:
 *	Output:
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
 * Function Name: isStrLgl
 *	Input:
 *	Output:
 *	Function Operation: check if str is legal
*******************/
int isStrLgl(char str[])//TODO add check for multiple /// , add check for token length
{

    int tempLength = strlen(str);
    int boardSize = (SIZE * SIZE) * (SIZE * SIZE) + (SIZE * SIZE);
    //we test whether the length of the string is greater than the size of the board for our given SIZE
    if((tempLength <= boardSize) && (countSigns(str, '/') <= SIZE * SIZE - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*******************
 * Function Name: convertChars
 *	Input:
 *	Output:
 *	Function Operation: converts characters depending on SIZE
*******************/
void convertChars(char number)
{

    int size = SIZE;
    switch (size)
    {
        case 1:
        {
            {
                if(number == 'a')
                {
                    printf(" ");
                }
            }
            break;
        }
        case 2:
        {
            {
                if(number == 'a')
                {
                    printf(" ");
                }
                if(number == 'b')
                {
                    printf("  ");
                }
                if(number == 'c')
                {
                    printf("   ");
                }
                if(number == 'd')
                {
                    printf("    ");
                }
            }
            break;
        }
        case 3:
        {
            {
                if(number == 'a')
                {
                    printf(" ");
                }
                if(number == 'b')
                {
                    printf("  ");
                }
                if(number == 'c')
                {
                    printf("   ");
                }
                if(number == 'd')
                {
                    printf("    ");
                }
                if(number == 'e')
                {
                    printf("     ");
                }
                if(number == 'f')
                {
                    printf("      ");
                }
                if(number == 'g')
                {
                    printf("       ");
                }
                if(number == 'h')
                {
                    printf("        ");
                }
                if(number == 'i')
                {
                    printf("         ");
                }
                /*else
                    printf("%c",number);*/
            }
            break;
        }
    }
}//TODO check me later
//sample:12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679
void createBoard(char board[][SIZE * SIZE], char str[])
{

    int tester = isStrLgl(str);
    if(tester == 1)
    {
        char strCopy[90]; //TODO check for cases, add fill empty spaces
        strcpy(strCopy, str);
        char *token = strtok(strCopy, "/");
        int i = 0, j = 0, len = strlen(token);//i=board rows j=board columns


        while ((token != NULL))
        {
            //printf("%d\n",strlen(token));//TODO remove me
            len = strlen(token);
            strncpy(*board + i, token, len);
            if(len < (SIZE * SIZE))//TODO add token padding
            {
                for (int k = len; k < (SIZE * SIZE); k++)
                    board[ i ][ k ] = ' ';
            }
            token = strtok(NULL, "/");
            i += 9;
        }
    }
    else
    {
        printf("error\n");
    }
}

void printBoard(char board[][SIZE * SIZE])
{//"12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679"
    for (int i = 0; i < (SIZE * SIZE); i++)
    {
        for (int j = 0; j < (SIZE * SIZE); j++)
        {
            if(j == ((SIZE * SIZE) - 1))
            {
                if((board[ i ][ j ] >= 'a') && (board[ i ][ j ] <= 'i'))
                {
                    convertChars(board[ i ][ j ]);
                    printf("\n");
                }
                else
                {
                    printf("%c\n", board[ i ][ j ]);
                }
            }
            else if((j == SIZE - 1) || (j == 2 * SIZE - 1))
            {
                if((board[ i ][ j ] >= 'a') && (board[ i ][ j ] <= 'i'))
                {
                    convertChars(board[ i ][ j ]);
                    printf(" | ");
                }
                else
                {
                    printf("%c | ", board[ i ][ j ]);
                }
            }
            else
            {
                if((board[ i ][ j ] >= 'a') && (board[ i ][ j ] <= 'i'))
                {
                    convertChars(board[ i ][ j ]);
                }
                else
                {
                    printf("%c", board[ i ][ j ]);
                }
            }
        }
        if((i == SIZE - 1) || (i == 2 * SIZE - 1))
        {
            for (int k = 0; k < (SIZE * SIZE); k++)
                printf(" ");
            printf("\n");
        }
    }
}

void makeMove(char board[][SIZE * SIZE], char move[])
{
}

int isSameBoard(char board[][SIZE * SIZE], char board1[][SIZE * SIZE])//TODO delete me
//"12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679"
//"12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679"
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
                if (board[i][j]!=board1[i][j])
                {
                    printf("board1:%c board2:%c\n",board[i][j],board1[i][j]);//FIXME cant see last digit
                    printf("Found inequality on row %d col %d.\n",(i+1),(j+1));
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