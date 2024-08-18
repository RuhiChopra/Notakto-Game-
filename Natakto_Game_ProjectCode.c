/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Ruhi Chopra
 * Student ID    : 1155165504
 * Class/Section : E
 * Date          : 17/04/2023
 */



#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */



/* Initialize the specified game board.
   Please design your own representation for the game board.  For example:
      - Does gameBoard[0][0] represent the top left corner or the bottom left corner of the game board?
      - Which numbers represent empty cells and crosses? */
void initGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part

    int i,j,k=1;
    for (i=2;i>=0;i--){
        for (j=2;j>=0;j--){
            if (i==0){
                gameBoard[i][j]=16-k;
                k++;
            }
            if (i==1){
                gameBoard[i][j]=10-k;
                k++;
            }
            if (i==2){
                gameBoard[i][j]=4-k;
                k++;
            }
        }
    }

}



/* Display the specified game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part

    int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("|");
            if (gameBoard[i][j]==11){
                printf("X");
            }
            else{
                printf("%d",gameBoard[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n");

}



/* Display the two game boards on the screen.
   Implemented for you already and no change is needed */
void printTwoGameBoards(int gameBoard1[3][3], int gameBoard2[3][3]) {
    printf("\n");
    printf("# Game Board 1 #\n");
    printGameBoard(gameBoard1);
    printf("# Game Board 2 #\n");
    printGameBoard(gameBoard2);
}



/* Return 1 if the specified game board is dead (i.e., having three-in-a-row of crosses), otherwise return 0. */
int isGameBoardDead(int gameBoard[3][3]){

    // TODO: Complete this part

    int i;
        for(i=0;i<3;i++){
            if(gameBoard[i][0]==11 && gameBoard[i][1]==11 && gameBoard[i][2]==11){
                return 1;
            }
            if(gameBoard[0][i]==11 && gameBoard[1][i]==11 && gameBoard[2][i]==11){
                return 1;
            }
        }
        if(gameBoard[0][0]==11 && gameBoard[1][1]==11 && gameBoard[2][2]==11){
            return 1;
        }
        if(gameBoard[0][2]==11 && gameBoard[1][1]==11 && gameBoard[2][0]==11){
            return 1;
        }
    return 0;

}



/* Update the specific game board according to the user input.
   The user input may not be valid, but you can assume that it must be an integer. */
void updateGameBoard(int gameBoard[3][3]) {

    // TODO: Complete this part

    int c;
    printf("Choose the cell:\n");
    scanf("%d",&c);
    while (c<1 || c>9){
        printf("Input out of range. Please input again:\n");
        scanf("%d",&c);
    }

    int i,j;
    j=((c-1)%3);
    i=((9-c)/3);
    while (gameBoard[i][j]==11){
        printf("The chosen cell is occupied. Please input again:\n");
        scanf("%d",&c);
        j=((c-1)%3);
        i=((9-c)/3);
        if (gameBoard[i][j]!=11){
            break;
        }
    }

    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (gameBoard[i][j]==c){
                gameBoard[i][j]=11;
            }
        }
    }
}



/* Choose a game board and place a cross according to the user inputs.
   The user input may not be valid, but you can assume that it must be an integer. */
void placeCrossByHumanPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {

    // TODO: Complete this part

    int gb;
    while (gb!=1 || gb!=2){
        printf("Choose the game board:\n");
        scanf("%d",&gb);
        if (gb==1 || gb==2){
            break;
        }
        printf("Input out of range. Please input again:\n");
        scanf("%d",&gb);
        if (gb==1 || gb==2){
            break;
        }
    }

    if (gb==1){
        while (isGameBoardDead(gameBoard1)==1){
            printf("The chosen game board is dead. Please input again:\n");
            scanf("%d",&gb);
            if (gb!=1){
                break;
            }
        }
    }
    if (gb==2){
        while (isGameBoardDead(gameBoard2)==1){
            printf("The chosen game board is dead. Please input again:\n");
            scanf("%d",&gb);
            if (gb!=2){
                break;
            }
        }
    }

    if (gb==1){
        updateGameBoard(gameBoard1);
    }

    if (gb==2){
        updateGameBoard(gameBoard2);
    }
}



