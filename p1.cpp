//Kenny Nguyen
//Code for the game tic-tac-toe, to win a player must have 3 of there shape in a row which can be
//placed veritcally, horizontally, and or diagonally. 

#include <iostream> 
#include <iomanip> 

using namespace std; 

struct PlayerInfo{
    string name; 
    char symbol;
};

int const ROWS = 3;
int const COLS = 3; 
int const ZERO = 0;
int const ONE = 1; 
int const TWO = 2; 
int const MAXPLAYERS = 2; 
char const SPACE = ' ';
char const SYMBOL_X = 'X';
char const SYMBOL_O = 'O';

//Prints welcome message for users and prints the win conditons as well 
//Pre: None 
//Post: None
void welcome();

//Prints goodbye message for user 
//Pre: None 
//Post: None
void goodbye();

//Clears the previous screen so user can easily see the new board position
//Pre: None
//Post: None
void clearscreen();

//Prints the tic tac toe grid 
//Pre: The 2D array must be chars and [3][3] in size
//Post: Displays the game board   
void display(char board[][COLS]);

//Gets users names and assigns them with a character to play with
//Pre: Players names must be strings
//Post: Stores information into the players struct and assigns them a character either X or O 
void get_player_info(PlayerInfo players[]); 

//Gets the players pick of what row and column they would like to place their char
//Pre: Players must choose a spot on the board that exists 
//Post: Marks the spot on the board that the player would like to place their symbol  
void get_pick(char board[][COLS], bool take_turn, PlayerInfo players[]);

//Checks the location of a players board for any 3 in a row in either the vertical, horizontal, or diagonal lines
//Pre: User must have enter valid and existing position on the board
//Post: Determines if the game has been won, by checking 3 in a row in either of the 
//3 patterns: horizontal, vertical, diagonal
bool check_win(char board[][COLS], char symbol);

int main(){

    char const YES = 'y';
    char ans = 'y'; 
    char current_symbol;
    bool take_turn = true;
    
    char board[ROWS][COLS]; 
    PlayerInfo players[MAXPLAYERS];

    welcome(); //Welcomes the player(s)
    get_player_info(players); //Get player(s) name
    for (int i = 0; i < ROWS; i++){ //Initializes the board 
        for (int j = 0; j < COLS; j++){
        board[i][j] = SPACE;
        }
    }
    
    players[ZERO].symbol = SYMBOL_X; //assigns player with symbol and stored into the players struct 
    players[ONE].symbol = SYMBOL_O;
    bool game_not_won = true; 

    while(tolower(ans) == YES){ //While loop to reiterate if they would like to play again
        while(game_not_won){

            clearscreen(); //clears screen 
            display(board);

            if(take_turn){ //taketurn allows for players to alternate turns 
                cout << players[ZERO].name << SPACE << "its your turn!" << endl;
                current_symbol = players[ZERO].symbol; //mentions whos turn it is at the start of each turn, and symbol
                cout << players[ZERO].name << SPACE << "you are" << SPACE << players[ZERO].symbol << endl << endl; 
            }else{
                cout << players[ONE].name << SPACE << "its your turn!" << endl;
                current_symbol = players[ONE].symbol;
                take_turn = false; 
                cout << players[ONE].name << SPACE << "you are" << SPACE << players[ONE].symbol << endl << endl;  
            }
         
            get_pick(board, take_turn, players); //gets the player pick 
            if(check_win(board, current_symbol)){ //checks win 
                display(board); 
                game_not_won = false;
                cout << "Congratulations, you won!" << endl << endl;
            }
            
            bool is_tie = true; //checks for a tie in the game
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    if(board[i][j] == SPACE){ //check if the game is a tie 
                        is_tie = false;
                        break;
                    }
                }
            }
            if(is_tie){ 
                game_not_won = false;
                cout << "Its a tie!" << endl << endl;
        }

            if(take_turn == true){ //Alternates turns for each player after one player has picked a spot on the board 
                take_turn = false; 
            }else{
                take_turn = true; 
            }
            
        }
        cout << "Do you want to play again? (y/n):" << SPACE; //Asks if the user would like to play again
        cin >> ans; //Stores the response of the player and repeats the game if they would like
        
        if(tolower(ans) == YES){
            game_not_won = true; 
            take_turn = true; 
            for (int i = 0; i < ROWS; i++){ //Initializes the board 
                for (int j = 0; j < COLS; j++){
                    board[i][j] = SPACE;
                }
            }
        }else{

            goodbye(); //goodbye message
        }
    }

    return 0; 
    
}

 //Welcomes message 
