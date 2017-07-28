#include "WGRAPH.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

void printMenu(){
    cout << "=================== State Navigator ===================" << endl;
    cout << " Enter command:" << endl;
    cout << " 1. Shortest path from capital to capital" << endl;
    cout << " 2. Display all states and their capitals" << endl;
    cout << " 3. Display all connections from one capital" << endl;
    cout << " 4. Display total number of states and capitals" << endl;
    cout << " 5. Display total number of connections between capitals" << endl;
    cout << " 6. Exit program" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    return;

}

int main(){
    graph g;
    g.buildGraph();

    int input;
    string capital1;
    string capital2;
    while(1){
        printMenu();
        cin >> input;
        cin.ignore();
        if(input == 1){
            cout << "Use _ for space" << endl;
            cout << "Enter starting city: " << endl;
            cin >> capital1;
            cout << "Enter city to navigate to: " << endl;
            cin >> capital2;
            cout << endl;
            g.shortestPath(capital1, capital2);
        }
        else if(input == 2){
            g.printVertices();
        }
        else if(input == 3){
            cout << "Use _ for space" << endl;
            cout << "Enter city: " << endl;
            cin >> capital1;
            g.printEdges(capital1);
        }
        else if(input == 4){
            g.countVertices();
        }
        else if(input == 5){
            g.countEdges();
        }
        else if(input == 6){
            g.deleteGraph();
            cout << "Goodbye!";
            return 0;
        }
        else{
            cout << "Invalid input" << endl;
        }
    }
    return 0;
}

