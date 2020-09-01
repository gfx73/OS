#include <stdio.h>
#include <stdlib.h>
//in this implementation head does not contain any value
struct Node{
    struct Node *next;
    int val;
};

void insert_node(struct Node *head, int val){
    struct Node *end = head;
    while(end->next != NULL)
        end = end->next;
    end->next = (struct Node*) malloc(sizeof(struct Node));
    end->next->next = NULL;
    end->next->val = val;
}
//deletes by value
void delete_node(struct Node *head, int val){
    struct Node *currentNode = head;
    while(currentNode->next->val != val && currentNode->next != NULL)
        currentNode = currentNode->next;
    if(currentNode->next->val == val){
        struct Node *prev = currentNode, *toDelete = currentNode->next;
        if(toDelete->next == NULL){
            free(toDelete);
            prev->next = NULL;
        }
        else{
            prev->next = toDelete->next;
            free(toDelete);
        }
    }
}
void print_list(struct Node *head){
    struct Node *i = head->next;
    while(i != NULL){
        printf("%d ", i->val);
        i = i->next;
    }
}
int main(){
    struct Node *list;
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 5);
    delete_node(list, 3);
    print_list(list);
    return 0;
}
