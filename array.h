#ifndef __ARRAY_H
#define __ARRAY_H

#define ITERATE(start, end) for (int index = start; index < end; index++)

typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

typedef Array *Array_ptr;
typedef int *Int_ptr;

Array_ptr map(Array_ptr src, Mapper mapper);
Array_ptr filter(Array_ptr src, Predicate predicate);
int reduce(Array_ptr src, int init, Reducer reducer);

Array_ptr copy_list(Array_ptr src);

Array_ptr create_dynamic_array(int length);

#endif
