//
// Created by messi-lp on 18-9-27.
//
#include <stdio.h>
typedef struct {
    int elem[21];
    int length;
} SqList;


void selectSort(SqList *list){
    for (int i = 1; i < list->length; ++i) {
        int temp=i;
        int k;
        for (int j = i+1; j <=list->length ; ++j) {
            if (list->elem[temp]>list->elem[j])
                temp=j;
        }
        if (temp!=i){
            k=list->elem[i];
            list->elem[i]=list->elem[temp];
            list->elem[temp]=k;
        }
    }

}
//elem(从１开始)
void insertSort(SqList *list){
    int i,j;
    for ( i = 2; i <list->length ; ++i) {
        if (list->elem[i]>list->elem[i-1])
            continue;
        list->elem[0]=list->elem[i];
        for ( j=i-1; list->elem[0] < list->elem[j]; --j) {
            list->elem[j+1]=list->elem[j];
        }
        list->elem[j+1]=list->elem[0];
    }

}

void bubbleSort(SqList*list){
    int flag;
    int temp;
    for (int i = 1; i < list->length; ++i) {
        flag=0;
        for (int j = 0; j < list->length-i; ++j) {
            if (list->elem[j]>list->elem[j+1])
            {
                flag=1;
                temp=list->elem[j];
                list->elem[j]=list->elem[j+1];
                list->elem[j+1]=temp;

            }

        }
        if (!flag)
            break;
    }

}


int  Partition(int *array,int low,int hight){
    array[0]=array[low];
    while (low<hight){
        while (low<hight&&array[hight]>=array[0])hight--;
        if(low<hight)
            array[low++]=array[hight];
        while (low<hight&&array[low]<=array[0])low++;
        if (low<hight)
            array[hight--]=array[low];
    }

    array[low]=array[0];
    return low;

}

void quickSort(int *array,int low,int hight){
    int k;
    if (low<hight){
        k=Partition(array,low,hight);
        quickSort(array,low,k-1);
        quickSort(array,k+1,hight);

    }


}