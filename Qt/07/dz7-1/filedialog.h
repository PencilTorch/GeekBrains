#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QObject>
#include <QFileDialog>
#include <QCheckBox>
#include <QGridLayout>

class FileDialog : public QFileDialog {
public:
    FileDialog();
    bool checkState();
private:
        QCheckBox *checkBox;
        QStringList filters;
};

#endif // FILEDIALOG_H
