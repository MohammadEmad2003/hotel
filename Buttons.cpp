#include "window.h"
#include "ui_window.h"

rooms SelectedRoom;

void Window::displayRoom(int roomNumber) {
    SQLiteRooms roomsDB;
    SelectedRoom = roomsDB.getRoomData(roomNumber);
    ui->RoomSize->setText(SelectedRoom.size);
    ui->numberOfPersons->setText(QString::number(SelectedRoom.numberOfPersons));
    ui->pricePerNight->setText(QString::number(SelectedRoom.price));
    if (SelectedRoom.status == "1") {
        ui->isReserved->setText("Occupied");
    } else {
        ui->isReserved->setText("available");
    }
}

void Window::on_exitBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

void Window::on_reserve_clicked()
{
    BtnIconDisplay();
    QDate checkIn = ui->checkin->date();
    QDate checkOut = ui->checkout->date();

    SQLiteCustomers clientDB;
    customer client = clientDB.getCustomerData(ui->mailTxt->text());
    SQLiteRooms r;
    ResidenceCost rc(ui->mailTxt->text());
    client.totalBill = rc.calculateCost();
    if(checkIn > checkOut) ErrorMassage("Invalid Check In or Check Out Date");
    else if(SelectedRoom.status == '1') ErrorMassage("This room is already in use !!");
    else
    {
        InfoMassage("Reservation Checked Successfully");
        client.checkInDate = checkIn;
        client.roomNumber = SelectedRoom.room_number;
        client.checkOutDate = checkOut;
        clientDB.updateCustomerData(client);
        SelectedRoom.status = '1';
        r.updateRoomData(SelectedRoom);
        BtnIconDisplay();
    }
}

void Window::on_serviceDone_clicked()
{
    int selectedIndex = ui->servicesList->currentIndex();
    service srv;
    srv.MarkAsDone(selectedIndex);
    SetServiceTable();
}

void Window::InfoMassage(QString s)
{
    QMessageBox::information(nullptr, "Information", s);
}

void Window::ErrorMassage(QString s)
{
    QMessageBox::critical(nullptr, "Error", s);
}

void Window::on_loginBtn_clicked()
{
    QString email = ui->mailTxt->text();
    QString password = ui->passwordTxt->text();

    SQLiteAuthentication auth;
    auth.authenticate(email, password, ui->MainWindow, ui->subWindow);
}

void Window::on_LogoutBtn_clicked()
{
    ui->MainWindow->setCurrentIndex(0);
}

void Window::on_rsBtn_clicked()
{
    ui->subWindow->setCurrentIndex(3);
}

static int lastselectedprice =0;
void Window::on_breakfastBrn_clicked()
{
    lastselectedprice=20;
    ui->servicePrice->setText( QString::number(lastselectedprice));
}

void Window::on_lunchBtn_clicked()
{
    lastselectedprice=25;
    ui->servicePrice->setText( QString::number(lastselectedprice));
}

void Window::on_dinnerBtn_clicked()
{
    lastselectedprice=40;
    ui->servicePrice->setText( QString::number(lastselectedprice));
}

void Window::on_cleanRoomBtn_clicked()
{
    lastselectedprice=30;
    ui->servicePrice->setText( QString::number(lastselectedprice));
}

void Window::on_roomMaintainceBtn_clicked()
{    lastselectedprice=50;
    ui->servicePrice->setText(QString::number(lastselectedprice));
}

void Window::on_drinkBtn_clicked()
{
    lastselectedprice=15;
    ui->servicePrice->setText( QString::number(lastselectedprice));
}

void Window::on_ServiceOrder_clicked()
{
    InfoMassage("Order Added Successfully");
    QString Email = ui->mailTxt->text();
    QString serviceType;
    switch (lastselectedprice)
    {
        case 15: serviceType = "Drink"; break;
        case 20: serviceType = "Breakfast"; break;
        case 25: serviceType = "Lunch"; break;
        case 40: serviceType = "Dinner"; break;
        case 30: serviceType = "Room Clean"; break;
        case 50: serviceType = "Room Maintains"; break;
        default: break;
    }
    ServiceCost servCost(Email, serviceType);
    int price = servCost.calculateCost();
    service srv;
    srv.addService(Email, serviceType, price);
    servCost.updateServiceCost(Email, price);
}

void Window::on_searchBtn_clicked()
{
    QString mail = ui->employeeSearch->text();
    if (mail.isEmpty()) {
        QMessageBox::warning(this, "erorr","employee is not found");
        return;
    }
    displayEmployeeData(mail);
}

void Window::on_findBtn_clicked()
{
    QString clientEmail = ui->customerEmailTxt->text();
    displayclientdata(clientEmail);
}

void Window::on_checkinBtn_clicked()
{
    QString email = ui->customerEmailTxt->text();
    if(email == "")
    {
        ErrorMassage("Please Enter valid Email");
    }
    else
    {
        SQLiteCustomers clientDB;
        customer client = clientDB.getCustomerData(email);
        InfoMassage("Client ( " + client.name + " ) Checked In Successfully");
    }
}

void Window::on_checkoutBtn_clicked()
{
    QString email = ui->customerEmailTxt->text();
    BtnIconDisplay();
    if(email == "")
    {
       ErrorMassage("Please Enter valid Email");
    }
    else
    {
        room rm(email);
        rm.RoomCheckOut();
        BtnIconDisplay();
        InfoMassage("Client Checked Out Successfully");
    }
}

void Window::on_btn101_clicked(){displayRoom(101);}
void Window::on_btn102_clicked(){displayRoom(102);}
void Window::on_btn103_clicked(){displayRoom(103);}
void Window::on_btn104_clicked(){displayRoom(104);}
void Window::on_btn105_clicked(){displayRoom(105);}
void Window::on_btn106_clicked(){displayRoom(106);}
void Window::on_btn107_clicked(){displayRoom(107);}
void Window::on_btn108_clicked(){displayRoom(108);}
void Window::on_btn109_clicked(){displayRoom(109);}
void Window::on_btn110_clicked(){displayRoom(110);}
void Window::on_btn201_clicked(){displayRoom(201);}
void Window::on_btn202_clicked(){displayRoom(202);}
void Window::on_btn203_clicked(){displayRoom(203);}
void Window::on_btn204_clicked(){displayRoom(204);}
void Window::on_btn205_clicked(){displayRoom(205);}
void Window::on_btn206_clicked(){displayRoom(206);}
void Window::on_btn207_clicked(){displayRoom(207);}
void Window::on_btn208_clicked(){displayRoom(208);}
void Window::on_btn209_clicked(){displayRoom(209);}
void Window::on_btn210_clicked(){displayRoom(210);}
void Window::on_btn301_clicked(){displayRoom(301);}
void Window::on_btn302_clicked(){displayRoom(302);}
void Window::on_btn303_clicked(){displayRoom(303);}
void Window::on_btn304_clicked(){displayRoom(304);}
void Window::on_btn305_clicked(){displayRoom(305);}
void Window::on_btn306_clicked(){displayRoom(306);}
void Window::on_btn307_clicked(){displayRoom(307);}
void Window::on_btn308_clicked(){displayRoom(308);}
void Window::on_btn309_clicked(){displayRoom(309);}
void Window::on_btn310_clicked(){displayRoom(310);}
