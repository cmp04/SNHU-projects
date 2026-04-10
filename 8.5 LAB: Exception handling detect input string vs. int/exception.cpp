#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main() {
   string inputName;
   int age;
   // Set exception mask for cin stream
   cin.exceptions(ios::failbit);

   cin >> inputName;
   while(inputName != "-1") {
      try {
         cin >> age;
         cout << inputName << " " << (age + 1) << endl;
      }
      catch (ios_base::failure& e) {
         cout << inputName << " " << 0 << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      cin >> inputName;

   }
   
   return 0;
}