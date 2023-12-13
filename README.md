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
         - três dias, um dia, uma hora e quinze minutos antes para eventos de trabalho e pessoal.

## Desafios Futuros: Oferecer Personalização de Notificações aos Usuários

Para melhorar ainda mais o Calendário Acadêmico, um desafio futuro significativo é a implementação da capacidade de personalizar as notificações para os usuários. Isso garantirá uma experiência mais adaptada e conveniente, permitindo que cada usuário ajuste as notificações de acordo com suas preferências individuais.

 * Personalização de Notificações
    - Notificações Configuráveis: Permitir que os usuários escolham o tipo de eventos para os quais desejam receber notificações (aulas, exames, eventos acadêmicos, etc.).
    - Frequência e Horário: Oferecer opções para personalizar a frequência e o horário das notificações, permitindo que os usuários ajustem a periodicidade e os momentos mais adequados para receberem alertas.
    - Métodos de Notificação: Disponibilizar opções para escolha do método de notificação preferido (notificações push, e-mail, mensagens SMS, etc.).
    - Localização e Idioma: Permitir que as notificações sejam adaptadas à localização e preferências de idioma do usuário.
    
 * Benefícios da Personalização
    - Melhor Experiência do Usuário: Oferecer controle sobre as notificações proporciona uma experiência mais personalizada e adaptada às necessidades individuais de cada usuário.
    - Maior Engajamento: Ao permitir que os usuários personalizem as notificações de acordo com suas preferências, é mais provável que eles se envolvam mais com o calendário acadêmico.
    - Eficiência e Produtividade: Notificações mais personalizadas podem ajudar os usuários a gerenciar melhor seu tempo e a se manterem informados sobre os eventos acadêmicos mais relevantes para eles.


## Autores
 * Biowa C. Fortunat H.
 * Mateus Oliveira
 * Pedro Bandeira

#####