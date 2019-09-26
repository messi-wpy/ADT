//
// Created by messi-lp on 18-9-14.
//

#include <stdio.h>

//#include "ChapterTwo.c"
#include "ArraySort.c"
int main(){
    SqList list;
    list.length=20;
    for (int i = 0; i <= 20; ++i) {
        list.elem[i]=i;

    }
    list.elem[4]=20;
    list.elem[5]=43;
    list.elem[11]=9;
    list.elem[3]=0;
    list.elem[14]=99;
    quickSort(list.elem,1,20);
    //bubbleSort(&list);
   // selectSort(&list);
   //insertSort(&list);
    for (int j = 1; j <list.length ; ++j) {
        printf("%d\n",list.elem[j]);
    }
    return 0;
}

