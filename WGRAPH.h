#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Graphs.h"

#ifndef GRAPH_TESTER_H
#define GRAPH_TESTER_H

struct path;
struct adjVertex;
struct vertex;
class graph;

//Structure that holds the shortest path between two vertices
struct path{
    std::string key;
    path *next;
    path *previous;
};

//Structure that defines two attached vertices
struct adjVertex{
    vertex *v;
    int distance;
    int miles;
};

//Structure that defines a vertex
struct vertex{
    std::string key;
    std::string city;
    std::vector<adjVertex> adjacent;
    bool solved;
    int distance;
    vertex *parent;
};

//Class that contains vertices and functions to manipulate vertices
class graph{
    private:
        std::vector<vertex> vertices;
        void insertVertex(std::string value, std::string city);
        void insertEdge(std::string v1, std::string v2, int miles, int distanceH, int distanceM);
    public:
        void countVertices();
        void countEdges();
        void printVertices();
        void printEdges(std::string value);
        void buildGraph();
        void deleteGraph();
        void shortestPath(std::string start, std::string finish);
};

//Returns the number of vertices in the graph
void graph::countVertices(){
    std::cout << "Total cities: " << vertices.size() << std::endl;
    return;
}

//Returns the number of edges in the graph
void graph::countEdges(){
    int counter = 0;
    for(int i = 0; i < vertices.size(); i++){
        counter = counter + vertices[i].adjacent.size();
    }
    std::cout << "Total connections between cities: " << counter << std::endl;
    return;
}

//Prints out values of all vertices
void graph::printVertices(){
    for(int i = 0; i < vertices.size(); i++){
        std::cout << vertices[i].city << ", ";
        std::cout << vertices[i].key << std::endl;
    }
    std::cout << std::endl;
    return;
}

void graph::printEdges(std::string value){
    bool found = false;
    vertex *city;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value){
            found = true;
            city = &vertices[i];
            break;
        }
    }
    if(found == false){
        std::cout << "City not found." << std::endl;
    }
    std::cout <<"Cities connecting to: " << city -> key << ", ";
    std::cout << city -> city << std::endl;
    for(int i = 0; i < city -> adjacent.size(); i++){
        std::cout << city -> adjacent[i].v -> key;
        std::cout << ", " << city -> adjacent[i].miles;
        std::cout << " miles away" << std::endl;
    }
    std::cout << std::endl;
    return;
}

