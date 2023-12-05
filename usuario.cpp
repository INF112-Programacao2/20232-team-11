#include "Usuario.hpp"
#include "Evento.hpp"
#include <iostream>


Usuario::Usuario() {}       //construtor

Usuario::Usuario(const std::string& tipo, const std::string& id, const std::string& senha) : _tipo(tipo), _id(id), _senha(senha) {}       //construtor

Usuario::~Usuario() {}      //destrutor

//metodo para criar um usuario
void Usuario::criarUsuario(std::vector<Usuario>& usuarios){

    int numUsuarios = 0;    //variavel para armazenar o numero de usuarios que o usuario deseja criar
    std::cout << "=========CRIANDO USUARIO=========\n";
    std::cout << "Digite o número de usuários que deseja criar: ";
    std::cin >> numUsuarios;    //le o numero de usuarios que o usuario deseja criar
    std::cin.ignore();  //ignora o enter

    std::ifstream arquivo("usuarios.txt"); // Abre o arquivo para leitura

    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto
        std::string linha;  //variavel para armazenar a linha do arquivo
        while (std::getline(arquivo, linha)) {  //percorre o arquivo
            std::stringstream ss(linha);    //variavel para armazenar a linha do arquivo
            std::string tipo, id, senha;    //variaveis para armazenar os dados do usuario
            std::getline(ss, tipo, '|');    //le o tipo do usuario
            std::getline(ss, id, '|');  //le o id do usuario
            std::getline(ss, senha, '|');   //le a senha do usuario
            Usuario usuario(tipo, id, senha);   //cria um novo usuario
            usuarios.push_back(usuario); // Adiciona o usuário ao vetor
        }
        arquivo.close(); //fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; //saia da função
    }

    std::ofstream arquivoSaida("usuarios.txt", std::ios::app); //abre o arquivo para escrita

    for (int i = 0; i < numUsuarios; ++i) { 
        std::string tipo, id, senha;    //variaveis para armazenar os dados do usuario

        std::cout << "Criação de usuário n°" << i + 1 << std::endl;
        std::cout << "Digite o tipo de usuário (ADMIN, PROF, ALUNO): ";
        std::getline(std::cin, tipo);  //le o tipo do usuario

        if(tipo != "ADMIN" && tipo != "PROF" && tipo != "ALUNO"){
            std::cout << "Tipo de usuário inválido!" << std::endl;
            return;
        }

        if(tipo == "ALUNO"){
            std::cout << "ID de usuário: Digite seu Matricula: ";
        }else{
            std::cout << "Crie um ID de usuário: ";
        }
        std::getline(std::cin, id);  //le o id do usuario   

        std::cout << "Crie uma senha de usuário: ";
        std::getline(std::cin, senha);  //le a senha do usuario

        Usuario novoUsuario(tipo, id, senha);   //cria um novo usuario

        bool idExiste = false;  //variavel para verificar se o id ja existe
        for (const auto& user : usuarios) { //percorre o vetor de usuarios
            if (user.getId() == novoUsuario.getId()) {  //verifica se o id ja existe
                idExiste = true;    //se o id ja existe, a variavel recebe true
                break;  //sai do loop
            }
        }

        if (idExiste) { // Verifica se o ID já existe
            std::cout << "ID já existente!" << std::endl;
        } else {
            usuarios.push_back(novoUsuario); // Adiciona o novo usuário ao vetor

            arquivoSaida << tipo << '|' << id << '|' << senha << '\n'; // Escreve no arquivo
            std::cout << "Usuário criado e salvo com sucesso!" << std::endl;
        }
    }
    arquivoSaida.close(); //fecha o arquivo

}

//metodo para adicionar um usuario
void Usuario::adicionarUsuario(const Usuario& usuario){
    _usuarios.push_back(usuario);   //adiciona o usuario no vetor de usuarios
}

//metodo get para retornar o tipo do usuario
std::string Usuario::getTipo() const {        
    return _tipo;   
}

//metodo set para alterar o tipo do usuario
void Usuario::setTipo(const std::string& tipo) {
    _tipo = tipo;
}

//metodo get para retornar o id do usuario
std::string Usuario::getId() const {        
    return _id; 
}

//metodo set para alterar o id do usuario
void Usuario::setId(const std::string& id) {
    _id = id;
}

//metodo get para retornar a senha do usuario
std::string Usuario::getSenha() const {
    return _senha;
}

//metodo set para alterar a senha do usuario
void Usuario::setSenha(const std::string& senha) {
    _senha = senha;
}

