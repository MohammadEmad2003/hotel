#include "services.cpp"

class Cost :  public SQLite{
protected:
    SQLiteCustomers customerDatabase;
    customer customerData;
public:
    Cost(QString email) {
        customerData = customerDatabase.getCustomerData(email);
    }
    virtual int calculateCost() = 0;
};

class ResidenceCost : public Cost {
private:
    SQLiteRooms roomDatabase;
    rooms roomData;
    QDate checkInDate;
    QDate checkOutDate;
public:
    ResidenceCost(QString email) : Cost(email) {}

    int calculateCost() {
        checkInDate = customerData.checkInDate;
        checkOutDate = customerData.checkOutDate;
        int stayDuration = checkInDate.daysTo(checkOutDate);
        roomData = roomDatabase.getRoomData(customerData.roomNumber);
        return roomData.price * stayDuration;
    }
};

class ServiceCost : public Cost {
private:
    QMap<QString, int> servicePrices;
    int serviceCharge;
public:
    ServiceCost(QString email, QString service) : Cost(email) {
        servicePrices["Room Clean"] = 30;
        servicePrices["Breakfast"] = 20;
        servicePrices["Lunch"] = 25;
        servicePrices["Dinner"] = 40;
        servicePrices["Drink"] = 15;
        servicePrices["Room Maintains"] = 50;
        serviceCharge = servicePrices[service];
    }
    int calculateCost() {
        return serviceCharge;
    }
    void updateServiceCost(QString Email, int price)
    {
        customerData = customerDatabase.getCustomerData(Email);
        customerData.serviceBill += price;
        customerData.totalBill += price;
        customerDatabase.updateCustomerData(customerData);
    }
};
