#include "show.hpp"

#include <algorithm>

show::show() : evento(), genero_musical("") {}
show::~show() {}

float show::calcula_preco() {
    return genero_musical.length() * 1.6 * lista_de_artistas.size();
}

evento* show::clone() const {
    return new show(*this);
}

void show::adicionar_artista(const artista& artista_inserir) {
    lista_de_artistas.push_back(artista_inserir);
}

void show::remover_artista(const artista *artista_remover) {
    if (!artista_remover) return;

    lista_de_artistas.erase(
        std::remove_if(lista_de_artistas.begin(), lista_de_artistas.end(),
                       [artista_remover](const artista& a) {
                           return &a == artista_remover;
                       }),
        lista_de_artistas.end());
}

void show::set_genero_musical(const string &genero) {genero_musical = genero;}
