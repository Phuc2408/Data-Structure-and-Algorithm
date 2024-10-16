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
    void input(int x)
    {
        do
        {
            cin >> x;
            if (x != 1000)
            {
                this->addElement(x);
            }
        } while (x != 1000);
    }

    linkList reverse()
    {
        linkList reversed;
        node *current = pHead;
        while (current != nullptr)
        {
            reversed.addFromHead(current->data);
            current = current->next;
        }
        return reversed;
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

void cau1(linkList l1, linkList l2)
{
    cout << "Enter list 1: ";
    l1.input(x);
    cout << "Enter list 2: ";
    l2.input(x);
    linkList result;
    node *p1 = l1.pHead;
    node *p2 = l2.pHead;

    linkList rev1 = l1.reverse();
    linkList rev2 = l2.reverse();

    node *r1 = rev1.pHead;
    node *r2 = rev2.pHead;

    int carry = 0;

    while (r1 != nullptr || r2 != nullptr || carry)
    {
        int sum = carry;
        if (r1 != nullptr)
        {
            sum += r1->data;
            r1 = r1->next;
        }
        if (r2 != nullptr)
        {
            sum += r2->data;
            r2 = r2->next;
        }

        carry = sum / 10;
        result.addElement(sum % 10);
    }
    linkList l3 = result.reverse();
    node *p = l3.pHead;
    cout << "The sum of 2 numbers is: ";
    while (p != nullptr)
    {
        cout << p->data;
        p = p->next;
    }
}
void cau2(linkList l1)
{
    cout << "Original List:" << endl;
    l1.printList();
}

void cau3(linkList l1, int y, int z)
{
    cout << "Enter your list 1: ";
    l1.input(x);
    cout << "Enter your position you want to change: ";
    cin >> y >> z;
    y--;
    z--;

    while (z >= l1.total)
    {
        cout << "Invalid, please try again." << endl;
        cout << "Enter your position you want to change: ";
        cin >> y >> z;
        y--;
        z--;
    }
    if (y == z)
    {
        node *p = l1.pHead;
        cout << "List after change: ";
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        return;
    }

    node *prevY = nullptr, *currY = l1.pHead;
    for (int i = 0; currY && i < y; i++)
    {
        prevY = currY;
        currY = currY->next;
    }

    node *prevZ = nullptr, *currZ = l1.pHead;
    for (int i = 0; currZ && i < z; i++)
    {
        prevZ = currZ;
        currZ = currZ->next;
    }

    if (!currY || !currZ)
        return;

    if (prevY)
    {
        prevY->next = currZ;
    }
    else
    {
        l1.pHead = currZ;
    }

    if (prevZ)
    {
        prevZ->next = currY;
    }
    else
    {
        l1.pHead = currY;
    }

    node *temp = currY->next;
    currY->next = currZ->next;
    currZ->next = temp;
    node *p = l1.pHead;
    cout << "The list after change is: ";
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void cau4(linkList l1, int y)
{
    cout << "Enter list 1: ";
    l1.input(x);
    cout << "Enter your position from end position: ";
    cin >> y;
    if (y == 1)
    {
        node *p = l1.pHead;
        while (p->next->next != nullptr)
        {
            p = p->next;
        }
        node *temp = l1.pTail;
        l1.pTail = p;
        p->next = nullptr;
        delete temp;
        l1.printList();
        return;
    }
    else if (y == l1.total)
    {
        node *temp = l1.pHead;
        l1.pHead = l1.pHead->next;
        delete temp;
        l1.printList();
    }
    else
    {
        node *current = l1.pHead;
        node *previous = l1.pHead;
        for (int i = 0; i < l1.total - y; i++)
        {
            previous = current;
            current = current->next;
        }
        node *temp = current;
        current = current->next;
        previous->next = current;
        delete temp;
        l1.printList();
        return;
    }
}
void cau5(linkList l1)
{
    cout << "Enter list 1: ";
    l1.input(x);

    if (l1.pHead == nullptr)
        return;

    linkList oddList;
    linkList evenList;

    node *current = l1.pHead;

    while (current != nullptr)
    {
        if (current->data % 2 != 0)
        {
            oddList.addElement(current->data);
        }
        else
        {
            evenList.addElement(current->data);
        }
        current = current->next;
    }

    cout << "Odd list: ";
    oddList.printList();

    cout << endl;

    cout << "Even list: ";
    evenList.printList();
}
void cau6(linkList l, int k)
{
    cout << "Enter list 1: ";
    l.input(x);

    cout << "Enter number of part: ";
    cin >> k;
    int totalNodes = l.total;

    int partSize = totalNodes / k;
    int remainder = totalNodes % k;

    node *current = l.pHead;

    for (int i = 0; i < k; i++)
    {
        linkList part;
        int currentPartSize = partSize + (i < remainder ? 1 : 0);

        for (int j = 0; j < currentPartSize; j++)
        {
            if (current != nullptr)
            {
                part.addElement(current->data);
                current = current->next;
            }
        }

        cout << "Part " << (i + 1) << ": ";
        part.printList();
        cout << endl;
    }
}
void cau7(linkList l1)
{
    cout << "Enter list 1: ";
    l1.input(x);
    node *current = l1.pHead;
    node *prev = nullptr;

    while (current != nullptr)
    {
        int sum = 0;
        node *runner = current;

        while (runner != nullptr)
        {
            sum += runner->data;

            if (sum == 0)
            {
                if (prev == nullptr)
                {
                    l1.pHead = runner->next;
                }
                else
                {
                    prev->next = runner->next;
                }

                current = runner->next;
                break;
            }

            runner = runner->next;
        }

        if (sum != 0)
        {
            prev = current;
            current = current->next;
        }
    }

    cout << "The list after removing zero-sum nodes is: ";
    l1.printList();
}
// void cau8(linkList l1) {
//     cout << "Enter list 1:";
//     l1.input(x);

// }
int main()
{
    linkList l1;
    linkList l2;
    cout << "STT: 22521137\n";
    cout << "Full Name : Pham Quang Dai Phuc\n";
    cout << "In-Class Exercise - Part 2\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    int choice = 1;
    while (choice != 9)
    {
        cout << "\nMenu:\n";
        cout << "1. Add two numbers\n";
        cout << "2. Copy List with Random Pointers\n";
        cout << "3. Swap Nodes in a Linked List\n";
        cout << "4. Remove the N-th Node from the End of a List\n";
        cout << "5. Separate Odd and Even Nodes in a Linked List\n";
        cout << "6. Divide a Linked List into Parts\n";
        cout << "7. Remove Zero-Sum Consecutive Nodes from a Linked List\n";
        cout << "8. Input values for a list using the automatic input method\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Question 1 (enter the end list with 1000): " << endl;
            cau1(l1, l2);
            break;
            // case 2:
            //     cout << "Question 2: " << endl;
            //     cau2(l1);
            //     break;
        case 3:
        {
            cout << "Question 3 (enter the end list with 1000):" << endl;
            int y, z;
            cau3(l1, y, z);
            break;
        }
        case 4:
        {
            cout << "Question 4 (enter the end list with 1000):" << endl;
            int y;
            cau4(l1, y);
            break;
        }
        case 5:
        {
            cout << "Question 5 (enter the end list with 1000):" << endl;
            cau5(l1);
            break;
        }
        case 6:
        {
            int number;
            cout << "Question 6 (enter the end list with 1000): " << endl;
            cau6(l1, number);
            break;
        }
        case 7:
            cout << "Question 7 (enter the end list with 1000): " << endl;
            cau7(l1);
            break;
            // case 8:
            //     cout << "Question 8 (enter the end list with 1000): " << endl;
            //     cau8(l1);
            //     break;
        default:
            cout << "Exit successfully";
            break;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}