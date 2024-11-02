#include "gerenciador_de_eventos.hpp"

#include <algorithm>

gerenciador_de_eventos::gerenciador_de_eventos() : lista_de_eventos() {}

void gerenciador_de_eventos::adicionar_evento(evento& evento_adicionar) {
    lista_de_eventos.push_back(&evento_adicionar);
}

void gerenciador_de_eventos::remover_evento(evento *evento_remover) {
    auto it = std::find(lista_de_eventos.begin(), lista_de_eventos.end(), evento_remover);

    if (it != lista_de_eventos.end()) {
        delete *it;
        lista_de_eventos.erase(it);
    }
}

void gerenciador_de_eventos::ordenar_eventos() {
    std::sort(lista_de_eventos.begin(), lista_de_eventos.end(), [](evento *a, evento *b) {return *b < *a;});
}

const vector<evento*>& gerenciador_de_eventos::eventos() {
    ordenar_eventos();
    return lista_de_eventos;
}

gerenciador_de_eventos gerenciador_de_eventos::operator + (evento& evento_adicionar) {
    gerenciador_de_eventos gev;
    gev.lista_de_eventos = this->lista_de_eventos;
    gev.adicionar_evento(evento_adicionar);
    return gev;
}

gerenciador_de_eventos gerenciador_de_eventos::operator - (evento& evento_remover) {
    gerenciador_de_eventos gev;
    gev.lista_de_eventos = this->lista_de_eventos;
    gev.remover_evento(&evento_remover);
    return gev;
}
