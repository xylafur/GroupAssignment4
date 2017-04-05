#ifndef FILEREADER
    #define FILEREADER
//this class if supposed to read a file into a linked list.  Each node of the
//  linked list should contain one line of the file.

//just something i use for a linked list

#include <string>
#include <fstream>
//beacause the file should only contain ints im gonna go ahead and parse them
struct fileNode{
    std::string strVal;
    int val
    fileNode *next;
};

fileNode readFile(std::string filename){
    fstream file(filename);
    if(file.is_open() ){
        fileNode * head = new fileNode;
    }
    //open flie
    //create head
    //pass head into file to get all values
    //return head node 
}

#endif
