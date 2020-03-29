#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "propmodel.h"
#include <QDebug>
#include "spinboxdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PropModel *myModel = new PropModel(this);
    ui->tableView->setModel(myModel);
    ui->tableView->show();
    ui->tableView->update();
    SpinBoxDelegate *delegate = new SpinBoxDelegate(this);

    ui->tableView->setItemDelegateForColumn(1,delegate);

}

MainWindow::~MainWindow()
{
    delete ui;
}
