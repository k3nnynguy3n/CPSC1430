// Kenny Nguyen
// Tic-Tac-Toe with classes

#include "board.h"
#include "player.h"
#include <iostream>
#include <string>

// Runs the game tic tac toe, allows user to pick board size
// Pre: board.h and player.h files were inlcluded
// Post: Runs the tic-tac-toe game, until the user decides to quit the program
int main() {

    unsigned int size;
    char         p1_symbol = 'X';
    char         p2_symbol = 'O';
    std::string  p1_name, p2_name;

    // Welcome message
    std::cout << std::endl << std::endl;
    std::cout << "Welcome to tic-tac-toe!" << std::endl;
    std::cout << std::endl << std::endl;

    // Getting player one's information
    std::cout << "Please enter the name for player one: ";
    std::cin >> p1_name;
    std::cout << p1_name << " you have been assigned X" << std::endl << std::endl;

    // Getting player two's information
    std::cout << "Please enter the name for player two: ";
    std::cin >> p2_name;
    std::cout << p2_name << " you have been assigned O" << std::endl << std::endl;

    // Sets board size, and player symbols and names
    Player p1        = Player(p1_name, p1_symbol);
    Player p2        = Player(p2_name, p2_symbol);

    bool   play_game = true;
    while (play_game) {

        // Gets the board size information
        std::cout << std::endl;
        std::cout << "Enter the size of the board (3 for 3x3, 4 for 4x4, 5 for 5x5 and so on): ";
        std::cin >> size;
        std::cout << std::endl << std::endl;

        Board board = Board(size);
        board.display();
        int turn = 0;

        while (board.is_full() != true && board.is_winner(p1) != true && board.is_winner(p2) != true) {

            // Take turn
            if ((turn % 2) == 0) {
                board.get_input(p1);
                turn++;
            } else {
                board.get_input(p2);
                turn++;
            }
            board.display();
        }

        // Check for a winner
        if (board.is_winner(p1)) {
            std::cout << p1.get_name() << " wins!" << std::endl;
            p1.award_point(); // increment winning player's score

        } else if (board.is_winner(p2)) {
            std::cout << p2.get_name() << " wins!" << std::endl;
            p2.award_point(); // increment winning player's score

        } else {
            std::cout << "It's a tie!" << std::endl;
        }

        // Display scores
        p1.display_score();
        p2.display_score();

        // Quit command
        std::cout << "Press 'Q' followed by enter to quit or enter any character to play again:";
        std::cout << std::endl << "Answer: ";
        std::string command;
        std::cin >> command;
        if (command == "Q") {
            return 0;
        }
    }

    return 0;
}
