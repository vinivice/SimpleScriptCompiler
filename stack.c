#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
typedef enum Op {PUSH, POP} Stack_Op;

void printStack(int element, Stack_Op action, string &State) {
    string wall, base;
    base = "----";
    if (State == "") {
        wall = "|  |";
        wall.replace(1,2, to_string(element));   
    }
    else 
        base = "  |";
    if (action == PUSH) {
        wall.replace(0, 2, to_string(element));
        State = State  + wall + "\n" + base;
    }
    cout << State;


}


int main() {
    //printf("\t\t\t|  |\n\t\t\t|--|\n\t\t\t|12|\n\t\t\t----\n");
    string State = "";
    printStack(20, PUSH, &State);
    printStack(30, PUSH, &State);
    return 0;
}
