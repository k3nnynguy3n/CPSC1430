//Kenny Nguyen
//lab1.cpp
//Description: Welcomes user and says bye, ask for input between -100 and 100,
//accepts and stores user inputted number based on the input function
//(input is stopped inf there is a negative number recieved) then prints
//the minimum, maximum and sum all of the recorded inputs, 

#include <iostream>

using namespace std; 

void welcome();
void goodbye();
int input();
void print_statistics(int value[], int count);

const char SPACE = ' ';
const int MAX_VAL = 100;
const int MIN_VAL = -100;

int main(){

  const int ARRAY_SIZE = 100;
  const int ZERO = 0; 
  int arr[ARRAY_SIZE]; 
  int count = 0; 


  welcome();
  for(int i = 0; i < ARRAY_SIZE; i++){
    arr[i] = input();
    if(arr[i] < ZERO){
    break; 
    }  
     count++;
  }
  
  print_statistics(arr,count); 
  goodbye();
  
  return 0;
}

void welcome(){

  //Prints welcome message 
  cout << endl << endl;
  cout << "Welcome to the program!";
  cout << endl << endl; 
}

void goodbye(){

  //Prints goodbye message
  cout << endl << endl;
  cout << "Goodbye! Thank you for visiting!";
  cout << endl << endl << endl; 
}

int input(){

  //requests integer from user and checks if it is in the range
  int num; 

    cout << "Please enter a number between -100 to 100:" << SPACE;
    cin >> num;
    if(num > MAX_VAL || num < MIN_VAL){
      cout << "Invalid input, please try again" << endl;
      num = 0;
    }
    
  return num; 
}

void print_statistics(int values[], int count){

  int total = 0;
  int MinNum = 0;
  int MaxNum = 0;
  
  //Finds the minimum, maximum, and the sum
  for(int i = 0; i < count; i++){
    if(values[i] < values[MinNum]){
      MinNum = i;
    }
    if(values[i] > values[MaxNum]){
      MaxNum = i;
    }
    total += values[i];
  }
  
  cout << endl << "Minimum Value:" << SPACE << values[MinNum] << endl;
  cout << "Maximum Value:" << SPACE << values[MaxNum] << endl;
  cout << "Sum of all Numbers:" << SPACE << total << endl;   

}
