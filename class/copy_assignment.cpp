#include<iostream>
#include <cstring>
using namespace std;

class product {   //by default all the attribules and methods are private 
    int id;
    char *name;
    int mrp;
    int selling_price;

    public:
    //constructor
    product() {
        cout << "we are inside the constructor" << endl;
    }

    //paramertised constructors
    product(int id, char *n, int mrp, int selling_price) {
        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // copy constructor - our own
    product(product &x){
        id = x.id;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
        mrp = x.mrp;
        selling_price = x.selling_price;
    }

    //copy assignment operation
    void operator=(product &x){
        //deep copy 
        id = x.id;
        name = new char[strlen(x.name) + 1];
        strcpy(name, x.name);
        mrp = x.mrp;
        selling_price = x.selling_price;
    }

    //setters
    void setMrp(int amt){
        mrp = amt;
    }

    void setSellingPrice(int amt){
        if(amt > mrp){
            selling_price = mrp;
            cout << "WARNING: selling price is more than the mrp, so by default mrp is set as selling price!" << endl;
        }else{
            selling_price = amt;
        }
    }

    void showDetails(){
        cout << "Id " << id << endl;
        cout << "Name " << name << endl;
        cout << "MRP " << mrp << endl;
        cout << "Selling Price " << selling_price << endl;
        cout << "------------------" << endl;
    }

    void setName(char* n) {
        strcpy(name, n);
    }

    //getters
    int getmrp(){
        return mrp;
    }

    int getSellingPrice(){
        return selling_price;
    }

};

int main() {

    product mobile(101, "iphone 11", 60000, 55000);

    //copy constructor
    product old_mobile(mobile);
    //copy assignment operator
    product new_mobile = mobile;

    old_mobile.setName("iphone X");
    old_mobile.setSellingPrice(1000);

    new_mobile.setName("iphone 12");

    mobile.showDetails();
    old_mobile.showDetails();
    new_mobile.showDetails();



    //copyconstructor - way1
    // product copyMobile1(mobile);
    // copyMobile1.showDetails();

    //copyconstructor - way2
    // product copyMboile2 = mobile;
    // copyMboile2.showDetails();


    //using setters values have inii
    // mobile.setMrp(100);
    // mobile.setSellingPrice(150);

    //using getters values have to be returned
    //cout << "mrp: " << mobile.getmrp() << endl;
    //cout << "sellingPrice: " << mobile.getSellingPrice() << endl;

    return 0;
}