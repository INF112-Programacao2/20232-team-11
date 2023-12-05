#include "Calendario.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Evento.hpp"

Calendario::Calendario() {}     // Construtor

Calendario::~Calendario() {}        // Destrutor

// Métodos para excluir eventos
void Calendario::excluirEvento() {
    std::cout << "==============EXCLUINDO EVENTO==============\n";
    std::string tipoUsuario, id, titulo;    // Variaveis para armazenar o tipo de usuario, o id e o titulo do evento
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    if(tipoUsuario != "ADMIN" && tipoUsuario != "PROF" && tipoUsuario != "ALUNO") {    // Verifica se o tipo de usuario e valido
        std::cout << "Tipo de usuario invalido!" << std::endl;
        return; // sai da funcao
    }
    std::getline(std::cin, tipoUsuario);    // Recebe o tipo de usuario
    std::cout << "Digite o titulo do evento a ser excluido: ";
    std::getline(std::cin, titulo);    // Recebe o titulo do evento
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);   // Recebe o id do usuario

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado
    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    std::string linha;
    std::vector<std::string> eventosAtualizados;

    while (std::getline(arquivoEventos, linha)) {   //percorre o arquivo de eventos
        std::stringstream ss(linha);    //variavel para armazenar a linha do arquivo
        std::string tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento;  //variaveis para armazenar os dados do evento
        std::getline(ss, tipoEvento, '|');  //le o tipo do evento
        std::getline(ss, tituloEvento, '|');    //le o titulo do evento
        std::getline(ss, descricao, '|');   //le a descricao do evento
        std::getline(ss, data, '|');    //le a data do evento
        std::getline(ss, hora, '|');    //le a hora do evento
        std::getline(ss, local, '|');   //le o local do evento
        std::getline(ss, criador, '|'); //le o criador do evento
        std::getline(ss, idEvento, '|');    //le o id do evento

        if (id == idEvento && titulo == tituloEvento) {   // Verifica se o id e o titulo do evento existem
            idEncontrado = true;    // Caso existam, a variavel recebe true
            eventoEncontrado = true;    // Caso existam, a variavel recebe true
        } else {
            Evento evento(tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
            eventosAtualizados.push_back(linha); //adiciona o evento ao vetor
        }
    }

    arquivoEventos.close(); //fecha o arquivo

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario ou ID nao encontrado!" << std::endl;
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Evento nao encontrado!" << std::endl;
    }

    std::ofstream novoArquivoEventos("eventos.txt"); //abre o arquivo para escrita
    for(const std::string evento : eventosAtualizados) {
        novoArquivoEventos << evento << std::endl; //escreve o evento no arquivo
    }
    novoArquivoEventos.close(); //fecha o arquivo

    std::cout << "Evento excluido com sucesso!" << std::endl;
}

