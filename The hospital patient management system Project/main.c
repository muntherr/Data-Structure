//1182028 muntherr anati
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//#include "library.h"
void menu();
void printall(struct node* h);
struct node *MakeEmpty(struct node* L);
void count_of_node(struct node* head);
void printAll(struct node* head);
struct node *add(struct node* head);
void update(struct node* head);
struct node *Search(struct node* head, char[]);
void deleteSpaces(char src[], char dst[]);
struct node *Psearch(struct node *head);
struct node *DateSearch(struct node *head, char s[50]);
struct node *PList(struct  node* head);
struct node *soft_delete(struct  node* head);
void print_soft_delete(struct  node* head);
void XML(struct node *head);
struct node *linked_list(struct node* x[]);
int AsciiCode(char *s);
struct node *Rsort(struct  node* head);
int getMax(struct  node* head);
void insert(struct node* head, char x[]);
struct node *linked_list(struct node *x[]);

struct node
{
    int number_of_patients[100];
    char name[50];

    char gender[2];
    int date_of_addmision[10];
    int date_of_birthday[10];
    char illness[20];
    char address[20];
    char Blood_type[5];
    bool is_delete;

    struct node *next;
};
struct node *before = NULL;
struct node *after = NULL;

int main()
{
    struct node *head = NULL;
    FILE *fp, *fout;
    fp = fopen("patients.txt", "r");
    fout = fopen("Report.xml", "w");
    int choice;

    menu();
    printf("\nYour choice :");

    scanf("%d", &choice);
    printf("\n=========================================================\n");

    while (choice != 9)
    {
        switch (choice)
        {

        case 1:
        {
            struct node *ptr = NULL;
            struct node *temp = NULL;

            char c[100][50];
            char *token;
            char line[100];
            int i = 0, j = 0, v = 0;

            while (fgets(line, sizeof(c), fp) != NULL)
            {
                // printf("patient number %d\n",i+1);
                {
                    if (token == NULL)
                    {
                        break;
                    }
                    ptr = MakeEmpty(ptr);
                    // use strtok function to split the input when reach #
                    token = strtok(line, "#");
                    strcpy(ptr->name, token);

                    token = strtok(NULL, "#");
                    strcpy(ptr->gender, token);

                    token = strtok(NULL, "#");
                    strcpy(ptr->date_of_addmision, token);

                    token = strtok(NULL, "#");
                    strcpy(ptr->date_of_birthday, token);

                    token = strtok(NULL, "#");
                    strcpy(ptr->illness, token);

                    token = strtok(NULL, "#");
                    strcpy(ptr->address, token);

                    token = strtok(NULL, "#");
                    strcpy(ptr->Blood_type, token);

                    ptr->is_delete = false;

                    ptr->next = NULL;
                    if (head == NULL)
                        head = ptr;
                    else
                    {
                        temp = head;
                        while (temp->next != NULL)
                            temp = temp->next;
                        temp->next = ptr;
                    }
                }
                i++;
            }
            printf("\nData read successfully !!\n");
        }
        break;
        case 2:
            // Radix Sort~!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            printf("before sorting\n");
            before = show(head);
            Rsort(head);
            printf("After sorting\n");
            after = show(head);
            break;
        case 3:
            head = add(head);
            break;
        case 4:
            update(head);
            break;
        case 5:
            soft_delete(head);
            printf("\nThe patient has been successfully deleted !!\n");
            break;

        case 6:
            Psearch(head);

            break;
        case 7:
            PList(head);

            break;
        case 8:
            XML(head);
            break;

        case 9:

            break;

        default:
            printf("Please choose a valid choice from 1 to 10 !! \n");
        }
        menu();
        printf("\nYour choice :");
        scanf("%d", &choice);

        printf("\n=========================================================\n");
    }
    printf("\n    Thank you for using hospital patient management system, Bye Bye :)\n");
    return 0;
}
void menu()
{
    printf("\n=========================================================");
    printf("\n    Welcome to the hospital patient management system\n");
    printf("=========================================================\n");
    printf("\t   Please choose from 1 to 10\n"
           "\t\t1-Read data \n"
           "\t\t2-Sort Data\n"
           "\t\t3-Add patient\n"
           "\t\t4-Update patient\n"
           "\t\t5-Delete patient\n"
           "\t\t6-Search for patient\n"
           "\t\t7-List patient\n"
           "\t\t8- Export medical report\n"
           "\t\t9-Exit");
    printf("\n=========================================================\n");
}
struct node *Rsort(struct node *head)
{
    struct node *arr[256]; // I defined array 256

