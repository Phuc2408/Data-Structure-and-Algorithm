#include <iostream>
using namespace std;
int x = 1;
class node
{
public:
    int data;
    node *next;
};
class linkList
{
public:
    node *pHead;
    node *pTail;
    int total = 0;

public:
    linkList()
    {
        pHead = nullptr;
        pTail = nullptr;
    }
    node *createNode(int x)
    {
        node *temp = new node;
        temp->data = x;
        temp->next = nullptr;
        return temp;
    }
    node *addElement(int x)
    {
        if (pHead == nullptr)
        {
            pHead = createNode(x);
            pTail = pHead;
            total++;
            return pHead;
        }
        else
        {
            node *temp = createNode(x);
            pTail->next = temp;
            pTail = temp;
            total++;
            return temp;
        }
    }
    node *addFromHead(int x)
    {
        if (pHead == nullptr)
        {
            pHead = createNode(x);
            pTail = pHead;
            total++;
            return pHead;
        }
        else
        {
            node *temp = createNode(x);
            temp->next = pHead;
            pHead = temp;
            total++;
            return temp;
        }
    }
    void printList()
    {
        node *l = pHead;
        if (l == nullptr)
        {
            cout << "Danh sach rong" << endl;
        }
        while (l != nullptr)
        {
            cout << l->data << " ";
            l = l->next;
        }
    }
    void input(int x)
    {
        do
        {
            cin >> x;
            if (x != 0)
            {
                this->addElement(x);
            }
        } while (x);
    }
    void deleteByValue(int value)
    {
        node *current = pHead;
        node *previous = pHead;
        if (pHead->data == value)
        {
            pHead = pHead->next;
            delete current;
            total--;
        }
        else
        {
            while (current != nullptr)
            {
                if (current->data == value)
                {
                    if (current == pTail)
                    {
                        delete current;
                        pTail = previous;
                        total--;
                    }
                    else
                    {
                        node *temp = current;
                        current = current->next;
                        previous->next = current;
                        delete temp;
                        total--;
                        return;
                    }
                }
                previous = current;
                current = current->next;
            }
        }
    }
    ~linkList()
    {
        while (pHead != nullptr)
        {
            node *p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
};
void cau1(linkList l)
{
    cout << "Enter your list 1: ";
    l.input(1);
    int count = 0;
    node *p = l.pHead;
    if (l.total % 2 != 0)
    {
        while (count != l.total / 2)
        {
            p = p->next;
            count++;
        }
        cout << p->data << endl;
    }
    else
    {
        while (count != l.total / 2 - 1)
        {
            p = p->next;
            count++;
        }
        cout << p->data << " " << p->next->data << endl;
    }
}
void cau2(linkList l)
{
    cout << "Enter your list 1: ";
    l.input(1);
    node *slow = l.pHead;
    node *fast = l.pHead;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle detected!" << endl;
            return;
        }
    }
    cout << "No cycle found." << endl;
}
void cau3(linkList l1, linkList l2)
{
    cout << "Enter your list 1: ";
    l1.input(1);
    cout << "Nhap list 2: ";
    l2.input(x);
    linkList l3;
    node *p1 = l1.pHead;
    node *p2 = l2.pHead;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->data < p2->data)
        {
            l3.addElement(p1->data);
            p1 = p1->next;
        }
        else
        {
            l3.addElement(p2->data);
            p2 = p2->next;
        }
    }
    while (p2 != nullptr)
    {
        l3.addElement(p2->data);
        p2 = p2->next;
    }
    while (p1 != nullptr)
    {
        l3.addElement(p1->data);
        p1 = p1->next;
    }
    l3.printList();
}
void cau4(linkList l1, linkList l2)
{
    cout << "Enter your list 1: ";
    l1.input(1);
    cout << "Nhap list 2: ";
    l2.input(x);
    node *p = l1.pHead;
    while (p != nullptr)
    {
        node *p1 = l2.pHead;
        while (p1 != nullptr)
        {
            if (p->data == p1->data)
            {
                cout << p->data << " ";
                break;
            }
            p1 = p1->next;
        }
        p = p->next;
    }
}
void cau5(linkList l)
{
    cout << "Enter your list 1: ";
    l.input(1);
    linkList l3;
    node *p = l.pHead;
    while (p != nullptr)
    {
        l3.addFromHead(p->data);
        p = p->next;
    }
    l3.printList();
}
void cau6(linkList l1)
{
    cout << "Enter your list 1: ";
    l1.input(1);
    node *current = l1.pHead->next;
    node *previous = l1.pHead;
    while (current != nullptr)
    {
        if (current->data == previous->data)
        {
            node *temp = current;
            current = current->next;
            previous->next = current;
        }
        else
        {
            current = current->next;
            previous = previous->next;
        }
    }
    l1.printList();
}
void cau7(linkList l)
{
    cout << "Enter your list 1: ";
    l.input(1);
    linkList l3;
    node *p = l.pHead;
    while (p != nullptr)
    {
        l3.addFromHead(p->data);
        p = p->next;
    }
    p = l.pHead;
    node *p1 = l3.pHead;
    while (p != nullptr)
    {
        if (p->data != p1->data)
        {
            cout << "List is not Palindrome";
            return;
        }
        p = p->next;
        p1 = p1->next;
    }
    cout << "List is Palindrome";
    cout << endl;
}
void cau8(linkList l)
{
    cout << "Enter your list 1: ";
    l.input(1);
    int value;
    cout << "Enter your value: ";
    cin >> value;
    node *p = l.pHead;
    while (p != nullptr)
    {
        if (p->data == value)
        {
            cout << p;
            return;
        }
        p = p->next;
    }
    cout << "NULL value.";
    cout << endl;
    return;
}
int main()
{
    linkList l1;
    linkList l2;
    cout << "STT: 22521137\n";
    cout << "Full Name : Pham Quang Dai Phuc\n";
    cout << "In-Class Exercise - Part 1\n";
    cout << "Notes or Remarks: ......\n";
    cout << "End list with -1 value. \n";
    cout << "\n";
    int choice = 1;
    while (choice != 9)
    {
        cout << "\nMenu:\n";
        cout << "1. Find Middle Node\n";
        cout << "2. Detect Cycle\n";
        cout << "3. Combine Two Sorted Linked Lists\n";
        cout << "4. Find Intersection of Two Linked Lists\n";
        cout << "5. Reverse List\n";
        cout << "6. Eliminate Duplicates\n";
        cout << "7. Check if List is Palindrome\n";
        cout << "8. Search Value\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Question 1: " << endl;
            cau1(l1);
            break;
        case 2:
            cout << "Question 2: " << endl;
            cau2(l1);
            break;
        case 3:
        {
            cout << "Question 3:" << endl;
            cau3(l1, l2);
            break;
        }
        case 4:
        {
            cout << "Question 4:" << endl;
            cau4(l1, l2);
            break;
        }
        case 5:
        {
            cout << "Question 5:" << endl;
            cau5(l1);
            break;
        }
        case 6:
        {
            cout << "Question 6: " << endl;
            cau6(l1);
            break;
        }
        case 7:
            cout << "Question 7: " << endl;
            cau7(l1);
            break;
        case 8:
            cout << "Question 8: " << endl;
            cau8(l1);
            break;
        default:
            cout << "Exit successfully";
            break;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}