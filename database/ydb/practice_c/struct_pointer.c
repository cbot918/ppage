#include <stdio.h>

typedef struct {
  int id;
  char name[30];

} User;

typedef struct {
  int id;
  char page[30];
} Pager;





int main(void){
  User user1;
  user1.id = 1;
  strcpy( user1.name, "yale");
  printf("id: %d\n", user1.id);
  printf("name: %s\n", user1.name);

  User* user2 = malloc(sizeof(User));
  user2->id = 2;
  strcpy( user2->name, "node");
  printf("id: %d\n", user2->id);
  printf("name: %s\n", user2->name);
  
  return 0;
}
