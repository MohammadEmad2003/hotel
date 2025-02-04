#include "cost.cpp"

class room{
private:
    SQLiteRooms roomDB;
    SQLiteCustomers clientDB;
    customer client;
    rooms rom;
public:
    room(QString email)
    {
        client = clientDB.getCustomerData(email);
        rom = roomDB.getRoomData(client.roomNumber);
    }
    void RoomCheckOut()
    {
        rom.status = '0';
        roomDB.updateRoomData(rom);
    }
};
