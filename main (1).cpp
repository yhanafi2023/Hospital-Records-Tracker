#include <string>
#include <iostream>
using namespace std;
struct slinklist {
    int ID;
    string name;
    string disease;
    struct slinklist *next;
};
typedef struct slinklist node;
node *start = NULL;
int countnode(node* start) {
    node* temp;
    int count=0;
    temp = start;
    while (temp != NULL) {
        count = count+1;
        temp = temp->next;
    }
    return count;
}
node* GetNode() {
    node* newnode;
    newnode = new node;
    printf("\n Enter Patient ID: ");
    cin >> newnode->ID;
    printf("\n Enter Patient Name: ");
    cin >> newnode->name;
    printf("\n Enter Patient Disease: ");
    cin >> newnode->disease;
    newnode->next = NULL;
    return newnode;
}
void CreateList(int n) {
    int i;
    node* newnode;
    node* temp;
    for (i = 0; i < n; i++) {
        newnode = GetNode();
        if (start==NULL) {
            start = newnode;
        }
        else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
        }
        temp->next = newnode;
            }
}
}
void InsertNodeMid() {
    node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = GetNode();
    printf("\n\nEnter the Position");
    scanf("%d", &pos);
    nodectr = countnode(start);
    if (pos > 1 && pos <= nodectr) {
        temp = prev = start;
        while (ctr < pos) {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else {
        printf("position %d is not a valid position", pos);
    }   
}
void DeleteNodeMid() {
    node *temp, *prev;
    int pos, nodectr, ctr = 1;
    if (start == NULL) {
        printf("\nEmpty List. Create a List First.");
    }
    else {
        printf("\n\nEnter the Position of What You Would Like to Delete: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if (pos > nodectr) {
            printf("\nPosition Does not Exist");
        }
        if (pos > 1 && pos <= nodectr) {
            temp = prev = start;
            while (ctr < pos) {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            delete temp;
            printf("\nNode Deleted! ");
        }
        if (pos == 1 && nodectr == 1) {
            temp = start;
            start = NULL;
            delete temp;
            printf("\nNode Deleted! ");
        }
        else {
            printf("\nInvalid Position Entered. ");
        }
    }
}
void DisplayNodes() {
    node* temp;
    temp = start;
    printf("\nHere is all the patient Info In the Order You Entered/Modified Them:\n ");
    if (start == NULL) {
        printf("\nNo User Information Entered. ");
    }
    else {
        while (temp != NULL) {
            cout << "ID: " << temp->ID << "\nName: " << temp->name << "\nDisease: " <<
            temp->disease << "\n" << endl;
            temp = temp->next;
    }
    }
}
int main() {
int choice = 0;
int n;
while (choice != 5) {
    cout << "\nPick an Action You Would Like to Do: \n\n1. Register 'n' amount of patients\n2.Insert a New Patient in the Middle\n3. Delete a Patient Record\n4. Display all patientrecords\n5. Exit\n\n" << endl;;
    cin >> choice;
    if (choice == 1) {
        cout << "Enter How many patients you would like to register" << endl;
        cin >> n;
        CreateList(n);
        cout << "List Creation Executed!" << endl;
    }
    if (choice == 2) {
        InsertNodeMid();
    }
    if (choice == 3) {
        DeleteNodeMid();
    }
    if (choice == 4) {
        DisplayNodes();
}
}
cout << "Program successfully exited!" << endl;
return 0;
}