#include <iostream>
#include <string>
using namespace std;

int main() {
  // creation a string
  string mystring = "Hello";

  // to change the 0 index (i.e H) of the string to T
  mystring[0] = 'T';
  cout << mystring;
  return 0;
}