// Métodos para editar eventos
void Calendario::editarEvento() {        // Edita o evento
    std::cout << "==============EDITANDO EVENTO==============\n";
    std::string id, titulo, tipo, descricao, data, hora, local;    // Variaveis para armazenar o id, o titulo, o tipo, a descricao, a data, a hora e o local do evento
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);  // Recebe o id do usuario
    std::cout << "Digite o titulo do evento: ";
    std::getline(std::cin, titulo); // Recebe o titulo do evento

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado
    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado
    
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    std::string linha;
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;
        std::getline(ss, tipoEvento, '|');
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        // Verifica se o id e o titulo do evento existem
        if (id == idEvento && titulo == tituloEvento) {
            idEncontrado = true;    // Caso existam, a variavel recebe true
            
            std::cout << "Digite o novo tipo de evento (PROVA - TRABALHO - APRESENTACAO - OUTRO): ";
            std::getline(std::cin, tipo);   // Recebe o novo tipo de evento
            if(tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "OUTRO") {    // Verifica se o tipo de evento e valido
                std::cout << "Tipo de evento invalido!" << std::endl;
                return; // sai da funcao
            }
            std::cout << "Digite a nova descricao do evento: ";
            std::getline(std::cin, descricao);  // Recebe a nova descricao do evento
            std::cout << "Digite a nova data do evento (DD-MM-AAAA): ";
            std::getline(std::cin, data);   // Recebe a nova data do evento
            if(data.size() != 10 || data[2] != '-' || data[5] != '-') { // Verifica se a data possui o tamanho correto
                std::cout << "Data invalida!" << std::endl;
                return; // sai da funcao
            }
            std::cout << "Digite a nova hora do evento (HH:MM): ";
            if(hora.size() != 5 || hora[2] != ':') { // Verifica se a hora possui o tamanho correto
                std::cout << "Hora invalida!" << std::endl;
                return; // sai da funcao
            }
            std::getline(std::cin, hora);   // Recebe a nova hora do evento
            std::cout << "Digite o novo local do evento: ";
            std::getline(std::cin, local);  // Recebe o novo local do evento

            //atualiza os dados do evento
            std::ofstream arquivoTemporario("temporario.txt"); //abre o arquivo temporário para escrita
            if(!arquivoTemporario.is_open()) {    // Verifica se o arquivo foi aberto
                std::cout << "Erro ao abrir o arquivo!" << std::endl;
                return; // sai da funcao
            }

            //escreve os dados no arquivo temporário
            arquivoTemporario << tipo << "|" << titulo << "|" << descricao << "|" << data << "|" << hora << "|" << local << "|" << criador << "|" << id << "|" << std::endl; 

            //copiar o restante do arquivo para o arquivo temporário
            while (std::getline(arquivoEventos, linha)) {
                arquivoTemporario << linha << std::endl;
            }

            arquivoTemporario.close(); //fecha o arquivo temporário
            arquivoEventos.close(); //fecha o arquivo

            
            remove("eventos.txt"); //remove o arquivo original
            rename("temp.txt", "eventos.txt"); //renomeia o arquivo temporário para o nome do arquivo original

            std::cout << "Evento editado com sucesso!" << std::endl;
            eventoEncontrado = true;    // Caso existam, a variavel recebe true
            return; // sai da funcao
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario ou ID nao encontrado!" << std::endl;
    }else if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Evento nao encontrado!" << std::endl;
    }
}

