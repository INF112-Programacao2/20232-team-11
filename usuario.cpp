#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(const std::string& nome, const std::string& id, const std::string& senha) : _nome(nome), _id(id), _senha(senha) {}       //construtor
Usuario::Usuario(): _nome(""), _id(""), _senha(""){}; 

Usuario::~Usuario() {}      //destrutor

std::string Usuario::get_id() const {        
    return _id; 
}

std::string Usuario::get_senha() const {
    return _senha;
}
std::string Usuario::get_nome() const {
    return _nome;
}

void Usuario::alterar_senha(const std::string& senha)  {
    _senha = senha;
}

void Usuario::criarEvento(const std::string& tipo, const std::string& titulo, const std::string& descricao, const std::string& data, const std::string& hora, const std::string& local, const std::string& criador){
    Evento evento(tipo, titulo, descricao, data, hora, local, criador);     //cria um evento
    std::cout << "Evento criado com sucesso!" << std::endl;
}

bool Usuario::fazer_login(const std::string& id, const std::string& senha){      
    if(id == _id && senha == _senha){           //verifica se o id e a senha estao corretos
        std::cout << "Login realizado com sucesso!" << std::endl;
        return true;
    }
    else{
        std::cout << "Login ou senha incorretos!" << std::endl;
        return false;
    }
}

void Usuario::cadastrar() {
    std::string novo_id, nova_senha, confirmacao_senha;

    do {
        // Solicitar o ID
        std::cout << "Informe o ID do usuário: ";
        std::cin >> novo_id;

        // Verificar se o ID já está em uso
        if (novo_id == _id) {
            std::cout << "ID já está em uso. Escolha outro." << std::endl;
        }
    } while (novo_id == _id);

    do {
        // Solicitar a senha e confirmar a senha
        std::cout << "Informe a senha do usuário: ";
        std::cin >> nova_senha;

        std::cout << "Confirme a senha do usuário: ";
        std::cin >> confirmacao_senha;

        // Verificar se as senhas coincidem
        if (nova_senha != confirmacao_senha) {
            std::cout << "As senhas não coincidem. Tente novamente." << std::endl;
        }
    } while (nova_senha != confirmacao_senha);

    // Atribuir os valores após a verificação
    _id = novo_id;
    _senha = nova_senha;

    std::cout << "Cadastro de usuário concluído." << std::endl;
}

void Usuario::inativar() {
    _ativo = false;
}

bool Usuario::esta_ativo() const {
    return _ativo;
}
