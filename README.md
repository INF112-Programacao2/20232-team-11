# Calendário Acadêmico

O **Calendário Acadêmico** é uma plataforma projetada para facilitar a troca de eventos entre administradores, professores e estudantes. Seu objetivo é permitir a gestão de eventos acadêmicos, como trabalhos, tarefas, apresentações, além de eventos pessoais. Este programa oferece a capacidade de criar, modificar, excluir eventos, realizar pesquisas por tipo, data, título, listar eventos todos, por usúario e enviar notificações aos usuários no momento apropriado.

## Funcionalidades
   * Funcionalidades de base:
     - Criação do usúario
     - Login
     - Trocar senha caso esquecir
     - Logout
     - Avaliar o programa

   * Funcionalidades principais:
     - Criação de eventos de tipo acadêmicos (prova, trabalho, apresentação) e de tipo pessaois.
     - Edição de eventos.
     - Exclusão de eventos.
     - Listagem de eventos:
        * futuros
        * passados
        * pessoal

     - Pesquisar de eventos:
        * por título
        * por data
        * por tipo

     - Enviar notificações aos usuários no momento adequado dependendo do tipo de usúario e do tipo de evento.

     ![Alt text](Interface-1.png)
     ![Alt text](Interface-2.png)
     ![Alt text](Interface-3.png)


## Manuel Usuario
 * 1- Certifique-se de ter todos os arquivos em um único diretório a partir do qual você executará o programa.
 * 2- No terminal, execute o seginte comando:
      - comando: make run
 * 3- Explorar o programa "Calendario Acadêmico".

    ## Criação dos eventos:
      O programa define cinco tipos de eventos: Puramente Acadêmico, Prova, Trabalho, Apresentação e Evento Pessoal. Apenas os administradores têm permissão para criar eventos do tipo Puramente Acadêmico (visível para todoas os usuários), além dos outros tipos de eventos. Os professores têm permissão para criar todos os tipos de eventos, exceto os eventos Puramente Acadêmicos. Por fim, os estudantes podem criar somente eventos do tipo Evento Pessoal.
   
    ## Modo de exibição das notificações:
      * para os usuários do tipo administrador ou professor, as notificações começam três dias, um dia, e uma hora antes do evento independentemente do tipo.
      * para os usúarios do tipo estudante, as notificações variam conforme o tipo de evento:
         - uma semana, três dias, um dia, e uma hora antes para eventos de prova.
         - três dias, um dia, e uma hora antes para eventos de apresentação ou do tipo acadêmico.
         - três dias, um dia, uma hora e quinze minutos antes para eventos de trabalho.


## Autores
 * Biowa C. Fortunat H.
 * Mateus Oliveira
 * Pedro Bandeira

#####