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

struct node {
    int data;
    struct node* next;
};
// Create Link List At First
struct node* createLinkedList(int a[], int size) {
    struct node* head = NULL;
    struct node* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = a[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
//Insert into mid position
struct node* insertMiddle(struct node* head, int value) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    int mid = count / 2;
    current = head;
    for (int i = 1; i <mid; i++) {
        current = current->next;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;

    return head;
}

//Function to add all elements of an array at the end of the linked list
struct node* add_element_in_linklist(struct node *head,int data){
    struct node *pointer =head;
    while(pointer->next != NULL){
        pointer=pointer->next ;
    }
    struct node *NEW_pointer =(struct node*)malloc(sizeof(struct node));
    pointer->next=NEW_pointer;
    NEW_pointer->data=data;
    NEW_pointer->next=NULL;
}

//Delete k-th element of a Linked List
struct node* Delete(struct node* head, int data) {
    struct node* dummyhead = (struct node*)malloc(sizeof(struct node));
    dummyhead->next = head;
    struct node* current = dummyhead;

    while (current->next != NULL) {
        if (current->next->data == data) {
            // delet main logic
            current->next = current->next->next;
        }
        current = current->next;
    }
    return dummyhead->next;
}

// Function to replace the last element of the linked list using the sum of the list

struct node* replaceLastWithSum(struct node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Calculate the sum of all elements in the list
    struct node* current = head;
    int sum = 0;
    while (current->next != NULL) {
        sum += current->data;
        current = current->next;
    }
    sum += current->data;

    // Replace the last element with the sum
    current->data = sum;

    return head;
}


// Function to search all even numbers in the linked list and put them in an array
void searchEvenNumbers(struct node* head, int arr[], int* size) {
    *size = 0;
    struct node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            arr[*size] = current->data;
            (*size)++;
        }
        current = current->next;
    }
}

// Function to display the linked list
void displayList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int a[]={10,20,30,40,50,60};
    struct node *head = createLinkedList(a,6);
    printf("Linked list array elements: ");
    displayList(head);

    // Test insertMid
    head=insertMiddle(head,500);  
    printf("Linked list after inserting in mid: ");
    displayList(head);

    // Test deleteKthElement
    head =Delete(head,30);
    printf("Linked list after deleting 2nd element: ");
    displayList(head);

    // Test replaceLastWithSum
    head=replaceLastWithSum(head);
    printf("Linked list after replacing last element with sum: ");
    displayList(head);

    // Test searchEvenNumbers
    int evenArr[100];
    int evenSize = 0;
    searchEvenNumbers(head, evenArr, &evenSize);
    printf("Even numbers in the linked list: ");
    for (int i = 0; i < evenSize; i++) {
        printf("%d ", evenArr[i]);
    }
    printf("\n");

    return 0;
}
