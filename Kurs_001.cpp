#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <ctype.h>

void createfile();  //�����i� ��������� �����. ����������� � ������� ������� "main()".
void addinfile();   //�����i� ��������� �����. ����������� � ������� ������� "main()".
void viewfile();    //�����i� ��������� �����i� � ����. ����������� � ������� ������� "main()".
void staj();        //�����i� ������ �������i� �� ������ ������.������� ������ "table(...)". 
                    //����������� � ������� ������� "main()".
void change();      //�����i� ��i�� ����� �������� �� ������� � �����i. ������� �����i� "createstruct()". 
                    //����������� � ������� ������� "main()".
void createstruct();//�����i� ������ ����� ����� �� �i��i ����������� ����������� �����i�� "change()". 
                    //������ � �����i� "change()". 
void deldata();     //����i� ��������� ������ �������.����������� � ������� ������� "main()".
void viewfak();     //����i� ��������� �����i� �� ������ �����������. ������� ������ "table(...)".
                    //����������� � ������� ������� "main()".
void viewspec();    //����i� ��������� �����i� �� ������ ����i����i���. ������� ������ "table(...)".
                    //����������� � ������� ������� "main()".
void viewcourse();  //����i� ��������� �����i� �� ������ ������.������� ������ "table(...)".
                    //����������� � ������� ������� "main()".
void dovidnyk();    // ����i� ��������� ���i�����. ����������� � ������� ������� "main()".
void table(double, int, int, int, int, int b);// ����i� ��� ������ 2 ������i.
                                             //����������� ���������: "staj()", "viewfak()", "viewspec()", "viewcourse()"

	
using namespace std;

	struct student	
	{	
		char fakultet[10]; //����� ����������;
		char nomer[8];     //����� ������� ������;
		char spec[5];      //����� ������������;
		char course[3];    //����� �����;
		char group[3];     // ����� �����;
		char name[32];     // ϲ�
		char staj[3];      //���� ������
	   
	};
student st;


//������� �����i� ��������. �i������� � ���i ���� �������� ��������. 
int main()
{setlocale(LC_CTYPE, "ukr");

  int choise; //��i�� �� ��������������� ��� ������ � ����.

do
{
	system("cls");
	cout <<"|=====================================================|\n";
	cout <<"�---------------------������� ����:-------------------�\n";
	cout <<"�------- 1  - �������� ���� � ������       -----------�\n";
	cout <<"�------- 2  - ����������� ���� � ������    -----------�\n";
	cout <<"�------- 3  - ������ ���i                  -----------�\n";
	cout <<"�------- 4  - �������� �������i� (������i�)-----------�\n"; 
	cout <<"�------- 5  - ��i���� ���i ��������        -----------�\n";
	cout <<"�------- 6  - �������� ������ ��������     -----------�\n";
	cout <<"�------- 7  - �������� �������i� �� ������������------�\n";
	cout <<"�------- 8  - �������� �������i� �� ����i����������---�\n";
	cout <<"�------- 9  - �������� �������i� �� ������ -----------�\n";
	cout <<"�------- 10 - �������� ��������           -----------�\n";
	cout <<"�------- 0  - ���i�                        -----------�\n";
	cout <<"|=====================================================-\n";
	cin >> choise;
	switch(choise)
	{

	case 0:
			{
				break;
			}
	case 1:
			 {
				 createfile(); //������ �����i�;
				 break;
			 }
	case 2:
			 {
				 viewfile();//������ �����i�;
				 _getch();
				 break;
			 }
	case 3:
			 {
				 addinfile();//������ �����i�;
				 break;
			 }
	case 4:
			{
				staj();//������ �����i�;
				break;
			}
	case 5:
			{
				change();//������ �����i�;
				break;
			}
	case 6:
			{
				deldata();//������ �����i�;
				break;
			}
	case 7:
			{
				viewfak();//������ �����i�;
				break;
			}
	case 8:
			{
				viewspec();//������ �����i�;
				break;
			}
	case 9:
			{
				viewcourse();//������ �����i�;
				break;
			}dovidnyk();
	case 10:
			{
				dovidnyk();//������ �����i�;
				break;
			}
	default:
			{
				cerr << "�������. ���i ������i ���i���";
				break;
			}

	}

}
while (choise != 0);
	return 0;
}

