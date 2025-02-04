#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPropertyAnimation>
#include <QSizeGrip>
#include "revenue.cpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Window;
}
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_loginBtn_clicked();
    void on_rsBtn_clicked();
    void on_ServiceOrder_clicked();
    void on_LogoutBtn_clicked();
    void on_btn101_clicked();
    void on_btn102_clicked();
    void on_btn103_clicked();
    void on_btn104_clicked();
    void on_btn105_clicked();
    void on_btn106_clicked();
    void on_btn107_clicked();
    void on_btn108_clicked();
    void on_btn109_clicked();
    void on_btn110_clicked();
    void on_btn201_clicked();
    void on_btn202_clicked();
    void on_btn203_clicked();
    void on_btn204_clicked();
    void on_btn205_clicked();
    void on_btn206_clicked();
    void on_btn207_clicked();
    void on_btn208_clicked();
    void on_btn209_clicked();
    void on_btn210_clicked();
    void on_btn301_clicked();
    void on_btn302_clicked();
    void on_btn303_clicked();
    void on_btn304_clicked();
    void on_btn305_clicked();
    void on_btn306_clicked();
    void on_btn307_clicked();
    void on_btn308_clicked();
    void on_btn309_clicked();
    void on_btn310_clicked();
    void on_searchBtn_clicked();
    void on_breakfastBrn_clicked();
    void on_lunchBtn_clicked();
    void on_dinnerBtn_clicked();
    void on_cleanRoomBtn_clicked();
    void on_roomMaintainceBtn_clicked();
    void on_drinkBtn_clicked();
    void on_reserve_clicked();
    void on_checkinBtn_clicked();
    void on_findBtn_clicked();
    void on_checkoutBtn_clicked();
    void on_exitBtn_clicked();
    void on_serviceDone_clicked();

private:
    void ExpandedWidgets();
    void defineBtn();
    void displayclientdata(QString clientEmail);
    void displayEmployeeData(const QString& mail);
    void BtnIconDisplay();
    void PlotGraph(Revenue rev);
    void setupCustomPlot();
    void displayRoom(int t);
    void SetServiceTable();
    void ErrorMassage(QString s);
    void InfoMassage(QString s);
    QPropertyAnimation *topContainerAnimation;
    QPropertyAnimation *bottomContainerAnimation;
    Ui::Window *ui;
    QString selectedFilePath;
    QPropertyAnimation *slideInAnimation;
    QPropertyAnimation *logoScaleAnimation;
    QPropertyAnimation *expandAnimation;
    QPropertyAnimation *shrinkAnimation;
    QPropertyAnimation *headerShrinkAnim;
    QPropertyAnimation *headerExpandAnim;
    QPropertyAnimation *animation;
    QPropertyAnimation *leftMenuAnimation;
    QPropertyAnimation *centerMenuAnimation;
    bool isMenuExpanded = true;
};
#endif
