#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
// Createfiles 'a_num' or 'b_num' based on input
// Populates the file with random numbers
void createFiles(string aORb, int numberOfFiles, int numberOfNumbers){   
    
    for(int i=0; i<numberOfFiles;i++){
        // File
        ofstream myfile;
        // File name
        string str = aORb + "_" + to_string(i) + ".txt";
        char * filename = new char [str.length()+1];
        strcpy(filename, str.c_str());
        
        // Debug
        //cout << "\n File: " << filename;
        
        //Open file
        myfile.open ( filename );
        for(int j=0;j<numberOfNumbers;j++){
            myfile << 1 << "\n";
        }
        myfile.close();
    }
}