#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "artista.hpp"
#include "show.hpp"
#include "exposicao.hpp"

#include <QMessageBox>
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // utilizacao de lambda para que a funcao receba seu
    // parametro e atualize o texto corretamente
    connect(ui->radiobtn_exposicao, &QRadioButton::clicked, this, [this]() {
        atualiza_placeholder_atributo_adicional(ui->radiobtn_exposicao);
    });

    connect(ui->radiobtn_show, &QRadioButton::clicked, this, [this]() {
        atualiza_placeholder_atributo_adicional(ui->radiobtn_show);
    });

    // botoes "cadastra"
    connect(ui->btn_criar_evento, &QPushButton::clicked, this, &MainWindow::criar_evento);
    connect(ui->btn_cadastra_artista, &QPushButton::clicked, this, &MainWindow::cadastrar_artista_no_evento);

    connect(ui->table_eventos, &QTableWidget::itemClicked, this, &MainWindow::atualizar_info_evento_selecionado);

    connect(ui->btn_excluir_evento, &QPushButton::clicked, this, &MainWindow::excluir_evento_selecionado);
    connect(ui->btn_excluir_artista, &QPushButton::clicked, this, &MainWindow::excluir_artista_selecionado);

    configura_widgets();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::configura_widgets() {
    ui->table_eventos->setColumnCount(4);
    ui->table_eventos->setColumnWidth(0, 180);
    ui->table_eventos->setColumnWidth(1, 42);
    ui->table_eventos->setColumnWidth(2, 62);
    ui->table_eventos->setColumnWidth(3, 42);
    QStringList headers_eventos = {"Nome", "Idade", "Tipo", "Preço"};
    ui->table_eventos->setHorizontalHeaderLabels(headers_eventos);

    ui->table_artistas->setColumnCount(2);
    ui->table_artistas->setColumnWidth(0, 220);
    ui->table_artistas->setColumnWidth(1, 115);
    QStringList headers_artistas = {"Nome", "Idade"};
    ui->table_artistas->setHorizontalHeaderLabels(headers_artistas);

    ui->btn_criar_evento->setToolTip("Cria um evento");
    QToolTip::showText(ui->btn_criar_evento->mapToGlobal(QPoint()), "", ui->btn_criar_evento, QRect(), 300);
    ui->btn_excluir_evento->setToolTip("Remove um evento");
    QToolTip::showText(ui->btn_excluir_evento->mapToGlobal(QPoint()), "", ui->btn_excluir_evento, QRect(), 300);

    ui->btn_cadastra_artista->setToolTip("Adiciona um artista\nao evento selecionado");
    QToolTip::showText(ui->btn_cadastra_artista->mapToGlobal(QPoint()), "", ui->btn_cadastra_artista, QRect(), 300);
    ui->btn_excluir_artista->setToolTip("Remove um artista\ndo evento selecionado");
    QToolTip::showText(ui->btn_excluir_artista->mapToGlobal(QPoint()), "", ui->btn_excluir_artista, QRect(), 300);
}

void MainWindow::atualizar_info_evento_selecionado(QTableWidgetItem *item) {
    if(item->column() >= 1) return;
    limpar_tabela_artistas();

    ui->label_informacao_evento->setText(item->text());
    insesir_artistas_na_tabela_artistas();
}

bool MainWindow::verifica_inputs_artista() {
    if(ui->input_nome_artista->text().toStdString() == "") {
        QMessageBox::critical(this, "Erro", "Digite um nome");
        return false;
    }

    if(ui->input_idade_artista->text().toStdString() == ""){
        QMessageBox::critical(this, "Erro", "Digite uma idade");
        return false;
    }

    return true;
}

