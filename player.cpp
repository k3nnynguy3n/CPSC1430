#include "player.h"

// Sets up the palyer information
// Pre: Players must be included with a name, symbol, and points
// Post: Returns the player name, symbol, and points
Player::Player(std::string name, char symbol) {
    this->name   = name;
    this->symbol = symbol;
    points       = 0;
}

// Returns the value of symbol
// Pre: Players must be included
// Post: Returns symbol to the player
char Player::get_symbol() {
    return symbol;
}

// Increments the value of points
// Pre: Players must be included
// Post: Awards points to the player
void Player::award_point() {
    points++;
}

// Returns the value of points
// Pre: Players must be included
// Post: Returns the amount of points a player has
int Player::get_points() {
    return points;
}

// Gets users name and returns it
// Pre: Name must be a string
// Post: Returns the players name
std::string Player::get_name() {
    return name;
}

// Prints out the amount of points a player has
// Pre: None
// Post: Prints out the name of the player and how many points they have
void Player::display_score() {
    std::cout << name << " has " << points << " points" << std::endl;
}