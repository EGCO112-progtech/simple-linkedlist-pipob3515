//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,d,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;
    b.next=&d;
    d.value=head ->next->value+3;

    d.next=NULL;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value ); //what value for 11
    printf("%d\n", head ->next->next->next ); //what value for NULL
    printf("\n");
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node f;
    f.next=&a;
    head=&f;
    f.value=2;
    printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for  5
    printf("%d\n", head ->next->next->value ); //what value for 8
    printf("%d\n", head ->next->next->next->value ); //what value for 11
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2) */
    typedef struct node* NodePtr;
    typedef struct node Node;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything*/
        printf("\n");
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp->next;
          // What is missing???  Ans  tmp=tmp+1;
        }
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)*/
        printf("\n\n");
        //for(tmp=head;tmp!=NULL;tmp=tmp->next)                                                         ( In "for" form )
        tmp = head;
         while(tmp!=NULL){
            printf("%3d", tmp->value);
            tmp = tmp->next;
           // What is missing???
        }
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!! */
        printf("\n\n");
        head = (NodePtr)malloc(sizeof(struct node));
        tmp = head; 
        for(i=0;i<3;i++) {
            tmp->next = (NodePtr)malloc(sizeof(struct node));                                          //สร้าง 3 node ต่อท้าย
            tmp=tmp->next;
            tmp->value=i+3;                                                                            //ใส่ค่า i+3 ใน value
            tmp->next=NULL;
        }
        for(tmp=head;tmp!=NULL;tmp=tmp->next)  {
                printf("%3d", tmp->value);
        }
        

           // What is missing???


    /*  Exercise VI Free all node !!
         //use a loop to help */
    for(tmp=head;tmp!=NULL;tmp=head) {
        head=head -> next;
        printf("\nFree %d",tmp->value);
        free(tmp);
    }
    
    return 0;
}
