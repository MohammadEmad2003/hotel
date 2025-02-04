#include "SQLite.cpp"

class service : public SQLiteServices{
private:
    SQLiteCustomers customerDatabase;
    customer customerData;
    SQLiteServices srvDB;
    services srv;
    QList<services> srvList;
public:
    void addService(QString email, QString type, int price)
    {
        customerData = customerDatabase.getCustomerData(email);
        srv.email = customerData.email;
        srv.serviceType = type;
        srv.price = price;
        srv.is_done = 0;
        srv.room_number = customerData.roomNumber;
        addServiceData(srv);
    }
    void MarkAsDone(int ind)
    {
        srvList = srvDB.getAllServices();
        srvList[ind].is_done = true;
        srvDB.updateServiceData(srvList[ind]);
    }
};
