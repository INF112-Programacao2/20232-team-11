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




    bool rodar = true;
    while (rodar) {
        std::cout << std::endl;
        std::cout << "§§§§§§§§§§§§§§==CALENDARIO ACADEMICO==§§§§§§§§§§§§§§\n" << std::endl;

        std::cout << "Bem vindo ao Calendario Academico!" << std::endl;
        std::cout << "Escolha uma opção:" << std::endl;

        std::cout << "1 - Fazer login" << std::endl;
        std::cout << "2 - Criar usuário" << std::endl;
        std::cout << "3 - Sair" << std::endl;

        int opcao;
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                bool loggedIn = false;
                usu.fazerLogin(); 
                if (usu.fazerLogin()) {
                    loggedIn = true;
                    while (loggedIn) {
                        std::cout << "MENU" << std::endl;
                        std::cout << "Escolha uma opção:" << std::endl;
                        std::cout << "1 - Criar evento" << std::endl;
                        std::cout << "2 - Editar evento" << std::endl;
                        std::cout << "3 - Excluir evento" << std::endl;
                        std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                        std::cout << "5 - Pesquisar evento por data" << std::endl;
                        std::cout << "6 - Listar eventos por tipo" << std::endl;
                        std::cout << "7 - Listar meus eventos" << std::endl;
                        std::cout << "8 - Listar todos os eventos" << std::endl;
                        std::cout << "9 - Voltar" << std::endl;
                        int opcao2;
                        std::cin >> opcao2;
                        switch (opcao2) {
                            case 1:
                                usu.criarEvento(eventos);
                                break;
                            case 2:
                                calendario.editarEvento();
                                break;
                            case 3:
                                calendario.excluirEvento();
                                break;
                            case 4:
                                calendario.pesquisarEventoPorTitulo();
                                break;
                            case 5:
                                calendario.pesquisarEventoPorData();
                                break;
                            case 6:
                                calendario.listarEventosTipo();
                                break;
                            case 7:
                                calendario.listarMeusEventos();
                                break;
                            case 8:
                                calendario.listarEventosTodos();
                                break;
                            case 9:
                                loggedIn = false;
                                break;
                            default:
                                std::cout << "Opção inválida!" << std::endl;
                                break;
                        }
                    }
                } else {
                    std::cout << "Falha no login!" << std::endl;
                }
                break;
            }
            case 2:
                usu.criarUsuario(usuarios);
                break;
            case 3:
                rodar = false; //saia do loop
                std::cout << "*******************************" << std::endl;
                notificacao.exibirNotificacao();
                usu.logout();
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }
    }

    
    return 0;
}