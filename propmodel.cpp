#include "propmodel.h"
#include <QDebug>
#include <QFont>
#include <QBrush>

PropModel::PropModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int PropModel::rowCount(const QModelIndex &i) const
{
   return 2;
}

int PropModel::columnCount(const QModelIndex &i) const
{
    return 3;
}

QVariant PropModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
   // generate a log message when this method gets called
   qDebug() << QString("row %1, col%2, role %3")
           .arg(row).arg(col).arg(role);

   switch (role) {
   case Qt::DisplayRole:
       if (row == 0 && col == 1) return QString("<--left");
       if (row == 1 && col == 1) return QString("right-->");

       return QString("Row%1, Column%2")
               .arg(row + 1)
               .arg(col +1);
   case Qt::FontRole:
       if (row == 0 && col == 0) { //change font only for cell(0,0)
           QFont boldFont;
           boldFont.setBold(true);
           return boldFont;
       }
       break;
   case Qt::BackgroundRole:
       if (row == 1 && col == 2)  //change background only for cell(1,2)
           return QBrush(Qt::red);
       break;
   case Qt::TextAlignmentRole:
       if (row == 1 && col == 1) //change text alignment only for cell(1,1)
           return Qt::AlignRight + Qt::AlignVCenter;
       break;
   case Qt::CheckStateRole:
       if (row == 1 && col == 0) //add a checkbox to cell(1,0)
           return Qt::Checked;
       break;
   }
   return QVariant();
}

QVariant PropModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Property");
            case 1:
                return QString("Value");
            }
        }
    }
    return QVariant();
}

bool PropModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
     if (role == Qt::EditRole)
     {
         //save value from editor to member m_gridData
         //m_gridData[index.row()][index.column()] = value.toString();
         //for presentation purposes only: build and emit a joined string
         QString result;
         /*for(int row= 0; row < ROWS; row++)
         {
             for(int col= 0; col < COLS; col++)
             {
                 result += m_gridData[row][col] + " ";
             }
         }*/
         emit editCompleted( result );
     }
     return true;
}

Qt::ItemFlags PropModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}
