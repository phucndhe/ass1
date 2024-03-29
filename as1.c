/* CONTACT KEEPER
 * ==============
 * 
 * So far, you've been learning the C programing language about two weeks.
 * Now is the right time to think about your assignment.
 * This semester, your task is to write a C program, namely Contact Keeper,
 * to manage your contacts easily and effectively.
 * 
 * One contact should have the following features:
 *		1. First Name
 *		2. Last Name
 *		3. Company
 *		3. Phone Number
 *		4. Email
 *		5. Working Address
 *		6. Home Address
 *		7. Birthday
 *
 * Data validation should be implemented, for example:
 *		1. Phone Number should be a integer number of 9 or 10 digits
 *		2. Bithday should be in the DD/MM/YYYY format 
 *
 * Your program should have at least six functions:
 *		1. Add new contact
 *		2. Edit contact
 *		3. Delete contact (by name or phone number)
 *		4. Search contact (by name or phone number)
 *		5. List all contacts with birthdays in a given month (sort by date)
 *		6. List all contacts in the table format (sort by name)
 *
 * The contact information should be permanently stored in a text file
 * so that when the program starts all contacts could be loaded automatically.
 *
 * Form a group of three members and enjoy this task!
 */


#include <stdio.h>
#include <stdlib.h>

void print_menu();
void add_contact();
void edit_contact();
void delete_contact();
// các hàm thêm
void search_contact();
void list_month();
void list_all();
//

// t khai baos 1 struct kieu ngay sinh
typedef struct born
{
	int date;
	int month;
	int year;
}bd;

// day la kieu khai bao 1 struct kieu con nguoi, la tat ca cac thong tin de contact
typedef struct ng
{

	char first_name[10];
	char last_name[25];
	char company[40];
	int phone_number;
	char email[50];
	char working_address[100];
	char home_address[100];
	bd birday;
	
}person;

person man[1000];
int i = 0;
int main()
{
	char choice;

	do
	{
		system("cls"); 
		print_menu();
		scanf("%c%*c", &choice);

		system("cls"); 
		int i = 0;
		printf("CONTACT KEEPER\n");
		printf("==============\n\n");

		switch(choice)
		{
			case '1':
				add_contact();
				break;
			case '2':
				edit_contact();
				break;
			case '3':
				delete_contact();
				break;
			case '4':
				search_contact();
				break;
			case '5':
				list_month();
				break;
			case '6':
				list_all();
				break;
		}
		
		if (choice != 'q')
		{
			printf("\n\n---\n");
			printf("Press any key to back to main menu.");
			getchar();
		}
	}
	while (choice != 'q');

	return 0;
}


void print_menu()
{
	printf("CONTACT KEEPER\n");
	printf("==============\n\n");
	printf("1. Add Contact\n");
	printf("2. Edit Contact\n");
	printf("3. Delete Contact\n");
	printf("4. Search Contact\n");
	printf("5. Show list Contact\n");
	printf("6. show list Contact with birday by given month\n");
	printf("q. Quit\n\n");
	printf("Enter your choice (1/2/3/4/5/6/q): ");
}


int valid_date(int dd, int mm, int yy) {
    if (mm < 1 || mm > 12) {
        return 0;
    }
    if (dd < 1) {
        return 0;
    }

    int days = 31;
    if (mm == 2) {
        days = 28;
        if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
            days = 29;
        }
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        days = 30;
    }

    if (dd > days) {
        return 0;
    }
    return 1;
}


void inputPhone(char* phone){
	while(1){
	printf("\nNhap so dien thoai : ");	
	scanf("%s",phone);
	if(strlen(phone) < 9 || strlen(phone) > 10){
		printf("\nSo dien thoai can tu 9-10 so");
		continue;
	}
	int i = 0;
	int check = 1;
	for(i = 0;i < strlen(phone);i++){
		if(!isdigit(phone[i])){
			printf("\nSo dien thoai phai gom cac chu so");
			check = 0;
			break;
		}
	}
	if(check){
		return;
	}	
	}
}

person create(){
	person p;
	fflush(stdin);
	printf("\n Nhap ho : ");
	gets(p.first_name);
	printf("\n Nhap ten : ");
	gets(p.last_name);
	printf("\nNhap ten cong ty : ");
	gets(p.company);
	inputPhone(p.phone_number);
	fflush(stdin);
	printf("\nNhap email : ");
	gets(p.email);
	printf("\nDia chi lam viec : ");
	gets(p.working_address);
	printf("\ndia chi nha : ");
	gets(p.home_address);
	while(1){
	printf("\nNhap ngay : ");
	scanf("%d",&p.birday.date);
	printf("\nNhap thang : ");
	scanf("%d",&p.birday.month);
	printf("\nNhap nam : ");
	scanf("%d",&p.birday.year);
	if(valid_date(p.birday.date,p.birday.month,p.birday.year) == 1){
		break;
	}
	printf("Khong hop le!! Nhap lai");
		continue;
	}
	fflush(stdin);
	return p;
}
void add_contact()
{
	person p = create();
	man[i] = p;
	i++;
}


void edit_contact(int j)
{
}


void delete_contact()
{
	printf("Write your code here to delete contact.");
}

//ham them
void search_contact()
{
	printf("Write your code here to delete contact.");
}


void list_month()
{
	printf("Write your code here to delete contact.");
}


void list_all()
{
	printf("Write your code here to delete contact.");
}


