#include "idade_invalida_excpt.hpp"

const char* idade_invalida::what() const noexcept {
    return "Idade invalida!";
}
