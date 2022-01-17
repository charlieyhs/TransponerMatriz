#include "widget.h"
#include "ui_widget.h"
#include "doublespinboxdelegate.h"

#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModelA = new QStandardItemModel(this);
    mModelT = new QStandardItemModel(this);

    ui->tableViewA->setModel(mModelA);
    ui->tableViewT->setModel(mModelT);
    ui->tableViewA->setItemDelegate(new DoubleSpinBoxDelegate(this));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_numeroDeFilasSpinBox_valueChanged(int arg1)
{
    mModelA->setRowCount(arg1);
    mModelT->setColumnCount(arg1);
}

void Widget::on_numeroDeColumnasSpinBox_valueChanged(int arg1)
{
    mModelA->setColumnCount(arg1);
    mModelT->setRowCount(arg1);
}

void Widget::on_transponerPushButton_clicked()
{
    const int rowCountA = mModelA->rowCount();
    const int colCountA = mModelA->columnCount();
    const int rowCountT = mModelT->rowCount();
    const int colCountT = mModelT->columnCount();
    mModelT->clear();
    mModelT->setRowCount(rowCountT);
    mModelT->setColumnCount(colCountT);

    for(int jx = 0;jx <colCountA;jx++){
        for(int ix=0;ix<rowCountA;ix++){
            appendTo(mModelT,getValueAt(mModelA, ix,jx));
        }
    }

}

void Widget::on_salirPushButton_clicked()
{
    close();
}

void Widget::appendTo(QStandardItemModel *model, double value) const
{
    const int rowCount = model->rowCount();
    const int colCount = model->columnCount();

    for(int ix=0;ix<rowCount;ix++){
        for(int jx=0;jx<colCount;jx++){
            if(!model->item(ix,jx)){
                model->setItem(ix,jx,new QStandardItem(QString::number(value)));
                return;
            }
        }
    }
}

double Widget::getValueAt(QStandardItemModel *model, int ix, int jx) const
{
    if(!model->item(ix,jx)){
        return 0.0;
    }
    return model->item(ix,jx)->text().toDouble();
}
