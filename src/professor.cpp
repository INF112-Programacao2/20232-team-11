#include "Professor.hpp"

Professor::Professor() {}  // Construtor

Professor::~Professor() {}  // Destrutor

// Métodos

// Métodos para criar eventos
void Professor::criarEvento(std::vector<Evento>& eventos){
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
       criador = "PROF"; //criador recebe PROF
        std::cout << "Digite o tipo de evento (PROVA, TRABALHO, APRESENTACAO, PESSOAL): ";

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

// Métodos para editar eventos
void Professor::editarEvento(){        // Edita o evento
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
                
            std::cout << "Digite o novo tipo de evento (PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
            std::getline(std::cin, novoTipo);   // Recebe o novo tipo de evento
            while(novoTipo != "PROVA" && novoTipo != "TRABALHO" && novoTipo != "APRESENTACAO" && novoTipo != "PESSOAL") {    // Verifica se o tipo de evento e valido
                std::cout << "Tipo de evento invalido!" << std::endl;
                std::cout << "Digite o novo tipo de evento (PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
                std::getline(std::cin, novoTipo);   // Recebe o novo tipo de evento
            }

            std::cout << "Digite o novo titulo do evento: ";
            std::getline(std::cin, novoTitulo);   // Recebe o novo titulo do evento

            std::cout << "Digite a nova descricao do evento: ";
            std::getline(std::cin, novaDescricao);  // Recebe a nova descricao do evento

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

            std::cout << "Digite o novo local do evento: ";
            std::getline(std::cin, novoLocal);  // Recebe o novo local do evento

            novoCriador = "PROF";  //o criador do evento é o administrador
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
void Professor::pesquisarEventoPorTipo() {
    std::cout << "==============PESQUISANDO EVENTO POR TIPO==============\n\n";
    std::string tipo, id;    // Variaveis para armazenar o tipo de evento, o tipo de usuario e o id do usuario
    std::cout << "Digite o tipo de evento a ser pesquisado (ACADEMICO, PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
    std::getline(std::cin, tipo);   // Recebe o tipo de evento
    while(tipo != "ACADEMICO" && tipo != "PROVA" && tipo != "TRABALHO" && tipo != "APRESENTACAO" && tipo != "PESSOAL") {    // Verifica se o tipo de evento e valido
        std::cout << "Tipo de evento invalido!" << std::endl;
        std::cout << "Digite o tipo de evento a ser pesquisado (ACADEMICO, PROVA - TRABALHO - APRESENTACAO - PESSOAL): ";
        std::getline(std::cin, tipo);   // Recebe o tipo de evento
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

    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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
void Professor::pesquisarEventoPorTitulo() {
    std::cout << "==============PESQUISANDO EVENTO POR TITULO==============\n\n";
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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
void Professor::pesquisarEventoPorData() { 
    std::cout << "==============PESQUISANDO EVENTO POR DATA==============\n\n"; 
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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
            if ((data == dataEvento && criador == "ADMIN") || ((data == dataEvento && criador == "PROF") && tipoEvento != "PESSOAL")) {   // Verifica se o titulo e o id do usuario existem
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
void Professor::listarTodosEventosFuturos() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS FUTUROS==============\n\n";
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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


        if(dataHoraEvento - dataHoraAtual > 0 ){
            if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
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
void Professor::listarTodosEventosPassados() {
    std::cout << "==============LISTANDO TODOS OS EVENTOS PASSADOS==============\n\n";
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


    std::cout << "==========LISTA DOS EVENTOS ENCONTRADOS==========\n\n";
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


        if(dataHoraEvento - dataHoraAtual < 0 ){
            if (id == idEvento || ((criador == "PROF" || criador == "ADMIN") && tipoEvento != "PESSOAL")) {    // Verifica se o tipo de usuario e o criador do evento sao iguais
                Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                imprimirEvento(evento); // Imprime o evento
                eventoEncontrado = true;  //eventoEncontrado recebe true
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
void Professor::exibirNotificacoes(){
    std::cout << "=======CALENDARIO ACADEMICO=======\n\n";
    std::cout << "---------Você tem uma notificação dos eventos!---------\n\n";

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
        if(dataHoraEvento - dataHoraAtual > 0 ){
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "PROF") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual && ((((dataHoraEvento - dataHoraAtual) <= 259200) || ((dataHoraEvento - dataHoraAtual) <= 86400)) || ((dataHoraEvento - dataHoraAtual) <= 3600))) { 
                    Evento evento(tipoEvento, tituloEvento, descricaoEvento, dataEvento, horaEvento, localEvento, criador, idEvento); // Cria um evento
                    imprimirEvento(evento); // Imprime o evento
                    std::cout << "**********************************" << std::endl;
                    std::cout << std::endl;
                    notificacao = true;
                }
            }
        }
    }

    if(!notificacao) {  // Verifica se a notificação foi encontrada
        std::cout << "Nenhuma notificação encontrada." << std::endl;
    }
}


/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/


// Métodos para contar o número de notificações
int Professor::getNumeroNotificacao(){
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
       
        if(dataHoraEvento - dataHoraAtual > 0 ){
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "PROF") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA" || tipoEvento == "TRABALHO"){  // 1 dia em segundos (1 jour * 24 heures * 60 minutes * 60 secondes = 86400)
                if (dataHoraEvento >= dataHoraAtual) { 
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
void Professor::contTipoEvento() const {
    
    std::cout << "- " << contEventoAcademico << " eventos acadêmicos" << std::endl;
    std::cout << "- " << contEventoApresentacao << " eventos de apresentação" << std::endl;
    std::cout << "- " << contEventoProva << " eventos de prova" << std::endl;
    std::cout << "- " << contEventoTrabalho << " eventos de trabalho" << std::endl;
    std::cout << "- " << contEventoPessoal << " eventos pessoal" << std::endl;
}

/*****************************************************************************************************************************************************************/
/*****************************************************************************************************************************************************************/

void Professor::calendarioComEventos(){
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
            if(tipoEvento == "ACADEMICO" || (tipoEvento == "PESSOAL" && criador == "PROF") || tipoEvento == "APRESENTACAO" || tipoEvento == "PROVA"){
                std::istringstream dataStream(dataEvento);  
                std::string token;
                while (std::getline(dataStream, token, '-')) {  
                    try {
                        int diaEvento = std::stoi(token);   
                        diasEventos.insert(diaEvento); 
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erreur lors de la conversion de la date en entier : " << e.what() << std::endl;
                    }
                }
            }
        }
    }
    arquivoEventos.close();

    time_t agora = time(0); //variável para armazenar a data e hora atual
    tm *tempo = localtime(&agora);  //variável para armazenar a data e hora atual
    int mesAtual = tempo->tm_mon;   //variável para armazenar o mês atual
    int anoAtual = tempo->tm_year + 1900;   //variável para armazenar o ano atual

    //logica para imprimir o calendario
    int diasPorMes[] = {31, ((anoAtual % 4 == 0 && anoAtual % 100 != 0) || anoAtual % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string nomesMeses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    std::cout << "Calendário dos eventos de " << nomesMeses[mesAtual] << " de " << anoAtual << ":" << std::endl;
    std::cout << "______________________" << std::endl;
    std::cout << "|      " << nomesMeses[mesAtual] << "       |" << std::endl;
    std::cout << "|____________________|" << std::endl;
    std::cout << "| Seg Ter Qua Qui Sex Sáb Dom |" << std::endl;
    std::cout << "|____________________|" << std::endl;

    int dia = 1;
    tm primeiroDia = { 0, 0, 0, 1, mesAtual, anoAtual - 1900 }; //variável para armazenar o primeiro dia do mês
    mktime(&primeiroDia);
    int primeiroDiaSemana = primeiroDia.tm_wday;    //variável para armazenar o primeiro dia da semana

    for (int i = 0; i < primeiroDiaSemana; i++) {       // Imprime os espaços para o primeiro dia da semana
        std::cout << "    ";
    }

    while (dia <= diasPorMes[mesAtual]) {   // Imprime os dias do mês enquanto o dia for menor ou igual ao último dia do mês
        for (int i = primeiroDiaSemana; i < 7 && dia <= diasPorMes[mesAtual]; i++) {   

            // Imprime o dia do mês com um * se o dia possuir evento 
            if (diasEventos.find(dia) != diasEventos.end()) {   // Verifica se o dia possui evento
                std::cout << std::setw(2) << dia << "* ";
            } else {
                std::cout << std::setw(3) << dia << " ";
            }
            dia++;
        }
        std::cout << std::endl;
        primeiroDiaSemana = 0;  // Reseta o primeiro dia da semana
    }
    std::cout << std::endl;
}