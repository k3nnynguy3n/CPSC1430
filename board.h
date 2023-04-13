#include "player.h"

class Board {

    private:
    // Members
    char       **squares;
    unsigned int size;
    bool         take_turn = true;

    public:
    // Methods
    void clearscreen();
    void display();
    void get_input(Player &player);
    bool is_full();
    bool is_winner(Player player);

    // Constructor
    Board(unsigned int size);

    // Deconstructor
    ~Board();
};