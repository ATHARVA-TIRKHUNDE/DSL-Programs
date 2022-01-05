/*
GROUP E-14
Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. 
Write C++ program to simulate the system using circular queue using array.
*/

#include <iostream>
#include <windows.h>

using namespace std;
const int MAX = 5;

class PizzaParlour
{
    int front, rear;
    int orders[MAX];

public:
    PizzaParlour()
    {
        front = rear = -1 ;
    }
    bool addOrder(int data);
    void serveOrder();
    void display();
    void intro();
};
bool PizzaParlour::addOrder(int id)
{
    if (rear == -1)
    {
        front = rear = 0;
        orders[rear] = id;
        return true;
    }
    else
    {
        int pos = (rear + 1) % MAX;
        if (pos == front)
        {
            cout << "\nCafe is Full.Please wait.\n";
            return false;
        }
        else
        {
            rear = pos;
            orders[rear] = id;
            return true;
        }
    }
}
void PizzaParlour::serveOrder()
{
    if (front == -1)
    {
        cout << "\nNo Orders in Cafe.[Cafe is Empty)";
        return;
    }
    else
    {
        cout << "\nOrder No. "
             << " PIZORD_" << orders[front] << " is processed.";
        if (front == rear) //only one order
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}
void PizzaParlour::display()
{
    int i = 0;
    if (front == -1)
    {
        cout << "\nCafe is Empty.No orders.\n";
        return;
    }
    else
    {
        cout << "Pending Order's : \n";
        for (i = front; i != rear; i = ((i + 1) % MAX))
        {
            cout << " PIZORD_" << orders[i] << "\n";
        }
        cout << " PIZORD_" << orders[rear];
    }
}
void PizzaParlour::intro()
{
    char name[100] = {"\n                       ***( PIZZA WALA PARLOR )***                       \n"};  
    cout << name;
    cout << "\n_______________________________________________________________________________\n";
    cout << "\n\n_____________________ MENU _______________________\n";
    cout << "\n           1. Accept order of Pizza \n";
    cout << "           2. Serve order of Pizza \n";
    cout << "           3. Display orders to Customer\n";
    cout << "           4. Exit";
}
int main()
{
    int ch, id = 100;
    PizzaParlour q;
    cout << "\n_______________________________________________________________________________\n";
    q.intro();
    cout << "\n_______________________________________________________________________________";
    do
    {
        cout << "\n\nPlease Enter Your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            id++;
            if (q.addOrder(id))
            {
                cout << "Order id is : PIZORD_" << id;
                cout << "\nThank You For Your Order ";
            }
            else
            {
                id--;
            }
            break;
        case 2:
            q.serveOrder();
            break;
        case 3:
            q.display();
            break;
        }
    } while (ch != 4);
    cout << "\nThank You.Keep Visiting.";
}
