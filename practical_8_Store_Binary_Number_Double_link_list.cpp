#include <iostream>
using namespace std;

struct node
{
    int no;
    node *prev;
    node *next;
};

class Binary
{
    // int i;
public:
    node *head, *tail, *temp, *temp1, *current;
    void create();
    void display();
    Binary add(Binary, Binary, Binary);
    void onecompl();
    void twocompl();
    Binary()
    {
        head = NULL;
        tail = NULL;
        temp = NULL;
        temp1 = NULL;
    }
};

void Binary::create()
{
    int b, i;
    cout << "\nEnter the Number of Bits : ";
    cin >> b;
    cout << endl;
    head = NULL;
    for (i = 0; i < b; i++)
    {
        temp = new node;
        cout << "Enter the digit ( 1/0 ) : ";
        cin >> temp->no;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;            
        }
        else
        {
            temp1 = head;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
            temp->prev = temp1;
            tail = temp;
        }
    }
}
Binary Binary::add(Binary d1, Binary d2, Binary d3)
{
    int x, y, z, c = 0;
    d3.tail = NULL;
    d3.head = NULL;
    x = y = 0;
    while (d1.tail != NULL || d2.tail != NULL)
    {
        if (d1.tail != NULL)
        {
            x = d1.tail->no;
            d1.tail = d1.tail->prev;
        }
        if (d2.tail != NULL)
        {
            y = d2.tail->no;
            d2.tail = d2.tail->prev;
        }
        z = (x + y + c) % 2;
        c = (x + y + c) / 2;
        current = new node;
        current->no = z;
        current->next = NULL;
        current->prev = NULL;
        if (d3.tail == NULL)
        {
            d3.tail = current;
        }
        else
        {
            temp = d3.tail;
            while (temp->prev != NULL)
            {
                temp = temp->prev;
            }
            temp->prev = current;
            current->next = temp;
            d3.head = current;
        }
        // if (d3.head == NULL)
        // {
        // 	d3.head = new node;
        // 	d3.head->next = d3.head->prev = NULL;
        // }
        // else
        // {
        // 	d3.head->prev = new node;
        // 	(d3.head->prev)->next = d3.head;
        // 	d3.head->prev = (d3.head->prev);
        // 	d3.head = d3.head->prev;
        // 	d3.head->prev = NULL;
        // }
        // d3.head->no = z;
    }
    if (c == 1)
    {
        d3.head->prev = new node;
        d3.head->prev->next = d3.head;
        d3.head = d3.head->prev;
        d3.head->prev = NULL;
        d3.head->no = c;
    }
    return d3;
}
void Binary::onecompl()
{
    for (temp = tail; temp != NULL; temp = temp->prev)
    {
        if (temp->no == 0)
        {
            temp->no = 1;
        }
        else if (temp->no == 1)
        {
            temp->no = 0;
        }
    }
}

void Binary::twocompl()
{
    int c;
    int j = 0;
    for (temp1 = tail; temp1 != NULL; temp1 = temp1->prev)
    {
        if (j == 0)
        {
            temp1->no = temp1->no + 1;
            if (temp1->no == 2)
            {
                temp1->no = 0;
                c = 1;
            }
            else if (temp1->no == 0)
            {
                temp1->no = 0;
                c = 0;
            }
            else
            {
                temp1->no = 1;
                c = 0;
            }
        }
        else
        {
            temp1->no = temp1->no + c;
            if (temp1->no == 1)
            {
                temp1->no = 1;
                c = 0;
            }
            else if (temp1->no == 0)
            {
                temp1->no = 0;
                c = 0;
            }
            else
            {
                temp1->no = 0;
                c = 1;
            }
        }
        j = j + 1;
    }
    if (c == 1)
    {
        cout << "\nCarry : " << 1;
    }
}

void Binary::display()
{
    for (temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->no << " ";
    }
}

int main()
{
    int ch;
    Binary b1, b2, b3;

    while (true)
    {
        cout << "\n---------------------------------------------------------------------------------------------------\n";

        cout << "\n1. Enter 1st binary no. ";
        cout << "\n2. Enter 2nd binary no. ";
        cout << "\n3. Add binary no.s";
        cout << "\n4. 1's and 2's compliment of binary no.";
        cout << "\n\nEnter the choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the First Binary Number  ";
            b1.create();
            cout << "\nThe First Binary Number is : ";
            b1.display();
            break;

        case 2:
            cout << "\nEnter the Second Binary Number : ";
            b2.create();
            cout << "\nThe Second Binary Number is : ";
            b2.display();
            break;

        case 3:
            if (b2.head == NULL)
            {
                cout << "\nAdition is: ";
                b1.display();
            }
            else if (b1.head == NULL)
            {
                cout << "\nAdition is: ";
                b2.display();
            }
            else
            {
                cout << "\nAdition is: ";
                b3 = b3.add(b1, b2, b3);
                b3.display();
            }

            break;

        case 4:
            if (b1.head != NULL)
            {
                cout << "\nOne's of First Compliment : ";
                b1.onecompl();
                b1.display();
                cout << "\ntwo's of First Compliment : ";
                b1.twocompl();
                b1.display();
            }
            if (b2.head != NULL)
            {
                cout << "\nOne's of Second Compliment : ";
                b2.onecompl();
                b2.display();
                cout << "\ntwo's of Second Compliment : ";
                b2.twocompl();
                b2.display();
            }
            break;

        default:
            break;
            cout << "\n---------------------------------------------------------------------------------------------------\n";
        }
    }
}