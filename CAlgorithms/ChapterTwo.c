//
// Created by messi-lp on 18-9-24.
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#include "list.c"

int DeleteK(SqList * q,int i,int k){
    if(i<1||k<0||i+k>q->length)return 0;
    for (int j = 0; j <=q->length-k-i ; ++j) {
        q->elem[j+i]=q->elem[j+i+k];
    }
    q->length-=k;
    return 1;
}


//第二题
int insertOrdered(SqList *l,ElemType x){
    int i;
    for ( i = 0; i <l->length ; ++i) {
        if (x<l->elem[i])
            break;
    }
    listInsert(l,i,x);
}