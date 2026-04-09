#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
   fstream inFS;
   ofstream outFS;
   string city;
   double temp;
   int i;
   //lists for the temps and citys
   vector<double> tempsList;
   vector<string> cityList;

   //open the file
   inFS.open("FahrenheitTemperature.txt");

   //if there is an error display a message
   if(!inFS.is_open()) {
      cout << "Could not read file" << endl;
      return 1;
   }
   //get the input from the txt file
   else {
      inFS >> city;
      inFS >> temp;
      while (!inFS.fail()) {
         //convert F to C
         temp = (temp - 32) * 5 / 9;
         tempsList.push_back(temp);
         cityList.push_back(city);
         inFS >> city;
         inFS >> temp;
      }

   }
   //close the file
   inFS.close();

   //open and create a new txt file
   outFS.open("CelsiusTemperature.txt");  

   if (!outFS.is_open()) {
      cout << "Could not create file" << endl;
   }

   //write each new line with the C temperature  
   for (i = 0; i < tempsList.size(); i++) {
      outFS << cityList.at(i) << " " << fixed << setprecision(2) << tempsList.at(i) << endl;
   }
   
   //close the file
   outFS.close();
   cout << "File written and closed";

}