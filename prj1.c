#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int choice,ch1;
char cho[5];
struct date
{
    int day,month,year;
};
struct
{
    char name[30],a_fname[30],a_lname[30],b_name[50];
    char a_name[30],status[30];
    char city[150];
    float mo;
    int m_id,b_id,mbno;
    char a_id[5];
    char m_type[20];
    int age, sr_no;
    struct date dob;
    struct date issue;
    struct date recieve;
}add,chk,upd;
void dash()
{
     printf("\n\t\t-----------------------------");
}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void close()
{
    system("cls");
    dash();
    printf("\n\t\tThank you for visiting");
    dash();
    printf("\n\t\tThis is programmed by Yash");
    dash();
}
void lbrn()
{
    char pasl[10];
    system("cls");

 printf("\n\n Enter The Password: ");
 scanf("%s",pasl);
 if(strcmp(pasl,"yashp1")==0)
 {
     printf("\n\nPassword Match!\nLOADING");
        for(int i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
     dash();
     printf("\n\t\t Welcome to librarian system");
 dash();

 }
 else
 {
     printf("\n Wrong Password....");
     lbrn();
 }
}
void addmbr()
{
    FILE *ad1;
    ad1=fopen("mlist.txt","a+");
adm:
    system("cls");
    printf("\n\t\t----add a member-----");
    dash();
    printf("\n add membership id: ");
    scanf("%d",&chk.m_id);
    while(fscanf(ad1,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {
            printf("\n already exists...");
            fordelay(1000000000);
            goto adm;
        }
    }
    add.m_id=chk.m_id;
    printf("\n add name :");
    scanf("%s",add.name);
     printf("\n add mobile no. :");
    scanf("%f",&add.mo);
     printf("\n add date of birth:");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
     printf("\n add age:");
    scanf("%d",&add.age);
     fprintf(ad1,"%d %s %f %d/%d/%d %d \n",add.m_id,add.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age);
     printf("\n account added successfully");
     dash();
     ag:
     printf("\n enter 1 for main menu, 2 for staff menu and 3 for exit ");
     scanf("%d",&choice);
 fclose(ad1);
     if(choice==1)
        menu();
     else if(choice==2)
        staff();
     else if(choice==3)
        close();
     else
     {
         printf("\n try again...");
         goto ag;
     }

}
void vimd()
{
    int ch,ch1;
    printf("\n\t\t view the database");
    dash();

    printf("\n 1)view all data \n 2)search by id\n 3)main menu \n 4)exit");
    dash();
    printf("\n add choice: ");
    scanf("%d",&ch);
     system("cls");
    FILE *view;
    view=fopen("mlist.txt","r");

   if(ch==1)
   {
       int t=0;

       printf("\n\t Database");
       dash();
       printf("\n Id Name Mobile_no.  Date_Of_Birth  Age \n ");
       while(fscanf(view,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
       {
           printf("%3d %s %.0f   %2d/%2d/%4d  %d \n",add.m_id,add.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age);
           t++;
       }
       if(t==0)
       {
           printf("\n no records...");
       }
        printf("\n enter 1 for menu 2 for exit");
       scanf("%d",&ch1);
       system("cls");
       if(ch1==1)
        vimd();
       else
        close();
   }
   else if(ch==2)
   {
       int f1=0;
      printf("\n search by id");
      dash();

      printf("\n add id: ");
      scanf("%d",&chk.m_id);
     while(fscanf(view,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
       {
          if(chk.m_id==add.m_id)
          {
              f1=1;
              break;
          }
       }
       if(f1==1)
       {
           printf("\n found..\n ");
           printf(" id: %3d \n name: %s\n mobile no.: %.0f \n date of birth: %2d/%2d/%4d \n Age: %d \n",add.m_id,add.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age);
       }

     printf("\n enter 1 for menu 2 for exit");
       scanf("%d",&ch1);
       system("cls");
       if(ch1==1)
        vimd();
       else
        close();
   }
   if(ch==3)
    menu();
   else if(ch==4)
   close();

}
void edmbr()
{
    int test=0;
    printf("\n Edit details of member");
    dash();
    FILE *upde,*old;
    old=fopen("mlist.txt","r");
    upde=fopen("new.txt","w");
    printf("\n add membership id: ");
    scanf("%d",&chk.m_id);

     while(fscanf(old,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
       {
          if(chk.m_id==add.m_id)
          {
             test=1;
    printf("\n old details: ");
    printf(" id: %3d \n name: %s\n mobile no.: %.0f \n date of birth: %2d/%2d/%4d \n Age: %d \n",add.m_id,add.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age);
    printf("\n\n What you have to update: ");
    printf("\n 1)Name \n 2)Mobile no. \n 3)Staff Menu \n 4)exit");
    dash();

    printf("\n add your choice: ");
    scanf("%d",&choice);
    system("cls");

    switch(choice)
    {
    case 1:
        printf("\n add a new name: ");
        scanf("%s",upd.name);
        fprintf(upde,"%d %s %f %d/%d/%d %d \n",add.m_id,upd.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age);
        system("cls");
        printf("\n saved");
        break;
    case 2:
        printf("\n add a new mobile no. : ");
        scanf("%f",upd.mo);
        fprintf(upde,"%d %s %.0f %d/%d/%d %d \n",add.m_id,upd.name,upd.mo,add.dob.day,add.dob.month,add.dob.year,add.age);
        system("cls");
        printf("\n saved");
        break;
    case 3:
        staff();
        break;
    case 4:
        close();
        break;
    }
          }
          fclose(old);
          fclose(upde);
           remove("mlist.txt");
           rename("new1.txt","mlist.txt");
       }



     printf("\n enter 1 for menu 2 for exit");
       scanf("%d",&ch1);
       system("cls");
       if(ch1==1)
        edmbr();
       else
        close();
}
void vibook()
{
    int ch;
    FILE *vbook;
    vbook=fopen("blist.txt","r");
    printf("\n view database");
    printf("\n 1)all Data\n 2)search\n 3)menu\n 4)exit");
    printf("\n add your choice: ");
    scanf("%d",&ch);
    int ch1;
    switch(ch)
    {
    case 1:
        printf("\nsr_no book_id book_name author's_name authors_id\n");
         while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id)!=EOF)
         {
             printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id);
         }
         break;
    case 2:
        men:
        printf("\n search book by 1)book name 2)authors name 3)book id 4)author id 5)menu 6)exit");
        printf("\n add your choice: ");
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            printf("\n add keyword from books name : ");
            scanf("%s",chk.b_name);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id)!=EOF)
            {
                if(strstr(add.b_name,chk.b_name)!=NULL)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id);
                }
            }
            break;
        case 2:
            printf("\n add keyword from author's name : ");
            scanf("%s",chk.a_name);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id)!=EOF)
            {
                if(strstr(add.a_fname,chk.a_name)!=NULL || strstr(add.a_lname,chk.a_name)!=NULL)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id);
                }
            }
            break;
        case 3:
            printf("\n add keyword from book ID : ");
            scanf("%d",&chk.b_id);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id)!=EOF)
            {
                if(chk.b_id==add.b_id)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id);
                }
            }
            break;
        case 4:
            printf("\n add keyword from Author's ID : ");
            scanf("%s",chk.a_id);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id)!=EOF)
            {
                if(strstr(add.a_id,chk.a_id)!=NULL)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id);
                }
            }
            break;
        case 5:
            goto men;
            break;
        case 6:
            close();
            break;
        }
        break;
    case 3:
        vibook();
        break;
    case 4:
        close();
        break;
    }
    fclose(vbook);
}

