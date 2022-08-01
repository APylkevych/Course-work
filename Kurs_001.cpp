#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <ctype.h>

void createfile();  //Функцiя створення файлу. Викликається з головної функції "main()".
void addinfile();   //Функцiя перегляду файлу. Викликається з головної функції "main()".
void viewfile();    //Функцiя додавання записiв у файл. Викликається з головної функції "main()".
void staj();        //Функцiя показу студентiв за стажем роботи.Викликає фунцію "table(...)". 
                    //Викликається з головної функції "main()".
void change();      //Функцiя змiни даних студента за номером в записi. Викликає функцiю "createstruct()". 
                    //Викликається з головної функції "main()".
void createstruct();//Функцiя запису нових даних на мiсцi визначеному попередньою функцiєю "change()". 
                    //Виклик з функцiї "change()". 
void deldata();     //Фунцiя видалення запису студнта.Викликається з головної функції "main()".
void viewfak();     //Фунцiя виведення записiв за певним факультетом. Викликає фунцію "table(...)".
                    //Викликається з головної функції "main()".
void viewspec();    //Фунцiя виведення записiв за певною спецiальнiстю. Викликає фунцію "table(...)".
                    //Викликається з головної функції "main()".
void viewcourse();  //Фунцiя виведення записiв за певним курсом.Викликає фунцію "table(...)".
                    //Викликається з головної функції "main()".
void dovidnyk();    // Фунцiя перегляду довiдника. Викликається з головної функції "main()".
void table(double, int, int, int, int, int b);// Фунцiя для виводу 2 таблицi.
                                             //Викликається функціями: "staj()", "viewfak()", "viewspec()", "viewcourse()"

	
using namespace std;

	struct student	
	{	
		char fakultet[10]; //Назва факультету;
		char nomer[8];     //Номер залікової унижки;
		char spec[5];      //Номер спеціальності;
		char course[3];    //Номер курсу;
		char group[3];     // Номер групи;
		char name[32];     // ПІБ
		char staj[3];      //Стаж роботи
	   
	};
student st;


//Головна функцiя програми. Мiституть у собi меню контролю програми. 
int main()
{setlocale(LC_CTYPE, "ukr");

  int choise; //Змiна що використовується для роботи з меню.

do
{
	system("cls");
	cout <<"|=====================================================|\n";
	cout <<"¦---------------------Головне меню:-------------------¦\n";
	cout <<"¦------- 1  - Створити файл з даними       -----------¦\n";
	cout <<"¦------- 2  - Переглянути файл з даними    -----------¦\n";
	cout <<"¦------- 3  - Додати данi                  -----------¦\n";
	cout <<"¦------- 4  - Перегляд студентiв (розподiл)-----------¦\n"; 
	cout <<"¦------- 5  - Змiнити данi студента        -----------¦\n";
	cout <<"¦------- 6  - Видаленя запиту студента     -----------¦\n";
	cout <<"¦------- 7  - Перегляд студентiв за факультетами------¦\n";
	cout <<"¦------- 8  - Перегляд студентiв за спецiальностями---¦\n";
	cout <<"¦------- 9  - Перегляд студентiв за курсом -----------¦\n";
	cout <<"¦------- 10 - Перегляд довідника           -----------¦\n";
	cout <<"¦------- 0  - Вихiд                        -----------¦\n";
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
				 createfile(); //Виклик функцiї;
				 break;
			 }
	case 2:
			 {
				 viewfile();//Виклик функцiї;
				 _getch();
				 break;
			 }
	case 3:
			 {
				 addinfile();//Виклик функцiї;
				 break;
			 }
	case 4:
			{
				staj();//Виклик функцiї;
				break;
			}
	case 5:
			{
				change();//Виклик функцiї;
				break;
			}
	case 6:
			{
				deldata();//Виклик функцiї;
				break;
			}
	case 7:
			{
				viewfak();//Виклик функцiї;
				break;
			}
	case 8:
			{
				viewspec();//Виклик функцiї;
				break;
			}
	case 9:
			{
				viewcourse();//Виклик функцiї;
				break;
			}dovidnyk();
	case 10:
			{
				dovidnyk();//Виклик функцiї;
				break;
			}
	default:
			{
				cerr << "Помилка. Данi введенi невiрно";
				break;
			}

	}

}
while (choise != 0);
	return 0;
}

