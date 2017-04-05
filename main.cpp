#include <stdio.h>
#include <iostream>
#include <string>
#include "ADTs/sortedArray.h"
#include "ADTs/hasMap.h"
#include "ADTs/hashedArray.h"
#include "ADTs/unsortedArray.h"
#include "filereader.h"
/*
 *  Need a has map, a sorted array and an unsorted array.
 *
 *  Read from a file with 20 different integers
 *  Place those numbers into all 3 data types and insert them 
 *          all into the different storage containers
 *      time all of the inserts
 *  After inserting, delete elements from all three containers
 *      record time to do this as well.
 *
 */
struct stats{
    std::string operation;
    double timeTaken;
};
//function to take in a function pointer and return how long it took to complete
/*
double timerWrapper( void (*func)(void) ){
    func();
}


void otherFunction(){
    std::cout<<"calling functionction pointer"<<std::endl;
}
*/

void callHashFunctions(int size, fileNode *head){
    HashedArray<int> *arr = new HashedArray<int>();
    for(int i = 0; i < 10; i++)
        arr->addElement(i);
    arr->print();
    std::cout<<"searching for 5.. found = " << arr->search(5) <<std::endl;
    std::cout<<"searching for 11.. found = " << arr->search(11) <<std::endl;
    std::cout<<"deleting value 5..\n";
    arr->deleteByValue(5);
    arr->print();
}

void callSortedArrayFunctions(){
    SortedArray<int> arr(10);
    for(int i = 11; i > 0; i--)
        arr.insert(i);
    arr.print();
    std::cout<<"searching for 5.. index = " << arr.search(5) <<std::endl;
    std::cout<<"searching for 11.. index = " << arr.search(11) <<std::endl;
    std::cout<<"deleting index 5..\n";
    arr.deleteAtIndex(5);
    arr.print();

}

void callUnsortedArrayFunctions(){
    UnsortedArray<int> arr(10);
    for(int i = 0; i < 10; i++)
        arr.insert(i);
    arr.print();
    std::cout<<"searching for 5.. index = " << arr.search(5) <<std::endl;
    std::cout<<"searching for 11.. index = " << arr.search(11) <<std::endl;
    std::cout<<"deleting index 5..\n";
    arr.deleteAtIndex(5);
    arr.print();
}

int main(){
    std::cout.setf(ios::fixed | ios::showpoint);
    std::cout.precision(20);

    std::string filename = "test.txt";
    fileNode *head = new fileNode;
    int size = readFileToList(filename, head);
    printAllLines(head);

}

