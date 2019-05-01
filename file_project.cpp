#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
int main()
{
    ofstream employee("fileProject.txt");
    srand(time(0));
    char name[10];
    int random_char,ssn,date,month,year,salary;
    char c1,c2;
    int j=0,i=1;
    int n;
    cout<<"Enter the number of employee: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<10;j++)
        {
            random_char = rand()%27 + 65;
            name[j] = (char)random_char;
        }
        name[j] = '\0';
        date = rand()%32;if(date==0){date++;}
        month = rand()%13;if(month==0){month++;}
        year = rand()%100;
        year = year+1900;
        salary = rand() + 100000;
        ssn = rand();

        employee<<setw(8)<<setfill('0')<<i<<" "<<name<<" "
                <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                <<month<<"/"<<setw(4)<<setfill('0')<<year<<" "<<salary<<"    "<<setw(5)<<setfill('0')
                <<ssn<<endl;
    }

    int choice = 1 ;
    int choice_2 = 1;
    while(choice)
    {
        cout<<"                             ------------------------"<<endl;
        cout<<"                             |  Enter your choice:  |"<<endl;
        cout<<"                             |       0.Quit         |"<<endl;
        cout<<"                             |       1.Add          |"<<endl;
        cout<<"                             |       2.Edit         |"<<endl;
        cout<<"                             |       3.Delete       |"<<endl;
        cout<<"                             |       4.Search       |"<<endl;
        cout<<"                             |       5.Show all     |"<<endl;
        cout<<"                             ------------------------"<<endl<<endl;
        cout<<"                                    Choice: ";
        cin>>choice;
        cout<<endl;

        if(choice==1)
        {
            ofstream add("fileProject.txt",ios::app);
            for(j=0;j<10;j++)
            {
                random_char = rand()%26 + 65;
                name[j] = (char)random_char;
            }
            name[j] = '\0';
            date = rand()%32;if(date==0){date++;}
            month = rand()%13;if(month==0){month++;}
            year = rand()%100;
            year = year+1900;
            salary = rand() + 100000;
            ssn = rand();
            i++;
            add<<setw(8)<<setfill('0')<<i<<" "<<name<<" "
                    <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                    <<month<<"/"<<setw(4)<<setfill('0')<<year<<" "<<salary<<"    "<<setw(5)<<setfill('0')
                    <<ssn<<endl;
            cout<<endl<<"Informations are added to the file successfully!!!..."<<endl;
            system("pause");
            system("cls");
        }
        else if(choice==2)
        {
            fstream fin_edit("fileProject.txt");
            int id;
            cout<<"Enter id of the employee: ";
            cin>>id;
            id = id - 1;


            while(fin_edit>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
            {
                if(i==id)
                {
                    for(j=0;j<10;j++)
                    {
                        random_char = rand()%26 + 65;
                        name[j] = (char)random_char;
                    }
                    name[j] = '\0';
                    date = rand()%32;if(date==0){date++;}
                    month = rand()%13;if(month==0){month++;}
                    year = rand()%100;
                    year = year+1900;
                    salary = rand() + 100000;
                    ssn = rand();

                    fin_edit<<setw(8)<<setfill('0')<<i+1<<" "<<name<<" "
                    <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                    <<month<<"/"<<setw(4)<<setfill('0')<<year<<" "<<salary<<"    "<<setw(5)<<setfill('0')
                    <<ssn<<endl;
                    cout<<endl<<"Informations are edited to the file successfully!!!..."<<endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if(choice==3)
        {
            fstream fin_del("fileProject.txt");
            int id;
            cout<<"Enter id of the employee: ";
            cin>>id;
            id = id - 1;

            while(fin_del>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
            {
                if(i==id)
                {
                    for(j=0;j<10;j++)
                    {
                        name[j] = 'o';
                    }
                    name[j] = '\0';
                    date = 0;
                    month = 0;
                    year = 0;
                    salary = 0;
                    ssn = 0;

                    fin_del<<setw(8)<<setfill('0')<<i+1<<" "<<name<<" "
                    <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                    <<month<<"/"<<setw(4)<<setfill('0')<<year<<" "<<salary<<"    "<<setw(5)<<setfill('0')
                    <<ssn<<endl;
                    id=i=00000000;
                    cout<<endl<<"Informations are deleted from the file successfully!!!..."<<endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if(choice==4)
        {
            system("cls");
            while(choice_2)
            {
                cout<<"                             ------------------------"<<endl;
                cout<<"                             |     Search by:-      |"<<endl;
                cout<<"                             |      0.Go to main    |"<<endl;
                cout<<"                             |      1.Id            |"<<endl;
                cout<<"                             |      2.Name          |"<<endl;
                cout<<"                             |      3.Date of birth |"<<endl;
                cout<<"                             |      4.Salary        |"<<endl;
                cout<<"                             |      5.SSN           |"<<endl;
                cout<<"                             ------------------------"<<endl<<endl;
                cout<<"                                    Choice: ";
                cin>>choice_2;
                cout<<endl;
                if(choice_2==0)
                {
                    system("pause");
                    system("cls");
                }
                else if(choice_2==1)
                {
                    ifstream fin1("fileProject.txt",ios::in);
                    int id_ch;
                    cout<<"Enter id of the employee: ";
                    scanf("%d",&id_ch);
                    cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                      <<"SALARY"<<"\t   "<<" SSN"<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                    while(fin1>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                    {

                        if(i==id_ch)
                        {
                            name[10]='\0';

                            cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                <<ssn<<endl;
                        }
                    }
                    system("pause");
                    system("cls");
                }
                else if(choice_2==2)
                {
                    ifstream fin2("fileProject.txt",ios::in);
                    char enter_eater;
                    enter_eater = getchar();
                    int count = 0;
                    int count1 = 0;
                    char c;
                    char ch[20];
                    cout<<"Enter a name to search"<<endl;
                    while((c = getchar())!='\n')
                    {
                        ch[count]=c;
                        count++;
                    };
                    ch[count]='\0';

                     cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                      <<"SALARY"<<"\t   "<<" SSN"<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                    while(fin2>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                    {

                        for(int j = 0;j<count;j++)
                        {
                            if(ch[j]==name[j])
                            {
                                 count1++;
                            }
                        }
                        if(count==count1)
                        {

                            cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                <<ssn<<endl;
                        }
                        count1=0;
                    }
                    system("pause");
                    system("cls");
                }
                else if(choice_2 == 3)
                {
                    ifstream fin3("fileProject.txt",ios::in);
                    system("cls");
                    int choice3;
                    cout<<"                             ------------------------"<<endl;
                    cout<<"                             |     Search by:-      |"<<endl;
                    cout<<"                             |      0.Go to search  |"<<endl;
                    cout<<"                             |      1.Date          |"<<endl;
                    cout<<"                             |      2.Month         |"<<endl;
                    cout<<"                             |      3.Year          |"<<endl;
                    cout<<"                             |      4.Full Date     |"<<endl;
                    cout<<"                             ------------------------"<<endl<<endl;
                    cout<<"                                    Choice: ";
                    cin>>choice3;
                    cout<<endl;
                    char enter_eater;
                    enter_eater = getchar();
                    enter_eater = ' ';
                    int count = 0;
                    char c;
                    int date_ch, month_ch, year_ch;
                    switch(choice3)
                    {
                        case 0:
                            break;
                        case 1:
                            char  date_in[10];
                            cout<<"Enter a date: ";
                            while((c=getchar())!='\n')
                            {
                                date_in[count] = c;
                                count++;
                            }
                            date_ch = (date_in[0]-48)*10 + (date_in[1]-48);
                            int per_date;
                            cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                              <<"SALARY"<<"\t   "<<" SSN"<<endl;
                                    cout<<"-----------------------------------------------------------------"<<endl;
                            while(fin3>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                            {
                                per_date=date_ch;

                                if(date==per_date)
                                {
                                    name[10]='\0';
                                    cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                        <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                        <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                        <<ssn<<endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            char  month_in[10];
                            cout<<"Enter a month: ";
                            while((c=getchar())!='\n')
                            {
                                month_in[count] = c;
                                count++;
                            }
                            month_ch = (month_in[0]-48)*10 + (month_in[1]-48);
                            int per_month;
                            cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                              <<"SALARY"<<"\t   "<<" SSN"<<endl;
                                    cout<<"-----------------------------------------------------------------"<<endl;
                            while(fin3>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                            {
                                per_month=month_ch;

                                if(month==per_month)
                                {
                                    name[10]='\0';

                                    cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                        <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                        <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                        <<ssn<<endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            char  year_in[10];
                            cout<<"Enter a year: ";
                            while((c=getchar())!='\n')
                            {
                                year_in[count] = c;
                                count++;
                            }
                            year_ch = (year_in[0]-48)*1000 + (year_in[1]-48)*100+
                                      (year_in[2]-48)*10+(year_in[3]-48);
                            int per_year;
                            cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                              <<"SALARY"<<"\t   "<<" SSN"<<endl;
                                    cout<<"-----------------------------------------------------------------"<<endl;
                            while(fin3>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                            {
                                per_year=year_ch;

                                if(year==per_year)
                                {
                                    name[10]='\0';

                                    cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                    <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                    <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                    <<ssn<<endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            char  whole_in[12];
                            cout<<"Enter full date: ";
                            while((c=getchar())!='\n')
                            {
                                whole_in[count] = c;
                                count++;
                            }
                            date_ch = (whole_in[0]-48)*10 + (whole_in[1]-48);
                            month_ch = (whole_in[3]-48)*10 + (whole_in[4]-48);
                            year_ch = (whole_in[6]-48)*1000 + (whole_in[7]-48)*100+
                                      (whole_in[8]-48)*10+(whole_in[9]-48);

                            cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                              <<"SALARY"<<"\t   "<<" SSN"<<endl;
                                    cout<<"-----------------------------------------------------------------"<<endl;
                            while(fin3>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                            {
                                per_date=date_ch;
                                per_month=month_ch;
                                per_year=year_ch;

                                if(date==per_date && month==per_month && year==per_year)
                                {
                                    name[10]='\0';

                                    cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                        <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                        <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                        <<ssn<<endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;
                    }
                }
                else if(choice_2==4)
                {
                    ifstream fin4("fileProject.txt",ios::in);
                    int sal_srh;
                    cout<<"Enter a salary: ";
                    scanf("%d",&sal_srh);
                    cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                      <<"SALARY"<<"\t   "<<" SSN"<<endl;
                            cout<<"-----------------------------------------------------------------"<<endl;
                    while(fin4>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                    {

                        if(salary==sal_srh)
                        {
                            name[10]='\0';

                            cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                <<ssn<<endl;
                        }
                    }
                    system("pause");
                    system("cls");
                }
                else if(choice_2==5)
                {
                    ifstream fin5("fileProject.txt",ios::in);
                    int ssn_srh;
                    cout<<"Enter the Social Sequrity Number: "<<endl;
                    scanf("%d",&ssn_srh);
                    while(fin5>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
                    {
                        if(ssn==ssn_srh)
                        {
                            name[10]='\0';
                            cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                                      <<"SALARY"<<"\t   "<<" SSN"<<endl;
                            cout<<"-----------------------------------------------------------------"<<endl;
                            cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                                <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                                <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                                <<ssn<<endl;
                        }
                    }
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout<<"Wrong key!!!"<<endl;
                }
            }
        }
        else if(choice==5)
        {
            ifstream fin6("fileProject.txt",ios::in);


            cout<<endl<<"   ID\t"<<"\t"<<"EMPLOYEE NAME"<<"\t"<<"BIRTH_OF_DATE"<<"\t"
                      <<"SALARY"<<"\t   "<<" SSN"<<endl;
            cout<<"-----------------------------------------------------------------"<<endl;
            while(fin6>>i>>name>>date>>c1>>month>>c2>>year>>salary>>ssn)
            {
                name[10]='\0';
                cout<<setw(8)<<setfill('0')<<i<<"\t"<<name<<"\t"
                    <<setw(2)<<setfill('0')<<date<<"/"<<setw(2)<<setfill('0')
                    <<month<<"/"<<setw(4)<<setfill('0')<<year<<"\t"<<salary<<"\t   "<<setw(5)<<setfill('0')
                    <<ssn<<endl;
            }
            cout<<endl;
            system("pause");
            system("cls");
        }
        else
        {
            cout<<"Wrong key!!!"<<endl;
            cout<<"Try again."<<endl<<endl;
            system("pause");
            system("cls");
        }
    }
}

