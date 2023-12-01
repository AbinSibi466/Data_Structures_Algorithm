#include<stdio.h>
int dq[100];
int front = -1, rear = -1;
#define size 5 
void front_insert(int z)
{
     if((front == 0 && rear == size-1) || (front == rear +1))
     {
        printf("dequeue is full");
     }
     else if ((front == -1)&& (rear == -1))
     {
        front = rear = 0;
        dq[front]= z;
     }
     else if ((front == -1) && (rear == -1))
     {
        front = rear = 0;
        dq[front] = z ;
     }
     else if (front == 0)
     {
        front = size -1 ;
        dq[front] = z; 
     }
       else{
                front = front -1;
                dq[front]= z;

       }
     }

     void rear_insert(int z)
     {
        if ((front== 0 && rear == size-1) || (front == rear +1))
        {
            printf("deque is full");
                }
                else if(front == -1 && rear == -1)
                {
                    rear = 0;
                    dq[rear]= z;
             
                }
                else 
                {
                    rear++;
                    dq[rear] = z;

                }
     }

     void front_dequeue()
     {
        if((front == -1) && (rear == -1))
        {
            printf("No element to delete");
        }
        else if (front == rear)
        {
printf("\n the deleted element from the front is %d",dq[front]);
        front = -1;
        rear = -1; 
        }
     else if (front == size -1)
     {
        printf("\n The deleted element fron the front %d",dq[front]);
        front = 0; 
     }
     else 
     {
        printf("\n The Deleted element from the front %d",dq[front]);
     }
     }
     void dequeue_rear()
     {
        if(front == -1 && rear == -1)
        {
            printf("\n No element inside queue");
        
        }
        else if (front == rear)
        {
            printf("\n deleted element in rear %d",dq[rear]);
             front = -1;
             rear = -1;
        }
        else if (rear == 0)
        {
            printf("\n The deleted element %d",dq[rear]);
            rear = size -1 ;
        }
        else 
        {
            printf("\n Deleted element %d",dq[rear]);
            rear = rear -1; 
        }
     }

        void display()
        {
            int i = front;
            printf("\n Elements inside double ended queue");
            while(i!= rear)
            {
                printf("%d", dq[i]);
                i = (i+1)%size;
            }
            printf("%d",dq[rear]);
        }
        int main()
        {
            front_insert(-5);
            front_insert(23);
            rear_insert(17);
            rear_insert(12);
            rear_insert(47);
            display();
            front_dequeue();
            dequeue_rear();
            display();
            return 0;
        }
        