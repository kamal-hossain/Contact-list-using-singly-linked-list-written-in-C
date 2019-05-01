#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Declaring Structure
struct Node
{
    char name[20];
    char phone[18];
    char email[25];
    struct Node *link;
};
//Declaring Global Variables
struct Node* Start=NULL;
struct Node *add, *firstNode, *lastNode;
char userInput;
int countContacs =0;

//Function Prototypes
void mainMenu();
void insert();
void insertNsort();
void displaycontact(struct Node* PTR);
void findContact(void);
void switchMenu();

//Main function
int main()
{
    Start = NULL;

    printf("\t\t______________________________\n");
    printf("\t\tWelcome To Contact Database\n");
    printf("\t\t\tCopyright @2019\n");
    printf("\t\t______________________________\n");
    do
    {
        mainMenu();
    }
    while(userInput!='q');

    return 0;
}

/*Sub-Functions Starts from here*/

//Main menu for user
void mainMenu()
{
    printf("\n\t\t\t---------------------\n");
    printf("\t\t\t| ====Main Menu==== |");
    printf("\n\t\t\t---------------------");
    printf("\n\t  Total Contacts in list = %d\n", countContacs);
    printf("\n\t  Add a new contact \t     (Press 1 and enter)\n");
    printf("\t  View all contacts \t     (Press 2 and enter)\n");
    printf("\t  Search a contact \t     (Press 3 and enter)\n");
    printf("\t**Exit from Contact Database (Press Q and enter)\n");

    switchMenu();
}

//Checking case
void switchMenu()
{
    fflush(stdin);
    userInput = 999;

    printf("\n\t\t\tEnter value:");
    scanf("%c", &userInput);
    printf("\t\t____________________________\n");

    userInput = tolower(userInput);
    switch(userInput)
    {
    case '1':
        insert();
        break;
    case '2':
        displaycontact(Start);
        break;
    case '3':
        findContact();
        break;
    case 'q':
        exit(0);
        break;
    default:
        printf("\t\t**Invalid entry! Try again!**\n");
        switchMenu();
        break;
    }
}
//Adding Contact(s) to the linked list
void insert()
{
    ++countContacs;
    printf("\n\t\t||Add a Contact|| \n");
    printf("\t\t------------------\n");

    //Taking input from User
    char NAME[20], NUMBER[18], EMAIL[25];
    fflush(stdin);
    printf("\t\tEnter Name   (29 MAX): ");
    gets(NAME);
    printf("\t\tEnter Number (17 MAX): ");
    gets(NUMBER);
    printf("\t\tEnter E-mail (24 MAX): ");
    gets(EMAIL);

    add= malloc(sizeof(struct Node));


    //Adding first contact in add
    strcpy(add->name,NAME);
    strcpy(add->phone,NUMBER);
    strcpy(add->email,EMAIL);
    add->link=NULL;

    //Defining New Node position in linked list
    if(Start==NULL)
    {
        Start=add;
    }
    else
    {
        insertNsort();
        /* if any other contact is already
        available in linked list,
        then this func. will be called
         to sort and insert in correct position*/
    }

    printf("\n\t\tOne contact added successfully\n");
    printf("\t\tPress ENTER to go to Main menu...");
    getch();
    return;
}

//sorting and inserting
void insertNsort()
{
    lastNode=NULL;
    firstNode=Start;

    while (firstNode!=NULL)
    {
        int check;
        check = strcmp(add->name,firstNode->name);

        if(check<=0)
        {
            if(lastNode==NULL)
            {
                add->link=Start;
                Start=add;
                printf("\n\t\tAdded to contact successfully\n");
                return;
            }
            else
            {
                add->link=lastNode->link;
                lastNode->link=add;
                printf("\n\t\tAdded to contact successfully\n");
                return;
            }
        }
        else
        {
            lastNode=firstNode;
            firstNode=firstNode->link;
        }
    }
    lastNode->link=add;
}
//Printing All contact
void displaycontact(struct Node* PTR)
{

    if(Start==NULL)
    {
        printf("\n\t\t__Sorry!The is no Contacts to Show!!\n", countContacs);
        printf("\t\tPress any key to go to Main menu...");
        getch();
        return;
    }
    printf("\n\tTotal Contact(s) - %d \n", countContacs);
    printf("\t---------------------\n");
    int countNow=1;
    while (PTR!=NULL)
    {
        printf("\tContact-(%d)\n",countNow);
        printf("\tName  : %s \n", PTR->name);
        printf("\tNumber: %s \n", PTR->phone);
        printf("\tE-mail: %s \n\n", PTR->email);
        countNow++;
        PTR = PTR->link;
    }
    printf("\t\tEnd of list!!\n");
    printf("\t\tPress any key to go to Main menu...");
    getch();
}

//Searching A contact!
void findContact(void)
{
    if(add==NULL)
    {
        printf("\t\t_________________________________________\n");
        puts("\t\t Sorry, There are no contacts to find!! ");
        puts("\t\tPress any key to go to main menu...");
        getch();
        return;
    }

    int check;
    printf("\n\t\t* Welcome to search menu * \n");
    printf("\t\tTo search by name  (Press 1)\n\t\tTo Search by number(Press 2)\n");
    printf("\n\t\t     Enter value: ");
    scanf("%d", &check);

    if(check==1)
    {
        char buff[20];

        printf("\n\t\tEnter contact name: ");
        fflush(stdin);
        gets(buff);

        struct Node* find = NULL;

        find = Start;

        while(find != NULL)
        {
            if( strcmp(find->name, buff) == 0 )
            {
                printf("\n\t\tName: %s\t", find->name);
                printf("Contact No.: %s\n", find->phone);
                puts("\n\t\tPress any key to go to main menu...");
                getch();
                return;
            }
            else
            {
                find = find->link;
            }
        }
        printf("\t\t***contact %s was not found!***\n",buff);
        return;
    }
    else if(check==2)
    {
        char buff[20];

        printf("\n\t\tEnter Number: ");
        fflush(stdin);
        gets(buff);
        struct Node* find = NULL;

        find = Start;

        while(find != NULL)
        {
            if( strcmp(find->phone, buff) == 0 )
            {
                printf("\n\t\tName: %s\t", find->name);
                printf("Contact No.: %s\n", find->phone);
                puts("\n\t\tPress any key to go to main menu...");
                getch();
                return;
            }
            else
            {
                find = find->link;
            }
        }
        printf("\t\tcontact %s was not found!\n",buff);
        return;
    }
    else
    {
        printf("\t\t_______________________\n");
        printf("\t\t    Invalid entry!!\n");
    }
}
/*-------------End-------------------*/
