#include "Usuario.hpp"
#include "Aluno.hpp"
#include "Adminitrador.hpp"
#include "Professor.hpp"
#include "Evento.hpp"
#include "Calendario.hpp"
#include "Notificacoes.hpp"


#include <iostream>
#include <string>
#include <vector>


int main(){

    std::vector<Evento> eventos;

    Calendario Calendario;

    Usuario* usuario = new Administrador("admin", "admin");
    Usuario* usuario2 = new Aluno("aluno", "aluno");
    Usuario* usuario3 = new Professor("professor", "professor");

    Evento* evento = new Evento("PROVA", "Título 1", "Descrição 1", "25-11-2023", "02:00", "Local A", "admin");
    Evento* evento2 = new Evento("TRABALHO", "Título 2", "Descrição 2", "25-11-2023", "03:00", "Local A", "aluno");
    Evento* evento3 = new Evento("APRESENTACAO", "Título 3", "Descrição 3", "25-11-2023", "20:00", "Local A", "professor");

    Calendario.adicionarEvento(*evento);
    Calendario.adicionarEvento(*evento2);
    Calendario.adicionarEvento(*evento3);

    //Calendario.listarEventosTodos();

    // Calendario.excluirEvento(*evento, "admin");

    // Calendario.listarEventosTodos();

    // Calendario.editarEvento(*evento2, "aluno");

    // Calendario.listarEventosTodos();

    // Calendario.pesquisarEventoPorTitulo("Título 3");

    // Calendario.listarEventosTipo(APRESENTACAO);

    // Calendario.listarEventosDia("25-11-2023");

    // Calendario.listarMeusEventos("professor");

    // Notificacao notificacao;

    // notificacao.exibirNotificacao(eventos);

    for(int i = 0; i < eventos.size(); i++){
        delete &eventos[i];
    }

    delete usuario;
    delete usuario2;
    delete usuario3;


    return 0;
}