//Builds a graph with all state capitals and connections.
void graph::buildGraph(){
    //Insert all cities
    insertVertex("Montgomery","Alabama");
    insertVertex("Phoenix", "Arizona");
    insertVertex("Little_Rock", "Arkansas");
    insertVertex("Sacramento","California");
    insertVertex("Denver","Colorado");
    insertVertex("Hartford","Connecticut");
    insertVertex("Dover","Delaware");
    insertVertex("Tallahassee","Florida");
    insertVertex("Atlanta","Georgia");
    insertVertex("Boise","Idaho");
    insertVertex("Springfield","Illinois");
    insertVertex("Indianapolis","Indiana");
    insertVertex("Des_Moines","Iowa");
    insertVertex("Topeka","Kansas");
    insertVertex("Frankfurt","Kentucky");
    insertVertex("Baton_Rouge","Louisiana");
    insertVertex("Augusta","Maine");
    insertVertex("Annapolis","Maryland");
    insertVertex("Boston","Massachusetts");
    insertVertex("Lansing","Michigan");
    insertVertex("Saint_Paul","Minnesota");
    insertVertex("Jackson","Mississippi");
    insertVertex("Jefferson City","Missouri");
    insertVertex("Helena","Montana");
    insertVertex("Lincoln","Nebraska");
    insertVertex("Carson_City","Nevada");
    insertVertex("Concord","New Hampshire");
    insertVertex("Trenton","New Jersey");
    insertVertex("Santa Fe","New Mexico");
    insertVertex("Albany","New York");
    insertVertex("Raleigh","North Carolina");
    insertVertex("Bismarck","North Dakota");
    insertVertex("Columbus","Ohio");
    insertVertex("Oklahoma City","Oklahoma");
    insertVertex("Salem","Oregan");
    insertVertex("Harrisburg","Pennsylvania");
    insertVertex("Providence","Rhode Island");
    insertVertex("Columbia","South Carolina");
    insertVertex("Pierre","South Dakota");
    insertVertex("Nashville","Tennessee");
    insertVertex("Austin","Texas");
    insertVertex("Salt_Lake_City","Utah");
    insertVertex("Montpelier","Vermont");
    insertVertex("Richmond","Virginia");
    insertVertex("Olympia","Washington");
    insertVertex("Charleston","West Virginia");
    insertVertex("Madison","Wisconsin");
    insertVertex("Cheyenne","Wyoming");

    //Insert city connections
    insertEdge("Montgomery","Tallahassee", 210,3,33);
    insertEdge("Montgomery","Atlanta",160,2,20);
    insertEdge("Montgomery","Nashville",281,4,4);
    insertEdge("Montgomery","Jackson",248,4,1);

    insertEdge("Phoenix","Santa_Fe",481,7,49);
    insertEdge("Phoenix","Denver",821,12,57);
    insertEdge("Phoenix","Salt_Lake_City",663,10,39);
    insertEdge("Phoenix","Carson_City",737,12,2);
    insertEdge("Phoenix","Sacramento",755,11,44);

    insertEdge("Little_Rock","Jackson",262,4,20);
    insertEdge("Little_Rock","Baton_Rouge",344,6,2);
    insertEdge("Little_Rock","Nashville",349,5,16);
    insertEdge("Little_Rock","Jefferson_City",345,6,3);
    insertEdge("Little_Rock","Oklahoma_City",339,5,4);
    insertEdge("Little_Rock","Austin",514,7,40);
    insertEdge("Little_Rock","Topeka",439,7,21);

    insertEdge("Sacramento","Carson_City",130,2,36);
    insertEdge("Sacramento","Salem",536,8,48);
    insertEdge("Sacramento","Phoenix",757,11,21);

    insertEdge("Denver","Cheyenne",101,1,40);
    insertEdge("Denver","Salt_Lake_City",521,8,8);
    insertEdge("Denver","Santa_Fe",392,5,58);
    insertEdge("Denver","Phoenix",821,12,58);
    insertEdge("Denver","Lincoln",488,7,5);
    insertEdge("Denver","Topeka",539,7,48);
    insertEdge("Denver","Oklahoma_City",679,9,58);

    insertEdge("Hartford","Providence",75,1,21);
    insertEdge("Hartford","Boston",102,1,41);
    insertEdge("Hartford","Albany",112,1,52);

    insertEdge("Dover","Trenton",112,1,52);
    insertEdge("Dover","Annapolis",65,1,20);
    insertEdge("Dover","Harrisburg",130,2,30);

    insertEdge("Tallahassee","Georgia",262,4,22);
    insertEdge("Tallahassee","Montgomery",206,3,39);

    insertEdge("Atlanta","Columbia",214,3,11);
    insertEdge("Atlanta","Raleigh",405,6,9);
    insertEdge("Atlanta","Nashville",250,3,46);
    insertEdge("Atlanta","Montgomery",161,2,22);
    insertEdge("Atlanta","Tallahassee",261,4,22);

    insertEdge("Boise","Helena",486,7,41);
    insertEdge("Boise","Olympia",535,8,23);
    insertEdge("Boise","Salem",475,7,34);
    insertEdge("Boise","Carson_City",450,7,2);
    insertEdge("Boise","Salt_Lake_City",340,4,59);
    insertEdge("Boise","Cheyenne",736,10,46);

    insertEdge("Springfield","Madison",266,4,8);
    insertEdge("Springfield","Des_Moines",296,5,10);
    insertEdge("Springfield","Indianapolis",213,3,22);
    insertEdge("Springfield","Jefferson_City",193,3,26);
    insertEdge("Springfield","Frankfurt",375,5,46);

    insertEdge("Indianapolis","Lansing",254,4,0);
    insertEdge("Indianapolis","Columbus",175,2,44);
    insertEdge("Indianapolis","Frankfurt",166,2,37);
    insertEdge("Indianapolis","Springfield",212,3,23);

    insertEdge("Des_Moines","Saint_Paul",248,3,42);
    insertEdge("Des_Moines","Pierre",503,7,21);
    insertEdge("Des_Moines","Lincoln",188,2,55);
    insertEdge("Des_Moines","Jefferson_City",266,4,27);
    insertEdge("Des_Moines","Springfield",337,5,6);
    insertEdge("Des_Moines","Madison",293,4,37);

    insertEdge("Topeka","Lincoln",166,2,50);
    insertEdge("Topeka","Denver",541,8,5);
    insertEdge("Topeka","Oklahoma_City",294,4,29);
    insertEdge("Topeka","Jefferson_City",220,3,24);

    insertEdge("Frankfurt","Indianapolis",210,3,14);
    insertEdge("Frankfurt","Springfield",375,5,43);
    insertEdge("Frankfurt","Jefferson_City",220,3,25);
    insertEdge("Frankfurt","Nashville",210,3,14);
    insertEdge("Frankfurt","Charleston",198,3,9);
    insertEdge("Frankfurt","Columbus",186,3,6);

    insertEdge("Baton_Rouge","Austin",433,6,42);
    insertEdge("Baton_Rouge","Little_Rock",344,6,8);
    insertEdge("Baton_Rouge","Jackson",175,2,41);

    insertEdge("Augusta","Concord",163,2,35);
    insertEdge("Augusta","Montpelier",180,3,45);

    insertEdge("Annapolis","Dover",65,1,18);
    insertEdge("Annapolis","Harrisburg",112,1,53);
    insertEdge("Annapolis","Charleston",386,5,57);
    insertEdge("Annapolis","Richmond",143,2,17);

    insertEdge("Boston","Concord",68,1,7);
    insertEdge("Boston","Montpelier",180,2,52);
    insertEdge("Boston","Albany",169,2,48);
    insertEdge("Boston","Hartford",101,1,44);
    insertEdge("Boston","Providence",51,1,47);

    insertEdge("Lansing","Columbus",256,4,4);
    insertEdge("Lansing","Indianapolis",255,3,55);

    insertEdge("Saint_Paul","Bismarck",438,6,30);
    insertEdge("Saint_Paul","Pierre",468,6,53);
    insertEdge("Saint_Paul","Des_Moines",247,3,41);
    insertEdge("Saint_Paul","Madison",259,3,50);

    insertEdge("Jackson","Nashville",415,6,6);
    insertEdge("Jackson","Little_Rock",263,4,19);
    insertEdge("Jackson","Baton_Rouge",174,2,41);
    insertEdge("Jackson","Montgomery",247,4,6);

    insertEdge("Jefferson_City","Des_Moines",267,4,27);
    insertEdge("Jefferson_City","Lincoln",352,5,32);
    insertEdge("Jefferson_City","Topeka",207,3,25);
    insertEdge("Jefferson_City","Oklahoma_City",420,6,22);
    insertEdge("Jefferson_City","Little_Rock",340,6,1);
    insertEdge("Jefferson_City","Nashville",440,6,41);
    insertEdge("Jefferson_City","Frankfurt",372,5,56);
    insertEdge("Jefferson_City","Springfield",193,3,17);

    insertEdge("Helena","Boise",490,7,24);
    insertEdge("Helena","Cheyenne",691,10,5);
    insertEdge("Helena","Pierre",701,11,11);
    insertEdge("Helena","Bismarck",612,9,24);

    insertEdge("Lincoln","Pierre",393,6,38);
    insertEdge("Lincoln","Cheyenne",445,6,33);
    insertEdge("Lincoln","Denver",488,7,26);
    insertEdge("Lincoln","Topeka",166,2,52);
    insertEdge("Lincoln","Jefferson_City",351,5,28);
    insertEdge("Lincoln","Des_Moines",188,2,57);

    insertEdge("Carson_City","Salem",518,8,54);
    insertEdge("Carson_City","Sacramento",131,2,36);
    insertEdge("Carson_City","Phoenix",739,12,5);
    insertEdge("Carson_City","Salt_Lake_City",546,7,59);
    insertEdge("Carson_City","Boise",450,7,4);

    insertEdge("Concord","Augusta",164,2,37);
    insertEdge("Concord","Montpelier",118,1,53);
    insertEdge("Concord","Boston",68,1,8);

    insertEdge("Trenton","Albany",196,3,15);
    insertEdge("Trenton","Harrisburg",127,2,5);
    insertEdge("Trenton","Dover",112,1,54);

    insertEdge("Santa_Fe","Denver",392,5,46);
    insertEdge("Santa_Fe","Salt_Lake_City",625,10,12);
    insertEdge("Santa_Fe","Phoenix",480,7,52);
    insertEdge("Santa_Fe","Austin",688,10,58);
    insertEdge("Santa_Fe","Oklahoma_City",535,7,55);

    insertEdge("Albany","Montpelier",158,3,8);
    insertEdge("Albany","Harrisburg",293,4,30);
    insertEdge("Albany","Trenton",205,3,14);
    insertEdge("Albany","Hartford",112,1,55);
    insertEdge("Albany","Boston",170,2,43);

    insertEdge("Raleigh","Richmond",154,2,34);
    insertEdge("Raleigh","Nashville",543,8,21);
    insertEdge("Raleigh","Atlanta",407,6,34);
    insertEdge("Raleigh","Columbia",226,3,23);

    insertEdge("Bismarck","Helena",612,9,28);
    insertEdge("Bismarck","Pierre",210,3,25);
    insertEdge("Bismarck","Saint_Paul",435,6,39);

    insertEdge("Columbus","Lansing",260,4,2);
    insertEdge("Columbus","Indianapolis",176,2,45);
    insertEdge("Columbus","Frankfurt",188,3,6);
    insertEdge("Columbus","Charleston",163,2,39);
    insertEdge("Columbus","Harrisburg",368,5,52);

    insertEdge("Oklahoma_City","Topeka",294,4,24);
    insertEdge("Oklahoma_City","Denver",680,9,54);
    insertEdge("Oklahoma_City","Santa_Fe",534,7,59);
    insertEdge("Oklahoma_City","Austin",389,6,13);
    insertEdge("Oklahoma_City","Little_Rock",339,5,2);
    insertEdge("Oklahoma_City","Jefferson_City",420,6,24);

    insertEdge("Salem","Olympia",160,2,40);
    insertEdge("Salem","Sacramento",536,8,39);
    insertEdge("Salem","Carson_City",516,8,55);
    insertEdge("Salem","Boise",477,7,38);

    insertEdge("Harrisburg","Albany",293,4,31);
    insertEdge("Harrisburg","Columbus",367,5,52);
    insertEdge("Harrisburg","Charleston",366,5,36);
    insertEdge("Harrisburg","Annapolis",112,1,50);
    insertEdge("Harrisburg","Dover",129,2,31);
    insertEdge("Harrisburg","Trenton",127,2,6);

    insertEdge("Providence","Boston",50,0,54);
    insertEdge("Providence","Hartford",74,1,33);

    insertEdge("Columbia","Raleigh",227,3,22);
    insertEdge("Columbia","Atlanta",215,3,14);

    insertEdge("Pierre","Bismarck",205,3,26);
    insertEdge("Pierre","Helena",700,10,58);
    insertEdge("Pierre","Cheyenne",424,6,45);
    insertEdge("Pierre","Lincoln",410,6,37);
    insertEdge("Pierre","Des_Moines",503,7,13);
    insertEdge("Pierre","Saint_Paul",406,7,6);

    insertEdge("Nashville","Frankfurt",211,3,18);
    insertEdge("Nashville","Jefferson_City",440,6,31);
    insertEdge("Nashville","Little_Rock",349,5,18);
    insertEdge("Nashville","Jackson",415,6,11);
    insertEdge("Nashville","Montgomery",281,4,8);
    insertEdge("Nashville","Atlanta",248,3,49);
    insertEdge("Nashville","Raleigh",539,8,16);
    insertEdge("Nashville","Richmond",614,9,10);

    insertEdge("Austin","Oklahoma_City",388,6,19);
    insertEdge("Austin","Santa_Fe",688,10,57);
    insertEdge("Austin","Baton_Rouge",432,6,33);
    insertEdge("Austin","Little_Rock",514,7,54);

    insertEdge("Salt_Lake_City","Boise",345,4,59);
    insertEdge("Salt_Lake_City","Carson_City",546,8,5);
    insertEdge("Salt_Lake_City","Phoenix",663,10,20);
    insertEdge("Salt_Lake_City","Santa_Fe",626,10,7);
    insertEdge("Salt_Lake_City","Denver",521,8,5);
    insertEdge("Salt_Lake_City","Cheyenne",440,6,41);

    insertEdge("Montpelier","Augusta",180,3,43);
    insertEdge("Montpelier","Albany",158,3,7);
    insertEdge("Montpelier","Boston",180,2,46);
    insertEdge("Montpelier","Concord",119,1,51);

    insertEdge("Richmond","Annapolis",142,2,12);
    insertEdge("Richmond","Charleston",316,4,54);
    insertEdge("Richmond","Frankfurt",513,7,49);
    insertEdge("Richmond","Nashville",614,9,11);
    insertEdge("Richmond","Raleigh",171,2,34);

    insertEdge("Olympia","Salem",159,2,34);
    insertEdge("Olympia","Boise",535,8,19);

    insertEdge("Charleston","Harrisburg",366,5,46);
    insertEdge("Charleston","Columbus",162,2,41);
    insertEdge("Charleston","Frankfurt",198,3,2);
    insertEdge("Charleston","Richmond",317,4,58);
    insertEdge("Charleston","Annapolis",384,6,12);

    insertEdge("Madison","Saint_Paul",265,4,7);
    insertEdge("Madison","Des_Moines",285,4,34);
    insertEdge("Madison","Springfield",264,4,4);

    insertEdge("Cheyenne","Helena",691,10,7);
    insertEdge("Cheyenne","Boise",740,10,41);
    insertEdge("Cheyenne","Salt_Lake_City",439,6,38);
    insertEdge("Cheyenne","Denver",102,1,35);
    insertEdge("Cheyenne","Lincoln",445,6,30);
    insertEdge("Cheyenne","Pierre",424,6,47);


    //Initialize vertices
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].solved = false;
        vertices[i].distance = 0;
        vertices[i].parent = NULL;
    }
    return;
}

