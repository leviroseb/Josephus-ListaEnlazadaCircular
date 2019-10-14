#include<iostream>
using namespace std;

struct node;
typedef struct node* list;
typedef struct node* position;

struct node{
    int number;
    position next;
};

void insert(int x, position p){
    position tmpcell;
    tmpcell=(struct node*) malloc(sizeof(struct node));
    tmpcell->number=x;
    tmpcell->next=p->next;
    p->next=tmpcell;
}

void deletenext(position p){
    position tmpcell;
    tmpcell=p->next;
    p->next=tmpcell->next;
    free(tmpcell);
}

int josephus(int n, int m){
    list L;
    position lastcell;
    int i, count =0;
    L=(struct node*)malloc(sizeof(struct node));
    L->number=1;
    lastcell=L->next=L;
    for(i=2;i<=n;i++){
        insert(i,lastcell);
        lastcell=lastcell->next;
    }

    while(L!=L->next){
        if(++count==m){
            deletenext(L);
            count=0;
        }
        L=L->next;
    }
    return L->number;


}

int main(){
        int n,m;
        scanf("%d %d" , &n, &m);
        printf("The winner is %d\n", josephus(n,m));
    }
