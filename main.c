/**
Command line to do manager
Users can add, view, complete, and delete tasks from a to-do list
Stored in a file
Command line option:
    -add "String"
    -view (will print numbered list of tasks)
    -complete # of task
    -delete # of task
     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseArgs(char* userArgs);
void addTask(char* taskName);
char* viewTasks();
void completeTask(int taskNum);
void deleteTask(int taskNum);

int main(int argc, char* argv[]){

    if(argc != 3){
        perror("Invalid number of command line arguments\n");
        exit(1);
    }
    FILE *outputFile;
    outputFile = fopen("tasks.txt", "a"); //opens the file in append mode so it saves every run
    if(outputFile == NULL){
        perror("No file found");
        exit(1);
    }
   //takes in the thing the user wants to do
    int operation = parseArgs(argv[1]);
    int number = 0;
    switch(operation){
        case(1): //addTask
            addTask(argv[2]);
            break;
        case(2): //viewTasks
            viewTasks();
            break;
        case(3): //completeTask
            //get task number
            number = argv[3];
            completeTask(number);
            break;
        case(4): //deleteTask
            //get task number
            number = argv[3];
            deleteTask(number);
            break;
        case(5): //close program
            exit(0);
            break;
        default:
            perror("Operation not found.\n");
            exit(1);
    }
}

//parseArgs function
int parseArgs(char* userArgs){
    if(strcmp(userArgs, "-add") == 0 || strcmp(userArgs, "-Add") == 0){
        return 1; //corresponds to add operation
    } 
    else if(strcmp(userArgs, "-view") == 0 || strcmp(userArgs, "-View") ==0){
        return 2;
    }
    else if(strcmp(userArgs, "-complete") ==0 || strcmp(userArgs, "-Complete") ==0){
        return 3;
    }
    else if (strcmp(userArgs, "-delete") ==0 || strcmp(userArgs, " -Delete") == 0){
        return 4;
    }
    else{
        fprintf(stderr, "No operation found.\n");
        exit(1);
    }
}
//addTask
void addTask(char* taskName){
    //need to use fwrite
}
//viewTasks

//completeTask

//deleteTask