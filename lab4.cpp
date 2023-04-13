//Kenny Nguyen
//Gets an integer from user (non-negative), followed by the exact number of those integers separated
//by white space only, prints the inputs in the reverse order they were recieved again separated by white space
//frees memory, and does not accept any input beyond the first integer 

#include <iostream>
#include <array> 

using namespace std;

int const ZERO = 0;
char const SPACE = ' '; 

//Returns a pointer to the int array with count elements allocated with new[]
//Pre: Elements must be in an array 
//Post: Stores elements as a pointer in a new array 
int* new_int_array(int count);

//De-allocated the int pointed by ptr with delete[]
//Pre: None 
//Post: Deletes the pointer to free up space 
void delete_int_array(int* array_ptr);

//Accepts a pointer, takes the count ints from user as inputs
//putting them in an array
//Pre: Elements must be a pointer
//Post: Stores user input into an array 
void read_ints(int* array_ptr, int count);

//Reverses the elements in the array_ptr array
//Pre: Elements must be in an array 
//Post: Reverses the order of the elements
void reverse(int array_ptr[], int count);

int main(){

    int count;

    cout << endl << endl; 

    cout << "Please enter a non-negative integer:" << SPACE; 
    cin >> count; 
    while(count < ZERO){
        cout << "Please enter a non-negative integer:" << SPACE; 
    cin >> count; 
    }
    
    int *arr = new_int_array(count);
    read_ints(arr, count);
    reverse(arr, count);
    cout << endl << "Reversed Output:" << SPACE << endl; 
    for(int i = 0; i < count; i++){
        cout << arr[i] << SPACE; 
    }

    cout << endl << endl << endl; 
    delete_int_array(arr);
    arr = nullptr; 

    return 0;
}

int* new_int_array(int count){
    
    return new int[count]; 
}

void delete_int_array(int* array_ptr){
  
delete[] array_ptr;
}

void read_ints(int* array_ptr, int count){

cout << "Enter" << SPACE << count << SPACE << "integers:" << SPACE; 

    for(int i = 0; i < count; i++){
        cin >> array_ptr[i];
    }
}

void reverse(int array_ptr[], int count){

int const ONE = 1; 
int const TWO = 2;

    for(int i = 0; i < count/TWO; i++){
    int temp = array_ptr[i];
    array_ptr[i] = array_ptr[count - i - ONE];
    array_ptr[count - i - ONE] = temp; 
    }
}