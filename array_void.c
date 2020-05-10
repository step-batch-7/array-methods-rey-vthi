#include <stdlib.h>
#include <stdio.h>
#include "array_void.h"

ArrayVoid_ptr create_ArrayVoid(int length)
{
  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));
  array_void->array = malloc(sizeof(Object) * length);
  array_void->length = 0;
  return array_void;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr result = create_ArrayVoid(src->length);
  ITERATE(0,src->length)
  {
    result->array[index] = (*mapper)(src->array[index]);
    result->length++;
  }
  return result;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  ArrayVoid_ptr result = create_ArrayVoid(src->length);
  ITERATE(0,src->length)
  {
    if ((*predicate)(src->array[index]))
    {
      result->array[result->length] = src->array[index];
      result->length++;
    }
  }
  ArrayVoid_ptr filtered_list = copy_void_list(result);
  free(result);
  return filtered_list;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  ITERATE(0,src->length)
  {
    init = (*reducer)(init, src->array[index]);
  }
  return init;
}

ArrayVoid_ptr copy_void_list(ArrayVoid_ptr src)
{
  ArrayVoid_ptr copy_of_list = create_ArrayVoid(src->length);
  ITERATE(0,src->length)
  {
    copy_of_list->array[index] = src->array[index];
    copy_of_list->length++;
  }
  return copy_of_list;
}