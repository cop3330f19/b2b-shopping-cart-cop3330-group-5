/****************************************
 * B2B Driver File                      *
 * Group #5- Iyesha Gonzalez            *
 *           Levictoria Jackson         *
 *           Markee Davis               *
 *           James Peterson             *
 * Last Edited: 2/27/20                 *
 * Purpose:                             *
 *                                      *
 * **************************************/
 

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

/****************************************
 *                                      *
 *        FUNCTION DECLARATIONS         *
 *                                      *
 * **************************************/

vector<string> parse(string, char);
void readData(Customer[],vector<Address>&,vector<Product>&);
string upperCaseIt(string);
int binarySearch(Customer[],int); 
int linearSearch(Customer[],string);
int linearSearchAddress(vector<Address>,string);
int linearSearchInvent(vector<Product>,int);
void selectionSort(Customer[],vector<Address>&);
string generateOrderNum();

struct Address{ //structure function for address 
    string streetAddress;
    string city;
    string state;
    string zipCode;
};

struct Customer{ //structure function for customer
    string customerNum;
    string customerName;
    double lineOfCredit;
    Address * corperateAddress;
};

struct Product{ //structure function for product
    int itemNo;
    string description;
    double price;
    int stockQuantity;
};

struct Memory{ //structure function to .........
    int position;
    int quantity;
    double cartTotal;
    double remainFunds;

};

/*-----------------------------------------------------------------------------------------------------------------------------*/

