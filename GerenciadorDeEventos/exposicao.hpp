#ifndef EXPOSICAO_HPP
#define EXPOSICAO_HPP

#include "evento.hpp"

#include <string>
using std::string;

/**
* @brief Classe que representa uma exposição, derivado de evento.
*
* A classe exposição mantem informacoes
* sobre o nome, idade do evento (exposição) e
* uma lista com os artistas do evento (exposição)
*/
class exposicao : public evento {
    string tipo_de_arte;

public:
    /**
    * @brief Construtor padrão
    *
    * Inicializa os atributos com um valor pré-definido
    */
    exposicao();

    /**
    * @brief Destrutor padrão
    */
    ~exposicao() override;

    /**
    * @brief Método que calcula o preço da exposição
    *
    * calcula o valor com base no tamanho do nome
    * e na quantidade de artistas
    *
    * @return int - preço do evento
    */
    float calcula_preco() override;

    /**
    * @brief Altera o valor do tipo de arte
    *
    * @param string - tipo de arte
    */
    void set_tipo_de_arte(const string& tipo_arte);

private:
    /**
    * @brief Cria uma cópia do objeto exposicao.
    *
    * Este método implementa a função virtual pura clone() da classe base evento,
    * permitindo a criação de um novo objeto exposicao que é uma cópia do objeto atual.
    *
    * @return evento* - um ponteiro para o novo objeto exposicao, que é uma cópia do objeto atual.
    */
    evento* clone() const override;

    /**
    * @brief Adiciona um artista a lista de artistas
    *
    * @param artista - artista a ser adicionado
    */
    void adicionar_artista(const artista& artista_inserir) override;

    /**
    * @brief Remove um artista da lista de artistas
    *
    * @param artista - artista a ser removido
    */
    void remover_artista(const artista *artista_remover) override;
};

#endif // EXPOSICAO_HPP