void MainWindow::cadastrar_artista_no_evento() {
    if(!verifica_inputs_artista()) return;

    const string& nome_evento = ui->label_informacao_evento->text().toStdString();
    evento *ev = obter_evento_pelo_nome(nome_evento);

    if(!ev) return;

    artista a;
    string nome = ui->input_nome_artista->text().toStdString();
    int idade = ui->input_idade_artista->text().toInt();

    a.set_nome(nome);

    try {
        a.set_idade(idade);
    } catch(std::exception *e) {
        QMessageBox::critical(this, "Erro", QString::fromStdString(e->what()));
        return;
    }

    ev->adicionar_artista(a);

    limpar_tabela_artistas();
    insesir_artistas_na_tabela_artistas();
    limpar_tabela_eventos();
    inserir_itens_na_tabela_eventos();
    limpa_inputs_pelo_nome("artista");
}

void MainWindow::insesir_artistas_na_tabela_artistas() {
    const string& nome_evento = ui->label_informacao_evento->text().toStdString();
    evento *ev = obter_evento_pelo_nome(nome_evento);

    if(!ev) return;

    const vector<artista>& artistas = ev->get_artistas();
    int artistas_count = artistas.size();

    for(int i = 0; i < artistas_count; i++) {
        artista a = artistas[i];
        ui->table_artistas->insertRow(i);

        QString nome = QString::fromStdString(a.get_nome());
        QString idade = QString::number(a.get_idade());

        ui->table_artistas->setItem(i, 0, new QTableWidgetItem(nome));
        ui->table_artistas->setItem(i, 1, new QTableWidgetItem(idade));
    }
}

void MainWindow::limpar_tabela_artistas() {
    int row_count = ui->table_artistas->rowCount();
    for(int i = row_count; i >= 0; i--) {
        ui->table_artistas->removeRow(i);
    }
}

bool MainWindow::verifica_inputs_evento() {
    if(ui->input_nome_evento->text().toStdString() == "") {
        QMessageBox::critical(this, "Erro", "Digite um nome");
        return false;
    }

    if(ui->input_idade_evento->text().toStdString() == "") {
        QMessageBox::critical(this, "Erro", "Digite uma idade");
        return false;
    }

    if(ui->radiobtn_exposicao->isChecked() || ui->radiobtn_show->isChecked()) {
        if(ui->input_atributo_adicional->text().toStdString() == "") {
            QString atributo = ui->input_atributo_adicional->placeholderText();
            QString mensagem = "Digite o " + atributo;
            QMessageBox::critical(this, "Erro", mensagem);
            return false;
        }
    }

    return true;
}

void MainWindow::criar_evento() {
    if(!verifica_inputs_evento()) return;

    string nome_evento = ui->input_nome_evento->text().toStdString();
    int idade_evento = ui->input_idade_evento->text().toInt();
    string atributo_adicional = ui->input_atributo_adicional->text().toStdString();
    string tipo = ui->input_atributo_adicional->placeholderText().toStdString();
    tipo = (tipo == "Genero Musical") ? "Show" : "Exposicao";

    if(ui->radiobtn_exposicao->isChecked()) {
        class exposicao *e = new class exposicao;
        e->set_tipo(tipo);
        e->set_tipo_de_arte(atributo_adicional);
        e->set_nome(nome_evento);

        try {
            e->set_idade(idade_evento);
        } catch(std::exception *e) {
            QMessageBox::critical(this, "Erro", QString::fromStdString(e->what()));
            delete e;
            return;
        }

        ger_eventos.adicionar_evento(*e);

    } else if(ui->radiobtn_show->isChecked()) {
        class show *s = new class show;
        s->set_tipo(tipo);
        s->set_genero_musical(atributo_adicional);
        s->set_nome(nome_evento);

        try {
            s->set_idade(idade_evento);
        } catch(std::exception *e) {
            QMessageBox::critical(this, "Erro", QString::fromStdString(e->what()));
            delete s;
            return;
        }

        ger_eventos.adicionar_evento(*s);

    } else {
        QMessageBox::critical(this, "Erro", "Marque ao menos uma opção");
        return;
    }

    limpar_tabela_eventos();
    inserir_itens_na_tabela_eventos();
    limpa_inputs_pelo_nome("evento");
}