void welcome(){
    
    cout << endl << endl << "Welcome to tic-tac-toe!" << endl << endl;
}

//Says goodbye to user
void goodbye(){
 
    cout << endl << endl << "Thank you for playing, goodbye!" << endl << endl;
}

//Gets the names of the two players and stores them into their player struct, 
//the x's and o's are also assigned to the players
void get_player_info(PlayerInfo players[]){

    char const MAXPLAYERS = 2; 

    cout << "Enter names for each player then press enter to submit" << endl << endl;

    for(int i = 0; i < MAXPLAYERS; i++){
        cout << "Please enter name for" << SPACE << "player" << SPACE << i + 1 << ":" << SPACE; 
        getline(cin, players[i].name);
    }
    cout << endl << endl; 
}


//Prints the board for the game and determines coordinates for the X's and O's
void display(char board[][COLS]){

    char const BRACKET = '|';
    char const SPACE = ' ';
    int const RowNCol = 3; 
    int ColSpace = 5; 

    for(int i = 0; i < RowNCol; i++){
    cout << setw(ColSpace) << i;
    }
    cout << endl; 

    for(int k = 0; k < RowNCol; k++){
        cout << k;
        for(int e = 0; e < RowNCol; e++){
        cout << SPACE << SPACE << BRACKET << board[k][e] << BRACKET; 
        }
        cout << endl;
    }
    cout << endl << endl;
}

//Ask user for spot selection during their turn, and checks if the coordinate is valid
void get_pick(char board[][COLS], bool take_turn, PlayerInfo players[]){
    
    int row;
    int col;

    cout << "Please pick a row:" << SPACE;
    cin >> row;
    cout << "Please pick a column:" << SPACE;
    cin >> col;
    cout << endl;
    
    while(row < ZERO && row > ROWS && col < ZERO && col > COLS && board[row][col] != SPACE){
        cout << "Invalid coordinates, please pick again" << endl;
        cout << "Please pick a row:" << SPACE;
        cin >> row;
        cout << "Please pick a column:" << SPACE;
        cin >> col;
        cout << endl; 
    }

    if (board[row][col] == SPACE) {
        if(take_turn){
            board[row][col] = players[ZERO].symbol;
        } else {
            board[row][col] = players[ONE].symbol;
        }

    } else {
        cout << "That spot is already taken, please try again" << endl;
        get_pick(board, take_turn, players);
    }

    if(take_turn){
        board[row][col] = players[ZERO].symbol;
    }else{
        board[row][col] = players[ONE].symbol;
    }
}

//Checks if a player has won, checking the veritcal, horizontal, and diagonal matches 
bool check_win(char board[][COLS], char symbol){

    //Checks the rows
    for(int i = 0; i < ROWS; i++){
        if(board[i][ZERO] == symbol && board[i][ONE] == symbol && board[i][TWO] == symbol){
            return true; 
        }
    }

    //Checks the columns 
    for(int k = 0; k < COLS; k++){
        if(board[ZERO][k] == symbol && board[ONE][k] == symbol && board[TWO][k] == symbol){
            return true;
        }
    }
    
    //Checks the diagonals
    if(board[ZERO][ZERO] == symbol && board[ONE][ONE] == symbol && board[TWO][TWO] == symbol){
        return true; 
    }
    if(board[TWO][ZERO] == symbol && board[ONE][ONE] == symbol && board[ZERO][TWO] == symbol){
        return true; 
    }

    return false; 
}

//Clears screen 
void clearscreen(){

    int const fifty = 50; 

    for(int i = 0; i < fifty; i++){
        cout << endl; 
    }
}