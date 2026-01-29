#include <iostream>

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(int value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(const T& value)
    {
        Node* newNode = new Node(value);
        if (!head)  
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;

    }

    void push_front(const T& value)
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    T front() const
    {
        return head->data;
    }

    T back() const
    {
        return tail->data;
    }

    void print() const
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~List()
    {
        while (head)
        {
            pop_front();
        }
    }
};

int main(int argc, char* argv[])
{
    List<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    l.push_front(5);
    l.push_front(1);

    std::cout << "List contents: ";
    l.print();

    std::cout << "Front element: " << l.front() << std::endl;
    std::cout << "Back element: " << l.back() << std::endl;

    l.pop_front();
    l.pop_front();

    std::cout << "After popping front twice: ";
    l.print();

    return 0;
}
