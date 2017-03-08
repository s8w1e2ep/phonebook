#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "phonebook_hash.h"

entry *findName(char lastName[], entry *pHead)
{
    /* Look up lastName whether in phonebook */
    unsigned int hashValue = BKDRHash(lastName);

    pHead = hashTable[hashValue];
    while(pHead) {
        if(!strcasecmp(lastName, pHead->lastName )) {
            return pHead;
        }
        pHead = pHead->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* Append lastName to phonebook */
    unsigned int hashValue = BKDRHash(lastName);

    e = (entry *) malloc(sizeof(entry));
    e->pNext = hashTable[hashValue];
    strcpy(e->lastName, lastName);
    e->detailEntry = NULL;
    e->pNext = NULL;
    hashTable[hashValue] = e;

    return e;
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131, hash = 0;

    while(*str) {
        hash = hash * seed + (*str++);
    }

    return hash % MAX_HASH_TABLE_SIZE;
}