//�����i� ��������� �����.
void createfile()
{setlocale(LC_CTYPE, "ukr");
system("cls");
int len = 0; //��i��� ��� ������ �������� ������� ����i�.
int i = 0; // ��i��� ��� ����i�.
int error; // ��i��� �� ��������������� ��� �����i��� ������ �������� �� �������.

ofstream dataWriting("data.txt", ios::out | ios::binary);
	if(!dataWriting)
		cerr << "��������� �i������ ����\n";

do
{
	error = 0;

	cout << "����i�� ���������(���������: FISiT)\n";
	cin >> st.fakultet;
	len = strlen(st.fakultet);
	for (i = 0;i < len;i++)
		if(!isalpha(st.fakultet[i]))
		{
			error = 1;
			break;
		}
	
	if (error == 1)
		cerr << "�������. ���i���� ��� �����\n";

	
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����� ���i�����':(���������: 116223)\n";
	cin >> st.nomer;
	len = strlen(st.nomer);
	if (len != 6 )
	{
		cerr << "�������. ����� ���i����� �� �i����� 6 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.nomer[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����i����i���':(���������: 6101)\n";
	cin >> st.spec;
	len = strlen(st.spec);
	if (len != 4)
	{
		cerr << "�������. ����i����i��� �� �i����� 4 �����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.spec[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����:(���������: 2)\n";
	cin >> st.course;
	len = strlen(st.course);
	if (len > 1)
	{
		cerr << "�������. ���� �� ���� �i����� �i���� 1 �����n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.course[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� �����:(���������: 1)\n";
	cin >> st.group;
	len = strlen(st.group);
	if (len > 2)
	{
		cerr << "�������. ����� �� ���� �i����� �i���� 2 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.group[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{
	len = 0;
	error = 0;
	cout << "����i�� ���� \n";
	cin >> st.staj;
	len = strlen(st.staj);
	if (len > 2)
	{
		cerr << "�������. ����� �� ���� �i����� �i���� 2 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.staj[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error==1);

do
{
	len = 0;
	error = 0;
	cout << "����i�� ��i����� �� i�i�i���\n";
	cin.ignore(1);
	cin.getline(st.name, 20, '\n');
	len = strlen(st.name);
	for(i = 0;i < len;i++)
	if(!isalpha(st.name[i]) && !isspace(st.name[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);
dataWriting.write((char *) &st, sizeof(student));
dataWriting.close();
system("cls");
}

//�����i� ��������� �����.
void viewfile()
{setlocale(LC_CTYPE, "ukr");	
student st1;

system("cls");
ifstream dataReading("data.txt", ios::in | ios::binary);
if (!dataReading)
		{
			cerr << "�������. ��������� �i������ ����\n";
			_getch();
			exit(1);
		}
dataReading.read((char *) &st1, sizeof(student));
int i=0; // ��i��� ��� ���������� ������� �����i� � ����i.

  cout <<"|===|========|========|=====|===|===|==============|========|\n";
  cout <<"�   �        �        |     �   �   �              �        �\n";
  cout <<"� # �Fakultet�N_zalik |Spec.�Crs�Grp�     Name     �  Staj  �\n";
  cout <<"�   �        �        |     �   �   �              �        �\n"; 
while(dataReading && !dataReading.eof())
	{	
		cout << "|===|========|========|=====|===|===|==============|========|\n";
		cout << "�";
		cout << setiosflags(ios::left) << setw(3) << ++i;
		cout << "�";
		cout << setiosflags(ios::left) << setw(8) << st1.fakultet;
		cout << "�";
		cout << setiosflags(ios::left) << setw(8) << st1.nomer;
		cout << "�";
		cout << setiosflags(ios::left) << setw(5) << st1.spec;
		cout << "�";
		cout << setiosflags(ios::left) << setw(3) << st1.course;
		cout << "�";
		cout << setiosflags(ios::left) << setw(3) << st1.group;
		cout << "�";
		cout << setiosflags(ios::left) << setw(14) << st1.name;
		cout << "�";
		cout << setiosflags(ios::left) << setw(8) << st1.staj;
		cout << "�\n";
		dataReading.read((char *) &st1, sizeof(student));
	}
	cout <<"|===|========|========|=====|===|===|==============|========|";
dataReading.close();
}

//�����i� ��������� �����i� � ����.
void addinfile()
{setlocale(LC_CTYPE, "ukr");
system("cls");
int len = 0; //��i��� ��� ������ �������� ������� ����i�.
int i = 0; // ��i��� ��� ����i�.
int error; // ��i��� �� ��������������� ��� �����i��� ������ �������� �� �������.
ofstream dataAdding ("data.txt", ios::app | ios::binary);
	if(!dataAdding)
		cerr << "��������� �i������ ����\n";
do
{
	error = 0;
	cout << "����i�� ���������(���������: FISiT)\n";
	cin >> st.fakultet;
	len = strlen(st.fakultet);
	for (i = 0;i < len;i++)
		if(!isalpha(st.fakultet[i]))
		{
			error = 1;
			break;
		}
	if (error == 1)
		cerr << "�������. ����������� ��� �����\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����� ���i�����':(���������: 116223)\n";
	cin >> st.nomer;
	len = strlen(st.nomer);
	if (len != 6)
	{
		cerr << "�������. ����� ���i����� �� �i����� 6 �����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.nomer[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);


do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����i����i���':(���������: 6101)\n";
	cin >> st.spec;
	len = strlen(st.spec);
	if (len != 4)
	{
		cerr << "�������. ����i����i��� �� �i����� 4 �����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.spec[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����:(���������: 2)\n";
	cin >> st.course;
	len = strlen(st.course);
	if (len > 1)
	{
		cerr << "�������. ���� �� ���� �i����� �i���� 1 �����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.course[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� �����:(���������: 1)\n";
	cin >> st.group;
	len = strlen(st.group);
	if (len > 2)
	{
		cerr << "�������. ����� �� ���� �i����� �i���� 2 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.group[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{
	len = 0;
	error = 0;
	cout << "����i�� ���� \n";
	cin >> st.staj;
	len = strlen(st.staj);
	if (len > 2)
	{
		cerr << "�������. ���� �� ���� �i����� �i���� 2 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.staj[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error==1);

do
{
	len = 0;
	error = 0;
	cout << "����i�� ��i����� �� i�i�i���\n";
	cin.ignore(1);
	cin.getline(st.name, 20, '\n');
	len = strlen(st.name);
	for(i = 0;i < len;i++)
	if(!isalpha(st.name[i]) && !isspace(st.name[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

dataAdding.write((char *) &st, sizeof(student));
dataAdding.close();
system("cls");
}

//�����i� ������ �������i� �� ������ ������.
void staj()
{setlocale(LC_CTYPE, "ukr");
	student st1;
	system("cls");
	double counter=0; // ��i���-�i�������.
	int counter1=0,counter2=0,counter3=0,counter4=0;// ��i��i-�i��������.
	int b=1; //��i��� ��� �����i��� �����.
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "�������. ��������� �i������ ����\n";
			_getch();
			exit(1);
		}
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"�        �        |     �   �   �              �        �\n";
  cout <<"�Fakultet�N_zalik |Spec.�Crs�Grp�     Name     �  Staj  �\n";
  cout <<"�        �        |     �   �   �              �        �\n"; 
	

	while( dataReading && !dataReading.eof())
	{
		
		        b++;
				counter++;
				if (atoi(st1.staj)==0)
			        counter4++;
				if (atoi(st1.staj)<1)
			        counter1++;
				if (atoi(st1.staj)>=1 && atoi(st1.staj)<=3)
			        counter2++;
				if (atoi(st1.staj)>3)
			        counter3++;

			cout <<"|========|========|=====|===|===|==============|========|\n";
			cout << "�";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "�";
			cout.width(8);
			cout << st1.nomer ;
			cout << "�";
			cout.width(5);
			cout << st1.spec ;
			cout << "�";
			cout.width(3);
			cout << st1.course ;
			cout << "�";
			cout.width(3);
			cout << st1.group ;
			cout << "�";
			cout.width(14);
			cout << st1.name ;
			cout << "�";
			cout.width(8);
			cout << st1.staj;
			cout << "�\n";
			

		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		  
			cout <<"|========|========|=====|===|===|==============|========|\n\n\n"; 
			table(counter,counter1,counter2,counter3,counter4,b);
cout << "\n������i�� ����-��� ����i�� ��� ������\n";
_getch();
}

//�����i� ��i�� ����� �������� �� ������� � �����i. ������� �����i� "createstruct()".
void change()
{setlocale(LC_CTYPE, "ukr");	
	int i=0;// ��i��� ���������� ������ ������.
fstream change("data.txt", ios::out | ios::in | ios::binary);
	if(!change)
	{
		cerr <<"\n�������. ��������� �i������ ����\n";
		exit(1);
	}
	do
	{
		viewfile();
		cout << "\n����i�� ����� ��������(#) ���i ����� ����� ���� ��i���i.\n";
		cout << "\n ��� ����i�� 0 - ��� ������: " << " ";
		cin >> i;
		if (change.eof())
			change.seekp(0);
		if (i == 0)
			break;
		else
		{
			change.seekg((i-1) * sizeof(student));
			change.read((char *) &st, sizeof(student));
			cout << setiosflags(ios::left) << setw(2) << i;
			cout << setiosflags(ios::left) << setw(10) << st.fakultet;
			cout << setiosflags(ios::left) << setw(7) << st.nomer;
			cout << setiosflags(ios::left) << setw(6) << st.spec;
			cout << setiosflags(ios::left) << setw(6) << st.course;
			cout << setiosflags(ios::left) << setw(6) << st.group;
			cout << setiosflags(ios::left) << setw(2) << st.staj;
			cout << setiosflags(ios::left) << setw(20) << st.name;
			cout << endl;
			createstruct();
			change.seekp((i-1) * sizeof(student));
			change.write((char *) &st, sizeof(student));
			change.close();
		}
	}
	while(i != 0);
}

//�����i� ������ ����� ����� �� �i��i ����������� ����������� �����i�� "change()". 
//������ � �����i� "change()".
void createstruct()
{setlocale(LC_CTYPE, "ukr");
system("cls");
int len = 0; //��i��� ��� ������ �������� ������� ����i�.
int i = 0; // ��i��� ��� ����i�.
int error; // ��i��� �� ��������������� ��� �����i��� ������ �������� �� �������.

do
{
	error = 0;

	cout << "����i�� ���������(���������: FISiT)\n";
	cin >> st.fakultet;
	len = strlen(st.fakultet);
	for (i = 0;i < len;i++)
		if(!isalpha(st.fakultet[i]))
		{
			error = 1;
			break;
		}
	
	if (error == 1)
		cerr << "�������. ���i���� ��� �����\n";

	
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����� ���i�����':(���������: 116223)\n";
	cin >> st.nomer;
	len = strlen(st.nomer);
	if (len != 6 )
	{
		cerr << "�������. ����� ���i����� �� �i����� 6 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.nomer[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����i����i���':(���������: 6101)\n";
	cin >> st.spec;
	len = strlen(st.spec);
	if (len != 4)
	{
		cerr << "�������. ����i����i��� �� �i����� 4 �����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.spec[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� ����:(���������: 2)\n";
	cin >> st.course;
	len = strlen(st.course);
	if (len > 1)
	{
		cerr << "�������. ���� �� ���� �i����� �i���� 1 �����n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.course[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "����i�� �����:(���������: 1)\n";
	cin >> st.group;
	len = strlen(st.group);
	if (len > 2)
	{
		cerr << "�������. ����� �� ���� �i����� �i���� 2 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.group[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);

do
{
	len = 0;
	error = 0;
	cout << "����i�� ���� \n";
	cin >> st.staj;
	len = strlen(st.staj);
	if (len > 2)
	{
		cerr << "�������. ����� �� ���� �i����� �i���� 2 ����\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.staj[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error==1);

do
{
	len = 0;
	error = 0;
	cout << "����i�� ��i����� �� i�i�i���\n";
	cin.ignore(1);
	cin.getline(st.name, 20, '\n');
	len = strlen(st.name);
	for(i = 0;i < len;i++)
	if(!isalpha(st.name[i]) && !isspace(st.name[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "�������\n";
}
while(error == 1);
system("cls");
}

//����i� ��������� �����i� �� ������ �����������.
void viewfak()

{setlocale(LC_CTYPE, "ukr");
system("cls");
    double counter=0; // ��i���-�i�������.
	int counter1=0,counter2=0,counter3=0,counter4=0;// ��i��i-�i��������.
	int b=1; //��i��� ��� �����i��� �����.
	char fak[10];//��i��� ��� ������ �������� �������� ����������.
	student st1;
    int len ; //��i��� ��� ������ �������� ������� �����.
    int k; // ��i��� ��� ��������� ������ �� ������� �����������.
    int error; // ��i��� �� ��������������� ��� �����i��� ������ �������� �� �������.
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "�������. ��������� �i������ ����\n";
			system("pause");
			exit(1);
		}
	do
	{
		len = 0;
		error = 0;
		system("cls");
		viewfile();
		cout << "\n����i�� ��������� ��� �������� �������i�:\n";
		cin >> fak;
		len = strlen(fak);
		for (int i = 0; i < len; i++)
			if(!isalpha(fak[i]))
			{
				error = 1;
				break;
			}
			if (error == 1)
			{
				cerr << "�������. ����������� ��� �����\n";
				system("pause");
			}
	}
	while(error == 1);
	system("cls");
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"�        �        |     �   �   �              �        �\n";
  cout <<"�Fakultet�N_zalik |Spec.�Crs�Grp�     Name     �  Staj  �\n";
  cout <<"�        �        |     �   �   �              �        �\n"; 
	while( error != 1 && dataReading && !dataReading.eof())
	{
		
		
				for(int i = 0; i < len; i++)
					if(strcmp(st1.fakultet,fak))
						k = 0;
					else {k = 1;}
				if(k == 1)
			{     b++;
				counter++;
				if (atoi(st1.staj)==0)
			        counter4++;
				if (atoi(st1.staj)<1)
			        counter1++;
				if (atoi(st1.staj)>=1 && atoi(st1.staj)<=3)
			        counter2++;
				if (atoi(st1.staj)>3)
			        counter3++;
			
			
			cout <<"|========|========|=====|===|===|==============|========|\n";
			cout << "�";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "�";
			cout.width(8);
			cout << st1.nomer ;
			cout << "�";
			cout.width(5);
			cout << st1.spec ;
			cout << "�";
			cout.width(3);
			cout << st1.course ;
			cout << "�";
			cout.width(3);
			cout << st1.group ;
			cout << "�";
			cout.width(14);
			cout << st1.name ;
			cout << "�";
			cout.width(8);
			cout << st1.staj;
			cout << "�\n";
			}
		
		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		cout <<"|========|========|=====|===|===|==============|========|\n\n"; 

		table(counter,counter1,counter2,counter3,counter4,b);

		system("pause");
}

//����i� ��������� �����i� �� ������ ����i����i���.
void viewspec()

{setlocale(LC_CTYPE, "ukr");
system("cls");
    double counter=0; // ��i���-�i�������.
	int counter1=0,counter2=0,counter3=0,counter4=0;// ��i��i-�i��������.
	int b=1; //��i��� ��� �����i��� �����.
	char spec[5];//��i��� ��� ������ �������� ������ ����i�������i.
	student st1;
	int len ; //��i��� ��� ������ �������� ������� ����i�.
    int k; // ��i��� ��� ��������� ������ �� ������� ����i����i���.
    int error; // ��i��� �� ��������������� ��� �����i��� ������ �������� �� �������.
	system("cls");
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "�������. ��������� �i������ ����\n";
			system("pause");
			exit(1);
		}
	do
	{
		error = 0;
		len = 0;
		k = 0;
		viewfile();
		cout << "\n����i�� ����i����i��� ��� �������� �������i�:\n";
		cin >> spec;
		len = strlen(spec);
		for (int i = 0; i < len; i++)
			if(!isdigit(spec[i]))
			{
				error = 1;
				break;
			}
			if (error == 1)
			{
				cerr << "�������. ����������� ��� �����\n";
				system("pause");
			}
	}
	while(error == 1);
	system("cls");
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"�        �        |     �   �   �              �        �\n";
  cout <<"�Fakultet�N_zalik |Spec.�Crs�Grp�     Name     �  Staj  �\n";
  cout <<"�        �        |     �   �   �              �        �\n"; 
	while( error != 1 && dataReading && !dataReading.eof())
	{
		
				len = strlen(spec);
				for(int i = 0; i < len; i++)
					if( st1.spec[i] != spec[i])
						k = 0;
					else k = 1;
				if(k == 1)
			{
				b++;
				counter++;
				if (atoi(st1.staj)==0)
			        counter4++;
				if (atoi(st1.staj)<1)
			        counter1++;
				if (atoi(st1.staj)>=1 && atoi(st1.staj)<=3)
			        counter2++;
				if (atoi(st1.staj)>3)
			        counter3++;

			cout <<"|========|========|=====|===|===|==============|========|\n";
			cout << "�";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "�";
			cout.width(8);
			cout << st1.nomer ;
			cout << "�";
			cout.width(5);
			cout << st1.spec ;
			cout << "�";
			cout.width(3);
			cout << st1.course ;
			cout << "�";
			cout.width(3);
			cout << st1.group ;
			cout << "�";
			cout.width(14);
			cout << st1.name ;
			cout << "�";
			cout.width(8);
			cout << st1.staj;
			cout << "�\n";
			}
		
		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		cout <<"|========|========|=====|===|===|==============|========|\n\n\n"; 

		table(counter,counter1,counter2,counter3,counter4,b);

system("pause");
}

//����i� ��������� �����i� �� ������ ������.
void viewcourse()

{setlocale(LC_CTYPE, "ukr");
system("cls");
	char course[2]; //��i��� ��� ������ �������� �������� �����.
	student st1;
	double counter=0; // ��i���-�i�������.
	int counter1=0,counter2=0,counter3=0,counter4=0;// ��i��i-�i��������.
	int b=1; //��i��� ��� �����i��� �����.
	int len ; //��i��� ��� ������ �������� ������� ����i�.
    int k; // ��i��� ��� ��������� ������ �� ������� ������.
    int error; // ��i��� �� ��������������� ��� �����i��� ������ �������� �� �������.
	system("cls");
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "�������. ��������� �i������ ����\n";
			system("pause");
			exit(1);
		}
	do
	{
		error = 0;
		len = 0;
		k = 0;
		viewfile();
		cout << "\n����i�� ���� ��� �������� �������i�:\n";
		cin >> course;
		len = strlen(course);
		for (int i = 0; i < len; i++)
			if(!isdigit(course[i]))
			{
				error = 1;
				break;
			}
			if (error == 1)
			{
				cerr << "�������. ����������� ��� �����\n";
				system("pause");
			}
	}
	while(error == 1);
	system("cls");
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"�        �        |     �   �   �              �        �\n";
  cout <<"�Fakultet�N_zalik |Spec.�Crs�Grp�     Name     �  Staj  �\n";
  cout <<"�        �        |     �   �   �              �        �\n"; 
	while( error != 1 && dataReading && !dataReading.eof())
	{
		
				len = strlen(course);
				for(int i = 0; i < len; i++)
					if( st1.course[i] != course[i])
						k = 0;
					else k = 1;
				if(k == 1)


			{    b++;
				counter++;
				if (atoi(st1.staj)==0)
			        counter4++;
				if (atoi(st1.staj)<1)
			        counter1++;
				if (atoi(st1.staj)>=1 && atoi(st1.staj)<=3)
			        counter2++;
				if (atoi(st1.staj)>3)
			        counter3++;


			cout <<"|========|========|=====|===|===|==============|========|\n";
			cout << "�";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "�";
			cout.width(8);
			cout << st1.nomer ;
			cout << "�";
			cout.width(5);
			cout << st1.spec ;
			cout << "�";
			cout.width(3);
			cout << st1.course ;
			cout << "�";
			cout.width(3);
			cout << st1.group ;
			cout << "�";
			cout.width(14);
			cout << st1.name ;
			cout << "�";
			cout.width(8);
			cout << st1.staj;
			cout << "�\n";
			}
		
		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		cout <<"|========|========|=====|===|===|==============|========|\n\n\n"; 

		table(counter,counter1,counter2,counter3,counter4,b);

system("pause");
}

//����i� ��������� ������ �������.
void deldata()
{setlocale(LC_CTYPE, "ukr");
    char Name [25]; //��i��� ��� ������ �������� �������� i���i.
    fstream NewDataFile;
    student st,
        Buffer = {"", "", "", ""};
    long int filepos;
   
    NewDataFile.open("data.txt", ios::in | ios::out | ios::binary);
    if (!NewDataFile)
    {
        cout << "\n��������� �i������ ����...\n";
        system("pause");
        return;
    }
    cout << "����i�� ��i����� �� i�i�i��� ��������: ";
    cin >> Name;

    while (!NewDataFile.eof())
    {
        filepos = NewDataFile.tellp();
        NewDataFile.read((char *) &st, sizeof(student));
		if (strcmp(st.name, Name) == 0)
        {
            cout << "�������� ��������." << endl;
            cout << "�������� �����:" << endl;
			cout << "���������: " << st.fakultet << endl;
			cout << "����� ���i�����: " << st.nomer << endl;
			cout << "����i����i���: " << st.spec << endl;
			cout << "����: " << st.course << endl;
			cout << "�����: " << st.group << endl;
			cout << "��i����� �� i�i�i���: " << st.name << endl;
			cout << "����:" << st.staj<< endl;
            system("pause");
            NewDataFile.seekp(filepos, ios::beg);
            NewDataFile.write((char *)&Buffer, sizeof(student));
            return;
        }
    }
    cout << "������ �������� �� ��������." << endl;
}

// ����i� ��������� ���i�����.
void dovidnyk()
{ cout << "� ���i����� �� ������ ������ �����i��� i�������i� ��� ���������i ��������:\n";
  cout << "���������� : \n\n";
  cout << "FISiT  FEF \n"; 
_getch ();
}

// ����i� ��� ������ 2 ������i.
void table(double counter, int counter1, int counter2, int counter3, int counter4, int b)
{if (b>1)
		{
		cout <<"���� ������ �������i�: \n\n";
		cout <<"|=======|=======|===========|=========|\n";
		cout <<"| ���� |�� ����| �i� 1 �� 3|�i���� 3 |\n";
        cout <<"|===|===|===|===|=====|=====|===|=====|\n";
		cout <<"| n | % | n | % |  n  |  %  | n |  %  |\n";
		cout <<"|===|===|===|===|=====|=====|===|=====|\n";
		cout << "|";
		cout.width(3);
		cout<<counter4;
		cout << "|";
		cout.width(3);
		cout<<setprecision(2)<<(counter4/counter)*100;
		cout << "|";
		cout.width(3);
		cout<<counter1;
		cout << "|";
	    cout.width(3);
		cout<<setprecision(2)<<(counter1/counter)*100;
		cout << "|";
	    cout.width(5);
		cout<<counter2;
		cout << "|";
		cout.width(5);
		cout<<setprecision(2)<<(counter2/counter)*100;
		cout << "|";
		cout.width(3);
		cout<<counter3;
		cout << "|";
		cout.width(5);
		cout<<setprecision(2)<<(counter3/counter)*100;
		cout << "|"<<endl;
		cout <<"|===|===|===|===|=====|=====|===|=====|\n";}}