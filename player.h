#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <ostream>
#include <string>

class Player {

    private:
    // Members
    char        symbol;
    int         points;
    std::string name;

    public:
    // Methods
    Player(std::string name, char symbol);
    char        get_symbol();
    void        award_point();
    void        display_score();
    int         get_points();
    std::string get_name();
};

#endif