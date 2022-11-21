#include<stdio.h>
int amount,purse;
void welcome();
void rules();
void snacks();
void drinks();
int selection_snacks();
int selection_drinks();
int deposit();
int cashback(int);
int shortage_deposit(int,int);
void again();
void shop_again();

int main(){
    int selection,cash;
    welcome();
    rules();
    again:
    printf("\npress 1 for snacks \npress 2 for drinks \n");
    scanf("%d",&selection);
    switch (selection)
    {
    case 1:
        snacks();
        break;
    
    case 2:
        drinks();
        break;
    default:
        printf("\nyou pressed wrong number\n");
        goto again;
    }
    cash=deposit();
    purse=cashback(cash);
    again();
    return 0;
}
void welcome(){
    for(int i=0;i<30;i++){
        printf("*");
    }
    printf("\t \t \nwelcome to vending machine \n");
    for (int i = 0; i < 30; i++)
    {
        printf("*");
    }
}
void rules(){
    printf("\nplease don't enter coins in the machine.\n");
    printf("you can buy a single type of item at a time.\n");
    printf("In case if your money get stuck inside machine please contact to 0755-658138.\n");
    printf("please don't kick or stomp the machine.\n");
    for(int i = 0 ;i<30;i++){
        printf("*");
    }
}
void snacks(){
    printf("Code\tname\t\tweight\t\tprice\n");
    printf("001\tkurkure\t\t110gm\t\t20\n");
    printf("002\tlays\t\t100gm\t\t20\n");
    printf("003\tsandwich\t200gm\t\t60\n");
    printf("004\tsoya sticks\t150gm\t\t50\n");
    amount =selection_snacks();
}
void drinks(){
    printf("Code\tname\t\tweight\t\tprice \n");
    printf("001\tsting\t\t 200ml\t\t20 \n");
    printf("002\tamul kool\t 150ml\t\t20\n");
    printf("003\tcoolberg\t 500ml\t\t60\n");
    printf("004\tpepsi\t\t 750ml\t\t50\n");
    printf("005\tnescafe latte \t 300ml\t\t45\n");
    printf("006\tred bull\t 750ml\t\t150\n");
    amount=selection_drinks();
}
int selection_snacks(){
    int code,quantity,total_amount;
    again_selection:
    printf("enter the code of your desired snack :- ");
    scanf("%d",&code);
    printf("enter the quantity :- ");
    scanf("%d",&quantity);
    if (code == 001)
    {
        total_amount=20*quantity;
        printf("your amount of %d kurkure is :- %d",quantity,total_amount);
    }
    else if (code == 002)
    {
        total_amount=20*quantity;
        printf("your amount of %d lays is :- %d",quantity,total_amount);
    }
    else if (code == 003)
    {
        total_amount=45*quantity;
        printf("your amount of %d sandwich is :- %d",quantity,total_amount);
    }
    else if (code == 004)
    {
        total_amount=50*quantity;
        printf("your amount of %d soya sticks is :- %d",quantity,total_amount);
    }
    else{
        printf("\nyou enter wrong code \n");
        goto again_selection;
    }
    return total_amount;
}
int selection_drinks(){
    int code,quantity,total_amount;
    again_selection:
    printf("enter the code of your desired drink :- ");
    scanf("%d",&code);
    printf("enter the quantity :- ");
    scanf("%d",&quantity);
    if (code == 001)
    {
        total_amount=20*quantity;
        printf("your amount of %d sting is :- %d",quantity,total_amount);
    }
    else if (code == 002)
    {
        total_amount=20*quantity;
        printf("your amount of %d amul kool is :- %d",quantity,total_amount);
    }
    else if (code == 003)
    {
        total_amount=60*quantity;
        printf("your amount of %d coolberg is :- %d",quantity,total_amount);
    }
    else if (code == 004)
    {
        total_amount=50*quantity;
        printf("your amount of %d pepsi is :- %d",quantity,total_amount);
    }
    else if (code == 005)
    {
        total_amount=45*quantity;
        printf("your amount of %d nescafe latte is :- %d",quantity,total_amount);
    }
    else if (code == 006)
    {
        total_amount=150*quantity;
        printf("your amount of %d red bull is :- %d",quantity,total_amount);
    }
    else{
        printf("\nyou enter wrong code \n");
        goto again_selection;
    }
    return total_amount;
}
int deposit(){
    int deposit;
    printf("\nplease deposit your money\n");
    scanf("%d",&deposit);
    return deposit;
}
int cashback(int cash){
    int remaining;
    remaining = amount - cash;
    if(remaining>0){
        remaining=shortage_deposit(remaining,cash);
    }
    printf("\nyou got %d amount left\n",remaining*-1);
    return remaining*-1;
}
int shortage_deposit(int remaining,int cash){
    int shortage,left;
    remaining=cash - amount;
        printf("you are short on %d amoun\nt",remaining*-1);
        printf("please deposit the remaining amount\n");
        scanf("%d",&shortage);
        remaining = (remaining*-1)-shortage;
        cash = cash+shortage;
        if (remaining>0)
        {
            shortage_deposit(remaining,cash);
        }
        else{
            return remaining;
        }   
}
void again(){
    int response;
    try_again:
    printf("press 1 if you want to buy something else\n ");
    printf("\npres 2 if you want to quit ");
    scanf("%d",&response);
    switch (response)
    {
    case 1:
        shop_again();
        break;
    case 2:
        for (int i = 0; i < 30; i++)
        {
            printf("*");
        }
        printf("\nThank you for shopping\n");
        printf("\nplease visit us again\n");
        for (int i = 0; i < 30; i++)
        {
            printf("*");
        }
        break;
    default:
        printf("you pressed wrong number");
        goto try_again;
        break;
    }
}
void shop_again(){
    int selection,cash;
    again:
    printf("\npress 1 for snacks \npress 2 for drinks \n");
    scanf("%d",&selection);
    switch (selection)
    {
    case 1:
        snacks();
        break;
    
    case 2:
        drinks();
        break;
    default:
        printf("\nyou pressed wrong number\n");
        goto again;
    }
    cash=deposit()+purse;
    cashback(cash);
    again();
}








