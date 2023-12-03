#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <vector>

#include "Aluno.hpp"
#include "Professor.hpp"
#include "Adminitrador.hpp"
#include "Calendario.hpp"
#include "Usuario.hpp"

// Declaração avançada para evitar dependências cíclicas
class Aluno;
class Professor;
class Administrador;

class Interface{
private:
    bool administradorCadastrado = false;
    void executar_opcao(int opcao);
    void realizar_login(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    Administrador cadastrar_administrador();
    Professor cadastrar_professor();
    Aluno cadastrar_aluno();
    
public:
    void menu_principal(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    void menu_administrador(std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    void menu_professor(Professor& professor);
    void menu_aluno(Aluno& aluno);
    void menu_evento();
    void menu_pesquisa();
    void menu_edicao();
    void menu_exclusao();
    void menu_listagem();
    void menu_listagem_data();
    void cadastrar_usuario(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    void excluir_professor(std::vector<Professor>& professores);
    void excluir_aluno(std::vector<Aluno>& alunos);
    void professor_criar_evento(Professor& professor);
    void professor_editar_evento(Professor& professor);
    void professor_excluir_evento(Professor& professor);
    void professor_pesquisar_evento(Professor& professor);
    void professor_listar_eventos(Professor& professor);

    
       // Função para solicitar e recuperar senha
    void solicitar_e_recuperar_senha(std::vector<Aluno>& alunos, std::vector<Professor>& professores, Administrador& administrador);

    // Função genérica para encontrar um usuário pelo ID em um vetor
    template<typename UserType>
    UserType* encontrar_usuario_pelo_ID(const std::vector<UserType>& users, const std::string& id);

    // Função genérica para recuperar senha de um usuário
    template<typename UserType>
    void recuperar_senha(UserType& user);
    
    
    void aluno_criar_evento(Aluno& aluno);
    void aluno_editar_evento(Aluno& aluno);
    void aluno_excluir_evento(Aluno& aluno);
    void aluno_pesquisar_evento(Aluno& aluno);
    void aluno_listar_eventos(Aluno& aluno);
    

};

#endif