/* Return the number of crosses on the specified game board. */
int countNumOfCrosses(int gameBoard[3][3]) {

    // TODO: Complete this part

    int i,j,k=0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (gameBoard[i][j]==11){
                k++;
            }
        }
    }
    return k;

}



/* Determine the next move of the computer player and update the corresponding game board accordingly.
   You are required to exactly follow the strategy mentioned in the project specification.
   IMPORTANT: Using other strategies will result in mark deduction. */
void placeCrossByComputerPlayer(int gameBoard1[3][3], int gameBoard2[3][3]) {

    // TODO: Complete this part

    int gb;
    if (isGameBoardDead(gameBoard1)!=1 && isGameBoardDead(gameBoard2)!=1){
        if (countNumOfCrosses(gameBoard1)<countNumOfCrosses(gameBoard2)){
            gb=1;
        }
        else{
            gb=2;
        }
    }
    else if (isGameBoardDead(gameBoard1)==1 || isGameBoardDead(gameBoard2)==1){
        if (isGameBoardDead(gameBoard1)){
            gb=2;
        }
        else{
            gb=1;
        }
    }
    printf("Choose the game board: %d\n",gb);

    int i,j,num=0;
    if (isGameBoardDead(gameBoard1)!=1 && isGameBoardDead(gameBoard2)!=1){
        if (gb==1){
            for (i=2;i>=0;i--){
                for (j=0;j<3;j++){
                    if  (gameBoard1[i][j]!=11){
                        num=gameBoard1[i][j];
                        gameBoard1[i][j]=11;
                        break;
                    }
                }
                if (num!=0){
                    break;
                }
            }
        }
        else{
            for (i=0;i<3;i++){
                for (j=2;j>=0;j--){
                    if (gameBoard2[i][j]!=11){
                        num=gameBoard2[i][j];
                        gameBoard2[i][j]=11;
                        break;
                    }
                }
                if (num!=0){
                    break;
                }
            }
        }
        printf("Choose the cell: %d\n",num);
    }
    else if (isGameBoardDead(gameBoard1)==1 || isGameBoardDead(gameBoard2)==1){
        if (isGameBoardDead(gameBoard2)==1){
            for (i=2;i>=0;i--){
                for (j=0;j<3;j++){
                    if (gameBoard1[i][j]!=11){
                        num=gameBoard1[i][j];
                        gameBoard1[i][j]=11;
                        if (isGameBoardDead(gameBoard1)!=1){
                            break;
                        }
                        else{
                            gameBoard1[i][j]=num;
                            num=0;
                        }
                    }
                }
                if (num!=0){
                    break;
                }
            }
        }
        else if(isGameBoardDead(gameBoard1)==1){
            for (i=0;i<3;i++){
                for (j=2;j>=0;j--){
                    if (gameBoard2[i][j]!=11){
                        num=gameBoard2[i][j];
                        gameBoard2[i][j]=11;
                        if (isGameBoardDead(gameBoard2)!=1){
                            break;
                        }
                        else{
                            gameBoard2[i][j]=num;
                            num=0;
                        }
                    }
                }
                if (num!=0){
                    break;
                }
            }
        }
            if (num==0){
                if (gb==1){
                    for(i=2;i>=0;i--){
                        for (j=0;j<3;j++){
                            if (gameBoard1[i][j]!=11){
                                num=gameBoard1[i][j];
                                gameBoard1[i][j]=11;
                                break;
                            }
                        }
                        if (num!=0){
                            break;
                        }
                    }
                }
                else if (gb==2){
                    for (i=0;i<3;i++){
                        for (j=2;j>=0;j--){
                            if(gameBoard2[i][j]!=11){
                                num=gameBoard2[i][j];
                                gameBoard2[i][j]=11;
                                break;
                            }
                        }
                        if (num!=0){
                            break;
                        }
                    }
                }
            }
        printf("Choose the cell: %d\n",num);
    }
}




