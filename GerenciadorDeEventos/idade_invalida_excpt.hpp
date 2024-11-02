#ifndef IDADE_INVALIDA_EXCPT_HPP
#define IDADE_INVALIDA_EXCPT_HPP

#include <exception>

/**
* @brief Classe para tratar exceções
*
* Trata as exceções de idade inválida
* e retorna um char* com a mensagem
* informando o erro
*/
class idade_invalida : public std::exception {
public:
    const char* what() const noexcept;
};

#endif // IDADE_INVALIDA_EXCPT_HPP
