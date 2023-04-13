//Kenny Nguyen
//Desc. this program will read in from a file and sort the file into
//three different arrrays depending if the numbers are divisible by 2, 3, and
//other. Once the numbers are in the right array, the numbers will be printed
//in the same order that they were in for the text file. 

#include <iostream> 
#include <fstream> 

using namespace std;

bool is_even(unsigned int value);
bool is_threeven(unsigned int value);
void print_list(unsigned int list[], unsigned int count);

const int MAX_NUMBERS = 30;

int main(){

    const string FILENAME = "numbers.txt";
    int even_count = 0;
    int three_even_count = 0;
    int other_count = 0; 
    int current_num;
    unsigned int even_list[MAX_NUMBERS];
    unsigned int threeven_list[MAX_NUMBERS];
    unsigned int other_list[MAX_NUMBERS];

    ifstream infile; 
 
    infile.open(FILENAME);
    if(infile.fail()){
    cout << "file error...exiting program...press enter...";
    cin.get();

    return 0;
  }

  cout << endl << endl << endl; 

    while(infile >> current_num){
        if(is_even(current_num)){
            even_list[even_count] = current_num;
            even_count++;
        
        }else if(is_threeven(current_num)){
            threeven_list[three_even_count] = current_num;
            three_even_count++;
       
       }else{
            other_list[other_count] = current_num;
            other_count++;
        }
    }
    infile.close();

    cout << "Numbers divisible by 2:" << endl; 
    print_list(even_list, even_count);
    cout << endl << endl;
    cout << "Numbers divisible by 3:" << endl;
    print_list(threeven_list, three_even_count);
    cout << endl << endl;
    cout << "Other:" << endl; 
    print_list(other_list, other_count);
    cout << endl << endl << endl; 

    return 0; 
}

//Pre: Number must be an unsigned integer
//Post: Determine whether the number is divisible by 2
bool is_even(unsigned int value){

    bool is_even = false; 
    int two = 2; 

    if(value % two == 0){
       return is_even = true; 

    }else{
        return is_even = false;
    }
}

//Pre: Number must be an unsigned integer
//Post: Determine whether the number is divisible by 3 
bool is_threeven(unsigned int value){
    
    bool is_threeven = false; 
    int three = 3; 

    if(value % three == 0){
        return is_threeven = true; 
   
   }else{
        return is_threeven = false;
    }

}

//Pre: Needs an array, and a counter variable 
//Post: Prints out the desired array, in order with commas between and printing the last index on a newline 
void print_list(unsigned int list[], unsigned int count){
    
    const char SPACE = ' '; 
    const char COMMA = ','; 
    const int ONE = 1; 

    for(unsigned int i = 0; i < count && i < MAX_NUMBERS; i++) {
       if(i < count - ONE){
        cout << list[i] << COMMA << SPACE;
       }else{ 
        cout << endl << list[i];
       }
       
    }
}
