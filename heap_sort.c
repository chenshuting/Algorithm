/*
 * =====================================================================================
 *
 *       Filename:  heap.c
 *
 *    Description: Heap sort algorithm 
 *
 *        Version:  1.0
 *        Created:  08/07/2013 10:14:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shuting Chen (cst), cicy0125@gmail.com
 *        Company:  ucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
 
void HeapSort(int num[],int size);
void BuildHeap(int num[] ,int size);
void PercolateDown(int num[] , int index,int size);
void PrintHeap(const char* strMsg,int array[],int nLength);
void Swap(int num[] , int v, int u);
 
int main(int argc, char *argv[])
{
  int data[13]={8,5,4,6,13,7,2,9,12,11,3,10,1};
  HeapSort(data,13);
  return 0;
}

/* *
 * The function interface of Heap sort
 * */
void HeapSort(int num[] ,int size)
{
    int i;
    int iLength=size;
     
    PrintHeap("Befor Sort:",num,iLength);
     
    BuildHeap(num,size);
     
    for (i = iLength - 1; i >= 1; i--) {  
        Swap(num, 0, i); 
        size--;//reduce the heap size after swao 
        PercolateDown(num, 0,size);//adjusting new heap
        PrintHeap("Sort Heap:",num,iLength); 
    }
}

/* *
 * Build heap by shift down internal nodes.
 * From bottom to top.
 * */
void BuildHeap(int num[] ,int size) {
    int i;
    
    for (i = size / 2 - 1; i >= 0; i--) {  
        PercolateDown(num, i,size);
        PrintHeap("Build heap:",num,size);
    }  
}

/* *
 * shift down one node.
 * End condition: Both left and right child is less than it
 * */
void PercolateDown(int num[] , int index,int size) {  
    int min;//
    while (index * 2 + 1<size) {//
        min = index * 2 + 1;//set min to left child
        if (index * 2 + 2<size) {//if has right child
            if (num[min] > num[index * 2 + 2]) {
                min = index * 2 + 2;//choose the minimun child index
            }  
        }  
        if (num[index] < num[min]) {//face the end condition
            break;
        } else {  
            Swap(num, index, min);//shift down the node
            index = min;
        }  
    }
}

void Swap(int num[] , int v, int u) { 
    int temp = num[v];  
    num[v] = num[u];  
    num[u] = temp;  
}  
 
void PrintHeap(const char* strMsg,int array[],int nLength)
{
     int i;
     printf("%s",strMsg);
     for(i=0;i<nLength;i++)
     {
        printf("%d ",array[i]);
     }
     printf("\n");
}

