//Created 9/13/2023 by Ethan Larson
//tolowercase guide by Safa Mulani: digitalocean.com/community/tutorials/string-uppercase-lowercase-c-plus-plus
#include <iostream>
#include <cstring>

using namespace std;

int main() {

  char input[81];
  char reversed[81];
  bool isPalindrome = true;

  cout << "ask for input ";
  
  cin.get(input, 81);
  cin.get();
  int count = 0;

  cout << "input typed: ";
  cout << input << endl;

  for (int i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
  }

  cout << "lowered input test: ";

  cout << input << endl;
  
  cout << "removing non letters ";
  
  for (int i = 0; i < 81; i++) {
    if (input[i] != '\0') { //keeps the null character
      if (input[i] <= 'z' && input[i] >= 'a') {//for every letter
	//input[count] = input[i];
	//count++;
      }
      else {//everytime there's a non letter, do this

	for (int j = i; j < 81; j++) {
	  input[j] = input[j+1]; //effectively deletes the non-letter by moving the whole array back one
	  if (!(input[i] <= 'z' && input[i] >= 'a')) {
	    i--;
	  }
	}
      }
    }
  }

  cout << input << endl;
  //we can now assume our charray (haha) is now all lowercase with only letters

  for (int i = 0; i < strlen(input); i++) {
    if (input[strlen(input)-i-1] != '\0') {
      reversed[i] = input[strlen(input)-i-1];
      
    }
    else {
      i++;
    }
  }
  reversed[strlen(input)] = '\0';

  cout << "reversed: ";
  cout << reversed << endl;

  for (int i = 0; i < strlen(input); i++) {
    if (reversed[i] != input[i]) {
      isPalindrome = false;
    }
  }

  if (isPalindrome) {
    cout << "It's a palindrome!";
  }
  else {
    cout << "It's not a palindrome.";
  }
  
  return 0;
}
