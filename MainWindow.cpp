#include "mainwindow.h"
#include<stdio.h>
#include<string>
 int n=0;//표에한칸씩내려서 기록하기위해전역변수2개선언


MainWindow::MainWindow(QWidget *parent)

{

    fp=fopen("test.txt","w");//파일을텍스트파일로저장하기위해 열음
    this->Push3=new QPushButton;//헤더에서기능을사용하기위해선언한것들을동적할당시켜준다.
    this->Push2=new QPushButton;
    this->Push=new QPushButton;
    this->testlabel2=new QLabel;
    this->testlabel3=new QLabel;
    this->testlabel=new QLabel;
    this ->mainlayout=new QGridLayout;
    this->view=new QTableView;
    this->model=new QStandardItemModel(0,2,this);
    this->setLayout(mainlayout);
    this->Line=new QLineEdit;
    this->Line2=new QLineEdit;

    model->setHorizontalHeaderItem(0,new QStandardItem(QString("name")));//표의가로축에이름을붙여준다.
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("number")));
    view->setModel(model);
    view->show();//표를보여준다.
    testlabel->setText("phonenumber book");
    testlabel2->setText("name");
    testlabel3->setText("phonenumber");//어떤빈칸에무엇을써넣을지 알려주기위해 위젯안에넣어준다.
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);


    connect(Push, SIGNAL(clicked()), this,SLOT(okclick()));//어떤버튼을눌렀을때어떤함수에들어갈지 정해준다.
    connect(Push2, SIGNAL(clicked()), this,SLOT(reset()));
    connect(Push3, SIGNAL(clicked()), this,SLOT(save()));


    Push->setText("OK");//버튼에 어떤글씨를 써넣은것이다.
    Push2->setText("reset");
    Push3->setText("save");
    mainlayout->addWidget(testlabel,0,0);//QgridLayout을이용하여 원하는좌표에글씨를써넣는다.
    mainlayout->addWidget(testlabel2,10,0);
    mainlayout->addWidget(testlabel3,30,0);
    mainlayout->addWidget(Push,10,30);
    mainlayout->addWidget(Line,10,10);
    mainlayout->addWidget(Line2,30,10);
    mainlayout->addWidget(Push2,30,30);
    mainlayout->addWidget(Push3,50,30);


}

MainWindow::~MainWindow()
{
    delete mainlayout;//동적할당을이용하여 메모리를할당하였으니 프로그램이끝나고 지워주기위해 소멸자에서delete시켜준다.
    delete testlabel;
    delete testlabel2;
    delete testlabel3;
    delete Push;
    delete Push2;
    delete Push3;
    delete view;
    delete model;
    delete Line;
    delete Line2;





}
void MainWindow::okclick()//ok버튼을눌렀을때들어오는 함수이다.
{


    QStandardItem * firstslow=new QStandardItem(Line->text());//버튼을 누르면 빈칸에있는내용을 표에옮기기위해 빈칸인Line의값을텍스트해주어서 표에옮긴다.
    model->setItem(n,0,firstslow);
    QStandardItem * secondslow=new QStandardItem(Line2->text());
    model->setItem(n,1,secondslow);\
    fprintf(fp,"%s %s\n",model->item (n,0)->text().toUtf8().constData(),model->item (n,1)->text().toUtf8().constData());//또한 이값을텍스트파일에저장하도록입력해준다.



    n++;//한번쓰고 그다음에입력할때는 표의아래칸에 채워지도록 전역변수를 위에처럼위치값으로 설정해주고 수행할때마다 하나씩더해준다.
    Line->setText("");//ok버튼을 눌러표에채워넣고 Line을 다시빈칸으로둬준다.
    Line2->setText("");

}

void MainWindow::reset()//가장최근표에넣은 것 을지워주기위한함수
{
    n--;//우선전에값을 지워야함으로n을하나 빼준다.
    QStandardItem * firstslow=new QStandardItem(QString(""));//그후빈칸으로 만든다.
    model->setItem(n,0,firstslow);
    QStandardItem * secondslow=new QStandardItem(QString(""));
    model->setItem(n,1,secondslow);\

}
void MainWindow::save()//마지막으로 저장버튼을 누르면프로그램이종료되도록한다.
{
    close();
    fclose(fp);


}
