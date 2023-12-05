#include "Usuario.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Adminitrador.hpp"
#include "Evento.hpp"
#include "Calendario.hpp"
#include "Notificacao.hpp"

#include <iostream>
#include <string>
#include <vector>


int main(){

    std::vector<Evento> eventos;
    std::vector<Usuario> usuarios;
    Calendario calendario;
    Usuario usu;
    Notificacao notificacao;

    
    //usu.criarUsuario(usuarios);
    //usu.criarEvento(eventos);


    // std::cout << "*******************************" << std::endl;
    
    
    // calendario.listarEventosTodos();

    // std::cout << "*******************************" << std::endl;

   
    // calendario.excluirEvento();

    // std::cout << "*******************************" << std::endl;

   
    // calendario.listarEventosTodos(eventos, usuarios);

    // std::cout << "*******************************" << std::endl;

    
    // calendario.editarEvento();

    // std::cout << "*******************************" << std::endl;


    // calendario.listarEventosTodos(eventos, usuarios);

    // std::cout << "*******************************" << std::endl;

    // calendario.pesquisarEventoPorTitulo();

    // std::cout << "*******************************" << std::endl;

   
    // calendario.pesquisarEventoPorData();

    // std::cout << "*******************************" << std::endl;

   
    // calendario.listarEventosTipo();

    // std::cout << "*******************************" << std::endl;

   
    // calendario.listarMeusEventos();

    // std::cout << "*******************************" << std::endl;

    
    // calendario.listarEventosTodos(eventos, usuarios);

    // std::cout << "*******************************" << std::endl;

   
    notificacao.exibirNotificacao();

    
    return 0;
}