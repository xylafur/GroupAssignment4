#ifndef SORTED_ARRAY
    #define SORTED_ARRAY
#include <stdio.h>
#include <iostream>
#include <string>

template <class T>
class SortedArray{
private:
    int size, realSize;
    T * arr;
    void bubbleUp(T val, int index){
        T temp = arr[index];
        arr[index] = val;
        for(index++; index < realSize; index++){
            T otherTemp = arr[index];
            arr[index] = temp;
            temp = otherTemp;
        }

    }
public:
    SortedArray<T>(int size){
        this->size = size;
        this->realSize = 0;
        arr = new T[size];
    }
    ~SortedArray<T>(){
        delete(arr);
    }
    void insert(T val){
        if(realSize >= size)
            std::cout<<"trying to put to many elements in your sorted array..\n";
        else{
            int index = 0;
            while( arr[index] < val ){
                //new element is the greatest value
                if(index == realSize){
                    arr[index] = val;
                    return;
                }
                index++;
            }//end while
            realSize++;
            bubbleUp(val, index);
        }//end else
    }//end insert
    void deleteAtIndex(int index){
        if( index > realSize )
            std::cout<<"Invalid index to delete bruh\n";
        else{
            for( int i = index; i < realSize; i++)
                arr[i] = arr[i+1];
            realSize--;
        }
    }
    void print(){
        for(int i = 0; i < size; i++){
            std::cout<<arr[i];
        }
        std::cout<<std::endl;
    }
};


#endif
