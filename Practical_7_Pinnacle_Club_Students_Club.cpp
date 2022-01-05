/*

* Name  : Atharva Mohan Tirkhunde 
* Class : SE 
* Div   : B
* DSL Praticle

Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member's information using singly linked list. Store student PRN and Name. Write functions to:

a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.

*/

#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    /* data */
    string prn;
    string name;
    node *next;
};

class club
{
public:

    node *current, *temp, *head, *tail, *precident, *secretary, *temp1;

    club()
    {
        head = NULL;
    }

    void members();
    void display();
    void cancel_membership();
    void remove_precident();
    void remove_secretary();
    void display_removed_precident();
    void display_removed_secretary();
    void concat(node *head);
    void total();
    void add_precident();
    void add_secratery();
    void add_new_members();

};

void club::members()
{
    char ch;
    do
    {
        current = new node;
        cout << "\nEnter PRN number. : \n";
        cin >> current->prn;
        cout << "Enter Member Name : \n";
        cin.ignore();
        getline(cin, current->name);
        current->next = NULL;

        if (head == NULL)
        {
            head = current;
            precident = current;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = current;
            tail = temp->next;
            secretary = tail;
        }

        cout << "Add New Members (y/n) : \n";
        cin >> ch;
        cout << "__________________________________________________________________________________________________";
    } while (ch == 'y' || ch == 'Y');
}

void club::add_new_members()
{
    char cm;
    do
    {
        current = new node;
        cout << "Enter PRN no :\n";
        cin >> current->prn;
        cout << "Enter Member Name : \n";
        cin.ignore();
        getline(cin, current->name);
        current->next = NULL;

        temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        temp->next = current;
        current->next = secretary;

        cout << "Add New Members (y/n) : \n";
        cin >> cm;
        cout << "__________________________________________________________________________________________________";
    } while (cm == 'y' || cm == 'Y');
}

void club::add_precident()
{
    current = new node;
    cout << "\nEnter PRN number. : \n";
    cin >> current->prn;
    cout << "Enter Member Name : \n";
    cin.ignore();
    getline(cin, current->name);
    current->next = head;
    head = current;
    precident = current;
}
void club ::add_secratery()
{
    current = new node;
    cout << "\nEnter PRN number. : \n";
    cin >> current->prn;
    cout << "Enter Member Name : \n";
    cin.ignore();
    getline(cin, current->name);
    secretary->next = current;
    secretary = current;
    tail = current;
}

void club::concat(node *current)
{
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = head;
}

void club::cancel_membership()
{
    string key;
    int flag = 0;
    cout << "Enter Name : ";
    cin.ignore();
    getline(cin, key);

    for (current = head; current->next != NULL; current = current->next)
    {
        if (current->next->name == key)
        {
            temp = current->next;
            current->next = current->next->next;
            delete temp;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "\nMember Not Found Try to Search By Correct Name : ";
    }
}
void club::remove_precident()
{
    temp = head;
    head = head->next;
    precident = head;
    delete temp;
}

void club::remove_secretary()
{
    temp = secretary;
    current = head;
    while (current->next != NULL)
    {
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
    secretary = temp;
    delete current;
}

void club::display()
{
    int count = 1;
    cout << "\n__________________________________________________________________________________________________\n";
    cout << left << setw(10) << "Sr. No" << setw(15) << "PRN No. " << setw(30) << "Name" << endl;
    cout << "__________________________________________________________________________________________________\n";
    cout << endl;
    for (current = head; current != NULL; current = current->next)
    {
        cout << left << setw(10) << count << setw(15) << current->prn << setw(30) << current->name << endl;
        count++;
        secretary = current ;
    }
    cout << "\nPrecident : " << precident->name << endl;
    cout << "Secretary : " << secretary->name << endl;
}

void club::total()
{
    int count = 1;
    for (current = head; current != NULL; current = current->next)
    {
        count++;
    }
    cout << "\n__________________________________________________________________________________________________\n";
    cout << "\nTotal Members in Club :" << count - 1 << endl;
    cout << "\n__________________________________________________________________________________________________\n";
}

void club::display_removed_precident()
{
    cout << "\nClub Precident is Change  ...";
}

void club::display_removed_secretary()
{
    cout << "\nClub Secratery is Now ...";
}

int main()
{
    club c, d;
    char ch;
    int ch2;
    cout << "\n__________________________________________________________________________________________________\n\n";
    cout << setw(75) << "Department of Computer Engineering has student's\n";
    cout << setw(80) << "                                  Dashboard of Pinnacle club                                         \n";
    cout << "__________________________________________________________________________________________________\n";

    do
    {
        cout << "\n1. Entry of Members \n";
        cout << "2. Member Details \n";
        cout << "3. Total Members of the club \n";
        cout << "4. Create & Combine Two Division Members \n";
        cout << "5. Remove Precident\n";
        cout << "6. Remove Secratery\n";
        cout << "7. Remove Member \n";
        cout << "8. Select new Precident\n";
        cout << "9. Select new Secratery\n";
        cout << "10.Add new Member \n";

        
        cout << "\nEnter Your Choice : ";
        cin >> ch2;
        cout << "\n__________________________________________________________________________________________________\n";

        switch (ch2)
        {
        case 1:
            c.members();
            break;
        case 2:
            c.display();
            break;
        case 3:
            c.total();
            break;
        case 4:
            d.members();
            d.concat(c.head);
            break;
        case 5:
            c.remove_precident();
            c.display_removed_precident();
            break;
        case 6:
            c.remove_secretary();
            c.display_removed_secretary();
            break;
        case 7:
            c.cancel_membership();
            break;
        case 8:
            c.add_precident();
            break;
        case 9:
            c.add_secratery();
            break;
        case 10:
            c.add_new_members();
            break;
        default:
            cout << "\nInvalid Choice !!!";
            break;
        }
        cout << "\nDo you Want to Continue : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << "\n                    Thank you           ";
    return 0;
}