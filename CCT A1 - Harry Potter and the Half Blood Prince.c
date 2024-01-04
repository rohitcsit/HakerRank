/* Harry Potter has now learned about the elder wand which is the strongest wand in the wizarding world.
Harry realises that the elder want can be represented as a linked list of integers. (Wow, Just Wow).
Harry realises that it could be devastating if this wand went into wrong hands and decides to mess with it.
He wants to reverse a part of this wand. Harry has the idea and you are the executioner. Help him.

image

Harry tells you the positions on the elder wand, the starting point and the ending point to the section in the wand that is to be reversed.

Formally, Write a function that reverses a linked list from index n to index m.

For example: Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Constraints

Your algorithm must be linear in time complexity.

  */


solution in c

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
    int val;
    struct LinkedListNode *next;
} LinkedListNode;

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if (head == NULL) {
        head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        head->val = val;
        head->next = NULL;
        tail = head;
    } else {
        LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

LinkedListNode* reverseSublist(LinkedListNode* head, int n, int m) {
    if (head == NULL || n >= m) {
        return head;
    }

    LinkedListNode *dummy = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    dummy->next = head;
    LinkedListNode *prev = dummy;

    // Move to the (n-1)th node
    for (int i = 0; i < n - 1; ++i) {
        if (prev == NULL) {
            return head; // Invalid range
        }
        prev = prev->next;
    }

    LinkedListNode *current = prev->next;
    LinkedListNode *nextNode = NULL;
    LinkedListNode *tail = current;

    // Reverse the sublist from n to m
    for (int i = 0; i <= m - n; ++i) {
        LinkedListNode *temp = current->next;
        current->next = nextNode;
        nextNode = current;
        current = temp;
    }

    prev->next = nextNode;
    tail->next = current;

    return dummy->next;
}

int main() {
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    LinkedListNode *res;
    int head_size = 0;

    LinkedListNode *head = NULL;
    LinkedListNode *head_tail = NULL;

    scanf("%d\n", &head_size);
    for (int i = 0; i < head_size; i++) {
        int head_item;
        scanf("%d", &head_item);
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if (i == 0) {
            head = head_tail;
        }
    }

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    res = reverseSublist(head, n, m);
    while (res != NULL) {
        fprintf(f, "%d ", res->val);
        res = res->next;
    }

    fclose(f);
    return 0;
}