    int i;
    for (i = 0; i < 256; i++)
    {
        arr[i] = MakeEmpty(NULL);
    }

    int x = getMax(head);

    struct node *p = head;
    int j;

    for (j = 0; j < x; j++)
    {

        while (p != NULL)
        {
            int a = AsciiCode(p->name[x - j - 1]);

            insert(arr[a], p->name);
            p = p->next;
        }
        p = linked_list(arr);
    }
    return p;
}
// I defined the function "getMax" to return the number of character of the greater data in Linked list.
int getMax(struct node *head)
{

    struct node *p = head;
    int Max = sizeof(p->name);
    while (p != NULL)
    {

        if (Max < (sizeof(p->name)))
        {
            Max = (sizeof(p->name));
        }
        p = p->next;
    }
    return Max;
}
// I defined the function "AsciiCode" to return the Ascii Code of the character.
int AsciiCode(char *s)
{

    int i = s;
    if (i <= 0) // if the compiler return negative value, will return 0.
        return 0;

    if (i >= 97 && i <= 122) //convert from lower case to uppercase
        i = i - 32;

    return i;
}

// I defined the function "insert" to add node contains data that it receives to last Linked list.
void insert(struct node *d, char x[])
{
    struct node *p = MakeEmpty(NULL);

    strcpy(p->name, x);
    struct node *t = d;
    while (t != NULL)
    {

        t = t->next;
    }
    t = p->next;
}
struct node *linked_list(struct node *x[])
{
    int counter = 0, count = 50; // I defined (counter) to count the number of characters
    struct node *L = MakeEmpty(NULL);
    struct node *p = L;
    int i;
    // I defined "for loop" to return the node in these buckets to Linked list.
    for (i = 0; i < 256; i++)
    {
        if (counter == count) // if the number of words that I return it to the Linked list equal the number of words I read from the file, the loop will stop.
        {
            break;
        }
        else
        {
            if (x != NULL)
            {

                struct node *h = NULL;
                h = x;
                while (h != NULL)
                {
                    p = h;
                    p = p->next;
                    h = h->next;
                    counter++;
                }

                *x[i]->name = NULL; // There is pro
            }
        }
    }

    return L;
}
void show(struct node *head)
{
    struct node *p;
    p = head;
    while (p != NULL)
    {
        printf("%s\n", p->name);
        p = p->next;
    }
}

struct node *MakeEmpty(struct node *L)
{
    if (L != NULL)
        DeleteList(L);
    L = (struct node *)malloc(sizeof(struct node));
    if (L == NULL)
        printf("Out of memory!\n");
    return L;
}
void DeleteList(struct node *L)
{
    struct node *P;
    struct node *temp = NULL;
    P = L->next;
    L->next = NULL;

    while (P != NULL)
    {
        temp = P->next;
        free(P);
        P = temp;
    }
}
void print_soft_delete(struct node *head)
{
    struct node *p = head;
    int j = 1;

    while (p != NULL)
    {
        if (p->is_delete == false)
        {
            printf("Patient Number:%d\n", j);
            printf("Name is:%s\n", p->name);
            printf("Gender:%s\n", p->gender);
            printf("Date Of Admision:%d\n", p->date_of_addmision);
            printf("Date Of Birthday:%d\n", p->date_of_birthday);
            printf("Illness:%s\n", p->illness);
            printf("Address:%s\n", p->address);
            printf("Blood Type:%s\n", p->Blood_type);
            //printf("Is Deleted :%s\n",p->is_delete ? "true" : "false"); print if true print true else print false
            printf("\n");
            j++;
        }
        p = p->next;
    }
}

void printAll(struct node *head)
{
    struct node *p = head;
    int j = 1;

    while (p != NULL)
    {
        printf("Patient Number:%d\n", j);
        printf("Name is:%s\n", p->name);
        printf("Gender:%s\n", p->gender);
        printf("Date Of Admision:%d\n", p->date_of_addmision);
        printf("Date Of Birthday:%d\n", p->date_of_birthday);
        printf("Illness:%s\n", p->illness);
        printf("Address:%s\n", p->address);
        printf("Blood Type:%s\n", p->Blood_type);
        //printf("Is Deleted :%s\n",p->is_delete ? "true" : "false");
        printf("\n");
        p = p->next;
        j++;
    }
}

