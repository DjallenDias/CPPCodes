#ifndef ARTISTA_HPP
#define ARTISTA_HPP

#include <string>
using std::string;

/**
* @brief Classe que representa um artista.
*
* A classe artista mantem informacoes
* sobre o nome e idade do artista
*/
class artista {
    string nome_do_artista;
    int idade_do_artista;

public:

    /**
    * @brief Construtor padrao que inicializa um artista.
    *
    * Inicializa as variáveis com valores pré-definidos
    */
    artista();

    /**
    * @brief Retorna o nome do artista
    *
    * @return const string - nome do artista
    */
    const string get_nome() const noexcept;

    /**
    * @brief Retorna a idade do artista
    *
    * @return int - idade do artista
    */
    int get_idade() const noexcept;

    /**
    * @brief Altera o nome do artista
    *
    * @param string nome - nome a ser inserido
    */
    void set_nome(const string& nome) noexcept;

    /**
    * @brief Altera a idade do artista
    *
    * @param int idade - idade a ser inserida
    */
    void set_idade(int idade);


    /**
    * @brief Compara dois artistas pela idade
    *
    * @param artista outro_artista - artista com qual haverá comparação
    *
    * @return this->idade_do_artista < outro_artista.idade_do_artista
    */
    bool operator < (const artista& outro_artista);

    /**
    * @brief Verifica se a idade de dois artistas são iguais
    *
    * @param artista outro_artista - artista com qual haverá comparação
    *
    * @return this->idade_do_artista == outro_artista.idade_do_artista
    */
    bool operator == (const artista& outro_artista);
};

#endif // ARTISTA_HPP