//Inserts new vertex into the graph
void graph::insertVertex(std::string value, std::string city){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value){
            found = true;
            std::cout << vertices[i].key << "found." << std::endl;
            break;
        }
    }
    if(found == false){
        vertex v;
        v.key = value;
        v.city = city;
        vertices.push_back(v);
    }
    return;
}

//Inserts an edge that connects two existing vertices
void graph::insertEdge(std::string v1, std::string v2, int miles, int distanceH, int distanceM){
    int distance = distanceH * 60 + distanceM;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].key == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.miles = miles;
                    av.distance = distance;
                    vertices[i].adjacent.push_back(av);
                }
            }
        }
    }
    return;
}

//Deletes all vertices and edges within a graph.
void graph::deleteGraph(){
    //Deletes all edges
    int sizeAdj;
    for(int i = 0; i < vertices.size(); i++){
        sizeAdj = vertices[i].adjacent.size();
        for(int j = 0; j < sizeAdj; j++){
            vertices[i].adjacent.erase(vertices[i].adjacent.begin());
        }
    }

    //Deletes all vertices
    int sizeVert = vertices.size();
    for(int i = 0; i < sizeVert; i++){
        vertices.erase(vertices.begin());
    }
    return;
}

//Finds the shortest path between two vertices, returns shortest path's head
void graph::shortestPath(std::string start, std::string finish){
    //Finds the vertex that corresponds to the starting and finishing vertices
    bool found = false;
    vertex s;
    vertex f;
    if(start == finish){
        std::cout << "Cannot start and finish in the same city" << std::endl;
        return;
    }
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == start){
            found = true;
            s = vertices[i];
            std::cout << "Starting at " << s.key;
        }
    }
    if(found == false){
        std::cout << "Input for starting city is invalid" << std::endl;
        return;
    }
    found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == finish){
            found = true;
            f = vertices[i];
            std::cout << " and finishing at " << f.key << std::endl;
        }
    }
    if(found == false){
        std::cout << "--" << std::endl;
        std::cout << "Input for finishing city is invalid" << std::endl;
        return;
    }
    std::cout << "The shortest path is:" << std::endl;

    //Begins finding shortest path using Dijkstra's
    s.solved = true;
    s.distance = 0;
    vertex solved[100];
    solved[0] = s;
    int solvedSize = 1;

    int dist = 0;
    int minDistance = 0;
    vertex *solvedV;
    vertex *sTemp;
    vertex *parent;
    int dd = 0;
    while(f.solved == false){
        minDistance = 10000000;
        solvedV = NULL;
        for(int i = 0; i < solvedSize; i++){
            sTemp = &solved[i];
            for(int j = 0; j < sTemp -> adjacent.size(); j++){
                if(sTemp -> adjacent[j].v -> solved == false){
                    dist = sTemp -> distance + sTemp -> adjacent[j].distance;
                    if(dist < minDistance){
                        solvedV = sTemp -> adjacent[j].v;
                        minDistance = dist;
                        parent = sTemp;
                    }
                }
            }
        }
        solvedV -> distance = minDistance;
        solvedV -> parent = parent;
        solvedV -> solved = true;
        if(solvedV -> key == f.key){
            f.solved = true;
        }
        solved[solvedSize] = *solvedV;
        solvedSize++;
    }
    vertex *index = &solved[solvedSize-1];
    path *shortRoute = new path;
    shortRoute -> previous = NULL;
    shortRoute -> next = NULL;
    shortRoute -> key = index -> key;
    while(index -> key != s.key){
        index = index -> parent;
        path *shortRouteTemp = new path;
        shortRouteTemp -> key = index -> key;
        shortRouteTemp -> previous = shortRoute;
        shortRouteTemp -> previous -> next = shortRoute;
        shortRoute = shortRouteTemp;
    }
    path *pIndex = shortRoute;
    while(pIndex -> previous != NULL){
        std::cout << "From " << pIndex -> key;
        std::cout << " to " << pIndex -> previous -> key;
        std::cout << std::endl;
        pIndex = pIndex -> previous;
    }
    int minutes = solvedV -> distance % 60;
    int hours = (solvedV -> distance - minutes) / 60;
    std::cout << "Total time: ";
    std::cout << hours << " hours, " << minutes << " minutes";
    std::cout << std::endl << std::endl;
    return;
}

#endif // GRAPH_TESTER_H
