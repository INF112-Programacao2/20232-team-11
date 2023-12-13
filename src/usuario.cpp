#include "Usuario.hpp"
#include "Evento.hpp"
#include <iostream>

//construtor
Usuario::Usuario() {
    _id = "";
    _senha = "";
    _tipo = "";
}       

Usuario::Usuario(const std::string& tipo, const std::string& id, const std::string& senha) : _id(id), _senha(senha), _tipo(tipo) {}   //construtor

Usuario::~Usuario() {}      //destrutor


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

//metodo para fazer login
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
        std::cout << "Erro sistema!" << std::endl;
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
   
//metodo para pesquisar evento por titulo
void Usuario::avaliarPrograma(){
    std::cout << "=========AVALIAR PROGRAMA=========\n\n";
    std::string avaliacao, sugestao;  //variavel para armazenar a avaliacao do usuario
    std::cout << "Digite sua avaliação: \n";
    std::cout << "1 - Ótimo\n";
    std::cout << "2 - Bom\n";
    std::cout << "3 - Regular\n";
    std::cout << "4 - Ruim\n";
    std::cout << "5 - Péssimo\n";
    std::cout << "6 - Sugestão/Recomendação\n";
    std::cout << "7 - Não avaliar\n";
    std::getline(std::cin, avaliacao);  //le a avaliacao do usuario
    if(avaliacao == "6"){
        std::cout << "Digite sua sugestão/recomendação (100 caracteres máximo): \n";
        std::getline(std::cin, sugestao);  //le a avaliacao do usuario
        while(sugestao.size() > 100){
            std::cout << "Texto muito grande!" << std::endl;
            std::cout << "Digite sua sugestão/recomendação (100 caracteres máximo): \n";
            std::getline(std::cin, sugestao);  //le a avaliacao do usuario
        }
    }else if(avaliacao == "7"){
        return;
    }

    while(avaliacao != "1" && avaliacao != "2" && avaliacao != "3" && avaliacao != "4" && avaliacao != "5" && avaliacao != "6" && avaliacao != "7"){
        std::cout << "Avaliação inválida!" << std::endl;
        std::cout << "Digite sua avaliação: \n";
        std::cout << "1 - Ótimo\n";
        std::cout << "2 - Bom\n";
        std::cout << "3 - Regular\n";
        std::cout << "4 - Ruim\n";
        std::cout << "5 - Péssimo\n";
        std::cout << "6 - Sugestão/Recomendação\n";
        std::cout << "7 - Não avaliar\n";
        std::getline(std::cin, avaliacao);  //le a avaliacao do usuario
        if(avaliacao == "6"){
            std::cout << "Digite sua sugestão/recomendação (100 caracteres máximo): \n";
            std::getline(std::cin, sugestao);  //le a avaliacao do usuario
            while(sugestao.size() > 100){
                std::cout << "Texto muito grande!" << std::endl;
                std::cout << "Digite sua sugestão/recomendação (100 caracteres máximo): \n";
                std::getline(std::cin, sugestao);  //le a avaliacao do usuario
            }
        }else if(avaliacao == "7"){
            return;
        }
    }

    std::ofstream arquivoOtimo("otimo.txt", std::ios::app); //abre o arquivo para escrita
    std::ofstream arquivoBom("bom.txt", std::ios::app); //abre o arquivo para escrita
    std::ofstream arquivoRegular("regular.txt", std::ios::app); //abre o arquivo para escrita
    std::ofstream arquivoRuim("ruim.txt", std::ios::app); //abre o arquivo para escrita
    std::ofstream arquivoPessimo("pessimo.txt", std::ios::app); //abre o arquivo para escrita
    std::ofstream arquivoSugestao("sugestao.txt", std::ios::app); //abre o arquivo para escrita

    if(!arquivoOtimo.is_open() || !arquivoBom.is_open() || !arquivoRegular.is_open() || !arquivoRuim.is_open() || !arquivoPessimo.is_open() || !arquivoSugestao.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    if(avaliacao == "1"){
        arquivoOtimo << "Ótimo" << '\n'; // Escreve no arquivo
    }else if(avaliacao == "2"){
        arquivoBom << "Bom" << '\n'; // Escreve no arquivo
    }else if(avaliacao == "3"){
        arquivoRegular << "Regular" << '\n'; // Escreve no arquivo
    }else if(avaliacao == "4"){
        arquivoRuim << "Ruim" << '\n'; // Escreve no arquivo
    }else if(avaliacao == "5"){
        arquivoPessimo << "Péssimo" << '\n'; // Escreve no arquivo
    }else if(avaliacao == "6"){
        arquivoSugestao << "Sugestão/Recomendação: " << sugestao << '\n'; // Escreve no arquivo
    }

    std::cout << "Avaliação salva com sucesso!" << std::endl;
    
    //fecha os arquivos
    arquivoOtimo.close();   
    arquivoBom.close();     
    arquivoRegular.close();     
    arquivoRuim.close();    
    arquivoPessimo.close();     
    arquivoSugestao.close();

}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

void Usuario::logout() {
    std::cout << "Logout realizado com sucesso!\n" << std::endl;
    std::cout << "Obrigado por usar o Calendario Acadêmico!\n" << std::endl;
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
        std::cout << "Erro sistema!" << std::endl;
        return; //saia da função
    }

    std::ofstream arquivoSaida("usuarios.txt", std::ios::app); //abre o arquivo para escrita

    std::string tipo, id, senha, senhaDeNovo;    //variaveis para armazenar os dados do usuario

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
        std::cout << "Crie um ID de usuário (16 caracteres máximo): ";
    }
    std::getline(std::cin, id);  //le o id do usuario   
    while(id.size() > 16){
        std::cout << "ID muito grande!" << std::endl;
        std::cout << "Crie um ID de usuário (16 caracteres máximo): ";
        std::getline(std::cin, id);  //le o id do usuario
    }

    std::cout << "Crie uma senha de usuário (5 caracteres mínimo): ";
    std::getline(std::cin, senha);  //le a senha do usuario
    while(senha.size() < 5){
        std::cout << "Senha muito pequena!" << std::endl;
        std::cout << "Crie uma senha de usuário (5 caracteres mínimo): ";
        std::getline(std::cin, senha);  //le a senha do usuario
    }

    std::cout << "Digite sua senha novamente: ";
    std::getline(std::cin, senhaDeNovo);  //le a senha do usuario
    while(senhaDeNovo != senha){
        std::cout << "As senhas não coincidem!" << std::endl;
        std::cout << "Criar uma senha de usuário (5 caracteres mínimo): ";
        std::getline(std::cin, senha);  //le a senha do usuario
        while(senha.size() < 5){
            std::cout << "Senha muito pequena!" << std::endl;
            std::cout << "Criar uma senha de usuário (5 caracteres mínimo): ";
            std::getline(std::cin, senha);  //le a senha do usuario
        }
        std::cout << "Digite sua senha novamente: ";
        std::getline(std::cin, senhaDeNovo);  //le a senha do usuario
    }

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

