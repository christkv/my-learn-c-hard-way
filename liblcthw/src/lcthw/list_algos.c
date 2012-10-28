#include "list_algos.h"

int List_bubble_sort(List *list, List_compare cmp) {
  if(List_count(list) <= 1) {
    return 0;
  }

  int swapped = 0;

  do {
    swapped = 0;

    LIST_FOREACH(list, first, next, cur) {
      if(cur->next) {
        if(cmp(cur->value, cur->next->value) > 0) {
          ListNode_swap(cur, cur->next);
          swapped = 1;
        }
      }
    }
  } while(swapped != 0);

  return 0;
}

List *List_merge_sort(List *list, List_compare cmp) {
  return list;
}
