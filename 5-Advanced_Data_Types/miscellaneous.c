#include "finalProject.h"

struct fileList * append(struct fileList * end, struct fileList * ptr){
    end->next = ptr;
    return ptr;
}
