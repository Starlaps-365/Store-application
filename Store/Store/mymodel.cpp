#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    : QAbstractItemModel{parent}
{

}
bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole)
    {
        //save value from editor to member m_gridData
        m_gridData[index.row()][index.column()] = value.toString();         //for presentation purposes only: build and emit a joined string
        QString result;
        for(int row= 0; row < ROWS; row++)
        {
            for(int col= 0; col < COLS; col++)

            {
                result += m_gridData[row][col] + " ";
            }
        }
        //emit editCompleted( result );
    }
    return true;
}


int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QString("Row%1, Column%2")
            .arg(index.row() + 1)
            .arg(index.column() +1);
    }
    return QVariant();
}