/* The main function */
    int main(){
        /* Local variables */
        int gameBoard1[3][3];   // Represent Game Board 1
        int gameBoard2[3][3];   // Represent Game Board 2
        int currentPlayer;      // 1: Player 1             2: Player 2
        int gameEnd;            // 0: The game continues   1: The game ends
        int numOfHumanPlayers;  // 1 or 2

        /* Initialize the local variables */
        initGameBoard(gameBoard1);
        initGameBoard(gameBoard2);
        currentPlayer = 1;
        gameEnd = 0;
        printf("Enter the number of human players [1-2]:\n");
        scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid here

        /* Uncomment the following statements to test whether the printTwoGameBoards() and the placeCrossByHumanPlayer() functions are implemented correctly.
         You can add more if you wish.
         After testing, you can delete them or move them elsewhere. */
        //printTwoGameBoards(gameBoard1, gameBoard2);
        //printf("# Player 1's turn #\n");
        //placeCrossByHumanPlayer(gameBoard1, gameBoard2);
        //printTwoGameBoards(gameBoard1, gameBoard2);
        //printf("# Player 2's turn #\n");
        //placeCrossByHumanPlayer(gameBoard1, gameBoard2);
        //printTwoGameBoards(gameBoard1, gameBoard2);

        /* Game start
         If there are two human players, they are Player 1 and Player 2
         If there is only one human player, he/she is Player 1 and another player is the computer
         For both cases, Player 1 moves first
         Hint: use a while loop */

        // TODO: Complete this part
        int gb1,gb2,chance1=0;
        while (gameEnd==0){
            if (chance1==0){
                printTwoGameBoards(gameBoard1, gameBoard2);
                chance1++;
            }
            if (numOfHumanPlayers==2){
                if (currentPlayer==1){
                    printf("# Player 1's turn #\n");
                    placeCrossByHumanPlayer(gameBoard1, gameBoard2);
                    printTwoGameBoards(gameBoard1, gameBoard2);
                }
                gb1=isGameBoardDead(gameBoard1);
                gb2=isGameBoardDead(gameBoard2);
                if (gb1==1 && gb2==1){
                    printf("Congratulations! Player 2 wins!\n");
                    gameEnd=1;
                    break;
                }
                currentPlayer=3-currentPlayer;
                if (currentPlayer==2){
                    printf("# Player 2's turn #\n");
                    placeCrossByHumanPlayer(gameBoard1, gameBoard2);
                    printTwoGameBoards(gameBoard1, gameBoard2);
                }
                gb1=isGameBoardDead(gameBoard1);
                gb2=isGameBoardDead(gameBoard2);
                if (gb1==1 && gb2==1){
                    printf("Congratulations! Player 1 wins!\n");
                    gameEnd=1;
                    break;
                }
                currentPlayer=3-currentPlayer;
            }
            else if (numOfHumanPlayers==1){
                if (currentPlayer==1){
                    printf("# Player 1's turn #\n");
                    placeCrossByHumanPlayer(gameBoard1, gameBoard2);
                    printTwoGameBoards(gameBoard1, gameBoard2);
                }
                gb1=isGameBoardDead(gameBoard1);
                gb2=isGameBoardDead(gameBoard2);
                if (gb1==1 && gb2==1){
                    printf("Computer wins!\n");
                    gameEnd=1;
                    break;
                }
                currentPlayer=3-currentPlayer;
                if (currentPlayer==2){
                    printf("# Computer's turn #\n");
                    placeCrossByComputerPlayer(gameBoard1, gameBoard2);
                    printTwoGameBoards(gameBoard1, gameBoard2);
                }
                gb1=isGameBoardDead(gameBoard1);
                gb2=isGameBoardDead(gameBoard2);
                if (gb1==1 && gb2==1){
                    printf("Congratulations! Player 1 wins!\n");
                    gameEnd=1;
                    break;
                }
                currentPlayer=3-currentPlayer;
            }
        }
        return 0;
 }
