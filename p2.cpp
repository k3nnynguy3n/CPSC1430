// Kenny Nguyen
// This is a program that allows its user to alter, resize, save, and load grids of characters based on the user input
// and what they would like.

#include <fstream>
#include <iostream>
#include <string>

struct TextGrid {
    char       **tiles;
    unsigned int height;
    unsigned int width;
};

// Loads the grid from the file
// Pre: None
// Post: Returns a TextGrid that contains the file of the file_path as a 2D array
TextGrid load_grid(std::string file_path);

// Saves the grid whenever the user would like to and pushes the progress to a file where
// it can be recovered
// Pre:
// Post: Saves the contents of the grid to file_path, saing each row as a line in the file
void save_grid(TextGrid &grid, std::string file_path);

// Writes the value to fill the given char to the y amount of rows and x amount of columns
// of the grid
// Pre: Input must be a char, and given coordinates must be in the bounds of the grid
// Post:
void paint(TextGrid &grid, unsigned int x, unsigned int y, char fill);

// Shows the grid, with the updated changes
// Pre: contents of the dynamic array must be valid
// Post: prints the contents of the dynamic array, with a newline after each row
void show(TextGrid &grid);

// Adds a column to the right side of the grid, with the desired char that the user would like
// Pre: User must enter a char
// Post: Adds a column using the char that the user inputted
void add_column(TextGrid &grid, char fill);

// Removes a column from the right side of the grid
// Pre: There must be columns available to delete
// Post: Removes a column from the right side
void remove_column(TextGrid &grid);

// Adds a row to the bottom of the grid with the char that the user chooses
// Pre: Char must be entered
// Post: Adds a row to the bottom of the grid filled with the char the user entered
void add_row(TextGrid &grid, char fill);

// Removes a row from the bottom of the grid
// Pre: There must be rows available to delete
// Post: Removes a row from the bottom of the grid
void remove_row(TextGrid &grid);

// Takes the input from the user "replace" and replaces it with that character at every instance
// of the target character
// Pre: Inputs must both be chars
// Post: Replaces the chosen character with inputted character
void transform(TextGrid &grid, char target, char replace);

// Checks to see if the file can open
// Pre: Checks file
// Post: Checks if a file is able to be able and returning true or false
bool is_bad();

// Deallocates allocated grid
//  Pre: Grid must be allocated
//  Post: Deallocates the grid that has been passed into the function
void delete_grid(TextGrid &grid);

int  main() {

     // Initializes a grid 16-wide and 8-high with tick marks, also shows the 'show' function
    // to display the grid sate to the user then accepts the command.
    // Pre: None
    // Post: Updates and prints the board based on the user input

    std::string file_path = "/home/st/knguyen26/cs2/file_path";
    char const  TICK      = '`';
    int const   WIDTH     = 16;
    int const   HEIGHT    = 8;

    // Initializing the 16x8 grid with tick marks
    TextGrid grid;
    grid.height = HEIGHT;
    grid.width  = WIDTH;
    grid.tiles  = new char *[grid.width];
    for (unsigned int i = 0; i < grid.width; i++) {
         grid.tiles[i] = new char[grid.height];
         for (unsigned int k = 0; k < grid.height; k++) {
             grid.tiles[i][k] = TICK;
        }
    }

    while (true) {

         std::cout << std::endl << std::endl;
         show(grid);
         std::cout << std::endl;

         std::string command;
         std::cin >> command;
         if (command.size() != 1) {
             std::cout << "Invalid input" << std::endl;
        }

         // Checks for user input and returns on the action based on what the user wants
         switch (command[0]) {

         // Quits
         case 'Q':
            delete_grid(grid);
            return 0;

            // Paints a char at a location
         case 'P': {
             int  x, y;
             char c;
             std::cin >> x >> y >> c;
             if (!is_bad()) {
                paint(grid, x, y, c);
                break;
            }
        }

            // Transforms the board
         case 'T': {
             char t, r;
             std::cin >> t >> r;
             transform(grid, t, r);
             break;
        }

            // Loads the previous or most recent saved grid in the file
         case 'L':
            std::cin >> file_path;
            delete_grid(grid);
            grid = load_grid(file_path);
            break;

            // Saves the grid
         case 'S':
            std::cin >> file_path;
            save_grid(grid, file_path);
            break;

            // Adds row with given char
         case 'R': {
             char k;
             std::cin >> k;
             add_row(grid, k);
             break;
        }

            // Removes row
         case 'r':
            remove_row(grid);
            break;

            // Adds column with given char
         case 'C': {
             char z;
             std::cin >> z;
             add_column(grid, z);
             break;
        }

            // Removes column
         case 'c':
            remove_column(grid);
            break;
        }
    }

    return 0;
}

