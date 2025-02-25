#include <stdio.h>
#include <stdlib.h>

// 1. Criação da lista vazia
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// 2. Verificar se a lista está vazia
int isEmpty(LinkedList* list) {
    return list->size == 0;
}

// 3. Obter o tamanho da lista
int getSize(LinkedList* list) {
    return list->size;
}

// 4. Obter/modificar o valor do elemento de uma determinada posição na lista
int getElement(LinkedList* list, int position) {
    if (position < 1 || position > list->size) {
        printf("Posicao invalida!\n");
        return -1;
    }
    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

void setElement(LinkedList* list, int position, int value) {
    if (position < 1 || position > list->size) {
        printf("Posicao invalida!\n");
        return;
    }
    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    current->data = value;
}

// 5. Inserir um elemento em uma determinada posição
void insertElement(LinkedList* list, int position, int value) {
    if (position < 1 || position > list->size + 1) {
        printf("Posicao invalida!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// 6. Retirar um elemento de uma determinada posição
void removeElement(LinkedList* list, int position) {
    if (position < 1 || position > list->size) {
        printf("Posicao invalida!\n");
        return;
    }
    Node* temp;
    if (position == 1) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        Node* current = list->head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    list->size--;
}

// 7. Imprimir os elementos de toda a lista
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Casos de teste demonstrando o funcionamento da lista
int main() {
    LinkedList* list = createList();

    insertElement(list, 1, 10);
    insertElement(list, 2, 20);
    insertElement(list, 3, 30);
    insertElement(list, 2, 15);
    
    printf("Lista apos insercoes: ");
    printList(list);
    
    printf("Elemento na posicao 2: %d\n", getElement(list, 2));
    setElement(list, 2, 25);
    printf("Lista apos modificacao na posicao 2: ");
    printList(list);
    
    removeElement(list, 3);
    printf("Lista apos remocao da posicao 3: ");
    printList(list);
    
    printf("Tamanho da lista: %d\n", getSize(list));
    printf("A lista esta vazia? %s\n", isEmpty(list) ? "Sim" : "Nao");
    
    return 0;
}
