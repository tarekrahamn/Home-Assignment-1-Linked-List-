/*
               Starting with the name of almighty ALLAH 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~**
            In the name of Allah, Most Gracious, Most Merciful             
                    লা ইলাহা ইল্লাল্লাহু মুহাম্মাদুর রাসুলুল্লাহ 
                        Author:  tarek200 
                        Created: 24.07.2023 
                    United International University
                Practice is the only shortcut to improve  
*/
#include <bits/stdc++.h>
#include<vector>
#include<set>
#define   Tarek           ios::sync_with_stdio(false);cin.tie(0);
#define   ll              long long int
#define   ull             unsigned long long int
#define   ld              long double
#define   vi              vector<int>
#define   vll             vector<ll>
#define   vc              vector<char>
#define   vs              vector<string>
#define   test            ll t;cin >> t;while(t--)
#define   pb              push_back
#define   pp              pop_back
#define   sz              size()
#define   ff              first
#define   ss              second
#define   YES             cout<<"YES"<<endl;
#define   NO              cout<<"NO"<<endl;
#define   exit            return ;
#define   checkmate       return 0;
#define   nl              "\n"
#define   gcd(a,b)        __gcd(a,b)
#define   lcm(a,b)        (a/gcd(a,b))*b
#define   mod             1000000007
#define   all(x)          (x).begin(), (x).end()
#define   des(x)          (x).rbegin(), (x).rend()
#define   FOREACH(it, l)  for (auto it = l.begin(); it != l.end(); it++)
#define   cinv(v)         for(auto &it:v)cin>>it;
#define   FOR(i,a,b)      for(ll i=a;i<b;i++)
#define   LOOP(i,a,b)     for(ll j=a;j<b;j++)
#define   LOOP2(i,a,b)    for(ll i=a;i<=b;i++)
#define   ROF(i, a, b)    for (ll i = a; i >=b; i--)
const long long int N     = (ll) 1e7+1;
const long long int M     = (ll) 1e9+5;
#define MAX                 200005
#define MOD                 1000003
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f // 4,557,430,888,798,830,399
#define inf                 0x3f3f3f3f // 1,061,109,567
#define PI                  acos(-1.0)  // 3.1415926535897932
using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into k-th position
struct Node* insertAtK(struct Node* head, int k, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return head;
    }

    if (k == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        int count = 1;
        while (count < k - 1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

// Function to insert a node into the second last position
struct Node* insertAtSecondLast(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        if (head->next == NULL) {
            head->next = newNode;
            newNode->prev = head;
        } else {
            struct Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            // Insert before the last node
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    return head;
}

// Function to find the maximum element in the linked list
int findMaximum(struct Node* head) {
    int max = INT_MIN;

    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }

    return max;
}

// Function to delete all odd elements from the linked list
struct Node* deleteOddElements(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL) {
        if (current->data % 2 != 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            temp = current->next;
            free(current);
            current = temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

// Function to search for all occurrences of a specific element
int searchOccurrences(struct Node* head, int value) {
    int count = 0;

    while (head != NULL) {
        if (head->data == value) {
            count++;
        }
        head = head->next;
    }

    return count;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;

    // Test cases
    head = insertAtK(head, 1, 10);
    head = insertAtK(head, 2, 20);
    head = insertAtK(head, 3, 30);
    head = insertAtK(head, 4, 40);
    head = insertAtK(head, 5, 50);

    printf("Doubly Linked List: ");
    printList(head);

    head = insertAtSecondLast(head, 35);

    printf("After inserting 35 at the second last position: ");
    printList(head);

    int max = findMaximum(head);
    printf("Maximum element in the linked list: %d\n", max);

    head = deleteOddElements(head);

    printf("After deleting odd elements: ");
    printList(head);

    int valueToSearch = 40;
    int occurrences = searchOccurrences(head, valueToSearch);
    printf("Occurrences of %d in the linked list: %d\n", valueToSearch, occurrences);

    // Free the memory used by the linked list
    freeList(head);

    return 0;
}
