#pragma once
#include <iostream>
using namespace std;

//template <class T>
//struct Node {
//	T val;
//	Node* next;
//	Node* prev;
//
//	Node (const T& _val = 0,Node* _next = nullptr, Node* _prev = nullptr): val(_val), next(_next),prev(_prev){}
//};
template <class T>
class TList {
    struct Node {
        T val;
        Node* next;
        Node* prev;

        Node(const T& _val = 0, Node* _next = nullptr, Node* _prev = nullptr) : val(_val), next(_next), prev(_prev) {}
    };
	Node* head;
	Node* tail;
	int count;
public:
    TList() : head(nullptr), tail(nullptr), count(0) {}

    TList(const TList& other) : head(nullptr), tail(nullptr), count(0) {
        Node* current = other.head;
        while (current) {
            push_back(current->val);
            current = current->next;
        }
    }

    ~TList() {
        clear();
    }
    TList& operator=(const TList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                push_back(current->val);
                current = current->next;
            }
        }
        return *this;
    }
    void push_back(const T& value) {
        Node* newNode = new Node(value, nullptr, tail);

        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
        count++;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value, head, nullptr);

        if (head) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
        count++;
    }

    T pop_front() {
        if (empty()) throw std::out_of_range("List is empty");

        Node* temp = head;
        T value = temp->val;

        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;

        delete temp;
        count--;
        return value;
    }

    T pop_back() {
        if (empty()) throw std::out_of_range("List is empty");

        Node* temp = tail;
        T value = temp->val;

        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;

        delete temp;
        count--;
        return value;
    }

    T& front() {
        if (empty()) throw std::out_of_range("List is empty");
        return head->val;
    }

    T& back() {
        if (empty()) throw std::out_of_range("List is empty");
        return tail->val;
    }

    bool empty() const { return count == 0; }
    size_t size() const { return count; }

    void clear() {
        while (!empty()) pop_front();
    }
    void insert(size_t index, const T& value) {
        if (index > count) throw std::out_of_range("Index out of range");

        if (index == 0) {
            push_front(value);
        }
        else if (index == count) {
            push_back(value);
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            current->next = new Node(value, current->next);
            count++;
        }
    }

    T remove(size_t index) {
        if (index >= count) throw std::out_of_range("Index out of range");

        if (index == 0) return pop_front();

        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        T value = temp->val;
        current->next = temp->next;

        if (temp == tail) tail = current;

        delete temp;
        count--;
        return value;
    }
    
    class Iterator {
        Node* ptr;
    public:
        Iterator(Node* p = nullptr) : ptr(p) {}
        T& operator*() { return ptr->val; }
        Iterator& operator++() { ptr = ptr->next; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};