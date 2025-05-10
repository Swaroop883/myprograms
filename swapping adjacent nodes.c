#include<stdio.h>
#include<stdlib.h>

struct node {
    int n;
    struct node* p;
};

struct node* create(int val, struct node* ptr) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->n = val;
    newnode->p = NULL;
    if (ptr != NULL) {
        ptr->p = newnode;
    }
    return newnode;
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;
    int sz, val;
    scanf("%d", &sz);
    if (!(0 <= sz && sz <= 100)) {
        return 0;
    }

    for (int i = 0; i < sz; i++) {
        scanf("%d", &val);
        if (!(0 <= val && val <= 100)) {
            return 0;
        }
        if (head == NULL) {
            head = create(val, head);
            tail = head;
        } else {
            tail = create(val, tail);
        }
    }

    int even_count = (sz + 1) / 2;
    int odd_count = sz / 2;

    struct node** even = (struct node**)malloc(sizeof(struct node*) * even_count);
    struct node** odd = (struct node**)malloc(sizeof(struct node*) * odd_count);

    struct node* temp = head;
    int e = 0, o = 0, index = 0;
    while (temp != NULL) {
        if (index % 2 == 0) {
            even[e++] = temp;
        } else {
            odd[o++] = temp;
        }
        temp = temp->p;
        index++;
    }

    // Re-link nodes: even -> odd -> even -> odd ...
    struct node* new_head = even[0];
    temp = new_head;
    int i = 1, ev = 1, od = 0;
    while (ev < even_count || od < odd_count) {
        if (od < odd_count) {
            temp->p = odd[od++];
            temp = temp->p;
        }
        if (ev < even_count) {
            temp->p = even[ev++];
            temp = temp->p;
        }
    }
    temp->p = NULL; // end the list

    // Print the rearranged list
    temp = new_head;
    while (temp != NULL) {
        printf("%d\n", temp->n);
        temp = temp->p;
    }

    return 0;
}
