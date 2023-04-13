//Kenny Nguyen
//Takes in two strings from the user, printing the strings, then printing
//them once again but in reverse order, lastly printing it the original order

#include <iostream> 
using namespace std;

void input(string &first, string &second);
void swap_strings(string &first, string &second); 
void output(string &first, string &second);

const char SPACE = ' '; 

int main(){

string ValueOne, ValueTwo; 

cout << endl << endl; 
input(ValueOne, ValueTwo);
output(ValueOne, ValueTwo); 
swap_strings(ValueOne, ValueTwo);
output(ValueOne, ValueTwo); 
swap_strings(ValueOne, ValueTwo);
output(ValueOne, ValueTwo); 
cout << endl << endl; 

    return 0; 
}

void input(string &first, string &second){

    //Gets user input for string number 1 and 2
    //Pre: user must enter in a string 
    //Post: strings are stored in variables 
    cout << "Enter two strings (Press enter after typing your string):" << endl;
    cout << "String #1:" << SPACE; 
    cin >> first;
    cin.get();
    cout << "String #2:" << SPACE; 
    cin >> second;
    cin.get();
    cout << endl; 
}

void swap_strings(string &first, string &second){

    //Swaps the two strings given, so that the first string will be the second and vice versa 
    //Pre: variables must be strings 
    //Post: swaps the position of the strings 
    string temp = first;
    first = second;
    second = temp; 
} 

void output(string &first, string &second){

    //Prints the strings in order from whichever one is first then prints the second
    //Pre: strings have to be sorted in some way 
    //Post: strings are printed out onto the display 
    cout << first << SPACE << second << endl; 
}
