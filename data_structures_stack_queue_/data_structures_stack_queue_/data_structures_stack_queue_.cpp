#include <iostream>

class DataStructure {
public:
    virtual void push(int) = 0;

    virtual void pop() = 0;

    virtual void print() = 0;

    virtual int size() = 0;
};

class Node {

    int value;
    Node* next;

public:
    Node(int value) {
        this->value = value;
        next = nullptr;
    }

    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }

    int getValue() {
        return value;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* node) {
        next = node;
    }

    void setValue(int val) {
        value = val;
    }
};

class Stack : public DataStructure {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    Stack(int val) : top(new Node(val)) {}

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            delete temp;
        }
    }

    void push(int val) override {
        if (top == nullptr) {

            top = new Node(val);
        }
        else {

            Node* ptr = new Node(val);
            ptr->setNext(top);
            top = ptr;
        }
    }

    void pop() override {
        if (top == nullptr) return;
        Node* temp = top;
        top = top->getNext();
        delete temp;
    }

    void print() override {
        Node* cur = top;
        while (cur != nullptr) {
            std::cout << cur->getValue() << " ";
            cur = cur->getNext();
        }
        std::cout << "\n";
    }

    int size() override {
        int result = 0;
        Node* cur = top;
        while (cur != nullptr) {
            result++;
            cur = cur->getNext();
        }

        return result;
    }
};


class Queue : public DataStructure {
private:
    Node* front, * back;

public:
    Queue() : front(nullptr), back(nullptr) {}

    Queue(int val) : front(new Node(val)), back(front) {}
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->getNext();
            delete temp;
        }
    }

    void push(int val) override {
        if (back == nullptr) {
            back = new Node(val);
            front = back;
        }
        else {
            back->setNext(new Node(val));
            back = back->getNext();
        }
    }


    void pop() override {
        if (front == nullptr) return;
        Node* temp = front;
        front = front->getNext();
        delete temp;
    }

    void print() override {
        Node* cur = front;
        while (cur != nullptr) {
            std::cout << cur->getValue() << " ";
            cur = cur->getNext();
        }
        std::cout << "\n";
    }

    int size() override {
        int result = 0;
        Node* cur = front;
        while (cur != nullptr) {
            result++;
            cur = cur->getNext();
        }
        return result;
    }
};

int main()
{
    Stack st;
    st.push(5);
    st.push(5);
    st.push(5);
    st.push(5);
    st.print();
    st.pop();
    st.print();
    st.size();
}
