#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Patient
{
    char name[30];
    char disease[30];
    int cabin,phone,age;
} 

patients[100];
int n,i,endIndex=0,g,num;
void read();
void add();
void view();
void search();
void edit();
void del();
void write();

int main()
{
    read();
    int c = 0;
    printf("========== Patient Recording System ===========\n");

    while(c!=6)
    {
        printf("\n**Enter your choice**\n\n1. Add Patient\n2. View Patient Record\n3. Search Patient\n4. Update Patient\n5. Delete Patient\n6. Exit\n\nOption=");
        scanf("%d",&c); //choice for option
        fflush(stdin); //making it clear
        if(c==1) //add
        {
            system("clear");
            add();
        }
        else if(c==2) //view
        {
            system("clear");
            view();
        }
        else if(c==3) //search
        {
            system("clear");
            search();
        }
        else if(c==4) //edit
        {
            system("clear");
            edit();
        }
        else if(c==5) //delete
        {
            system("clear");
            del();
        }
        else if(c==6)
        {
            write();
            return 0;
        }
        else
        {
            system("clear");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}

void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num); //how many inputs
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);
    endIndex=n+num;

    for(i=num; i<endIndex; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name = ");
        fgets(patients[i].name, sizeof(patients[i].name), stdin);
        patients[i].name[strcspn(patients[i].name, "\n")] = '\0';
        fflush(stdin);
        printf("Enter disease = ");
        fgets(patients[i].disease, sizeof(patients[i].disease), stdin);
        patients[i].disease[strcspn(patients[i].disease, "\n")] = '\0';
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d",&patients[i].age);
        fflush(stdin);
        printf("Enter cabin no = ");
        scanf("%d",&patients[i].cabin);
        fflush(stdin);
        printf("Enter phone number = ");
        scanf("%d",&patients[i].phone);
        fflush(stdin);
        printf("\n");
        num++;
    }
}

void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("Serial Number=%d\n",i);
        printf("Name = ");
        puts(patients[i].name);
        printf("Disease = ");
        puts(patients[i].disease);
        printf("Cabin no = %d\nPhone number = 0%d\nAge=%d",patients[i].cabin,patients[i].phone,patients[i].age);
        printf("\n\n");
    }
}

void edit()
{
    int q,p;

    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option=");
    scanf("%d",&q); //option

    if(q<=5)
    {
        printf("Enter the serial no of that patient= (0 - %d)=",num-1);
        scanf("%d",&p); //serial number
        if(p >= 0 && p < num)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new name=");
                fgets(patients[p].name, sizeof(patients[p].name), stdin);
                patients[p].name[strcspn(patients[p].name, "\n")] = '\0';

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Disease=");
                fgets(patients[p].disease, sizeof(patients[p].disease), stdin);
                patients[p].disease[strcspn(patients[p].disease, "\n")] = '\0';
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d",&patients[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new Cabin no=");
                scanf("%d",&patients[p].cabin);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%d",&patients[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}

void search()
{
    int s,h;
    char u[100];

    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\nOption = ");
    scanf("%d",&h);

    if(h==1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("Serial Number=%d\n",s);
            printf("Name = ");
            puts(patients[s].name);
            printf("Disease = ");
            puts(patients[s].disease);
            printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",patients[s].cabin,patients[s].phone,patients[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2) //problem is here.........
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name=");
        fgets(u, sizeof(u), stdin);
        u[strcspn(u, "\n")] = '\0';
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,patients[g].name)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(patients[g].name);
                printf("Disease = ");
                puts(patients[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",patients[g].cabin,patients[g].phone,patients[g].age);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");
    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease = ");
        fgets(u, sizeof(u), stdin);
        u[strcspn(u, "\n")] = '\0';
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,patients[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(patients[g].name);
                printf("Disease = ");
                puts(patients[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",patients[g].cabin,patients[g].phone,patients[g].age);
                printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("\nNot Found\n");
    }
    else if(h==4)
    {
        int f=1;
        printf("Enter Cabin number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==patients[g].cabin)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(patients[g].name);
                printf("Disease = ");
                puts(patients[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",patients[g].cabin,patients[g].phone,patients[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");
    }
    else if(h==5)
    {
        int f=1;
        printf("Enter Phone number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==patients[g].phone)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(patients[g].name);
                printf("Disease = ");
                puts(patients[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",patients[g].cabin,patients[g].phone,patients[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==6)
    {
        int f=1;
        printf("Enter Age = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==patients[g].age)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(patients[g].name);
                printf("Disease = ");
                puts(patients[g].disease);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",patients[g].cabin,patients[g].phone,patients[g].age);
                printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}

void del()
{
    int f,h;

    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&f);

    if(f >= 0 && f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nOption = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(patients[f].name,patients[f+1].name);
                strcpy(patients[f].disease,patients[f+1].disease);
                patients[f].age=patients[f+1].age;
                patients[f].cabin=patients[f+1].cabin;
                patients[f].phone=patients[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(patients[f].name,"Cleared");

        }
        else if(h==3)
        {
            strcpy(patients[f].disease,"Cleared");
        }
        else if(h==4)
        {
            patients[f].age=0;
        }
        else if(h==5)
        {
            patients[f].cabin=0;
        }
        else if(h==6)
        {
            patients[f].phone=0;
        }
    }
    else
        printf("\n\nInvalid Serial number\n");
}

void read()
{
    FILE *fp = fopen("patient.txt","r");

    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return;
    }

    num = fread(patients, sizeof(struct Patient),100, fp);
    fclose(fp);
}

void write()
{
    FILE *fp = fopen("patient.txt","w");

    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(patients, sizeof(struct Patient),num, fp);

    fclose(fp);
}