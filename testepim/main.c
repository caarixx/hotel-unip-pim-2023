#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "func.h"
#include <conio.h>

    int day_of_year(int year, int month, int day) {
        static int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        return days[month - 1] + day + (month > 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int days_between_dates(int checkin_year, int checkin_month, int checkin_day, int checkout_year, int checkout_month, int checkout_day) {
    int days_checkin = day_of_year(checkin_year, checkin_month, checkin_day);
    int days_checkout = day_of_year(checkout_year, checkout_month, checkout_day);
    int days_in_years = 0;

    // Calculate days between full years
    for (int year = checkin_year + 1; year < checkout_year; year++) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            days_in_years += 366;
        } else {
            days_in_years += 365;
        }
    }

    void getCheckinAndCheckoutDates(int *checkin_day, int *checkin_month, int *checkin_year, int *checkout_day, int *checkout_month, int *checkout_year) {
    printf("Digite a data de check-in (dia mês ano): ");
    scanf("%d %d %d", checkin_day, checkin_month, checkin_year);
    fflush(stdin);

    printf("Digite a data de check-out (dia mês ano): ");
    scanf("%d %d %d", checkout_day, checkout_month, checkout_year);
    fflush(stdin);

    int days = days_between_dates(*checkin_year, *checkin_month, *checkin_day, *checkout_year, *checkout_month, *checkout_day);

    if (days >= 0) {
        printf("Número total de diárias atualizado é: %d\n", days);
    } else {
        printf("A data de check-out deve ser posterior à data de check-in.\n");
    }
}

    int days_between = days_checkout - days_checkin + days_in_years;

    return days_between;
}

    struct cadastrado{
        int ja_cadastrado_luxo1;
        int ja_cadastrado_luxo2;
        int ja_cadastrado_luxo3;
        int ja_cadastrado_luxo4;

        int ja_cadastrado_suite1;
        int ja_cadastrado_suite2;
        int ja_cadastrado_suite3;
        int ja_cadastrado_suite4;

        int ja_cadastrado_standard1;
        int ja_cadastrado_standard2;
        int ja_cadastrado_standard3;
        int ja_cadastrado_standard4;
    };

    struct hospede{
        char confirmacao[100];
        float total;
        int numero_diarias;
        int resposta_pagamento;
        float total_parcelamento;
        int divisao_cartao;
    };


    struct registro {
        char data_checkin[100];
        char data_checkout[100];
    };

    struct opcoes {
        int resposta_menu;
        int resposta_voltar;
    };

    struct quartos{
        int cancelar_reserva;
        int minhas_reservas_quarto;
        int resposta_numero_quarto;
        char resposta_quarto[5];
        int tipo_quarto;

    };


    typedef struct {
        char nome_confirmacao[100];
        char nome[100];
        char email[100];
        char genero[50];
        char documento[100];
        char fone[100];
        char fone_emergencia[100];
        char confirmacao[100];
        char nome_acompanhante[100];
        char documento_acompanhante[100];
        char fone_acompanhante[100];
        char confirmacao_dados[100];
        char resposta[5];
    }cadastro;

    cadastro cadastro_hospede();


