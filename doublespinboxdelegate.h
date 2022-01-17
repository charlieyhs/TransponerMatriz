#ifndef DOUBLESPINBOXDELEGATE_H
#define DOUBLESPINBOXDELEGATE_H

#include <QItemDelegate>
#include <QObject>

class DoubleSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit DoubleSpinBoxDelegate(QObject *parent = nullptr);

protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // DOUBLESPINBOXDELEGATE_H
