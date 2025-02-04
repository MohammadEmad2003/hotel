#include "room.cpp"

class Revenue : public SQLiteRevenue{
private:
    SQLiteRevenue revDB;
    revenue rev;
public:
    QVector<int> RevCalc() {
        QVector<int> monthlyRevenue(12, 0);

        for (auto it = revenueData.begin(); it != revenueData.end(); ++it) {
            QDate date = it.value().date;
            int totalRevenue = it.value().totalRevenue;
            int monthIndex = date.month() - 1;

            if (monthIndex >= 0 && monthIndex < 12) {
                monthlyRevenue[monthIndex] += totalRevenue;
            }
        }
        return monthlyRevenue;
    }
};