void pAll(struct node *head)
{
    struct node *p = head;

    while (p != NULL)
    {
        printf("Name is:%s\n", p->name);
        printf("Gender:%s\n", p->gender);
        printf("Date Of Admission:%d\n", p->date_of_addmision);
        printf("Date Of Birthday:%d\n", p->date_of_birthday);
        printf("Illness:%s\n", p->illness);
        printf("Address:%s\n", p->address);
        printf("Blood Type:%s\n", p->Blood_type);
        printf("\n");
        break;
    }
}

struct node *add(struct node *head)
{

    char name[50];
    char gender[2];
    int DOaddmision[10];
    int DOB[10];
    char illness[20];
    char address[20];
    char Bloodtype[5];
    char temp;

    struct node *current_head = head;
    struct node *p;
    // In this function i will add new patient to bottom of linked list
    while (current_head != NULL && current_head->next != NULL) //move current head pointer  at end of likend list until reach NULL
    {
        current_head = current_head->next;
    }
    p = MakeEmpty(NULL);

    printf("To Add new Patient Enter the following\n");

    printf("Name: ");

    scanf("%c", &temp);
    scanf("%[^\n]", name); // %[^\n] to read till hit Enter
    strcpy(p->name, name);

    printf("Gender: ");
    scanf("%s", gender);
    strcpy(p->gender, gender);

    printf("Date Of Admission(DDMMYYYY): ");
    scanf("%d", &DOaddmision);
    strcpy(p->date_of_addmision, DOaddmision);

    printf("Date Of Birthday(DDMMYYYY): ");
    scanf("%d", &DOB);
    strcpy(p->date_of_birthday, DOB);
    printf("Illness: ");

    scanf("%c", &temp); // To prevent store "Enter or null into string illness  'First character in illness string'"
    // To read Full name with spaces i used temporary buffer to clear any input data in illness string
    scanf("%[^\n]", &illness);
    strcpy(p->illness, illness);

    printf("Address: ");
    scanf("%s", &address);
    strcpy(p->address, address);

    printf("Blood Type: ");
    scanf("%s", &Bloodtype);
    strcpy(p->Blood_type, Bloodtype);

    p->next = NULL;
    if (current_head != NULL) // check if current head == null then pointer of head equal new node , if  it != NULL then move current head pointer to next pointer then link the new node
        current_head->next = p;
    else
        head = p;
    printf("\nThe patient has been Added successfully ^^\n");
    return head;
}

