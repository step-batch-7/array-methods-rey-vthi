#include "array.h"

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

Array *filter(Array *list, Predicate predicate)
{
  Array *result = create_dynamic_array(list->length);
  ITERATE(0,list->length)
  {
    if((*predicate)(list->array[index]))
    {
      result->array[result->length] = list->array[index];
      result->length++;
    }
  }
  Array *filtered_list = copy_list(result);
  free(result);
  return filtered_list;
}