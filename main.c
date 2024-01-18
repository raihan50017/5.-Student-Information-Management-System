#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
char dec,choice,pc;

int ID;
struct student
{
    char name[30];
    int id;
    int reg;
    int mobile;
    char blood[30];
} st;

FILE *std,*temp,*restore,*result,*result_tmp;


showrecord()
{
    system("cls");
    int i,m;
    char n[30],b[30];
    std=fopen("stddata.txt","r");
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&i,n,&m,b)!=EOF)
    {
        printf("%d %s 0%d %s\n",i,n,m,b);
    }
    fclose(std);
    printf("Want to go to Main Menu? (Y/N)\nExit(E)\n");
    fflush(stdin);
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        main();
    else if(pc=='E' || pc=='N')
        exit(0);



}
restore_data()
{
    int i,m;
    char n[30],b[30];
    restore=fopen("restoredata.txt","r");
    std=fopen("stddata.txt","w");
    while(fscanf(restore,"%d\t%s\t%d\t%s\n",&i,n,&m,b)!=EOF)
    {
        fprintf(std,"%d\t%s\t%d\t%s\n",i,n,m,b);
    }
    fclose(std);
    fclose(restore);
    printf("Successfully restored\nEntering Main Menu in 3 Seconds\n");
    Sleep(3);
    mainmenu();

}
search()
{
    int x;
    char tmp[20];
    system("cls");
    system("Color C7");
    int i,t,a;
    char n[30],b[30],d;
    FILE *std;
    std=fopen("stddata.txt","r");
    printf("Enter your id\n");
    scanf("%s",&tmp);


    i=atoi(tmp);




    while(fscanf(std,"%d\t%s\t%d\t%s\n",&t,n,&a,b)!=EOF)
    {
        if(t==i)
            printf("Id = %d Name = %s Mobile = 0%d Blood = %s",t,n,a,b);

    }
    fclose(std);

    printf("Want to search again? (Y/N)\nExit(E)\n");
    fflush(stdin);
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        search();
    else if(pc=='E')
        exit(0);
    else
        mainmenu();
}
search_by_blood()
{
    system("cls");
    system("Color C7");
    char bl[30],bo[30],n[50];
    int a,b;
    printf("Enter blood group (first letter of blood group should be in capital letter)\n");
    fflush(stdin);
    scanf("%s",&bl);
    std=fopen("stddata.txt","r");
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&a,n,&b,bo)!=EOF)
    {
        if(strcmp(bl, bo)==0)
        {
            printf("%d\t%s\t0%d\t%s\n",a,n,b,bo);
        }


    }
    fclose(std);
    printf("\nWant to search again? (Y/N)\nExit(E)\n");
    fflush(stdin);
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        search_by_blood();
    else if(pc=='E')
        exit(0);
    else
        mainmenu();
}
editrecord()
{
    system("cls");
    int i,t,l,k,a;
    char n[20],b[20];
    std=fopen("stddata.txt","r");
    temp=fopen("temp.txt","w");
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&t,n,&a,b)!=EOF)
    {
        printf("%d\t%s\t%d\t%s\n",t,n,a,b);
    }
    printf("Enter id to be edited\n");
    scanf("%d",&l);

    fclose(std);
    std=fopen("stddata.txt","r");
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&t,n,&a,b)!=EOF)
    {



        printf("%d\t%s\t%d\t%s\n",t,n,a,b);
        if(l==t)
        {
            continue;
        }

        fprintf(temp,"%d\t%s\t%d\t%s\n",t,n,a,b);
    }

    int id,mob;
    char name[50],bld[50];
    fclose(std);
    fclose(temp);
    temp=fopen("temp.txt","a+");
    printf("Enter id, Name, Mobile, Blood Group\n");
    fflush(stdin);
    scanf("%d %s %d %s",&id,&name,&mob,&bld);
    fprintf(temp,"%d\t%s\t%d\t%s\n",id,name,mob,bld);
    fclose(temp);
    std=fopen("stddata.txt","w");
    temp=fopen("temp.txt","r");
    while(fscanf(temp,"%d\t%s\t%d\t%s\n",&id,name,&mob,bld)!=EOF)
    {

        fprintf(std,"%d\t%s\t%d\t%s\n",id,name,mob,bld);
    }
    fclose(std);
    fclose(temp);
    printf("Showing edited record\n");
    std=fopen("stddata.txt","r");
    while(fscanf(std,"%d\t%s\%d\%s\n",&id,name,&mob,bld)!=EOF)
    {
        printf("%d\t%s\%d\%s\n",id,name,mob,bld);
    }
    fclose(std);

    printf("Want to edit again? (Y/N)\nExit(E)\n");
    fflush(stdin);
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        editrecord();
    else if(pc=='E')
        exit(0);
    else
        mainmenu();

}

