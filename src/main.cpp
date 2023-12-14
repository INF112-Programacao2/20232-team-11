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

    std::vector<Evento> eventos;        //vetor de eventos para armazenar os eventos
    std::vector<Usuario> usuarios;      //vetor de usuarios para armazenar os usuarios  
    Administrador admin;        //objeto da classe administrador
    Aluno aluno;        //objeto da classe aluno
    Professor prof;     //objeto da classe professor
    Usuario usu;        //objeto da classe usuario


    int tipoUsuario;    //variavel para armazenar o tipo de usuario
    bool login = false; //variavel para verificar se o usuario esta logado no programa
    bool erroLogin = false; //variavel para verificar se o usuario errou a senha 3 vezes
    int cont = 0;   //variavel para contar quantas vezes o usuario errou a senha

    do{     //loop para abrir o programa
        std::cout << "\n§§§§§§§§§§§§§§==CALENDARIO ACADEMICO==§§§§§§§§§§§§§§\n";
        std::cout << "\nVocê é: \n";
        std::cout << "1 - Administrador" << std::endl;
        std::cout << "2 - Professor" << std::endl;
        std::cout << "3 - Estudante" << std::endl;
        std::cout << "4 - Fechar o programa" << std::endl;
        std::cin >> tipoUsuario;    //ler o tipo de usuario
        bool rodar = true;      //variavel para rodar o programa
        switch(tipoUsuario){    //switch para escolher o tipo de usuario
            case 1: 
                while (rodar) { //loop para rodar o programa
                    std::cout << std::endl;
                    std::cout << "§§§§§§§§§§§§§§==CALENDARIO ACADEMICO==§§§§§§§§§§§§§§\n" << std::endl;

                    std::cout << "Bem vindo ao Calendario Acadêmico!" << std::endl;
                    std::cout << "Escolha uma opção:" << std::endl;

                    std::cout << "1 - Fazer login" << std::endl;
                    std::cout << "2 - Criar usuário" << std::endl;
                    std::cout << "3 - Sair" << std::endl;

                    int opcao;
                    std::cin >> opcao;  //ler a opcao
                    std::cin.ignore();  

                    switch (opcao) {    //switch para escolher a opcao do menu
                        case 1: {
                            bool log = false;  //variavel para verificar se o usuario esta logado
                            if (usu.fazerLogin()) { //chama a funcao fazer login
                                log = true; //usuario esta logado
                                login = true;   //variavel para verificar se o usuario esta logado no programa 
                                std::cout << "\n!!!  " << admin.getNumeroNotificacao() << " notificações" << "  !!!\n" << std::endl;    //imprime o numero de notificacoes
                                admin.calendarioComEventos();   //chama a funcao calendario com eventos
                                admin.contTipoEvento(); //chama a funcao para contar o numero de notificacoes
                                std::cout << std::endl;
                                while (log) {   
                                    std::cout << "\n=*=*=*=*=*=*=*MENU=*=*=*=*=*=*=*\n" << std::endl;
                                    std::cout << "Escolha uma opção:" << std::endl;
                                    std::cout << "1 - Criar evento" << std::endl;
                                    std::cout << "2 - Editar evento" << std::endl;
                                    std::cout << "3 - Excluir evento" << std::endl;
                                    std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                                    std::cout << "5 - Pesquisar evento por data" << std::endl;
                                    std::cout << "6 - Pesquisar evento por tipo" << std::endl;
                                    std::cout << "7 - Listar meus eventos futuros" << std::endl;
                                    std::cout << "8 - Listar meus eventos passados" << std::endl;
                                    std::cout << "9 - Listar todos os eventos futuros" << std::endl;
                                    std::cout << "10 - Listar todos os eventos passados" << std::endl;
                                    std::cout << "11 - Alterar senha" << std::endl;
                                    std::cout << "12 - Voltar" << std::endl;
                                    int opcao2;
                                    std::cin >> opcao2;
                                    std::cin.ignore();
                                    switch (opcao2) {
                                        case 1:
                                            admin.criarEvento(eventos);
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
                                            break;
                                        case 7:
                                            admin.listarMeusEventosFuturos();
                                            break;
                                        case 8:
                                            admin.listarMeusEventosPassados();
                                            break;
                                        case 9:
                                            admin.listarTodosEventosFuturos();
                                            break;
                                        case 10:
                                            admin.listarMeusEventosPassados();
                                            break;
                                        case 11:
                                            usu.trocarSenha();
                                            break;
                                        case 12:
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
                                cont++; //conta quantas vezes o usuario errou a senha
                                if(cont == 3){  //se o usuario errou a senha 3 vezes
                                    erroLogin = true;   //variavel para verificar se o usuario errou a senha 4 vezes recebe true
                                }

                                if(erroLogin == true){  //se o usuario errou a senha 3 vezes
                                    std::cout << "Você errou a senha 3 vezes!" << std::endl;
                                    std::cout << "1 - Trocar senha" << std::endl;
                                    std::cout << "2 - Sair" << std::endl;
                                    int opcao3; //variavel para ler a opcao
                                    std::cin >> opcao3; //ler a opcao
                                    std::cin.ignore();
                                    switch(opcao3){ //switch para escolher a opcao
                                        case 1:
                                            usu.trocarSenha();  //chama a funcao trocar senha
                                            break;
                                        case 2:
                                            usu.logout();   //chama a funcao logout
                                            rodar = false;  //sai do loop
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
                            usu.criarUsuario(usuarios); //chama a funcao criar usuario
                            break;
                        case 3:
                            if(login == true){  //se o usuario estiver logado
                                usu.avaliarPrograma();  //chama a funcao avaliar programa
                                std::cout << "*******************************" << std::endl;
                                admin.exibirNotificacoes(); //chama a funcao exibir notificacoes
                                usu.logout();
                            }
                            rodar = false; //saia do loop
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            std::cin.clear(); 
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                            break;
                    }
                }
                break;  
            case 2:
                while (rodar) {
                    std::cout << std::endl;
                    std::cout << "§§§§§§§§§§§§§§==CALENDARIO ACADEMICO==§§§§§§§§§§§§§§\n" << std::endl;

                    std::cout << "Bem vindo ao Calendario Acadêmico!" << std::endl;
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
                                std::cout << "\n!!!  " << admin.getNumeroNotificacao() << " notificações" << "  !!!\n" << std::endl;
                                prof.calendarioComEventos();
                                prof.contTipoEvento();
                                std::cout << std::endl;
                                while (log) {
                                    std::cout << "\n=*=*=*=*=*=*=*MENU=*=*=*=*=*=*=*\n" << std::endl;
                                    std::cout << "Escolha uma opção:" << std::endl;
                                    std::cout << "1 - Criar evento" << std::endl;
                                    std::cout << "2 - Editar evento" << std::endl;
                                    std::cout << "3 - Excluir evento" << std::endl;
                                    std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                                    std::cout << "5 - Pesquisar evento por data" << std::endl;
                                    std::cout << "6 - Pesquisar evento por tipo" << std::endl;
                                    std::cout << "7 - Listar meus eventos futuros" << std::endl;
                                    std::cout << "8 - Listar meus eventos passados" << std::endl;
                                    std::cout << "9 - Listar todos os eventos futuros" << std::endl;
                                    std::cout << "10 - Listar todos os eventos passados" << std::endl;
                                    std::cout << "11 - Alterar senha" << std::endl;
                                    std::cout << "12 - Voltar" << std::endl;
                                    int opcao2;
                                    std::cin >> opcao2;
                                    std::cin.ignore();
                                    switch (opcao2) {
                                        case 1:
                                            prof.criarEvento(eventos);
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
                                            break;
                                        case 7:
                                            prof.listarMeusEventosFuturos();
                                            break;
                                        case 8:
                                            prof.listarMeusEventosPassados();
                                            break;
                                        case 9:
                                            prof.listarTodosEventosFuturos();
                                            break;
                                        case 10:
                                            prof.listarTodosEventosPassados();
                                            break;
                                        case 11:
                                            usu.trocarSenha();
                                            break;
                                        case 12:
                                            log = false;
                                            break;
                                        default:
                                            std::cout << "Opção inválida!" << std::endl;
                                            std::cin.clear(); 
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                                            break;
                                    }
                                }
                            } else {
                                std::cout << "Falha no login!" << std::endl;
                                cont++;
                                if(cont == 3){
                                    erroLogin = true;
                                }

                                if(erroLogin == true){
                                    std::cout << "Você errou a senha 3 vezes!" << std::endl;
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
                                            std::cin.clear(); 
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
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
                                usu.avaliarPrograma();  //chama a funcao avaliar programa
                                std::cout << "*******************************" << std::endl;
                                prof.exibirNotificacoes();
                                usu.logout();
                            }
                            rodar = false; //saia do loop
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            std::cin.clear(); 
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                            break;
                    }
                }
                break;
            case 3:
                while (rodar) {
                    std::cout << std::endl;
                    std::cout << "§§§§§§§§§§§§§§==CALENDARIO ACADEMICO==§§§§§§§§§§§§§§\n" << std::endl;

                    std::cout << "Bem vindo ao Calendario Acadêmico!" << std::endl;
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
                                std::cout << "\n!!!  " << admin.getNumeroNotificacao() << " notificações" << "  !!!\n" << std::endl;
                                aluno.calendarioComEventos();
                                aluno.contTipoEvento();
                                std::cout << std::endl;
                                while (log) {
                                    std::cout << "\n=*=*=*=*=*=*=*MENU=*=*=*=*=*=*=*\n" << std::endl;
                                    std::cout << "Escolha uma opção:" << std::endl;
                                    std::cout << "1 - Criar evento" << std::endl;
                                    std::cout << "2 - Editar evento" << std::endl;
                                    std::cout << "3 - Excluir evento" << std::endl;
                                    std::cout << "4 - Pesquisar evento por titulo" << std::endl;
                                    std::cout << "5 - Pesquisar evento por data" << std::endl;
                                    std::cout << "6 - Pesquisar evento por tipo" << std::endl;  
                                    std::cout << "7 - Listar meus eventos futuros" << std::endl;
                                    std::cout << "8 - Listar meus eventos passados" << std::endl;
                                    std::cout << "9 - Listar todos os eventos futuros" << std::endl;
                                    std::cout << "10 - Listar todos os eventos passados" << std::endl;
                                    std::cout << "11 - Alterar senha" << std::endl;
                                    std::cout << "12 - Voltar" << std::endl;
                                    int opcao2;
                                    std::cin >> opcao2;
                                    std::cin.ignore();
                                    switch (opcao2) {
                                        case 1:
                                            aluno.criarEvento(eventos);
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
                                            break;
                                        case 7:
                                            aluno.listarMeusEventosFuturos();
                                            break;
                                        case 8:
                                            aluno.listarMeusEventosPassados();
                                            break;
                                        case 9:
                                            aluno.listarTodosEventosFuturos();
                                            break;
                                        case 10:
                                            aluno.listarTodosEventosPassados();
                                            break;
                                        case 11:
                                            usu.trocarSenha();
                                            break;
                                        case 12:
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
                                if(cont == 3){
                                    erroLogin = true;
                                }

                                if(erroLogin == true){
                                    std::cout << "Você errou a senha 3 vezes!" << std::endl;
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
                                            std::cin.clear(); 
                                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
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
                                usu.avaliarPrograma();  //chama a funcao avaliar programa
                                std::cout << "*******************************" << std::endl;
                                aluno.exibirNotificacoes();
                                usu.logout();
                            }
                            rodar = false; //saia do loop
                            break;
                        default:
                            std::cout << "Opção inválida!" << std::endl;
                            std::cin.clear(); 
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                            break;
                        
                    }
                }
                case 4:
                    std::cout << "Programa fechou!" << std::endl;
                    rodar = false;
                break;
            default:
                std::cout << "Tipo invalido!" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                break;
            }
    }while(tipoUsuario != 1 && tipoUsuario != 2 && tipoUsuario != 3 && tipoUsuario != 4);   //enquanto o tipo de usuario for diferente de 1, 2, 3 e 4 o programa continua rodando


    return 0;
}

