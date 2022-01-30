#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *list_insert_tail(struct ListNode *tail, int val) {
    struct ListNode *new;

    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->val = val;
    new->next = NULL;
    if (tail == NULL) {
        return new;
    }
    tail->next = new;
    return new;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *ans, *ans_tail, *l1ptr, *l2ptr;
    int sum, carry;
    bool first;

    first = true;
    ans = NULL;
    ans_tail = NULL;
    l1ptr = l1;
    l2ptr = l2;
    carry = 0;
    while (l1ptr && l2ptr) {
        sum = l1ptr->val + l2ptr->val + carry;
        carry = sum / 10;
        sum %= 10;
        ans_tail = list_insert_tail(ans_tail, sum);
        if (first) {
            first = false;
            ans = ans_tail;
        }
        l1ptr = l1ptr->next;
        l2ptr = l2ptr->next;
    }
    while (l1ptr) {
        sum = l1ptr->val + carry;
        carry = sum / 10;
        sum %= 10;
        ans_tail = list_insert_tail(ans_tail, sum);
        l1ptr = l1ptr->next;
    }
    while (l2ptr) {
        sum = l2ptr->val + carry;
        carry = sum / 10;
        sum %= 10;
        ans_tail = list_insert_tail(ans_tail, sum);
        l2ptr = l2ptr->next;
    }
    if (carry) {
        ans_tail = list_insert_tail(ans_tail, carry);
        carry = 0;
    }
    return ans;
}

void list_print(struct ListNode *l) {
    struct ListNode *traverse;
    bool first;

    traverse = l;
    first = true;
    while (traverse) {
        if (first) {
            first = false;
            printf("%d", traverse->val);
        } else {
            printf(" %d", traverse->val);
        }
        traverse = traverse->next;
    }
    putchar('\n');
}

void list_free(struct ListNode *l) {
    struct ListNode *pre, *cur;

    cur = l;
    while (cur->next) {
        pre = cur;
        cur = cur->next;
        free(pre);
    }
    free(cur);
}

int main() {
    struct ListNode *l1, *l1_tail, *l2, *l2_tail, *ans;
    char input[4096];
    char *inptr;
    char delm[] = " ";
    char *saveptr;

    l1 = NULL;
    l2 = NULL;
    l1_tail = NULL;
    l2_tail = NULL;

    inptr = input;
    if (fgets(input, 4096, stdin) == NULL) {
        fprintf(stderr, "Line 1 is empty.\n");
        exit(1);
    }
    inptr = strtok_r(inptr, delm, &saveptr);
    l1 = list_insert_tail(l1, atoi(inptr));
    l1_tail = l1;
    while (inptr) {
        inptr = strtok_r(NULL, delm, &saveptr);
        if (inptr) {
            l1_tail = list_insert_tail(l1_tail, atoi(inptr));
        }
    }

    inptr = input;
    if (fgets(input, 4096, stdin) == NULL) {
        fprintf(stderr, "Line 2 is empty.\n");
        exit(1);
    }
    inptr = strtok_r(inptr, delm, &saveptr);
    l2 = list_insert_tail(l2, atoi(inptr));
    l2_tail = l2;
    while (inptr) {
        inptr = strtok_r(NULL, delm, &saveptr);
        if (inptr) {
            l2_tail = list_insert_tail(l2_tail, atoi(inptr));
        }
    }

    ans = addTwoNumbers(l1, l2);

    list_print(ans);
    list_free(l1);
    list_free(l2);
    list_free(ans);
    return 0;
}