void MainWindow::inserir_itens_na_tabela_eventos() {
    int eventos_count = ger_eventos.eventos().size();

    for(int i = 0; i < eventos_count; i++) {
        evento *ev = ger_eventos.eventos()[i];
        ui->table_eventos->insertRow(i);

        QString nome = QString::fromStdString(ev->get_nome());
        QString idade = QString::number(ev->get_idade());
        QString tipo = QString::fromStdString(ev->get_tipo());
        QString preco = QString::number(ev->calcula_preco());

        ui->table_eventos->setItem(i, 0, new QTableWidgetItem(nome));
        ui->table_eventos->setItem(i, 1, new QTableWidgetItem(idade));
        ui->table_eventos->setItem(i, 2, new QTableWidgetItem(tipo));
        ui->table_eventos->setItem(i, 3, new QTableWidgetItem(preco));
    }
}

void MainWindow::limpar_tabela_eventos() {
    int row_count = ui->table_eventos->rowCount();
    for(int i = row_count; i >= 0; i--) {
        ui->table_eventos->removeRow(i);
    }
}

void MainWindow::excluir_artista_selecionado() {
    string nome_evento = ui->label_informacao_evento->text().toStdString();
    evento* ev = obter_evento_pelo_nome(nome_evento);

    if(!ev) return;

    QList<QTableWidgetItem *> lista_itens_selecionados = ui->table_artistas->selectedItems();

    if(lista_itens_selecionados.isEmpty()) return;

    QTableWidgetItem *item = lista_itens_selecionados.first();

    string nome_artista = item->text().toStdString();

    auto at = obter_artista_pelo_nome(nome_artista);

    ev->remover_artista(at);
    limpar_tabela_artistas();
    inserir_itens_na_tabela_eventos();
}

void MainWindow::excluir_evento_selecionado() {
    string nome_evento = ui->label_informacao_evento->text().toStdString();
    evento* ev = obter_evento_pelo_nome(nome_evento);

    if(!ev) return;

    ger_eventos.remover_evento(ev);

    limpa_label_info_evento();
    limpar_tabela_eventos();
    limpar_tabela_artistas();
    inserir_itens_na_tabela_eventos();
}

void MainWindow::limpa_label_info_evento() {
    ui->label_informacao_evento->setText("");
}

void MainWindow::limpa_inputs_pelo_nome(const string& nome_input) {
    if(nome_input == "evento") {
        ui->input_nome_evento->setText("");
        ui->input_idade_evento->setText("");
        ui->input_atributo_adicional->setText("");
    } else if(nome_input == "artista") {
        ui->input_nome_artista->setText("");
        ui->input_idade_artista->setText("");
    }
}

void MainWindow::atualiza_placeholder_atributo_adicional(QRadioButton *btn) {
    QString placeholdertext = (btn->text() == "Show") ? "Genero Musical" : "Tipo de Arte";
    ui->input_atributo_adicional->setPlaceholderText(placeholdertext);
}

artista *MainWindow::obter_artista_pelo_nome(const string& nome_artista) {
    string nome_evento = ui->label_informacao_evento->text().toStdString();
    evento* ev = obter_evento_pelo_nome(nome_evento);

    vector<artista>& artistas = ev->get_artistas();

    auto it = std::find_if(artistas.begin(), artistas.end(),
                           [&nome_artista](const artista& a) {
                               return a.get_nome() == nome_artista;
                           }
                        );

    if(it != artistas.end()) return &(*it);
    return NULL;
}

evento *MainWindow::obter_evento_pelo_nome(const string& nome_evento) {
    const vector<evento*>& eventos = ger_eventos.eventos();

    auto it = std::find_if(eventos.begin(), eventos.end(),
                           [&nome_evento](const evento *ev) {
                               return ev->get_nome() == nome_evento;
                           }
                        );

    if(it != eventos.end()) return *it;

    return NULL;
}
