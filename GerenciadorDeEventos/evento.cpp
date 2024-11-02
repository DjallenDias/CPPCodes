#include "evento.hpp"
#include "idade_invalida_excpt.hpp"

#include <algorithm>

evento::evento() : nome_do_evento(""), lista_de_artistas(), idade_do_evento(0) {}
evento::~evento() {}

const string evento::get_nome() const noexcept {return nome_do_evento;}

int evento::get_idade() const noexcept {return idade_do_evento;}

vector<artista>& evento::get_artistas() noexcept {
    ordena_artistas();
    return lista_de_artistas;
}

void evento::set_nome(const string& nome) noexcept {nome_do_evento = nome;}

void evento::set_idade(int idade) {
    if(idade < 0) throw new idade_invalida();
    idade_do_evento = idade;
}

void evento::set_tipo(const string& tipo) noexcept {
    this->tipo = tipo;
}

const string& evento::get_tipo() const noexcept {
    return tipo;
}

evento* evento::operator + (const artista& artista_inserir) {
    evento* novo = this->clone();
    novo->adicionar_artista(artista_inserir);
    return novo;
}

evento* evento::operator - (const artista *artista_remover) {
    evento* novo = this->clone();
    novo->remover_artista(artista_remover);
    return novo;
}

bool evento::operator < (const evento& outro_evento) const {
    return (this->idade_do_evento < outro_evento.idade_do_evento);
}

void evento::ordena_artistas() {
    std::sort(lista_de_artistas.begin(), lista_de_artistas.end());
}