void update(struct node *head)
{
    //This function will update the patient information. by asked the user to Enter the name of patients that need to update.
    //Then use the Search function to find the required patient then update the needed information.
    int choice;
    // New data will be stored in the variables below
    char new_name[50];
    char new_gender[2];
    int new_DOaddmision[10];
    int new_DOB[10];
    char new_illness[20];
    char new_address[20];
    char new_Bloodtype[5];
    char old_name[50];

    int pos = 0;
    struct node *temp = NULL;
    temp = head;
    char t;
    printf("\n=========================================================\n");
    printf("please choose from the list\n");
    printf("\t\t1.change name\n"
           "\t\t2.change Gender\n"
           "\t\t3.change Date of admission(DDMMYYYY)\n"
           "\t\t4.change Date of Birthday(DDMMYYYY)\n"
           "\t\t5.change illness\n"
           "\t\t6.change address\n"
           "\t\t7.change Blood Type\n"
           "\t\t8.return to main menu\n");
    printf("\n=========================================================\n");

    printf("Your choice :");

    scanf("%d", &choice);
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
        {
            printf("Enter the name of the wanted patient : \n");

            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("Please enter New name \n");
                scanf("%c", &t);
                scanf("%[^\n]", new_name); //'[^\n]' it able to take a complete string with spaces, it takes a string until hit the enter key
                strcpy(temp->name, new_name);
            }
        }

        break;

        case 2:
        {
            printf("Enter the name of the wanted patient : \n");
            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("Please enter the new gender : \n");
                scanf("%s", new_gender);
                strcpy(temp->gender, new_gender);
            }
        }
        break;

        case 3:
        {
            printf("Enter the name of the wanted patient : \n");
            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("Please enter the new Date of admission : \n");
                scanf("%s", new_DOaddmision);
                strcpy(temp->date_of_addmision, new_DOaddmision);
            }
        }
        break;

        case 4:
        {
            printf("Enter the name of the wanted patient : \n");
            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("please enter the new Date Of Birthday : \n");
                scanf("%s", new_DOB);
                strcpy(temp->date_of_birthday, new_DOB);
            }
        }
        break;

        case 5:
        {

            printf("Enter the name of the wanted patient : \n");
            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("please enter the new Illness : \n");
                scanf("%c", &t);
                scanf("%[^\n]", new_illness);

                strcpy(temp->illness, new_illness);
            }
        }
        break;

        case 6:
        {
            printf("Enter the name of the wanted patient : \n");
            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("please enter the new address : \n");
                scanf("%s", new_address);
                strcpy(temp->address, new_address);
            }
        }
        break;

        case 7:
        {
            printf("Enter the name of the wanted patient : \n");
            scanf("%c", &t);
            scanf("%[^\n]", old_name);
            temp = Search(head, old_name);
            if (temp != NULL)
            {
                printf("Please enter the new Blood type : \n");

                scanf("%s", new_Bloodtype);
                strcpy(temp->Blood_type, new_Bloodtype);
            }
        }
        break;

        default:
            printf("please choose a number between 1 - 7 !! \n");
            break;
        }
        printf("\n=========================================================\n");
        printf("please choose from the list\n\n");
        printf("\t\t1.change name\n"
               "\t\t2.change Gender\n"
               "\t\t3.change Date of admission(DDMMYYYY)\n"
               "\t\t4.change Date of Birthday(DDMMYYYY)\n"
               "\t\t5.change illness\n"
               "\t\t6.change address\n"
               "\t\t7.change Blood Type\n"
               "\t\t8.return to main menu\n");
        printf("\n=========================================================\n");

        scanf("%d", &choice);
    }
    //printf("Data updated successfully \n");
};
struct node *Search(struct node *head, char s[50])
{
    struct node *temp;
    temp = head;
    int yes = 0;
    while (temp != NULL)
    {
        if (!(strcasecmp(temp->name, s))) //  ignore string case (capital , it convert string to small letters , if two strings are equals it  return 0 , and because if expression evaluated
            //when it is true i add not to it.
        {
            yes = 1;
            return temp;
            break;
        }
        temp = temp->next; // go to next node
    }
    if (yes == 0)
    {
        printf("there is no such patient !! \n");
        temp = NULL;
        return temp;
    }
    return temp;
};

struct node *Psearch(struct node *head)
{
    // i used this function to search for specific information for patients
    struct node *temp = NULL;
    temp = head;
    char name[50];
    int choice;
    char ch[1];
    char t;
    // printf("\n=========================================================\n");

    printf("choose From List \n");
    printf("\t\ta. Search By Name\n");
    printf("\t\tb. Search by Date Of Birthday\n");
    printf("\t\tc. Seturn to main menu\n");
    printf("=========================================================\n");

    printf("\nYour choice is :");
    scanf("%s", ch);
    printf("\n=========================================================\n");

    while (ch[0] != 'c')
    {
        switch (ch[0])
        {
        case 'a':
        {
            printf("Enter the name of the wanted patient :");

            scanf("%c", &t);
            scanf("%[^\n]", name);
            temp = Search(head, name);
            printf("\n \n");
            if (temp != NULL)
            {
                pAll(temp);
                break;
            }
        }
        break;
        case 'b':
        {
            char DOB[10];
            printf("Enter the Date Of birthday  of the wanted patient : ");
            scanf("%s", &DOB);
            struct node *temp;
            temp = head;
            printf("\n \n");
            while (temp->next != NULL)
            {
                if (!(strcmp(temp->date_of_birthday, DOB)))
                {
                    pAll(temp);
                    return;
                }
                temp = temp->next;
            }
        }

        break;
        case 'c':
            return 0;
            break;
        default:
            printf("Please choose a valid choice (a - b - c) !! \n");
        }
        //printf("\n=========================================================\n");

        printf("choose From List \n");
        printf("\t\ta. Search By Name\n");
        printf("\t\tb. Search by Date Of Birthday\n");
        printf("\t\tc. Seturn to main menu\n");
        printf("=========================================================\n");

        printf("\nYour choice is :");
        scanf("%s", ch);
        //printf("\n=========================================================\n");
    }
};

struct node *PList(struct node *head)
{
    // This function will list all data for patients , or by city or discharged patient
    struct node *temp = NULL;
    temp = head;
    char name[50];
    int choice;
    char ch[1];

