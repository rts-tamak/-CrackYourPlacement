void push(Node **head, int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
 
  if (*head == nullptr) {
    *head = newNode;
    return;
  }
 
  Node *last = *head;
  while (last->next != nullptr) {
    last = last->next;
  }
 
  last->next = newNode;
}
 
void printList(Node *head) {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}
 
void sortList(Node *head) {
  int count[3] = {0, 0, 0};
 

  Node *current = head;
  while (current != nullptr) {
    count[current->data]++;
    current = current->next;
  }

  current = head;
  int i = 0;
  while (current != nullptr) {
    if (count[i] == 0) {
      i++;
    } else {
      current->data = i;
      count[i]--;
      current = current->next;
    }
  }
}