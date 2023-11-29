

#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue {
  int size;
  char* queue;
  int front;
  int rear;
} CircularQueue;

CircularQueue* initializeCircularQueue(int size) {
  CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
  queue->size = size;
  queue->queue = (char*)malloc(queue->size * sizeof(char));
  queue->front = 0;
  queue->rear = -1;
  return queue;
}

int isCircularQueueFull(CircularQueue* queue) {
  return ((queue->rear + 1) % queue->size == queue->front);
}

int isCircularQueueEmpty(CircularQueue* queue) {
  return (queue->rear == -1);
}

void enqueue(CircularQueue* queue, char element) {
  if (!isCircularQueueFull(queue)) {
    queue->rear = (queue->rear + 1) % queue->size;
    queue->queue[queue->rear] = element;
  }
}

char dequeue(CircularQueue* queue) {
  if (!isCircularQueueEmpty(queue)) {
    char element = queue->queue[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return element;
  }
  return '\0'; // Default value for empty queue
}

void displayCircularQueue(CircularQueue* queue) {
  if (!isCircularQueueEmpty(queue)) {
    int i = queue->front;
    while (i <= queue->rear) {
      printf("%c ", queue->queue[i]);
      i = (i + 1) % queue->size;
    }
  } else {
    printf("Queue is empty\n");
  }
}

int main() {
  CircularQueue* queue = initializeCircularQueue(5);

  // Enqueue elements
  enqueue(queue, 'A');
  enqueue(queue, 'B');
  enqueue(queue, 'C');

  // Display the queue
  displayCircularQueue(queue);

  // Dequeue elements
  char element = dequeue(queue);
  printf("Dequeued element: %c\n", element);
  element = dequeue(queue);
  printf("Dequeued element: %c\n", element);

  // Display the queue
  displayCircularQueue(queue);

  return 0;
}