/*  UI List for all the Programs
 *
 *  From: https://github.com/Mysticial/Pokemon-Automation-SwSh-Arduino-Scripts
 *
 */

#include <vector>
#include "Dialogs/MainWindow.h"
#include "Programs/AllPrograms.h"
#include "ProgramDialog.h"

//#include <iostream>
//using namespace std;

ProgramDialog::ProgramDialog(MainWindow& parent)
    : m_parent(parent)
    , m_text_width(0)
{
//    setSizeAdjustPolicy(SizeAdjustPolicy::AdjustToContents);
//    setMinimumWidth();
//    setMaximumWidth(300);
//    sizeHintForRow(100);
//    sizeHintForColumn(100);

    connect(this, &QListWidget::itemClicked, this, &ProgramDialog::row_selected);
    connect(this, &QListWidget::currentRowChanged, this, &ProgramDialog::row_changed);

    QFontMetrics fm(this->font());
    for (const auto& item : PROGRAM_LIST()){
        addItem(item->name());
        m_text_width = std::max(m_text_width, fm.width(item->name()));
//        cout << m_text_width << endl;
    }
//    setMaximumWidth(m_width);
}

void ProgramDialog::row_selected(QListWidgetItem* item){
    auto iter = PROGRAM_MAP().find(item->text());
    if (iter == PROGRAM_MAP().end()){
//        std::cout << item->text().toUtf8().data() << std::endl;
        throw "Invalid program name: " + item->text();
    }

    m_parent.replace_active_program(*iter->second);
}
void ProgramDialog::row_changed(int row){
    row_selected(this->item(row));
}




