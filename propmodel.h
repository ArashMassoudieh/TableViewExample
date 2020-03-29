#ifndef PROPMODEL_H
#define PROPMODEL_H
#include <QAbstractTableModel>

class PropModel: public QAbstractTableModel
{
private:
    Q_OBJECT
public:
    PropModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // PROPMODEL_H
