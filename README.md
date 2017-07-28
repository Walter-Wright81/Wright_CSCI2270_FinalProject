# Wright_CSCI2270_FinalProject

This project's primary function is to allow you to enter the capital of two states (excluding Hawaii and Alaska) and the program will find the shortest path from capital to capital between the states. The state capitals are vertices of a graph and the connections between them are the edges of the graph. The edges of the graph hold two pieces of information, the distance in miles and the amount of time it takes to go from one state capital to the other. The distance in miles is not used in the code except to tell the user the distance between state capitals. The amount of time to go from one state capital to another is what is used in the Dijkstra's Algorithm to find the shortest path between two capitals. This gives you the route that takes the least amount of time to travel.

The 7 public functions display the total number of vertices, display the total number of edges, display all vertices (states and capitals), display all edges from one vertex, build the graph (put all 48 states and their connections into the graph), delete the graph, and find the shortest path between two state capitals.

To use the program, a menu will display with 6 options. Enter a number corresponding to the option and that option will be executed or you will be prompted for further input.

To download and use the program:

1. Clone onto machine using
    
    git clone https://github.com/Walter-Wright81/Wright_CSCI2270_FinalProject.git
    
2. Open directory using
    
    cd Wright_CSCI2270_FinalProject
    
3. Compile using
    
    g++ -o shortPath Graph_runner.cpp

4. Run using
    
    ./shortPath