//Функцiя створення файлу.
void createfile()
{setlocale(LC_CTYPE, "ukr");
system("cls");
int len = 0; //Змiнна яка приймає значення довжини рядкiв.
int i = 0; // Змiнна для циклiв.
int error; // Змiнна що використовується для перевiрки роботи програми на помилки.

ofstream dataWriting("data.txt", ios::out | ios::binary);
	if(!dataWriting)
		cerr << "Неможливо вiдкрити файл\n";

do
{
	error = 0;

	cout << "Введiть факультет(Наприклад: FISiT)\n";
	cin >> st.fakultet;
	len = strlen(st.fakultet);
	for (i = 0;i < len;i++)
		if(!isalpha(st.fakultet[i]))
		{
			error = 1;
			break;
		}
	
	if (error == 1)
		cerr << "Помилка. Невiрний тип даних\n";

	
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть номер залiковки':(Наприклад: 116223)\n";
	cin >> st.nomer;
	len = strlen(st.nomer);
	if (len != 6 )
	{
		cerr << "Помилка. Номер залiковки має мiстити 6 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.nomer[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть спецiальнiсть':(Наприклад: 6101)\n";
	cin >> st.spec;
	len = strlen(st.spec);
	if (len != 4)
	{
		cerr << "Помилка. Спецiальнiсть має мiстити 4 цифри\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.spec[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть курс:(Наприклад: 2)\n";
	cin >> st.course;
	len = strlen(st.course);
	if (len > 1)
	{
		cerr << "Помилка. Курс не може мiстити бiльше 1 цифриn";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.course[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть групу:(Наприклад: 1)\n";
	cin >> st.group;
	len = strlen(st.group);
	if (len > 2)
	{
		cerr << "Помилка. Група не може мiстити бiльше 2 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.group[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{
	len = 0;
	error = 0;
	cout << "Введiть стаж \n";
	cin >> st.staj;
	len = strlen(st.staj);
	if (len > 2)
	{
		cerr << "Помилка. Група не може мiстити бiльше 2 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.staj[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error==1);

do
{
	len = 0;
	error = 0;
	cout << "Введiть прiзвище та iнiцiали\n";
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
			cerr << "Помилка\n";
}
while(error == 1);
dataWriting.write((char *) &st, sizeof(student));
dataWriting.close();
system("cls");
}

//Функцiя перегляду файлу.
void viewfile()
{setlocale(LC_CTYPE, "ukr");	
student st1;

system("cls");
ifstream dataReading("data.txt", ios::in | ios::binary);
if (!dataReading)
		{
			cerr << "Помилка. Неможливо вiдкрити файл\n";
			_getch();
			exit(1);
		}
dataReading.read((char *) &st1, sizeof(student));
int i=0; // Змiнна для визначення порядку записiв в файлi.

  cout <<"|===|========|========|=====|===|===|==============|========|\n";
  cout <<"¦   ¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n";
  cout <<"¦ # ¦Fakultet¦N_zalik |Spec.¦Crs¦Grp¦     Name     ¦  Staj  ¦\n";
  cout <<"¦   ¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n"; 
while(dataReading && !dataReading.eof())
	{	
		cout << "|===|========|========|=====|===|===|==============|========|\n";
		cout << "¦";
		cout << setiosflags(ios::left) << setw(3) << ++i;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(8) << st1.fakultet;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(8) << st1.nomer;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(5) << st1.spec;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(3) << st1.course;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(3) << st1.group;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(14) << st1.name;
		cout << "¦";
		cout << setiosflags(ios::left) << setw(8) << st1.staj;
		cout << "¦\n";
		dataReading.read((char *) &st1, sizeof(student));
	}
	cout <<"|===|========|========|=====|===|===|==============|========|";
dataReading.close();
}

//Функцiя додавання записiв у файл.
void addinfile()
{setlocale(LC_CTYPE, "ukr");
system("cls");
int len = 0; //Змiнна яка приймає значення довжини рядкiв.
int i = 0; // Змiнна для циклiв.
int error; // Змiнна що використовується для перевiрки роботи програми на помилки.
ofstream dataAdding ("data.txt", ios::app | ios::binary);
	if(!dataAdding)
		cerr << "Неможливо вiдкрити файл\n";
do
{
	error = 0;
	cout << "Введiть факультет(Наприклад: FISiT)\n";
	cin >> st.fakultet;
	len = strlen(st.fakultet);
	for (i = 0;i < len;i++)
		if(!isalpha(st.fakultet[i]))
		{
			error = 1;
			break;
		}
	if (error == 1)
		cerr << "Помилка. Некоректний тип даних\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть номер залiковки':(Наприклад: 116223)\n";
	cin >> st.nomer;
	len = strlen(st.nomer);
	if (len != 6)
	{
		cerr << "Помилка. Номер залiковки має мiстити 6 цифри\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.nomer[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);


do
{	
	len = 0;
	error = 0;
	cout << "Введiть спецiальнiсть':(Наприклад: 6101)\n";
	cin >> st.spec;
	len = strlen(st.spec);
	if (len != 4)
	{
		cerr << "Помилка. Спецiальнiсть має мiстити 4 цифри\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.spec[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть курс:(Наприклад: 2)\n";
	cin >> st.course;
	len = strlen(st.course);
	if (len > 1)
	{
		cerr << "Помилка. Курс не може мiстити бiльше 1 цифри\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.course[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть групу:(Наприклад: 1)\n";
	cin >> st.group;
	len = strlen(st.group);
	if (len > 2)
	{
		cerr << "Помилка. Група не може мiстити бiльше 2 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.group[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{
	len = 0;
	error = 0;
	cout << "Введiть стаж \n";
	cin >> st.staj;
	len = strlen(st.staj);
	if (len > 2)
	{
		cerr << "Помилка. Стаж не може мiстити бiльше 2 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.staj[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error==1);

do
{
	len = 0;
	error = 0;
	cout << "Введiть прiзвище та iнiцiали\n";
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
			cerr << "Помилка\n";
}
while(error == 1);

dataAdding.write((char *) &st, sizeof(student));
dataAdding.close();
system("cls");
}

//Функцiя показу студентiв за стажем роботи.
void staj()
{setlocale(LC_CTYPE, "ukr");
	student st1;
	system("cls");
	double counter=0; // Змiнна-лiчильник.
	int counter1=0,counter2=0,counter3=0,counter4=0;// Змiннi-лiчильники.
	int b=1; //Змiнна для перевiрки умови.
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "Помилка. Неможливо вiдкрити файл\n";
			_getch();
			exit(1);
		}
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n";
  cout <<"¦Fakultet¦N_zalik |Spec.¦Crs¦Grp¦     Name     ¦  Staj  ¦\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n"; 
	

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
			cout << "¦";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "¦";
			cout.width(8);
			cout << st1.nomer ;
			cout << "¦";
			cout.width(5);
			cout << st1.spec ;
			cout << "¦";
			cout.width(3);
			cout << st1.course ;
			cout << "¦";
			cout.width(3);
			cout << st1.group ;
			cout << "¦";
			cout.width(14);
			cout << st1.name ;
			cout << "¦";
			cout.width(8);
			cout << st1.staj;
			cout << "¦\n";
			

		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		  
			cout <<"|========|========|=====|===|===|==============|========|\n\n\n"; 
			table(counter,counter1,counter2,counter3,counter4,b);
cout << "\nНатиснiть будь-яку клавiшу для виходу\n";
_getch();
}

//Функцiя змiни даних студента за номером в записi. Викликає функцiю "createstruct()".
void change()
{setlocale(LC_CTYPE, "ukr");	
	int i=0;// Змiнна визначення номеру запису.
fstream change("data.txt", ios::out | ios::in | ios::binary);
	if(!change)
	{
		cerr <<"\nПомилка. Неможливо вiдкрити файл\n";
		exit(1);
	}
	do
	{
		viewfile();
		cout << "\nВведiть номер студента(#) данi якого мають бути змiненi.\n";
		cout << "\n Або введiть 0 - для виходу: " << " ";
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

//Функцiя запису нових даних на мiсцi визначеному попередньою функцiєю "change()". 
//Виклик з функцiї "change()".
void createstruct()
{setlocale(LC_CTYPE, "ukr");
system("cls");
int len = 0; //Змiнна яка приймає значення довжини рядкiв.
int i = 0; // Змiнна для циклiв.
int error; // Змiнна що використовується для перевiрки роботи програми на помилки.

do
{
	error = 0;

	cout << "Введiть факультет(Наприклад: FISiT)\n";
	cin >> st.fakultet;
	len = strlen(st.fakultet);
	for (i = 0;i < len;i++)
		if(!isalpha(st.fakultet[i]))
		{
			error = 1;
			break;
		}
	
	if (error == 1)
		cerr << "Помилка. Невiрний тип даних\n";

	
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть номер залiковки':(Наприклад: 116223)\n";
	cin >> st.nomer;
	len = strlen(st.nomer);
	if (len != 6 )
	{
		cerr << "Помилка. Номер залiковки має мiстити 6 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.nomer[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть спецiальнiсть':(Наприклад: 6101)\n";
	cin >> st.spec;
	len = strlen(st.spec);
	if (len != 4)
	{
		cerr << "Помилка. Спецiальнiсть має мiстити 4 цифри\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.spec[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть курс:(Наприклад: 2)\n";
	cin >> st.course;
	len = strlen(st.course);
	if (len > 1)
	{
		cerr << "Помилка. Курс не може мiстити бiльше 1 цифриn";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.course[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{	
	len = 0;
	error = 0;
	cout << "Введiть групу:(Наприклад: 1)\n";
	cin >> st.group;
	len = strlen(st.group);
	if (len > 2)
	{
		cerr << "Помилка. Група не може мiстити бiльше 2 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.group[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error == 1);

do
{
	len = 0;
	error = 0;
	cout << "Введiть стаж \n";
	cin >> st.staj;
	len = strlen(st.staj);
	if (len > 2)
	{
		cerr << "Помилка. Група не може мiстити бiльше 2 цифр\n";
		error = 1;
	}
	for (i = 0;i < len; i++)
		if(!isdigit(st.staj[i]))
		{
			error = 1;
			break;
		}
		if(error == 1)
			cerr << "Помилка\n";
}
while(error==1);

do
{
	len = 0;
	error = 0;
	cout << "Введiть прiзвище та iнiцiали\n";
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
			cerr << "Помилка\n";
}
while(error == 1);
system("cls");
}

//Фунцiя виведення записiв за певним факультетом.
void viewfak()

{setlocale(LC_CTYPE, "ukr");
system("cls");
    double counter=0; // Змiнна-лiчильник.
	int counter1=0,counter2=0,counter3=0,counter4=0;// Змiннi-лiчильники.
	int b=1; //Змiнна для перевiрки умови.
	char fak[10];//Змiнна яка приймає значення заданого факультету.
	student st1;
    int len ; //Змiнна яка приймає значення довжини рядка.
    int k; // Змiнна для виведення запису за заданим факультетом.
    int error; // Змiнна що використовується для перевiрки роботи програми на помилки.
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "Помилка. Неможливо вiдкрити файл\n";
			system("pause");
			exit(1);
		}
	do
	{
		len = 0;
		error = 0;
		system("cls");
		viewfile();
		cout << "\nВведiть факультет щоб побачити студентiв:\n";
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
				cerr << "Помилка. Некоректний тип даних\n";
				system("pause");
			}
	}
	while(error == 1);
	system("cls");
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n";
  cout <<"¦Fakultet¦N_zalik |Spec.¦Crs¦Grp¦     Name     ¦  Staj  ¦\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n"; 
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
			cout << "¦";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "¦";
			cout.width(8);
			cout << st1.nomer ;
			cout << "¦";
			cout.width(5);
			cout << st1.spec ;
			cout << "¦";
			cout.width(3);
			cout << st1.course ;
			cout << "¦";
			cout.width(3);
			cout << st1.group ;
			cout << "¦";
			cout.width(14);
			cout << st1.name ;
			cout << "¦";
			cout.width(8);
			cout << st1.staj;
			cout << "¦\n";
			}
		
		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		cout <<"|========|========|=====|===|===|==============|========|\n\n"; 

		table(counter,counter1,counter2,counter3,counter4,b);

		system("pause");
}

//Фунцiя виведення записiв за певною спецiальнiстю.
void viewspec()

{setlocale(LC_CTYPE, "ukr");
system("cls");
    double counter=0; // Змiнна-лiчильник.
	int counter1=0,counter2=0,counter3=0,counter4=0;// Змiннi-лiчильники.
	int b=1; //Змiнна для перевiрки умови.
	char spec[5];//Змiнна яка приймає значення заданої спецiальностi.
	student st1;
	int len ; //Змiнна яка приймає значення довжини рядкiв.
    int k; // Змiнна для виведення запису за заданою спецiальнiстю.
    int error; // Змiнна що використовується для перевiрки роботи програми на помилки.
	system("cls");
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "Помилка. Неможливо вiдкрити файл\n";
			system("pause");
			exit(1);
		}
	do
	{
		error = 0;
		len = 0;
		k = 0;
		viewfile();
		cout << "\nВведiть спецiальнiсть щоб побачити студентiв:\n";
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
				cerr << "Помилка. Некоректний тип даних\n";
				system("pause");
			}
	}
	while(error == 1);
	system("cls");
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n";
  cout <<"¦Fakultet¦N_zalik |Spec.¦Crs¦Grp¦     Name     ¦  Staj  ¦\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n"; 
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
			cout << "¦";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "¦";
			cout.width(8);
			cout << st1.nomer ;
			cout << "¦";
			cout.width(5);
			cout << st1.spec ;
			cout << "¦";
			cout.width(3);
			cout << st1.course ;
			cout << "¦";
			cout.width(3);
			cout << st1.group ;
			cout << "¦";
			cout.width(14);
			cout << st1.name ;
			cout << "¦";
			cout.width(8);
			cout << st1.staj;
			cout << "¦\n";
			}
		
		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		cout <<"|========|========|=====|===|===|==============|========|\n\n\n"; 

		table(counter,counter1,counter2,counter3,counter4,b);

system("pause");
}

//Фунцiя виведення записiв за певним курсом.
void viewcourse()

{setlocale(LC_CTYPE, "ukr");
system("cls");
	char course[2]; //Змiнна яка приймає значення заданого курсу.
	student st1;
	double counter=0; // Змiнна-лiчильник.
	int counter1=0,counter2=0,counter3=0,counter4=0;// Змiннi-лiчильники.
	int b=1; //Змiнна для перевiрки умови.
	int len ; //Змiнна яка приймає значення довжини рядкiв.
    int k; // Змiнна для виведення запису за заданим курсом.
    int error; // Змiнна що використовується для перевiрки роботи програми на помилки.
	system("cls");
	ifstream dataReading("data.txt", ios::in | ios::binary);
	if (!dataReading)
		{
			cerr << "Помилка. Неможливо вiдкрити файл\n";
			system("pause");
			exit(1);
		}
	do
	{
		error = 0;
		len = 0;
		k = 0;
		viewfile();
		cout << "\nВведiть курс щоб побачити студентiв:\n";
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
				cerr << "Помилка. Некоректний тип даних\n";
				system("pause");
			}
	}
	while(error == 1);
	system("cls");
	dataReading.read((char *) &st1, sizeof(st1));
  cout <<"|========|========|=====|===|===|==============|========|\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n";
  cout <<"¦Fakultet¦N_zalik |Spec.¦Crs¦Grp¦     Name     ¦  Staj  ¦\n";
  cout <<"¦        ¦        |     ¦   ¦   ¦              ¦        ¦\n"; 
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
			cout << "¦";
			cout.width(8);
			cout << st1.fakultet ;
			cout << "¦";
			cout.width(8);
			cout << st1.nomer ;
			cout << "¦";
			cout.width(5);
			cout << st1.spec ;
			cout << "¦";
			cout.width(3);
			cout << st1.course ;
			cout << "¦";
			cout.width(3);
			cout << st1.group ;
			cout << "¦";
			cout.width(14);
			cout << st1.name ;
			cout << "¦";
			cout.width(8);
			cout << st1.staj;
			cout << "¦\n";
			}
		
		dataReading.read((char *) &st1, sizeof(student));
	}
		dataReading.close();
		cout <<"|========|========|=====|===|===|==============|========|\n\n\n"; 

		table(counter,counter1,counter2,counter3,counter4,b);

system("pause");
}

//Фунцiя видалення запису студнта.
void deldata()
{setlocale(LC_CTYPE, "ukr");
    char Name [25]; //Змiнна яка приймає значення заданого iменi.
    fstream NewDataFile;
    student st,
        Buffer = {"", "", "", ""};
    long int filepos;
   
    NewDataFile.open("data.txt", ios::in | ios::out | ios::binary);
    if (!NewDataFile)
    {
        cout << "\nНеможливо вiдкрити файл...\n";
        system("pause");
        return;
    }
    cout << "Введiть прiзвище та iнiцiали студента: ";
    cin >> Name;

    while (!NewDataFile.eof())
    {
        filepos = NewDataFile.tellp();
        NewDataFile.read((char *) &st, sizeof(student));
		if (strcmp(st.name, Name) == 0)
        {
            cout << "Студента знайдено." << endl;
            cout << "Поточний запис:" << endl;
			cout << "Факультет: " << st.fakultet << endl;
			cout << "Номер залiковки: " << st.nomer << endl;
			cout << "Спецiальнiсть: " << st.spec << endl;
			cout << "Курс: " << st.course << endl;
			cout << "Група: " << st.group << endl;
			cout << "Прiзвище та iнiцiали: " << st.name << endl;
			cout << "Стаж:" << st.staj<< endl;
            system("pause");
            NewDataFile.seekp(filepos, ios::beg);
            NewDataFile.write((char *)&Buffer, sizeof(student));
            return;
        }
    }
    cout << "Такого студента не знайдено." << endl;
}

// Фунцiя перегляду довiдника.
void dovidnyk()
{ cout << "В довiднику ви можете знайти необхiдну iнформацiю при винекненнi запитань:\n";
  cout << "Факультети : \n\n";
  cout << "FISiT  FEF \n"; 
_getch ();
}

// Фунцiя для виводу 2 таблицi.
void table(double counter, int counter1, int counter2, int counter3, int counter4, int b)
{if (b>1)
		{
		cout <<"Стаж роботи студентiв: \n\n";
		cout <<"|=======|=======|===========|=========|\n";
		cout <<"| Немає |До року| Вiд 1 до 3|Бiльше 3 |\n";
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