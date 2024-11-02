#include "artista.hpp"
#include "idade_invalida_excpt.hpp"

artista::artista() : nome_do_artista(""), idade_do_artista(0) {}

const string artista::get_nome() const noexcept {
    return nome_do_artista;
}

int artista::get_idade() const noexcept {
    return idade_do_artista;
}



void artista::set_nome(const string& nome) noexcept {
    nome_do_artista = nome;
}

void artista::set_idade(int idade) {
    if(idade < 0) throw new idade_invalida();
    idade_do_artista = idade;
}

bool artista::operator < (const artista& outro_artista) {
    return (this->idade_do_artista < outro_artista.idade_do_artista);
}

bool artista::operator == (const artista& outro_artista) {
    return (this->idade_do_artista == outro_artista.idade_do_artista);
}
