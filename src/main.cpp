#include "Usuario.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Administrador.hpp"
#include "Evento.hpp"
#include "Calendario.hpp"

#include <iostream>
#include <string>
#include <vector>



int main(){

    std::vector<Evento> eventos;
    std::vector<Usuario> usuarios;
    std::string id, senha;
    Administrador admin;
    Aluno aluno;
    Professor prof;
    Usuario usu;


    int tipoUsuario;
    bool login = false; //variavel para verificar se o usuario esta logado
    bool erroLogin = false; //variavel para verificar se o usuario errou a senha 4 vezes
    int cont = 0;

    do{
        std::cout << "\nVocê é: \n";
        std::cout << "1 - Administrador" << std::endl;
        std::cout << "2 - Professor" << std::endl;
        std::cout << "3 - Estudante" << std::endl;
        std::cout << "4 - Fechar o programa" << std::endl;
        std::cin >> tipoUsuario;
        bool rodar = true;
        switch(tipoUsuario){
            case 1: 
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
                    std::cin.ignore();

                    switch (opcao) {
                        case 1: {
                            bool log = false;  //variavel para verificar se o usuario esta logado
                            if (usu.fazerLogin()) {
                                log = true;
                                login = true;
                                std::cout << std::endl;
                                std::cout << admin.getNumeroNotificacao() << " notificações" << std::endl;
                                std::cout << std::endl;
                                admin.contTipoEvento();
                                while (log) {
                                    std::cout << std::endl;
                                    std::cout << "MENU" << std::endl;
                                    std::cout << "Escolha uma opção:" << std::endl;
                                    std::cout << "1 - Criar evento" << std::endl;
                                    std::cout << "2 - Editar evento" << std::endl;
                                    std::cout << "3 - Excluir evento" << std::endl;
                                    std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                                    std::cout << "5 - Pesquisar evento por data" << std::endl;
                                    std::cout << "6 - Pesquisar evento por tipo" << std::endl;
                                    std::cout << "7 - Listar meus eventos" << std::endl;
                                    std::cout << "8 - Listar todos os eventos" << std::endl;
                                    std::cout << "9 - Alterar senha" << std::endl;
                                    std::cout << "10 - Voltar" << std::endl;
                                    int opcao2;
                                    std::cin >> opcao2;
                                    std::cin.ignore();
                                    switch (opcao2) {
                                        case 1:
                                            usu.criarEvento(eventos);
                                            break;
                                        case 2:
                                            admin.editarEvento();
                                            break;
                                        case 3:
                                            admin.excluirEvento();
                                            break;
                                        case 4:
                                            admin.pesquisarEventoPorTitulo();
                                            break;
                                        case 5:
                                            admin.pesquisarEventoPorData();
                                            break;
                                        case 6:
                                            admin.pesquisarEventoPorTipo();
                                        case 7:
                                            admin.listarMeusEventos();
                                            break;
                                        case 8:
                                            admin.listarEventosTodos();
                                            break;
                                        case 9:
                                            usu.trocarSenha();
                                            break;
                                        case 10:
                                            log = false;
                                            break;
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            std::cin.clear(); //limpa o que foi digitado
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                                            break;
                                    }
                                }
                            } else {
                                std::cout << "Falha no login!" << std::endl;
                                cont++;
                                if(cont == 4){
                                    erroLogin = true;
                                }

                                if(erroLogin == true){
                                    std::cout << "Você errou a senha 4 vezes!" << std::endl;
                                    std::cout << "1 - Trocar senha" << std::endl;
                                    std::cout << "2 - Sair" << std::endl;
                                    int opcao3;
                                    std::cin >> opcao3;
                                    std::cin.ignore();
                                    switch(opcao3){
                                        case 1:
                                            usu.trocarSenha();
                                            break;
                                        case 2:
                                            usu.logout();
                                            rodar = false;
                                            break;  
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            std::cin.clear(); //limpa o que foi digitado
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                                            break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                            usu.criarUsuario(usuarios);
                            break;
                        case 3:
                            if(login == true){
                                std::cout << "*******************************" << std::endl;
                                admin.exibirNotificacoes();
                                usu.logout();
                            }
                            rodar = false; //saia do loop
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            std::cin.clear(); //limpa o que foi digitado
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                            break;
                    }
                }
                break;  
            case 2:
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
                    std::cin.ignore();
                    switch (opcao) {
                        case 1: {
                            bool log = false;
                            if (usu.fazerLogin()) {
                                log = true;
                                login = true;
                                std::cout << std::endl;
                                std::cout << prof.getNumeroNotificacao() << " notificações" << std::endl;
                                std::cout << std::endl;
                                prof.contTipoEvento();
                                while (log) {
                                    std::cout << "MENU" << std::endl;
                                    std::cout << "Escolha uma opção:" << std::endl;
                                    std::cout << "1 - Criar evento" << std::endl;
                                    std::cout << "2 - Editar evento" << std::endl;
                                    std::cout << "3 - Excluir evento" << std::endl;
                                    std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                                    std::cout << "5 - Pesquisar evento por data" << std::endl;
                                    std::cout << "6 - Pesquisar evento por tipo" << std::endl;
                                    std::cout << "7 - Listar meus eventos" << std::endl;
                                    std::cout << "8 - Listar todos os eventos" << std::endl;
                                    std::cout << "9 - Alterar senha" << std::endl;
                                    std::cout << "10 - Voltar" << std::endl;
                                    int opcao2;
                                    std::cin >> opcao2;
                                    std::cin.ignore();
                                    switch (opcao2) {
                                        case 1:
                                            usu.criarEvento(eventos);
                                            break;
                                        case 2:
                                            prof.editarEvento();
                                            break;
                                        case 3:
                                            prof.excluirEvento();
                                            break;
                                        case 4:
                                            prof.pesquisarEventoPorTitulo();
                                            break;
                                        case 5:
                                            prof.pesquisarEventoPorData();
                                            break;
                                        case 6:
                                            prof.pesquisarEventoPorTipo();
                                        case 7:
                                            prof.listarMeusEventos();
                                            break;
                                        case 8:
                                            prof.listarEventosTodos();
                                            break;
                                        case 9:
                                            usu.trocarSenha();
                                            break;
                                        case 10:
                                            log = false;
                                            break;
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            std::cin.clear(); //limpa o que foi digitado
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                                            break;
                                    }
                                }
                            } else {
                                std::cout << "Falha no login!" << std::endl;
                                cont++;
                                if(cont == 4){
                                    erroLogin = true;
                                }

                                if(erroLogin == true){
                                    std::cout << "Você errou a senha 4 vezes!" << std::endl;
                                    std::cout << "1 - Trocar senha" << std::endl;
                                    std::cout << "2 - Sair" << std::endl;
                                    int opcao3;
                                    std::cin >> opcao3;
                                    std::cin.ignore();
                                    switch(opcao3){
                                        case 1:
                                            usu.trocarSenha();
                                            break;
                                        case 2:
                                            usu.logout();
                                            rodar = false;
                                            break;  
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            std::cin.clear(); //limpa o que foi digitado
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                                            break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                            usu.criarUsuario(usuarios);
                            break;
                        case 3:
                            if(login == true){
                                std::cout << "*******************************" << std::endl;
                                prof.exibirNotificacoes();
                                usu.logout();
                            }
                            rodar = false; //saia do loop
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            std::cin.clear(); //limpa o que foi digitado
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                            break;
                    }
                }
                break;
            case 3:
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
                    std::cin.ignore();
                    switch (opcao) {
                        case 1: {
                            bool log = false; 
                            if (usu.fazerLogin()) {
                                log = true;
                                login = true;
                                std::cout << std::endl;
                                std::cout << aluno.getNumeroNotificacao() << " notificações" << std::endl;
                                std::cout << std::endl;
                                aluno.contTipoEvento();
                                while (log) {
                                    std::cout << "MENU" << std::endl;
                                    std::cout << "Escolha uma opção:" << std::endl;
                                    std::cout << "1 - Criar evento" << std::endl;
                                    std::cout << "2 - Editar evento" << std::endl;
                                    std::cout << "3 - Excluir evento" << std::endl;
                                    std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                                    std::cout << "5 - Pesquisar evento por data" << std::endl;
                                    std::cout << "6 - Pesquisar evento por tipo" << std::endl;  
                                    std::cout << "7 - Listar meus eventos" << std::endl;
                                    std::cout << "8 - Listar todos os eventos" << std::endl;
                                    std::cout << "9 - Alterar senha" << std::endl;
                                    std::cout << "10 - Voltar" << std::endl;
                                    int opcao2;
                                    std::cin >> opcao2;
                                    std::cin.ignore();
                                    switch (opcao2) {
                                        case 1:
                                            usu.criarEvento(eventos);
                                            break;
                                        case 2:
                                            aluno.editarEvento();
                                            break;
                                        case 3:
                                            aluno.excluirEvento();
                                            break;
                                        case 4:
                                            aluno.pesquisarEventoPorTitulo();
                                            break;
                                        case 5:
                                            aluno.pesquisarEventoPorData();
                                            break;
                                        case 6:
                                            aluno.pesquisarEventoPorTipo();
                                        case 7:
                                            aluno.listarMeusEventos();
                                            break;
                                        case 8:
                                            aluno.listarEventosTodos();
                                            break;
                                        case 9:
                                            usu.trocarSenha();
                                            break;
                                        case 10:
                                            log = false;
                                            break;
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            break;
                                        
                                    }
                                }
                            } else {
                                std::cout << "Falha no login!" << std::endl;
                                cont++;
                                if(cont == 4){
                                    erroLogin = true;
                                }

                                if(erroLogin == true){
                                    std::cout << "Você errou a senha 4 vezes!" << std::endl;
                                    std::cout << "1 - Trocar senha" << std::endl;
                                    std::cout << "2 - Sair" << std::endl;
                                    int opcao3;
                                    std::cin >> opcao3;
                                    std::cin.ignore();
                                    switch(opcao3){
                                        case 1:
                                            usu.trocarSenha();
                                            break;
                                        case 2:
                                            usu.logout();
                                            rodar = false;
                                            break;  
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            std::cin.clear(); //limpa o que foi digitado
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                                            break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:
                            usu.criarUsuario(usuarios);
                            break;
                        case 3:
                            if(login == true){
                                std::cout << "*******************************" << std::endl;
                                aluno.exibirNotificacoes();
                                usu.logout();
                            }
                            rodar = false; //saia do loop
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            std::cin.clear(); //limpa o que foi digitado
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                            break;
                        
                    }
                }
                case 4:
                    std::cout << "Programa fechou!" << std::endl;
                    rodar = false;
                break;
            default:
                std::cout << "Tipo invalido!" << std::endl;
                std::cin.clear(); //limpa o que foi digitado
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignora o que foi digitado
                break;
            }
    }while(tipoUsuario != 1 && tipoUsuario != 2 && tipoUsuario != 3 && tipoUsuario != 4);


    return 0;
}

