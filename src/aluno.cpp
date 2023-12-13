#include "Aluno.hpp"

Aluno::Aluno() {}    // Construtor
Aluno::~Aluno() {}      // Destrutor

//Metodos

//metodo para criar um evento
void Aluno::criarEvento(std::vector<Evento>& eventos){
    int numEventos = 0; //variavel para armazenar o numero de eventos que o usuario deseja criar
    std::cout << "=========CRIANDO EVENTO=========\n\n";
    std::cout << "Digite o número de eventos que deseja criar: ";
    std::cin >> numEventos; //le o numero de eventos que o usuario deseja criar
    if(numEventos < 1){
        std::cout << "Número inválido!" << std::endl;
        return;
    }
    std::cin.ignore();  //ignora o \n

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
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
        std::cout << "Erro sistema!" << std::endl;
        return; //saia da função
    }

    std::ofstream arquivoSaida("eventos.txt", std::ios::app); //abre o arquivo para escrita

    for (int i = 0; i < numEventos; ++i) {  //percorre o vetor de eventos
        std::string tipo, titulo, descricao, data, hora, local, criador, id;   //variaveis para armazenar os dados do evento

        std::cout << "Criação de evento n°" << i + 1 << std::endl;
        criador = "ALUNO";  //criador recebe ALUNO
        tipo = "PESSOAL";   //tipo recebe PESSOAL

        std::cout << "Digite o título do evento (30 caracteres máximo): ";
        std::getline(std::cin, titulo);  //le o titulo do evento
        while(titulo.size() > 30){  //verifica se o titulo possui o tamanho correto
            std::cout << "Título muito grande!" << std::endl;
            std::cout << "Digite o título do evento (30 caracteres máximo): ";
            std::getline(std::cin, titulo);  //le o titulo do evento
        }

        std::cout << "Digite a descrição do evento (100 caracteres máximo): ";
        std::getline(std::cin, descricao);  //le a descricao do evento
        while(descricao.size() > 100){  //verifica se a descricao possui o tamanho correto
            std::cout << "Descrição muito grande!" << std::endl;
            std::cout << "Digite a descrição do evento (100 caracteres máximo): ";
            std::getline(std::cin, descricao);  //le a descricao do evento
        }

        std::cout << "Digite a data do evento (DD-MM-AAAA): ";
        std::getline(std::cin, data);  //le a data do evento
        while(!Usuario::dataValida(data)){
            std::cout << "Data inválida!" << std::endl;
            std::cout << "Digite a data do evento (DD-MM-AAAA): ";
            std::getline(std::cin, data);  //le a data do evento
        }
        std::cout << "Digite a hora do evento (HH:MM): ";
        std::getline(std::cin, hora);  //le a hora do evento
        while(!Usuario::horaValida(hora)){
            std::cout << "Hora inválida!" << std::endl;
            std::cout << "Digite a hora do evento (HH:MM): ";
            std::getline(std::cin, hora);  //le a hora do evento
        }

        std::cout << "Digite o local do evento (20 caracteres máximo): ";
        std::getline(std::cin, local);  //le o local do evento
        while(local.size() > 20){  //verifica se o local possui o tamanho correto
            std::cout << "Local muito grande!" << std::endl;
            std::cout << "Digite o local do evento (20 caracteres máximo): ";
            std::getline(std::cin, local);  //le o local do evento
        }
        
        
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


// Método para listar todos os eventos futuros
void Aluno::editarEvento(){        // Edita o evento
    std::cout << "==============EDITANDO EVENTO==============\n\n";
    std::string id, titulo, novoTipo, novaDescricao, novaData, novaHora, novoLocal, novoCriador, novoTitulo; // Variables pour stocker les informations de l'événement
    std::cout << "Digite o titulo do evento: ";
    std::getline(std::cin, titulo); // Saisie du titre de l'événement
    std::cout << "Digite o seu ID de usuario: ";
    std::getline(std::cin, id); // Saisie de l'ID de l'utilisateur

    std::ifstream arquivoUsuarios("usuarios.txt");
    std::ifstream arquivoEventos("eventos.txt");

    if (!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {
        std::cout << "Erro sistema!" << std::endl;
        return;
    }

    bool idEncontrado = false;
    bool eventoEncontrado = false;

    std::ofstream arquivoTemporario("tempEvento.txt");

    std::string linha, tipoUsuario, idUsuario, senhaUsuario;
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');
        if (id == idUsuario) {
            idEncontrado = true;
            break;
        }
    }

    if (!idEncontrado) {
        std::cout << "ID nao existe!" << std::endl;
        return;
    }

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

        if (id == idEvento && titulo == tituloEvento) {
            eventoEncontrado = true;
                
            novoTipo = "PESSOAL";

            std::cout << "Digite o novo titulo do evento (30 caracteres máximo): ";
            std::getline(std::cin, novoTitulo);   // Recebe o novo titulo do evento
            while(novoTitulo.size() > 30) {  // Verifica se o titulo possui o tamanho correto
                std::cout << "Titulo muito grande!" << std::endl;
                std::cout << "Digite o novo titulo do evento (30 caracteres máximo): ";
                std::getline(std::cin, novoTitulo);   // Recebe o novo titulo do evento
            }

            std::cout << "Digite a nova descricao do evento (100 caracteres máximo): ";
            std::getline(std::cin, novaDescricao);  // Recebe a nova descricao do evento
            while(novaDescricao.size() > 100) { // Verifica se a descricao possui o tamanho correto
                std::cout << "Descricao muito grande!" << std::endl;
                std::cout << "Digite a nova descricao do evento (100 caracteres máximo): ";
                std::getline(std::cin, novaDescricao);  // Recebe a nova descricao do evento
            }

            std::cout << "Digite a nova data do evento (DD-MM-AAAA): ";
            std::getline(std::cin, novaData);   // Recebe a nova data do evento
            while(!Usuario::dataValida(novaData)) { // Verifica se a data possui o tamanho correto
                std::cout << "Data invalida!" << std::endl;
                std::cout << "Digite a nova data do evento (DD-MM-AAAA): ";
                std::getline(std::cin, novaData);   // Recebe a nova data do evento
            }

            std::cout << "Digite a nova hora do evento (HH:MM): ";
            std::getline(std::cin, novaHora);   // Recebe a nova hora do evento
            while(!Usuario::horaValida(novaHora )) { // Verifica se a hora possui o tamanho correto
                std::cout << "Hora invalida!" << std::endl;
                std::cout << "Digite a nova hora do evento (HH:MM): ";
                std::getline(std::cin, novaHora);   // Recebe a nova hora do evento
            }

            std::cout << "Digite o novo local do evento (20 caracteres máximo): ";
            std::getline(std::cin, novoLocal);  // Recebe o novo local do evento
            while(novoLocal.size() > 20) {  // Verifica se o local possui o tamanho correto
                std::cout << "Local muito grande!" << std::endl;
                std::cout << "Digite o novo local do evento (20 caracteres máximo): ";
                std::getline(std::cin, novoLocal);  // Recebe o novo local do evento
            }

            novoCriador = "ALUNO";  //o criador do evento é o administrador
            arquivoTemporario << novoTipo << "|" << novoTitulo << "|" << novaDescricao << "|" << novaData << "|" << novaHora << "|" << novoLocal << "|" << novoCriador << "|" << id << std::endl;
        } else {
            arquivoTemporario << linha << std::endl;
        }
        
    }

    arquivoEventos.close();
    arquivoTemporario.close();

    if (!eventoEncontrado) {
        std::cout << "Evento não encontrado!" << std::endl;
        return;
    }

    std::remove("eventos.txt");
    std::rename("tempEvento.txt", "eventos.txt");

    if(eventoEncontrado && idEncontrado){
        std::cout << "Evento editado com sucesso!" << std::endl;
    }   
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para pesquisar eventos por tipo
void Aluno::pesquisarEventoPorTipo() {
    std::cout << "==============PESQUISANDO EVENTO POR TIPO==============\n";
    std::string tipo, id;    // Variaveis para armazenar o tipo de evento, o tipo de usuario e o id do usuario
    std::cout << "Digite o tipo de evento a ser pesquisado (ACADEMICO, PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
    std::getline(std::cin, tipo);   // Recebe o tipo de evento
    if(tipo != "ACADEMICO" && tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "PESSOAL") {    // Verifica se o tipo de evento e valido
        std::cout << "Tipo de evento invalido!" << std::endl;
        return; // sai da funcao
    }

    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual
            if (tipo != "PESSOAL" && ((tipo == tipoEvento) && (criador == "PROF" || criador == "ADMIN"))) {   // Verifica se o tipo de evento e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento futuro" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
            }else if(tipo == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento futuro" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;  //eventoEncontrado recebe true
                }
            }
        }else{
            if(tipo != "PESSOAL" && ((tipo == tipoEvento) && (criador == "PROF" || criador == "ADMIN"))) {   // Verifica se o tipo de evento e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento passado" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
            }else if(tipo == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento passado" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;  //eventoEncontrado recebe true
                }
            }
        }
    }

    if(!eventoEncontrado) {   // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para pesquisar eventos por título
void Aluno::pesquisarEventoPorTitulo() {
    std::cout << "==============PESQUISANDO EVENTO POR TITULO==============\n";
    std::string titulo, id;   // Variaveis para armazenar o titulo, o tipo e o id do usuario
    std::cout << "Digite o titulo do evento a ser pesquisado: ";
    std::getline(std::cin, titulo); // Recebe o titulo do evento

    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual

            if(((titulo == tituloEvento && criador == "ADMIN") || (titulo == tituloEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento futuro" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(titulo == tituloEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento futuro" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
            }
        }else{
            if(((titulo == tituloEvento && criador == "ADMIN") || (titulo == tituloEvento && criador == "PROF")) && tipoEvento != "PESSOAL") {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento passado" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(titulo == tituloEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento passado" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
            }
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para pesquisar eventos por data
void Aluno::pesquisarEventoPorData() { 
    std::cout << "==============PESQUISANDO EVENTO POR DATA==============\n"; 
    std::string data, id;   // Variaveis para armazenar a data e o tipo de usuario
    std::cout << "Digite a data do evento a ser pesquisado (DD-MM-AAAA): ";
    std::getline(std::cin, data);   // Recebe a data do evento
    if(!Usuario::dataValida(data)) { // Verifica se a data possui o tamanho correto
        std::cout << "Data invalida!" << std::endl;
        return; // sai da funcao
    }

    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario

    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento

        if(dataHoraEvento - dataHoraAtual > 0) {   //verifica se a data do evento é maior que a data atual
            if ((data == dataEvento && criador == "ADMIN") || ((data == dataEvento && criador == "PROF") && tipoEvento != "PESSOAL")) {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento futuro" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(data == dataEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento futuro" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
            }
        }else{
            if((data == dataEvento && criador == "ADMIN") || ((data == dataEvento && criador == "PROF") && tipoEvento != "PESSOAL")) {   // Verifica se o titulo e o id do usuario existem
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                std::cout << "Evento passado" << std::endl;
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }else if(data == dataEvento && tipoEvento == "PESSOAL"){
                if(id == idEvento){
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    std::cout << "Evento passado" << std::endl;
                    imprimirEvento(evento); // Imprime o evento
                    eventoEncontrado = true;    //eventoEncontrado recebe true
                }
            }
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

// Métodos para listar todos os eventos futuros
void Aluno::listarTodosEventosFuturos() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS==============\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario
   
    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
        
        if(dataHoraEvento - dataHoraAtual > 0 ){ // Verifica se a data do evento e posterior a data atual
            if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para listar todos os eventos passados
void Aluno::listarTodosEventosPassados() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS==============\n";
    std::string id;    // Variaveis para armazenar o tipo de usuario e o id do usuario
    std::cout << "Digite o seu id de usuario: ";
    std::getline(std::cin, id); // Recebe o id do usuario
   
    std::ifstream arquivoUsuarios("usuarios.txt"); //abre o arquivo para leitura
    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoUsuarios.is_open() || !arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro sistema!" << std::endl;
        return; // sai da funcao
    }

    std::string linha; //variavel para armazenar a linha do arquivo
    bool eventoEncontrado = false;    //variavel para verificar se o evento foi encontrado
    bool idEncontrado = false; //variavel para verificar se o usuario foi encontrado

    //percorre o arquivo de usuários para encontrar o id do usuário
    while (std::getline(arquivoUsuarios, linha)) {
        std::stringstream ss(linha);
        std::string tipoUsuario, idUsuario, senhaUsuario;
        std::getline(ss, tipoUsuario, '|');
        std::getline(ss, idUsuario, '|');
        std::getline(ss, senhaUsuario, '|');

        if (id == idUsuario) {  // Verifica se o id do usuario existe
            idEncontrado = true;    //idEncontrado recebe true
        }
    }

    if(!idEncontrado) { // Verifica se o id do usuario foi encontrado
        std::cout << "Id invalido!" << std::endl;
        return; // sai da funcao
    }


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n";
    //percorre o arquivo de eventos para encontrar os eventos associados ao id do usuário
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

        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
        
        if(dataHoraEvento - dataHoraAtual < 0 ){ // Verifica se a data do evento e posterior a data atual
            if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;    //eventoEncontrado recebe true
            }
        }
    }

    if(!eventoEncontrado) { // Verifica se o evento foi encontrado
        std::cout << "Nenhum evento encontrado." << std::endl;
    }

    arquivoEventos.close(); //fecha o arquivo
}



/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para exibir notificações
void Aluno::exibirNotificacoes(){
    std::cout << "=======CALENDARIO ACADEMICO=======" << std::endl;
    std::cout << std::endl;
    std::cout << "---------Você tem uma notificação dos eventos!---------" << std::endl;
    std::cout << std::endl;
    bool notificacao = false; // variável para verificar se a notificação foi encontrada
    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        return; // sai da funcao
    }

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;

    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);    //cria um fluxo de string
        std::string linha, tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;  //variáveis para armazenar os dados do evento

        //ler os dados do arquivo
        std::getline(ss, tipoEvento, '|');  
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
        if(dataHoraEvento - dataHoraAtual > 0 ){ // Verifica se a data do evento e posterior a data atual
            notificacao = true;
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ALUNO") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if(tipoEvento == "PROVA"){                                          // 1 semana em segundos (1 semaine * 7 jours * 24 heures * 60 minutes * 60 secondes = 604800)
                    if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 604800) || ((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400)) || ((dataHoraEvento - dataHoraAtual) <= 3600)))  {    
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }                                                                // 15 minutos em segundos (15 minutes * 60 secondes = 900)
                }else if(tipoEvento == "TRABALHO"){                                 // 3 dias em segundos (3 jours * 24 heures * 60 minutes * 60 secondes = 259200)
                    if (dataHoraEvento >= dataHoraAtual && (((((dataHoraEvento - dataHoraAtual) <= 259200) || (dataHoraEvento - dataHoraAtual) <= 86400) ||((dataHoraEvento - dataHoraAtual) <= 3600)) || ((dataHoraEvento - dataHoraAtual) <= 900))) {    
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }                                                                                               //uma hora em segundos (1 heure * 60 minutes * 60 secondes = 3600)
                }else if(tipoEvento == "APRESENTACAO" || tipoEvento == "ACADEMICO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                    if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400)) || ((dataHoraEvento - dataHoraAtual) <= 3600))) { 
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }
                }else if(tipoEvento == "PESSOAL" && criador == "ALUNO"){
                    if (dataHoraEvento >= dataHoraAtual && (((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400) || ((dataHoraEvento - dataHoraAtual) <= 3600))) { 
                        //exibe os dados do evento
                        Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                        imprimirEvento(evento); // Imprime o evento
                        notificacao = true;
                    }
                
                }
            }
        }
    }

    if(!notificacao) { // Verifica se a notificação foi encontrada
        std::cout << "Nenhuma notificação encontrada." << std::endl;
    }
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para retornar o número de notificações
int Aluno::getNumeroNotificacao(){

    std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual

    std::ifstream arquivoEventos("eventos.txt"); //abre o arquivo para leitura

    if(!arquivoEventos.is_open()) {    // Verifica se o arquivo foi aberto
        return 0; // sai da funcao
    }

    //percorre o arquivo de usuários para encontrar o id do usuário
    std::string linha;

    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);    //cria um fluxo de string
        std::string linha, tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;  //variáveis para armazenar os dados do evento

        //ler os dados do arquivo
        std::getline(ss, tipoEvento, '|');  
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
       
        if(dataHoraEvento - dataHoraAtual > 0 ){ //
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ALUNO") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual) { //
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    eventos.push_back(evento);
                    if(tipoEvento == "ACADEMICO"){
                        contEventoAcademico++;
                    }else if(tipoEvento == "PESSOAL"){
                        contEventoPessoal++;
                    }else if(tipoEvento == "APRESENTACAO"){
                        contEventoApresentacao++;
                    }else if(tipoEvento == "PROVA"){
                        contEventoProva++;
                    }else if(tipoEvento == "TRABALHO"){
                        contEventoTrabalho++;
                    }
                }
            }
        }
    }

    return eventos.size();
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para contar o número de eventos por tipo
void Aluno::contTipoEvento() const {
    std::cout << "- " << contEventoAcademico << " eventos acadêmicos" << std::endl;
    std::cout << "- " << contEventoApresentacao << " eventos de apresentação" << std::endl;
    std::cout << "- " << contEventoProva << " eventos de prova" << std::endl;
    std::cout << "- " << contEventoPessoal << " eventos pessoal" << std::endl;
}

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

