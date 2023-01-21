#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int choice,ch1;
char cho[5],cho1[5];
struct flags
{
    int f1,f2;
}emp,mem;
struct date
{
    int day,month,year;
};
struct trns
{
    int sr_no;
    char item[30];
    float with,cred,tot;
};
struct book
{
    char a_fname[30],a_lname[30],b_name[50],a_name[30];
    int b_id;
    char a_id[5];
};
struct employee
{
    char name[30],e_psd[10];
    char e_city[30];
    char e_post[30];
    float e_mo;
    int age,e_id;
};
struct
{
    char name[30],status[30],city[150],m_psd[10];
    float mo;
    int m_id,mbno;
    char m_type[20];
    int age, sr_no;
    struct book bk;
    struct trns trs;
    struct date dob;
    struct date e_dob;
    struct date issue;
    struct date recieve;
    struct date reissue;
    struct employee emp;
}add,chk,upd;
void dash()
{
     printf("\n\t\t-----------------------------");
}
int valid_date(int day, int mon, int year)
{
    int is_valid = 1, is_leap = 0;
    if (year >= 1800 && year <= 9999)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            is_leap = 1;
        }
        if(mon >= 1 && mon <= 12)
        {
            if (mon == 2)
            {
                if (is_leap && day == 29)
                {
                    is_valid = 1;
                }
                else if(day > 28)
                {
                    is_valid = 0;
                }
            }
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }
            else if(day > 31)
            {
                is_valid = 0;
            }
        }
        else
        {
            is_valid = 0;
        }
    }
    else
    {
        is_valid = 0;
    }
    return is_valid;
}
int func1(x)
{
     int y=0;
     switch(x)
     {
case 1: y=0; break;
case 2: y=31; break;
case 3: y=59; break;
case 4: y=90; break;
case 5: y=120;break;
case 6: y=151; break;
case 7: y=181; break;
case 8: y=212; break;
case 9: y=243; break;
case 10:y=273; break;
case 11:y=304; break;
case 12:y=334; break;
default: printf("Error encountered"); exit(1);
     }
return(y);
}
int penalty(int p)
{
    return 5*(p-14);
}
int datediff(int day1,int mon1,int year1,int day2,int mon2,int year2)
{
    int ref,dd1,dd2,i;

  if(valid_date(day1,mon1,year1)&&valid_date(day2,mon2,year2))
   {
     ref = year1;
     if(year2<year1)
      ref = year2;

     dd1=0;
     dd1=func1(mon1);
     for(i=ref;i<year1;i++)
      {
	    if(i%4==0)
	    dd1+=1;
      }
     dd1=dd1+day1+(year1-ref)*365;
     dd2=0;
  for(i=ref;i<year2;i++)
  {
	if(i%4==0)
	dd2+=1;
  }
   dd2=func1(mon2)+dd2+day2+((year2-ref)*365);
   int dd3=abs(dd2-dd1);
   printf("diff between the two dates is %d",dd3);
return dd3;
}
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
 printf("\n 1)profile \n 2)menu \n 3)exit");
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
    int s=0,c=0,d=0,sc=0;
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
    ad2:
    printf("\n add password[8 characters and must contain digit, small and capital alphabet and characters[@,&,#]: ");
    scanf("%s",add.m_psd);
    char a[10];
     strcpy(a,add.emp.e_psd);
            for(int i=0;i<strlen(a);i++)
            {
                if(a[i]>='a'&& a[i]<='z')
                    s++;
                else if(a[i]>='A'&& a[i]<='Z')
                    c++;
                else if(a[i]>='0' && a[i]<='9')
                    d++;
                else if(a[i]=='#'||a[i]=='@'||a[i]=='&')
                    sc++;
            }
            if(s>0&&sc>0&&d>0&&c>0)
            {
                printf("\n password is strong..");
            }
            else{
                printf("\n password is poor");
                goto ad2;
            }
    printf("\n confirm the password: ");
    ad3:
    scanf("%s",chk.m_psd);
    if(strcmp(chk.m_psd,add.m_psd)==0)
    {
     fprintf(ad1,"%d %s %f %d/%d/%d %d %s \n",add.m_id,add.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age,add.m_psd);
     printf("\n account added successfully");
    }
    else
        goto ad3;
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
       while(fscanf(view,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
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
     while(fscanf(view,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
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

     while(fscanf(old,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
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
        fprintf(upde,"%d %s %f %d/%d/%d %d %s \n",add.m_id,upd.name,add.mo,add.dob.day,add.dob.month,add.dob.year,add.age,add.m_psd);
        system("cls");
        printf("\n saved");
        break;
    case 2:
        printf("\n add a new mobile no. : ");
        scanf("%f",upd.mo);
        fprintf(upde,"%d %s %.0f %d/%d/%d %d %s \n",add.m_id,upd.name,upd.mo,add.dob.day,add.dob.month,add.dob.year,add.age,add.m_psd);
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
void tres()
{
    int ch;
    float total1=0.0,total0=0.0;
    FILE *tresr;
    tresr=fopen("tlist.txt","r");
    printf("\n tresury");
    printf("\n---------");
    printf("\n\n1)view the account \n2)view the income \n3)view the expenses \n4)menu \n5)exit");
    printf("\n add your choice -> ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\n view the account");
        printf("\n srno item name withdrawal credit total");
        printf("\n---------------------------------------");
        while(fscanf(tresr,"%d %s %f %f %f\n",&add.trs.sr_no,add.trs.item,&add.trs.with,&add.trs.cred,&add.trs.tot)!=EOF)
        {
             printf("\n %d    %s\t %.2f   %.2f   %.2f",add.trs.sr_no,add.trs.item,add.trs.with,add.trs.cred,add.trs.tot);
        }
        break;
    case 2:
        printf("\n view the income");
        printf("\n srno item name credit total");
        printf("\n---------------------------------------");
        while(fscanf(tresr,"%d %s %f %f %f\n",&add.trs.sr_no,add.trs.item,&add.trs.with,&add.trs.cred,&add.trs.tot)!=EOF)
        {
            if(add.trs.cred>0)
           printf("\n %d    %s\t %.2f  %.2f",add.trs.sr_no,add.trs.item,add.trs.cred,total0);
           total0 = total0 + add.trs.cred;
        }
        printf("\n total income--> %.2f",total0);
        break;
    case 3:
        printf("n view the expenses");
        printf("\n srno item name withdrawal total");
        printf("\n---------------------------------------");
        while(fscanf(tresr,"%d %s %f %f %f\n",&add.trs.sr_no,add.trs.item,&add.trs.with,&add.trs.cred,&add.trs.tot)!=EOF)
        {
            if(add.trs.with>0)
            printf("\n %d    %s\t -%.2f   -%.2f",add.trs.sr_no,add.trs.item,add.trs.with,total1);
            total1=total1+add.trs.with;
        }
        printf("\n total expenses--> %.2f",total1);
        break;
    case 4:
        menu();
    case 5:
        close();
    default:
        printf("\n you have entered wrong no.");
        break;
    }
    fclose(tresr);
    printf("\n enter 1 for treasury menu 2 for main menu and 3 for exit");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        tres();
        break;
    case 2:
        menu();
        break;
    case 3:
        close();
        break;
    }
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
         while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF)
         {
             printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
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
            scanf("%s",chk.bk.b_name);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF)
            {
                if(strstr(add.bk.b_name,chk.bk.b_name)!=NULL)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
                }
            }
            break;
        case 2:
            printf("\n add keyword from author's name : ");
            scanf("%s",chk.bk.a_name);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF)
            {
                if(strstr(add.bk.a_fname,chk.bk.a_name)!=NULL || strstr(add.bk.a_lname,chk.bk.a_name)!=NULL)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
                }
            }
            break;
        case 3:
            printf("\n add keyword from book ID : ");
            scanf("%d",&chk.bk.b_id);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF)
            {
                if(chk.bk.b_id==add.bk.b_id)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
                }
            }
            break;
        case 4:
            printf("\n add keyword from Author's ID : ");
            scanf("%s",chk.bk.a_id);
            while(fscanf(vbook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF)
            {
                if(strstr(add.bk.a_id,chk.bk.a_id)!=NULL)
                {
                    printf("%3d    %5d  %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
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
    system("cls");
    int ch,che;
    FILE *abook,*issbok,*tr;
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
        tr=fopen("tlist.txt","a+");
        system("cls");
        printf("\n add a book");
        adb:
        printf("\n\n add book id: ");
        scanf("%d",&chk.bk.b_id);
         while(fscanf(abook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF)
       {
           i++;
           if(add.bk.b_id==chk.bk.b_id)
           {
               printf("\n This id already exists....");
               system("cls");
               goto adb;
           }
        }
        add.bk.b_id=chk.bk.b_id;
        add.sr_no=i;
        printf("\n add book name: ");
        scanf("%s",add.bk.b_name);
        printf("\n add authors first name: ");
        scanf("%s",add.bk.a_fname);
        printf("\n add authors last name: ");
        scanf("%s",add.bk.a_lname);
        printf("\n add authors id(3 characters of authors last name):");
        scanf("%s",add.bk.a_id);
        while(fscanf(tr,"%d %s %f %f %f\n",&add.trs.sr_no,add.trs.item,&add.trs.with,&add.trs.cred,&add.trs.tot)!=EOF)
        {
            add.trs.sr_no++;
        }
        printf("\n add book price: ");
        scanf("%f",&add.trs.with);
        add.trs.tot=add.trs.tot-add.trs.with;
        fprintf(tr,"%d %s %f %f %f\n",add.trs.sr_no,"library",add.trs.with,add.trs.cred=0,add.trs.tot);
        fprintf(abook,"%d %d %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
        printf("\n book saved successfully");
        issbok=fopen("isslist.txt","a+");
        strcpy(add.status,"available");
        fprintf(issbok," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);

        fclose(issbok);
        fclose(tr);
        fclose(abook);
        break;
   /* case 2:
        abook=fopen("blist.txt","r+");
        issbok=fopen("isslist.txt","r+");
        printf("\n delete a book");
        printf("\n add book id: ");
        scanf("%d",&chk.bk.b_id);

        while(fscanf(abook,"%d %d %s %s %s %s \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id)!=EOF && fscanf(issbok,"%d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
        {
            if(chk.bk.b_id==add.bk.b_id)
            {
                printf("\n do you want to delete ?");
                scanf("%s",cho);
                if(strcmp(cho,"yes")==0)
                {
                    printf("\n book is deleted");
                }
                else
                {
                    fprintf(issbok," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
                    fprintf(abook,"%d %d %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
                }
            }
            else
            {
                fprintf(issbok," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
                fprintf(abook,"%d %d %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id);
            }
        }
        fclose(abook);
        fclose(issbok);
        break;*/
    case 4:
        edbook();
        break;
    case 5:
        close();
       }
       ed1:
       printf("\n enter 1 for edit book menu, 2 for main menu, 3 for exit ");
       scanf("%d",&che);
       switch(che)
       {
       case 1:
           edbook();
        break;
       case 2:
           menu();
        break;
       case 3:
           close();
        break;
        default:
            printf("\n try again....");
            goto ed1;
            break;
       }
}
void profile()
{
    int test=0,i;
    mem.f1=0;
    char ch;
    if(mem.f1==1)
        goto ad4;
    printf("\n add your id: ");
    scanf("%d",&chk.m_id);
    FILE *pf1;
    pf1=fopen("mlist.txt","r");
     while(fscanf(pf1,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {test=1;
        break;}
    }
    if(test==1)
    {
        ae1:
        printf("\n add password: ");
         for( i = 0;i < 10;i++)
         {
            ch = getch();
            if(ch == 13)
            break;
            chk.m_psd[i] = ch;
            ch ='*';
            printf("%c ", ch);
          }
         chk.m_psd[i] = '\0';
        if(strcmp(add.m_psd,chk.m_psd)==0)
        {
            mem.f1=1;
    ad4:
        printf("\n------------\n");
        printf("Your Profile");
        printf("\n------------");
        printf("\n Name=%s",add.name);
        printf("\n mobile no.=%.0f",add.mo);
        printf("\n birth date=%d/%d/%d",add.dob.day,add.dob.month,add.dob.year);
        printf("\n-------------------");
        }
        else
            goto ae1;
    }
    fclose(pf1);
}
void resbook()
{
    system("cls");
    int ch,che,test=0;
    printf("\n------------------");
    printf("\n Reissue the book ");
    printf("\n--------------------");
    FILE *res1,*res,*re0;
    re0=fopen("mlist.txt","r");
    res=fopen("isslist.txt","r");
    res1=fopen("isslist1.txt","w");

    printf("\n 1)return the book \n 2)reissue the book");
    printf("\n add your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    printf("\n add your id: ");
    scanf("%d",&chk.m_id);
    while(fscanf(re0,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {
            test=1;
        }
    }
    if(test==1)
    {
         printf("\n add book id: ");
         scanf("%d",&chk.bk.b_id);
         while(fscanf(res,"%d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
           {
            if(add.bk.b_id==chk.bk.b_id)
            {
                printf("\n book found...\n");
                printf("%d %d %s %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status);
              if(strcmp(add.status,"not")==0)
             {
                printf("\n book is issued");
                printf("\n do you want to return it ?");
                scanf("%s",cho);
                if(strcmp(cho,"yes")==0)
                {
                    printf("\n add date: ");
                    scanf("%d/%d/%d",&add.recieve.day,&add.recieve.month,&add.recieve.year);
                    int df=datediff(add.issue.day,add.issue.month,add.issue.year,add.recieve.day,add.recieve.month,add.recieve.year);
                    int pn=penalty(df);
                    if(df>14)
                    {
                         printf("\n you have penalty of %d for %d days",pn,df-14);
                         pnt:
                         printf("\n have you paid your penalty ?");
                         scanf("%s",cho1);
                         if(strcmp(cho1,"yes")==0)
                         {
                             printf("\n thank you for payment");
                         }
                         else if(strcmp(cho1,"no")==0)
                         {
                             printf("\n pay the penalty first..");
                             goto pnt;
                         }
                         else
                         {
                             printf("\n try again");
                             goto pnt;
                         }
                    }
                    else
                    {
                        printf("\n thank you...");
                    }
                    printf("\n Your book is returned");
                    add.m_id=chk.m_id;
                    fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"available",add.m_id=0,add.recieve.day,add.recieve.month,add.recieve.year);
                }
                else
                    fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
             else
             {
                printf("\n book is available....");
                fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"available",add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
            }
            else
               fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
        }
    }
     break;
    case 2:
        printf("\n reissue the book ");
        printf("\n-------------------");
        printf("\n\n add id: ");
        scanf("%d",&chk.m_id);

        while(fscanf(re0,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
         {
           if(chk.m_id==add.m_id)
            {
            test=1;
            }
         }
    if(test==1)
    {
         printf("\n add book id: ");
         scanf("%d",&chk.bk.b_id);
         while(fscanf(res,"%d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
           {
            if(add.bk.b_id==chk.bk.b_id)
            {
                printf("\n book found...\n");
                printf("%d %d %s %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status);
              if(strcmp(add.status,"not")==0)
             {
                printf("\n book is isuued");
                printf("\n do you want to re-issue it ?");
                scanf("%s",cho);
                if(strcmp(cho,"yes")==0)
                {
                    printf("\n add date: ");
                    scanf("%d/%d/%d",&add.reissue.day,&add.reissue.month,&add.reissue.year);
                    printf("\n Your book is reissued");
                    add.m_id=chk.m_id;
                    fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"not",add.m_id,add.reissue.day,add.reissue.month,add.reissue.year);
                }
                else
                    fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
             else
             {
                printf("\n book is available....");
                fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"available",add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
            }
            else
               fprintf(res1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
        }
    }
        break;
    }
    fclose(re0);
    fclose(res1);
    fclose(res);
    remove("isslist.txt");
    rename("isslist1.txt","isslist.txt");

    printf("\n add 1 for menu 2 for exit");
    scanf("%d",&che);
    switch(che)
    {
    case 1:
        resbook();
        break;
    case 2:
        close();
        break;
    }
}
void empl()
{
    FILE *trl,*epl;
   // add.sr_no=0;
    char a[10],ch;
    int test=0,t1=0,i,c=0,d=0,s=0,sc=0;
    epl=fopen("elist.txt","a+");
    ad0:
    system("cls");
    printf("\n EMPLOYEE SECTION");
    printf("\n------------------");
    printf("\n\n are you a registered employee ?");
    scanf("%s",cho);
    if(strcmp(cho,"yes")==0)
    {
        ad11:
    printf("\n enter your id: ");
    scanf("%d",&chk.emp.e_id);
    while(fscanf(epl,"%d %d %s %s %f %d %d/%d/%d %s",&add.sr_no,&add.emp.e_id,add.emp.name,add.emp.e_city,&add.emp.e_mo,&add.emp.age,&add.e_dob.day,&add.e_dob.month,&add.e_dob.year,add.emp.e_psd)!=EOF)
    {
        if(chk.emp.e_id==add.emp.e_id)
        {
            test=1;
        }
    }
    if(test==1)
    {
        printf("\n add password: ");
       // scanf("%s",chk.emp.e_psd);
        for( i = 0;i < 10;i++)
         {
            ch = getch();
            if(ch == 13)
            break;
            chk.emp.e_psd[i] = ch;
            ch = '*' ;
            printf("%c ", ch);
          }
         chk.emp.e_psd[i] = '\0';
        rewind(epl);
        while(fscanf(epl,"%d %d %s %s %f %d %d/%d/%d %s",&add.sr_no,&add.emp.e_id,add.emp.name,add.emp.e_city,&add.emp.e_mo,&add.emp.age,&add.e_dob.day,&add.e_dob.month,&add.e_dob.year,add.emp.e_psd)!=EOF)
         {
           if(strcmp(chk.emp.e_psd,add.emp.e_psd)==0)
           {
            t1=1;
           }
         }
         if(t1==1)
         {
           printf("\n welcome %s",add.emp.name);
         }
         else
         {
             printf("\n wrong password...");
             goto ad11;
         }
    }
    }
    else if(strcmp(cho,"no")==0)
    {
        ad3:
        printf("\n do you want to register ?");
        scanf("%s",cho1);
        if(strcmp(cho1,"yes")==0)
        {
            ad1:
            printf("\n add your id: ");
            scanf("%d",&chk.emp.e_id);
            while(fscanf(epl,"%d %d %s %s %f %d %d/%d/%d %s \n",&add.sr_no,&add.emp.e_id,add.emp.name,add.emp.e_city,&add.emp.e_mo,&add.emp.age,&add.e_dob.day,&add.e_dob.month,&add.e_dob.year,add.emp.e_psd)!=EOF)
              {
                  add.sr_no++;
                if(chk.emp.e_id==add.emp.e_id)
                 {
                   printf("\n id already exists...");
                   fordelay(100000000);
                   goto ad1;
                 }
              }
              add.emp.e_id=chk.emp.e_id;
               printf("\n add your name: ");
            scanf("%s",add.emp.name);
            printf("\n add your age: ");
            scanf("%d",&add.emp.age);
            printf("\n add your mobile no. : ");
            scanf("%f",&add.emp.e_mo);
            printf("\n add your date of birth: ");
            scanf("%d/%d/%d",&add.e_dob.day,&add.e_dob.month,&add.e_dob.year);
            printf("\n add your city: ");
            scanf("%s",add.emp.e_city);
            ad2:
            printf("\n create a password, password should be 8 characters long and password should contain small characters, capital characters, digits and special characters.");
            printf("\n create a strong password: ");
            scanf("%s",add.emp.e_psd);
            strcpy(a,add.emp.e_psd);
            for(int i=0;i<strlen(a);i++)
            {
                if(a[i]>='a'&& a[i]<='z')
                    s++;
                else if(a[i]>='A'&& a[i]<='Z')
                    c++;
                else if(a[i]>='0' && a[i]<='9')
                    d++;
                else if(a[i]=='#'||a[i]=='@'||a[i]=='&')
                    sc++;
            }
            if(s>0&&sc>0&&d>0&&c>0)
            {
                printf("\n password is strong..");
            }
            else{
                printf("\n password is poor");
                goto ad2;
            }
            printf("\n confirm password: ");
            scanf("%s",chk.emp.e_psd);
            if(strcmp(add.emp.e_psd,chk.emp.e_psd)==0)
            {
                printf("\n correct");
            }
            else
                goto ad2;
                printf("\n account created successfully");
            fprintf(epl,"%d %d %s %s %f %d %d/%d/%d %s \n",add.sr_no,add.emp.e_id,add.emp.name,add.emp.e_city,add.emp.e_mo,add.emp.age,add.e_dob.day,add.e_dob.month,add.e_dob.year,add.emp.e_psd);
        }
        else if(strcmp(cho1,"no")==0)
        {
            printf("\n thank you for visit...");
        }
        else
        {
            printf("\n try again...");
            goto ad3;
        }
    }
    else
    {
        printf("\n try again...");
        goto ad0;
    }
    fclose(epl);
 /*   printf("\n enter 1 for menu and 2 for exit: ");
    scanf("%d",&ch1);
    switch(ch1)
    {
    case 1:
        menu();
        break;
    case 2:
        close();
        break;
    }*/
}
void daan()
{
    system("cls");
    FILE *dan;
    d1:
    printf("\n welcome to donation section");
    printf("\n----------------------------");
    printf("\n\t The Central Library is a vital resource for our community, providing access to books, information, and educational resources for people of all ages.");
    printf("However, in order to continue providing these services, we rely on the generosity of donors like you.");
    printf("We are currently collecting donations to help support the Central Library's ongoing operations and future development.");
    printf(" Any amount, large or small, would be greatly appreciated and will go ");
    printf("towards purchasing new books, updating technology, and supporting library programs and events.");
    printf("\n-----------------------------");
    printf("\n do you want to contribute by donating?");
    scanf("%s",cho);
    if(strcmp(cho,"yes")==0)
    {
        dan=fopen("tlist.txt","a+");
        while(fscanf(dan,"%d %s %f %f %f\n",&add.trs.sr_no,&add.trs.item,&add.trs.with,&add.trs.cred,&add.trs.tot)!=EOF)
        {
            add.trs.sr_no++;
        }
        printf("\n enter the value of donation: ");
        scanf("%f",&add.trs.cred);
        printf("\n add your name: ");
        scanf("%s",add.trs.item);
        add.trs.tot=add.trs.tot+add.trs.cred;
        fprintf(dan,"%d %s %f %f %f\n",add.trs.sr_no,add.trs.item,add.trs.with=0,add.trs.cred,add.trs.tot);
        fclose(dan);
        printf("\n thank you for your contribution");
    }
    else if (strcmp(cho,"no")==0)
    {
        printf("\n thank you for visiting");
    }
    else
    {
        printf("\n try again");
        goto d1;
    }
}
void issbook()
{
    system("cls");
    char cb[10];
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

    printf("\n do you want to search for book ?");
    scanf("%s",cb);
    if(strcmp(cb,"yes")==0)
    {
        vibook();
    }
    while(fscanf(issid,"%d %s %f %d/%d/%d %d %s \n",&add.m_id,add.name,&add.mo,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.m_psd)!=EOF)
    {
        if(chk.m_id==add.m_id)
        {
            test=1;
        }
    }
            if(test==1)
            {
                abk:
            printf("\n add book id: ");
            scanf("%d",&chk.bk.b_id);
        while(fscanf(issb,"%d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
           {
               if(chk.m_id==add.m_id)
               {
                   is++;
               }
           }
           rewind(issb);

           while(fscanf(issb,"%d %d %s %s %s %s %s %d %d/%d/%d \n",&add.sr_no,&add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,&add.m_id,&add.issue.day,&add.issue.month,&add.issue.year)!=EOF)
           {
            if(add.bk.b_id==chk.bk.b_id)
            {
                printf("\n book found...\n");
                printf("%d %d %s %s %s %s %s \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status);
              if(strcmp(add.status,"available")==0)
             {
                printf("\n book is available...");
                printf("\n do you want to issue it ?");
                scanf("%s",cho);
                if(strcmp(cho,"yes")==0)
                {
                     if(is>=4)
                   {
                    printf("\n you can't issue a book....");
                    fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
                   }
                    else
                   {
                    printf("\n add date: ");
                    scanf("%d/%d/%d",&add.issue.day,&add.issue.month,&add.issue.year);
                    printf("\n Your book is issued");
                    add.m_id=chk.m_id;
                    fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"not",add.m_id,add.issue.day,add.issue.month,add.issue.year);
                    }
                }
                else
                    fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,add.status,add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
             else
             {
                printf("\n book is not available....");
                fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"not",add.m_id,add.issue.day,add.issue.month,add.issue.year);
             }
            }
            else
               fprintf(issb1," %d %d %s %s %s %s %s %d %d/%d/%d \n",add.sr_no,add.bk.b_id,add.bk.b_name,add.bk.a_fname,add.bk.a_lname,add.bk.a_id,"available",add.m_id,add.issue.day,add.issue.month,add.issue.year);
        }
            }
    else
    {
        printf("\n you are not a member");
    }
        fclose(issb);
        fclose(issb1);
        fclose(issid);
        remove("isslist.txt");
        rename("isslist1.txt","isslist.txt");

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
    profile();
    system("cls");
    int che,ch;
    dash();
    printf("\n\t\t Reader section");
    dash();
    printf("\n 1)view the book database \n 2)issue a book \n 3)reissue a book \n 4)give a donation \n 5)menu \n 6)exit");
    printf("\n add your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        system("cls");
        vibook();
        break;
    case 2:
        issbook();
        break;
    case 3:
        resbook();
        break;
    case 4:
        daan();
        break;
    case 5:
        menu();
        break;
    case 6:
        close();
    exit(0);
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
    empl();
    char pasl[10];
    int ch;
    dash();
    bbf:
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
   resbook();
   break;
case 7:
    edbook();
    break;
case 8:
    tres();
    break;
case 9:
    menu();
    break;
case 10:
    close();
    break;
default:
    printf("\n you have entered wrong no try again");
    goto bbf;
    break;
 }
}
void menu()
{
    int ch;
    bbf:
    system("cls");
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
    default:
        printf("\n you have entered wrong choice try again...");
        goto bbf;
    }
}
void main()
{
    bbg:
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
    else if(strcmp("no",cho)==0)
    {
        printf("\n thank you for visit");
        close();
    }
    else
    {
        printf("\n try again...");
        goto bbg;
    }
}
