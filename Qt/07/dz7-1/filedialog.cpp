#include "filedialog.h"

FileDialog::FileDialog() {
    this->setOption(QFileDialog::DontUseNativeDialog);
    this->setAcceptMode(QFileDialog::AcceptOpen);
    QGridLayout* mainLayout = qobject_cast<QGridLayout*>(this->layout());
    checkBox = new QCheckBox(tr("Открыть только для чтения"));
    mainLayout->addWidget(checkBox, 4, 1);
    filters << tr("Текстовый файл (*.txt)") << tr("Все файлы (*)");
    this->setNameFilters(filters);
}

bool FileDialog::checkState() {
    if(this->checkBox->checkState())
        return 1;
    else
        return 0;
}
