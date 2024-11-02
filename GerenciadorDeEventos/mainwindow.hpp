#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "qradiobutton.h"
#include "gerenciador_de_eventos.hpp"
#include "qtablewidget.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


/**
* @brief Classe MainWindow representa a janela
*
* ela armazena um objeto de gerenciador de eventos
* para que, com isso, possa atualizar os valores nas tabelas
* e que possa inserir eventos e artistas através dos
* widgets
*/
class MainWindow : public QMainWindow {
    Q_OBJECT
    gerenciador_de_eventos ger_eventos;

public:
    /**
    * @brief Construtor padrão
    *
    * Faz a conexão dos push buttons e das tabelas com algumas
    * determinadas métodos, além de chamar um método que configura
    * as colunas da tabela, e algumas caixas flutuantes
    * que aparecem ao passar o cursor por cima
    *
    */
    MainWindow(QWidget *parent = nullptr);

    /**
    * @brief Destrutor padrão
    */
    ~MainWindow();

private slots:
    /**
    * @brief Método que configura alguns widgets
    *
    * Configura as colunas das tabelas, como seus header labels
    * e o tamanho de cada coluna
    * além de configurar tooltips que aparecem ao passar o cursor
    * por cima de um botão
    *
    */
    void configura_widgets();

    /**
    * @brief Atualiza o placeholder do input
    *
    * Atualiza o placeholder do input de atributo adicional
    * para facilitar o uso, usando como base o
    * texto do radio button que está no parâmetro
    */
    void atualiza_placeholder_atributo_adicional(QRadioButton *btn);

    /**
    * @brief Cria um evento
    *
    * Chama a funcão que verifica se os inputs de nome, idade e atributo principal
    * Caso nenhum deles esteja vazio, ele verifica qual radio button está marcado
    * e com isso, cria o determinado objeto.
    * Após criado, os valores de nome, idade e o atributo adicional são inseridos
    * caso, ao inserir a idade, aconteça uma exceção, um message box aparece
    * informando a exceção da idade inválida, apaga o objeto que havia sido criado
    * e não faz nada.
    * Caso a idade seja inserida com sucesso, os inputs do evento são limpos
    * e a tabela de eventos é atualizada com base no vector de eventos no ger_eventos
    */
    void criar_evento();

    /**
    * @brief Inseres os eventos na tabela
    *
    * Com base no vector de eventos no ger_eventos
    * é feito um loop que percorre todo o vector e vai adicionando
    * cada informação de cada evento na tabela
    */
    void inserir_itens_na_tabela_eventos();

    /**
    * @brief Remove os itens da tabela
    *
    * Percorre cada linha da tabela e a remove
    */
    void limpar_tabela_eventos();

    /**
    * @brief Apaga o evento do vector de eventos em ger_eventos
    *
    * Chama o método de achar o evento pelo nome, e com isso
    * usa o método remover_evento() de ger_evento para remover o evento que foi retornado pelo
    * método que acha o evento pelo nome
    * Após isso, limpa o label que informa qual evento está selecionado
    * limpa a tabela de eventos e de artistas e insere novamente os eventos na tabela de eventos
    */
    void excluir_evento_selecionado();

    /**
    * @brief Limpa o texto do label informativo
    */
    void limpa_label_info_evento();

    /**
    * @brief Limpa inputs pelo valor dado
    *
    * Com base no valor dado como argumento, ele apaga os determinados inputs
    * @param string - "evento" ou "artista"
    *
    * Com isso, ou limpa os inputs de evento ou limpa os inputs de artista
    */
    void limpa_inputs_pelo_nome(const std::string& nome_input);

    /**
    * @brief Atualiza texto do label informatido
    *
    * Usando apenas a primeira coluna (nome)
    * o valor guardado no item selecionado nesta coluna
    * será utilizado para atualizar o label informativo
    * este label serve para informar onde que o
    * usuário está inserindo ou removendo artistas
    * ou até mesmo removendo eventos
    */
    void atualizar_info_evento_selecionado(QTableWidgetItem *item);

    /**
    * @brief Cadastra artista
    *
    * Após verificar os inputs de artista
    * É feita uma busca pelo evento, usando como base
    * o texto no label informativo para essa busca.
    * Ao achar o evento, são coletados os valores nos
    * inputs de artista e inseridos no objeto artista.
    * Se, ao tentar inserir a idade acontecer uma
    * exceção, um message box aparecerá
    * informando a exceção, e o artista
    * não será inserido na lista de artistas do evento
    */
    void cadastrar_artista_no_evento();

    /**
    * @brief Insere artistas na tabela
    *
    * É feita uma busca pelo evento, usando como base
    * o texto no label informativo para essa busca.
    * Ao achar o evento, o vector de artistas desse evento
    * é percorrido, e cada informação de cada artista
    * é inserido na tabela
    */
    void insesir_artistas_na_tabela_artistas();

    /**
    * @brief Limpa a tabela de artistas
    *
    * Percorre cada linha da tabela de artistas e as remove
    */
    void limpar_tabela_artistas();

    /**
    * @brief Verifica os inputs de evento
    *
    * Com base no nome selecionado na tabela de artistas
    * é feita uma busca no vetor de artistas no evento que
    * já está selecionado, e remove o artista o qual o nome for igual
    */
    void excluir_artista_selecionado();

    /**
    * @brief Verifica os inputs de evento
    *
    * Retorna true se ambos estiverem com algum valor escrito
    * Caso algum não tenha um valor escrito
    * irá aparecer um messagebox informando qual valor falta
    */
    bool verifica_inputs_evento();

    /**
    * @brief Verifica os inputs de artista
    *
    * Retorna true se ambos estiverem com algum valor escrito
    * Caso algum não tenha um valor escrito
    * irá aparecer um messagebox informando qual valor falta
    */
    bool verifica_inputs_artista();

    /**
    * @brief Retorna um evento usando o nome
    *
    * Dado o nome do evento via argumento
    * é feita uma busca linear (std::find_if) no vector de eventos
    * em ger_eventos, comparando o nome dos eventos
    * com o nome do argumento, caso o evento exista
    * é retornado seu ponteiro, caso contrário, é retornado null
    */
    evento *obter_evento_pelo_nome(const std::string& nome_evento);

    /**
    * @brief Retorna um artista usando o nome
    *
    * Dado o nome de um artista pelo argumento,
    * e com base no atual texto no label informativo
    * onde esse texto é, com certeza, o nome de um evento
    * é feita uma busca usando este valor no label e
    * passando esse valor como argumeto para obter_evento_pelo_nome().
    * Após achar o evento, é feita uma busca (std::find_if) no vector de
    * artistas que está contido no evento antes encontrado, com base
    * no nome passado via argumento, caso o artista seja encontrado
    * é retornado um ponteiro para ele, caso contrário
    * é retornado null
    *
    */
    artista *obter_artista_pelo_nome(const std::string& nome_artista);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP

