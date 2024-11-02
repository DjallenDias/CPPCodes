#include "exposicao.hpp"

#include <algorithm>

exposicao::exposicao() : evento(), tipo_de_arte("") {}
exposicao::~exposicao() {}

float exposicao::calcula_preco() {
    return tipo_de_arte.length() * 1.2 * lista_de_artistas.size();
}

evento* exposicao::clone() const {
    return new exposicao(*this);
}

void exposicao::adicionar_artista(const artista& artista_inserir) {
    lista_de_artistas.push_back(artista_inserir);
}

void exposicao::remover_artista(const artista *artista_remover) {
    if (!artista_remover) return;

    lista_de_artistas.erase(
        std::remove_if(lista_de_artistas.begin(), lista_de_artistas.end(),
                       [artista_remover](const artista& a) {
                           return &a == artista_remover;
                       }),
        lista_de_artistas.end());
}

void exposicao::set_tipo_de_arte(const string& tipo_arte) {tipo_de_arte = tipo_arte;}
