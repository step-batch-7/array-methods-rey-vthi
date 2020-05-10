#include "array.h"
#include <stdlib.h>

Array_ptr create_dynamic_array(int length)
{
  Array_ptr dynamic_array = malloc(sizeof(Array));
  dynamic_array->array = malloc(length * sizeof(Int_ptr));
  dynamic_array->length = 0;
  return dynamic_array;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr result = create_dynamic_array(src->length);
  ITERATE(0,src->length)
  {
    result->array[index] = (*mapper)(src->array[index]);
    result->length++;
  }
  return result;
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  Array_ptr result = create_dynamic_array(src->length);
  ITERATE(0,src->length)
  {
    if((*predicate)(src->array[index]))
    {
      result->array[result->length] = src->array[index];
      result->length++;
    }
  }
  Array_ptr filtered_list = copy_list(result);
  free(result);
  return filtered_list;
}

int reduce(Array_ptr src, int init, Reducer reducer)
{
   ITERATE(0,src->length)
  {
    init = (*reducer)(init, src->array[index]);
  }
  return init;
}

Array_ptr copy_list(Array_ptr src)
{
  Array_ptr copy_of_list = create_dynamic_array(src->length);
  ITERATE(0,src->length)
  {
    copy_of_list->array[index] = src->array[index];
    copy_of_list->length++;
  }
  return copy_of_list;
}
