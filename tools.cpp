#include "window.h"
#include "ui_window.h"
#include <QPushButton>

QVector<QPushButton*> buttons;
void Window::defineBtn()
{
    buttons.push_back(ui->btn101);
    buttons.push_back(ui->btn102);
    buttons.push_back(ui->btn103);
    buttons.push_back(ui->btn104);
    buttons.push_back(ui->btn105);
    buttons.push_back(ui->btn106);
    buttons.push_back(ui->btn107);
    buttons.push_back(ui->btn108);
    buttons.push_back(ui->btn109);
    buttons.push_back(ui->btn110);
    buttons.push_back(ui->btn201);
    buttons.push_back(ui->btn202);
    buttons.push_back(ui->btn203);
    buttons.push_back(ui->btn204);
    buttons.push_back(ui->btn205);
    buttons.push_back(ui->btn206);
    buttons.push_back(ui->btn207);
    buttons.push_back(ui->btn208);
    buttons.push_back(ui->btn209);
    buttons.push_back(ui->btn210);
    buttons.push_back(ui->btn301);
    buttons.push_back(ui->btn302);
    buttons.push_back(ui->btn303);
    buttons.push_back(ui->btn304);
    buttons.push_back(ui->btn305);
    buttons.push_back(ui->btn306);
    buttons.push_back(ui->btn307);
    buttons.push_back(ui->btn308);
    buttons.push_back(ui->btn309);
    buttons.push_back(ui->btn310);
}

void Window::BtnIconDisplay()
{
    SQLiteRooms roomsDB;
    auto it = buttons.begin();
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            int number = i * 100 + j;
            rooms Room = roomsDB.getRoomData(number);

            if (Room.status == "1") {
                (*it)->setIcon(QIcon(":/icons/icons/home d.png"));
            } else {
                (*it)->setIcon(QIcon(":/icons/icons/home A.png"));
            }
            it++;
        }
    }
}

void Window::SetServiceTable()
{
    SQLiteServices ServiceDB;
    QList<services> srv;
    srv = ServiceDB.getAllServices();

    QStringList headers = {"Room Number", "Service Type", "Is Done"};
    ui->serviceTable->setColumnCount(3);
    ui->serviceTable->setHorizontalHeaderLabels(headers);
    ui->serviceTable->setRowCount(srv.size());

    for (int i = 0; i < srv.size(); ++i) {
        services currentService = srv[i];
        ui->serviceTable->setItem(i, 0, new QTableWidgetItem(QString::number(currentService.room_number)));
        ui->serviceTable->setItem(i, 1, new QTableWidgetItem(currentService.serviceType));
        QString isDoneText = currentService.is_done ? "Yes" : "No";
        QTableWidgetItem *isDoneItem = new QTableWidgetItem(isDoneText);
        QFont font;
        font.setBold(true);
        isDoneItem->setFont(font);
        isDoneItem->setForeground(Qt::white);

        if (currentService.is_done) {
            isDoneItem->setBackground(Qt::green);
        } else {
            isDoneItem->setBackground(Qt::red);
        }

        ui->serviceTable->setItem(i, 2, isDoneItem);
    }
    ui->servicesList->clear();
    for (const services &currentService : srv) {
        ui->servicesList->addItem(QString::number(currentService.room_number) + " " + currentService.serviceType);
    }
    ui->serviceTable->resizeColumnsToContents();
}

void Window::displayclientdata(QString clientEmail)
{
    SQLiteCustomers clientDB;
    customer customerData =clientDB.getCustomerData(clientEmail);
    if (!customerData.email.isEmpty()) {
        ui->customernameLbl->setText(customerData.name);
        ui->customerpersonsnumLbl->setText(customerData.phone);
        ui->customerroomnumLbl->setText(QString::number(customerData.roomNumber));
        ui->customercheckoutLbl->setText(customerData.checkOutDate.toString());
        ui->customercheckinLbl->setText(customerData.checkInDate.toString());
        ui->customertotalbillLbl->setText(QString::number(customerData.totalBill));
    }
    else{QMessageBox::warning(this, "Error", "Client not found!");
    }

}

void Window::PlotGraph(Revenue rev)
{
    QCustomPlot* plot = ui->graph;

    plot->xAxis->setLabelColor(QColor(255, 255, 255));
    plot->yAxis->setLabelColor(QColor(255, 255, 255));
    plot->xAxis->setTickLabelColor(QColor(255, 255, 255));
    plot->yAxis->setTickLabelColor(QColor(255, 255, 255));
    plot->axisRect()->setBackground(QColor(0, 0, 0, 100));
    plot->setBackground(QColor(0, 0, 0, 100));

    QVector<int> revenueData = rev.RevCalc();
    plot->xAxis->setRange(0, 12);
    plot->yAxis->setRange(0, (*std::max_element(revenueData.begin(), revenueData.end())/1000) + 10);

    QCPGraph* dataGraph = plot->addGraph();

    QVector<double> months, revenues;
    QStringList monthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; ++i) {
        months.append(i + 1);
        revenues.append(revenueData[i]/1000);
    }

    dataGraph->setData(months, revenues);
    dataGraph->setLineStyle(QCPGraph::lsLine);
    dataGraph->setPen(QPen(Qt::cyan));
    dataGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    plot->xAxis->setLabel("Month");
    plot->yAxis->setLabel("Revenue (K)");

    for (int i = 0; i < 12; ++i) {
        QCPItemText* monthLabel = new QCPItemText(plot);
        monthLabel->setText(monthNames[i]);
        monthLabel->setPositionAlignment(Qt::AlignHCenter | Qt::AlignTop);
        monthLabel->position->setCoords(i + 1, -5);
        monthLabel->setFont(QFont("Arial", 10));
    }
    plot->replot();
}

void Window::displayEmployeeData(const QString& mail)
{
    SQLiteEmployee empDB;
    employee employeeData = empDB.getEmployeeData(mail);

    if (!employeeData.email.isEmpty()) {

        ui->employeeName->setText(employeeData.name);
        ui->employeePosition->setText(employeeData.position);
        ui->employeePhone->setText(employeeData.phone);
        ui->employeeEmail->setText(employeeData.email);
        qDebug() << "Employee Salary: " << employeeData.salary;
        ui->employeeSalary->setText(QString::number(employeeData.salary));
        ui->hireDate->setText(employeeData.hireDate.toString());
    } else {
        QMessageBox::warning(this, "Error", "Room not found!");
    }
}
