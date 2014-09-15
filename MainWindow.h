#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLineEdit>// 여러가지를 선언하는 헤더파일로 qt의다양한기능을사용하기위해 필요한것들을 include시켜준다.
#include<QPushButton>
#include <QWidget>
#include<QLabel>
#include<QGridLayout>
#include<QTableView>
#include<QStandardItemModel>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>


class MainWindow : public QWidget //기능을위한함수들을묶어준클래스이다.
{
    Q_OBJECT
public slots://버튼을누르면사용될함수들을만든것이다.
    void okclick();
    void reset();
    void save();
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    QGridLayout * mainlayout;//위젯에서위치를잡아주는역활이다.
    QLabel * testlabel;//위젯의창안에뭔가를 적는역활이다.
    QLabel * testlabel2;
    QLabel * testlabel3;
    QLineEdit * Line;//빈칸을만들어주고빈칸안에적힌것을나타낸다.
    QLineEdit * Line2;
    QPushButton *  Push;//버튼을 나타낸다.
    QPushButton * Push2;
    QPushButton *  Push3;
    QTableView * view;//프로그램진행시표를보이도록하는 역이다.
    QStandardItemModel * model;//그표안에값을입력하기위한변수이다다


    FILE *fp;//파일을 저장하기위해호출한다.


};

#endif // MAINWINDOW_H
