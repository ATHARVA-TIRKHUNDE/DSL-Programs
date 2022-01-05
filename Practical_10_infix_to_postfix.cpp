/*
GROUP D-11
Implement C++ program for expression conversion as infix to postfix and 
its evaluation using stack based on given conditions: 1. Operands and operator, 
both must be single character. 2. Input Postfix expression must be in a desired format. 
3. Only '+', '-', '*' and '/ ' operators are expected.
*/

#include <iostream>
using namespace std;
#define SIZE 50 //Size of Stack


class conversion
{
    char s[SIZE];
    int top = -1;
    char infx[50], postfx[50];

public:
    void push(char) ;
    char pop();
    int pre(char);
    void infix_postfix();
};

void conversion::push(char elem)
{
    s[++top] = elem;
}

char conversion::pop()
{
    return (s[top--]);
}

int conversion::pre(char e)
{ 
    switch (e)
    {
        case '#':
            e = 1;
            break;
        case '(':
            e = 1;
            break;
        case '+':
            e = 2;
            break;
        case '-':
            e = 2;
            break;
        case '*':
            e = 3;
            break;
        case '/':
            e = 3;
            break;
    }
    return e;
}

void conversion::infix_postfix()
{
    char ch, elem;
    int i = 0, j = 0;
    cout << "\nEnter the Infix Expression : ";
    cin.getline(infx,SIZE) ;
    push('#'); //# represent end of input expression
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfx[j++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfx[j++] = pop();
            elem = pop(); //Remove 
        }
        else
        { 
            while (pre(s[top]) >= pre(ch))
                postfx[j++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
    {
        postfx[j++] = pop();
    }
    postfx[j] = '\0'; 
    cout << "Postfix Expression : " << postfx <<endl;
}

int main()
{
    conversion s;
    char infix[SIZE],postfix;
    while (true)
    {
        s.infix_postfix();
    }
    return 0;
}
 