addrecord()
{
    char pc;

    system("cls");
    system("Color F7");
    printf("Enter name\n");
    scanf("%s",&st.name);
    std=fopen("stddata.txt","a+");
    restore=fopen("restoredata.txt","a+");
    printf("Enter blood group\n");
    scanf("%s",&st.blood);
    printf("Enter id\n");
    scanf("%d",&st.id);
    printf("Enter mobile number\n");
    fflush(stdin);
    scanf("%d",&st.mobile);
    fprintf(std,"%d\t%s\t%d\t%s\n",st.id,st.name,st.mobile,st.blood);
    fprintf(restore,"%d\t%s\t%d\t%s\n",st.id,st.name,st.mobile,st.blood);
    //fflush(stdin);
    printf("Record added succesfully! Want to add more? (Y/N/M)\n");

    fflush(stdin);
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        addrecord();
    else if(pc=='N')
        exit(0);
        else if(pc=='M')
            main();
}
deleterecord()
{
    system("cls");
    int id,tmpid,tmpm,id2,m2;
    char tmpn[30],tmpb[30],n2[30],b2[30];
    FILE *del;
    std=fopen("stddata.txt","r");
    printf("Loading Data\n");
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&tmpid,tmpn,&tmpm,tmpb)!=EOF)
    {

        printf("%d\t%s\t%d\t%s\n",tmpid,tmpn,tmpm,tmpb);
    }

    fclose(std);
    del=fopen("del.txt","w");
    std=fopen("stddata.txt","r");
    printf("Enter id.....\n");
    scanf("%d",&id);
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&tmpid,tmpn,&tmpm,tmpb)!=EOF)
    {

        if(tmpid==id)
        {
            printf("%d\t%s\t%d\t%s\n",tmpid,tmpn,tmpm,tmpb);
            printf("Record deleted\n");
            continue;
        }
        fprintf(del,"%d\t\%s\t%d\t%s\n",tmpid,tmpn,tmpm,tmpb);
    }
    fclose(del);
    fclose(std);
    del=fopen("del.txt","r");
    std=fopen("stddata.txt","w");
    while(fscanf(del,"%d\t%s\t%d\t%s\n",&tmpid,tmpn,&tmpm,tmpb)!=EOF)
    {

        fprintf(std,"%d\t\%s\t%d\t%s\n",tmpid,tmpn,tmpm,tmpb);
    }
    fclose(std);
    fclose(del);
    printf("Want to delete again? (Y/M/E)\n");
    char pc;
    fflush(stdin);
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        deleterecord();
    else if(pc=='M')
        main();
}