    printf("Choose From List\n");
    printf("\t a-All patients\n"
           "\t b-Category\n"
           "\t c-City\n"
           "\t d-Discharged\n"
           "\t e-To exit List menu\n");

    printf("Your choice is :");
    //ch = tolower(ch);
    scanf("%s", ch);
    printf("\n");

    while (ch[0] != 'e')
    {
        switch (ch[0])
        {

        case 'a':
            if (temp != NULL)
            {
                //i++;
                print_soft_delete(head);
                break;
            }
            else
                printf("There is no readable Data !! \n");
            printf("\n====================================\n");

            break;

        case 'b':
        {
            char t;
            struct node *temp;
            temp = head;
            char illnes[20];
            printf("Enter the illness you'd like to search for patients with : ");
            scanf("%c", &t);
            scanf("%[^\n]", illnes);
            printf("\n \n");
            int yes = 0;
            while (temp != NULL)
            {
                if (!(strcasecmp(temp->illness, illnes)))
                {
                    yes = 1;
                    pAll(temp);
                }
                temp = temp->next;
            }
            if (yes == 0)
            {
                printf("There is no such patient !! \n");
                printf("\n");
            }
        }
        break;
        case 'c':
        {
            struct node *temp;
            temp = head;
            int yes = 0;
            char city[20];
            printf("Enter the Address(City) you'd like to search for patients with : ");
            scanf("%s", &city);
            printf("\n \n");
            while (temp != NULL)
            {
                if (!(strcasecmp(temp->address, city)))
                {
                    yes = 1;
                    pAll(temp);
                }
                temp = temp->next;
            }
            if (yes == 0)
            {
                printf("There is no such patient !! \n");
                printf("\n");
            }
        }
        break;
        case 'd':
        {
            int j = 1;
            struct node *temp;
            temp = head;
            while (temp != NULL)
            {
                if (temp->is_delete == true) // if flag = true then print just deleted patient
                {
                    printf("Patient Number:%d\n", j);
                    printf("Name is:%s\n", temp->name);
                    printf("Gender:%s\n", temp->gender);
                    printf("Date Of Admission:%d\n", temp->date_of_addmision);
                    printf("Date Of Birthday:%d\n", temp->date_of_birthday);
                    printf("Illness:%s\n", temp->illness);
                    printf("Address:%s\n", temp->address);
                    printf("Blood Type:%s\n", temp->Blood_type);
                    //printf("Is Deleted :%s\n",temp->is_delete ? "true" : "false"); // if p->is_delete = true print true else print false
                    printf("\n");
                    j++;
                }
                temp = temp->next;
            }
        }
        break;

        case 'e':
            return 0;
            break;

        default:
            printf("Please choose a valid choice (a - b - c - d - e) !! \n");
        }
        printf("\n\n====================================\n\n");
        printf("Choose From List\n");
        printf("\t a-All patients\n"
               "\t b-Category\n"
               "\t c-City\n"
               "\t d-Discharged\n"
               "\t e-To exit List menu\n");
        printf("Your choice is :");
       // ch = tolower(ch);
        scanf("%s", ch);
        printf("\n");
    }
};

struct node *soft_delete(struct node *head)
{
    // in soft delete i used a flag change when user choose to delete one of patients
    int j = 1, d = 0;
    struct node *temp;
    temp = head;
    printf("Enter number of patient to delete it :");
    scanf("%d", &d);
    while (temp != NULL)
    {
        if (j == d)
        {
            temp->is_delete = true;
        }
        j++;
        temp = temp->next;
    }
};

void XML(struct node *head)
{
    // some print statements to export all patients to xml file.

    FILE *fout;
    fout = fopen("Report.xml", "w");
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {

        fprintf(fout, "<patient>\n<name>%s</name>\n", temp->name);
        fprintf(fout, "<gender>%s</gender>\n", temp->gender);
        fprintf(fout, "<admissionDate value=\"%s\"/>\n", temp->date_of_addmision);
        fprintf(fout, "<birthDate value=\"%s\"/>\n", temp->date_of_birthday);
        fprintf(fout, "<diagnosis>%s</diagnosis>\n", temp->illness);
        fprintf(fout, "<city>%s</city>\n", temp->address);
        strtok(temp->Blood_type, "\n");
        fprintf(fout, "<bloodType>%s</bloodType>\n", temp->Blood_type);
        fprintf(fout, "</patient>\n");
        temp = temp->next;
    }
    printf("\nData exported To File \"Report.xml\" Successfuly");
    close(fout);
}
