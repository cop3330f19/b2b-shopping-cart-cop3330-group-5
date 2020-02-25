//product.cpp
//Group 5- iyesha gonzalez
//2/22/20
//file that prints product information

#include "Product.h"
#include "Inventory.dat"
#include <iomanip>
using namespace std;
 
Product::Product(){ // declare the Inventory object using the default constructor
    itemNo=0;
    description="";
    price=0.00;
    stockQuantity=0;
}


 Product::Product(int newItemNo, int newQuantity, double newPrice, string desc) 
    {
        itemNo = newItemNo;
        stockQuantity = newQuantity;
        price = newPrice;
        description=desc;
        
    }

    // Set product's item number
    void Product::setItemNo(int newItemNo)  {itemNo = newItemNo;}
    
    
    // Sets stock quantity and if negative, defaults to zero.
    void Product::setStockQuantity(int newQuantity)	
    {
        if (newQuantity >0)
        { stockQuantity = newQuantity; }
        else{stockQuantity=0.0;}    
    }


    // Set price of a product and defaults it to zero if negative.
    void Product::setPrice(double newPrice)  
    {
        if(newPrice>0.00)
        {price = newPrice;}
        else{price=0.00;}
    }

    // Set name of a product 
    void Product::setDescription(string desc) {description=desc;}
    
    

    // Get the product's item number
    int Product::getItemNo() {return itemNo;}

    //gets the products stock quantity
    int Product::getStockQuantity()   {return stockQuantity;}
    
    // Get the product's price
    double Product::getPrice()   {return price;}
    
    // Get the product's name
    string Product::getDescription() {return description;}




