#include "main.h"
#include <stdlib.h>

nspe* _make_node(spe data) {
    nspe* p=NULL;
    nspe* head = (nspe*)malloc(sizeof(nspe));
    head->data = data;
    head->next = NULL;
    p = head;
}

nspe* p£»