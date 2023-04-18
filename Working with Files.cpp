#Carisma Carter
#March 27, 2023

#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std; // included to make the name 

int main(){ //braces indicate the start and the end of the function

string cityName;
int fahrenheit,celcius; //variables to for name of city and temperature


ifstream inFile; //creating file
inFile.open("FahrenheitTemperature.txt"); //opening the file

ofstream outFile; //creating file
outFile.open("CelsiusTemperature.txt"); //creating and opening the file

if(!inFile) {
cout << "File cannot be opened." << endl;
}else{

//Loops until the file ends 
while(inFile >> cityName >> fahrenheit){  //reads the name of city and fahrenheit

celcius = (int)round(((fahrenheit - 32) * 5)/(double)9); //converts fahrenheit to celcius 
outFile << cityName << " " << celcius << endl; // the name of city and celcius value to 'CelsiusTemperature.txt' file
}
}
inFile.close(); //closes both files
outFile.close();

return 0;
}