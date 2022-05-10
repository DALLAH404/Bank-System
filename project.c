#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>


struct Node
{
	void *data;
	struct Node *next;
};

void push(struct Node** head_ref, void *new_data, size_t data_size)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = malloc(data_size);
	new_node->next = (*head_ref);

	int i;
	for (i=0; i<data_size; i++)
		*(char *)(new_node->data + i) = *(char *)(new_data + i);

	(*head_ref) = new_node;
}

void printList(struct Node *node, void (*fptr)(void *))
{
	while (node != NULL)
	{
		(*fptr)(node->data);
		node = node->next;
	}
}


void printInt(void *n)
{
printf(" %d", *(int *)n);
}

void printFloat(void *f)
{
printf(" %f", *(float *)f);
}



typedef struct UserINFO
{
    char FullName[100];
    char FullAddress[100];
    unsigned long long int NationalId;
    unsigned int Age;
    unsigned long long int BankAccountId;
    bool hasGuardian;
    unsigned long long int GuardianNationalId;
    char AccountStatus[100];
    unsigned long long int Balanced;
    unsigned long long int Password;

}UserINFO;




char const adminpass[8] = "DALLAH";
/*
int main() {
    int switcher;    
    do
    {
        system("cls");
        printf("please enter your role\n");
        printf("1-Iam admin\n");
        printf("2-Iam a user\n");
        printf("press ESC to exit\n");
        switch((switcher = _getch())){
        //49 is ascii for button 1
        case 49:
        system("cls");
        printf("U Choose admin\n");
        int switcher2;
        do {
            printf("Press Any Key to continue\n");
            switcher2 = _getch();
            if(switcher2 == 27){break;}
            char adminpwd[8];
            int i;
            system("cls");
            printf("Now You need authenicate who you are\n");
            printf("You can press ESC to return if you failed\n");
            printf("Enter your password : ");
            for (i=0; i<8; i++){
                adminpwd[i]=_getch();
                if((int) adminpwd[i] == 13){break;}
                printf("*");
            }
            adminpwd[i]='\0';
            printf("\n");
            if (!strcmp(adminpwd, adminpass))
            {
                system("cls");
                printf("Congrats You are now admin\n");
                switcher2 = _getch();
                int switcher3;
                do
                {
                    system("cls");
                    printf("U now have the following actions in your desposal\n");
                    printf("1-Create An Account\n");
                    printf("2-Open Account\n");
                    printf("3-Exit\n");
                    switch(switcher3 = _getch()){
                    case 49:
                    printf("create an account");
                    continue;
                    case 50:
                    printf("open existing(account) which isn't closed or restricted");
                    continue;
                    case 51:
                    return 0;
                    }


                } while (switcher3 != 27);
                

            }
            else
            {
                system("cls");
                printf("You Failed to authenticate\n");
                printf("You Failed to authenticate\n");
                switcher2 = _getch();
            }

        } while (switcher2 != 27);
        continue;
        
        //50 is ascii for button 2
        case 50:
        system("cls");
        printf("U are now a user\n");

        continue;
        }    

    // 27 is ascii for ESC
    } while (switcher != 27);
    
    return 0;
}
*/

/*
bool CheckString(char[] A)
{

}*/

bool isValidAge(int A)
{
    if (A < 21)
    return false
}
bool isValidName(char s[]){
    int j = 0;
    for (int i = 0; i<strlen(s); i ++){
        str
    }
}


void lolstring()
{
    char s[]="Helllo MyBrother";
    int i;
    for(i = 0; i<sizeof(s); i++)
    {
        printf("lol: %c\n", s[i]);
    }
}


int main()
{
    _flushall();
    printf("hello world\n");
    lolstring();
    return 0;
} 