TextGrid load_grid(std::string file_path) {

    TextGrid      grid;
    std::string   line;
    std::ifstream file;
    file.open(file_path);
    grid.height = 0;
    grid.width  = 0;

    // Gets the height and width of the grid
    while (getline(file, line)) {
        grid.height++;
        grid.width = line.size();
    }

    // Allocates and sets the width of the grid
    grid.tiles = new char *[grid.width];
    for (unsigned int i = 0; i < grid.width; i++) {
        grid.tiles[i] = new char[grid.height];
    }

    // Clears the grid so that it is starting at the top again
    file.clear();
    file.seekg(0, std::ios::beg);

    // Gets the lines and copies them into the grid
    for (unsigned int k = 0; k < grid.height; k++) {
        std::getline(file, line);
        for (unsigned int e = 0; e < grid.width; e++) {
            grid.tiles[e][k] = line[e];
        }
    }

    file.close();

    return grid;
}

void save_grid(TextGrid &grid, std::string file_path) {

    std::ofstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Error" << file_path << std::endl;
    }

    // Puts the elements in the grid array into the file
    for (unsigned int k = 0; k < grid.height; k++) {
        for (unsigned int i = 0; i < grid.width; i++) {
            file << grid.tiles[i][k];
        }
        file << std::endl;
    }
    file.close();
}

void paint(TextGrid &grid, unsigned int x, unsigned int y, char fill) {

    // Checks if the user input is valid
    // If the user input is valid then replace the tile with the given input with the given char
    if (x >= grid.width || y >= grid.height) {
        return;
    }
    grid.tiles[x - 1][y - 1] = fill;
}

void show(TextGrid &grid) {

    for (unsigned int i = 0; i < grid.height; i++) {
        for (unsigned int k = 0; k < grid.width; k++) {
            std::cout << grid.tiles[k][i];
            // Prints the grid
        }
        std::cout << std::endl;
        // Prints a new line a the end of every row
    }
}

void add_column(TextGrid &grid, char fill) {

    unsigned int new_width = grid.width + 1;
    char       **new_tiles = new char *[new_width];

    for (unsigned int i = 0; i < grid.width; ++i) {
        new_tiles[i] = new char[grid.height];
        for (unsigned int j = 0; j < grid.height; j++) {
            new_tiles[i][j] = grid.tiles[i][j];
        }
    }

    new_tiles[new_width - 1] = new char[grid.height];

    for (unsigned int k = 0; k < grid.height; k++) {
        new_tiles[new_width - 1][k] = fill;
    }

    delete_grid(grid);

    grid.width = new_width;

    grid.tiles = new_tiles;
}

void remove_column(TextGrid &grid) {

    int const ZERO = 0;

    if (grid.height == ZERO) {
        std::cout << "You can not remove a column because there are no columns to delete" << std::endl;
        return;
    }

    char **new_tiles = new char *[grid.width - 1];
    for (unsigned int i = 0; i < grid.width - 1; i++) {
        new_tiles[i] = new char[grid.height];
    }

    for (unsigned int k = 0; k < grid.width - 1; k++) {
        for (unsigned int n = 0; n < grid.height; n++) {
            new_tiles[k][n] = grid.tiles[k][n];
        }
    }

    delete_grid(grid);

    grid.tiles = new_tiles;
    grid.width--;
}

void add_row(TextGrid &grid, char fill) {

    unsigned int new_height = grid.height + 1;
    char       **new_tiles  = new char *[grid.width];

    for (unsigned int i = 0; i < grid.width; ++i) {
        new_tiles[i] = new char[new_height];
        for (unsigned int j = 0; j < grid.height; ++j) {
            new_tiles[i][j] = grid.tiles[i][j];
        }
        new_tiles[i][new_height - 1] = fill;
    }

    grid.height = new_height;

    delete_grid(grid);

    grid.tiles = new_tiles;
}

void remove_row(TextGrid &grid) {

    int const ZERO = 0;

    if (grid.width == ZERO) {
        std::cout << "You can not remove a column because there are no rows to delete" << std::endl;
        return;
    }

    char **new_tiles = new char *[grid.width];
    for (unsigned int i = 0; i < grid.width; i++) {
        new_tiles[i] = new char[grid.height - 1];
    }

    for (unsigned int k = 0; k < grid.width; k++) {
        for (unsigned int n = 0; n < grid.height - 1; n++) {
            new_tiles[k][n] = grid.tiles[k][n];
        }
    }

    delete_grid(grid);

    grid.tiles = new_tiles;
    grid.height--;
}

void transform(TextGrid &grid, char target, char replace) {

    for (unsigned int i = 0; i < grid.width; i++) {
        for (unsigned int n = 0; n < grid.height; n++) {
            if (grid.tiles[i][n] == target) {
                grid.tiles[i][n] = replace;
            }
        }
    }
}

bool is_bad() {

    bool bad = std::cin.fail();
    if (bad) {
        std::cin.clear();
        std::cin.ignore();
    }
    return bad;
}

void delete_grid(TextGrid &grid) {

    for (unsigned int i = 0; i < grid.width; i++) {
        delete[] grid.tiles[i];
    }
    delete[] grid.tiles;
}