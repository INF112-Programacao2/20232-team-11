#include "Usuario.hpp"
#include "Evento.hpp"
#include <iostream>


Usuario::Usuario() {
    _tipo = "";
    _id = "";
    _senha = "";
}       //construtor

Usuario::Usuario(const std::string& tipo, const std::string& id, const std::string& senha) : _tipo(tipo), _id(id), _senha(senha) {}       //construtor

Usuario::~Usuario() {}      //destrutor


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


bool Usuario::fazerLogin(){ 
    std::cout << "=========LOGIN=========\n\n";
    std::string id, senha;  //variaveis para armazenar o id e a senha do usuario
    std::cout << "Digite seu ID: ";
    std::getline(std::cin, id);  //le o id do usuario
    std::cout << "Digite sua senha: ";
    std::getline(std::cin, senha);  //le a senha do usuario

    std::ifstream arquivo("usuarios.txt"); // Abre o arquivo para leitura
    std::string tipoUsuario, idUsuario, senhaUsuario;    //variaveis para armazenar os dados do usuario
    if (arquivo.is_open()) { // Verifica se o arquivo foi aberto
        std::string linha;  //variavel para armazenar a linha do arquivo
        while (std::getline(arquivo, linha)) {  //percorre o arquivo
            std::stringstream ss(linha);    //cria um fluxo de string
            
            std::getline(ss, tipoUsuario, '|');    //le o tipo do usuario
            std::getline(ss, idUsuario, '|');  //le o id do usuario
            std::getline(ss, senhaUsuario, '|');   //le a senha do usuario
            Usuario usuario(tipoUsuario, idUsuario, senhaUsuario);   //cria um novo usuario
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


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


//metodo get para retornar os usuarios
std::vector<Usuario> Usuario::getUsuarios() const {
    return _usuarios;
}


 
/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/
   

void Usuario::logout() {
    std::cout << "Logout realizado com sucesso!\n" << std::endl;
    exit(0);
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


//metodo para criar um usuario
void Usuario::criarUsuario(std::vector<Usuario>& usuarios){

    std::cout << "=========CRIANDO USUARIO=========\n\n";

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

    std::string tipo, id, senha;    //variaveis para armazenar os dados do usuario

    std::cout << "Digite o tipo de usuário (ADMIN, PROF, ALUNO): ";
    std::getline(std::cin, tipo);  //le o tipo do usuario

    while(tipo != "ADMIN" && tipo != "PROF" && tipo != "ALUNO"){
        std::cout << "Tipo de usuário inválido!" << std::endl;
        std::cout << "Digite o tipo de usuário (ADMIN, PROF, ALUNO): ";
        std::getline(std::cin, tipo);  //le o tipo do usuario
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
    
    arquivoSaida.close(); //fecha o arquivo

}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/



void Usuario::trocarSenha(){
    std::cout << "=========TROCANDO A SENHA=========\n\n";
    std::string tipo, id, novasenha, novaSenhaDeNovo;
    std::cout << "Digite seu tipo de usuário (ADMIN, PROF, ALUNO): ";
    std::getline(std::cin, tipo);

    while (tipo != "ADMIN" && tipo != "PROF" && tipo != "ALUNO") {
        std::cout << "Tipo de usuário inválido!" << std::endl;
        std::cout << "Digite seu tipo de usuário (ADMIN, PROF, ALUNO): ";
        std::getline(std::cin, tipo);
    }

    std::cout << "Digite seu ID: ";
    std::getline(std::cin, id);

    std::ifstream arquivoEntrada("usuarios.txt"); 
    std::ofstream arquivoTemporario("tempUsu.txt"); 

    if (!arquivoEntrada.is_open() || !arquivoTemporario.is_open()) {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    std::string linha;
    bool usuarioEncontrado = false;

    while (std::getline(arquivoEntrada, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (idUsuario == id) {
            usuarioEncontrado = true;

            std::cout << "Digite sua nova senha: ";
            std::getline(std::cin, novasenha);
            std::cout << "Digite sua nova senha novamente: ";
            std::getline(std::cin, novaSenhaDeNovo);

            while (novasenha != novaSenhaDeNovo) {
                std::cout << "As senhas não coincidem!" << std::endl;
                std::cout << "Digite sua nova senha: ";
                std::getline(std::cin, novasenha);
                std::cout << "Digite sua nova senha novamente: ";
                std::getline(std::cin, novaSenhaDeNovo);
            }

            arquivoTemporario << tipo << '|' << id << '|' << novasenha << '\n';
        } else {
            arquivoTemporario << linha << std::endl;
        }
    }

    arquivoEntrada.close();
    arquivoTemporario.close();

    if (!usuarioEncontrado) {
        std::cout << "ID do usuário não encontrado!" << std::endl;
        return;
    }

    std::remove("usuarios.txt");
    std::rename("tempUsu.txt", "usuarios.txt");

    std::cout << "Senha alterada com sucesso!" << std::endl;
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


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


//metodo para criar um evento
void Usuario::criarEvento(std::vector<Evento>& eventos){
    
    int numEventos = 0; //variavel para armazenar o numero de eventos que o usuario deseja criar
    std::cout << "=========CRIANDO EVENTO=========\n\n";
    std::cout << "Digite o número de eventos que deseja criar: ";
    std::cin >> numEventos; //le o numero de eventos que o usuario deseja criar
    if(numEventos < 1){
        std::cout << "Número inválido!" << std::endl;
        return;
    }
    std::cin.ignore();  //ignora o enter

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha, tipoUsuario, idUsuario, senhaUsuario;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

    }

    arquivoUsuarios.close(); //fecha o arquivo

    if (arquivoEventos.is_open()) { // Verifica se o arquivo foi aberto
        std::string linha;  //variavel para armazenar a linha do arquivo
        while (std::getline(arquivoEventos, linha)) {  //percorre o arquivo
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
        arquivoEventos.close(); //fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; //saia da função
    }

    std::ofstream arquivoSaida("eventos.txt", std::ios::app); //abre o arquivo para escrita

    for (int i = 0; i < numEventos; ++i) {  //percorre o vetor de eventos
        std::string tipo, titulo, descricao, data, hora, local, criador, id;   //variaveis para armazenar os dados do evento

        std::cout << "Criação de evento n°" << i + 1 << std::endl;
        std::cout << "Digite seu tipo de usuario (ADMIN, PROF, ALUNO): ";
        std::getline(std::cin, criador);  //le o tipo do evento
        while(criador != "ADMIN" && criador != "PROF" && criador != "ALUNO"){
            std::cout << "Tipo de usuário inválido!" << std::endl;
            std::cout << "Digite seu tipo de usuario (ADMIN, PROF, ALUNO): ";
            std::getline(std::cin, criador);  //le o tipo do evento
        }
        if(criador == "ADMIN"){
            std::cout << "Digite o tipo de evento (ACADEMICO, PROVA, TRABALHO, APRESENTACAO, PESSOAL): ";
        }else{
            std::cout << "Digite o tipo de evento (PROVA, TRABALHO, APRESENTACAO, PESSOAL): ";
        }
        std::getline(std::cin, tipo);  //le o tipo do evento
        while(tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "PESSOAL"){
            std::cout << "Tipo de evento inválido!" << std::endl;
            std::cout << "Digite o tipo de evento (PROVA, TRABALHO, APRESENTACAO, PESSOAL): ";
            std::getline(std::cin, tipo);  //le o tipo do evento
        }
        std::cout << "Digite o título do evento: ";
        std::getline(std::cin, titulo);  //le o titulo do evento

        std::cout << "Digite a descrição do evento: ";
        std::getline(std::cin, descricao);  //le a descricao do evento

        std::cout << "Digite a data do evento (DD-MM-AAAA): ";
        std::getline(std::cin, data);  //le a data do evento
        while(data.size() != 10 || data[2] != '-' || data[5] != '-'){
            std::cout << "Data inválida!" << std::endl;
            std::cout << "Digite a data do evento (DD-MM-AAAA): ";
            std::getline(std::cin, data);  //le a data do evento
        }
        std::cout << "Digite a hora do evento (HH:MM): ";
        std::getline(std::cin, hora);  //le a hora do evento
        while(hora.size() != 5 || hora[2] != ':'){
            std::cout << "Hora inválida!" << std::endl;
            std::cout << "Digite a hora do evento (HH:MM): ";
            std::getline(std::cin, hora);  //le a hora do evento
        }

        std::cout << "Digite o local do evento: ";
        std::getline(std::cin, local);  //le o local do evento
        
        
        std::cout << "Digite seu id : ";
        std::getline(std::cin, id);  //le o id do evento

        Evento novoEvento(tipo, titulo, data, hora, tipo, descricao, criador, id);  //cria um novo evento
        eventos.push_back(novoEvento); // Adiciona o novo evento ao vetor

        arquivoSaida << tipo << '|' << titulo << '|' << descricao << "|" <<  data << '|' << hora << '|' << local << '|' << criador << '|' << id << '\n'; // Escreve no arquivo
        std::cout << "Evento criado e salvo com sucesso!" << std::endl;
        

    }
    arquivoSaida.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


//metodo para adicionar um evento
void Usuario::adicionarEvento(const Evento& evento){
    _eventos.push_back(evento);
}

//metodo get para retornar os eventos
std::vector<Evento> Usuario::getEventos() {
    return _eventos;
}

//metodo get para retornar os usuarios
std::vector<Usuario> Usuario::getUsuarios() {
    return _usuarios;
}


//metodo para listar os usuarios
void Usuario::listarUsuarios(){ 
    for(const auto user : _usuarios){   //percorre o vetor de usuarios
        std::cout << "Tipo: " << user.getTipo() << std::endl;  //imprime o tipo do usuario
        std::cout << "ID: " << user.getId() << std::endl;  //imprime o id do usuario
        std::cout << "Senha: " << user.getSenha() << std::endl;  //imprime a senha do usuario
        std::cout << "==============================" << std::endl;

    }
}


