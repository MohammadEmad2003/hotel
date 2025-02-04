#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStackedWidget>
#include <QMessageBox>
#include <QMap>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QVariant>
#include <QList>
#include <QDir>
#include <QCoreApplication>
#include "structs.cpp"

class SQLite {
    QSqlDatabase db;
public:
    SQLite()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QString dbPath = QCoreApplication::applicationDirPath() + "/hotel_system.db";
        db.setDatabaseName(dbPath);

        qDebug() << "Database Path: " << dbPath;
        if (!db.open()) {
            qDebug() << "Error: Could not open database! " << db.lastError().text();
            return;
        }
        qDebug() << "Database opened successfully!";
    }
    ~SQLite()
    {
        if (db.isOpen()) {
            db.close();
        }
        qDebug() << "Database connection closed and removed.";
    }
};

class SQLiteAuthentication : public SQLite {
private:
    QString email;
    QString password;
public:
    void authenticate(QString& email, QString& password, QStackedWidget *mainWindow, QStackedWidget *subWindow)
    {
        if (email.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(nullptr, "Login Error", "Please fill in all fields.");
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT state FROM Authentication WHERE email = :email AND password = :password");
        query.bindValue(":email", email);
        query.bindValue(":password", password);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Database Error", "Failed to query the database: " + query.lastError().text());
            return;
        }
        if (query.next()) {
            QString role = query.value("state").toString();
            mainWindow->setCurrentIndex(1);

            if (role == "Manager") {
                subWindow->setCurrentIndex(0);
            } else if (role == "Receptionist") {
                subWindow->setCurrentIndex(4);
            } else if (role == "RoomService") {
                subWindow->setCurrentIndex(1);
            } else if (role == "Customer") {
                subWindow->setCurrentIndex(2);
            }
        } else {
            QMessageBox::warning(nullptr, "Login Error", "Invalid email or password.");
        }
    }
};

class SQLiteCustomers : public SQLite {
private:
    QMap<QString, customer> customers;

public:
    SQLiteCustomers() {
        QSqlQuery query;
        query.prepare("SELECT name, phone, email, room_number, check_in_date, check_out_date, "
                      "services_bill, employee_email, total_bill FROM Customers");

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
        }

        while (query.next()) {
            customer customerData;
            QString email = query.value(2).toString();

            customerData.name = query.value(0).toString();
            customerData.phone = query.value(1).toString();
            customerData.email = email;
            customerData.roomNumber = query.value(3).toInt();
            customerData.checkInDate = query.value(4).toDate();
            customerData.checkOutDate = query.value(5).toDate();
            customerData.serviceBill = query.value(6).toInt();
            customerData.employeeMail = query.value(7).toString();
            customerData.totalBill = query.value(8).toDouble();

            customers[email] = customerData;
        }
    }

    bool updateCustomerData(const customer& customerData) {
        QSqlQuery query;

        query.prepare("UPDATE Customers "
                      "SET name = :name, phone = :phone, room_number = :room_number, "
                      "check_in_date = :check_in_date, check_out_date = :check_out_date, "
                      "services_bill = :services, employee_email = :employee_email, total_bill = :total_bill "
                      "WHERE email = :email");

        query.bindValue(":name", customerData.name);
        query.bindValue(":phone", customerData.phone);
        query.bindValue(":room_number", customerData.roomNumber);
        query.bindValue(":check_in_date", customerData.checkInDate);
        query.bindValue(":check_out_date", customerData.checkOutDate);
        query.bindValue(":services", customerData.serviceBill);
        query.bindValue(":employee_email", customerData.employeeMail);
        query.bindValue(":total_bill", customerData.totalBill);
        query.bindValue(":email", customerData.email);

        if (!query.exec()) {
            qDebug() << "Error updating customer data:" << query.lastError().text();
            return false;
        } else {
            qDebug() << "Customer data updated successfully!";
            return true;
        }
    }
    customer getCustomerData(const QString& email) {
        if (customers.contains(email)) {
            return customers[email];
        } else {
            return customer();
        }
    }
};

class SQLiteRooms : public SQLite  {
private:
    QMap<int, rooms> roomsData;

public:
    SQLiteRooms() {
        QSqlQuery query;
        query.prepare("SELECT room_number, size, number_of_persons, price_per_night, availability FROM Rooms");

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
        }

        while (query.next()) {
            rooms roomData;
            roomData.room_number = query.value(0).toInt();
            roomData.size = query.value(1).toString();
            roomData.numberOfPersons = query.value(2).toInt();
            roomData.price = query.value(3).toInt();
            roomData.status = query.value(4).toString();

            roomsData[roomData.room_number] = roomData;
        }
    }

    bool updateRoomData(const rooms& roomData) {
        QSqlQuery query;
        query.prepare("UPDATE Rooms "
                      "SET size = :size, number_of_persons = :number_of_persons, "
                      "price_per_night = :price_per_night, availability = :availability "
                      "WHERE room_number = :room_number");

        query.bindValue(":size", roomData.size);
        query.bindValue(":number_of_persons", roomData.numberOfPersons);
        query.bindValue(":price_per_night", roomData.price);
        query.bindValue(":availability", roomData.status);
        query.bindValue(":room_number", roomData.room_number);

        if (!query.exec()) {
            qDebug() << "Error updating room data:" << query.lastError().text();
            return false;
        } else {
            qDebug() << "Room data updated successfully!";
            return true;
        }
    }

    rooms getRoomData(int roomNum) {
        if (roomsData.contains(roomNum)) {
            return roomsData[roomNum];
        } else {
            return rooms();
        }
    }
};

