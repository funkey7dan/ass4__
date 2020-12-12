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
#define MOVESIZE 17
#define BOARDSIZE (SIZE*SIZE*SIZE*SIZE+SIZE*SIZE)
#define RPLCLEN 14
#define CHGLEN 12
#define ADDLEN 9
#define DLTLEN 10
/*
 * A Note about why I used a global array:
 * I defined a the boxArr array to be global, because the other 2d array I can use is declared in the main.
 * given that I can't change the main the code will be checked with, I needed the array to be global.
 * if I declared the array each time anew every time I needed it, I would have to add about ~10 lines of the
 * same code to each function I use the array in. Also, the changes I make in this array span a lot of functions,
 * so I needed they array to be unchanging.
 * boxArr:
 * this 2d array is an array of "boxes" with each box representing a sub-square in the board.
 * each "box" is the digits from top-left to the bottom right of the square.
 * */
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
        // we add spaces to locations after the index
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
 *	Output: int total - the total number of convertible chars we found
 *	Function Operation: find and count small letters which need to be replaced by spaces
*******************/
int countConvertibles(char token[], int len)
{

    int total = 0;
    for (int i = 0; i < len; i++)
    {
        /*
         * we add the value of each letter in spaces to the total
         * we know that the value depends on the size defined so we break into cases
         * in the case of letter a its replaced by 1 space, so no additionnal space is needed,
         * so the value of a is 0, and we add 0 to the total. etc.
         */
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
                    //we
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
                    if(token[ i ] == 'e')
                    {
                        total += 4;
                    }
                    if(token[ i ] == 'f')
                    {
                        total += 5;
                    }
                    if(token[ i ] == 'g')
                    {
                        total += 6;
                    }
                    if(token[ i ] == 'h')
                    {
                        total += 7;
                    }
                    if(token[ i ] == 'i')
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

/*
 * we run the loop a number of times depending on the num we receive
 * each time we move the string starting from the given index to the right, one index each iteraion
 */
    for (int i = 0; i < num; i++)
    {
        for (int j = (len - 1 + i); j > index; j--)
        {
            //change the next number to the previous
            str[ j + 1 ] = str[ j ];
            str[ j ] = ' ';
        }
    }
    //we finish the string with the null terminator manually because we overwrite it
    //str[ SIZE * SIZE ] = '\0';
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
        /*
         * We know that the value depends on the size defined so we break into cases
         * each time we encounter a convertible letter, we move the rest of the string all the way
         * to the right side, to free spots for the spaces.
         * we then 
         * */
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
                /*
                 * We know that the value depends on the size defined so we break into cases
                 * each time we encounter a convertible letter, we move the rest of the string all the way
                 * to the right side, to free spots for the spaces.
                 * we then add spaces instead of the letter.
                 * finally, we increment the counter, to indicate we replaced words
                 *
                 */
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
    //if we replaced a letter we return 1
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
    //we run the loop for the length of the string
    for (int i = 0; i <= strlen(str); i++)
    {
        //each time we find the sign we increment the counter
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
    //if the slash comes first, the first line is empty and we need to pad it for strtok
    if(str[ 0 ] == '/')
    {
        //we start the loop from the end of the array, we begin from the length of str+1 for \0 which strlen ignores
        for (int j = strlen(str) + 1; j > 0; j--)
        {
            //we change the space to the letter before it
            str[ j + 1 ] = str[ j ];
        }
        //because this slash was first we manually replace it
        str[ 0 ] = ' ';
        str[ 1 ] = '/';
    }
    for (int i = 1; i < strlen(str); i++)
    {
        //we check if the the slashes are adjacent
        if((str[ i ] == '/') && (str[ i + 1 ] == '/'))
        {
//we start the loop from the end of the array, we begin from the length of str+1 for \0 which strlen ignores
            for (int k = strlen(str) + 1; k > 0; k--)
            {
                str[ k + 1 ] = str[ k ];
                if(k == i)
                {
                    str[ k + 1 ] = ' ';
                    break;
                }
            }
        }
        //if we reached the end of the string we need to replace the null terminator to indicate the new end of string
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

    /*we test whether the length of the string is greater than the size of the board for our given SIZE
     *we also check the amount of slashes.
     */
    if((tempLength < BOARDSIZE) && ((countSigns(str, '/') == SIZE * SIZE - 1)))
    {
        //if everything is in order we return 1
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
    //indication that the string is legal
    int tester = isStrLgl(str);
    // we check if there is enough slashes and the length is not greater than allowed.
    if(tester == 1)
    {
        // we create a copy of the string, because strtok is destructive to the string we run it on
        char strCopy[BOARDSIZE];
        strncpy(strCopy, str, BOARDSIZE);
        // we check if there are empty slashes, and pad them with spaces because strtok cant tokenize them otherwise.
        checkLoneSlashes(strCopy);
        // i - start of our line in the board, len - legnth of the token, index - the index of the line we are at
        int i = 0, len = 0, index = 0, replacedLetters = 0;
        // we save the result of strtok in the pointer token
        char *token = strtok(strCopy, "/");
        while ((token != NULL))
        {
            //we save the length of the token to compare it with things later
            len = strlen(token);
            //we check if after we convert the letters to spaces we will still be in the allowed size range
            if((len + countConvertibles(token, len)) > (SIZE * SIZE))
            {
                printf("Error\n");
                return;
            }
            //we initialize the tokenCopy with spaces to flush the previous chars from it
            initArr(tokenCopy, (SIZE * SIZE));
            //if token is NULL there is no need to copy it
            if(token != NULL)
            {
                //we copy the token to our tokenCopy on which we will operate
                strncpy(tokenCopy, token, SIZE * SIZE);
            }
            //if we replaced letters with spaces in the token, we will pass the tokenCopy to the board array
            if(replaceLetters(tokenCopy, strlen(tokenCopy), (SIZE * SIZE) - len))
            {
                strncpy(*board + i, tokenCopy, SIZE * SIZE);
                token = strtok(NULL, "/");
                //we update our index to know on which line we are currently
                index++;
                //we move between lines, each line is equal to SIZE^2 in length
                i += (SIZE * SIZE);
            }
                //if there were no spaces to add we pass the token as is
            else
            {
                //if our token is too short we pad the line with spaces in the board itself
                if(len < (SIZE * SIZE))
                {
                    for (int k = len; k < (SIZE * SIZE); k++)
                    {
                        board[ index ][ k ] = ' ';
                    }
                }
                strncpy(*board + i, token, len);
                token = strtok(NULL, "/");
                index++;
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
    //depending on the SIZE we create a different tokenCopy with the right amount of spaces from the get-go.
    switch (SIZE)
    {
        // we invoke the function that creates the board for us
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
            break;
        }
        case 3:
        {
            char tokenCopy[] = "          ";
            myCreateBoard(board, str, tokenCopy);
            break;
        }
    }
}

/*******************
 * Function Name: printBoard
 *	Input:char board[][SIZE * SIZE] - the board we will print
 *	Output:None
 *	Function Operation: prints the board
*******************/
void printBoard(char board[][SIZE * SIZE])
{
    // we go through the rows of the board
    for (int i = 0; i < (SIZE * SIZE); i++)
    {
        // and we go through the columns of the board
        for (int j = 0; j < (SIZE * SIZE); j++)
        {
            //we reached th end of the line and we need to go down a line
            if(j == ((SIZE * SIZE) - 1))
            {
                printf("%c\n", board[ i ][ j ]);
            }
                //if we reach the separation line we print the ABS sign to separate the board
            else if((j == SIZE - 1) || (j == 2 * SIZE - 1))
            {
                printf("%c | ", board[ i ][ j ]);
            }
                //no special cases, just print the char at that location
            else
            {
                printf("%c", board[ i ][ j ]);
            }
        }
        // we print the spacers
        if((i == SIZE - 1) || (i == 2 * SIZE - 1))
        {
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

int isLglMove(char input)
{
    //we check if the input in the string is an char that's allowed - numbers 0-9
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

    //we loop through the board in search of the char
    for (int i = 0; i < (SIZE * SIZE); i++)
    {
        for (int j = 0; j < (SIZE * SIZE); j++)
        {
            // if we found our char we return 1
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

    //we check if the given coordinates are comprise of allowed characters
    if(isLglMove(locationCol) && isLglMove(locationRow))
    {
        /*
         * we receive the coordinates as chars so we subtract the ascii sign of 0 from the digit to get the number itself
         * if the location we are given is already an empty space we return an error.
         *
         * */
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

    //we check if the given coordinates are comprise of allowed characters
    if(isLglMove(locationCol) && isLglMove(locationRow))
    {
        /*
     * we receive the coordinates as chars so we subtract the ascii sign of 0 from the digit to get the number itself
     * if the location we are given isn't an empty space we return an error.
     *
     * */
        if((board[ locationRow - '0' ][ locationCol - '0' ]) != ' ')
        {
            printf("Error\n");
            return;
        }
            //if the space is empty we put the char
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

    // we check if the spot we need to change isn't empty, and if the char even exists in the board
    if((toReplace != ' ') && (charExist(board, toReplace)))
    {
        for (int i = 0; i < (SIZE * SIZE); i++)
        {
            for (int j = 0; j < (SIZE * SIZE); j++)
            {
                //if we find the char we need to replace, we replace it
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

/*
 * strngCopy - we copy the given move to protect it from strtok
 * myMove - is the array we keep the name of the move for comparsion
 * */
    char strngCopy[MOVESIZE], myMove[MOVESIZE], toReplace, replaceWith, locationRow, locationCol, toAdd;
    char *token = NULL;
    // we know the maximum length of the move we are allowed, so if the given string is longer we return with error
    if(strlen(move) > MOVESIZE)
    {
        printf("Error\n");
        return;
    }
    //we copy the given move the our array
    strcpy(strngCopy, move);
    //we tokenize the copy using , as our delimiter
    token = strtok(strngCopy, ",");
    strcpy(myMove, token);
    // we check to see the move we are given,and we check if the move isn't longer than the known length
    if((strcmp(myMove, "replaceAll") == 0) && (strlen(move) == RPLCLEN))
    {
        /*
         * we proceed to break the given move into chunks, to pass it to our function
         * */
        token = strtok(NULL, ",");
        // if there was nothing after the ',' we return error
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
        //same as replaceAll
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
        //same as replaceAll
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
        //same as replaceAll
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

    //we loop through the board
    for (int i = 0; i < SIZE * SIZE; ++i)
    {
        for (int j = 0; j < SIZE * SIZE; ++j)
        {
            //if we have something other than spaces or the digits 1-9 we return 1 to indicate it's not a sudoku board
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

    //the first character, with which we will compare the rest
    char firstChar;
    //the colums index
    int k = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        //we run through the board until we find a char which isn't a space
        do
        {
            firstChar = board[ i ][ k ];
            k++;
        } while (firstChar == ' ');
        // we compare all the characters to the fisrt char we found
        for (int j = k; j < SIZE * SIZE; j++)
        {
            // if there is a duplicate we return 1
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
    //same as checkRowGlob
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
    // si - squares rows
    for (int si = 0; si < SIZE; si++)
    {
        // sj - squares columns
        for (int sj = 0; sj < SIZE; sj++)
        {
            // i the board rows
            for (int i = 0; i < SIZE; i++)
            {
                // j the board column
                for (int j = 0; j < SIZE; j++)
                {
                    // we add the numbers from the board to the corresponding square/box in the boxArr array
                    boxArr[ k ][ num % (SIZE * SIZE) ] = board[ si * SIZE + i ][ sj * SIZE + j ];
                    num++;
                }
            }
            // we are moving to the next square
            k++;
        }
    }
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
// we reverse the actions of boxify
    int k = 0, num = 0;
    for (int si = 0; si < SIZE; si++)
    {
        for (int sj = 0; sj < SIZE; sj++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    board[ si * SIZE + i ][ sj * SIZE + j ] = boxArr[ k ][ num % (SIZE * SIZE) ];
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

    //indicator for duplicates
    int dups = 0;
    // we run a loop through the boxes
    for (int k = 0; k < SIZE * SIZE; k++)
    {
        for (int i = 0; i < SIZE * SIZE; i++)
        {
            for (int j = i + 1; j < SIZE * SIZE; j++)
            {
                //if we found a duplicate which isn't a space we increment the dups
                if((boxArr[ k ][ i ] == boxArr[ k ][ j ]) && (boxArr[ k ][ i ] != ' '))
                {
                    dups++;
                }
            }
        }
    }
    // we return the number of duplicates we found
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
    // we break the board into boxes/squares and store tham in the boxArr array.
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
    //we check if the board is sudoku legal - only numbers and spaces
    if(isSudoku(board) == 0)
    {
        //if any of the tests is positive we add to the counter.
        counter += checkSquares(board);
        counter += checkRowGlob(board);
        counter += checkColGlob(board);
        //only if the counter is 0 we know that all the tests were passed
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
    //occurrences of spaces in the board
    int occurrences = 0;
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        //we set it to zero every row because we want to know if there is more than 1 space every row, not overall
        occurrences = 0;
        for (int j = 0; j < SIZE * SIZE; j++)
        {
            if(board[ i ][ j ] == ' ')
            {
                occurrences++;
            }
        }
        //if the current row had more than 1 space we return 0
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
//same as checkRowSpaces
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
int findSign(char toFind, int index)
{

    int occurrences = 0;
    for (int r = 0; r < SIZE * SIZE; r++)
    {
        //we check the given box
        if(boxArr[ index ][ r ] == toFind)
        {
            //everytime we find the sign we are looking for we increment
            occurrences++;
        }
    }
    return occurrences;
}

/*******************
 * Function Name: completeBoard
 *	Input:char board[][SIZE * SIZE] - the arrays containing the almost finished board
 *	Output:
 *	Function Operation: solves an almost finished sudoku board
*******************/
void completeBoard(char board[][SIZE * SIZE])
{
    //if all the test were passed we may continue
    if((testBoard(board) == 1) && (checkRowSpaces(board) == 1) && (checkColSpaces(board) == 1))
    {
        //check each box for empty spaces i=box index
        for (int i = 0; i < SIZE * SIZE; i++)
        {
            //j= chars in box
            for (int j = 0; j < SIZE * SIZE; j++)
                //we are looing for the space in the square
                if(boxArr[ i ][ j ] == ' ')
                {
                    //we try to insert every number until it fits the rules of sudoku
                    for (int k = 1; k <= SIZE * SIZE; k++)
                    {
                        boxArr[ i ][ j ] = k + '0';
                        if(findSign(boxArr[ i ][ j ], i) == 1)
                        {
                            //if the number doesn't break the box rules
                            break;
                        }
                    }
                }
        }
        //we turn the boxes back into a board
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

    // we compare the board to see if they are the same
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
                // we are looking for the difference between the boards
                if(board[ i ][ j ] != board1[ i ][ j ])
                {
                    printf("Found inequality on row %d col %d.\n", (i), (j));
                    return 0;
                }
            }
        }
    }
    return 1;
}
