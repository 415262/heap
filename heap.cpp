/*Max heap started 2/14/2024 
Be able to enter series of numbers via array
Cannot Input from file
Ethan Larson 2024
*/


#include <iostream>
using namespace std;

int heap[101];
string input;
int intput = 0;

void makeDefault(int heap[101]);
void print(int index, int count, int end, int head);
void addInit(int value);
void addRecurs(int index);
void delInit();
void delRecurs(int index);
void shiftTree(int index);

int main() {
  cout << "Begin Process" << endl;
  while (input != "quit") {
    cout << "You can type 'add' or 'deleteRoot' or 'print', you can 'default' heap, you can 'deleteAll' or 'quit' program." << endl;
    cin >> input;
    if (input == "file") {

    }
    else if (input == "add") {
      cout << "Type the number you wish to add to the heap:" << endl;
      cin >> intput;
      addInit(intput);
      cout << "Added." << endl;
    }
    else if (input == "deleteRoot") {
      cout << "Deleting Root..." << endl;
      delInit();
      shiftTree(2);
      cout << " Deleted." << endl;
    }
    else if (input == "print") {
      cout << "Printing heap..." << endl;
      print(1, 0, 101, 1);
      cout << "End of heap." << endl;
    }
    else if (input == "default") {
      makeDefault(heap);
      continue;
    }
    /*   else if (input == "file") {
      fstream fileStream;
      fileStream.open("file.txt");
      while (fileStream >> heap) {
	fileStream >> heap;
      }
    
    }
    */
    else if (input == "deleteAll") {
      cout << "Deleting all..." << endl;
      for (int i = 1; i < 101; i++) {
	if (heap[1] != 0) {
	delInit();
	shiftTree(2);
	}
	continue;
      }
      cout << endl << "Tree deleted." << endl;
    }
    else if (input == "quit") {
      return 0;
    }
    else {
      continue;
    }
  }
  cout << "End Process.";
  return 0;
}

void makeDefault(int heap[101]) {
  for (int i = 1; i < 101; i++) {
    heap[i] = 101-i;
  }
  cout << "Default heap created." << endl;
}

void addInit(int value) {
  int index = 0;
  for (int i = 1; i < 101; i ++) {
    if (heap[i] == 0) {
      heap [i] = value;
      i = index;
      break;
    }
  }
  addRecurs(index);
}

void addRecurs(int index) {
  
  int temp = 0;
  int pindex = (index/2);
  int lindex = (index*2);
  int rindex = ((index*2)+1);

  //check if bigger than parent

  if (heap[pindex] < heap[index]) {
    temp = heap[pindex];
    heap[pindex] = heap[index];
    heap[index] = temp;
    addRecurs(pindex);
  }
  
}

void delInit() {
  cout << endl << heap[1];
  int index = 1;
  while (heap[index] > heap[(index*2)+1]) {//goes to right most child
    index = (index*2)+1;
  }
  heap[1] = heap[index];
  heap[index] = 0;
  delRecurs(1);
}

void delRecurs(int index) {
  if (heap[index] != 0) {
    int lindex = (index*2);
    int rindex = ((index*2)+1);
    int temp = 0;

    if (heap[rindex] > heap[lindex]) {//right is bigger
      if (heap[index] < heap[rindex]) {//parent smaller than right child
	temp = heap[index];
	heap[index] = heap[rindex];
	heap[rindex] = temp;	
	delRecurs(rindex);        
      }
      else {
	if (heap[index] < heap[lindex]) {//parent smaller than left child
	  temp = heap[lindex];
	  heap[index] = heap[lindex];
	  heap[lindex] = temp;
	  addRecurs(lindex);	  
	}
      }
    }
    else if (heap[rindex] > heap[lindex]) {//left is bigger
      if (heap[index] < heap[lindex]) {//parent smaller than left child
	temp = heap[index];
	heap[index] = heap[lindex];
	heap[lindex] = temp;
	delRecurs(lindex);
      }
      else {
	if (heap[index] < heap[rindex]) {//parent smaller than right child
	  temp = heap[rindex];
	  heap[index] = heap[rindex];
	  heap[rindex] = temp;
	  addRecurs(rindex);
	}
      }
    }
  }
  return;
}

void shiftTree(int index) {//assume previous is empty, set that to current, and set current to empty
  heap[index-1] = heap[index];
  if (heap[index+1] != 0) {
    heap[index] = 0;
    index++;
    shiftTree(index);
  }
  else {
  heap[index] = 0;
  }
  return;
}


void print(int index, int count, int end, int head) {
  
  if ((index*2)+1 < end) {
    print ((index*2)+1, count+1, end, head);
  }
  for (int i = 0; i < count; i++) {
    cout << '\t';

  }
  cout << heap[index] << endl;
  
   if ((index*2) < end) {
    print ((index*2), count + 1, end, head);
  }
  
}
