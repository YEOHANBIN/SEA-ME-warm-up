#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , contactList(new contact_list(this))
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    connect(ui->add_pButton, &QPushButton::clicked, this, &MainWindow::onAddContact);
    connect(ui->remove_pButton, &QPushButton::clicked, this, &MainWindow::onRemoveContact);
    connect(ui->search_pButton, &QPushButton::clicked, this, &MainWindow::onSearchContact);
    connect(ui->save_pButton, &QPushButton::clicked, this, &MainWindow::onSaveContacts);
    connect(ui->load_pButton, &QPushButton::clicked, this, &MainWindow::onLoadContacts);


    ui->contact_listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddContact(){
    QString name = ui->name_line->text();
    QString number = ui->number_line->text();
    QString email = ui->email_line->text();
    QString nickname = "";

    if(!name.isEmpty() && !number.isEmpty()){
        Contact *nContact = new Contact(this,name, number, email, nickname);
        contactList->add_contact(nContact);

        QStandardItem *item = new QStandardItem(name);
        item->setData(QVariant::fromValue(static_cast<void*>(nContact)));
        model->appendRow(item);

        ui->name_line->clear();
        ui->number_line->clear();
        ui->email_line->clear();
        //ui->nicknameLineEdit->clear();
    }
}

void MainWindow::onRemoveContact(){
    QString name = ui->name_line->text();
    if(!name.isEmpty()){
        contactList->remove_contact(name);

        QList<QStandardItem *> items = model->findItems(name, Qt::MatchExactly);
        for (QStandardItem *item : items) {
            model->removeRow(item->row());
        }
    }
}

void MainWindow::onSearchContact(){
    QString name = ui->name_line->text();
    Contact *foundContact = contactList->search_contact(name);

    if (foundContact) {
        ui->number_line->setText(foundContact->getNumber());
        ui->email_line->setText(foundContact->getEmail());
        //ui->nickname_line->setText(foundContact->getNickname());

        // Optionally, highlight the found contact in the QListView
        QList<QStandardItem *> items = model->findItems(name, Qt::MatchExactly);
        if (!items.isEmpty()) {
            ui->contact_listView->setCurrentIndex(items.first()->index());
        }
    } else {
        // Optionally clear the fields if no contact is found
        ui->number_line->clear();
        ui->email_line->clear();
        //ui->nickname_line->clear();
    }
}

void MainWindow::onSaveContacts(){
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Contacts"), "", tr("Text Files (*.txt)"));
    if(!filePath.isEmpty()){
        if(contactList->save_file(filePath)){
            QMessageBox::information(this, tr("Success"), tr("File saved successfully."));
        }
        else{
            QMessageBox::warning(this, tr("Error"), tr("Failed to save file."));
        }
    }
}

void MainWindow::onLoadContacts(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Save Contacts"), "", tr("Text Files (*.txt)"));
    if(!filePath.isEmpty()){
        contactList->load_file(filePath);

        model->clear();

        for(Contact* contact : contactList->getContacts()){
            QStandardItem *item = new QStandardItem(contact->getName());
            item->setData(QVariant::fromValue(static_cast<void*>(contact)));
            model->appendRow(item);
        }
    }
}
