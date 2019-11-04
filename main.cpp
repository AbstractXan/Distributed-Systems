#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "include.h"
#include <math.h>
#include <fstream>
using namespace std;

// Data to be passed onto thread
// File Name

struct total_runner_struct{
    int index;
    string aORb;
    int numbersPerThread;
    int numberOfThreads;
    int numberOfFiles;
    int numbersPerFile;
    int answer;
};

void total(struct total_runner_struct* arg_struct){
    // struct total_runner_struct *arg_struct = (struct total_runner_struct*) arg;
    
    int index = arg_struct->index;
    int count_numbers = arg_struct->numbersPerThread; 
    int limit = index + count_numbers;
    int total = 0;
    // Decrement numbers according to targetted numbers per thread
    while(index < limit){
        // open file by file number
        int current_file_number = ceil( ((float) index)/( (float) arg_struct->numberOfFiles));
        string str = arg_struct->aORb + "_" + to_string(current_file_number) + ".txt";
        char * filename = new char [str.length()+1];
        strcpy(filename, str.c_str());
        std::ifstream infile(filename);

        //Reach index
        int fileStartIndex = (current_file_number-1)*(arg_struct->numbersPerFile)+1;
        //cout << "FileStartIndex: " << fileStartIndex << "\n";
        for(int i=fileStartIndex;i<index;i++){
            int temp;
            infile >> temp;
            cout << current_file_number << " i: "<< i << " index:"<< index << " limit:"<< limit <<"\n";
        }
        cout << "OUT";
        // Keep doing until you reach limit or end of file
        for(;index<limit && index<(current_file_number*(arg_struct->numbersPerFile));index++){
            int num;
            infile >> num;
            cout << "AADED";
            total += num;
        }       
        infile.close();
    }
    cout << "TOTAL" << total;
}
int main(int argc, char* argv[])
{
    // Argument Check
    if(argc < 6){
        cout << "Error: Check number of arguments";
        return 0;
    }
    
    // Creating files
    int numAfiles = atoi(argv[1]);
    int numBfiles = atoi(argv[2]);
    int numPerFile = atoi(argv[3]);
    int numParentThreads = atoi(argv[4]);
    int numChildThreads = atoi(argv[5]);

    createFiles("a",numAfiles,numPerFile);
    createFiles("b",numBfiles,numPerFile);
    
    //DEBUG TOTAL for parent
    struct total_runner_struct debug_total;
    debug_total.index = 1;
    debug_total.aORb = "a";
    debug_total.numbersPerThread= floor(float(numAfiles*numPerFile)/float(numParentThreads)); //Number of numbers / Number of threads
    debug_total.numberOfThreads = numParentThreads;
    debug_total.numberOfFiles = numAfiles;
    debug_total.numbersPerFile = numPerFile;
    //------------

    total(&debug_total);
    /***
    //Forking
    pid_t pid = fork();

    
    if(pid==0){
        // Debug
        cout<<"Child";
        int numChildThreads = atoi(argv[5]); 
        //Launch thread  
        pthread_t threads[numChildThreads];

        //Array of arguments
        struct total_runner_struct args[numChildThreads];
        for(int i = 0; i < numChildThreads ; i++ ) {
            pthread_attr_t attr;
            pthread_attr_init(&attr);
            args[i].index=i;
            args[i].numbersPerThread= atoi(argv[2])*atoi(argv[3]);
            int rc = pthread_create(&threads[i], NULL, total, &args[i]);
            if (rc) {
                cout << "Error:unable to create thread," << rc << endl;
                exit(-1);
            }
        }

        //Wait for all threads
        for(int i=0; i<numChildThreads;i++){
            pthread_join(threads[i],NULL);
        }
        

    }
    ***/
    return 0;
}