//metodo para criar um evento
void Usuario::criarEvento(std::vector<Evento>& eventos){
    
    int numEventos = 0; //variavel para armazenar o numero de eventos que o usuario deseja criar
    std::cout << "=========CRIANDO EVENTO=========\n";
    std::cout << "Digite o número de eventos que deseja criar: ";
    std::cin >> numEventos; //le o numero de eventos que o usuario deseja criar
    std::cin.ignore();  //ignora o enter

    std::ifstream arquivo("eventos.txt"); // Abre o arquivo para leitura

    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto
        std::string linha;  //variavel para armazenar a linha do arquivo
        while (std::getline(arquivo, linha)) {  //percorre o arquivo
            std::stringstream ss(linha);    //cria um fluxo de string
            std::string tipo, titulo, data, hora, descricao, criador, id;   //variaveis para armazenar os dados do evento
            std::getline(ss, titulo, '|');  //le o titulo do evento
            std::getline(ss, data, '|');    //le a data do evento
            std::getline(ss, hora, '|');    //le a hora do evento
            std::getline(ss, tipo, '|');    //le o tipo do evento
            std::getline(ss, descricao, '|');  //le a descricao do evento
            Evento evento(tipo, titulo, data, hora, tipo, descricao, criador, id);  //cria um novo evento
            eventos.push_back(evento); // Adiciona o evento ao vetor
        }
        arquivo.close(); //fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; //saia da função
    }

    std::ofstream arquivoSaida("eventos.txt", std::ios::app); //abre o arquivo para escrita

    for (int i = 0; i < numEventos; ++i) {  //percorre o vetor de eventos
        std::string tipo, titulo, data, hora, descricao, criador, id;   //variaveis para armazenar os dados do evento

        std::cout << "Criação de evento n°" << i + 1 << std::endl;
        std::cout << "Digite o tipo de evento (PROVA, TRABALHO, APRESENTACAO, OUTRO): ";
        std::getline(std::cin, tipo);  //le o tipo do evento
        if(tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "OUTRO"){
            std::cout << "Tipo de evento inválido!" << std::endl;
            return;
        }
        std::cout << "Digite o título do evento: ";
        std::getline(std::cin, titulo);  //le o titulo do evento
        std::cout << "Digite a data do evento (DD-MM-AAAA): ";
        std::getline(std::cin, data);  //le a data do evento
        if(data.size() != 10 || data[2] != '-' || data[5] != '-'){
            std::cout << "Data inválida!" << std::endl;
            return;
        }
        std::cout << "Digite a hora do evento (HH:MM): ";
        std::getline(std::cin, hora);  //le a hora do evento
        if(hora.size() != 5 || hora[2] != ':'){
            std::cout << "Hora inválida!" << std::endl;
            return;
        }
        std::cout << "Digite a descrição do evento: ";
        std::getline(std::cin, descricao);  //le a descricao do evento
        std::cout << "Digite seu tipo de usuario (ADMIN, PROF, ALUNO): ";
        std::getline(std::cin, criador);  //le o criador do evento
        if(criador != "ADMIN" && criador != "PROF" && criador != "ALUNO"){
            std::cout << "Tipo de usuário inválido!" << std::endl;
            return;
        }
        std::cout << "Digite seu id : ";
        std::getline(std::cin, id);  //le o id do evento

        Evento novoEvento(tipo, titulo, data, hora, tipo, descricao, criador, id);  //cria um novo evento

        // bool idExiste = false;  //variavel para verificar se o id ja existe

        // for (const auto& event : eventos) { //percorre o vetor de eventos
        //     if (event.getId() == novoEvento.getId()) {  //verifica se o id ja existe
        //         idExiste = true;    //se o id ja existe, a variavel recebe true
        //         break;  //sai do loop
        //     }
        // }

        // if (idExiste) {
        //     std::cout << "ID já existente!" << std::endl;
        // } else {
            eventos.push_back(novoEvento); // Adiciona o novo evento ao vetor

            arquivoSaida << tipo << '|' << titulo << '|' << data << '|' << hora << '|' << tipo << '|' << descricao << '|' << criador << '|' << id << '\n'; // Escreve no arquivo
            std::cout << "Evento criado e salvo com sucesso!" << std::endl;
        //}

    }
    arquivoSaida.close(); //fecha o arquivo
}



//metodo para adicionar um evento
void Usuario::adicionarEvento(const Evento& evento){
    _eventos.push_back(evento);
}

//metodo get para retornar os eventos
std::vector<Evento> Usuario::getEventos(){
    return _eventos;
}

//metodo get para retornar os usuarios
std::vector<Usuario> Usuario::getUsuarios(){
    return _usuarios;
}

//metodo para fazer o login
bool Usuario::fazerLogin(){ 
    std::string id, senha;  //variaveis para armazenar o id e a senha do usuario
    std::cout << "=========LOGIN=========\n";
    std::cout << "Digite seu ID: ";
    std::getline(std::cin, id);  //le o id do usuario
    std::cout << "Digite sua senha: ";
    std::getline(std::cin, senha);  //le a senha do usuario

    std::ifstream arquivo("usuarios.txt"); // Abre o arquivo para leitura

    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto
        std::string linha;  //variavel para armazenar a linha do arquivo
        while (std::getline(arquivo, linha)) {  //percorre o arquivo
            std::stringstream ss(linha);    //cria um fluxo de string
            std::string tipo, idUsuario, senhaUsuario;    //variaveis para armazenar os dados do usuario
            std::getline(ss, tipo, '|');    //le o tipo do usuario
            std::getline(ss, idUsuario, '|');  //le o id do usuario
            std::getline(ss, senhaUsuario, '|');   //le a senha do usuario
            Usuario usuario(tipo, idUsuario, senhaUsuario);   //cria um novo usuario
            _usuarios.push_back(usuario); // Adiciona o usuário ao vetor
        }
        arquivo.close(); //fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return false; //saia da função
    }

    for (const auto& user : _usuarios) { //percorre o vetor de usuarios
        if (user.getId() == id && user.getSenha() == senha) {  //verifica se o id e a senha do usuario estao corretos
            std::cout << "Login realizado com sucesso!" << std::endl;
            return true;    //retorna true
        }
    }
    std::cout << "ID ou senha incorretos!" << std::endl;
    return false;   //retorna false
}

//metodo para listar os usuarios
void Usuario::listarUsuarios(){
    
    for(int i = 0; i < _usuarios.size(); i++){       //percorre o vetor de usuarios
        std::cout << "Tipo: " << _usuarios[i].getTipo() << std::endl;
        std::cout << "Id: " << _usuarios[i].getId() << std::endl;
        std::cout << "Senha: " << _usuarios[i].getSenha() << std::endl;
    }
}

//metodo get para retornar os usuarios
std::vector<Usuario> Usuario::getUsuarios() const {
    return _usuarios;
}

void Usuario::logout(){
    std::cout << "Logout realizado com sucesso!" << std::endl;
    exit(0);
}