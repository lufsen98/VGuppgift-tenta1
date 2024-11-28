#include <iostream>
void appendValue(int value,int array[],const int MAX_SIZE,int& sum,int& index);
void popAndSubstract(int array[],const int minimumsize,int lastCommit,int& sum, int& index);
void remove_till_LastCommit(int array[],const int minimumsize,int lastCommit,int& sum, int& index);
void commitAppends(int& commitsum,int sum);
void intError();

int main()
{
    const int MAX_SIZE = 100;
    const int minSize = 0;
    int lastCommitIndex= 0;
    int arrayOfValues[MAX_SIZE];
    int arrayIndex = 0;
    int sum = 0;
    int value = 0;
    int running = 1;

    char command;

    std::cout << "Hello and welcome: to start press any number on your keyboard. if you press (-1) you will quit program\n";
    std::cout << "The menue will show what command does what\n";
    std::cout << "(a):+ value you want to add\n"
                  << "(p):  display sum of all values\n"
                  << "(u):  Undo latest value added\n"
                  << "(c):  Commit values make them undoable\n"
                  << "(r):  remove all added values till the last commit\n"
                  << "(q):  To Quit\n";
    while(running != 0) {
        std::cin >> command;
        if(command == 'a') {
            std::cin >> value;
            while(!std::cin >> value) {
                intError();
                std::cout << "Need to add a number as value\n";
                continue;
            }
        }
        switch(command) {
            case 'a':
                appendValue(value,arrayOfValues,MAX_SIZE,sum,arrayIndex);
                break;
            case 'p':
                std::cout << sum << "\n";
                break;
            case 'c':
                commitAppends(lastCommitIndex,sum);
                break;
            case 'u':
                popAndSubstract(arrayOfValues,minSize,lastCommitIndex,sum,arrayIndex);
                break;
            case 'r':
                remove_till_LastCommit(arrayOfValues,minSize,lastCommitIndex,sum,arrayIndex);
                break;
            case 'q':
                running = 0;
                break;
            default:
                std::cout << "No case matches your command\n";
                continue;
        }
    }
}

void intError() {
    std::cin.clear();
    std::cin.ignore(256 ,'\n');
}
void appendValue (int value,int array[],const int MAX_SIZE,int& sum,int& index) {
    if(index < MAX_SIZE) {
        index++;
        array[index] = value;
        sum += value;
    }
    else {
        std::cout << "The array is full you can't add more values";
    }
}
void popAndSubstract(int array[],const int minimumsize,int lastCommit,int &sum, int& index) {
    if ((index > minimumsize) && (sum > lastCommit)) {
        sum -= array[index];
        array[index] = 0;
        index--;          
    }
}
void commitAppends(int& commitsum,int sum) {
    commitsum = sum;
}
void remove_till_LastCommit(int array[],const int minimumsize,int lastCommit,int& sum, int& index) {
    while((index > minimumsize) && (sum > lastCommit)) {
        sum -= array[index];
        array[index] = 0;
        index--; 
    }
}