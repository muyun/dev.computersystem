/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "dialog.h"
#include "Logic.h"
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
{
    QGroupBox *inputWidgetBox = createInputWidgets();
    QDialogButtonBox *buttonBox = createButtons();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(inputWidgetBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Upload File"));
}

void Dialog::submit()
{
    QString path = fileEditor->text();

    if (path.isEmpty()) {
        QString message(tr("Please provide the path of the file."));
        QMessageBox::information(this, tr("Upload File"), message);
    } else {

        accept();
    }
}

QGroupBox *Dialog::createInputWidgets()
{
    QGroupBox *box = new QGroupBox(tr("Upload File"));

    QLabel *typeLabel = new QLabel(tr("Type:"));
    QPushButton *browser = new QPushButton("Browse",this);
    connect(browser,SIGNAL(clicked()),this,SLOT(onBrowseClicked()));
    fileEditor = new QLineEdit;
    typeBox = new QComboBox;
    typeBox->addItems(logic->getTypes());
    isNewType = new QCheckBox("New Type?");    
    newTypeEditor = new QLineEdit;
    newTypeEditor->setEnabled(false);
    connect(isNewType,SIGNAL(clicked(bool)),newTypeEditor,SLOT(setEnabled(bool)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(fileEditor, 0, 0, 1, 4);
    layout->addWidget(browser, 0, 4);
    layout->addWidget(typeLabel, 1, 0);
    layout->addWidget(typeBox, 1, 1, 1, 4);
    layout->addWidget(isNewType, 2, 0);
    layout->addWidget(newTypeEditor, 2, 1,1,4);
    box->setLayout(layout);

    return box;
}

void Dialog::onBrowseClicked()
{
    const QString filename = QFileDialog::getOpenFileName(this);
    fileEditor->setText(filename);
}

QDialogButtonBox *Dialog::createButtons()
{
    QPushButton *closeButton = new QPushButton(tr("&Close"));
    QPushButton *submitButton = new QPushButton(tr("&Submit"));

    closeButton->setDefault(true);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));

    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(submitButton, QDialogButtonBox::ResetRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::RejectRole);

    return buttonBox;
}