void edbook()
{
    int ch;
    FILE *abook,*issbok;
    int i=1;
    dash();
    printf("\n\t\t Edit book Database");
    dash();
    printf("\n\n 1)Add a book \n 2)delete a book \n 3)edit database \n 4)menu \n 5)exit");
    printf("\n add choice:");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        abook=fopen("blist.txt","a+");
        system("cls");
        printf("\n add a book");
        adb:
        printf("\n\n add book id: ");
        scanf("%d",&chk.b_id);
         while(fscanf(abook,"%d %d %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id)!=EOF)
       {
           i++;
           if(add.b_id==chk.b_id)
           {
               printf("\n This id already exists....");
               system("cls");
               goto adb;
           }
        }
        add.b_id=chk.b_id;
        add.sr_no=i;
        printf("\n add book name: ");
        scanf("%s",add.b_name);
        printf("\n add authors first name: ");
        scanf("%s",add.a_fname);
        printf("\n add authors last name: ");
        scanf("%s",add.a_lname);
        printf("\n add authors id(3 characters of authors last name): ");
        scanf("%s",add.a_id);
        fprintf(abook,"%d %d %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id);
        printf("\n book saved successfully");
        issbok=fopen("isslist.txt","a+");
        strcpy(add.status,"available");
        fprintf(issbok,"%d %d %s %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status);
        fclose(issbok);
        fclose(abook);
        break;
    case 4:
        edbook();
        break;
    case 5:
        close();
       }
    }
void profile()
{
    int test=0;
    printf("\n add your id: ");
    scanf("%d",&chk.m_id);
    FILE *pf1;
    pf1=fopen("mlist.txt","r");
     while(fscanf(pf1,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {test=1;
        break;}
    }
    if(test==1)
    {
        printf("\n------------\n");
        printf("Your Profile");
        printf("\n------------");
        printf("\n Name=%s",add.name);
        printf("\n mobile no.=%.0f",add.mo);
        printf("\n birth date=%d/%d/%d",add.dob.day,add.dob.month,add.dob.year);
        printf("\n-------------------");
    }
    fclose(pf1);
}
/*void resbook()
{
    int ch,che,test=0;
    printf("\n------------------");
    printf("\n Reissue the book ");
    printf("--------------------");
    FILE *res1,*res,*re0;
    re0=fopen("mlist.txt","r");
    res=fopen("isslist.txt","r");
    res1=fopen("isslist1.txt","w");
    printf("\n add your id: ");
    scanf("%d",&chk.m_id);
    while(fscanf(re0,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {test=1;}}
            if(test==1)
            {
            printf("\n add book id: ");
            scanf("%d",&chk.b_id);

           while(fscanf(res," %d %d %s %s %s %s %s \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status)!=EOF)
           {
            if(add.b_id==chk.b_id)
            {
                printf("\n book found...\n");
                printf("%d %d %s %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status);
              if(strcmp(add.status,"not")==0)
             {
                  printf("\n 1)Reissue the book \n 3)Return the book ");
                  printf("\n enter your choice: ");
                  scanf("%d",&ch);

                  switch(ch)
                {
                  case 1:
                       printf("\n do you want to reissue it ?");
                       scanf("%s",cho);
                       if(strcmp(cho,"yes")==0)
                        {
                          printf("\n Your book is issued");
                          strcpy(add.status,"not");
                          fprintf(res1," %d %d %s %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status);
                        }
                    break;
                  case 2:
                     break;
                }
             }

            }
            else
              fprintf(res1," %d %d %s %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status);
        }
    }
    else
    {
        printf("\n you are not a membor");
    }
    fclose(re0);
    fclose(res1);
    fclose(res);
    remove("isslist.txt");
    rename("isslist1.txt","isslist.txt");
}*/
void issbook()
{
    int ch,che,test=0,is=0;
    dash();
    printf("\n\t\t Issue a Book");
    dash();
    printf("\n\n");
    FILE *issb,*issb1,*issid;
    issid=fopen("mlist.txt","r");
    issb=fopen("isslist.txt","r");
    issb1=fopen("isslist1.txt","w");
    printf("\n add your id: ");
    scanf("%d",&chk.m_id);
    while(fscanf(issid,"%d %s %f %d/%d/%d %d \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {
            test=1;
        }

    }
            if(test==1)
            {
            printf("\n add book id: ");
            scanf("%d",&chk.b_id);
        while(fscanf(issb," %d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
           {
               if(chk.m_id==add.m_id)
               {
                   is++;
               }
           }
           while(fscanf(issb," %d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
           {
            if(add.b_id==chk.b_id)
            {
                printf("\n book found...\n");
                printf("%d %d %s %s %s %s %s \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status);
              if(strcmp(add.status,"available")==0)
             {
                printf("\n book is available...");
                printf("\n do you want to issue it ?");
                scanf("%s",cho);
                if(strcmp(cho,"yes")==0)
                {
                     if(is>=4)
                   {
                    printf("\n you cant issue a book....");
                    fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);

                   }
                    printf("\n add date: ");
                    scanf("%d/%d/%d",&add.issue.day,&add.issue.month,&add.issue.year);
                    printf("\n Your book is issued");
                    add.m_id=chk.m_id;
                    strcpy(add.status,"not");
                    fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
                }
                else
                    fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,"available",0,add.issue.day,add.issue.month,add.issue.year);
             }
             else
             {
                printf("\n book is not available....");
                fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,"available",add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
            }
            else
               fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.b_id,add.b_name,add.a_fname,add.a_lname,add.a_id,"available",add.m_id,add.issue.day,add.issue.month,add.issue.year);
        }
    }
    else
    {
        printf("\n you are not a member");
    }

        fclose(issb);
        fclose(issb1);
        fclose(issid);
        //remove("isslist.txt");
       // rename("isslist1.txt","isslist.txt");

        printf("\n add 1 for menu 2 for exit");
        scanf("%d",&che);
        switch(che)
        {
        case 1:
            menu();
            break;
        case 2:
            close();
            break;
        }
}

void readmn()
{
    system("cls");
    int che,ch;
    dash();
    printf("\n\t\t Reader section");
    dash();

    printf("\n 1)view the book database \n 2)issue a book \n 3)view your account \n 4)menu \n 5)exit");
    printf("\n add your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        vibook();
        break;
    case 2:
        issbook();
        break;
    case 3:
        profile();
        break;
    case 4:
        menu();
        break;
    case 5:
        close();
        break;
    }
    printf("\n enter 1 for menu and 2 for exit");
    scanf("%d",&che);
    switch(che)
    {
    case 1:
        readmn();
        break;
    case 2:
        close();
        break;
    }
}
void staff()
{
    int ch;
    dash();
     char pasl[10];
    system("cls");

     dash();
     printf("\n\t\t   Welcome to staff system");
 dash();
 printf("\n");
 dash();
 printf("\n\t\t 1)Add A Member \n\t\t 2)Edit details of Member \n\t\t 3)View  member's Database \n\t\t 4)Issue a Book \n\t\t 5)Reissue a Book \n\t\t 6)View Book database");
 printf("\n\t\t 7)Edit book database \n\t\t 8)treasury\n\t\t 9)Main menu \n\t\t 10)exit");
 dash();
 printf("\n Enter your choice: ");
 scanf("%d",&ch);
system("cls");
 switch(ch)
 {
 case 1:
     addmbr();
    break;
case 2:
    edmbr();
    break;
case 3:
    vimd();
    break;
case 4:
    issbook();
    break;
case 6:
    vibook();
    break;
case 5:
   // resbook();
   break;
case 7:
    edbook();
    break;
case 8:
    break;
case 9:
    menu();
    break;
case 10:
    close();
    break;
default:
    break;

 }

}
void menu()
{
    int ch;
    printf("\n\t\t------Central-Library--------");
    dash();
    printf("\n\t\t 1)librarian");
    printf("\n\t\t 2)Staff \n\t\t 3)Reader \n\t\t 4)exit");
    dash();
    printf("\n\n Enter your Choice here: ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        lbrn();
        break;
    case 2:
        staff();
        break;
    case 3:
        readmn();
        break;
    case 4:
        close();
        break;
    }
}
void main()
{
    dash();
    printf("\n\t\t\tCentral Library ");
    dash();
    printf("\n");
    printf("\n do you want to enter yes or no: ");
    scanf("%s",cho);
    if(strcmp("yes",cho)==0)
    {
        system("cls");
    menu();
    }
}
