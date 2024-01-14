#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int ticket_id;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int ticket_id) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->ticket_id = ticket_id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* createTreeLevelOrder(int tickets[], int size) {
    if (size <= 0) {
        return NULL;
    }

    struct TreeNode* root = createNode(tickets[0]);
    struct TreeNode* queue[size];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < size) {
        struct TreeNode* current = queue[front++];

        int left_ticket = tickets[i++];
        if (left_ticket != -1) {
            current->left = createNode(left_ticket);
            queue[rear++] = current->left;
        }

        int right_ticket = tickets[i++];
        if (right_ticket != -1) {
            current->right = createNode(right_ticket);
            queue[rear++] = current->right;
        }
    }

    return root;
}

void inorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("Ticket ID: %d\n", node->ticket_id);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        printf("Ticket ID: %d\n", node->ticket_id);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("Ticket ID: %d\n", node->ticket_id);
    }
}

int main() {
    int movie_tickets[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(movie_tickets) / sizeof(movie_tickets[0]);

    struct TreeNode* root_level_order = createTreeLevelOrder(movie_tickets, size);

    printf("Inorder Traversal:\n");
    inorderTraversal(root_level_order);

    printf("\nPreorder Traversal:\n");
    preorderTraversal(root_level_order);

    printf("\nPostorder Traversal:\n");
    postorderTraversal(root_level_order);

    return 0;
}