#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/**      Author : Abdallah Mohamed Hamdy      **/
/**      SWC : LinkedList                     **/  
/**      Date : 29 12 2021                    **/
/**      Version : v1.0                       **/

typedef struct account
{
    char FullName[100];
    char FullAddress[100];
    long long int NationalId;
    int Age;
    long long int BankAccountId;
    bool Guardian;
    long long int GuardianNationalId;
    char AccountStatus[100];
    long long int Balanced;
    long long int Password;
    struct account* next ;
    
}Account;
// typedef struct listnode 
// { 
//     struct Account *Account1;

// }ListNode;

typedef struct linkedList
{
    Account* head ;
    int size ; 

}LinkedList;

int LL_intIsEmpty(LinkedList* pl);
void FillAccount(Account *account);
void CreateBankAccount(LinkedList* pl);
void LL_voidInsertAtBeginning(Account *acc, LinkedList* pl);
void LL_voidPrint(LinkedList* pl);
void setList(LinkedList* pl);
// void LL_voidPrintAccountInfo(LinkedList* pl);




int main()
{
    LinkedList ll ;
    //struct Account acc1 ;
    // struct Account acc2 ;

    
    setList(&ll);
    CreateBankAccount(&ll);
    CreateBankAccount(&ll);
    LL_voidPrint(&ll);


    return 0;
}


void setList(LinkedList* pl)
{
    pl->head = NULL;
    pl->size = 0;
}
void FillAccount(Account *account)
{
    printf("Enter Your Full Name :");
    fflush(stdin);
    gets(account->FullName);
    

    printf("Enter Your Full Address :");
    fflush(stdin);
    gets(account->FullAddress);



    printf("Enter Your Account Status :");
    fflush(stdin);
    gets(account->AccountStatus);


   
    printf("Enter Your National Id :");
    scanf("%lli", &account->NationalId);
    
    printf("Enter Your Age :");
    scanf("%d", &account->Age);
    
    printf("Enter Your Bank Account Id :");
    scanf("%lli", &account->BankAccountId);
    
    printf("Enter Your Guardian (y/n) :");
    scanf("%d", &account->Guardian);
    
    printf("Enter Your Full Guardian Id :");
    scanf("%lli", &account->GuardianNationalId);
    
    
    printf("Enter Your Balanced :");
    scanf("%lli", &account->Balanced);
    
    printf("Enter Your Password :");
    scanf("%lli", &account->Password);

}
/**
void LL_voidPrintAccountInfo(LinkedList* pl)
{
    printf("Full Name : %s\n",pl->FullName);
    printf("Full Address : %s\n",pl->FullAddress);
    printf("Account Status : %s\n",pl->AccountStatus);
    printf("National Id : %li\n",pl->NationalId);
    printf("Age : %d\n",pl->Age);
    printf("Bank Account Id : %li\n",pl->BankAccountId);
    printf("Guardian : %d\n",pl->Guardian);
    printf("Guardian National Id : %li\n",pl->GuardianNationalId);
    printf("Balanced : %li\n",pl->Balanced);
    printf("Password : %li\n",pl->Password);
  

}
**/
int LL_intIsEmpty(LinkedList* pl)
{
    return(pl->head==NULL);
}
void LL_voidInsertAtBeginning(Account *acc, LinkedList* pl)
{
    Account* pn = (Account*) malloc(sizeof(Account));
    strcpy(pn->FullName,acc->FullName);
    strcpy(pn->FullAddress,acc->FullAddress);
    strcpy(pn->AccountStatus,acc->AccountStatus);
    pn->NationalId = acc->NationalId;
    pn->Age = acc->Age;
    pn->BankAccountId = acc->BankAccountId;
    pn->Guardian = acc->Guardian;
    pn->GuardianNationalId = acc->GuardianNationalId;
    pn->Balanced = acc->Balanced;
    pn->Password = acc->Password;
    pn->next = NULL;
    if(LL_intIsEmpty(pl))
    {
        pl->head = pn;
    }
    else
    {   
        pn->next = pl->head;
        pl->head = pn;
    }
    pl->size ++ ;
}

void CreateBankAccount(LinkedList* pl)
{
    Account acc;
    FillAccount(&acc) ;
    LL_voidInsertAtBeginning(&acc,pl);

}
void LL_voidPrint(LinkedList* pl)
{
    if(LL_intIsEmpty(pl))
    {
        printf("List doesn't have accounts to print\n");
    }
    else
    {
        Account* pn = pl->head;
        int i ;
        for(i=0;i<pl->size;i++)
        {
            printf("*********************************************\n");
            printf("**************** Account %d ******************\n",i+1);
            printf("*********************************************\n");
            printf("%s\n",pn->FullName);
            printf("%s\n",pn->FullAddress);
            printf("%s\n",pn->AccountStatus);
            printf("%li\n",pn->NationalId);
            printf("%d\n",pn->Age);
            printf("%li\n",pn->BankAccountId);
            printf("%d\n",pn->Guardian);
            printf("%li\n",pn->GuardianNationalId);
            printf("%li\n",pn->Balanced);
            printf("%li\n",pn->Password);
            printf("------------------------------------------------\n");

            pn=pn->next;
        }
    }
}
