#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_HASH_TABLE_SIZE 44887

/* line to set OPT properly */
#define HASH 1
typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detail *detailEntry;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *hashTable[MAX_HASH_TABLE_SIZE];

unsigned int BKDRHash(char *str);
entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