int main()
{//a começo

    setlocale(LC_ALL, "Portuguese");


    int checkin_year, checkin_month, checkin_day;
    int checkout_year, checkout_month, checkout_day;

    struct hospede hosp_luxo, hosp_suite, hosp_standart;

    struct quartos escolha_quarto;

    struct opcoes opcao;

    float hosp_luxo_valor_diaria = 1000;
    float hosp_standart_valor_diaria = 150;
    float hosp_suite_valor_diaria = 500;

    float hosp_luxo_taxas = 20;
    float hosp_standart_taxas = 20;
    float hosp_suite_taxas = 20;

    char numero_cartao[17], data_validade[7], codigo_seguranca_cartao[3];

    char nome_administrador_relatorio[100], nome_admin_reserva[100];

    float fat_suite = 0, fat_standard = 0, fat_total,  fat_luxo = 0, fat_reserva_luxo = 0, fat_reserva_suite = 0, fat_reserva_standard = 0;

    int fat_luxo1_att, fat_luxo2_att, fat_luxo3_att;

    int padrao_quarto_reservas_luxo, padrao_num_diarias_luxo, padrao_quarto_reservas_suite, padrao_num_diarias_suite, padrao_quarto_reservas_standard, padrao_num_diarias_standard;

    int num_diarias_qreserva_luxo = 0, num_diarias_qreserva_suite = 0, num_diarias_qreservas_standard = 0;

    int menu_voltar, resp_info, resp_relatorio, resp_numero_quarto, resp_minhas_reservas, resp_minhas_reservas_num, resp_cancelamento, resp_senha_admin, resp_senha_reserva, resp_usuario, resp_alteracao_reserva, resp_muda_quarto, res_quarto_reserva, resp_reserva_sim_nao, resp_reser_tipoq, resp_tipoq_mreservas, resp_confirma_dados;

    int num_diarias_luxo1 = 0, num_diarias_luxo2 = 0, num_diarias_luxo3 = 0, num_diarias_suite1 = 0, num_diarias_suite2 = 0, num_diarias_suite3 = 0, num_diarias_standard1 = 0, num_diarias_standard2 = 0, num_diarias_standard3 = 0, num_diarias_luxo4 = 0, num_diarias_suite4 = 0, num_diarias_standard4 = 0;

    int total_quartos_reservados_luxo = 0, total_quartos_reservados_suite = 0, total_quartos_reservados_standard = 0, total_quartos_reservados = 0;

    int num_total_diarias_luxo = 0, num_total_diarias_suite = 0, num_total_diarias_standard = 0;

    int continuar = 1;

    struct cadastrado cadastrados;

    int total_reservas = 0;

    cadastrados.ja_cadastrado_luxo1 = 0;
    cadastrados.ja_cadastrado_luxo2 = 0;
    cadastrados.ja_cadastrado_luxo3 = 0;
    cadastrados.ja_cadastrado_luxo4 = 0;

    cadastrados.ja_cadastrado_suite1 = 0;
    cadastrados.ja_cadastrado_suite2 = 0;
    cadastrados.ja_cadastrado_suite3 = 0;
    cadastrados.ja_cadastrado_suite4 = 0;

    cadastrados.ja_cadastrado_standard1 = 0;
    cadastrados.ja_cadastrado_standard2 = 0;
    cadastrados.ja_cadastrado_standard3 = 0;
    cadastrados.ja_cadastrado_standard4 = 0;


    struct registro registros;

    while (continuar) {//b começo

        printf("\n=======Seja bem vindo ao hotel UNIP!=======\n\n");

        printf("Por favor, escolha uma das opções de serviço:\n");

        printf("[1] Minhas Reservas\n");// ultimo(incluir opção de cancelamento) ok
        printf("[2] Nova Reserva\n"); // primeiro ok
        printf("[3] Informações Gerais\n"); //ok
        printf("[4] Gerar Relatórios\n"); //ok
        printf("[5] Sair\n\n");//ok

        scanf("%d", &opcao.resposta_menu);
        fflush(stdin);

        switch (opcao.resposta_menu){//c começo

            case 1 :
           //opção de verificar a reserva.
            printf("Selecione o modelo de quarto reservado:\n\n");
            printf("[7] Quarto de Luxo\n");
            printf("[8] Quarto Suite\n");
            printf("[9] Quarto Standard\n");

            scanf("%d", &resp_minhas_reservas);
            fflush(stdin);

                switch(resp_minhas_reservas){//d começo

                    case 7 :
                            resp_minhas_reservas_num = 0;
                            printf("Seu quarto reservado foi o Quarto de Luxo.\n\n");
                            printf("Informe o número do quarto reservado (1 ao 3):  ");
                            scanf("%d", &resp_minhas_reservas_num);
                            fflush(stdin);

                            if(resp_minhas_reservas_num > 3 && resp_minhas_reservas_num != 10){
                                printf("\nQuarto inválido!\n");
                                continuar = 1;
                            } else {//começo else caso numero errado luxo

                            padrao_quarto_reservas_luxo = 0;
                            padrao_num_diarias_luxo = 0;

                            if(resp_minhas_reservas_num == 1){//começo p
                                padrao_quarto_reservas_luxo = cadastrados.ja_cadastrado_luxo1;
                                padrao_num_diarias_luxo = num_diarias_luxo1;
                            };//fim p
                            if (resp_minhas_reservas_num == 2){
                                padrao_quarto_reservas_luxo = cadastrados.ja_cadastrado_luxo2;
                                padrao_num_diarias_luxo = num_diarias_luxo2;
                            };
                            if(resp_minhas_reservas_num == 3){
                                padrao_quarto_reservas_luxo = cadastrados.ja_cadastrado_luxo3;
                                padrao_num_diarias_luxo = num_diarias_luxo3;
                            };
                            if(resp_minhas_reservas_num == 10){
                                padrao_quarto_reservas_luxo = cadastrados.ja_cadastrado_luxo4;
                                padrao_num_diarias_luxo = num_diarias_luxo4;};

                            if(padrao_quarto_reservas_luxo == 0){//ma começo
                                    printf("\nNão há reserva nesse quarto!\nPressione qualquer tecla para voltar ao menu incial.\n");
                                    getch();
                                    continuar = 1;
                            }//ma fim
                                else {
                                    printf("Escolha uma das opções de serviço:\n[1] Mudar check-in e check-out e/ou Mudar opção de quarto.\n[2] Cancelar reserva.\n");
                                    scanf("%d", &resp_alteracao_reserva);
                                    fflush(stdin);

                                    switch(resp_alteracao_reserva){//mb começo
                                    case 1:
                                        printf("\nDeseja alterar data check-in e check-out?\n[1] Sim.\n[2] Não.\n");
                                        scanf("%d", &resp_reserva_sim_nao);
                                        fflush(stdin);

                                        if(resp_reserva_sim_nao == 1){//mc começo
                                                padrao_num_diarias_luxo = 0;

                                                printf("Digite a nova data de check-in (dia mês ano): ");
                                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                                fflush(stdin);

                                                printf("Digite a nova data de check-out (dia mês ano): ");
                                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                                fflush(stdin);


                                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                                if (days >= 0) {
                                                    printf("Número total de diárias atualizado é: %d\n", days);
                                                } else {
                                                    printf("A data de check-out deve ser posterior à data de check-in.\n");
                                                };

                                                padrao_num_diarias_luxo = days;
                                                printf("\nA diferença será acertada no ato do check-in!\n");
                                        }//mc fim
                                            else {
                                                    printf("\nData de check-in e check-out não alterada\n");};


                                        printf("\nDeseja alterar o tipo de quarto?\n[1] Sim.\n[2] Não.\n");
                                        scanf("%d", &resp_reser_tipoq);
                                        fflush(stdin);

                                        if (resp_reser_tipoq == 1){//md começo
                                                printf("\nPara o seu conhecimento estará sendo realocado para um dos nossos quartos reservas, para que não haja conflito na disponibilidade dos quartos principais.\n *Não há diferença entre os serviços oferecidos dos quartos principais para os reservas*\n");
                                                printf("\nPara qual tipo de quarto deseja alterar?\n[1] Quarto Suite.\n[2] Quarto standard.\n");
                                                scanf("%d", &resp_tipoq_mreservas);

                                                    if (resp_tipoq_mreservas == 1){//ec começo
                                                            if(cadastrados.ja_cadastrado_suite4 == 0){//ee começo
                                                            padrao_quarto_reservas_luxo = 0;
                                                            cadastrados.ja_cadastrado_suite4 = 1;

                                                            num_diarias_qreserva_suite = 0;
                                                            num_diarias_qreserva_suite = padrao_num_diarias_luxo;
                                                            padrao_num_diarias_luxo = 0;
                                                            printf("\nQuarto atualizado com sucesso!\nSeu novo quarto é o número 11 Suite, Quarto reserva.\n");
                                                            printf("\nA diferença será acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                            getch();
                                                            continuar = 1;
                                                            }//ee fim
                                                                else{
                                                                    printf("Quarto reserva não disponível!");
                                                                };
                                                    }//ec fim
                                                        else if(resp_tipoq_mreservas == 2){//ef começo
                                                            if(cadastrados.ja_cadastrado_standard4 == 0){//eg começo
                                                                padrao_quarto_reservas_luxo = 0;
                                                                cadastrados.ja_cadastrado_standard4 = 1;

                                                                num_diarias_qreservas_standard = 0;
                                                                num_diarias_qreservas_standard = padrao_num_diarias_luxo;
                                                                padrao_num_diarias_luxo = 0;
                                                                printf("\nQuarto atualizado com sucesso!\nSeu novo quarto é o número 12 Standard, Quarto reserva.\n");
                                                                printf("\nA diferença será acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                                getch();
                                                                continuar = 1;
                                                            }//eg fim
                                                            else{
                                                                    printf("Quarto reserva não disponível!");};
                                                        }//ef fim
                                                        else {
                                                            printf("Opção inválida!\n");
                                                            continuar = 1;};
                                        }//md fim
                                         else {
                                                printf("Tipo de quarto não alterado!\n");};
                                    break;
                                    case 2:
                                        printf("\nNão se esqueça de verificar as políticas de cancelamento\n");
                                        padrao_quarto_reservas_luxo = 0;
                                        padrao_num_diarias_luxo = 0;
                                        printf("\nCancelamento efetuado com sucesso!\n\n");
                                        printf("Analisaremos as condições de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                        printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                        getch();
                                        continuar = 1;
                                    break;
                                    default:
                                        printf("Opção inválida!");
                                        printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                        getch();
                                        continuar = 1;


                                    };//mb fim
                                };//else fim

                            if(resp_minhas_reservas_num == 1){
                                cadastrados.ja_cadastrado_luxo1 = padrao_quarto_reservas_luxo;
                                num_diarias_luxo1 = padrao_num_diarias_luxo;
                            };
                            if (resp_minhas_reservas_num == 2){
                                cadastrados.ja_cadastrado_luxo2 = padrao_quarto_reservas_luxo;
                                num_diarias_luxo2 = padrao_num_diarias_luxo;
                            };
                            if(resp_minhas_reservas_num == 3){
                                cadastrados.ja_cadastrado_luxo3 = padrao_quarto_reservas_luxo;
                                num_diarias_luxo3 = padrao_num_diarias_luxo;
                            };
                            if(resp_minhas_reservas_num == 10){
                                cadastrados.ja_cadastrado_luxo4 = padrao_quarto_reservas_luxo;
                                num_diarias_luxo4 = padrao_num_diarias_luxo;};

                            };//fim else caso numero errado luxo

//////////////////////////FIM MINHAS RESERVAS LUXO ///////////////////////////////////////////

                break;
                case 8:
                    resp_minhas_reservas_num = 0;
                    printf("Seu quarto reservado foi o Quarto Suite.\n\n");
                    printf("Informe o número do quarto reservado (4 ao 6):  ");
                    scanf("%d", &resp_minhas_reservas_num);
                    fflush(stdin);

                    if(resp_minhas_reservas_num < 4 && resp_minhas_reservas_num > 6 && resp_minhas_reservas_num != 11){
                        printf("\nQuarto inválido!\n");
                        continuar = 1;
                    } else {//oa começo

                    padrao_quarto_reservas_suite = 0;
                    padrao_num_diarias_suite = 0;

                    if(resp_minhas_reservas_num == 4){//começo p
                        padrao_quarto_reservas_suite = cadastrados.ja_cadastrado_suite1;
                        padrao_num_diarias_suite = num_diarias_suite1;
                    };//fim p
                    if (resp_minhas_reservas_num == 5){
                        padrao_quarto_reservas_suite = cadastrados.ja_cadastrado_suite2;
                        padrao_num_diarias_suite = num_diarias_suite2;
                    };
                    if(resp_minhas_reservas_num == 6){
                        padrao_quarto_reservas_suite = cadastrados.ja_cadastrado_suite3;
                        padrao_num_diarias_suite = num_diarias_suite3;
                    };
                    if(resp_minhas_reservas_num == 11){
                        padrao_quarto_reservas_suite = cadastrados.ja_cadastrado_suite4;
                        padrao_num_diarias_suite = num_diarias_suite4;};

                    if(padrao_quarto_reservas_suite == 0){//ob começo
                            printf("\nNão há reserva nesse quarto!\nPressione qualquer tecla para voltar ao menu incial.\n");
                            getch();
                            continuar = 1;
                    }//ob fim
                        else {//oc começo
                                printf("Escolha uma das opções de serviço:\n[1] Mudar check-in e check-out e/ou Mudar opção de quarto.\n[2] Cancelar reserva.\n");
                                scanf("%d", &resp_alteracao_reserva);
                                fflush(stdin);

                                switch(resp_alteracao_reserva){//od começo switch
                                case 1:
                                    printf("\nDeseja alterar data check-in e check-out?\n[1] Sim.\n[2] Não.\n");
                                    scanf("%d", &resp_reserva_sim_nao);
                                    fflush(stdin);

                                    if(resp_reserva_sim_nao == 1){//oe começo
                                        padrao_num_diarias_suite = 0;

                                        printf("Digite a nova data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a nova data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);

                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("Número total de diárias atualizado é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };

                                        padrao_num_diarias_suite = days;
                                        printf("\nA diferença será acertada no ato do check-in!\n");
                                    }//oe fim
                                        else {//of começo
                                            printf("\nData de check-in e check-out não alterada\n");};//of fim

                                printf("\nDeseja alterar o tipo de quarto?\n[1] Sim.\n[2] Não.\n");
                                scanf("%d", &resp_reser_tipoq);
                                fflush(stdin);

                                if (resp_reser_tipoq == 1){//og começo
                                    printf("\nPara qual tipo de quarto deseja alterar?\n[1] Quarto de Luxo.\n[2] Quarto standard.\n");
                                    scanf("%d", &resp_tipoq_mreservas);

                                    if (resp_tipoq_mreservas == 1){//oh começo
                                            if(cadastrados.ja_cadastrado_luxo4 == 0){//oi começo7
                                                    padrao_quarto_reservas_suite = 0;
                                                    cadastrados.ja_cadastrado_luxo4 = 1;

                                                    num_diarias_qreserva_luxo = 0;

                                                    num_diarias_qreserva_luxo = padrao_num_diarias_suite;
                                                    padrao_num_diarias_suite = 0;
                                                    printf("\nQuarto atualizado com sucesso!\nSeu novo quarto é o número 10 Luxo, Quarto reserva.\n");
                                                    printf("\nA diferença será acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                    getch();
                                                    continuar = 1;
                                            }//oi fim
                                                else {
                                                    printf("Quarto reserva não disponível!");
                                                };
                                    }//oh fim
                                    else if(resp_tipoq_mreservas == 2){//oj começo
                                            if(cadastrados.ja_cadastrado_standard4 == 0){//ok começo
                                                    padrao_quarto_reservas_suite = 0;
                                                    cadastrados.ja_cadastrado_standard4 = 1;

                                                    num_diarias_qreservas_standard = 0;

                                                    padrao_num_diarias_suite = num_diarias_qreservas_standard;
                                                    padrao_num_diarias_suite = 0;
                                                    printf("\nQuarto atualizado com sucesso!\nSeu novo quarto é o número 12 Standard, Quarto reserva.\n");
                                                    printf("\nA diferença será acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                    getch();
                                                    continuar = 1;
                                                }//ok fim
                                                else{
                                                    printf("Quarto reserva não disponível!");};
                                        }//oj fim
                                    else {
                                        printf("Opção inválida!\n");
                                        continuar = 1;};
                                    }//og fim
                                    else {
                                        printf("Tipo de quarto não alterado!\n");};

                                break;
                                case 2:
                                    printf("\nNão se esqueça de verificar as políticas de cancelamento\n");
                                    padrao_quarto_reservas_suite= 0;
                                    padrao_num_diarias_suite = 0;
                                    printf("\nCancelamento efetuado com sucesso!\n\n");
                                    printf("Analisaremos as condições de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                    printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                    getch();
                                    continuar = 1;

                                break;
                                default:
                                    printf("Opção inválida!");
                                    printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                    getch();
                                    continuar = 1;
                                };//od fim switch
                        };//oc fim

                    if(resp_minhas_reservas_num == 4){
                        cadastrados.ja_cadastrado_suite1 = padrao_quarto_reservas_suite;
                        num_diarias_suite1 = padrao_num_diarias_suite;
                    };
                    if (resp_minhas_reservas_num == 5){
                        cadastrados.ja_cadastrado_suite2= padrao_quarto_reservas_suite;
                        num_diarias_suite2 = padrao_num_diarias_suite;
                    };
                    if(resp_minhas_reservas_num == 6){
                        cadastrados.ja_cadastrado_suite3 = padrao_quarto_reservas_suite;
                        num_diarias_suite3 = padrao_num_diarias_suite;
                    };
                    if(resp_minhas_reservas_num == 11){
                        cadastrados.ja_cadastrado_suite4 = padrao_quarto_reservas_suite;
                        num_diarias_suite4 = padrao_num_diarias_suite;};
                    };//oa fim


//////////////////////////FIM MINHAS RESERVAS SUITE ///////////////////////////////////////
                break;
                case 9:
                    resp_minhas_reservas_num = 0;
                    printf("Seu quarto reservado foi o Quarto Standard.\n\n");
                    printf("Informe o número do quarto reservado (7 ao 9):  ");
                    scanf("%d", &resp_minhas_reservas_num);
                    fflush(stdin);

                    if(resp_minhas_reservas_num < 7 && resp_minhas_reservas_num > 9 && resp_minhas_reservas_num != 12){//pa começo
                            printf("\nQuarto inválido!\n");
                        continuar = 1;
                    }//pa fim
                    else {//pb começo

                    padrao_quarto_reservas_standard = 0;
                    padrao_num_diarias_standard = 0;

                    if(resp_minhas_reservas_num == 7){//começo p
                        padrao_quarto_reservas_standard = cadastrados.ja_cadastrado_standard1;
                        padrao_num_diarias_standard = num_diarias_standard1;
                    };//fim p
                    if (resp_minhas_reservas_num == 8){
                        padrao_quarto_reservas_standard = cadastrados.ja_cadastrado_standard2;
                        padrao_num_diarias_standard = num_diarias_standard2;
                    };
                    if(resp_minhas_reservas_num == 9){
                        padrao_quarto_reservas_standard = cadastrados.ja_cadastrado_standard3;
                        padrao_num_diarias_standard = num_diarias_standard3;
                    };
                    if(resp_minhas_reservas_num == 12){
                        padrao_quarto_reservas_standard = cadastrados.ja_cadastrado_standard4;
                        padrao_num_diarias_standard = num_diarias_standard4;};

                    if(padrao_quarto_reservas_standard == 0){//pc começo
                            printf("\nNão há reserva nesse quarto!\nPressione qualquer tecla para voltar ao menu incial.\n");
                            getch();
                            continuar = 1;
                    }//pc fim
                        else{//pd começo
                            printf("Escolha uma das opções de serviço:\n[1] Mudar check-in e check-out e/ou Mudar opção de quarto.\n[2] Cancelar reserva.\n");
                            scanf("%d", &resp_alteracao_reserva);
                            fflush(stdin);

                            switch(resp_alteracao_reserva){//pe começo
                            case 1:
                                printf("\nDeseja alterar data check-in e check-out?\n[1] Sim.\n[2] Não.\n");
                                scanf("%d", &resp_reserva_sim_nao);
                                fflush(stdin);

                                if(resp_reserva_sim_nao == 1){//pf começo
                                        padrao_num_diarias_standard = 0;

                                        printf("Digite a nova data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a nova data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);

                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("Número total de diárias atualizado é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };

                                        padrao_num_diarias_standard = days;

                                        printf("\nA diferença será acertada no ato do check-in!\n");
                                }//pf fim
                                else {
                                        printf("\nData de check-in e check-out não alterada\n");};

                                printf("\nDeseja alterar o tipo de quarto?\n[1] Sim.\n[2] Não.\n");
                                scanf("%d", &resp_reser_tipoq);
                                fflush(stdin);

                                if (resp_reser_tipoq == 1){//pg começo
                                    printf("\nPara qual tipo de quarto deseja alterar?\n[1] Quarto de Luxo.\n[2] Quarto Suite.\n");
                                    scanf("%d", &resp_tipoq_mreservas);

                                    if (resp_tipoq_mreservas == 1){
                                        if(cadastrados.ja_cadastrado_luxo4 == 0){//oi começo7
                                                padrao_quarto_reservas_standard = 0;
                                                cadastrados.ja_cadastrado_luxo4 = 1;

                                                num_diarias_qreserva_luxo = 0;

                                                num_diarias_qreserva_luxo = padrao_num_diarias_standard;
                                                padrao_num_diarias_standard = 0;
                                                printf("\nQuarto atualizado com sucesso!\nSeu novo quarto é o número 10 Luxo, Quarto reserva.\n");
                                                printf("\nA diferença será acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                getch();
                                                continuar = 1;
                                        }//oi fim
                                            else {
                                                printf("Quarto reserva não disponível!");};
                                    }
                                    else if(resp_tipoq_mreservas == 2){//ph começo
                                            if(cadastrados.ja_cadastrado_suite4 == 0){//pi começo
                                                    padrao_quarto_reservas_standard = 0;
                                                    cadastrados.ja_cadastrado_suite4 = 1;

                                                    num_diarias_qreserva_suite = 0;

                                                    num_diarias_qreserva_suite = padrao_num_diarias_standard;

                                                    padrao_num_diarias_standard = 0;
                                                    printf("\nQuarto atualizado com sucesso!\nSeu novo quarto é o número 12 Standard, Quarto reserva.\n");
                                                    printf("\nA diferença será acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                    getch();
                                                    continuar = 1;
                                                }//pi fim
                                                else{
                                                    printf("Quarto reserva não disponível!");};
                                }//ph fim
                                    else {
                                        printf("Opção inválida!\n");
                                        continuar = 1;};
                                }//pg fim
                                else {
                                    printf("Tipo de quarto não alterado!\n");};
                            break;
                            case 2:
                                printf("\nNão se esqueça de verificar as políticas de cancelamento\n");
                                padrao_quarto_reservas_standard = 0;
                                padrao_num_diarias_standard = 0;
                                printf("\nCancelamento efetuado com sucesso!\n\n");
                                printf("Analisaremos as condições de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                getch();
                                continuar = 1;

                            break;
                            default:
                                printf("Opção inválida!");
                                printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                getch();
                                continuar = 1;
                            };//pe fim

                        };//pd fim

                        if(resp_minhas_reservas_num == 7){
                        cadastrados.ja_cadastrado_standard1 = padrao_quarto_reservas_standard;
                        num_diarias_standard1 = padrao_num_diarias_standard;
                        };
                        if (resp_minhas_reservas_num == 8){
                            cadastrados.ja_cadastrado_standard2= padrao_quarto_reservas_standard;
                            num_diarias_standard2 = padrao_num_diarias_standard;
                        };
                        if(resp_minhas_reservas_num == 9){
                            cadastrados.ja_cadastrado_standard3 = padrao_quarto_reservas_standard;
                            num_diarias_standard3 = padrao_num_diarias_standard;
                        };
                        if(resp_minhas_reservas_num == 12){
                            cadastrados.ja_cadastrado_standard4 = padrao_quarto_reservas_standard;
                            num_diarias_standard4 = padrao_num_diarias_standard;};

                    };//pb fim
////////////////////////FIM MINHAS RESERVAS QUARTO STANDARD //////////////////////////////
                break;
                default:
                    printf("Opção inválida!");
                    continuar = 1;

                };//d fim
///////////////////////////////////////////////// FIM MINHAS RESERVAS /////////////////////////////////////////////
            break;

            case 2:
                //opção das novas reservas

                printf("Nova Reserva por:\n");
                printf("[1] Administrador\n");
                printf("[2] Usuário Padrão\n\n");
                scanf("%d", &resp_usuario);
                fflush(stdin);

                switch (resp_usuario){//cb começo
                case 1:
                    printf("Por favor informe o login e a senha de administrador\n");
                    printf("Login: ");
                    gets(nome_admin_reserva);
                    printf("\nSenha: ");
                    scanf("%d", &resp_senha_reserva);
                    fflush(stdin);

                    if (resp_senha_reserva == 1234){
                        printf("Reserva em nome do administrador: %s\n\n", nome_admin_reserva);
                    }
                        else {
                            printf("Senha Inválida!\n");
                            printf("\nNova Reserva atualizada para: *Usuário Padrão*");
                            strcpy(nome_admin_reserva, "Usuário Padrão");
                        };
                break;
                case 2:
                    printf("\nReserva em nome de: Usuário Padrão");
                    strcpy(nome_admin_reserva, "Usuário Padrão");

                break;
                default:
                    printf("Opção inválida");
                    continuar = 1;

                };//cb fim

                printf("\n\nNova Reserva por: %s", nome_admin_reserva);

                printf("\nPor gentileza, escolha o seu quarto\n");


                printf("Digite uma das opções de quarto: \n [7] Quarto de Luxo \n [8] Quarto Suíte \n [9] Quarto Standart \n");
                scanf("%d", &escolha_quarto.tipo_quarto);
                fflush(stdin);

                switch (escolha_quarto.tipo_quarto){//i começo
                     //opção 1 cadastro do quarto de luxo
                      case 7 :

                        printf("\nVocê escolheu o quarto de luxo. O seu quarto inclui: café da manhã, almoço, jantar, cama casal, banheiro privativo, amplo espaço e vista privilegiada.\n");
                        printf ("O valor da diária é: R$ 1000,00 + taxas.\n");
                        printf("\nSua escolha está certa? \nDigite [1] para prosseguir para o cadastro!\nDigite [2] para voltar ao menu de opções!\n");
                        gets(escolha_quarto.resposta_quarto);

                        if (strcmp(escolha_quarto.resposta_quarto, "1") == 0) {//j começo
                            printf("Escolha o número do quarto desejado (1 a 3): ");
                            scanf("%d", &resp_numero_quarto);
                            fflush(stdin);

                             if (resp_numero_quarto == 1){//k começo
                                    if (cadastrados.ja_cadastrado_luxo1 == 0){//l começo

                                        printf("Digite a data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                        printf("Número total de diárias é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };//ok

                                        num_diarias_luxo1 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_luxo1 = 1;

                                        printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                        hosp_luxo.total = days * hosp_luxo_valor_diaria + hosp_luxo_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_luxo.total);

                                        printf("Digite a forma a opção da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cartão de Crédito\n\n");

                                        scanf("%d", &hosp_luxo.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_luxo.resposta_pagamento){//m começo
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2 :
                                            printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                            break;
                                            case 3 :
                                            do {
                                                printf("Digite o número do seu cartão (16 dígitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("Número do cartão válido: %s\n", numero_cartao);

                                                printf("\nInforme a data de validade: ");
                                                gets(data_validade);

                                                printf("\nInforme o código de segurança do cartão: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                    switch (hosp_luxo.divisao_cartao){//n começo
                                                        case 1 :
                                                            printf("\nParcelamento: À vista, R$ %.2f\n", hosp_luxo.total);

                                                        break;

                                                        case 2 :
                                                            hosp_luxo.total_parcelamento = hosp_luxo.total / 2;

                                                            printf("Parcelamento: 2x, de R$%.2f", hosp_luxo.total_parcelamento);

                                                        break;

                                                        case 3 :
                                                            hosp_luxo.total_parcelamento = hosp_luxo.total / 3;

                                                             printf("Parcelamento: 3x, de R$%.2f", hosp_luxo.total_parcelamento);

                                                        break;

                                                        default :
                                                            printf("Opção Inválida!");

                                                    };//n fim
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                                break;
                                                default: {
                                                    printf("Opção Inválida!");
                                                    continuar = 1;
                                                    };

                                        };//m fim

                                    }//l fim
                                    else {
                                            printf("Quarto não disponível.\n");};

                             };//k fim quarto 1 luxo

                             if (resp_numero_quarto == 2){//o começo
                                if (cadastrados.ja_cadastrado_luxo2 == 0) {//p começo
                                        printf("Digite a data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("Número total de diárias é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };

                                        num_diarias_luxo2 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_luxo2 = 1;

                                        printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                        hosp_luxo.total = days * hosp_luxo_valor_diaria + hosp_luxo_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_luxo.total);

                                        printf("Digite a forma a opção da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cartão de Crédito\n\n");

                                        scanf("%d", &hosp_luxo.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_luxo.resposta_pagamento){//q começo
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 3:
                                                do {
                                                printf("Digite o número do seu cartão (16 dígitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("Número do cartão válido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o código de segurança do cartão: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_luxo.divisao_cartao){//r começo
                                                    case 1 :
                                                        printf("\nParcelamento: À vista, R$ %.2f\n", hosp_luxo.total);

                                                    break;
                                                    case 2 :
                                                        hosp_luxo.total_parcelamento = hosp_luxo.total / 2;

                                                        printf("Parcelamento: 2x, de R$%.2f", hosp_luxo.total_parcelamento);

                                                    break;
                                                    case 3 :
                                                        hosp_luxo.total_parcelamento = hosp_luxo.total / 3;

                                                         printf("Parcelamento: 3x, de R$%.2f", hosp_luxo.total_parcelamento);

                                                    break;
                                                    default :
                                                        printf("Opção Inválida!");

                                                };//r fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                                    printf("Opção Inválida!");
                                                    continuar = 1;
                                                    };
                                        };//q fim

                                }//p fim
                                else {
                                    printf("Quarto não disponível.\n");};

                             };//o fim quarto 2 luxo

                            if (resp_numero_quarto == 3){//s começo
                                   if (cadastrados.ja_cadastrado_luxo3 == 0) {//t começo
                                        printf("Digite a data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("Número total de diárias é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };

                                        num_diarias_luxo3 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_luxo3 = 1;

                                        printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                        hosp_luxo.total = days * hosp_luxo_valor_diaria + hosp_luxo_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_luxo.total);

                                        printf("Digite a forma a opção da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cartão de Crédito\n\n");

                                        scanf("%d", &hosp_luxo.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_luxo.resposta_pagamento){//u começo
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar =1;

                                            break;
                                            case 3:
                                                do {
                                                printf("Digite o número do seu cartão (16 dígitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("Número do cartão válido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o código de segurança do cartão: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_luxo.divisao_cartao){//v começo
                                                    case 1 :
                                                        printf("\nParcelamento: À vista, R$ %.2f\n", hosp_luxo.total);

                                                    break;
                                                    case 2 :
                                                        hosp_luxo.total_parcelamento = hosp_luxo.total / 2;

                                                        printf("Parcelamento: 2x, de R$%.2f", hosp_luxo.total_parcelamento);

                                                    break;
                                                    case 3 :
                                                        hosp_luxo.total_parcelamento = hosp_luxo.total / 3;

                                                         printf("Parcelamento: 3x, de R$%.2f", hosp_luxo.total_parcelamento);

                                                    break;
                                                    default :
                                                        printf("Opção Inválida!");

                                                };//v fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                                 printf("Opção Inválida!");
                                                    continuar = 1;};
                                        };//u fim
                                   }//t fim
                                   else {
                                        printf("Quarto não disponível.\n");
                                    };

                            }; //s fim

                        }//j fim prosseguir cadastro
                            else if (strcmp(escolha_quarto.resposta_quarto, "2") == 0) {
                                            // Volta ao menu
                                            continuar=1;
                                        }
                                        else {
                                            printf("\nEscolha novamente!\n");
                                        };

            break;
            case 8:

                printf("\nVocê escolheu o quarto suite. O seu quarto inclui: café da manhã, cama casal, banheiro privativo.\n");
                printf ("\nO valor da diária é: R$ 500,00 + taxas.\n");
                printf("\nSua escolha está certa? \nDigite [1] para prosseguir para o cadastro!\nDigite [2] para voltar ao menu de opções!\n");
                gets(escolha_quarto.resposta_quarto);

                if (strcmp(escolha_quarto.resposta_quarto, "1") == 0) {//w começo
                        printf("Escolha o número do quarto desejado (4 ao 6): ");
                        scanf("%d", &resp_numero_quarto);
                        fflush(stdin);

                        if (resp_numero_quarto == 4) {//x começo
                                if (cadastrados.ja_cadastrado_suite1 == 0) {//y começo
                                        printf("Digite a data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("Número total de diárias é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };

                                        num_diarias_suite1 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_suite1 = 1;

                                        printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                        hosp_suite.total = days * hosp_suite_valor_diaria + hosp_suite_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_suite.total);

                                        printf("Digite a forma a opção da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cartão de Crédito\n\n");

                                        scanf("%d", &hosp_suite.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_suite.resposta_pagamento) {//z começo
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 3:
                                               do {
                                                printf("Digite o número do seu cartão (16 dígitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("Número do cartão válido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o código de segurança do cartão: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_suite.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_suite.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_suite.divisao_cartao){//aa começo
                                                    case 1 :
                                                        printf("\nParcelamento: À vista, R$ %.2f\n", hosp_suite.total);
                                                    break;
                                                    case 2 :
                                                        hosp_suite.total_parcelamento = hosp_suite.total / 2;

                                                        printf("Parcelamento: 2x, de R$%.2f", hosp_suite.total_parcelamento);

                                                    break;
                                                    case 3 :
                                                        hosp_suite.total_parcelamento = hosp_suite.total / 3;

                                                         printf("Parcelamento: 3x, de R$%.2f", hosp_suite.total_parcelamento);

                                                    break;
                                                    default :
                                                        printf("Opção Inválida!");

                                                };//aa fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;
                                        break;
                                        default: {
                                                printf("Opção Inválida!");
                                                continuar = 1;};
                                        };//z fim

                                }//y fim
                                else {
                                    printf("Quarto não disponível.\n");
                                };

                        };//x fim

                        if (resp_numero_quarto == 5) {//ab começo
                                if (cadastrados.ja_cadastrado_suite2 == 0) {//ac começo
                                        printf("Digite a data de check-in (dia mês ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia mês ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("Número total de diárias é: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior à data de check-in.\n");
                                        };

                                        num_diarias_suite2 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_suite2 = 1;

                                        printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                        hosp_suite.total = days * hosp_suite_valor_diaria + hosp_suite_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_suite.total);

                                        printf("Digite a forma a opção da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cartão de Crédito\n\n");

                                        scanf("%d", &hosp_suite.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_suite.resposta_pagamento) {//ad começo
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                                printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 3:
                                                do {
                                                printf("Digite o número do seu cartão (16 dígitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("Número do cartão válido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o código de segurança do cartão: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_suite.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_suite.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_suite.divisao_cartao){//ae começo
                                                    case 1 :
                                                        printf("\nParcelamento: À vista, R$ %.2f\n", hosp_suite.total);

                                                    break;
                                                    case 2 :
                                                        hosp_suite.total_parcelamento = hosp_suite.total / 2;

                                                        printf("Parcelamento: 2x, de R$%.2f", hosp_suite.total_parcelamento);

                                                    break;
                                                    case 3 :
                                                        hosp_suite.total_parcelamento = hosp_suite.total / 3;

                                                         printf("Parcelamento: 3x, de R$%.2f", hosp_suite.total_parcelamento);

                                                    break;
                                                    default :
                                                        printf("Opção Inválida!");

                                                };//ae fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                            printf("Opção Inválida!");
                                            continuar = 1;
                                            };

                                        };//ad fim


                                }//ac fim
                                    else {
                                        printf("Quarto não disponível.\n");
                                    };

                        };//ab fim

                        if (resp_numero_quarto == 6) {//af começo
                            if (cadastrados.ja_cadastrado_suite3 == 0) {//ag começo

                                    printf("Digite a data de check-in (dia mês ano): ");
                                    scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                    fflush(stdin);

                                    printf("Digite a data de check-out (dia mês ano): ");
                                    scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                    fflush(stdin);


                                    int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                    if (days >= 0) {
                                        printf("Número total de diárias é: %d\n", days);
                                    } else {
                                        printf("A data de check-out deve ser posterior à data de check-in.\n");
                                    };

                                    num_diarias_suite3 = days;

                                    do {
                                    cadastro cads = cadastro_hospede();

                                    printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                    scanf("%d", &resp_confirma_dados);
                                    fflush(stdin);

                                    }while (resp_confirma_dados == 2);

                                    cadastrados.ja_cadastrado_suite3 = 1;

                                    printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                    printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                    hosp_suite.total = days * hosp_suite_valor_diaria + hosp_suite_taxas;

                                    printf("O valor total ficou em R$ %.2f\n\n", hosp_suite.total);

                                    printf("Digite a forma a opção da forma de pagamento: \n\n");
                                    printf("[1] Pix\n");
                                    printf("[2] Dinheiro\n");
                                    printf("[3] Cartão de Crédito\n\n");

                                    scanf("%d", &hosp_suite.resposta_pagamento);
                                    fflush(stdin);

                                    switch(hosp_suite.resposta_pagamento) {//ah começo
                                        case 1:
                                            printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                            printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                            printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        case 2:
                                            printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        case 3:
                                            do {
                                            printf("Digite o número do seu cartão (16 dígitos): ");
                                            fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                            numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                            if (strlen(numero_cartao) != 16) {
                                                printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                            }
                                            } while (strlen(numero_cartao) != 16);

                                            int c;
                                            while ((c = getchar()) != '\n' && c != EOF);

                                            printf("Número do cartão válido: %s\n", numero_cartao);

                                            printf("Informe a data de validade: ");
                                            gets(data_validade);

                                            printf("Informe o código de segurança do cartão: ");
                                            gets(codigo_seguranca_cartao);

                                            printf("\nO valor total foi R$%.2f\n\n", hosp_suite.total);
                                            printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                            printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                            scanf("%d", &hosp_suite.divisao_cartao);
                                            fflush(stdin);

                                            switch (hosp_suite.divisao_cartao){//ai começo
                                                case 1 :
                                                    printf("\nParcelamento: À vista, R$ %.2f\n", hosp_suite.total);

                                                break;
                                                case 2 :
                                                    hosp_suite.total_parcelamento = hosp_suite.total / 2;

                                                    printf("Parcelamento: 2x, de R$%.2f", hosp_suite.total_parcelamento);

                                                break;
                                                case 3 :
                                                    hosp_suite.total_parcelamento = hosp_suite.total / 3;

                                                     printf("Parcelamento: 3x, de R$%.2f", hosp_suite.total_parcelamento);

                                                break;
                                                default :
                                                    printf("Opção Inválida!");

                                            };//ai fim ok

                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                            printf("Opção Inválida!");
                                            continuar = 1;
                                        };

                                    };//ah fim

                            }//ag fim

                                else {
                                    printf("Quarto não disponível.\n");
                                };

                        };//af fim
                }//w fim

                 else if (strcmp(escolha_quarto.resposta_quarto, "2") == 0) {
                                            // Volta ao menu
                                            continuar=1;
                                        }
                                        else {
                                            printf("\nEscolha novamente!\n");
                                        };
            break;
            case 9:

                printf("\nVocê escolheu o quarto standard. O seu quarto inclui: café da manhã, 1 cama (tipo: beliche) o quarto e o banheiro são compartilhado.\n");
                printf ( "\nO valor da diária é: R$ 150,00 + taxas.\n");
                printf("\nSua escolha está certa? \nDigite [1] para prosseguir para o cadastro!\nDigite [2] para voltar ao menu de opções!\n");
                gets(escolha_quarto.resposta_quarto);

                if (strcmp(escolha_quarto.resposta_quarto, "1") == 0) {//aj começo

                    printf("Escolha o número do quarto desejado (7 ao 9): ");
                    scanf("%d", &resp_numero_quarto);
                    fflush(stdin);

                    if (resp_numero_quarto == 7) {//ak começo
                            if (cadastrados.ja_cadastrado_standard1 == 0) {//al começo
                                printf("Digite a data de check-in (dia mês ano): ");
                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                fflush(stdin);

                                printf("Digite a data de check-out (dia mês ano): ");
                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                fflush(stdin);


                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                if (days >= 0) {
                                    printf("Número total de diárias é: %d\n", days);
                                } else {
                                    printf("A data de check-out deve ser posterior à data de check-in.\n");
                                };

                                num_diarias_standard1 = days;

                                do {
                                cadastro cads = cadastro_hospede();

                                printf("\nApós a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                scanf("%d", &resp_confirma_dados);
                                fflush(stdin);

                                }while (resp_confirma_dados == 2);

                                cadastrados.ja_cadastrado_standard1 = 1;

                                printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                hosp_standart.total = days * hosp_standart_valor_diaria + hosp_standart_taxas;

                                printf("O valor total ficou em R$ %.2f\n\n", hosp_standart.total);

                                printf("Digite a forma a opção da forma de pagamento: \n\n");
                                printf("[1] Pix\n");
                                printf("[2] Dinheiro\n");
                                printf("[3] Cartão de Crédito\n\n");

                                scanf("%d", &hosp_standart.resposta_pagamento);
                                fflush(stdin);

                                switch(hosp_standart.resposta_pagamento) {//am começo
                                    case 1 :
                                        printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                        printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                        printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 2:
                                        printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 3:
                                        do {
                                        printf("Digite o número do seu cartão (16 dígitos): ");
                                        fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                        numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                        if (strlen(numero_cartao) != 16) {
                                            printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                        }
                                        } while (strlen(numero_cartao) != 16);

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);

                                        printf("Número do cartão válido: %s\n", numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o código de segurança do cartão: ");
                                        gets(codigo_seguranca_cartao);

                                        printf("\nO valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                        switch (hosp_standart.divisao_cartao){//an começo
                                            case 1 :
                                                printf("\nParcelamento: À vista, R$ %.2f\n", hosp_standart.total);

                                            break;
                                            case 2 :
                                                hosp_standart.total_parcelamento = hosp_standart.total / 2;

                                                printf("Parcelamento: 2x, de R$%.2f", hosp_standart.total_parcelamento);

                                            break;
                                            case 3 :
                                                hosp_standart.total_parcelamento = hosp_standart.total / 3;

                                                 printf("Parcelamento: 3x, de R$%.2f", hosp_standart.total_parcelamento);

                                            break;
                                            default :
                                                printf("Opção Inválida!");
                                        };//an fim
                                    printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                    printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                    printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                    getch();
                                    continuar = 1;

                                    break;
                                    default: {
                                        printf("Opção Inválida!");
                                        continuar = 1;};

                                };//am fim

                            }//al fim
                             else {
                                    printf("Quarto não disponível.\n");
                                };
                    };//ak fim
                    if (resp_numero_quarto == 8) {//ao começo
                        if (cadastrados.ja_cadastrado_standard2 == 0) {//ap começo
                                printf("Digite a data de check-in (dia mês ano): ");
                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                fflush(stdin);

                                printf("Digite a data de check-out (dia mês ano): ");
                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                fflush(stdin);


                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                if (days >= 0) {
                                    printf("Número total de diárias é: %d\n", days);
                                } else {
                                    printf("A data de check-out deve ser posterior à data de check-in.\n");
                                };

                                num_diarias_standard2 = days;

                                do {
                                cadastro cads = cadastro_hospede();

                                printf("\nApós a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                scanf("%d", &resp_confirma_dados);
                                fflush(stdin);

                                }while (resp_confirma_dados == 2);

                                cadastrados.ja_cadastrado_standard2 = 1;

                                printf(" *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                hosp_standart.total = days * hosp_standart_valor_diaria + hosp_standart_taxas;

                                printf("O valor total ficou em R$ %.2f\n\n", hosp_standart.total);

                                printf("Digite a forma a opção da forma de pagamento: \n\n");
                                printf("[1] Pix\n");
                                printf("[2] Dinheiro\n");
                                printf("[3] Cartão de Crédito\n\n");

                                scanf("%d", &hosp_standart.resposta_pagamento);
                                fflush(stdin);

                                switch(hosp_standart.resposta_pagamento) {//aq começo
                                    case 1 :
                                        printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                        printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                        printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 2:
                                        printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 3:
                                        do {
                                        printf("Digite o número do seu cartão (16 dígitos): ");
                                        fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                        numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                        if (strlen(numero_cartao) != 16) {
                                            printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                        }
                                        } while (strlen(numero_cartao) != 16);

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);

                                        printf("Número do cartão válido: %s\n", numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o código de segurança do cartão: ");
                                        gets(codigo_seguranca_cartao);

                                        printf("\nO valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                         switch (hosp_standart.divisao_cartao){//ar começo
                                             case 1 :
                                                printf("\nParcelamento: À vista, R$ %.2f\n", hosp_standart.total);
                                            break;
                                            case 2 :
                                                hosp_standart.total_parcelamento = hosp_standart.total / 2;

                                                printf("Parcelamento: 2x, de R$%.2f", hosp_standart.total_parcelamento);

                                            break;
                                            case 3 :
                                                hosp_standart.total_parcelamento = hosp_standart.total / 3;

                                                 printf("Parcelamento: 3x, de R$%.2f", hosp_standart.total_parcelamento);

                                            break;
                                            default :
                                                printf("Opção Inválida!");

                                         };//ar fim ok
                                         printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    default: {
                                        printf("Opção Inválida!");
                                        continuar = 1; };

                                }//aq fim ok


                        }//ap fim
                        else {
                            printf("Quarto não disponível.\n");
                        };

                    };//ao fim

                     if (resp_numero_quarto == 9) {//as começo
                        if (cadastrados.ja_cadastrado_standard3 == 0) {//at começo
                                printf("Digite a data de check-in (dia mês ano): ");
                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                fflush(stdin);

                                printf("Digite a data de check-out (dia mês ano): ");
                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                fflush(stdin);


                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                if (days >= 0) {
                                    printf("Número total de diárias é: %d\n", days);
                                } else {
                                    printf("A data de check-out deve ser posterior à data de check-in.\n");
                                };

                                num_diarias_standard3 = days;

                                do {
                                cadastro cads = cadastro_hospede();

                                printf("Após a revisão de seus dados: \nDigite [1] para prosseguir para a área de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                scanf("%d", &resp_confirma_dados);
                                fflush(stdin);

                                }while (resp_confirma_dados == 2);

                                cadastrados.ja_cadastrado_standard3 = 1;

                                printf("\n *A confirmação da sua reserva será enviada no e-mail informado no cadastro* \n\n");

                                printf("\n========== ÁREA DE PAGAMENTO =========\n\n");

                                hosp_standart.total = days * hosp_standart_valor_diaria + hosp_standart_taxas;

                                printf("O valor total ficou em R$ %.2f\n\n", hosp_standart.total);

                                printf("Digite a forma a opção da forma de pagamento: \n\n");
                                printf("[1] Pix\n");
                                printf("[2] Dinheiro\n");
                                printf("[3] Cartão de Crédito\n\n");

                                scanf("%d", &hosp_standart.resposta_pagamento);
                                fflush(stdin);

                                switch(hosp_standart.resposta_pagamento) {//au começo
                                    case 1 :
                                        printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                        printf("Após o pagamento envie o comprovante para o seguinte número: (016) 3030-3030\n\n");

                                        printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 2:
                                        printf("==== Opção de pagamento registrado ==== \n\nNesta opção o pagamento deverá ser efetuado no ato do check-in\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 3:
                                        do {
                                        printf("Digite o número do seu cartão (16 dígitos): ");
                                        fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                        numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                        if (strlen(numero_cartao) != 16) {
                                            printf("\nO número do cartão deve conter exatamente 16 dígitos.\n");
                                        }
                                        } while (strlen(numero_cartao) != 16);

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);

                                        printf("Número do cartão válido: %s\n", numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o código de segurança do cartão: ");
                                        gets(codigo_seguranca_cartao);

                                        printf("\nO valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] À vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                         switch (hosp_standart.divisao_cartao){//av começo
                                             case 1 :
                                                printf("\nParcelamento: À vista, R$ %.2f\n", hosp_standart.total);

                                            break;
                                            case 2 :
                                                hosp_standart.total_parcelamento = hosp_standart.total / 2;

                                                printf("Parcelamento: 2x, de R$%.2f", hosp_standart.total_parcelamento);

                                            break;
                                            case 3 :
                                                hosp_standart.total_parcelamento = hosp_standart.total / 3;

                                                 printf("Parcelamento: 3x, de R$%.2f", hosp_standart.total_parcelamento);

                                            break;
                                            default :
                                                printf("Opção Inválida!");

                                         };//av fim ok
                                         printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transação está assegurada pela Lei Geral de Proteção de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    default: {
                                            printf("Opção Inválida!");
                                            continuar = 1;
                                        };

                                };//au fim

                        }//at fim
                            else {
                                printf("Quarto não disponível.\n");
                            };

                     };//as fim

                }//aj fim

                    else if (strcmp(escolha_quarto.resposta_quarto, "2") == 0) {
                                // Volta ao menu
                                continuar=1;
                            }
                            else {
                                printf("\nEscolha novamente!\n");
                            };

            break;
            default:{
                printf("opção inválida!");
                continuar = 1;
            };

                };//i fim switch tipo quarto

/////////////////////////////////////////////FIM NOVAS RESERVAS /////////////////////////////////////////////////////////

        break;
        case 3:
            printf("\nPor favor, escolha uma das opções de informações gerais que deseja obter!\n\n");
            printf("[1] Políticas de Cancelamento\n");
            printf("[2] Lei Geral de Proteção de Dados(LGPD)\n");
            scanf("%d", &resp_info);
            fflush(stdin);

                switch (resp_info) {
                    case 1:
                        politicas_cancelamento();
                    break;
                    case 2:
                        lei_lgpd();

                    break;
                    default:
                        {
                        printf("Opção inválida!");
                        continuar = 1;
                        };
                        }//fim switch resp info
/////////////////////////////////////////////////FIM POLITICAS DE CANCELAMENTO ////////////////////////////////////////////////////
        break;
        case 4:
            printf("Informe o Login de Administrador e a senha de Administrador\n\n");
            printf("Login: ");
            gets(nome_administrador_relatorio);
            printf("\nSenha: ");
            scanf("%d", &resp_senha_admin);
            fflush(stdin);

            if( resp_senha_admin == 1234){//ca começo
                printf("\nRelatórios sendo gerados por: %s", nome_administrador_relatorio);

            printf("\n===== Relatórios =====\n\n");
            printf("[1] Faturamento.\n");
            printf("[2] Quartos Reservados.\n");
            scanf("%d", &resp_relatorio);

                switch (resp_relatorio){//aw começo
                    case 1:
                        printf("\n===== Relatório de Faturamento ====\n\n");
                        num_total_diarias_luxo = num_diarias_luxo1 + num_diarias_luxo2 + num_diarias_luxo3;
                        fat_luxo = num_total_diarias_luxo * hosp_luxo_valor_diaria;
                        printf("\nO Faturamento do Quarto de Luxo é: R$%.2f", fat_luxo); //verificar taxas

                        num_total_diarias_suite = num_diarias_suite1 + num_diarias_suite2 + num_diarias_suite3;
                        fat_suite = num_total_diarias_suite * hosp_suite_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Suite é: R$%.2f", fat_suite);

                        num_total_diarias_standard = num_diarias_standard1 + num_diarias_standard2 + num_diarias_standard3;
                        fat_standard = num_total_diarias_standard * hosp_standart_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Standard é: R$%.2f", fat_standard);

                        fat_reserva_luxo = num_diarias_qreserva_luxo * hosp_luxo_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Reserva de Luxo é: R$%.2f", fat_reserva_luxo);

                        fat_reserva_suite = num_diarias_qreserva_suite * hosp_suite_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Reserva Suite é: R$%.2f", fat_reserva_suite);

                        fat_reserva_standard = num_diarias_qreservas_standard * hosp_standart_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Reserva Standard é: R$%.2f", fat_reserva_standard);

                        fat_total = fat_luxo + fat_suite + fat_standard + fat_reserva_luxo + fat_reserva_standard + fat_reserva_suite;
                        printf("\n\nO Faturamento Total é: R$%.2f\n", fat_total);
                        printf("Relatório gerado sem a adição das taxas.\n");

                        printf("\nRelatório Gerado por: %s\n\n", nome_administrador_relatorio);
                        printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
                        getch();
                        continuar = 1;

                    break;
                    case 2:
                        printf("\n==== Relatório de Quartos Reservados ====\n\n");

                        total_quartos_reservados_luxo = 0;
                        total_quartos_reservados_standard =0;
                        total_quartos_reservados_suite = 0;
                        total_quartos_reservados = 0;

                        if (cadastrados.ja_cadastrado_luxo1 == 1){
                            total_quartos_reservados_luxo += 1;};

                        if (cadastrados.ja_cadastrado_luxo2 == 1){
                            total_quartos_reservados_luxo += 1;};

                        if (cadastrados.ja_cadastrado_luxo3 == 1){
                            total_quartos_reservados_luxo += 1;};

                        if(cadastrados.ja_cadastrado_luxo4 == 1){
                            total_quartos_reservados_luxo += 1;};


                        if (cadastrados.ja_cadastrado_standard1 == 1){
                            total_quartos_reservados_standard += 1;};

                        if (cadastrados.ja_cadastrado_standard2 == 1){
                            total_quartos_reservados_standard += 1;};

                        if (cadastrados.ja_cadastrado_standard3 == 1){
                            total_quartos_reservados_standard += 1;};

                        if(cadastrados.ja_cadastrado_standard4 == 1){
                            total_quartos_reservados_standard += 1;};

                        if (cadastrados.ja_cadastrado_suite1 == 1){
                            total_quartos_reservados_suite += 1;};

                        if (cadastrados.ja_cadastrado_suite2 == 1){
                            total_quartos_reservados_suite += 1;};

                        if (cadastrados.ja_cadastrado_suite3 == 1){
                            total_quartos_reservados_suite += 1;};

                        if(cadastrados.ja_cadastrado_suite4 == 1){
                            total_quartos_reservados_suite += 1;};

                        total_quartos_reservados = total_quartos_reservados_luxo + total_quartos_reservados_standard + total_quartos_reservados_suite;

                        printf("Quantidade de Reservas no Quarto de Luxo: %d", total_quartos_reservados_luxo);
                        printf("\nQuantidade de Reservas no Quarto Suite: %d", total_quartos_reservados_suite);
                        printf("\nQuantidade de Reservas no Quarto Standard: %d", total_quartos_reservados_standard);

                        printf("\n\nQuantidade de Reservas totais: %d", total_quartos_reservados);

                        printf("\nRelatório Gerado por: %s\n\n", nome_administrador_relatorio);
                        printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
                        getch();
                        continuar = 1;

                    break;
                    default:
                        printf("Escolha inválida");
                        continuar = 1;
                };//aw fim
            }//ca fim
                else {
                    printf("==Senha Inválida==\n\n");
                    printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
                    getch();
                    continuar = 1;
                }

        break;
        case 5:
            continuar = 0;

        break;
        default:{
            printf("Opção Inválida!");
            continuar = 1;
        };
        };//c fim switch menu

    };//b fim while


}//a fim main

cadastro cadastro_hospede(){
    cadastro cads;

    printf("\nPor gentileza, preencha com seus dados:\n");

    printf("\nNome completo: ");
    gets(cads.nome);

    printf("\nEmail de contato: ");
    gets(cads.email);

    printf("\nGênero: ");
    gets(cads.genero);

    printf("\nDigite seu documento de identificação: ");
    gets(cads.documento);

    printf("\nInforme seu número de contato: ");
    gets(cads.fone);

    printf("\nInforme um telefone para emergência: ");
    gets(cads.fone_emergencia);


            printf("\nHá acompanhante?\nDigite [1] para sim\nDigite [2] para não\n ");
            gets(cads.resposta);


            if (strcmp(cads.resposta, "1") == 0) {
                printf("\nPor favor preencha os dados do acompanhante\n");
                printf("\nNome do acompanhante: ");
                gets(cads.nome_acompanhante);

                printf("\nDigite o documento de identificação do acompanhante: ");
                gets(cads.documento_acompanhante);

                printf("\nInforme o telefone para casos de emergência: ");
                gets(cads.fone_acompanhante);

                printf("Os dados do acompanhante são: \n\n%s \n%s \n%s \n", cads.nome_acompanhante, cads.documento_acompanhante, cads.fone_acompanhante);
                printf("Cadastro do acompanhante finalizado com sucesso!");

                } else {
                    printf("Reserva sem acompanhante");

                };

        printf("\n\nOs seus dados então corretos?");
        printf("\n\nNome: %s \nE-mail: %s \nGênero: %s \nDocumento: %s \nTelefone: %s \nEmegência: %s \n", cads.nome, cads.email, cads.genero, cads.documento, cads.fone, cads.fone_emergencia);


return;
}