int main(){
    
    Memory memObj;
    Customer cust_Info[21];  
    vector<Address>   custAdd; //customer address vector 
    vector<Product>  custProd; // customer product vector 
    vector<Memory>    custMem; //
    int numPos,prodCode,prodPos,quantity,position,ender=1,number;
    string empName,cusName,option;
    string choice,choice2,choice3,temp,temp2,temp3;
    double total,finalTotal;
    double funds;
    
    string fileName;
    fileName=generateOrderNum();    //Order number is generated
    ofstream outFile;
    outFile.open(fileName.c_str());   //Creates output file's  name by order number


    readData(cust_Info,custAdd,custProd);   //Loads Structs with file information
    selectionSort(cust_Info,custAdd);      //Sorts Customer numbers from ascending to decending 
    
    cout<<string(40,'-')<<endl;
    
    cout<<"     WELCOME TO The B2B SHOPPING CENTER"<<endl;
    cout<<string(40,'-')<<endl;
    cout<<" Did a customer place an order? Y/N:";
    getline(cin,choice);

    while( (choice!="Y") && (choice!="y") && (choice!="N") && (choice!="n")  )
    {
        cout<<"Invalid input."<<endl;
        cout<<"Did a customer place an order? Y/N:";
        getline(cin,choice);

        }
    
     if(choice=="Y" || choice== "y")
     {
         cout<<"Employee name: ";
         getline(cin,empName);
         cout<<"Would you like to search customer by Name or Number?:";
         getline(cin,option);
         option=upperCaseIt(option);                 //Fixes case sensitivity
         
         while((option!="NAME") && (option!="NUMBER"))
         {
             cout<<"Enter Name or Number of Customer:";
             getline(cin,option);
             option = upperCaseIt(option);              //Fixes case sensitivity
         }
         
         if(option=="NAME"){
             
             cout<<"Customer's Name: ";
             getline(cin,cusName);
             numPos = linearSearch(cust_Info,cusName); 
             
             while(numPos==-1){ 
                 
                 cout<<"Name not located"<<endl;
                 cout<<"Try Again"<<endl;
                 cout<<"Enter Customer's Name: ";
                 getline(cin,cusName);
                 numPos = linearSearch(cust_Info,cusName);        //Searches Customer's file for correct name then returns it's position
             }
         }
         else if(option=="NUMBER"){
             
             cout<<"Enter Customer number: ";
             getline(cin,temp);
             number=atoi(temp.c_str());
             numPos = binarySearch(cust_Info,number);
             
             while(numPos==-1){ 
                 
                 cout<<"Customer not found"<<endl;
                 cout<<"Please try again"<<endl;
                 cout<<"Enter Customer number: ";
                 getline(cin,temp);
                 number=atoi(temp.c_str());
                 numPos = binarySearch(cust_Info,number); 
             }
         }
         
         funds=cust_Info[numPos].lineOfCredit;              //Sets funds to how much credit the customer has
         cout<<"Would you like to add a product? Y/N:";
         getline(cin,choice2);
         
         while( (choice2!="Y") && (choice2!="y") && (choice2!="N") && (choice2!="n")){
             
             cout<<"Invalid input. Try again (Y/N):";
             getline(cin,choice2);
         }
         
         if((choice2=="Y") || (choice2=="y")){
             
             while(ender){
                 
                 cout<<"Product code: ";
                 getline(cin,temp2);
                 prodCode=atoi(temp2.c_str());
                 prodPos=linearSearchInvent(custProd,prodCode);
                 
                 while(prodPos==-1){  
                     
                     cout<<"Item not located"<<endl;
                     cout<<"Try Again"<<endl;
                     cout<<"Enter Product code:";
                     getline(cin,temp2);
                     prodCode=atoi(temp2.c_str());
                     prodPos = linearSearchInvent(custProd,prodCode);                //Searches Inventory file for Item then returns it's Position
                 }
                 
                 cout<<"Enter Quantity: "; 
                 cin>>quantity;
                 
                 while(cin.fail()){
                     
                     cin.clear();
                     cin.ignore(256,'\n');
                     cout<<"Quantity: ";
                     cin>>quantity;
                 }
                 
                 cin.ignore(256,'\n');
                 memObj.position=prodPos; 
                 memObj.quantity=quantity;  
                 memObj.cartTotal=custProd[memObj.position].price * memObj.quantity;
                 funds-=memObj.cartTotal;
                 
                 if(funds<=0){
                     
                     cout<<"Insuffcient funds"<<endl; 
                     funds+=memObj.cartTotal;
                 }
                 else { 
                     custMem.push_back(memObj); 
                 }
                 
                 cout<<"Would you like to add another product? (Y/N):";
                 getline(cin,choice3);
                 
                 while( (choice3!="Y") && (choice3!="y") && (choice3!="N") && (choice3!="n")  ){
                     
                     cout<<"Invalid input. Try again"<<endl;
                     cout<<"Would you like to add another product? (Y/N):";
                     getline(cin,choice3);
                 }
                 
                 if((choice3=="N") || (choice3=="n")) ender=0;
             }
         } 
         else {
             cout<<"Order Cancelled"<<endl; 
             exit(0);       //Customer does not want to order so this ends the program
         }
     } 
    else {
        cout<<"Have a Blessed Day"<<endl; exit(0);
    }
    
    
    outFile<<string(65,'-')<<endl;
    outFile<<"B2B Shopping Cart"<<endl;
    outFile<<string(65,'-')<<endl;
    
    outFile<<"Order Number: "<<fileName<<endl;
    outFile<<"Associate: "<<empName<<endl;
    outFile<<"Customer Number: "<<cust_Info[numPos].customerNum<<endl;
    outFile<<"Customer: "<<cust_Info[numPos].customerName<<endl;
    outFile<<"Address: "<<cust_Info[numPos].corperateAddress->streetAddress<<" |"<<endl;
    outFile<<cust_Info[numPos].corperateAddress->city<<", "<<cust_Info[numPos].corperateAddress->state<<" "<<cust_Info[numPos].corperateAddress->zipCode;
    outFile<<endl<<endl;
    
    outFile<< string(65,'-')<<endl;
    outFile<< setw(20) << left << "Item No" << setw(25) << left<< "Description" << setw(10)<< left << "Qty" << setw(5) << "Total" << endl;
    outFile<< string(65,'-') << endl;
    
    for(int k=0;k<custMem.size();k++)
    {
        
        position=custMem[k].position;
        finalTotal+=custMem[k].cartTotal;
        outFile<< setw(15) << left << custProd[position].itemNo << setw(30);
        outFile<< left << custProd[position].description << left << setw(10);
        outFile<< custMem[k].quantity << fixed << setprecision(2)<< "$" << custMem[k].cartTotal << endl;
    }
    
    outFile<< string(65,'-') << endl << setw(55) << left << "Total "<< fixed << setprecision(2)<< "$" << finalTotal<< endl << string(65,'-') << endl;
    outFile<< setw(55) << left << "Remaining Credit " << fixed << setprecision(2) << "$"<< funds<< endl;
    outFile<<endl<<endl<<endl;
    outFile<<string(17,' ');
    
   
    outFile.close();
    return 0;
} //end of main function
    
