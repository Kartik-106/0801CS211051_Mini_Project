global amount
global purse
purse = 0
def welcome():
    for i in range (0,30):
        print("*",end='')
    print("\nwelcome to vending machine\n")
    for i in range (0,30):
        print("*",end='')

def rules():
    print("\nplease don't enter coins in the machine.\n")
    print("you can buy a single type of item at a time.\n")
    print("In case if your money get stuck inside machine please contact to 0755-658138.\n")
    print("please don't kick or stomp the machine.\n")
    for i in range(0,30):
        print("*",end='')

def snack():
    print("Code\tname\t\tweight\t\tprice\n")
    print("101\tkurkure\t\t110gm\t\t20\n")
    print("102\tlays\t\t100gm\t\t20\n")
    print("103\tsandwich\t200gm\t\t60\n")
    print("104\tsoya sticks\t150gm\t\t50\n")
    amount = selection_snacks()
    return amount

def selection_snacks():
    total_amount=0
    code = int(input("enter the code of your desired snack\n"))
    quantity=int(input("enter the quantity\n"))
    if code == 101:
        total_amount = 20*quantity
        print("your amount for ",quantity,"kurkure is ",total_amount)
    elif code == 102:
        total_amount=20*quantity
        print("your amount for ",quantity,"lays is ",total_amount)
    elif code == 103:
        total_amount=60*quantity
        print("your amount for ",quantity,"sandwich is ",total_amount)
    elif code == 104:
        total_amount=50*quantity
        print("your amount for ",quantity,"soya sticks is ",total_amount) 
    return total_amount

def drinks():
    print("Code\tname\t\tweight\t\tprice \n")
    print("101\tsting\t\t 200ml\t\t20 \n")
    print("102\tamul kool\t 150ml\t\t20\n")
    print("103\tcoolberg\t 500ml\t\t60\n")
    print("104\tpepsi\t\t 750ml\t\t50\n")
    print("105\tnescafe latte \t 300ml\t\t45\n")
    print("106\tred bull\t 750ml\t\t150\n")
    amount=selection_drinks()
    return amount

def selection_drinks():
    total_amount=0
    code = int(input("\nenter the code of your desired drink\n"))
    quantity=int(input("\nenter the quantity\n"))
    if code == 101:
        total_amount = 20*quantity
        print("your amount for ",quantity,"sting is ",total_amount)
    elif code == 102:
        total_amount=20*quantity
        print("your amount for ",quantity,"amul kool is ",total_amount)
    elif code == 103:
        total_amount=60*quantity
        print("your amount for ",quantity,"coolberg is ",total_amount)
    elif code == 104:
        total_amount=50*quantity 
        print("your amount for ",quantity,"pepsi is ",total_amount) 
    elif code == 105:
        total_amount=45*quantity
        print("your amount for ",quantity,"nescafe latte is ",total_amount)
    elif code == 106:
        total_amount=150*quantity
        print("your amount for ",quantity,"red bull is ",total_amount)
    return total_amount
        
def deposit():
    deposit = int(input("please deposit your money " ))
    return deposit
    
def cashback(cash,amount):
    remaining=0
    left=0
    remaining=amount-cash
    if remaining>0:
        remaining=shortage_deposit(remaining,cash)
        left=(remaining)*(-1)
    print("\nyou got ",left,"amount left in your purse")
    return left
    
def shortage_deposit(remaining,cash):
    shortage:any
    purse
    remaining=cash-amount
    print("you are short on ",remaining*-1,"amount\n")
    shortage = int(input("please deposit the  remaining amount\n"))
    remaining = (remaining*-1)-shortage
    cash=cash+shortage
    if remaining>0:
        shortage_deposit(remaining,cash)
    else:
        return remaining
        
def again(purse):
    response:any
    print("press 1 if you want to buy something else\n")
    print("press 2 if you want to quit")
    response=int(input())
    if response == 1:
        shop_again(purse)
    else:
        for i in range (0,30):
            print("*",end='')
        print("\nThank you for shopping\n")
        print("\nPlease visit us again\n")
        for i in range(0,30):
            print("*",end='')

def shop_again(purse):
    selection:any
    cash:any
    print("\npress 1 for snacks and press 2 for drinks\n")
    selection=int(input())
    if selection==1:
        amount=snack()
    else:
        amount=drinks()
    cash=deposit()+purse
    purse=cashback(cash,amount)
    again(purse)
    return 0
    
selection:any
cash:any
welcome()
rules()
print("\npress 1 for snacks and press 2 for drinks\n")
selection=int(input())
if selection==1:
    amount=snack()
else:
    amount=drinks()
cash=deposit()
purse=cashback(cash,amount)
again(purse)
