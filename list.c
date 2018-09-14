#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENTSIZE 10

typedef int ElemType;
//顺序存储链表
typedef struct SqList
{
    ElemType  *elem;
    int  length;
    int  listsize;
    int  increamentsize;
} SqList;
//链试存储链表
typedef struct LNode{
    ElemType data;
    struct LNode *next;

}LNode,* LinkList;

int getElem_L(LinkList h,int i,ElemType* e){
    LinkList p=h->next;
    int j=0;
    while (p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    if (j<i)
        return 0;
    else {
        *e=p->data;
        return 1;
    }
}

int listInsert_l(LinkList h,int i,ElemType e){
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    if (i==1){
        s->next=h->next;
        h->next=s;
        return 1;
    }
    int j=0;
    LinkList p=h->next;
    while (p&&j<i-1){
        p=p->next;
        j++;
    }
    s->next=p->next;
    p->next=s;
    return 1;
}

int listDeatory_L(LinkList h){
    LinkList p=h->next;
    LinkList q;
    while (p!=NULL) {
        q=p->next;
        free(p);
        p=q;
    }
    free(h);
}

void wrongMessage(char *string){
    printf("%s\n", string);
}

void initList(SqList *list){
    char *s="malloc wrong";
    list->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (list->elem==NULL)
        wrongMessage(s);
    list->length=0;
    list->listsize=LIST_INIT_SIZE;
    list->increamentsize=LISTINCREMENTSIZE;
}

void destoryList(SqList *list) {
    if (list->elem!=NULL) {
        free(list->elem);
        list->elem = NULL;
        list->length = 0;
        list->listsize = 0;
    }
}
int ListEmpty(SqList list){
    if(list.length!=0){
        return 1;
    } else
        return 0;
}

void clearList(SqList*List){
    ElemType  *temp=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    free(List->elem);
    List->elem=temp;
}

void getElem(SqList list,int locate,ElemType* e){
    if (locate<1||locate>100)return;
    *e=list.elem[locate-1];
}

int locateElem(SqList list,ElemType e,int(*compare)(ElemType e1,ElemType e2)){
    for (int i = 0; i <list.length ; ++i) {
        if (compare(list.elem[i],e))
            return i+1;
    }
    return 0;
}

int priorElem(SqList list,ElemType cur_e,ElemType * pre_e){
    for (int i = 0; i <list.length ; ++i)
        if (list.elem[i]==cur_e&&i!=0) {
            *pre_e = list.elem[i - 1];
            return 1;
        }
    return 0;
}

int nextElem(SqList list,ElemType cur_e,ElemType * pre_e){
    for (int i = 0; i <list.length ; ++i)
        if (list.elem[i]==cur_e&&i!=list.length-2) {
            *pre_e = list.elem[i + 1];
            return 1;
        }
    return 0;

}

void listInsert(SqList *sqList,int i,ElemType e){
    if (i<1||i>sqList->length+1)return;
    if (sqList->length>=sqList->listsize){
        ElemType *temp=(ElemType*)realloc(sqList->elem,sizeof(ElemType)*(LIST_INIT_SIZE+LISTINCREMENTSIZE));
        if (temp==NULL)exit(1);
        sqList->elem=temp;
        sqList->listsize+=LISTINCREMENTSIZE;
    }
    for (int j = sqList->length; j >=i ; --j) {
        *(sqList->elem+j)=*(sqList->elem+j-1);
    }
    *(sqList->elem+i-1)=e;
    sqList->length++;
}

void listDelete(SqList *sqList,int i,ElemType *e){
    if (i<1||i>sqList->length)return;
    *e=sqList->elem[i-1];
    for (int j = i-1; j <sqList->length-1 ; ++j) {
        sqList->elem[j]=sqList->elem[j+1];
    }
    sqList->length--;

}
/*
int main(){
    int a,b,c;
    SqList s;
    initList(&s);
    for (int i = 0; i <50 ; ++i) {
        s.elem[i]=i;
        s.length++;
    }
    listInsert(&s,10,100);
    listDelete(&s,20,&b);
    printf("%d\n",b);
    for (int j=0;j<s.length;j++)
        printf("%d  ",s.elem[j]);
    return 0;

}*/
