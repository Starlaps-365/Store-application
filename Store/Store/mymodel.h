#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractItemModel>
#include<QString>

const int COLS=3;
const int ROWS=2;

class MyModel : public QAbstractItemModel
{
public:
    explicit MyModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex&parent=QModelIndex())const;
    int columnCount(const QModelIndex&parent, int role=Qt::DisplayRole)const;

    QVariant data(const QModelIndex &iindex, int role=Qt::DisplayRole)const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);     Qt::ItemFlags flags(const QModelIndex & index) const ; private:
    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView signals:
    void editCompleted(const QString &);

};

#endif // MYMODEL_H
