#include "BacteriaTableModel.h"

int BacteriaTableModel::rowCount(const QModelIndex& parent) const
{
    std::vector<Bacterium> all_bacteria = repo.get_bacteria();
    std::vector<std::string>studied_species = biol.get_species_studied();
    std::vector<Bacterium>output_data;
    for (Bacterium bact : all_bacteria) {
        for (auto it : studied_species)
            if (bact.get_species() == it)
                output_data.push_back(bact);
    }
    return output_data.size();
}

int BacteriaTableModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant BacteriaTableModel::data(const QModelIndex& index, int role) const
{
    if(role != Qt::DisplayRole)
    return QVariant();
    if (!index.isValid())
        return QVariant();
    std::vector<Bacterium> all_bacteria = repo.get_bacteria();
    std::vector<std::string>studied_species = biol.get_species_studied();
    std::vector<Bacterium>output_data;
    for (Bacterium bact : all_bacteria) {
        for (auto it : studied_species)
            if (bact.get_species() == it)
                output_data.push_back(bact);
    }
    int row = index.row();
    int col = index.column();
    if (row >= 0 && row < output_data.size()) {
        Bacterium current_bact = output_data[row];
        switch (col) {
        case 0:
            return QString::fromStdString(current_bact.get_name());
            break;
        case 1:
            return QString::fromStdString(current_bact.get_species());
            break;
        case 2:
        {
            std::string output = "";
            for (auto it : current_bact.get_diseases())
                output = output + it + " ";
            return QString::fromStdString(output);
            break;
        }
        case 3:
            return QString::fromStdString(current_bact.get_size());
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();
}

QVariant BacteriaTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Name");
            break;
        case 1:
            return QString("Species");
            break;
        case 2:
            return QString("Diseases");
            break;
        case 3:
            return QString("Size");
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();
}

bool BacteriaTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role != Qt::EditRole)
        return false;
    if (!index.isValid())
        return false;
    std::vector<Bacterium> all_bacteria = repo.get_bacteria();
    std::vector<std::string>studied_species = biol.get_species_studied();
    std::vector<Bacterium>output_data;
    for (Bacterium bact : all_bacteria) {
        for (auto it : studied_species)
            if (bact.get_species() == it)
                output_data.push_back(bact);
    }
    int row = index.row();
    int col = index.column();
    if (row >= 0 && row < output_data.size()) {
        // Get the original bacterium from output_data
        Bacterium bact = output_data[row];

        // Find the index in the repo's bacteria vector
        int index_in_repo = -1;
        for (int i = 0; i < repo.get_size_bact(); ++i) {
            if (repo.get_bacteria()[i] == bact) {
                index_in_repo = i;
                break;
            }
        }
        Bacterium& current_bact = repo.get_bacteria()[index_in_repo];
        // Update the bacterium in the repo
        if (index_in_repo != -1) {
            switch (col) {
            case 0:
                current_bact.set_name(value.toString().toStdString());
                break;
            case 1:
                current_bact.set_species(value.toString().toStdString());
                break;
            case 2: {
                std::string input = value.toString().toStdString();
                std::vector<std::string> new_dis;
                std::string disease;
                std::istringstream read_d(input);
                while (read_d >> disease)
                    new_dis.push_back(disease);
                current_bact.set_diseases(new_dis);
                break;
            }
            case 3:
                current_bact.set_size(value.toString().toStdString());
                break;
            default:
                break;
            }

            // Update the bacterium in the repo
           // repo.get_bacteria()[index_in_repo] = current_bact;
            // Write the updated data to file
            repo.write_to_file();

            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

Qt::ItemFlags BacteriaTableModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
