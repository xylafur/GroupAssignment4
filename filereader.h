#ifndef FILEREADER
    #define FILEREADER
//this class if supposed to read a file into a linked list.  Each node of the
//  linked list should contain one line of the file.

//just something i use for a linked list

#include <string>
#include <fstream>
using namespace std;
//beacause the file should only contain ints im gonna go ahead and parse them
struct fileNode{
    std::string strVal;
    int val;
    fileNode *next = NULL;
};

void createNode(std::string line, fileNode *head){
    //find tail
    while(head != NULL)
        head = head->next;
    head = new fileNode;
    head-> strVal = line;
    head->next = NULL;
    
}
int readFile(std::string filename, fileNode *head){
    fstream file(filename);
    int count = 0;
    if(file.is_open() ){
        std::string line;
        while( getline( file, line )){
            createNode(line, head);
            count++;
        }
        file.close();
    }
    return count;
}

#endif
