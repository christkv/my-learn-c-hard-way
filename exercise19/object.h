#ifndef _object_h
#define _object_h

typedef enum {
  NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
  char *description;
  // Function pointer to an init function
  int (*init) (void *self);
  // Function pointer to description function
  void (*describe) (void *self);
  // Function pointer to the destroy function
  void (*destroy) (void *self);
  // Function pointer that returna void pointer
  void *(*move) (void *self, Direction direction);
  // Attack function
  int (*attack) (void *self, int damage);
} Object;

int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif