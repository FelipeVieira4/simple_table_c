#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
  int *values;
  size_t capacity;
  size_t count;
}table_s;

void init(table_s *t, size_t init_capacity){
  t->values=malloc(init_capacity*sizeof(int));

  if(!t->values){
    printf("Error de Alocação de mémoria!");
    exit(1);
  }

  t->count=0;
  t->capacity=init_capacity;
  
  return;
}

void push_value(table_s *t, int value){

  if (t->count>=t->capacity){
    t->capacity+=4;
    int *temp_values=realloc(t->values, t->capacity*sizeof(int));
    if (!temp_values){
      printf("Error realocar lista da table");
      exit(1);
    }

    t->values=temp_values;
  }

  t->values[t->count++]=value;
  return;
}

void free_table(table_s *t){
  free(t->values);
  t->values=NULL;
  t->capacity=0;
  t->count=0;
  
  return;
}

int main(void){
  table_s table;

  init(&table, 2);

  push_value(&table, 25);
  push_value(&table, 50);
  push_value(&table, 75);

  for(unsigned short int i=0;i<table.count;i++){
    printf("%d\n",table.values[i]);
  }

  push_value(&table, 100);

  for(unsigned short int i=0;i<table.count;i++){
    printf("%d\n",table.values[i]);
  }
  
  return 0;
}
