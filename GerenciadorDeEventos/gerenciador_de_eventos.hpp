#ifndef GERENCIADOR_DE_EVENTOS_HPP
#define GERENCIADOR_DE_EVENTOS_HPP

#include "evento.hpp"

#include <vector>
using std::vector;

/**
* @brief Classe que representa o gerenciador de eventos.
*
* O gerenciador de eventos guarda uma lista/vector de eventos
*/
class gerenciador_de_eventos {
    vector<evento*> lista_de_eventos;

public:
    /**
    * @brief Classe que representa o gerenciador de eventos.
    *
    * O gerenciador de eventos guarda uma lista/vector de eventos
    */
    gerenciador_de_eventos();

    /**
    * @brief Adiciona um evento a lista de eventos
    *
    * @param evento& evento_adicionar - evento a ser adicionado
    */
    void adicionar_evento(evento& evento_adicionar);

    /**
    * @brief Remove um evento da lista de eventos.
    *
    * @param evento *evento_remover - evento a ser removido
    */
    void remover_evento(evento *evento_remover);

    /**
    * @brief Retorna a lista de eventos
    *
    * @return const vector<evento*>& - lista de eventos
    */
    const vector<evento*>& eventos() ;

    /**
    * @brief Sobrecarga do operador +
    *
    * Adiciona um evento a lista de eventos e retorna um novo objeto
    * gerenciador de eventos com a nova lista com o evento adicionado
    *
    * @param evento& evento_adicionar - evento a ser adicionado
    *
    * @return gerenciador_de_eventos - novo objeto com o evento adicionado
    */
    gerenciador_de_eventos operator + (evento& evento_adicionar);

    /**
    * @brief Sobrecarga do operador -
    *
    * Remove um evento da lista de eventos e retorna um novo objeto
    * gerenciador de eventos com a nova lista com o evento removido
    *
    * @param evento& evento_adicionar - evento a ser removido
    *
    * @return gerenciador_de_eventos - novo objeto com o evento removido
    */
    gerenciador_de_eventos operator - (evento& evento_remover);

private:
    /**
    * @brief Ordena os eventos com base na idade deles
    */
    void ordenar_eventos();
};

#endif // GERENCIADOR_DE_EVENTOS_HPP
