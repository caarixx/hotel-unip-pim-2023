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
    printf("Digite a data de check-in (dia m�s ano): ");
    scanf("%d %d %d", checkin_day, checkin_month, checkin_year);
    fflush(stdin);

    printf("Digite a data de check-out (dia m�s ano): ");
    scanf("%d %d %d", checkout_day, checkout_month, checkout_year);
    fflush(stdin);

    int days = days_between_dates(*checkin_year, *checkin_month, *checkin_day, *checkout_year, *checkout_month, *checkout_day);

    if (days >= 0) {
        printf("N�mero total de di�rias atualizado �: %d\n", days);
    } else {
        printf("A data de check-out deve ser posterior � data de check-in.\n");
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
{//a come�o

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

    while (continuar) {//b come�o

        printf("\n=======Seja bem vindo ao hotel UNIP!=======\n\n");

        printf("Por favor, escolha uma das op��es de servi�o:\n");

        printf("[1] Minhas Reservas\n");// ultimo(incluir op��o de cancelamento) ok
        printf("[2] Nova Reserva\n"); // primeiro ok
        printf("[3] Informa��es Gerais\n"); //ok
        printf("[4] Gerar Relat�rios\n"); //ok
        printf("[5] Sair\n\n");//ok

        scanf("%d", &opcao.resposta_menu);
        fflush(stdin);

        switch (opcao.resposta_menu){//c come�o

            case 1 :
           //op��o de verificar a reserva.
            printf("Selecione o modelo de quarto reservado:\n\n");
            printf("[7] Quarto de Luxo\n");
            printf("[8] Quarto Suite\n");
            printf("[9] Quarto Standard\n");

            scanf("%d", &resp_minhas_reservas);
            fflush(stdin);

                switch(resp_minhas_reservas){//d come�o

                    case 7 :
                            resp_minhas_reservas_num = 0;
                            printf("Seu quarto reservado foi o Quarto de Luxo.\n\n");
                            printf("Informe o n�mero do quarto reservado (1 ao 3):  ");
                            scanf("%d", &resp_minhas_reservas_num);
                            fflush(stdin);

                            if(resp_minhas_reservas_num > 3 && resp_minhas_reservas_num != 10){
                                printf("\nQuarto inv�lido!\n");
                                continuar = 1;
                            } else {//come�o else caso numero errado luxo

                            padrao_quarto_reservas_luxo = 0;
                            padrao_num_diarias_luxo = 0;

                            if(resp_minhas_reservas_num == 1){//come�o p
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

                            if(padrao_quarto_reservas_luxo == 0){//ma come�o
                                    printf("\nN�o h� reserva nesse quarto!\nPressione qualquer tecla para voltar ao menu incial.\n");
                                    getch();
                                    continuar = 1;
                            }//ma fim
                                else {
                                    printf("Escolha uma das op��es de servi�o:\n[1] Mudar check-in e check-out e/ou Mudar op��o de quarto.\n[2] Cancelar reserva.\n");
                                    scanf("%d", &resp_alteracao_reserva);
                                    fflush(stdin);

                                    switch(resp_alteracao_reserva){//mb come�o
                                    case 1:
                                        printf("\nDeseja alterar data check-in e check-out?\n[1] Sim.\n[2] N�o.\n");
                                        scanf("%d", &resp_reserva_sim_nao);
                                        fflush(stdin);

                                        if(resp_reserva_sim_nao == 1){//mc come�o
                                                padrao_num_diarias_luxo = 0;

                                                printf("Digite a nova data de check-in (dia m�s ano): ");
                                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                                fflush(stdin);

                                                printf("Digite a nova data de check-out (dia m�s ano): ");
                                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                                fflush(stdin);


                                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                                if (days >= 0) {
                                                    printf("N�mero total de di�rias atualizado �: %d\n", days);
                                                } else {
                                                    printf("A data de check-out deve ser posterior � data de check-in.\n");
                                                };

                                                padrao_num_diarias_luxo = days;
                                                printf("\nA diferen�a ser� acertada no ato do check-in!\n");
                                        }//mc fim
                                            else {
                                                    printf("\nData de check-in e check-out n�o alterada\n");};


                                        printf("\nDeseja alterar o tipo de quarto?\n[1] Sim.\n[2] N�o.\n");
                                        scanf("%d", &resp_reser_tipoq);
                                        fflush(stdin);

                                        if (resp_reser_tipoq == 1){//md come�o
                                                printf("\nPara o seu conhecimento estar� sendo realocado para um dos nossos quartos reservas, para que n�o haja conflito na disponibilidade dos quartos principais.\n *N�o h� diferen�a entre os servi�os oferecidos dos quartos principais para os reservas*\n");
                                                printf("\nPara qual tipo de quarto deseja alterar?\n[1] Quarto Suite.\n[2] Quarto standard.\n");
                                                scanf("%d", &resp_tipoq_mreservas);

                                                    if (resp_tipoq_mreservas == 1){//ec come�o
                                                            if(cadastrados.ja_cadastrado_suite4 == 0){//ee come�o
                                                            padrao_quarto_reservas_luxo = 0;
                                                            cadastrados.ja_cadastrado_suite4 = 1;

                                                            num_diarias_qreserva_suite = 0;
                                                            num_diarias_qreserva_suite = padrao_num_diarias_luxo;
                                                            padrao_num_diarias_luxo = 0;
                                                            printf("\nQuarto atualizado com sucesso!\nSeu novo quarto � o n�mero 11 Suite, Quarto reserva.\n");
                                                            printf("\nA diferen�a ser� acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                            getch();
                                                            continuar = 1;
                                                            }//ee fim
                                                                else{
                                                                    printf("Quarto reserva n�o dispon�vel!");
                                                                };
                                                    }//ec fim
                                                        else if(resp_tipoq_mreservas == 2){//ef come�o
                                                            if(cadastrados.ja_cadastrado_standard4 == 0){//eg come�o
                                                                padrao_quarto_reservas_luxo = 0;
                                                                cadastrados.ja_cadastrado_standard4 = 1;

                                                                num_diarias_qreservas_standard = 0;
                                                                num_diarias_qreservas_standard = padrao_num_diarias_luxo;
                                                                padrao_num_diarias_luxo = 0;
                                                                printf("\nQuarto atualizado com sucesso!\nSeu novo quarto � o n�mero 12 Standard, Quarto reserva.\n");
                                                                printf("\nA diferen�a ser� acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                                getch();
                                                                continuar = 1;
                                                            }//eg fim
                                                            else{
                                                                    printf("Quarto reserva n�o dispon�vel!");};
                                                        }//ef fim
                                                        else {
                                                            printf("Op��o inv�lida!\n");
                                                            continuar = 1;};
                                        }//md fim
                                         else {
                                                printf("Tipo de quarto n�o alterado!\n");};
                                    break;
                                    case 2:
                                        printf("\nN�o se esque�a de verificar as pol�ticas de cancelamento\n");
                                        padrao_quarto_reservas_luxo = 0;
                                        padrao_num_diarias_luxo = 0;
                                        printf("\nCancelamento efetuado com sucesso!\n\n");
                                        printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                        printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                        getch();
                                        continuar = 1;
                                    break;
                                    default:
                                        printf("Op��o inv�lida!");
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
                    printf("Informe o n�mero do quarto reservado (4 ao 6):  ");
                    scanf("%d", &resp_minhas_reservas_num);
                    fflush(stdin);

                    if(resp_minhas_reservas_num < 4 && resp_minhas_reservas_num > 6 && resp_minhas_reservas_num != 11){
                        printf("\nQuarto inv�lido!\n");
                        continuar = 1;
                    } else {//oa come�o

                    padrao_quarto_reservas_suite = 0;
                    padrao_num_diarias_suite = 0;

                    if(resp_minhas_reservas_num == 4){//come�o p
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

                    if(padrao_quarto_reservas_suite == 0){//ob come�o
                            printf("\nN�o h� reserva nesse quarto!\nPressione qualquer tecla para voltar ao menu incial.\n");
                            getch();
                            continuar = 1;
                    }//ob fim
                        else {//oc come�o
                                printf("Escolha uma das op��es de servi�o:\n[1] Mudar check-in e check-out e/ou Mudar op��o de quarto.\n[2] Cancelar reserva.\n");
                                scanf("%d", &resp_alteracao_reserva);
                                fflush(stdin);

                                switch(resp_alteracao_reserva){//od come�o switch
                                case 1:
                                    printf("\nDeseja alterar data check-in e check-out?\n[1] Sim.\n[2] N�o.\n");
                                    scanf("%d", &resp_reserva_sim_nao);
                                    fflush(stdin);

                                    if(resp_reserva_sim_nao == 1){//oe come�o
                                        padrao_num_diarias_suite = 0;

                                        printf("Digite a nova data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a nova data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);

                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("N�mero total de di�rias atualizado �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };

                                        padrao_num_diarias_suite = days;
                                        printf("\nA diferen�a ser� acertada no ato do check-in!\n");
                                    }//oe fim
                                        else {//of come�o
                                            printf("\nData de check-in e check-out n�o alterada\n");};//of fim

                                printf("\nDeseja alterar o tipo de quarto?\n[1] Sim.\n[2] N�o.\n");
                                scanf("%d", &resp_reser_tipoq);
                                fflush(stdin);

                                if (resp_reser_tipoq == 1){//og come�o
                                    printf("\nPara qual tipo de quarto deseja alterar?\n[1] Quarto de Luxo.\n[2] Quarto standard.\n");
                                    scanf("%d", &resp_tipoq_mreservas);

                                    if (resp_tipoq_mreservas == 1){//oh come�o
                                            if(cadastrados.ja_cadastrado_luxo4 == 0){//oi come�o7
                                                    padrao_quarto_reservas_suite = 0;
                                                    cadastrados.ja_cadastrado_luxo4 = 1;

                                                    num_diarias_qreserva_luxo = 0;

                                                    num_diarias_qreserva_luxo = padrao_num_diarias_suite;
                                                    padrao_num_diarias_suite = 0;
                                                    printf("\nQuarto atualizado com sucesso!\nSeu novo quarto � o n�mero 10 Luxo, Quarto reserva.\n");
                                                    printf("\nA diferen�a ser� acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                    getch();
                                                    continuar = 1;
                                            }//oi fim
                                                else {
                                                    printf("Quarto reserva n�o dispon�vel!");
                                                };
                                    }//oh fim
                                    else if(resp_tipoq_mreservas == 2){//oj come�o
                                            if(cadastrados.ja_cadastrado_standard4 == 0){//ok come�o
                                                    padrao_quarto_reservas_suite = 0;
                                                    cadastrados.ja_cadastrado_standard4 = 1;

                                                    num_diarias_qreservas_standard = 0;

                                                    padrao_num_diarias_suite = num_diarias_qreservas_standard;
                                                    padrao_num_diarias_suite = 0;
                                                    printf("\nQuarto atualizado com sucesso!\nSeu novo quarto � o n�mero 12 Standard, Quarto reserva.\n");
                                                    printf("\nA diferen�a ser� acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                    getch();
                                                    continuar = 1;
                                                }//ok fim
                                                else{
                                                    printf("Quarto reserva n�o dispon�vel!");};
                                        }//oj fim
                                    else {
                                        printf("Op��o inv�lida!\n");
                                        continuar = 1;};
                                    }//og fim
                                    else {
                                        printf("Tipo de quarto n�o alterado!\n");};

                                break;
                                case 2:
                                    printf("\nN�o se esque�a de verificar as pol�ticas de cancelamento\n");
                                    padrao_quarto_reservas_suite= 0;
                                    padrao_num_diarias_suite = 0;
                                    printf("\nCancelamento efetuado com sucesso!\n\n");
                                    printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                    printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                    getch();
                                    continuar = 1;

                                break;
                                default:
                                    printf("Op��o inv�lida!");
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
                    printf("Informe o n�mero do quarto reservado (7 ao 9):  ");
                    scanf("%d", &resp_minhas_reservas_num);
                    fflush(stdin);

                    if(resp_minhas_reservas_num < 7 && resp_minhas_reservas_num > 9 && resp_minhas_reservas_num != 12){//pa come�o
                            printf("\nQuarto inv�lido!\n");
                        continuar = 1;
                    }//pa fim
                    else {//pb come�o

                    padrao_quarto_reservas_standard = 0;
                    padrao_num_diarias_standard = 0;

                    if(resp_minhas_reservas_num == 7){//come�o p
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

                    if(padrao_quarto_reservas_standard == 0){//pc come�o
                            printf("\nN�o h� reserva nesse quarto!\nPressione qualquer tecla para voltar ao menu incial.\n");
                            getch();
                            continuar = 1;
                    }//pc fim
                        else{//pd come�o
                            printf("Escolha uma das op��es de servi�o:\n[1] Mudar check-in e check-out e/ou Mudar op��o de quarto.\n[2] Cancelar reserva.\n");
                            scanf("%d", &resp_alteracao_reserva);
                            fflush(stdin);

                            switch(resp_alteracao_reserva){//pe come�o
                            case 1:
                                printf("\nDeseja alterar data check-in e check-out?\n[1] Sim.\n[2] N�o.\n");
                                scanf("%d", &resp_reserva_sim_nao);
                                fflush(stdin);

                                if(resp_reserva_sim_nao == 1){//pf come�o
                                        padrao_num_diarias_standard = 0;

                                        printf("Digite a nova data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a nova data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);

                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("N�mero total de di�rias atualizado �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };

                                        padrao_num_diarias_standard = days;

                                        printf("\nA diferen�a ser� acertada no ato do check-in!\n");
                                }//pf fim
                                else {
                                        printf("\nData de check-in e check-out n�o alterada\n");};

                                printf("\nDeseja alterar o tipo de quarto?\n[1] Sim.\n[2] N�o.\n");
                                scanf("%d", &resp_reser_tipoq);
                                fflush(stdin);

                                if (resp_reser_tipoq == 1){//pg come�o
                                    printf("\nPara qual tipo de quarto deseja alterar?\n[1] Quarto de Luxo.\n[2] Quarto Suite.\n");
                                    scanf("%d", &resp_tipoq_mreservas);

                                    if (resp_tipoq_mreservas == 1){
                                        if(cadastrados.ja_cadastrado_luxo4 == 0){//oi come�o7
                                                padrao_quarto_reservas_standard = 0;
                                                cadastrados.ja_cadastrado_luxo4 = 1;

                                                num_diarias_qreserva_luxo = 0;

                                                num_diarias_qreserva_luxo = padrao_num_diarias_standard;
                                                padrao_num_diarias_standard = 0;
                                                printf("\nQuarto atualizado com sucesso!\nSeu novo quarto � o n�mero 10 Luxo, Quarto reserva.\n");
                                                printf("\nA diferen�a ser� acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                getch();
                                                continuar = 1;
                                        }//oi fim
                                            else {
                                                printf("Quarto reserva n�o dispon�vel!");};
                                    }
                                    else if(resp_tipoq_mreservas == 2){//ph come�o
                                            if(cadastrados.ja_cadastrado_suite4 == 0){//pi come�o
                                                    padrao_quarto_reservas_standard = 0;
                                                    cadastrados.ja_cadastrado_suite4 = 1;

                                                    num_diarias_qreserva_suite = 0;

                                                    num_diarias_qreserva_suite = padrao_num_diarias_standard;

                                                    padrao_num_diarias_standard = 0;
                                                    printf("\nQuarto atualizado com sucesso!\nSeu novo quarto � o n�mero 12 Standard, Quarto reserva.\n");
                                                    printf("\nA diferen�a ser� acertada no ato do Check-in!\nPressione qualquer tecla para voltar ao menu inicial.\n");
                                                    getch();
                                                    continuar = 1;
                                                }//pi fim
                                                else{
                                                    printf("Quarto reserva n�o dispon�vel!");};
                                }//ph fim
                                    else {
                                        printf("Op��o inv�lida!\n");
                                        continuar = 1;};
                                }//pg fim
                                else {
                                    printf("Tipo de quarto n�o alterado!\n");};
                            break;
                            case 2:
                                printf("\nN�o se esque�a de verificar as pol�ticas de cancelamento\n");
                                padrao_quarto_reservas_standard = 0;
                                padrao_num_diarias_standard = 0;
                                printf("\nCancelamento efetuado com sucesso!\n\n");
                                printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                getch();
                                continuar = 1;

                            break;
                            default:
                                printf("Op��o inv�lida!");
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
                    printf("Op��o inv�lida!");
                    continuar = 1;

                };//d fim
///////////////////////////////////////////////// FIM MINHAS RESERVAS /////////////////////////////////////////////
            break;

            case 2:
                //op��o das novas reservas

                printf("Nova Reserva por:\n");
                printf("[1] Administrador\n");
                printf("[2] Usu�rio Padr�o\n\n");
                scanf("%d", &resp_usuario);
                fflush(stdin);

                switch (resp_usuario){//cb come�o
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
                            printf("Senha Inv�lida!\n");
                            printf("\nNova Reserva atualizada para: *Usu�rio Padr�o*");
                            strcpy(nome_admin_reserva, "Usu�rio Padr�o");
                        };
                break;
                case 2:
                    printf("\nReserva em nome de: Usu�rio Padr�o");
                    strcpy(nome_admin_reserva, "Usu�rio Padr�o");

                break;
                default:
                    printf("Op��o inv�lida");
                    continuar = 1;

                };//cb fim

                printf("\n\nNova Reserva por: %s", nome_admin_reserva);

                printf("\nPor gentileza, escolha o seu quarto\n");


                printf("Digite uma das op��es de quarto: \n [7] Quarto de Luxo \n [8] Quarto Su�te \n [9] Quarto Standart \n");
                scanf("%d", &escolha_quarto.tipo_quarto);
                fflush(stdin);

                switch (escolha_quarto.tipo_quarto){//i come�o
                     //op��o 1 cadastro do quarto de luxo
                      case 7 :

                        printf("\nVoc� escolheu o quarto de luxo. O seu quarto inclui: caf� da manh�, almo�o, jantar, cama casal, banheiro privativo, amplo espa�o e vista privilegiada.\n");
                        printf ("O valor da di�ria �: R$ 1000,00 + taxas.\n");
                        printf("\nSua escolha est� certa? \nDigite [1] para prosseguir para o cadastro!\nDigite [2] para voltar ao menu�de�op��es!\n");
                        gets(escolha_quarto.resposta_quarto);

                        if (strcmp(escolha_quarto.resposta_quarto, "1") == 0) {//j come�o
                            printf("Escolha o n�mero do quarto desejado (1 a 3): ");
                            scanf("%d", &resp_numero_quarto);
                            fflush(stdin);

                             if (resp_numero_quarto == 1){//k come�o
                                    if (cadastrados.ja_cadastrado_luxo1 == 0){//l come�o

                                        printf("Digite a data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                        printf("N�mero total de di�rias �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };//ok

                                        num_diarias_luxo1 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_luxo1 = 1;

                                        printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                        hosp_luxo.total = days * hosp_luxo_valor_diaria + hosp_luxo_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_luxo.total);

                                        printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cart�o de Cr�dito\n\n");

                                        scanf("%d", &hosp_luxo.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_luxo.resposta_pagamento){//m come�o
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2 :
                                            printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                            break;
                                            case 3 :
                                            do {
                                                printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                                printf("\nInforme a data de validade: ");
                                                gets(data_validade);

                                                printf("\nInforme o c�digo de seguran�a do cart�o: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                    switch (hosp_luxo.divisao_cartao){//n come�o
                                                        case 1 :
                                                            printf("\nParcelamento: � vista, R$ %.2f\n", hosp_luxo.total);

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
                                                            printf("Op��o Inv�lida!");

                                                    };//n fim
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                                break;
                                                default: {
                                                    printf("Op��o Inv�lida!");
                                                    continuar = 1;
                                                    };

                                        };//m fim

                                    }//l fim
                                    else {
                                            printf("Quarto n�o dispon�vel.\n");};

                             };//k fim quarto 1 luxo

                             if (resp_numero_quarto == 2){//o come�o
                                if (cadastrados.ja_cadastrado_luxo2 == 0) {//p come�o
                                        printf("Digite a data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("N�mero total de di�rias �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };

                                        num_diarias_luxo2 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_luxo2 = 1;

                                        printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                        hosp_luxo.total = days * hosp_luxo_valor_diaria + hosp_luxo_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_luxo.total);

                                        printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cart�o de Cr�dito\n\n");

                                        scanf("%d", &hosp_luxo.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_luxo.resposta_pagamento){//q come�o
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 3:
                                                do {
                                                printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_luxo.divisao_cartao){//r come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %.2f\n", hosp_luxo.total);

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
                                                        printf("Op��o Inv�lida!");

                                                };//r fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                                    printf("Op��o Inv�lida!");
                                                    continuar = 1;
                                                    };
                                        };//q fim

                                }//p fim
                                else {
                                    printf("Quarto n�o dispon�vel.\n");};

                             };//o fim quarto 2 luxo

                            if (resp_numero_quarto == 3){//s come�o
                                   if (cadastrados.ja_cadastrado_luxo3 == 0) {//t come�o
                                        printf("Digite a data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("N�mero total de di�rias �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };

                                        num_diarias_luxo3 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_luxo3 = 1;

                                        printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                        hosp_luxo.total = days * hosp_luxo_valor_diaria + hosp_luxo_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_luxo.total);

                                        printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cart�o de Cr�dito\n\n");

                                        scanf("%d", &hosp_luxo.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_luxo.resposta_pagamento){//u come�o
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar =1;

                                            break;
                                            case 3:
                                                do {
                                                printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_luxo.divisao_cartao){//v come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %.2f\n", hosp_luxo.total);

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
                                                        printf("Op��o Inv�lida!");

                                                };//v fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                                 printf("Op��o Inv�lida!");
                                                    continuar = 1;};
                                        };//u fim
                                   }//t fim
                                   else {
                                        printf("Quarto n�o dispon�vel.\n");
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

                printf("\nVoc� escolheu o quarto suite. O seu quarto inclui: caf� da manh�, cama casal, banheiro privativo.\n");
                printf ("\nO valor da di�ria �: R$ 500,00 + taxas.\n");
                printf("\nSua escolha est� certa? \nDigite [1] para prosseguir para o cadastro!\nDigite [2] para voltar ao menu�de�op��es!\n");
                gets(escolha_quarto.resposta_quarto);

                if (strcmp(escolha_quarto.resposta_quarto, "1") == 0) {//w come�o
                        printf("Escolha o n�mero do quarto desejado (4 ao 6): ");
                        scanf("%d", &resp_numero_quarto);
                        fflush(stdin);

                        if (resp_numero_quarto == 4) {//x come�o
                                if (cadastrados.ja_cadastrado_suite1 == 0) {//y come�o
                                        printf("Digite a data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("N�mero total de di�rias �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };

                                        num_diarias_suite1 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_suite1 = 1;

                                        printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                        hosp_suite.total = days * hosp_suite_valor_diaria + hosp_suite_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_suite.total);

                                        printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cart�o de Cr�dito\n\n");

                                        scanf("%d", &hosp_suite.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_suite.resposta_pagamento) {//z come�o
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 3:
                                               do {
                                                printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_suite.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_suite.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_suite.divisao_cartao){//aa come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %.2f\n", hosp_suite.total);
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
                                                        printf("Op��o Inv�lida!");

                                                };//aa fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;
                                        break;
                                        default: {
                                                printf("Op��o Inv�lida!");
                                                continuar = 1;};
                                        };//z fim

                                }//y fim
                                else {
                                    printf("Quarto n�o dispon�vel.\n");
                                };

                        };//x fim

                        if (resp_numero_quarto == 5) {//ab come�o
                                if (cadastrados.ja_cadastrado_suite2 == 0) {//ac come�o
                                        printf("Digite a data de check-in (dia m�s ano): ");
                                        scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                        fflush(stdin);

                                        printf("Digite a data de check-out (dia m�s ano): ");
                                        scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                        fflush(stdin);


                                        int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                        if (days >= 0) {
                                            printf("N�mero total de di�rias �: %d\n", days);
                                        } else {
                                            printf("A data de check-out deve ser posterior � data de check-in.\n");
                                        };

                                        num_diarias_suite2 = days;

                                        do {
                                        cadastro cads = cadastro_hospede();

                                        printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                        scanf("%d", &resp_confirma_dados);
                                        fflush(stdin);

                                        }while (resp_confirma_dados == 2);

                                        cadastrados.ja_cadastrado_suite2 = 1;

                                        printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                        printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                        hosp_suite.total = days * hosp_suite_valor_diaria + hosp_suite_taxas;

                                        printf("O valor total ficou em R$ %.2f\n\n", hosp_suite.total);

                                        printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                        printf("[1] Pix\n");
                                        printf("[2] Dinheiro\n");
                                        printf("[3] Cart�o de Cr�dito\n\n");

                                        scanf("%d", &hosp_suite.resposta_pagamento);
                                        fflush(stdin);

                                        switch(hosp_suite.resposta_pagamento) {//ad come�o
                                            case 1 :
                                                printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                                printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                                printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                                getch();
                                                continuar = 1;

                                            break;
                                            case 3:
                                                do {
                                                printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                                fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                                numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                                if (strlen(numero_cartao) != 16) {
                                                    printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                                }
                                                } while (strlen(numero_cartao) != 16);

                                                int c;
                                                while ((c = getchar()) != '\n' && c != EOF);

                                                printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: ");
                                                gets(codigo_seguranca_cartao);

                                                printf("\nO valor total foi R$%.2f\n\n", hosp_suite.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_suite.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_suite.divisao_cartao){//ae come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %.2f\n", hosp_suite.total);

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
                                                        printf("Op��o Inv�lida!");

                                                };//ae fim ok
                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                            printf("Op��o Inv�lida!");
                                            continuar = 1;
                                            };

                                        };//ad fim


                                }//ac fim
                                    else {
                                        printf("Quarto n�o dispon�vel.\n");
                                    };

                        };//ab fim

                        if (resp_numero_quarto == 6) {//af come�o
                            if (cadastrados.ja_cadastrado_suite3 == 0) {//ag come�o

                                    printf("Digite a data de check-in (dia m�s ano): ");
                                    scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                    fflush(stdin);

                                    printf("Digite a data de check-out (dia m�s ano): ");
                                    scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                    fflush(stdin);


                                    int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                    if (days >= 0) {
                                        printf("N�mero total de di�rias �: %d\n", days);
                                    } else {
                                        printf("A data de check-out deve ser posterior � data de check-in.\n");
                                    };

                                    num_diarias_suite3 = days;

                                    do {
                                    cadastro cads = cadastro_hospede();

                                    printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                    scanf("%d", &resp_confirma_dados);
                                    fflush(stdin);

                                    }while (resp_confirma_dados == 2);

                                    cadastrados.ja_cadastrado_suite3 = 1;

                                    printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                    printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                    hosp_suite.total = days * hosp_suite_valor_diaria + hosp_suite_taxas;

                                    printf("O valor total ficou em R$ %.2f\n\n", hosp_suite.total);

                                    printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                    printf("[1] Pix\n");
                                    printf("[2] Dinheiro\n");
                                    printf("[3] Cart�o de Cr�dito\n\n");

                                    scanf("%d", &hosp_suite.resposta_pagamento);
                                    fflush(stdin);

                                    switch(hosp_suite.resposta_pagamento) {//ah come�o
                                        case 1:
                                            printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                            printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                            printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        case 2:
                                            printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        case 3:
                                            do {
                                            printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                            fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                            numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                            if (strlen(numero_cartao) != 16) {
                                                printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                            }
                                            } while (strlen(numero_cartao) != 16);

                                            int c;
                                            while ((c = getchar()) != '\n' && c != EOF);

                                            printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                            printf("Informe a data de validade: ");
                                            gets(data_validade);

                                            printf("Informe o c�digo de seguran�a do cart�o: ");
                                            gets(codigo_seguranca_cartao);

                                            printf("\nO valor total foi R$%.2f\n\n", hosp_suite.total);
                                            printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                            printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                            scanf("%d", &hosp_suite.divisao_cartao);
                                            fflush(stdin);

                                            switch (hosp_suite.divisao_cartao){//ai come�o
                                                case 1 :
                                                    printf("\nParcelamento: � vista, R$ %.2f\n", hosp_suite.total);

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
                                                    printf("Op��o Inv�lida!");

                                            };//ai fim ok

                                            printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                            printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                            printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                            getch();
                                            continuar = 1;

                                        break;
                                        default: {
                                            printf("Op��o Inv�lida!");
                                            continuar = 1;
                                        };

                                    };//ah fim

                            }//ag fim

                                else {
                                    printf("Quarto n�o dispon�vel.\n");
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

                printf("\nVoc� escolheu o quarto standard. O seu quarto inclui: caf� da manh�, 1 cama (tipo: beliche) o quarto e o banheiro s�o compartilhado.\n");
                printf ( "\nO valor da di�ria �: R$ 150,00 + taxas.\n");
                printf("\nSua escolha est� certa? \nDigite [1] para prosseguir para o cadastro!\nDigite [2] para voltar ao menu�de�op��es!\n");
                gets(escolha_quarto.resposta_quarto);

                if (strcmp(escolha_quarto.resposta_quarto, "1") == 0) {//aj come�o

                    printf("Escolha o n�mero do quarto desejado (7 ao 9): ");
                    scanf("%d", &resp_numero_quarto);
                    fflush(stdin);

                    if (resp_numero_quarto == 7) {//ak come�o
                            if (cadastrados.ja_cadastrado_standard1 == 0) {//al come�o
                                printf("Digite a data de check-in (dia m�s ano): ");
                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                fflush(stdin);

                                printf("Digite a data de check-out (dia m�s ano): ");
                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                fflush(stdin);


                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                if (days >= 0) {
                                    printf("N�mero total de di�rias �: %d\n", days);
                                } else {
                                    printf("A data de check-out deve ser posterior � data de check-in.\n");
                                };

                                num_diarias_standard1 = days;

                                do {
                                cadastro cads = cadastro_hospede();

                                printf("\nAp�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                scanf("%d", &resp_confirma_dados);
                                fflush(stdin);

                                }while (resp_confirma_dados == 2);

                                cadastrados.ja_cadastrado_standard1 = 1;

                                printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                hosp_standart.total = days * hosp_standart_valor_diaria + hosp_standart_taxas;

                                printf("O valor total ficou em R$ %.2f\n\n", hosp_standart.total);

                                printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                printf("[1] Pix\n");
                                printf("[2] Dinheiro\n");
                                printf("[3] Cart�o de Cr�dito\n\n");

                                scanf("%d", &hosp_standart.resposta_pagamento);
                                fflush(stdin);

                                switch(hosp_standart.resposta_pagamento) {//am come�o
                                    case 1 :
                                        printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                        printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                        printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 2:
                                        printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 3:
                                        do {
                                        printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                        fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                        numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                        if (strlen(numero_cartao) != 16) {
                                            printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                        }
                                        } while (strlen(numero_cartao) != 16);

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);

                                        printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o c�digo de seguran�a do cart�o: ");
                                        gets(codigo_seguranca_cartao);

                                        printf("\nO valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                        switch (hosp_standart.divisao_cartao){//an come�o
                                            case 1 :
                                                printf("\nParcelamento: � vista, R$ %.2f\n", hosp_standart.total);

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
                                                printf("Op��o Inv�lida!");
                                        };//an fim
                                    printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                    printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                    printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                    getch();
                                    continuar = 1;

                                    break;
                                    default: {
                                        printf("Op��o Inv�lida!");
                                        continuar = 1;};

                                };//am fim

                            }//al fim
                             else {
                                    printf("Quarto n�o dispon�vel.\n");
                                };
                    };//ak fim
                    if (resp_numero_quarto == 8) {//ao come�o
                        if (cadastrados.ja_cadastrado_standard2 == 0) {//ap come�o
                                printf("Digite a data de check-in (dia m�s ano): ");
                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                fflush(stdin);

                                printf("Digite a data de check-out (dia m�s ano): ");
                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                fflush(stdin);


                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                if (days >= 0) {
                                    printf("N�mero total de di�rias �: %d\n", days);
                                } else {
                                    printf("A data de check-out deve ser posterior � data de check-in.\n");
                                };

                                num_diarias_standard2 = days;

                                do {
                                cadastro cads = cadastro_hospede();

                                printf("\nAp�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                scanf("%d", &resp_confirma_dados);
                                fflush(stdin);

                                }while (resp_confirma_dados == 2);

                                cadastrados.ja_cadastrado_standard2 = 1;

                                printf(" *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                hosp_standart.total = days * hosp_standart_valor_diaria + hosp_standart_taxas;

                                printf("O valor total ficou em R$ %.2f\n\n", hosp_standart.total);

                                printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                printf("[1] Pix\n");
                                printf("[2] Dinheiro\n");
                                printf("[3] Cart�o de Cr�dito\n\n");

                                scanf("%d", &hosp_standart.resposta_pagamento);
                                fflush(stdin);

                                switch(hosp_standart.resposta_pagamento) {//aq come�o
                                    case 1 :
                                        printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                        printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                        printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 2:
                                        printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 3:
                                        do {
                                        printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                        fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                        numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                        if (strlen(numero_cartao) != 16) {
                                            printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                        }
                                        } while (strlen(numero_cartao) != 16);

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);

                                        printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o c�digo de seguran�a do cart�o: ");
                                        gets(codigo_seguranca_cartao);

                                        printf("\nO valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                         switch (hosp_standart.divisao_cartao){//ar come�o
                                             case 1 :
                                                printf("\nParcelamento: � vista, R$ %.2f\n", hosp_standart.total);
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
                                                printf("Op��o Inv�lida!");

                                         };//ar fim ok
                                         printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    default: {
                                        printf("Op��o Inv�lida!");
                                        continuar = 1; };

                                }//aq fim ok


                        }//ap fim
                        else {
                            printf("Quarto n�o dispon�vel.\n");
                        };

                    };//ao fim

                     if (resp_numero_quarto == 9) {//as come�o
                        if (cadastrados.ja_cadastrado_standard3 == 0) {//at come�o
                                printf("Digite a data de check-in (dia m�s ano): ");
                                scanf("%d %d %d", &checkin_day, &checkin_month, &checkin_year);
                                fflush(stdin);

                                printf("Digite a data de check-out (dia m�s ano): ");
                                scanf("%d %d %d", &checkout_day, &checkout_month, &checkout_year);
                                fflush(stdin);


                                int days = days_between_dates(checkin_year, checkin_month, checkin_day, checkout_year, checkout_month, checkout_day);

                                if (days >= 0) {
                                    printf("N�mero total de di�rias �: %d\n", days);
                                } else {
                                    printf("A data de check-out deve ser posterior � data de check-in.\n");
                                };

                                num_diarias_standard3 = days;

                                do {
                                cadastro cads = cadastro_hospede();

                                printf("Ap�s a revis�o de seus dados: \nDigite [1] para prosseguir para a �rea de pagamento. \nDigite [2] para refazer o cadastro.\n");
                                scanf("%d", &resp_confirma_dados);
                                fflush(stdin);

                                }while (resp_confirma_dados == 2);

                                cadastrados.ja_cadastrado_standard3 = 1;

                                printf("\n *A confirma��o da sua reserva ser� enviada no e-mail informado no cadastro* \n\n");

                                printf("\n========== �REA DE PAGAMENTO =========\n\n");

                                hosp_standart.total = days * hosp_standart_valor_diaria + hosp_standart_taxas;

                                printf("O valor total ficou em R$ %.2f\n\n", hosp_standart.total);

                                printf("Digite a forma a op��o da forma de pagamento: \n\n");
                                printf("[1] Pix\n");
                                printf("[2] Dinheiro\n");
                                printf("[3] Cart�o de Cr�dito\n\n");

                                scanf("%d", &hosp_standart.resposta_pagamento);
                                fflush(stdin);

                                switch(hosp_standart.resposta_pagamento) {//au come�o
                                    case 1 :
                                        printf("Chave PIX para pagamento: 30.303.030/0001-30\n\n");

                                        printf("Ap�s o pagamento envie o comprovante para o seguinte n�mero: (016) 3030-3030\n\n");

                                        printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 2:
                                        printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    case 3:
                                        do {
                                        printf("Digite o n�mero do seu cart�o (16 d�gitos): ");
                                        fgets(numero_cartao, sizeof(numero_cartao), stdin);
                                        numero_cartao[strcspn(numero_cartao, "\n")] = '\0'; // Remove a quebra de linha

                                        if (strlen(numero_cartao) != 16) {
                                            printf("\nO n�mero do cart�o deve conter exatamente 16 d�gitos.\n");
                                        }
                                        } while (strlen(numero_cartao) != 16);

                                        int c;
                                        while ((c = getchar()) != '\n' && c != EOF);

                                        printf("N�mero do cart�o v�lido: %s\n", numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o c�digo de seguran�a do cart�o: ");
                                        gets(codigo_seguranca_cartao);

                                        printf("\nO valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                         switch (hosp_standart.divisao_cartao){//av come�o
                                             case 1 :
                                                printf("\nParcelamento: � vista, R$ %.2f\n", hosp_standart.total);

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
                                                printf("Op��o Inv�lida!");

                                         };//av fim ok
                                         printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, pressione qualquer tecla para voltar ao menu incial\n");
                                        getch();
                                        continuar = 1;

                                    break;
                                    default: {
                                            printf("Op��o Inv�lida!");
                                            continuar = 1;
                                        };

                                };//au fim

                        }//at fim
                            else {
                                printf("Quarto n�o dispon�vel.\n");
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
                printf("op��o inv�lida!");
                continuar = 1;
            };

                };//i fim switch tipo quarto

/////////////////////////////////////////////FIM NOVAS RESERVAS /////////////////////////////////////////////////////////

        break;
        case 3:
            printf("\nPor favor, escolha uma das op��es de informa��es gerais que deseja obter!\n\n");
            printf("[1] Pol�ticas de Cancelamento\n");
            printf("[2] Lei Geral de Prote��o de Dados(LGPD)\n");
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
                        printf("Op��o inv�lida!");
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

            if( resp_senha_admin == 1234){//ca come�o
                printf("\nRelat�rios sendo gerados por: %s", nome_administrador_relatorio);

            printf("\n===== Relat�rios =====\n\n");
            printf("[1] Faturamento.\n");
            printf("[2] Quartos Reservados.\n");
            scanf("%d", &resp_relatorio);

                switch (resp_relatorio){//aw come�o
                    case 1:
                        printf("\n===== Relat�rio de Faturamento ====\n\n");
                        num_total_diarias_luxo = num_diarias_luxo1 + num_diarias_luxo2 + num_diarias_luxo3;
                        fat_luxo = num_total_diarias_luxo * hosp_luxo_valor_diaria;
                        printf("\nO Faturamento do Quarto de Luxo �: R$%.2f", fat_luxo); //verificar taxas

                        num_total_diarias_suite = num_diarias_suite1 + num_diarias_suite2 + num_diarias_suite3;
                        fat_suite = num_total_diarias_suite * hosp_suite_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Suite �: R$%.2f", fat_suite);

                        num_total_diarias_standard = num_diarias_standard1 + num_diarias_standard2 + num_diarias_standard3;
                        fat_standard = num_total_diarias_standard * hosp_standart_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Standard �: R$%.2f", fat_standard);

                        fat_reserva_luxo = num_diarias_qreserva_luxo * hosp_luxo_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Reserva de Luxo �: R$%.2f", fat_reserva_luxo);

                        fat_reserva_suite = num_diarias_qreserva_suite * hosp_suite_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Reserva Suite �: R$%.2f", fat_reserva_suite);

                        fat_reserva_standard = num_diarias_qreservas_standard * hosp_standart_valor_diaria;
                        printf("\n\nO Faturamento do Quarto Reserva Standard �: R$%.2f", fat_reserva_standard);

                        fat_total = fat_luxo + fat_suite + fat_standard + fat_reserva_luxo + fat_reserva_standard + fat_reserva_suite;
                        printf("\n\nO Faturamento Total �: R$%.2f\n", fat_total);
                        printf("Relat�rio gerado sem a adi��o das taxas.\n");

                        printf("\nRelat�rio Gerado por: %s\n\n", nome_administrador_relatorio);
                        printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
                        getch();
                        continuar = 1;

                    break;
                    case 2:
                        printf("\n==== Relat�rio de Quartos Reservados ====\n\n");

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

                        printf("\nRelat�rio Gerado por: %s\n\n", nome_administrador_relatorio);
                        printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
                        getch();
                        continuar = 1;

                    break;
                    default:
                        printf("Escolha inv�lida");
                        continuar = 1;
                };//aw fim
            }//ca fim
                else {
                    printf("==Senha Inv�lida==\n\n");
                    printf("Pressione qualquer tecla para voltar ao menu inicial.\n");
                    getch();
                    continuar = 1;
                }

        break;
        case 5:
            continuar = 0;

        break;
        default:{
            printf("Op��o Inv�lida!");
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

    printf("\nG�nero: ");
    gets(cads.genero);

    printf("\nDigite seu documento de identifica��o: ");
    gets(cads.documento);

    printf("\nInforme seu n�mero de contato: ");
    gets(cads.fone);

    printf("\nInforme um telefone para emerg�ncia: ");
    gets(cads.fone_emergencia);


            printf("\nH� acompanhante?\nDigite [1] para sim\nDigite [2] para n�o\n ");
            gets(cads.resposta);


            if (strcmp(cads.resposta, "1") == 0) {
                printf("\nPor favor preencha os dados do acompanhante\n");
                printf("\nNome do acompanhante: ");
                gets(cads.nome_acompanhante);

                printf("\nDigite o documento de identifica��o do acompanhante: ");
                gets(cads.documento_acompanhante);

                printf("\nInforme o telefone para casos de emerg�ncia: ");
                gets(cads.fone_acompanhante);

                printf("Os dados do acompanhante s�o: \n\n%s \n%s \n%s \n", cads.nome_acompanhante, cads.documento_acompanhante, cads.fone_acompanhante);
                printf("Cadastro do acompanhante finalizado com sucesso!");

                } else {
                    printf("Reserva sem acompanhante");

                };

        printf("\n\nOs seus dados ent�o corretos?");
        printf("\n\nNome: %s \nE-mail: %s \nG�nero: %s \nDocumento: %s \nTelefone: %s \nEmeg�ncia: %s \n", cads.nome, cads.email, cads.genero, cads.documento, cads.fone, cads.fone_emergencia);


return;
}

