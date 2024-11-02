#ifndef EVENTO_HPP
#define EVENTO_HPP

#include "artista.hpp"

#include <vector>
#include <string>
using std::string;
using std::vector;

/**
* @brief Classe que representa um evento.
*
* A classe evento mantem informacoes
* sobre o nome, idade do evento e
* uma lista com os artistas do evento
* e armazena o tipo do evento
* que é alterado com base nas classes
* descendentes
*
*/
class evento {
    string nome_do_evento;
    string tipo;

protected:
    vector<artista> lista_de_artistas;
    int idade_do_evento;

public:
    /**
    * @brief Construtor padrao que inicializa um evento.
    *
    * Inicializa as variáveis com valores pré-definidos
    */
    evento();
    virtual ~evento();

    /**
    * @brief Retorna o nome do evento
    *
    * @return const string - nome do evento
    */
    const string get_nome() const noexcept;

    /**
    * @brief Retorna a idade do evento
    *
    * @return int - idade do evento
    */
    int get_idade() const noexcept;

    /**
    * @brief Retorna a lista de artistas do evento
    *
    * @return const vector<artista>& - lista de artistas do evento
    */
    vector<artista>& get_artistas() noexcept;

    /**
    * @brief Altera o nome do evento
    *
    * @param string nome - nome a ser inserido
    */
    void set_nome(const string& nome) noexcept;

    /**
    * @brief Altera a idade do evento
    *
    * @param int idade - idade a ser inserida
    */
    void set_idade(int idade);

    /**
    * @brief Altera o valor do tipo do evento
    *
    * @param string - tipo de evento
    */
    void set_tipo(const string& tipo) noexcept;

    /**
    * @brief Retorna o tipo de evento
    *
    * @return strign - tipo de evento
    */
    const string& get_tipo() const noexcept;

    /**
    * @brief Adiciona um artista à lista de artistas.
    *
    * Este método cria um novo ponteiro para um objeto do tipo evento,
    * utilizando a função virtual pura clone(), que deve ser implementada
    * pelos descendentes da classe evento (como show e exposicao).
    * A implementação de clone() retorna um ponteiro para uma cópia
    * do objeto descendente.
    * Após clonar evento, o método chama adicionar_artista() para
    * incluir o artista especificado na lista de artistas do novo evento.
    *
    * @param artista artista_inserir - artista a ser adicionado.
    *
    * @return evento* - um ponteiro para o novo evento com o artista adicionado.
    */
    evento* operator + (const artista& artista_inserir);

    /**
    * @brief Remove um artista da lista de artistas.
    *
    * Este método cria um novo ponteiro para um objeto do tipo evento,
    * utilizando a função virtual pura clone(), que deve ser implementada
    * pelos descendentes da classe evento (como show e exposicao).
    * A implementação de clone() retorna um ponteiro para uma cópia
    * do objeto descendente.
    * Após clonar evento, o método chama remover_artista() para
    * incluir o artista especificado na lista de artistas do novo evento.
    *
    * @param artista artista_remover - artista a ser removido.
    *
    * @return evento* - um ponteiro para o novo evento com o artista removido.
    */
    evento* operator - (const artista *artista_remover);

    /**
    * @brief Compara dois eventos pela idade
    *
    * @return this->idade_do_evento < outro_evento.idade_do_evento
    */
    bool operator < (const evento& outro_evento) const;

    /**
    * @brief Método virtual puro para calcular o preço do evento
    *
    * @return int - preço calculado usando a implementação das classes descendentes
    */
    virtual float calcula_preco()=0;

    /**
    * @brief Adiciona um artista a lista de artistas
    *
    * Este método virtual puro deve ser implementado por
    * todas as subclasses da classe evento.
    * Este método adiciona novos artistas na lista de artistas
    */
    virtual void adicionar_artista(const artista& artista_inserir) = 0;

    /**
    * @brief Remove um artista da lista de artistas
    *
    * Este método virtual puro deve ser implementado por
    * todas as subclasses da classe evento.
    * Este método remove artistas da lista de artistas
    */
    virtual void remover_artista(const artista *artista_inserir) = 0;

protected:
    /**
    * @brief Cria uma cópia do objeto evento.
    *
    * Este método virtual puro deve ser implementado
    * por todas as subclasses da classe evento. Ele permite que objetos
    * de tipo evento sejam clonados, possibilitando a criação de novas
    * instâncias que sejam cópias dos objetos existentes.
    *
    * @return evento* - um ponteiro para a nova instância do objeto evento.
    */
    virtual evento* clone() const = 0;

private:
    /**
    * @brief Método que ordena a lista de artistas com base na idade dos artistas
    */
    void ordena_artistas();
};

#endif // EVENTO_HPP
