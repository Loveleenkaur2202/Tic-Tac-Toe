#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*function declaration*/
void init_board();
void print_board();
void make_move(char player);
bool check_if_valid(int row, int col);
bool check_if_win(char player);

//global variable
char board[3][3];
int num_games_played = 0; 

int main(void){

    char play_again;

    int win_x = 0; 
    int win_o = 0;

    do
    {
        system("cls"); 
        num_games_played++;

        char player = 'X'; //initial player x
        bool running = true; //true to keep looping and play game
        int move = 0; // we can maximum make 9 moves
        char win = ' '; //initialising win with a space because we don't have any winner yet
        
        init_board();
        print_board();
    
        while (running){ //loop as long as game is on

        if (move % 2 == 0){
            player = 'x'; //to play alternatively
        }
        else{
            player = 'o';
        }
        
        switch(player){
            case 'x':
                make_move(player);
                break;
            case 'o':
                make_move(player);
                break;
        }
        
        if (check_if_win(player)){ //check if a player has won 
            win = player;
            running = false; // false to exit game
        }
        
        move++; //increment to change turns
        
        if (move == 9){//max moves is 9 so when moves =9 game exits 
            running = false;
        }
        
        print_board();//prints board for every move
    }
    
        if (win == ' '){ //if there is no winner it's draw
            printf("It's a draw!\n");
        }
        else {
            printf("%c won the game!\n", player);//prints out the winner
            if (player == 'x'){
                win_x++;
            }
            else{
                win_o++;
            }
            
        }

        fflush(stdin);

        printf("Would You Like to Play Again (Y/N): ");
        scanf("%c", &play_again);

    } while ( toupper( play_again ) == 'Y' );


    printf("X won %d games\n", win_x);
    printf("O won %d games\n", win_o);

    printf("You Played %d games!\n", num_games_played);
  
  return 0;
}


void init_board(){

    for (int i = 0; i < 3; i++){ //starting at 0 and goes till 3
        for (int j = 0; j < 3; j++){
            board[i][j] = '.'; //initializing the board with dots 
        }
    }

}

void print_board(){

    for (int i = 0; i < 3; i++){ //starting at 0 and go till 3
        for (int j = 0; j < 3; j++){
            printf(" %c ", board[i][j]); //prints out the characters x, o for each row
        }
        printf("\n"); 
    }

}


void make_move(char player){

    int row = 0, col = 0;
    
    do {

        printf("\n%c make a move\n", player);
        
        printf("enter the row number(from 1 to 3)\n");
        scanf("%d", &row);

        printf("enter the column number(from 1 to 3)\n");
        scanf("%d", &col);


        if(!(check_if_valid(row - 1, col - 1))){//-1 because of the indexes from 0-2
            printf("Not a valid move, try again!\n");
        }
    } while (!(check_if_valid(row - 1, col - 1)));
    
    board[row - 1][col - 1] = player; //-1 so that player types 1 to 3 instead of 0 to 2 becacuse we are starting at 0

}


bool check_if_valid(int row, int col){

    if(board[row][col] == '.'){ 
        return true; //return true if the chosen row and column is not filled by either x or o
    }
    else{
        return false;
    }

}


bool check_if_win(char player){
    
    for (int i = 0; i < 3; i++){
        if ((board[i][0] == player) && (board[i][1] == player) && (board[i][2] == player)){
            return true; //checks for win horizontally
        }
        else if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)){
            return true; //checks for win diagonally
        }
        else if ((board[0][i] == player) && (board[1][i] == player) && (board[2][i] == player)){
            return true; //checks for win vertically
        }
    }
    return false;

}

