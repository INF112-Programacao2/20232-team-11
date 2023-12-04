#include "Usuario.hpp"
#include "Evento.hpp"
#include <iostream>

Usuario::Usuario() {}       //construtor

Usuario::Usuario(const std::string& tipo, const std::string& id, const std::string& senha) : _tipo(tipo), _id(id), _senha(senha) {}       //construtor

Usuario::~Usuario() {}      //destrutor

//metodo para criar um usuario
void Usuario::criarUsuario(std::vector<Usuario>& usuarios){

    int numUsuarios = 0;  //numero de usuarios que o usuario deseja criar
    std::cout << "Digite o número de usuários que deseja criar: ";      
    std::cin >> numUsuarios;  //le o numero de usuarios
    std::cin.ignore();      //ignora o \n

    //loop para criar os usuarios
    for (int i = 0; i < numUsuarios; ++i) {
        std::string tipo, id, senha;    //tipo, id e senha do usuario

        std::cout << "Criação de usuário n°" << i + 1 << std::endl; 

        std::cout << "Digite o tipo de usuário (ADMIN, PROFESSOR, ESTUDANTE): ";
        std::getline(std::cin, tipo);  //le o tipo do usuario

        std::cout << "Crie um ID de usuário: ";
        std::getline(std::cin, id);  //le o id do usuario   

        std::cout << "Crie uma senha de usuário: ";
        std::getline(std::cin, senha);  //le a senha do usuario

        Usuario usuario(tipo, id, senha);   //cria um usuario para adicionar no vetor de usuarios

        usuarios.push_back(usuario);    //adiciona o usuario no vetor de usuarios

    std::cout << "Usuario criado e salvo com sucesso!" << std::endl;    
    }
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

    int numEventos = 0;       //numero de usuarios que o usuario deseja criar
    std::cout << "Digite o número de usuários que deseja criar: ";
    std::cin >> numEventos;
    std::cin.ignore();

    for (int i = 0; i < numEventos; ++i) {
        std::string tipo, titulo, descricao, data, hora, local, criador, id;
        std::cout << "Digite o tipo do evento (PROVA - TRABALHO - APRESENTACAO - OUTRO): ";
        std::getline(std::cin, tipo);

        std::cout << "Digite o titulo do evento: ";
        std::getline(std::cin, titulo);

        std::cout << "Digite a descricao do evento: ";
        std::getline(std::cin, descricao);

        std::cout << "Digite a data do evento (DD-MM-AAAA): ";
        std::getline(std::cin, data);

        std::cout << "Digite a hora do evento (HH:MM): ";
        std::getline(std::cin, hora);

        std::cout << "Digite o local do evento: ";
        std::getline(std::cin, local);

        std::cout << "Digite o criador do evento (admin - prof - aluno): ";
        std::getline(std::cin, criador);

        std::cout << "Digite seu id do usuario: ";
        std::getline(std::cin, id);

        Evento evento(tipo, titulo, descricao, data, hora, local, criador, id);     //cria um evento

        eventos.push_back(evento);        //adiciona o evento no vetor de eventos

        std::cout << "Evento criado e salvado com sucesso!" << std::endl;
    }
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
bool Usuario::fazerLogin(const std::string& id, const std::string& senha){  

    if(id == _id && senha == _senha){           //verifica se o id e a senha estao corretos
        std::cout << "Login realizado com sucesso!" << std::endl;
        return true;
    }
    else{
        std::cout << "Login ou senha incorretos!" << std::endl;
        return false;
    }
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