/*-----------------------------------------------------------------------------------------------------------------------------*/

/****************************************
 *                                      *
 *        FUNCTION DEFINITIONS          *
 *                                      *
 * **************************************/
    


void readData(Customer cInfo[], vector<Address>&cAdd, vector<Product>&pAdd){ //function that reads in customers data

        Address street;
        Customer add;
        Product product;
        vector<string> custInfo;
        vector<string> custAddress;
        vector<string> custProduct;
        ifstream file,stock;   
        file.open("customers.dat"); //opens customer data file 
        stock.open("inventory.dat"); //opens inventory data file 

    string line,location,inventory;

        int check=-1;
        int index=0;
        int pos=0;
        Address *ptr;
    
    while(!stock.eof()) { //while not at end of file
        
        getline(stock,inventory);                      //Gets full lines from inventory.dat file
        custProduct=parse(inventory,',');              //Parse the inventory to go into Product struct
        product.itemNo=atoi(custProduct[0].c_str());  //Needed to convert from string to int
        product.description=custProduct[1];
        product.price=atof(custProduct[2].c_str());   //Needed to convert from string to double
        pAdd.push_back(product);                      //Adding objects into Product  vector
    }
}

    
string generateOrderNum(){ //function to generate order number of the customer 
    time_t now = time(0);   //current time object
    string oNum;
    stringstream strstream;
    strstream << now;   //read the date/time in epoch into the string stream
    strstream >> oNum;  //output a string from string stream
    return oNum;
} //end of generated order number function

    
void selectionSort(Customer cVector[],vector<Address>&aVector){     //Sorts the customer vector by customer number (ascending)

        int minimumPos;
        Customer tempObj;
    
    for(int i=0;i<21;i++) // One by one move boundary of unsorted subarray 
    {
        // Find the minimum element in unsorted array
        minimumPos=i;    
        tempObj = cVector[i];
        
        for(int k=i+1;k<21;k++){ 
            
            // If min is greater than cVector[k] 
            if(cVector[minimumPos].customerNum>cVector[k].customerNum)
            {
                // Make cVector[k] as tempObj and update minPos
                minimumPos=k;
                tempObj = cVector[k];
            }
        }
        
        cVector[minimumPos] = cVector[i];
        cVector[i] = tempObj;
        }
} // end of selection sort function



int binarySearch(Customer cVector[],int customerNum){   //Searches customer objects for correct customer number

        int lo=0;
        int mid;
        int hi=20;
        bool state=false;

        while(lo<=hi){

                mid = (lo + hi) / 2;
            
             
            if(customerNum==atoi(cVector[mid].customerNum.c_str())) //tests to see if element is present in the middle
            {
                        state=true;return mid;break;
            }
            else if(customerNum>atoi(cVector[mid].customerNum.c_str())) //checks if the element is present in right subarray 
            {
                        lo=mid+1;

                }
            else{        //checks if the element is smaller than mid, meaning it can only be present in left subarray 
                        hi=mid-1;
                }
        }
    if(state==false)
        
        return -1;

} // end of binary search function



int linearSearch(Customer cVector[],string name){   //Searches customer objects for correct name

        int pos=-1;

        string nameObj,nameSearch;

        for(int i=0;i<21;i++){

                nameObj=upperCaseIt(cVector[i].customerName);    //Fixes case sensitivity
                nameSearch=upperCaseIt(name);                    //Fixes case sensitivity

                if(nameObj==nameSearch) pos=i;                   //If both names are equal then hold that position
        }


        if(pos!=-1) return pos;                              //Sends position of name
        else return -1;

} //end of linear search function (customer name)



int linearSearchAddress(vector<Address> aVector,string street){ //searches customer object for correct address

        int pos=-1;

        for(int i=0; i<aVector.size(); i++){
            if(aVector[i].streetAddress==street) pos = i;
        }

        return pos;
} //end of address linear search function

int linearSearchInvent(vector<Product> cVector,int code){     //Searches inventory objects for correct product numbers

        int pos=-1;

        for(int i=0;i<21;i++){
            if(cVector[i].itemNo==code) pos=i;   //If both numbers are equal then hold that position
        }
    
    if(pos!=-1) return pos;                 //Sends position of name
    else return -1;
} //end of inventory linear search function