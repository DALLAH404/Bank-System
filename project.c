#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


/**      Author : Abdallah Mohamed Hamdy      **/
/**      SWC : Bank System                    **/  
/**      Date : 10 5 2022                    **/
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
    char Password[100];
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
void OpenExistingAccount(LinkedList* pl);





int main()
{
    LinkedList ll ;
    setList(&ll);
    int option , flag =1;

    while(flag)
    {
        printf("1- Create an account \n");
        printf("2- Open an existing account \n");
        printf("3- Reveal all accounts\n");
        printf("4- Exit \n");
        scanf("%d",&option);
        
        
        switch(option)
        {
            case 1 :
                CreateBankAccount(&ll);
                break;

            case 2 :
                OpenExistingAccount(&ll);
                break;

            case 3 :
                LL_voidPrint(&ll);
                break;

            case 4 :
                flag = 0 ;
                break;

            default:
                printf("wtf?");
        }

    }
        

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
    
    printf("Enter your password :");
    fflush(stdin);
    gets(account->Password);

}

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
    strcpy(pn->Password ,acc->Password); 
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
void OpenExistingAccount(LinkedList* pl)
{   
    
    long int AccID,AccRec,amount;
    int action,flag=1,i=0,exist=0; 
    char status[100];
    Account* sn = pl->head;
    while(flag==1)
    {
    printf("Enter Account ID : ");
    scanf("%d",&AccID);
    for(i=0;i<pl->size;i++)
    {
        if(sn->BankAccountId == AccID)
        {
            exist = 1 ;
        }
        sn = sn->next;
    }
    if(exist==0)
    {   
        printf("*******there is no such file********* \n");
        break;
    }
    printf("1- Make Transaction \n");
    printf("2- Change Account Status \n");
    printf("3- Get cash \n");
    printf("4- Deposit in Account \n");
    printf("5- Return to main menu \n");
    scanf("%d",&action);
    Account* pn = pl->head;
    Account* fn = pl->head;

    
    switch(action)
    {
        case 1:
        if(strcmp(pn->AccountStatus,"active"))
        {
            printf("sorry :( , This account can't make any process \n");
        }
        else
        {
            printf("Enter Account ID OF RECEVIER : ");
            scanf("%li",&AccRec);
            printf("Enter the amount of money : ");
            scanf("%li",&amount);
            for(i=0;i<pl->size;i++)
            {
                if(pn->BankAccountId == AccID)
                {
                    if(!strcmp(pn->AccountStatus,"active"))
                    {
                        if(pn->Balanced >= amount)
                        {
                            for(i=0;i<pl->size;i++)
                            {
                                if(fn->BankAccountId == AccRec)
                                {
                                    if(!strcmp(pn->AccountStatus,"active"))
                                    {
                                        fn->Balanced = fn->Balanced + amount ;
                                        pn->Balanced = pn->Balanced - amount ;
                                    }
                                    else
                                    {
                                        printf("This account can't make any transactions");
                                    }
                                }
                                fn=fn->next;
                            }
                        }
                    else
                        {
                        printf("you haven't enough money\n");
                        
                        }
                    }
                    else
                    {
                        printf("This account can't make any transactions\n");
                        
                    }
                }
                pn = pn->next; 
            }

            printf("DONE!!!");
        }

            break;

        case 2:
            printf("Enter the new status : ");
            fflush(stdin);
            gets(status);
            for(i=0;i<pl->size;i++)
            {
                if(pn->BankAccountId == AccID)
                {
                    strcpy(pn->AccountStatus,status);      
                    printf("DONE!!");
                }
                pn = pn->next;
            }
            
            break;

        case 3 :
        if(strcmp(pn->AccountStatus,"active"))
        {
            printf("sorry :( , This account can't make any process \n");
        }
        else
        {
            printf("Enter the amount of money : ");
            scanf("%li",&amount);
            for(i=0;i<pl->size;i++)
                {
                    if(pn->BankAccountId == AccID)
                    {
                        if(amount < pn->Balanced)
                        {
                        pn->Balanced = pn->Balanced - amount  ;  
                        printf("DONE!!");
                        }
                    }
                    pn = pn->next;
                }
        }
            
            break;

        case 4:
        if(strcmp(pn->AccountStatus,"active"))
        {
            printf("sorry :( , This account can't make any process \n");
        }
        else
        {

        printf("Enter the amount of money : ");
        scanf("%li",&amount);
        for(i=0;i<pl->size;i++)
            {
                if(pn->BankAccountId == AccID)
                {
                    pn->Balanced = pn->Balanced + amount  ;
                    printf("DONE!!\n");  
                }
                pn = pn->next;
            }
        }
            
            break;

        case 5 :
            flag = 0 ;
            break;

        default:
            printf("don't know what to do");
    }
        flag = 0;
    }
}

