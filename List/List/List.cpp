#include <iostream>
using namespace std; 

template<typename T>
class Node {
public:
    Node<T>* next = nullptr;
    T data;
    Node(T data) {
        this->data = data; 
    }
};
template<typename T>
class List {
    int count = 0;
    Node<T>* head = nullptr;
public:
    void push_back(T data) {
        if (head == nullptr) head = new Node<T>(data);
        else {
            Node<T>* buf = head;
            while (buf->next != nullptr) {
                buf = buf->next;
            }
            buf->next = new Node<T>(data);
        }
        count++;
    }

    void push_front(T data) {
        Node<T>* buf = new Node<T>(data);
        if (head == nullptr) {
            head = buf;
        }
        else {
            buf->next = head;
            head = buf;
        }
        count++;
    }

    int size() {
        return count;
    }

    void clear() {
        Node<T>* buf = head;
        while (buf != nullptr) {
            Node<T>* bNext = buf->next;
            delete buf;
            buf = bNext;
        }
        head = nullptr;
        count = 0;
    }

    void insert(int position, T data) {
        Node<T>* newNode = new Node<T>(data);

        if (head == nullptr) {
            head = newNode;
        }
        else if (position == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<T>* buf = head;
            for (int i = 0; i < position - 1 && buf->next != nullptr; i++) {
                buf = buf->next;
            }
            newNode->next = buf->next;
            buf->next = newNode;
        }

        count++;
    }

    void pop_back() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
        }
        else {
            Node<T>* buf = head;
            Node<T>* previous= nullptr;
            while (buf->next != nullptr) {
                previous = buf;
                buf = buf->next;
            }
            delete buf;
            previous->next = nullptr;
        }
        count--;
    }

    void pop_front() {
        if (head == nullptr) return;
        head = head->next;
        count--;
    }

    bool empty() {
        if (count > 0)return true;
        else return false;
    }
    
    T front() {
        return head->data;
    }

    T back() {
        if (head == nullptr) {
            return;
        }
        Node<T>* buf = head;
        while (buf->next != nullptr) {
            buf = buf->next;
        }

        return buf->data;
    }

    void show() {
        Node<T>* buf = head;
        while (buf != nullptr) {
            cout << buf->data << " ";
            buf = buf->next;
        }
        cout << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "rus");
    List<int> list;
    list.push_front(2);
    list.push_front(4);
    list.push_back(23);

    cout << "Список после добавления элементов: ";
    list.show();

    cout << "Размер списка: " << list.size() << endl;

    list.clear();
    cout << "Список после очистки: ";
    list.show();

    list.push_front(2);
    list.push_front(4);
    list.push_back(23);
    list.push_front(457);
    cout << "Список после добавления элемента 457 в начало: ";
    list.show();

    list.clear();
    list.push_front(2);
    list.push_front(4);
    list.push_back(23);
    list.insert(2, 5);

    cout << "Список после вставки элемента 5 на позицию 2: ";
    list.show();

    cout << "Список удаления первого элемента: ";
    list.pop_front();
    list.show();

    cout << "Список удаления последнего элемента: ";
    list.pop_back();
    list.show();
}
