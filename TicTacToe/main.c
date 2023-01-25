#include <stdio.h>
#include <stdlib.h>

char square[10]={'0','1','2','3','4','5','6','7','8','9'};

int choice,player;

int checkForWin();
void drawBoard();
void markBoard(char mark);

int main()
{
    int gameStatus;
    char mark;
    player=1;

    do
    {
        drawBoard();
        player=(player%2)?1:2;
        printf("Player %d, enter a number: ",player);
        scanf("%d",&choice);

        mark=(player==1)?'X':'O';
        markBoard(mark);

        gameStatus=checkForWin();

        player++;

    }while(gameStatus==-1);

    if(gameStatus==1)
        printf("\n\n======>Player %d win...!!\n\n",--player);
    else
       printf("\n\n======> Game Draw.....!!\n\n");

    return 0;
}

/************************************************************************
Checking for different game status..........
return 1 for game over with result
return -1 for incomplete game
return 0 for game over with draw
************************************************************************/
int checkForWin()
{
    int returnValue=0;

    if(square[1]==square[2] && square[2]==square[3])
    {
        returnValue=1;
    }
    else if(square[4]==square[5] && square[5]==square[6])
            returnValue=1;

    else if(square[7]==square[8] && square[8]==square[9])
            returnValue=1;

    else if(square[1]==square[4] && square[4]==square[7])
            returnValue=1;

    else if(square[2]==square[5] && square[5]==square[8])
            returnValue=1;

    else if(square[3]==square[6] && square[6]==square[9])
            returnValue=1;

    else if(square[1]==square[5] && square[5]==square[9])
            returnValue=1;

    else if(square[3]==square[5] && square[5]==square[7])
            returnValue=1;

    else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' &&
            square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' &&
            square[9]!='9')
            returnValue=0;

    else
        returnValue=-1;


        return returnValue;
}

/************************************************************************
designing the board
***********************************************************************/

void drawBoard()
{
    system("clear");

    printf("\n  ***TIC***TAC***TOE\n");
    printf("\n PLAYER 1(X) - PLAYER 2(O)");

    printf("\n\n  %c  |  %c  |  %c  ",square[1],square[2],square[3]);

    printf("\n ____|_____|______\n");

    printf("  %c  |  %c  |  %c  ",square[4],square[5],square[6]);

    printf("\n ____|_____|______\n");

    printf("  %c  |  %c  |  %c  ",square[7],square[8],square[9]);

    printf("\n     |     |\n");


}

/*************************************************************************
Assigning the values
*************************************************************************/

void markBoard(char mark)
{
   if(choice==1 && square[1]=='1')
      square[1]=mark;

   else if(choice==2 && square[2]=='2')
      square[2]=mark;

   else  if(choice==3 && square[3]=='3')
      square[3]=mark;

   else if(choice==4 && square[4]=='4')
      square[4]=mark;

   else  if(choice==5 && square[5]=='5')
      square[5]=mark;

   else if(choice==6 && square[6]=='6')
      square[6]=mark;

   else if(choice==7 && square[7]=='7')
      square[7]=mark;

   else if(choice==8 && square[8]=='8')
      square[8]=mark;

   else if(choice==9 && square[9]=='9')
      square[9]=mark;

   else
   {
       printf("Invalid move");

       player--;
   }
}

