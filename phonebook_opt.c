#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{
    /* Look up lastName whether in phonebook */
    while (pHead) {
        if (!strcasecmp(lastName, pHead->lastName))
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* Append lastName to phonebook */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}