class SQLiteServices : public SQLite {
private:
    QMap<int, services> servicesData;

public:
    SQLiteServices() {
        QSqlQuery query;
        query.prepare("SELECT id, email, room_number, service_type, service_price, is_done FROM Services");

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        while (query.next()) {
            services serviceData;
            serviceData.id = query.value(0).toInt();
            serviceData.email = query.value(1).toString();
            serviceData.room_number = query.value(2).toInt();
            serviceData.serviceType = query.value(3).toString();
            serviceData.price = query.value(4).toDouble();
            serviceData.is_done = query.value(5).toBool();

            servicesData[serviceData.id] = serviceData;
        }
    }

    void addServiceData(const services& serviceData) {
        QSqlQuery query;
        query.prepare("INSERT INTO Services (email, room_number, service_type, service_price, is_done) "
                      "VALUES (:email, :room_number, :service_type, :service_price, :is_done)");

        query.bindValue(":email", serviceData.email);
        query.bindValue(":room_number", serviceData.room_number);
        query.bindValue(":service_type", serviceData.serviceType);
        query.bindValue(":service_price", serviceData.price);
        query.bindValue(":is_done", serviceData.is_done);

        if (!query.exec()) {
            qDebug() << "Error adding new service data:" << query.lastError().text();
            return;
        } else {
            qDebug() << "New service data added successfully!";
            // Update local map
            int newId = query.lastInsertId().toInt();
            services newService = serviceData;
            newService.id = newId;
            servicesData[newId] = newService;
            return;
        }
    }

    bool updateServiceData(const services& serviceData) {
        QSqlQuery query;
        query.prepare("UPDATE Services "
                      "SET email = :email, room_number = :room_number, service_type = :service_type, service_price = :service_price, is_done = :is_done "
                      "WHERE id = :id");

        query.bindValue(":email", serviceData.email);
        query.bindValue(":room_number", serviceData.room_number);
        query.bindValue(":service_type", serviceData.serviceType);
        query.bindValue(":service_price", serviceData.price);
        query.bindValue(":is_done", serviceData.is_done);
        query.bindValue(":id", serviceData.id);

        if (!query.exec()) {
            qDebug() << "Error updating service data:" << query.lastError().text();
            return false;
        } else {
            qDebug() << "Service data updated successfully!";
            servicesData[serviceData.id] = serviceData;
            return true;
        }
    }

    services getServiceData(int id) const {
        if (servicesData.contains(id)) {
            return servicesData[id];
        } else {
            return services();
        }
    }

    QList<services> getAllServices() const {
        return servicesData.values();
    }
};

class SQLiteEmployee : public SQLite {
private:
    QMap<QString, employee> employeeData;

public:
    SQLiteEmployee() {
        QSqlQuery query;
        query.prepare("SELECT email, name, phone, position, salary, hire_date, fire_date FROM Employee");

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        while (query.next()) {
            employee empData;
            empData.email = query.value(0).toString();
            empData.name = query.value(1).toString();
            empData.phone = query.value(2).toString();
            empData.position = query.value(3).toString();
            empData.salary = query.value(4).toDouble();
            empData.hireDate = query.value(5).toDate();
            empData.fireDate = query.value(6).toDate();

            employeeData[empData.email] = empData;
        }
    }

    bool updateEmployeeData(const employee& empData) {
        QSqlQuery query;
        query.prepare("UPDATE Employee "
                      "SET name = :name, phone = :phone, position = :position, "
                      "salary = :salary, hire_date = :hire_date, fire_date = :fire_date "
                      "WHERE email = :email");

        query.bindValue(":name", empData.name);
        query.bindValue(":phone", empData.phone);
        query.bindValue(":position", empData.position);
        query.bindValue(":salary", empData.salary);
        query.bindValue(":hire_date", empData.hireDate);
        query.bindValue(":fire_date", empData.fireDate);
        query.bindValue(":email", empData.email);

        if (!query.exec()) {
            qDebug() << "Error updating employee data:" << query.lastError().text();
            return false;
        } else {
            qDebug() << "Employee data updated successfully!";
            return true;
        }
    }

    employee getEmployeeData(const QString& email) const {
        if (employeeData.contains(email)) {
            return employeeData[email];
        } else {
            return employee();
        }
    }
};

class SQLiteRevenue : public SQLite {
protected:
    QMap<QString, revenue> revenueData;

public:
    SQLiteRevenue() {
        QSqlQuery query;
        query.prepare("SELECT date, total_revenue FROM Revenue");

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        while (query.next()) {
            revenue revData;
            revData.date = query.value(0).toDate();
            revData.totalRevenue = query.value(1).toInt();

            revenueData[revData.date.toString("yyyy-MM-dd")] = revData;
        }
    }

    bool updateRevenueData(const revenue& revData) {
        QSqlQuery query;
        query.prepare("UPDATE Revenue "
                      "SET total_revenue = :total_revenue "
                      "WHERE date = :date");

        query.bindValue(":total_revenue", revData.totalRevenue);
        query.bindValue(":date", revData.date.toString("yyyy-MM-dd"));

        if (!query.exec()) {
            qDebug() << "Error updating revenue data:" << query.lastError().text();
            return false;
        } else {
            qDebug() << "Revenue data updated successfully!";
            return true;
        }
    }
    revenue getRevenueData(const QString& date) const {
        if (revenueData.contains(date)) {
            return revenueData[date];
        } else {
            return revenue();
        }
    }
};


