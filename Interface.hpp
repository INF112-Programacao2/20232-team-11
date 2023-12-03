#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>

// Declaração avançada para evitar dependências cíclicas
class Aluno;
class Professor;
class Administrador;

class Interface{
private:
    bool administradorCadastrado = false;
    void executar_opcao(int opcao);
    void recuperar_senha(Aluno& aluno, Professor& professor, Administrador& administrador);
    void realizar_login(Aluno& aluno, Professor& professor , Administrador& administrador ,std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    void excluir_aluno(std::vector<Aluno>& alunos);
    Aluno& escolher_aluno();
    Administrador cadastrar_administrador();
    Professor cadastrar_professor();
    Aluno cadastrar_aluno();
public:
    void menu_principal(Aluno& aluno, Professor& professor, Administrador& administrador, std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    void menu_administrador(std::vector<Aluno>& alunos, std::vector<Professor>& professores);
    void menu_professor(Professor& professor);
    void menu_aluno();
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
    

};

#endif