#include <stdio.h>
#include <stdlib.h>

typedef struct user User;
typedef int (*func_t)(User *);

struct user {
  int a, b;
  func_t add, sub; 
};

static int add_impl(User *self){
  return self->a + self->b;  
}

static int sub_impl(User *self) {
  return self->a - self->b;
}

int init_user(User **self) {
  if (NULL == (*self = malloc(sizeof(User)))) return -1;
  (*self)->a = 0; (*self)->b = 0;
  (*self)->add = add_impl; (*self)->sub = sub_impl;
  return 0;
}

int main(int argc, char *argv[]) {
  User *o = NULL; 
  init_user(&o);
  o->a = 9922; o->b = 5566;
  printf("add=%d, sub=%d\n", o->add(o), o->sub(o));
 
  return 0;
}




