#ifndef CPP_LAB_10_MYDECK_HPP
#define CPP_LAB_10_MYDECK_HPP

#include <iostream>

template<typename T>
class MyDeck {
private:
    struct Node {
        T element;
        Node *next;
        Node *prev;

        explicit Node(const T &item) : element(item), next(nullptr), prev(nullptr) {}
    };

    size_t curr_size;
    Node *front;
    Node *back;
public:
    MyDeck() : front(nullptr), back(nullptr), curr_size(0) {}

    __attribute__((unused)) MyDeck(Node *item) : front(item), back(item), curr_size(1) {} //NOLINT

    MyDeck(MyDeck &o) {
        Node temp = o.back();
        while (temp != nullptr) {
            push_front(temp.element);
            temp = temp.next;
        }
        curr_size = o.curr_size;
    }

    ~MyDeck() {
        Node *sav;
        while (back) {
            sav = back;
            delete sav;
            back = back->prev;
        }
    }

    void push_back(const T &item) {
        Node *curr_node = new Node(item);
        if (curr_size == 0) {
            front = curr_node;
            back = curr_node;
        } else {
            back->prev = curr_node;
            curr_node->next = back;
            back = curr_node;
        }
        curr_size += 1;
    }

    __attribute__((unused)) void pop_back() {
        if (curr_size == 0) {
            std::cerr << "Deque is empty!";
            return;
        } else if (curr_size == 1) {
            Node *temp = back;
            front = nullptr;
            back = nullptr;
            delete temp;
            curr_size = 0;
        } else {
            Node *temp = back;
            back = temp->next;
            back->prev = nullptr;
            delete temp;
            curr_size -= 1;
        }
    }

    void push_front(const T& item) {
        Node *curr_node = new Node(item);
        if (curr_size == 0) {
            front = curr_node;
            back = curr_node;
        } else {
            front->next = curr_node;
            curr_node->prev = front;
            front = curr_node;
        }
        curr_size += 1;
    }

    void pop_front() {
        if (curr_size == 0) {
            std::cerr << "Deque is empty!";
            return;
        } else if (curr_size == 1) {
            Node *temp = back;
            front = nullptr;
            back = nullptr;
            delete temp;
            curr_size = 0;
        } else {
            Node *temp = front;
            front = temp->prev;
            front->next = nullptr;
            delete temp;
            curr_size -= 1;
        }
    }

    size_t size() {
        return curr_size;
    }

    friend std::ostream &operator<<(std::ostream &os, const MyDeck &obj) {
        if (obj.curr_size == 0) {
            std::cerr << "Deck is empty.";
        } else {
            Node *sav;
            sav = obj.back;
            while (sav) {
                os << sav->element << " ";
                sav = sav->next;
            }
        }
        return os;
    }

    void displayFromBack() {
        if (curr_size == 0) {
            std::cerr << "Deck is empty.";
            return;
        }
        Node *temp = back;
        while (temp) {
            std::cout << temp->element << std::endl;
            temp = temp->next;
        }
    }
};


#endif //CPP_LAB_10_MYDECK_HPP
