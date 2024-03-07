#pragma once
#include <qabstractitemmodel.h>
#include <algorithm>
#include "repository.h"

class BacteriaTableModel :
    public QAbstractTableModel
{
private:
    Repository& repo;
    Biologist biol;
public:
    BacteriaTableModel(Repository& rep, Biologist biol) : repo(rep), biol(biol) {
    }
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const;
};

