// C program on Online Voting System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// creating a node
struct node
{
    char data[10];     // node consists of a data field & count field along
    struct node *next; // with address field.
    int count;
} *head;

// Inserting a node
void insertNode(char x[], int len)
{
    struct node *nn, *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    for (int i = 0; i < len; i++)
    {
        nn->data[i] = x[i];
    }
    nn->count = 0;
    temp = head;
    if (head == NULL)
    {
        head = nn;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}

int display()
{
    struct node *temp = head;
    int i = 1;
    if (head == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        printf("\n%d .%s votes: %d", i++, temp->data, temp->count);
        temp = temp->next;
    }
    return i--;
}

// this function increments the vote count of a selected candidate/party
void check(char vote[], int len)
{
    struct node *temp = head;
    int i;
    while (temp != NULL)
    {
        for (i = 0; i < len; i++)
        {
            if (temp->data[i] != vote[i])
            {
                break;
            }
        }
        if (i == len)
        {
            temp->count = (temp->count) + 1;
        }
        temp = temp->next;
    }
}

// To check which party is leading & going to win the Election
void who_is_Leading()
{
    struct node *temp, *counter;
    int lead = 0, sum = 0;
    temp = head;
    while (temp != NULL)
    {
        if ((temp->count) > lead)
        {
            lead = temp->count;
            counter = temp;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp != counter)
            sum += temp->count;

        temp = temp->next;
    }
    temp = head;
    printf("Leading party(s) : ");
    while (temp != NULL)
    {
        if (temp->count == lead)
            printf("%s ", temp->data);

        temp = temp->next;
    }

    if (lead > sum)
        printf("\nWinning party is : %s\n", counter->data);
    else
        printf("\nNo party can win at this point of time\n");
}
int main()
{
    // Write C code here
    // printf("Hello world");
    char s[10];
    int n, choice, l, total = 0;
    head = NULL;
    printf("Enter number of participants :\n");
    scanf("%d", &n);
    printf("Enter the candidates:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        insertNode(s, strlen(s));
    }
    printf("\n1.Vote for your favourite candidate/party ");
    printf("\n2.Check the number of votes of each candidate");
    printf("\n3.Check the candidate whose leading");
    printf("\n0.Exit\n");

    display();

    do
    {

        // Taking the users choice

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char candidate_choice[10];
            // display();
            total++;
            printf("\nChoose your candidate by name : ");
            scanf("%s", candidate_choice);
            check(candidate_choice, strlen(candidate_choice));
            break;
        }
        case 2:
        {
            // display the number of votes;
            l = display();
            break;
        }
        case 3:
        {
            // To check whether who is leading
            printf("Total votes registered are : %d\n", total);
            who_is_Leading();
            break;
        }
        default:
        {
            printf("Select any other correct option mentioned above\n");
            choice = 0;
            break;
        }
        }
    } while (choice != 0);

    printf("Thank you\n");
    // int choice

    return 0;
}