void Aluno::calendarioComEventos(){
    std::set<int> diasEventos;  //variável para armazenar os dias dos eventos
    std::ifstream arquivoEventos("eventos.txt");

    if (!arquivoEventos.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivoEventos, linha)) {
        std::stringstream ss(linha);
        std::string linha, tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento;
        std::string palavra;

        // Ler os dados do arquivo
        std::getline(ss, tipoEvento, '|');  
        std::getline(ss, tituloEvento, '|');
        std::getline(ss, descricaoEvento, '|');
        std::getline(ss, dataEvento, '|');
        std::getline(ss, horaEvento, '|');
        std::getline(ss, localEvento, '|');
        std::getline(ss, criador, '|');
        std::getline(ss, idEvento, '|');

        std::tm tempo = {};
        std::istringstream dado(dataEvento + " " + horaEvento); //variável para armazenar a data e hora do evento
        dado >> std::get_time(&tempo, "%d-%m-%Y %H:%M");    //converte a data e hora do evento para o tipo time_t
        std::time_t dataHoraAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //variável para armazenar a data e hora atual
        
        if (dado.fail()) {
            continue;   //pula para a próxima iteração
        }

        std::time_t dataHoraEvento = std::mktime(&tempo);   //variável para armazenar a data e hora do evento
        if(dataHoraEvento - dataHoraAtual > 0 ){
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "ALUNO") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA"){
                std::istringstream dataStream(dataEvento); 
                std::string token;
                while (std::getline(dataStream, token, '-')) { 
                    try {
                        int diaEvento = std::stoi(token); 
                        diasEventos.insert(diaEvento); 
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erreur sistema" << e.what() << std::endl;
                    }
                }
            }
        }
    }
    arquivoEventos.close();

    time_t agora = time(0);
    tm *tempo = localtime(&agora);
    int mesAtual = tempo->tm_mon;
    int anoAtual = tempo->tm_year + 1900;

   int diasPorMes[] = {31, ((anoAtual % 4 == 0 && anoAtual % 100 != 0) || anoAtual % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string nomesMeses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    //imprime o calendário
    std::cout << "Calendário dos eventos de " << nomesMeses[mesAtual] << " de " << anoAtual << ":" << std::endl;
    std::cout << "______________________" << std::endl;
    std::cout << "|      " << nomesMeses[mesAtual] << "       |" << std::endl;
    std::cout << "|____________________|" << std::endl;
    std::cout << "|Seg Ter Qua Qui Sex Sáb Dom |" << std::endl;
    std::cout << "|____________________|" << std::endl;

    int dia = 1;    //variável para armazenar o dia do mês
    tm primeiroDia = { 0, 0, 0, 1, mesAtual, anoAtual - 1900 }; //variável para armazenar o primeiro dia do mês
    mktime(&primeiroDia);       //converte a data para o tipo time_t
    int primeiroDiaSemana = (primeiroDia.tm_wday + 6) % 7;   

    for (int i = 0; i < primeiroDiaSemana; i++) {
        std::cout << "    ";        //imprime os espaços em branco para alinhar os dias do mês
    }

    //imprime os dias do mês
    while (dia <= diasPorMes[mesAtual] || primeiroDiaSemana != 0) {     //enquanto o dia for menor ou igual ao número de dias do mês ou o primeiro dia da semana for diferente de 0
        for (int i = primeiroDiaSemana; i < 7; i++) {
            if (dia <= diasPorMes[mesAtual]) {    //verifica se o dia é menor ou igual ao número de dias do mês
                if (dia < 10) {     //verifica se o dia é menor que 10
                    std::cout << " ";   
                }
                if (diasEventos.find(dia) != diasEventos.end()) {
                    std::cout << dia << "* ";       //imprime o dia do mês com um '*' para indicar que há um evento neste dia
                } else {
                    std::cout << dia << "  ";       //imprime o sem um '*' para indicar que não há um evento neste dia
                }
            } else {
                std::cout << "   ";     //imprime os espaços em branco para alinhar os dias do mês
            }
            dia++;      //incrementa o dia
        }
        std::cout << std::endl;
        primeiroDiaSemana = 0;      //primeiroDiaSemana recebe 0 para que o dia da semana seja reiniciado
    }
    std::cout << std::endl;
}