
#include <stdio.h>
#include <string.h>
int size = 3;
// int count=size;
/*
Book Structure
*/
typedef struct Book
{
    int id;
    char name[20];
    char author[20];
    double price;
    double rating;
} Book;
/*
Function declrations
*/
// void storeBook(Book *);
void storeBooks(Book *);
void displayDetails(Book *);
void displayBook(int, Book *);
void searchBook(Book *);
void updateDetails(Book *);
void topBooks(Book *);
void deleteBook(Book *);
// void addBook(Book* bk);
/*
Main FUnction
*/

void main()
{
    Book bk[10];
    storeBooks(bk);
    int choice;
    char ch;

    do
    {
        printf("\nEnter your Choice:\n1)Display Book\n2)Search Book\n3)update Book\n4)Top Books\n5)Delete Book\nEnter Here:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayDetails(bk);
            break;
        case 2:
            searchBook(bk);
            break;
        case 3:
            updateDetails(bk);
            break;
        case 4:
            topBooks(bk);
            break;
        case 5:
            deleteBook(bk);
            break;
            // case 6:
            //     storeBook(bk);
            //     break;
            // case 7:
            //     addBook(bk);
            //     break;

        default:
            printf("Wrong Input");
            break;
        }
        printf("\nDo You Want To Continue ...Press y\n");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
/*
Function Defination of StoreBook() function
*/
void storeBooks(Book *bk)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the id of the Book %d:", i + 1);
        scanf("%d", &bk[i].id);
        printf("\nEnter the name of the Book %d:", i + 1);
        scanf("%s", &bk[i].name);
        printf("\nEnter the author of the Book %d:", i + 1);
        scanf("%s", &bk[i].author);
        printf("\nEnter the price of the Book %d:", i + 1);
        scanf("%lf", &bk[i].price);
        printf("\nEnter the rating of the Book %d:", i + 1);
        scanf("%lf", &bk[i].rating);
    }
    printf("\n*******************************************************\n");
}
/*
Function Defination of displayDetails() function
*/
void displayDetails(Book *bk)
{
    for (int i = 0; i < size; i++)
    {

        printf("\nId of the Book %d is:%d\n", i + 1, bk[i].id);
        printf("Name of the Book %d is:%s\n", i + 1, bk[i].name);
        printf("Author of the Book %d are:%s\n", i + 1, bk[i].author);
        printf("Price of the Book %d is:%lf\n", i + 1, bk[i].price);
        printf("Rating of the Book %d is:%lf\n", i + 1, bk[i].rating);
        printf("\n***********************************************************\n");
    }
    printf("\n");
}
/*
Function defination displayBook() function
*/
void displayBook(int i, Book *bk)
{

    printf("Id of the Book %d is:%d\n", i + 1, bk[i].id);
    printf("Name of the Book %d is:%s\n", i + 1, bk[i].name);
    printf("Author of the Book %d are:%s\n", i + 1, bk[i].author);
    printf("Price of the Book %d is:%lf\n", i + 1, bk[i].price);
    printf("Rating of the Book %d is:%lf\n", i + 1, bk[i].rating);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
/*
function defination of the searchBook() function
*/
void searchBook(Book *bk)
{
    int choice;
    printf("\nEnter Your Choice To Search Book :\n1)Search Book By Id\n2)Search Book By Name\n3)Search Book By Author\nEnter Here: ");
    scanf("%d", &choice);
    /*
    Search By Using Book Id
    */
    if (choice == 1)
    {
        int bkid;
        printf("\nEnter The Id Of The Book:");
        scanf("%d", &bkid);
        printf("\n");
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (bkid == bk[i].id)
            {
                displayBook(i, bk);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nBook Not Found......!!!!!\n");
        }
    }
    /*
   Search By Using Book Name
   */
    if (choice == 2)
    {
        char bname[20];
        printf("\nEnter The Name Of The Book To Search:");
        scanf("%s", &bname);
        printf("\n");
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            int ans = strcmp(bname, bk[i].name);
            if (ans == 0)
            {
                displayBook(i, bk);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nBook Not Found.....!!!\n");
        }
    }
    /*
   Search By Using Book Author
   */
    if (choice == 3)
    {
        int count = 0;
        char bauthor[20];
        printf("\nEnter The Name Of The Book To Search:");
        scanf("%s", &bauthor);
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            int ans = strcmp(bauthor, bk[i].author);
            if (ans == 0)
            {
                displayBook(i, bk);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nBook Not Found.....!!!\n");
        }
    }
}

/*
Function defination of the updateDetails() function
*/
void updateDetails(Book *bk)
{
    int choice;
    printf("\nEnter The Choice To Update The Book Details\n1)Update Price\n2)Update Ratings\nEnter Here:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        int bid;
        int count = 0;
        printf("\nEnter The Id of Book To Update The Price:");
        scanf("%d", &bid);
        for (int i = 0; i < size; i++)
        {
            if (bid == bk[i].id)
            {
                double bprice;
                printf("\nEnter The New Price Of The Book:");
                scanf("%lf", &bprice);
                printf("\n");
                bk[i].price = bprice;
                printf("\nUpdated Details Are:\n");
                printf("\n");
                displayBook(i, bk);
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nBook Details Not Match\n");
        }
    }
    if (choice == 2)
    {
        int count = 0;
        int bid;
        double brating;
        printf("\nEnter The Id of Book To Update The Ratings:");
        scanf("%d", &bid);
        for (int i = 0; i < size; i++)
        {
            if (bid == bk[i].id)
            {
                printf("\nEnter The New Ratings Of The Book:");
                scanf("%lf", &brating);
                bk[i].rating = brating;
                printf("\n");
                printf("\nUpdated Details Are:\n");
                printf("\n");
                displayBook(i, bk);
            }
        }
        if (count == 0)
        {
            printf("\nBook Details Not Match\n");
        }
    }
}
/*
Function Defination Of The TopBooks() Function
*/
void topBooks(Book *bk)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bk[j].rating < bk[j + 1].rating)
            {
                double temp = bk[j].rating;
                bk[j].rating = bk[j + 1].rating;
                bk[j + 1].rating = temp;
            }
        }
    }
    printf("\n Top Three Books Are....\n");
    printf("\n*************************************************\n");
    if (size > 3)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("Book %d is:\n", i + 1);
            displayBook(i, bk);
            printf("\n**********************************************\n");
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("Book %d is:\n", i + 1);
            displayBook(i, bk);
            printf("\n**********************************************\n");
        }
    }
}
/*
Function defination of DeleteBook() function
*/
void deleteBook(Book *bk)
{
    int bid;
    printf("\nEnter the id of Book to delete:");
    scanf("%d", &bid);
    for (int i = 0; i < size; i++)
    {
        if (bk[i].id == bid)
        {
            for (int j = i; j < size; j++)
            {
                bk[j].id = bk[j + 1].id;
                bk[j].price = bk[j + 1].price;
                bk[j].rating = bk[j + 1].rating;
                strcpy(bk[j].name, bk[j + 1].name);
                strcpy(bk[j].author, bk[j + 1].author);
            }
            break;
        }
    }
    size--;
}
