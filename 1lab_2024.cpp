#include <iostream>

using namespace std;

// Структура для элементов списка
struct Node {
  int data;
  Node *next;
};

class LinkedList {
private:
  Node *head;

public:
  // Конструктор по умолчанию
  LinkedList() { head = nullptr; }

  // Функция для добавления элемента в начало списка
  void addToBeginning(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
  }

  // Функция для добавления элемента в конец списка
  void addToEnd(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
      return;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  // Функция для определения середины списка
  Node *findMiddle() {
    if (head == nullptr) {
      return nullptr;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  // Функция для добавления элемента перед серединой списка
  void addBeforeMiddle(int value) {
    Node *middle = findMiddle();
    if (middle == nullptr) {
      addToBeginning(value);
      return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = middle->next;
    middle->next = newNode;
  }

  // Функция для добавления элемента после середины списка
  void addAfterMiddle(int value) {
    Node *middle = findMiddle();
    if (middle == nullptr) {
      addToEnd(value);
      return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = middle->next;
    middle->next = newNode;
  }

  // Функция для удаления элемента по индексу из списка
  void removeAt(int index) {
    if (head == nullptr) {
      cout << "Список пуст." << endl;
      return;
    }

    if (index == 0) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *prev = nullptr;
    Node *curr = head;
    int currentIndex = 0;

    while (curr != nullptr && currentIndex != index) {
      prev = curr;
      curr = curr->next;
      currentIndex++;
    }

    if (curr == nullptr) {
      cout << "Индекс находится за пределами списка." << endl;
      return;
    }

    prev->next = curr->next;
    delete curr;
  }

  // Функция для отображения списка
  void display() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList list;

  list.addToEnd(1);
  list.addToEnd(2);
  list.addToEnd(3);
  list.addToEnd(4);
  list.addToEnd(5);

  cout << "Исходный список: ";
  list.display();

  list.addToBeginning(-10);
  cout << "Список после добавления в начало: ";
  list.display();

  list.addToEnd(10);
  cout << "Список после добавления в конец: ";
  list.display();

  list.addBeforeMiddle(2); // Добавить 2 перед серединой
  cout << "Список после добавления 2 перед серединой: ";
  list.display();

  list.addAfterMiddle(3); // Добавить 3 после середины
  cout << "Список после добавления 3 после середины: ";
  list.display();

  list.removeAt(0);
  cout << "Список после удаления элемента по индексу 0: ";
  list.display();

  list.removeAt(100);
  cout << "Список после удаления элемента по индексу 100: ";
  list.display();

  return 0;
}
