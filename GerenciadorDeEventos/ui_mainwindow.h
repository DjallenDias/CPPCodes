/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *btn_excluir_evento;
    QFormLayout *formLayout;
    QRadioButton *radiobtn_exposicao;
    QRadioButton *radiobtn_show;
    QLineEdit *input_nome_evento;
    QLineEdit *input_idade_evento;
    QLineEdit *input_atributo_adicional;
    QPushButton *btn_criar_evento;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *input_nome_artista;
    QLineEdit *input_idade_artista;
    QPushButton *btn_cadastra_artista;
    QLabel *label_informacao_evento;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_excluir_artista;
    QTableWidget *table_eventos;
    QTableWidget *table_artistas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(700, 500);
        MainWindow->setMinimumSize(QSize(700, 500));
        MainWindow->setMaximumSize(QSize(700, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(500, 400));
        centralwidget->setMaximumSize(QSize(800, 500));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_excluir_evento = new QPushButton(centralwidget);
        btn_excluir_evento->setObjectName(QString::fromUtf8("btn_excluir_evento"));
        btn_excluir_evento->setCursor(QCursor(Qt::PointingHandCursor));
        btn_excluir_evento->setAutoDefault(false);
        btn_excluir_evento->setFlat(false);

        gridLayout_2->addWidget(btn_excluir_evento, 2, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(6);
        radiobtn_exposicao = new QRadioButton(centralwidget);
        radiobtn_exposicao->setObjectName(QString::fromUtf8("radiobtn_exposicao"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radiobtn_exposicao->sizePolicy().hasHeightForWidth());
        radiobtn_exposicao->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, radiobtn_exposicao);

        radiobtn_show = new QRadioButton(centralwidget);
        radiobtn_show->setObjectName(QString::fromUtf8("radiobtn_show"));

        formLayout->setWidget(1, QFormLayout::FieldRole, radiobtn_show);

        input_nome_evento = new QLineEdit(centralwidget);
        input_nome_evento->setObjectName(QString::fromUtf8("input_nome_evento"));

        formLayout->setWidget(2, QFormLayout::FieldRole, input_nome_evento);

        input_idade_evento = new QLineEdit(centralwidget);
        input_idade_evento->setObjectName(QString::fromUtf8("input_idade_evento"));

        formLayout->setWidget(3, QFormLayout::FieldRole, input_idade_evento);

        input_atributo_adicional = new QLineEdit(centralwidget);
        input_atributo_adicional->setObjectName(QString::fromUtf8("input_atributo_adicional"));

        formLayout->setWidget(4, QFormLayout::FieldRole, input_atributo_adicional);

        btn_criar_evento = new QPushButton(centralwidget);
        btn_criar_evento->setObjectName(QString::fromUtf8("btn_criar_evento"));
        btn_criar_evento->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout->setWidget(5, QFormLayout::FieldRole, btn_criar_evento);


        gridLayout_2->addLayout(formLayout, 0, 2, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label);

        input_nome_artista = new QLineEdit(centralwidget);
        input_nome_artista->setObjectName(QString::fromUtf8("input_nome_artista"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, input_nome_artista);

        input_idade_artista = new QLineEdit(centralwidget);
        input_idade_artista->setObjectName(QString::fromUtf8("input_idade_artista"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, input_idade_artista);

        btn_cadastra_artista = new QPushButton(centralwidget);
        btn_cadastra_artista->setObjectName(QString::fromUtf8("btn_cadastra_artista"));
        btn_cadastra_artista->setCursor(QCursor(Qt::PointingHandCursor));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, btn_cadastra_artista);

        label_informacao_evento = new QLabel(centralwidget);
        label_informacao_evento->setObjectName(QString::fromUtf8("label_informacao_evento"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_informacao_evento);

        verticalSpacer = new QSpacerItem(20, 48, QSizePolicy::Policy::Maximum, QSizePolicy::Minimum);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer);


        gridLayout_2->addLayout(formLayout_2, 0, 0, 1, 1);

        btn_excluir_artista = new QPushButton(centralwidget);
        btn_excluir_artista->setObjectName(QString::fromUtf8("btn_excluir_artista"));
        btn_excluir_artista->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(btn_excluir_artista, 2, 0, 1, 1);

        table_eventos = new QTableWidget(centralwidget);
        table_eventos->setObjectName(QString::fromUtf8("table_eventos"));
        table_eventos->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        table_eventos->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        table_eventos->setTabKeyNavigation(false);
        table_eventos->setProperty("showDropIndicator", QVariant(false));
        table_eventos->setDragDropOverwriteMode(false);
        table_eventos->setSortingEnabled(true);
        table_eventos->setColumnCount(0);

        gridLayout_2->addWidget(table_eventos, 1, 2, 1, 1);

        table_artistas = new QTableWidget(centralwidget);
        table_artistas->setObjectName(QString::fromUtf8("table_artistas"));

        gridLayout_2->addWidget(table_artistas, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        btn_excluir_evento->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gerenciador de Eventos", nullptr));
#if QT_CONFIG(tooltip)
        btn_excluir_evento->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btn_excluir_evento->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        btn_excluir_evento->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        btn_excluir_evento->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        btn_excluir_evento->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        btn_excluir_evento->setText(QCoreApplication::translate("MainWindow", "Excluir", nullptr));
        radiobtn_exposicao->setText(QCoreApplication::translate("MainWindow", "Exposi\303\247\303\243o", nullptr));
        radiobtn_show->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        input_nome_evento->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nome do Evento", nullptr));
        input_idade_evento->setPlaceholderText(QCoreApplication::translate("MainWindow", "Idade do Evento", nullptr));
        btn_criar_evento->setText(QCoreApplication::translate("MainWindow", "Criar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cadastrando em:", nullptr));
        input_nome_artista->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nome do Artista", nullptr));
        input_idade_artista->setPlaceholderText(QCoreApplication::translate("MainWindow", "Idade do Artista", nullptr));
        btn_cadastra_artista->setText(QCoreApplication::translate("MainWindow", "Cadastrar", nullptr));
        label_informacao_evento->setText(QString());
        btn_excluir_artista->setText(QCoreApplication::translate("MainWindow", "Excluir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
