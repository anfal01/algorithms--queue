#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
   char* data;
   struct Node* next;
} node;

typedef struct queue{
   struct Node* first;
   struct Node* last;
   int size;
} queue;

queue* init_queue (){
   queue* q = calloc(1, sizeof(queue));
   q->last = q->first = NULL;
   q->size = 0;                              /*  0 must not necessarily be represented by all 0 bits, cannot trust calloc  */
   return q;
}
node* init_node (char* _data) {
   node* n = calloc(1, sizeof(node));
   n->next = NULL;
   n->data = _data;
   return n;
}
node* destroy_node(node* n) {
   node* ret = n->next;
   free(n->data);
   free(n);
   return ret;
}
void destroy_queue(queue* q) {
   node* n = q->first;
   while (n != q->last) {
      n = destroy_node(n);
   }
   destroy_node(q->last);
   free(q);
}

void print_queue(queue* q) {
   node* f = q->first;

   fprintf(stdout, "Items in queue: ");
   do {
      printf("%s ",f->data);
      f = f->next;
   } while (f != q->last);
   printf("\n");
}

char* front(queue* q){
   return q->first->data;
}

void push(queue* q, char* _data) {
   node* n = init_node(_data);
   if (q->first == NULL) q->first = q->last = n;
   q->last = q->last->next = n;
   q->size++;
   fprintf(stdout, "Add: %s\n", _data);
}

int pop(queue* q){
   node* f = q->first;
   if (f == NULL) return 1;
   fprintf(stdout, "Remove: %s\n", f);
   f = f->next;
   q->size--;
   free(f);
   return 0;
}

readline(queue* q, char* newline){
   char delim[] = ",";
   int i;
   char* ptr = strtok(newline, delim);
   printf("***%s***\n", ptr);
   if(strcmp("add", ptr) == 0){
      ptr = strtok(NULL, "\n");
      push(q, ptr);
   } /* else if (strcmp("flush\n", ptr) == 0) {
      ptr = strtok(NULL, "\n");
      destroy_queue(q);
      q = init_queue();
   }*/
/*
   if (strcmp("remove\n", ptr) == 0) {
      ptr = strtok(NULL, "\n");
      pop(q);
   }
*/
   

   print_queue(q);
}

int main(void){
   queue* q = init_queue();
   char* line;
   char* newline;
   newline = calloc(512, sizeof(char));
   while (fgets(newline, 512, stdin) != NULL){
      readline(q, newline);
   }
   if (fgets(line, sizeof(line), stdin) == NULL)
      return -1;

   free(newline);
   destroy_queue(q);
   return 0;
}