// Métodos para pesquisar eventos por tipo
void Calendario::pesquisarEventoPorTipo() {
    std::cout << "==============PESQUISANDO EVENTO POR TIPO==============\n";
    std::string tipoEvento, tipoUsuario, id;    // Variaveis para armazenar o tipo de evento, o tipo de usuario e o id do usuario
    std::cout << "Digite o tipo de evento a ser pesquisado (PROVA - TRABALHO - APRESENTACAO - OUTRO): ";
    std::getline(std::cin, tipoEvento);   // Recebe o tipo de evento
    if(tipoEvento != "PROVA" && tipoEvento != "TRABALHO" && tipoEvento != "APRESENTACAO" && tipoEvento != "OUTRO") {    // Verifica se o tipo de evento e valido
        std::cout << "Tipo de evento invalido!" << std::endl;
        return; // sai da funcao
    }
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    std::getline(std::cin, tipoUsuario);    // Recebe o tipo de usuario
    if(tipoUsuario != "ADMIN" && tipoUsuario != "PROF" && tipoUsuario != "ALUNO") {    // Verifica se o tipo de usuario e valido
        std::cout << "Tipo de usuario invalido!" << std::endl;
        return; // sai da funcao
    }
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id);  // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;  //variavel para armazenar a linha do arquivo
    while (std::getline(arquivoUsuarios, linha)) {  //percorre o arquivo de usuarios
        std::stringstream ss(linha);    //variavel para armazenar a linha do arquivo
        std::string tipo, idUsuario, senha; //variaveis para armazenar os dados do usuario
        std::getline(ss, tipo, '|');    //le o tipo do usuario
        std::getline(ss, idUsuario, '|');   //le o id do usuario
        std::getline(ss, senha, '|');   //le a senha do usuario

        if (id == idUsuario) {  //verifica se o id existe
            idEncontrado = true;    // Caso exista, a variavel recebe true
            break;  //sai do loop
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipo, titulo, descricao, data, hora, local, criador, idEvento;
        std::getline(ss, tipo, '|');
        std::getline(ss, titulo, '|');
        std::getline(ss, descricao, '|');
        std::getline(ss, data, '|');
        std::getline(ss, hora, '|');
        std::getline(ss, local, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        if (tipoEvento == tipo && id == idEvento) {   // Verifica se o tipo de evento e o id do usuario existem
            std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
            if (tipoUsuario == "ADMIN" && criador == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipoUsuario == "PROF" && (criador == "PROF" || criador == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipoUsuario == "ALUNO") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse tipo." << std::endl;
    }

    arquivoUsuarios.close(); //fecha o arquivo
    arquivoEventos.close(); //fecha o arquivo
}


// Métodos para pesquisar eventos por título
void Calendario::pesquisarEventoPorTitulo() {
    std::cout << "==============PESQUISANDO EVENTO POR TITULO==============\n";
    std::string titulo, tipo, id;   // Variaveis para armazenar o titulo, o tipo e o id do usuario
    std::cout << "Digite o titulo do evento a ser pesquisado: ";
    std::getline(std::cin, titulo); // Recebe o titulo do evento
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    if(tipo != "ADMIN" && tipo != "PROF" && tipo != "ALUNO") {    // Verifica se o tipo de usuario e valido
        std::cout << "Tipo de usuario invalido!" << std::endl;
        return; // sai da funcao
    }
    std::getline(std::cin, tipo);   // Recebe o tipo de usuario
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipo, idUsuario, senha;
        std::getline(ss, tipo, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senha, '|');

        if (id == idUsuario) {
            idEncontrado = true;
            break;
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento;
        std::getline(ss, tipoEvento, '|');
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricao, '|');
        std::getline(ss, data, '|');
        std::getline(ss, hora, '|');
        std::getline(ss, local, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        if (titulo == tituloEvento && id == idEvento) {   // Verifica se o titulo e o id do usuario existem
            std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
            if (tipo == "ADMIN" && criador == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "PROF" && (criador == "PROF" || criador == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "ALUNO") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse titulo." << std::endl;
    }

    arquivoUsuarios.close(); //fecha o arquivo
    arquivoEventos.close(); //fecha o arquivo
}

// Métodos para listar eventos por tipo
void Calendario::listarEventosTipo() {   
    std::cout << "==============LISTANDO EVENTOS POR TIPO==============\n";   
    std::string tipoUsuario, tipoEvento, id;    // Variaveis para armazenar o tipo de usuario, o tipo de evento e o id do usuario
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    std::getline(std::cin, tipoUsuario);    // Recebe o tipo de usuario
    if(tipoUsuario != "ADMIN" && tipoUsuario != "PROF" && tipoUsuario != "ALUNO") {    // Verifica se o tipo de usuario e valido
        std::cout << "Tipo de usuario invalido!" << std::endl;
        return; // sai da funcao
    }
    std::cout << "Digite o tipo de evento a ser listado (PROVA - TRABALHO - APRESENTACAO - OUTRO): ";
    std::getline(std::cin, tipoEvento); 
    if(tipoEvento != "PROVA" && tipoEvento != "TRABALHO" && tipoEvento != "APRESENTACAO" && tipoEvento != "OUTRO") {    // Verifica se o tipo de evento e valido
        std::cout << "Tipo de evento invalido!" << std::endl;
        return; // sai da funcao
    }
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipo, idUsuario, senha;
        std::getline(ss, tipo, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senha, '|');

        if (id == idUsuario) {
            idEncontrado = true;
            break;
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipo, titulo, descricao, data, hora, local, criador, idEvento;
        std::getline(ss, tipo, '|');
        std::getline(ss, titulo, '|');
        std::getline(ss, descricao, '|');
        std::getline(ss, data, '|');
        std::getline(ss, hora, '|');
        std::getline(ss, local, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        if (tipoEvento == tipo && id == idEvento) {   // Verifica se o tipo de evento e o id do usuario existem
            std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
            if (tipoUsuario == "ADMIN" && criador == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
            } else if (tipoUsuario == "PROF" && (criador == "PROF" || criador == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
            } else if (tipoUsuario == "ALUNO") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
            }
        }
    }

    arquivoUsuarios.close(); //fecha o arquivo
    arquivoEventos.close(); //fecha o arquivo
}

// Métodos para pesquisar eventos por data
void Calendario::pesquisarEventoPorData() { 
    std::cout << "==============PESQUISANDO EVENTO POR DATA==============\n"; 
    std::string data, tipo;   // Variaveis para armazenar a data e o tipo de usuario
    std::cout << "Digite a data do evento a ser pesquisado (DD-MM-AAAA): ";
    std::getline(std::cin, data);   // Recebe a data do evento
    if(data.size() != 10 || data[2] != '-' || data[5] != '-') { // Verifica se a data possui o tamanho correto
        std::cout << "Data invalida!" << std::endl;
        return; // sai da funcao
    }
    std::cout << "Digite o seu tipo de usuario: ";
    std::getline(std::cin, tipo);   // Recebe o tipo de usuario

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    std::string linha;
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipoEvento, titulo, descricao, dataEvento, hora, local, criador, idEvento;
        std::getline(ss, tipoEvento, '|');
        std::getline(ss, titulo, '|');
        std::getline(ss, descricao, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, hora, '|');
        std::getline(ss, local, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        if (data == dataEvento) {   // Verifica se a data existe
            std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
            if (tipo == "ADMIN" && criador == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, titulo, descricao, dataEvento, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "PROF" && (criador == "PROF" || criador == "ADMIN")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, titulo, descricao, dataEvento, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            } else if (tipo == "ALUNO") {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, titulo, descricao, dataEvento, hora, local, criador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;    // Caso existam, a variavel recebe true
            }
        }
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para essa data." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}

// Métodos para listar todos os eventos
void Calendario::listarEventosTodos() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS==============\n";
    std::string id, criador;    // Variaveis para armazenar o id e o tipo de usuario
    std::cout << "Digite o seu tipo de usuario (ADMIN - PROF - ALUNO): ";
    std::getline(std::cin, criador);    // Recebe o tipo de usuario
    if(criador != "ADMIN" && criador != "PROF" && criador != "ALUNO") {    // Verifica se o tipo de usuario e valido
        std::cout << "Tipo de usuario invalido!" << std::endl;
        return; // sai da funcao
    }
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipo, idUsuario, senha;
        std::getline(ss, tipo, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senha, '|');

        if (id == idUsuario) {
            idEncontrado = true;
            break;
        }
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return; // sai da funcao
    }

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string tipo, titulo, descricao, data, hora, local, eventoCriador, idEvento;
        std::getline(ss, tipo, '|');
        std::getline(ss, titulo, '|');
        std::getline(ss, descricao, '|');
        std::getline(ss, data, '|');
        std::getline(ss, hora, '|');
        std::getline(ss, local, '|');
        std::getline(ss, eventoCriador, '|');
        std::getline(ss, idEvento, '|');

        if (criador == "ADMIN" && eventoCriador == "ADMIN" && id == idEvento) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
            Evento evento(tipo, titulo, descricao, data, hora, local, eventoCriador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
            imprimirEvento(evento); //imprime o evento
        } else if ((criador == "PROF" && id == idEvento) || eventoCriador == "ADMIN") {   // Verifica se o tipo de usuario e o criador do evento sao iguais
            Evento evento(tipo, titulo, descricao, data, hora, local, eventoCriador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
            imprimirEvento(evento); //imprime o evento
        } else if (criador == "ALUNO" && (id == idEvento || eventoCriador == "PROF" || eventoCriador == "ADMIN")) {   // Verifica se o tipo de usuario e o criador do evento sao iguais
            Evento evento(tipo, titulo, descricao, data, hora, local, eventoCriador, idEvento); //cria um objeto do tipo evento com os dados do arquivo
            imprimirEvento(evento); //imprime o evento
        }
    }

    arquivoUsuarios.close(); //fecha o arquivo
}

// Métodos para listar eventos por criador
void Calendario::listarMeusEventos() {
    std::cout << "==============LISTANDO MEUS EVENTOS==============\n";
    std::string id;   // Variavel para armazenar o id do usuario
    std::cout << "Digite o seu ID de usuário: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    bool idEncontrado = false;  // Variavel para verificar se o id foi encontrado

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    //percorre o arquivo de usuários para encontrar o id do usuário
    if (arquivoUsuarios.is_open()) {
        std::string linha;
        while (std::getline(arquivoUsuarios, linha)) {
            std::stringstream ss(linha);
            std::string tipo, idUsuario, senha;
            std::getline(ss, tipo, '|');
            std::getline(ss, idUsuario, '|');
            std::getline(ss, senha, '|');

            if (id == idUsuario) {
                idEncontrado = true;
                break;
            }
        }
        arquivoUsuarios.close(); //fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo de usuários!" << std::endl;
        return;
    }

    if (!idEncontrado) {    // Caso o id nao seja encontrado
        std::cout << "Usuario nao encontrado!" << std::endl;
        return;
    }

    bool eventoEncontrado = false;  // Variavel para verificar se o evento foi encontrado

    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
    if (arquivoEventos.is_open()) {
        std::string linha;
        while (std::getline(arquivoEventos, linha)) {
            std::stringstream ss(linha);
            std::string tipo, titulo, descricao, data, hora, local, criador, idEvento;
            std::getline(ss, tipo, '|');
            std::getline(ss, titulo, '|');
            std::getline(ss, descricao, '|');
            std::getline(ss, data, '|');
            std::getline(ss, hora, '|');
            std::getline(ss, local, '|');
            std::getline(ss, criador, '|');
            std::getline(ss, idEvento, '|');

            if (id == idEvento) {
                //cria um objeto do tipo evento com os dados do arquivo
                Evento evento(tipo, titulo, descricao, data, hora, local, criador, idEvento);
                imprimirEvento(evento); //imprime o evento
                eventoEncontrado = true;
            }
        }
        arquivoEventos.close(); //fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo de eventos!" << std::endl;
        return;
    }

    if (!eventoEncontrado) {    // Caso o evento nao seja encontrado
        std::cout << "Nenhum evento encontrado para esse usuario." << std::endl;
    }
}

// Método get para retornar os eventos
std::vector<Evento>  Calendario::getEventos() const {
    return eventos;
}

// Métodos para imprimir eventos
void Calendario::imprimirEvento(const Evento& evento) {
    std::cout << "Tipo: " << evento.getTipo() << std::endl;   // Imprime o tipo do evento
    std::cout << "Titulo: " << evento.getTitulo() << std::endl;  // Imprime o titulo do evento
    std::cout << "Descricao: " << evento.getDescricao() << std::endl;   // Imprime a descricao do evento
    std::cout << "Data: " << evento.getData() << std::endl;  // Imprime a data do evento
    std::cout << "Hora: " << evento.getHora() << std::endl; // Imprime a hora do evento
    std::cout << "Local: " << evento.getLocal() << std::endl;   // Imprime o local do evento
    std::cout << std::endl; // Pula uma linha
}