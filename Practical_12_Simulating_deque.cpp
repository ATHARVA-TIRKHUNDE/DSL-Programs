#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

class dqueue
{
    int data[MAX];
    int rear, front, item;

public:
    dqueue()
    {
        rear = -1;
        front = -1;
    }
    void insertR(int x);
    void deleteF();
    void insertF(int item);
    void deleteR();
    void display();
};

void dqueue::insertR(int x)
{
    if (rear >= MAX)
    {
        cout << "\nQueue is overflow";
        return;
    }

    if (front == -1)
        front = front + 1;
    data[++rear] = x;
    cout << "\nInserted : " << x;
}

void dqueue::deleteF()
{
    if (front == -1 || front > rear)
    {
        cout << "\nQueue is underflow";
        return;
    }
    item = data[front];
    cout << "\nDeleted : " << item;
    front = front + 1;
}

void dqueue::insertF(int item)
{
    int i, j;

    if (front == -1)
        front++;
    i = front - 1;

    while (i >= 0)
    {
        data[i + 1] = data[i];
        i--;
    }
    j = rear;
    while (j >= front)
    {
        data[j + 1] = data[j];
        j--;
    }
    rear++;
    data[front] = item;
    return;
}

void dqueue::deleteR()
{
    item = data[rear];
    data[rear] = -1;
    rear--;
    return;
}
void dqueue::display()
{
    if (front == -1 || front > rear)
        cout << "Queue is empty";

    for (int i = front; i <= rear; i++)
        cout << data[i] << " ";
}

int main()
{

    int ch;
    dqueue Q;
    while (1)
    {
        cout << "\n1.insert by rear \n2.delete by front \n3.insert by front \n4.delete by rear \n5.display \n6.exit";
        cout << "\nEnter ur choice : ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "\nEnter the job no: ";
                cin >> ch;
                Q.insertR(ch);
                break;

            case 2:
                Q.deleteF();
                break;

            case 3:
                cout << "\nEnter the job no: ";
                cin >> ch;
                Q.insertF(ch);
                break;

            case 4:
                Q.deleteR();
                break;

            case 5:
                Q.display();
                break;

            case 6:
                exit(0);
        }
    }

return (0);
}