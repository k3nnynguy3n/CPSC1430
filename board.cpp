#include "board.h"
#include <iomanip>
#include <iostream>

// Displays the board state through std::cout
// Pre: None
// Post: Displays the current state of the board
void Board::display() {

    int const  COL_SPACE = 5;
    char const SPACE     = ' ';
    char const BRACKET   = '|';

    // Displays the most current board
    for (unsigned int i = 0; i < size; i++) {
        std::cout << std::setw(COL_SPACE) << i;
    }
    std::cout << std::endl;

    for (unsigned int k = 0; k < size; k++) {
        std::cout << k;
        for (unsigned int e = 0; e < size; e++) {
            std::cout << SPACE << SPACE << BRACKET << squares[k][e] << BRACKET;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

// Returns true if the board is full of player symbols
// Pre: Must be a board to check if the board is full or not
// Post: Returns either true or false if the board is full or not
bool Board::is_full() {

    // Checks if the entire board is full,
    // if so then the method returns true, and the game ends
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int k = 0; k < size; k++) {
            if (squares[i][k] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Returns whether or not player won the game based off of the board state.
// Pre: player type must be passed in
// Post: Returns true or false if the game has been won by one of the players
bool Board::is_winner(Player player) {

    char symbol = player.get_symbol();

    // Checks horizontals
    for (unsigned int i = 0; i < size; i++) {
        bool row_win = true;
        for (unsigned int k = 0; k < size; k++) {
            if (squares[i][k] != symbol) {
                row_win = false;
                break;
            }
        }
        if (row_win) {
            return true;
        }
    }

    // Checks columns
    for (unsigned int e = 0; e < size; e++) {
        bool column_win = true;
        for (unsigned int q = 0; q < size; q++) {
            if (squares[q][e] != symbol) {
                column_win = false;
                break;
            }
        }
        if (column_win) {
            return true;
        }
    }

    // Checks diagonals
    bool         left_diagonal_win  = true;
    bool         right_diagonal_win = true;
    unsigned int d1_symbol_count    = 0;
    unsigned int d2_symbol_count    = 0;

    for (unsigned int o = 0; o < size; o++) {
        if (squares[o][o] != symbol) {
            left_diagonal_win = false;
        } else {
            d1_symbol_count++;
        }
        if (squares[o][size - o - 1] != symbol) {
            right_diagonal_win = false;
        } else {
            d2_symbol_count++;
        }
    }

    if (d1_symbol_count == size) {
        return true;
    }
    if (d2_symbol_count == size) {
        return true;
    }
    if (left_diagonal_win || right_diagonal_win) {
        return true;
    }

    return false;
}

//(Constructor) handles allocation of the memory used by the instance,
// creating a board which is size squares wide and size squares high.
// Pre: User must have entered size for this method to allocate a board of inputted size
// Post: Allocates a board of size height and size width based off of the user input
Board::Board(unsigned int size) {

    // Sets user inputted size into size, and allocates the board
    this->size = size;
    squares    = new char *[size];
    for (unsigned int i = 0; i < size; i++) {
        squares[i] = new char[size];
        for (unsigned int k = 0; k < size; k++) {
            squares[i][k] = ' ';
        }
    }
}

//(Destructor) handles deallocation of the memory used by the instance
// Pre: There must be a board to deallocate
// Post: Deallocates the memory that is no longer needed
Board::~Board() {

    // Deallocates the board
    for (unsigned int i = 0; i < size; i++) {
        delete[] squares[i];
    }
    delete[] squares;
}

// Clears the screen
// Pre: None
// Post: Prints out 50 newlines
void clearscreen() {

    int const FIFTY = 50;

    for (int i = 0; i < FIFTY; i++) {
        std::cout << std::endl;
    }
}

// Gets the input of the users and stores it into the squares board
// Pre: input must be an int corressponding to the rows and columns on the board
// Post: Stores the user input into squares
void Board::get_input(Player &player) {

    unsigned int row, col;
    char const   SPACE = ' ';

    // Gets user input on the spot on the board they would like to place their symbol
    std::cout << player.get_name() << ", it's your turn!" << std::endl;
    std::cout << "Please pick a row: ";
    std::cin >> row;
    std::cout << "Please pick a column: ";
    std::cin >> col;
    std::cout << std::endl;

    // Checks input
    while (row > size && col > size && squares[row][col] != SPACE) {
        std::cout << "Invalid coordinates, please pick again" << std::endl;
        std::cout << "Please pick a row: ";
        std::cin >> row;
        std::cout << "Please pick a column: ";
        std::cin >> col;
        std::cout << std::endl;
    }

    // If the spot on the square has a space it can be occupied
    if (squares[row][col] == SPACE) {
        squares[row][col] = player.get_symbol();

    } else {
        // if not then the spot has already been taken
        std::cout << "That spot is already taken, please try again" << std::endl;
        get_input(player);
    }
}