Result()
{
    char rc;
    system("cls");
    printf("(1)Add Result\n");
    printf("(2)Show Result\n");
    printf("(3)Edit Result\n");
    scanf("%c",&rc);
    if(rc<=48 || rc>51)
    {
        printf("Invalid Choice\n");
        Sleep(2000);
        Result();
    }
    switch(rc)
    {
    case '1':
        writeinfo();
        break;
    case '2':
        readinfo();
        break;
    case '3':
        edit_result();
        break;
    default:
        break;
    }

}
writeinfo()
{
    system("cls");
    float r;
    int i,m;
    char n[30],b[32];
    std=fopen("stddata.txt","r");
    result=fopen("result.txt","a");
    while(fscanf(std,"%d\t%s\t%d\t%s\n",&i,n,&m,b)!=EOF)
    {
        printf("%d\t%s\t%d\t%s ",i,n,m,b);
        fflush(stdin);
        scanf("%f",&r);
        fprintf(result,"%d\t%f\n",i,r);
    }

    printf("Record added succesfully! Want to add more? (Y/N)\n");

    fflush(stdin);
    if(getche()=='Y')
    {
        Result();
    }

    else
    {
        fclose(std);
        fclose(result);
        mainmenu();
    }

}
readinfo()
{
    int i;
    float rc;
    result=fopen("result.txt","r");
    while(fscanf(result,"%d\t%f\n",&i,&rc)!=EOF)
    {
        printf("%d\t%f\n",i,rc);
    }
    printf("Back to Main Menu /Result(N/Y)\n");
    fflush(stdin);
    if(getche()=='Y')
    {
        Result();
    }

    else
    {
        fclose(result);
        mainmenu();
    }
}
edit_result()
{
    system("cls");
    int i,id;
    float rc;
    result=fopen("result.txt","r");
    result_tmp=fopen("tmpr.txt","w");
    while(fscanf(result,"%d\t%f\n",&i,&rc)!=EOF)
    {
        printf("%d\t%f\n",i,rc);
    }
    printf("Enter Id whose result to be edited\n");
    scanf("%d",&id);
    fclose(result);
    result=fopen("result.txt","r");
    while(fscanf(result,"%d\t%f\n",&i,&rc)!=EOF)
    {
        if(id==i)
            continue;
        fprintf(result_tmp,"%d\t%f\n",i,rc);
    }
    fclose(result);
    fclose(result_tmp);
    result_tmp=fopen("tmpr.txt","a");
    printf("Enter result\n");
    float nwrc;
    fflush(stdin);
    scanf("%f",&nwrc);
    fprintf(result_tmp,"%d\t\%f\n",id,nwrc);
    fclose(result_tmp);
    printf("Edited Successfully\n");
    result=fopen("result.txt","w");
    result_tmp=fopen("tmpr.txt","r");
    while(fscanf(result_tmp,"%d\t%f\n",&i,&rc)!=EOF)
    {

        fprintf(result,"%d\t%f\n",i,rc);
    }
    fclose(result);
    fclose(result_tmp);
    printf("Want to continue?(Y/N/E)\n");
    scanf("%c",&pc);
    pc=toupper(pc);
    if(pc=='Y')
        deleterecord();
    else if(pc=='E' || pc=='N')
        exit(0);
}
main()
{

    mainmenu();

}
mainmenu()
{
    char choice;


    system("cls");
    system("color 76");
    printf(" ----------------------------------------------------------|\n");
    printf("|                     Welcome to                           |\n");
    printf("|               Student Information                        |\n");
    printf(" ----------------------------------------------------------|\n");
    printf("Please select your option\n");

    //gotoxy(5,20);
    printf("1.Add Record\n");
    //gotoxy(5,20);
    printf("2.Delete Record\n");
    //gotoxy(5,20);
    printf("3.Show All Records\n");
    //gotoxy(5,20);
    printf("4.Exit\n");
    printf("5.Edit Record\n");
    printf("6.Search by Id\n");
    printf("7.Search by blood\n");
    printf("8.Restore previous data\n");
    printf("9.Result\n");

    fflush(stdin);
    scanf("%c",&choice);
    if(choice<=48 || choice>57)
    {
        printf("Invalid Choice\n");
        Sleep(2000);
        main();
    }
    switch(choice)
    {
    case '1':
        addrecord();
        break;
    case '2':
        deleterecord();
        break;
    case '3':
        showrecord();
        break;
    case '4':
        exit(0);
        break;

    case '5':
        editrecord();
        break;
    case '6':
        search();
        break;
    case '7':
        search_by_blood();
        break;
    case '8':
        restore_data();
        break;
    case '9':
        Result();
        break;
    default:
        printf("Invalid Choice\n");
        break;



    }

}
