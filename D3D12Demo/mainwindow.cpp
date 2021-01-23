#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "D3D12Module/d3dx12widget.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    D3DX12Widget* Widget = new D3DX12Widget(this);
    setCentralWidget(Widget);
    Widget->initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}
