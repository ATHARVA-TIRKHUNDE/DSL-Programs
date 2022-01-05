#include <iostream>
#include <stdlib.h>
using namespace std;

class node;
class sll;

class node 
{
   int data;
   node *next;
   friend class sll;
};

class sll
{
    node *head,*current,*temp;
    public :
    void push();
    void pop();
    void display();
};

void sll::push() 
{
    current = new node;
    cout<<"Enter value to be pushed:"<<endl;
    cin>>current->data;
    current->next = head;
    head = current;
}

void sll::pop() 
{
    if(head == NULL)
    {
        cout<<"Stack Underflow"<<endl;    
    }
    else 
    {
        cout<<"The popped element is "<< head->data <<endl;
        head = head->next;
    }
}

void sll::display() 
{
    temp = new node ;
    if( head == NULL )
        cout<<"stack is empty";
    else 
    {
        cout<<"Stack elements are: ";
        while (head != NULL) 
        {
            cout<< head->data <<" ";
            head=head->next;
        }
    }
   cout<<endl;
}

int main() 
{
    system("cls");
    sll s;
    int ch;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl;
    do 
    {
        cout<<"Enter choice : ";
        cin>>ch;
        switch(ch) 
        {
            case 1: 
                s.push();
                break;  
            case 2: 
                s.pop();
                break;
            case 3: 
                s.display();
                break;
            case 4: 
                cout<<"Exit"<<endl;
                break;
            default: 
                cout<<"Invalid Choice"<<endl;
        }
    }while(ch!=4);
    return 0;
}
