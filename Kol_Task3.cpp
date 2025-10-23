#include <iostream>
#include "vector"
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newHead = reverse(head->next);


    head->next->next = head;  
    head->next = nullptr;     

    return newHead;  
}

void print(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* create(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

std::vector<int> listToVector(Node* head) {
    std::vector<int> result;
    Node* current = head;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}



int main() {
    setlocale(LC_ALL, "rus");
    try {
        Node* head = create({ 1, 2, 3, 4, 5 });

        std::cout << "Исходный список: ";
        print(head);

        head = reverse(head);

        std::cout << "Развернутый список: ";
        print(head);

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    }
}