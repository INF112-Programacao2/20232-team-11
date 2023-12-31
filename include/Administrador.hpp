#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Calendario.hpp"

//classe administrador
class Administrador : public Calendario {
public:
    Administrador();  // Construtor
    ~Administrador();    // Destrutor

    // Métodos
    void criarEvento(std::vector<Evento>& eventos) override;
    void editarEvento() override;
    void pesquisarEventoPorTitulo() override;
    void pesquisarEventoPorData() override;
    void pesquisarEventoPorTipo() override;
    void listarTodosEventosFuturos() override;
    void listarTodosEventosPassados() override;
    void exibirNotificacoes() override;
    int getNumeroNotificacao() override;
    void contTipoEvento() const override;
    void calendarioComEventos() override;
};

#endif