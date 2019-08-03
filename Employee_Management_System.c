#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int id;
    char name[50],dept[50];
    char sal[50];
    struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start)
{
    struct node *newnode,*ptr;
    int id1;
    char name1[50],dept1[50];
    char sal1[50];
    printf("Enter -1 in employee id to end\n");
    printf("Enter the employee id:\n");
    scanf("%d",&id1);
    printf("Enter the employee name:\n");
    scanf("%s",&name1);
    printf("Enter the employee department:\n");
    scanf("%s",&dept1);
    printf("Enter the employee salary:\n");
    scanf("%s",&sal1);
    while(id1!=-1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->id=id1;
        strcpy(newnode->name,name1);
        strcpy(newnode->dept,dept1);
        strcpy(newnode->sal,sal1);
        //printf("%d",newnode->sal);
        if(start==NULL)
        {
            newnode->next=NULL;
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("Enter the employee id:\n");
        scanf("%d",&id1);
        if(id1==-1)
            break;
        printf("Enter the employee name:\n");
        scanf("%s",&name1);
        printf("Enter the employee department:\n");
        scanf("%s",&dept1);
        printf("Enter the employee salary:\n");
        scanf("%s",&sal1);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    printf("Employee Details are:\n\n");
    while(ptr!=NULL)
    {
        printf("Employee id: %d\n",ptr->id);
        printf("Employee name: ");
        puts(ptr->name);
        printf("Employee department: %s\n",ptr->dept);
        //puts(ptr->dept);
        printf("Employee salary: %s\n",ptr->sal);
        //printf("\n");
        ptr=ptr->next;
    }

    return start;
}
struct node *insertbeg(struct node *start)
{
    struct node *newnode;
    int id1;
    char name1[50],dept1[50];
    char sal1[50];
    printf("Enter the employee id:\n");
    scanf("%d",&id1);
    printf("Enter the employee name:\n");
    scanf("%s",&name1);
    printf("Enter the employee department:\n");
    scanf("%s",&dept1);
    printf("Enter the employee salary:\n");
    scanf("%s",&sal1);
    newnode=(struct node*)malloc(sizeof(struct node*));
    newnode->id=id1;
    strcpy(newnode->name,name1);
    strcpy(newnode->dept,dept1);
    strcpy(newnode->sal,sal1);
    newnode->next=start;
    start=newnode;
    return start;
}
struct node *deletebeg(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
        printf("UNDERFLOW\n");
    else
    {
        ptr=start;
        start=start->next;
        free(ptr);
    }
    return start;
}
struct node *deletenode(struct node *start)
{
    struct node *newnode,*preptr,*ptr;
    int id1;
    printf("Enter the employee id whose record has to be deleted\n");
    scanf("%d",&id1);
    ptr=start;
    if(ptr->id==id1)
    {
         start=deletebeg(start);
    }
    else
    {
        while(ptr->id!=id1)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    return start;
}
struct node *modify(struct node *start)
{
    struct node *newnode,*preptr,*ptr;
    int id1;
    char dept1[50];
    char sal1[50];
    printf("Enter the employee id whose record has to be modified\n");
    scanf("%d",&id1);
    ptr=start;
    while(ptr->id!=id1)
        ptr=ptr->next;
    printf("Enter the employee's new department:\n");
    scanf("%s",&dept1);
    printf("Enter the employee's new salary:\n");
    scanf("%s",&sal1);
    strcpy(ptr->dept,dept1);
	strcpy(ptr->sal,sal1);
    return start;
}
struct node *sort(struct node *start)
{
    struct node *ptr1,*ptr2;
    int idt;
    char namet[50],deptt[50];
    char salt[50];
    printf("Sorted list of employees on basis of id:\n");
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->id>ptr2->id)
            {
                idt=ptr1->id;
                ptr1->id=ptr2->id;
                ptr2->id=idt;
                strcpy(namet,ptr1->name);
                strcpy(ptr1->name,ptr2->name);
                strcpy(ptr2->name,namet);
                strcpy(deptt,ptr1->dept);
                strcpy(ptr1->dept,ptr2->dept);
                strcpy(ptr2->dept,deptt);
                strcpy(salt,ptr1->sal);
                strcpy(ptr1->sal,ptr2->sal);
                strcpy(ptr2->sal,salt);
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    start=display(start);
    return start;
}
main()
{
    int ch;
    do
    {
        printf("**MAIN MENU**\n");
        printf("1.Add an employee\n");
        printf("2.Display the list of employees\n");
        printf("3.Add an employee at the beginning\n");
        printf("4.Delete an employee based on his/her id\n");
        printf("5.Modify an existing employee\n");
        printf("6.Sort the employee list\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            start=create(start);
            break;
        case 2:
            start=display(start);
            break;
        case 3:
            start=insertbeg(start);
            break;
        case 4:
            start=deletenode(start);
            break;
        case 5:
            start=modify(start);
            break;
        case 6:
            start=sort(start);
            break;
        case 7:
            break;
        }
    }while(ch!=7);
}