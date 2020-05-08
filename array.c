#include "array.h"
#include <stdlib.h>

Array *create_dynamic_array(int length)
{
  Array *dynamic_array = malloc(sizeof(Array));
  dynamic_array->array = malloc(length * sizeof(int *));
  dynamic_array->length = 0;
  return dynamic_array;
}

Array *map(Array *src, Mapper mapper)
{
  Array *result = create_dynamic_array(src->length);
  ITERATE(0,src->length)
  {
    result->array[index] = (*mapper)(src->array[index]);
    result->length++;
  }
  return result;
}

Array *filter(Array *src, Predicate predicate)
{
  Array *result = create_dynamic_array(src->length);
  ITERATE(0,src->length)
  {
    if((*predicate)(src->array[index]))
    {
      result->array[result->length] = src->array[index];
      result->length++;
    }
  }
  Array *filtered_list = copy_list(result);
  free(result);
  return filtered_list;
}

int reduce(Array *src, int init, Reducer reducer)
{
   ITERATE(0,src->length)
  {
    init = (*reducer)(init, src->array[index]);
  }
  return init;
}

Array *copy_list(Array *src)
{
  Array *copy_of_list = create_dynamic_array(src->length);
  ITERATE(0,src->length)
  {
    copy_of_list->array[index] = src->array[index];
    copy_of_list->length++;
  }
  return copy_of_list;
}
