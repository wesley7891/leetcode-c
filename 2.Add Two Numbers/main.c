#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int length_of_list(struct ListNode* l) {
    int length = 0;
    if (l == NULL) return 0;
    
    struct ListNode *p = l;
    while (p != NULL) {
        length ++;
        p = p->next;
    }

    return length;
}

void puts_list(struct ListNode* l) {
    
    struct ListNode* p = l;
    while (p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    }
}

struct ListNode* create_list(int* arr, int size) {
    struct ListNode* head = NULL;
    struct ListNode* p = NULL;

    for (int i = 0; i < size; i ++) {
        if (i == 0) {
            head = (struct ListNode *)malloc(sizeof(struct ListNode));
            head->val = arr[i];
            head->next = NULL;
            p = head;
        } else {
            struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val = arr[i];
            temp->next = NULL;
            p->next = temp;
            p = temp;
        }
    }

    return head;
}

struct ListNode* reverse_list(struct ListNode* l) {
    struct ListNode* head = NULL;

    while(l != NULL) {
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = l->val;
        if (head == NULL) {
            head = temp;
            head->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }

        l = l->next;
    }

    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len_of_l1 = length_of_list(l1);
    int len_of_l2 = length_of_list(l2);
    int min_len = len_of_l1 < len_of_l2 ? len_of_l1 : len_of_l2;

    int i = 0;
    int is_upped = 0;

    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* p3 = NULL;
    struct ListNode* prev_p = NULL;

    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    p->val = 0;
    p->next = NULL;

    for (i = 0; i < min_len; i ++) {
        int temp = (p1->val + p2->val + is_upped) % 10;
        is_upped = (p1->val + p2->val + is_upped) / 10;

        p->val = temp;
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        prev_p = p;
        p = p->next;
        p->next = NULL;

        p1 = p1->next;
        p2 = p2->next;
    }

    p3 = (len_of_l1 == len_of_l2) ? NULL : ((len_of_l1 > len_of_l2) ? p1 : p2);
    while(NULL != p3) {
        int temp = (p3->val + is_upped) % 10;
        is_upped = (p3->val + is_upped) / 10;

        p->val = temp;
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        prev_p = p;
        p = p->next;
        p->next = NULL;

        p3 = p3->next;
    }

    if (is_upped == 1) {
        p->val = is_upped;
    } else {
        if (NULL != prev_p->next) {
            free(prev_p->next);
        }
        prev_p->next = NULL;
    }

    return head;
}

int main() {
    
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    struct ListNode* head = addTwoNumbers(create_list(arr1, 3), create_list(arr2, 3));
    puts_list(head);
    printf("\n---------------------\n");

    int arr3[] = {0};
    int arr4[] = {0, 1};
    puts_list(addTwoNumbers(create_list(arr3, 1), create_list(arr4, 2)));

    printf("\n---------------------\n");

    int arr5[] = {0};
    int arr6[] = {0};
    puts_list(addTwoNumbers(create_list(arr5, 1), create_list(arr6, 1)));

    return 0;
}