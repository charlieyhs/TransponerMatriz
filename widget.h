#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QStandardItemModel;

QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_numeroDeFilasSpinBox_valueChanged(int arg1);
    void on_numeroDeColumnasSpinBox_valueChanged(int arg1);
    void on_transponerPushButton_clicked();
    void on_salirPushButton_clicked();



private:
    void appendTo(QStandardItemModel *model, double value)const;
    double getValueAt(QStandardItemModel *model, int ix, int jx)const;

    Ui::Widget *ui;
    QStandardItemModel *mModelA;
    QStandardItemModel *mModelT;
};
#endif // WIDGET_H
