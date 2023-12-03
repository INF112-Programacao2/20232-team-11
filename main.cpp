#include "Usuario.hpp"
#include "Aluno.hpp"
#include "Adminitrador.hpp"
#include "Professor.hpp"
#include "Evento.hpp"
#include "Calendario.hpp"
#include "Notificacoes.hpp"
#include "Interface.hpp"


#include <iostream>
#include <string>
#include <vector>


int main(){
    Interface interface;

    std::vector<Usuario*> usuarios;
    std::vector<Evento*> eventos;

    Aluno aluno("Jose", "ze", "aluno", "123");
    Professor professor("Joao", "prof", "prof");
    Administrador administrador("Admin", "admin", "admin");

    // Create vectors to store multiple instances
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;

    // Add some initial data to the vectors (optional)
    alunos.push_back(aluno);
    professores.push_back(professor);

    Calendario calendario;

     interface.menu_principal(aluno, professor, administrador, alunos, professores);

  /*  Usuario* usuario = new Administrador("joao","admin", "admin");
    Usuario* usuario2 = new Aluno("Maria", "aluno", "aluno" , "123");
    Usuario* usuario3 = new Professor("Joseph", "professor", "professor");

    usuarios.push_back(usuario);
    usuarios.push_back(usuario2);
    usuarios.push_back(usuario3);

    Evento* evento = new Evento("PROVA", "Título 1", "Descrição 1", "25-11-2023", "02:00", "Local A", "admin");
    Evento* evento2 = new Evento("TRABALHO", "Título 2", "Descrição 2", "25-11-2023", "03:00", "Local A", "aluno");
    Evento* evento3 = new Evento("APRESENTACAO", "Título 3", "Descrição 3", "25-11-2023", "20:00", "Local A", "professor");

    eventos.push_back(evento);
    eventos.push_back(evento2);
    eventos.push_back(evento3);

    calendario.adicionarEvento(*evento);
    calendario.adicionarEvento(*evento2);
    calendario.adicionarEvento(*evento3);
    */
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

   /* for(int i = 0; i < eventos.size(); i++){
        delete &eventos[i];
    }

    delete usuario;
    delete usuario2;
    delete usuario3;

    */
    return 0;
}