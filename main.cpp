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
    
    Usuario usuario1("ADMIN", "admin", "admin");
    Usuario usuario2("ALUNO", "aluno0", "user");
    Usuario usuario3("ALUNO", "aluno1", "user");
    Usuario usuario4("ALUNO", "aluno2", "user");
    Usuario usuario5("ALUNO", "aluno3", "user");
    Usuario usuario6("ALUNO", "aluno4", "user");

    Usuario usuario7("PROF", "prof0", "prof");
    Usuario usuario8("PROF", "prof1", "prof");
    Usuario usuario9("PROF", "prof2", "prof");
    Usuario usuario10("PROF", "prof3", "prof");
    Usuario usuario11("PROF", "prof4", "prof");


    Evento evento1("PROVA", "Titulo 1", "Descição 1", "09-12-2023", "12:00", "Local A", "ADMIN", "admin");
    Evento evento2("TRABALHO", "Titulo 2", "Descição 2", "28-12-2023", "14:30", "Local B", "ADMIN", "admin");
    Evento evento3("APRESENTACAO", "Titulo 3", "Descição 3", "09-12-2023", "12:00", "Local C", "ADMIN", "admin");
    Evento evento4("OUTRO", "Titulo 4", "Descição 4", "10-11-2023", "20:00", "Local D", "ADMIN", "admin");
    Evento evento5("PROVA", "Titulo 5", "Descição 5", "25-01-2024", "21:00", "Local E", "ADMIN", "admin");

    Evento evento6("PROVA", "Titulo 6", "Descição 6", "09-12-2023", "12:00", "Local A", "PROF", "prof0");
    Evento evento7("TRABALHO", "Titulo 7", "Descição 7", "28-12-2023", "14:30", "Local B", "PROF", "prof0");
    Evento evento8("APRESENTACAO", "Titulo 8", "Descição 8", "09-12-2023", "12:00", "Local C", "PROF", "prof0");
    Evento evento9("OUTRO", "Titulo 9", "Descição 9", "10-11-2023", "20:00", "Local D", "PROF", "prof0");
    Evento evento10("PROVA", "Titulo 10", "Descição 10", "25-01-2024", "21:00", "Local E", "PROF", "prof0");

    Evento evento11("PROVA", "Titulo 11", "Descição 11", "09-12-2023", "12:00", "Local A", "PROF", "prof1");
    Evento evento12("TRABALHO", "Titulo 12", "Descição 12", "28-12-2023", "14:30", "Local B", "PROF", "prof1");
    Evento evento13("APRESENTACAO", "Titulo 13", "Descição 13", "09-12-2023", "12:00", "Local C", "PROF", "prof1");
    Evento evento14("OUTRO", "Titulo 14", "Descição 14", "10-11-2023", "20:00", "Local D", "PROF", "prof1");
    Evento evento15("PROVA", "Titulo 15", "Descição 15", "25-01-2024", "21:00", "Local E", "PROF", "prof1");

    Evento evento16("PROVA", "Titulo 16", "Descição 16", "09-12-2023", "12:00", "Local A", "PROF", "prof2");
    Evento evento17("TRABALHO", "Titulo 17", "Descição 17", "28-12-2023", "14:30", "Local B", "PROF", "prof2");
    Evento evento18("APRESENTACAO", "Titulo 18", "Descição 18", "09-12-2023", "12:00", "Local C", "PROF", "prof2");
    Evento evento19("OUTRO", "Titulo 19", "Descição 19", "10-11-2023", "20:00", "Local D", "PROF", "prof2");
    Evento evento20("PROVA", "Titulo 20", "Descição 20", "25-01-2024", "21:00", "Local E", "PROF", "prof2");

    Evento evento21("PROVA", "Titulo 21", "Descição 21", "09-12-2023", "12:00", "Local A", "PROF", "prof3");
    Evento evento22("TRABALHO", "Titulo 22", "Descição 22", "28-12-2023", "14:30", "Local B", "PROF", "prof3");
    Evento evento23("APRESENTACAO", "Titulo 23", "Descição 23", "09-12-2023", "12:00", "Local C", "PROF", "prof3");
    Evento evento24("OUTRO", "Titulo 24", "Descição 24", "10-11-2023", "20:00", "Local D", "PROF", "prof3");
    Evento evento25("PROVA", "Titulo 25", "Descição 25", "25-01-2024", "21:00", "Local E", "PROF", "prof3");

    Evento evento26("PROVA", "Titulo 26", "Descição 26", "09-12-2023", "12:00", "Local A", "PROF", "prof4");
    Evento evento27("TRABALHO", "Titulo 27", "Descição 27", "28-12-2023", "14:30", "Local B", "PROF", "prof4");
    Evento evento28("APRESENTACAO", "Titulo 28", "Descição 28", "09-12-2023", "12:00", "Local C", "PROF", "prof4");
    Evento evento29("OUTRO", "Titulo 29", "Descição 29", "10-11-2023", "20:00", "Local D", "PROF", "prof4");
    Evento evento30("PROVA", "Titulo 30", "Descição 30", "25-01-2024", "21:00", "Local E", "PROF", "prof4");

    Evento evento31("PROVA", "Titulo 31", "Descição 31", "09-12-2023", "12:00", "Local A", "ALUNO", "aluno0");
    Evento evento32("TRABALHO", "Titulo 32", "Descição 32", "28-12-2023", "14:30", "Local B", "ALUNO", "aluno0");
    Evento evento33("APRESENTACAO", "Titulo 33", "Descição 33", "09-12-2023", "12:00", "Local C", "ALUNO", "aluno0");
    Evento evento34("OUTRO", "Titulo 34", "Descição 34", "10-11-2023", "20:00", "Local D", "ALUNO", "aluno0");
    Evento evento35("PROVA", "Titulo 35", "Descição 35", "25-01-2024", "21:00", "Local E", "ALUNO", "aluno0");

    Evento evento36("PROVA", "Titulo 36", "Descição 36", "09-12-2023", "12:00", "Local A", "ALUNO", "aluno1");
    Evento evento37("TRABALHO", "Titulo 37", "Descição 37", "28-12-2023", "14:30", "Local B", "ALUNO", "aluno1");
    Evento evento38("APRESENTACAO", "Titulo 38", "Descição 38", "09-12-2023", "12:00", "Local C", "ALUNO", "aluno1");
    Evento evento39("OUTRO", "Titulo 39", "Descição 39", "10-11-2023", "20:00", "Local D", "ALUNO", "aluno1");
    Evento evento40("PROVA", "Titulo 40", "Descição 40", "25-01-2024", "21:00", "Local E", "ALUNO", "aluno1");

    Evento evento41("PROVA", "Titulo 41", "Descição 41", "09-12-2023", "12:00", "Local A", "ALUNO", "aluno2");
    Evento evento42("TRABALHO", "Titulo 42", "Descição 42", "28-12-2023", "14:30", "Local B", "ALUNO", "aluno2");
    Evento evento43("APRESENTACAO", "Titulo 43", "Descição 43", "09-12-2023", "12:00", "Local C", "ALUNO", "aluno2");
    Evento evento44("OUTRO", "Titulo 44", "Descição 44", "10-11-2023", "20:00", "Local D", "ALUNO", "aluno2");
    Evento evento45("PROVA", "Titulo 45", "Descição 45", "25-01-2024", "21:00", "Local E", "ALUNO", "aluno2");

    Evento evento46("PROVA", "Titulo 46", "Descição 46", "09-12-2023", "12:00", "Local A", "ALUNO", "aluno3");
    Evento evento47("TRABALHO", "Titulo 47", "Descição 47", "28-12-2023", "14:30", "Local B", "ALUNO", "aluno3");
    Evento evento48("APRESENTACAO", "Titulo 48", "Descição 48", "09-12-2023", "12:00", "Local C", "ALUNO", "aluno3");
    Evento evento49("OUTRO", "Titulo 49", "Descição 49", "10-11-2023", "20:00", "Local D", "ALUNO", "aluno3");
    Evento evento50("PROVA", "Titulo 50", "Descição 50", "25-01-2024", "21:00", "Local E", "ALUNO", "aluno3");

    Evento evento51("PROVA", "Titulo 51", "Descição 51", "09-12-2023", "12:00", "Local A", "ALUNO", "aluno4");
    Evento evento52("TRABALHO", "Titulo 52", "Descição 52", "28-12-2023", "14:30", "Local B", "ALUNO", "aluno4");
    Evento evento53("APRESENTACAO", "Titulo 53", "Descição 53", "09-12-2023", "12:00", "Local C", "ALUNO", "aluno4");
    Evento evento54("OUTRO", "Titulo 54", "Descição 54", "10-11-2023", "20:00", "Local D", "ALUNO", "aluno4");
    Evento evento55("PROVA", "Titulo 55", "Descição 55", "25-01-2024", "21:00", "Local E", "ALUNO", "aluno4");


    usu.adicionarUsuario(usuario1);
    usu.adicionarUsuario(usuario2);
    usu.adicionarUsuario(usuario3);
    usu.adicionarUsuario(usuario4);
    usu.adicionarUsuario(usuario5);
    usu.adicionarUsuario(usuario6);
    usu.adicionarUsuario(usuario7);
    usu.adicionarUsuario(usuario8);
    usu.adicionarUsuario(usuario9);
    usu.adicionarUsuario(usuario10);
    usu.adicionarUsuario(usuario11);


    calendario.adicionarEvento(evento1);
    calendario.adicionarEvento(evento2);
    calendario.adicionarEvento(evento3);
    calendario.adicionarEvento(evento4);
    calendario.adicionarEvento(evento5);
    calendario.adicionarEvento(evento6);
    calendario.adicionarEvento(evento7);
    calendario.adicionarEvento(evento8);
    calendario.adicionarEvento(evento9);
    calendario.adicionarEvento(evento10);
    calendario.adicionarEvento(evento11);
    calendario.adicionarEvento(evento12);
    calendario.adicionarEvento(evento13);
    calendario.adicionarEvento(evento14);
    calendario.adicionarEvento(evento15);
    calendario.adicionarEvento(evento16);
    calendario.adicionarEvento(evento17);
    calendario.adicionarEvento(evento18);
    calendario.adicionarEvento(evento19);
    calendario.adicionarEvento(evento20);
    calendario.adicionarEvento(evento21);
    calendario.adicionarEvento(evento22);
    calendario.adicionarEvento(evento23);
    calendario.adicionarEvento(evento24);
    calendario.adicionarEvento(evento25);
    calendario.adicionarEvento(evento26);
    calendario.adicionarEvento(evento27);
    calendario.adicionarEvento(evento28);
    calendario.adicionarEvento(evento29);
    calendario.adicionarEvento(evento30);
    calendario.adicionarEvento(evento31);
    calendario.adicionarEvento(evento32);
    calendario.adicionarEvento(evento33);
    calendario.adicionarEvento(evento34);
    calendario.adicionarEvento(evento35);
    calendario.adicionarEvento(evento36);
    calendario.adicionarEvento(evento37);
    calendario.adicionarEvento(evento38);
    calendario.adicionarEvento(evento39);
    calendario.adicionarEvento(evento40);
    calendario.adicionarEvento(evento41);
    calendario.adicionarEvento(evento42);
    calendario.adicionarEvento(evento43);
    calendario.adicionarEvento(evento44);
    calendario.adicionarEvento(evento45);
    calendario.adicionarEvento(evento46);
    calendario.adicionarEvento(evento47);
    calendario.adicionarEvento(evento48);
    calendario.adicionarEvento(evento49);
    calendario.adicionarEvento(evento50);
    calendario.adicionarEvento(evento51);
    calendario.adicionarEvento(evento52);
    calendario.adicionarEvento(evento53);
    calendario.adicionarEvento(evento54);
    calendario.adicionarEvento(evento55);

    usu.criarUsuario(usuarios);
    usu.criarEvento(eventos);

    Notificacao notificacao;

    
    eventos = calendario.getEventos();
    usuarios = usu.getUsuarios();

    std::cout << "Liste de todos os eventos: " << std::endl;
    calendario.listarEventosTodos(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Excluindo evento: " << std::endl;
    calendario.excluirEvento(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Liste de todos os eventos: " << std::endl;
    calendario.listarEventosTodos(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Editando evento: " << std::endl;
    calendario.editarEvento(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Liste de todos os eventos: " << std::endl;
    calendario.listarEventosTodos(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Pesquisando evento por titulo: " << std::endl;
    calendario.pesquisarEventoPorTitulo(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Pesquisando evento por data: " << std::endl;
    calendario.pesquisarEventoPorData(eventos);

    std::cout << "*******************************" << std::endl;

    std::cout << "Pesquisando evento por tipo: " << std::endl;
    calendario.listarEventosTipo(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Listando meus eventos: " << std::endl;
    calendario.listarMeusEventos(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Liste de todos os eventos: " << std::endl;
    calendario.listarEventosTodos(eventos, usuarios);

    std::cout << "*******************************" << std::endl;

    std::cout << "Notificando eventos: " << std::endl;
    notificacao.exibirNotificacao(eventos);

    
    return 0;
}