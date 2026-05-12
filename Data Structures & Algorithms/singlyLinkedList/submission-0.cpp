#include <vector>
using namespace std;
class LinkedList {
public:
    struct Node {
        Node* next;
        int data;
        Node(int x) : next(nullptr), data(x) {}
    };

    Node* head;
    int size;

    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        Node* cur = head;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->data;
    }

    void insertHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        size++;
    }

    void insertTail(int val) {
        if (size == 0) {
            insertHead(val);
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new Node(val);
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;

        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            return true;
        }

        Node* prev = head;
        for (int i = 0; i < index - 1; i++)
            prev = prev->next;

        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* cur = head;
        while (cur != nullptr) {
            ans.push_back(cur->data);
            cur = cur->next;
        }
        return ans;
    }
};