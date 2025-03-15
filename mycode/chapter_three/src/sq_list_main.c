#include "sq_list.h"
#include <stdio.h>
int main() {
    sq_list L;
    init_list(&L);
    printf("List length: %d\n", get_list_length(&L));
    printf("List is empty: %d\n", list_is_empty(&L));
    return 0;
}