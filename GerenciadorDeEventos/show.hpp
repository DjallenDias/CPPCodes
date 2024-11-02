#ifndef SHOW_H
#define SHOW_H

#include "evento.hpp"

#include <string>
using std::string;

/**
* @brief Classe que representa um show, derivado de evento.
*
* A classe show mantem informacoes
* sobre o nome, idade do evento (show) e
* uma lista com os artistas do evento (show)
*
*/
class show : public evento {
    string genero_musical;

public:
    /**
    * @brief Construtor padrão
    *
    * Inicializa os atributos com um valor pré-definido
    */
    show();

    /**
    * @brief Destrutor padrão
    */
    ~show() override;

    /**
    * @brief Método que calcula o preço do show
    *
    * calcula o valor com base no tamanho do nome
    * e na quantidade de artistas
    *
    * @return int - preço do evento
    */
    float calcula_preco() override;

    /**
    * @brief Altera o valor do genero musical
    *
    * @param string - genero
    */
    void set_genero_musical(const string &genero);

private:
    /**
    * @brief Cria uma cópia do objeto show.
    *
    * Este método implementa a função virtual pura clone() da classe base evento,
    * permitindo a criação de um novo objeto show que é uma cópia do objeto atual.
    *
    * @return evento* - um ponteiro para o novo objeto show, que é uma cópia do objeto atual.
    */
    evento* clone() const override;

    /**
    * @brief Adiciona um artista a lista de artistas
    *
    * @param artista& artista_inserir - artista a ser adicionado
    */
    void adicionar_artista(const artista& artista_inserir) override;

    /**
    * @brief Remove um artista da lista de artistas
    *
    * @param artista& artista_inserir - artista a ser removido
    */
    void remover_artista(const artista *artista_inserir) override;
};

#endif // SHOW_H
