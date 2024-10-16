#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(string url)
    {
        Node *newNode = new Node;
        newNode->data = url;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    string peek()
    {
        if (top != nullptr)
        {
            return top->data;
        }
        return "";
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class BrowserHistory
{
private:
    Stack backStack;
    Stack forwardStack;
    string current;

public:
    BrowserHistory(string homepage)
    {
        current = homepage;
    }

    void visit(string url)
    {
        backStack.push(current);
        current = url;
        while (!forwardStack.isEmpty())
        {
            forwardStack.pop();
        }
    }

    // Move back 'steps' and return the current URL
    string back(int steps)
    {
        while (steps > 0 && !backStack.isEmpty())
        {
            forwardStack.push(current);
            current = backStack.peek();
            backStack.pop();
            steps--;
        }
        return current;
    }

    string forward(int steps)
    {
        while (steps > 0 && !forwardStack.isEmpty())
        {
            backStack.push(current);
            current = forwardStack.peek();
            forwardStack.pop();
            steps--;
        }
        return current;
    }
};

int main()
{
    string command;
    string homepage;

    // Input homepage
    cin >> homepage;
    BrowserHistory browser(homepage);

    int n;
    cin >> n;

    vector<string> output;

    for (int i = 0; i < n; ++i)
    {
        cin >> command;
        if (command == "visit")
        {
            string url;
            cin >> url;
            browser.visit(url);
            output.push_back("null");
        }
        else if (command == "back")
        {
            int steps;
            cin >> steps;
            output.push_back(browser.back(steps));
        }
        else if (command == "forward")
        {
            int steps;
            cin >> steps;
            output.push_back(browser.forward(steps));
        }
    }

    // Output all results after the loop finishes
    cout << "Output: " << endl;
    for (const string &res : output)
    {
        cout << res << endl;
    }

    system("pause");
    return 0;
}
