#include<iostream>
#include<string>
#include<vector>
#include <iomanip>

template <typename T> class Item{
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        Item(T n, T e, T c, int q){
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
template<typename T> class Inventory{
    private:
        std::vector<Item<T>> items;
    public:
        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
            }
        }
    void addNewItem(const Item<T>& newItem) {
        // Check if the item already exists in the inventory
        for (const auto& item : items) {
            if (item.name == newItem.name) {
                std::cout << "Item is already present in inventory." << std::endl;
                return;
            }
        }
        items.push_back(newItem);
    }

    void increaseQuantity(const T& itemName, int quantity) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.quantity += quantity;
                std::cout << "Quantity has increased: " << item.quantity << std::endl;
                return;
            }
        }

        std::cout << "Item not found in inventory." << std::endl;
    }

    void updateItem(const T& itemName, const T& newExpiration, const T& newCategory, int newQuantity) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.expiration = newExpiration;
                item.category = newCategory;
                item.quantity = newQuantity;
                std::cout << "Item " << itemName << " updated" << std::endl;
                return;
            }
        }
        throw std::runtime_error("Item not found");
    }

    void removeItem(const T& itemName) {
        auto it = std::find_if(items.begin(), items.end(), [&itemName](const Item<T>& item) {
            return item.name == itemName;
        });


        if (it != items.end()) {
            items.erase(it);
            std::cout << "Item " << itemName << " removed" << std::endl;
        } else {
            // Item not found, throw an exception
            throw std::runtime_error("Item not found");
        }
    }


    void Total() {
        std::cout << "Total Number of items in inventory = " << items.size() << std::endl;
    }


    void searchItem(const T& itemName) {
        for (const auto& item : items) {
            if (item.name == itemName) {
                std::cout << "Query for " << itemName << std::endl;
                std::cout << "Item = " << item.name << std::endl;
                std::cout << "Expiration Date = " << item.expiration << std::endl;
                std::cout << "Category= " << item.category << std::endl;
                std::cout << "Quantity= " << item.quantity << std::endl;
                return;
            }
        }
        throw std::runtime_error("Item not found!");
    }

};
template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};
template<typename T>class AppointmentSystem{
    private:
        std::vector<Appointment<T>> appointments;

    public: 
        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<ap.size();i++){
                std::cout<<std::left << std::setw(20)<<ap[i].c_name<<std::setw(15)<<ap[i].ap_date<<std::setw(15)<<ap[i].ap_time<<std::setw(15)<<ap[i].CWID<<std::endl;
            }
        }

        void schedule(const Appointment<T>& newAppointment) {
            for (const auto& appointment : appointments) {
                if (appointment.CWID == newAppointment.CWID) {
                std::cout << "You have already scheduled an appointment!!!" << std::endl;
                return;
            }
        }

        appointments.push_back(newAppointment);
        std::cout << "Appointment scheduled for: " << newAppointment.name << std::endl;
    }

        void Total_appointments(const T& date, const T& time) {
            int count = 0;
            for (const auto& appointment : appointments) {
                if (appointment.ap_date == date && appointment.ap_time == time) {
                ++count;
            }
        }
        std::cout << "Total Appointments = " << count << std::endl;
    }

        void removeRecent() {
            if (!appointments.empty()) {
                appointments.pop_back();  // Remove the last element of the vector
                std::cout << "Most recent appointment removed." << std::endl;
            } else {
                std::cout << "No appointments to remove." << std::endl;
            }
    }

};
int main(){
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total();
    try{
        i1.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
    try{
        i1.searchItem("Cerels");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
}