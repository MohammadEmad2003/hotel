#include <QString>
#include <QDate>

struct employee
{
    QString email;
    QString name;
    QString phone;
    QString position;
    QDate hireDate;
    QDate fireDate;
    double salary;
};

struct customer
{
    QString email;
    QString name;
    QString phone;
    int roomNumber = 0;
    QDate checkInDate;
    QDate checkOutDate;
    int serviceBill;
    int totalBill;
    QString employeeMail;
};

struct rooms
{
    int room_number;
    QString size;
    int numberOfPersons;
    int price;
    QString status;
};

struct services
{
    QString email;
    QString serviceType;
    int id;
    bool is_done;
    int room_number;
    double price;
};

struct revenue
{
    QDate date;
    int totalRevenue;
};
