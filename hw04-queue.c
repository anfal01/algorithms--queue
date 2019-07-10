#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
   char *data;
   struct node *next;
};

struct Queue{
   struct node *first;
   struct node *last;
   int size;
};

/* printing the queue*/ 
void printQueue(struct Queue *q){
   struct node* temp = q->first;
   fprintf(stdout, "Items in queue: ");
   while(temp->next != NULL) {
      printf("%s ",temp->data);
      temp = temp->next;
   }
   printf("\n");
}

/* Initialize Queue */
void init(struct Queue *q){
   q->first = NULL;
   q->last = NULL;
   q->size = 1;
}

char *front(struct Queue *q){
   return q->first->data;
}

/* come back to this later */
void pop(struct Queue *q){
   struct node *tmp;
   q->size--;
   
   if(q->first == NULL){
      printf("queue is empty!");
   }

   fprintf(stdout, "Remove: %s\n", q->first);
   tmp = q->first;
   q->first = q->first->next;
   free(tmp); 

}

void push(struct Queue *q, char *data) {
   
   struct node* temp;

   if (q->first == NULL) {
      fprintf(stdout, "Queue is empty!\n");
      q->first = malloc(sizeof(struct node));
      q->first->data = data;
      q->first->next = NULL;
      q->last = q->first;
   }
/*   else {
      q->last->next = malloc(sizeof(struct node));
      q->last->next->data = data;
      q->last->next->next = NULL;
      q->last = q->last->next;
   }
*/
   temp  = (struct node*)malloc(sizeof(struct node));
   temp->data = data;
   temp->next = NULL;
   q->last->next = temp;
   q->last = temp;
   fprintf(stdout, "Add: %s\n", q->last->data);
   
}

readline(struct Queue *q, char *newline){
   char delim[] = ",";
   int i;
   char *ptr = strtok(newline, delim);
   
   printf("***%s***\n", ptr);
   if(strcmp("add", ptr) == 0){
      ptr = strtok(NULL, "\n");
      push(q, ptr);
      printf("\n");
   }
/*
   if (strcmp("remove\n", ptr) == 0) {
      ptr = strtok(NULL, "\n");
      pop(q);
   }
   if(strcmp("flush\n", ptr) == 0){
      ptr = strtok(NULL, "\n");
      while(newline != NULL)
         pop(q);
   }
*/
   printQueue(q);
}

int main(void){
   struct Queue q;
   char *line;
   char *newline;
   
   init(&q);

   newline = malloc(512 * sizeof(char));

   while (fgets(newline, 512, stdin) != NULL){
      readline(&q, newline);
   }

   if (fgets(line, sizeof(line), stdin) == NULL)
      return -1;

   free(newline);

   return 0;

}
