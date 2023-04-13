// Kenny Nguyen
// list.h declares the EntryNode struct and the ToDoList class with its members and methods
#include <string>

struct EntryNode {

    std::string text;    // Represents whether or not the entry is checked
    bool        checked; // Represents the text of the entry
    EntryNode  *next;    // Identifies the node that follows the containing EntryNode instance
};

class ToDoList {

    private:
    // Indentifies the first node in a linkedlist of EntryNode instances which represents
    // the entries contained by the list
    EntryNode *head;

    public:
    ToDoList();
    ToDoList(ToDoList const &other);
    ~ToDoList();
    void add_entry(std::string text);
    void remove_entry(std::string text);
    void raise(std::string text);
    void check(std::string text);
    void uncheck(std::string text);
    void show();
    // void lower(std::string text);
};