//metodo para trocar a senha do usuario
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
        std::cout << "Erro sistema!" << std::endl;
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

            std::cout << "Digite sua nova senha (5 caracteres mínimo): ";
            std::getline(std::cin, novasenha);
            while (novasenha.size() < 5) {
                std::cout << "Senha muito pequena!" << std::endl;
                std::cout << "Digite sua nova senha (5 caracteres mínimo): ";
                std::getline(std::cin, novasenha);
            }
            std::cout << "Digite sua nova senha novamente: ";
            std::getline(std::cin, novaSenhaDeNovo);

            while (novasenha != novaSenhaDeNovo) {
                std::cout << "As senhas não coincidem!" << std::endl;
                std::cout << "Digite sua nova senha (5 caracteres mínimo): ";
                std::getline(std::cin, novasenha);
                while (novasenha.size() < 5) {
                    std::cout << "Senha muito pequena!" << std::endl;
                    std::cout << "Digite sua nova senha (5 caracteres mínimo): ";
                    std::getline(std::cin, novasenha);
                }
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

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


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


//metodo para verificar se a data é valida
bool Usuario::dataValida(const std::string& data) {
    if (data.size() != 10) {    // Verifica se a data tem o tamanho correto
        return false;
    }

    if (data[2] != '-' || data[5] != '-') { // Verifica se a data está no formato correto
        return false;
    }

    int dia = std::stoi(data.substr(0, 2)); // Converte o dia para inteiro
    int mes = std::stoi(data.substr(3, 2)); // Converte o mês para inteiro
    int ano = std::stoi(data.substr(6, 4)); // Converte o ano para inteiro

    if (dia < 1 || dia > 31) {  // Verifica se o dia é válido
        return false;
    }

    if (mes < 1 || mes > 12) {  // Verifica se o mês é válido
        return false;
    }

    if (ano < 2021) {   // Verifica se o ano é válido
        return false;
    }

    return true;
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


//metodo para verificar se a hora é valida
bool Usuario::horaValida(const std::string& hora) {
    if (hora.size() != 5) { // Verifica se a hora tem o tamanho correto
        return false;
    }

    if (hora[2] != ':') {   // Verifica se a hora está no formato correto
        return false;
    }

    int horaInt = std::stoi(hora.substr(0, 2)); // Converte a hora para inteiro
    int minuto = std::stoi(hora.substr(3, 2));  // Converte o minuto para inteiro

    if (horaInt < 0 || horaInt > 23) {  // Verifica se a hora é válida
        return false;
    }

    if (minuto < 0 || minuto > 59) {    // Verifica se o minuto é válido
        return false;
    }

    return true;
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




