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

    int days_between = days_checkout - days_checkin + days_in_years;

    return days_between;
}

    struct cadastrado{
        int ja_cadastrado_luxo1;
        int ja_cadastrado_luxo2;
        int ja_cadastrado_luxo3;

        int ja_cadastrado_suite1;
        int ja_cadastrado_suite2;
        int ja_cadastrado_suite3;

        int ja_cadastrado_standard1;
        int ja_cadastrado_standard2;
        int ja_cadastrado_standard3;
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

    char numero_cartao[19], data_validade[7], codigo_seguranca_cartao[3];

    float fat_suite = 0, fat_standard = 0, fat_total,  fat_luxo = 0;

    int menu_voltar, resp_info, resp_relatorio, resp_numero_quarto, resp_minhas_reservas, resp_minhas_reservas_num, resp_cancelamento;

    int num_diarias_luxo1 = 0, num_diarias_luxo2 = 0, num_diarias_luxo3 = 0, num_diarias_suite1 = 0, num_diarias_suite2 = 0, num_diarias_suite3 = 0, num_diarias_standard1 = 0, num_diarias_standard2 = 0, num_diarias_standard3 = 0;
    int total_quartos_reservados_luxo = 0, total_quartos_reservados_suite = 0, total_quartos_reservados_standard = 0, total_quartos_reservados = 0;
    int num_total_diarias_luxo = 0, num_total_diarias_suite = 0, num_total_diarias_standard = 0;

    int continuar = 1;

    struct cadastrado cadastrados;

    int total_reservas = 0;

    cadastrados.ja_cadastrado_luxo1 = 0;
    cadastrados.ja_cadastrado_luxo2 = 0;
    cadastrados.ja_cadastrado_luxo3 = 0;

    cadastrados.ja_cadastrado_suite1 = 0;
    cadastrados.ja_cadastrado_suite2 = 0;
    cadastrados.ja_cadastrado_suite3 = 0;

    cadastrados.ja_cadastrado_standard1 = 0;
    cadastrados.ja_cadastrado_standard2 = 0;
    cadastrados.ja_cadastrado_standard3 = 0;


    struct registro registros;

    while (continuar) {//b come�o

        printf("\n=======Seja bem vindo ao hotel UNIP!=======\n\n");

        printf("Por favor, escolha uma das op��es de servi�o:\n");

        printf("[1] Minhas Reservas\n");// ultimo(incluir op��o de cancelamento)
        printf("[2] Nova Reserva\n"); // primeiro
        printf("[3] Reservas por Administradores\n");
        printf("[4] Informa��es Gerais\n");
        printf("[5] Gerar Relat�rios\n"); //ultimo
        printf("[6] Sair\n\n");

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
                            printf("Seu quarto reservado foi o Quarto de Luxo.\n\n");
                            printf("Informe o n�mero do quarto reservado (1 ao 3):  ");
                            scanf("%d", &resp_minhas_reservas_num);
                            fflush(stdin);

                                switch (resp_minhas_reservas_num) {//ba come�o
                                case 1:
                                    if(cadastrados.ja_cadastrado_luxo1 == 1){//bb come�o
                                            printf("Deseja cancelar sua reserva?\n");
                                            printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                                            printf("Digite [1] para confirmar o cancelamento.\n");
                                            printf("Digite [2] para n�o efetuar o cancelamento e voltar ao menu inicial.\n\n");
                                            scanf("%d", &resp_cancelamento);
                                            fflush(stdin);

                                                switch(resp_cancelamento){//bc come�o
                                                case 1:
                                                    cadastrados.ja_cadastrado_luxo1 = 0;
                                                    printf("Cancelamento efetuado com sucesso!\n\n");
                                                    printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                                    printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                                    getch();
                                                    continuar = 1;
                                                break;
                                                default:
                                                    continuar = 1;
                                                };//bc fim
                                    }//bb fim
                                        else {
                                            printf("N�o h� reservas nesse quarto!");};
                                break;
                                case 2:
                                    if(cadastrados.ja_cadastrado_luxo2 == 1){//bd come�o
                                            printf("Deseja cancelar sua reserva?\n");
                                            printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                                            printf("Digite [1] para confirmar o cancelamento.\n");
                                            printf("Digite [2] para n�o efetuar o cancelamento e voltar ao menu inicial.\n\n");
                                            scanf("%d", &resp_cancelamento);
                                            fflush(stdin);

                                            switch(resp_cancelamento){//be come�o
                                                case 1:
                                                    cadastrados.ja_cadastrado_luxo2 = 0;
                                                    printf("Cancelamento efetuado com sucesso!\n\n");
                                                    printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                                    printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                                    getch();
                                                    continuar = 1;
                                                break;
                                                default:
                                                    continuar = 1;
                                            };//be fim ok

                                    }//bd fim
                                        else {
                                            printf("N�o h� reservas nesse quarto!");};
                                break;
                                case 3:
                                    if(cadastrados.ja_cadastrado_luxo3 == 1){//bf come�o
                                            printf("Deseja cancelar sua reserva?\n");
                                            printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                                            printf("Digite [1] para confirmar o cancelamento.\n");
                                            printf("Digite [2] para n�o efetuar o cancelamento e voltar ao menu inicial.\n\n");
                                            scanf("%d", &resp_cancelamento);
                                            fflush(stdin);

                                            switch(resp_cancelamento){//bg come�o
                                                case 1:
                                                    cadastrados.ja_cadastrado_luxo3 = 0;
                                                    printf("Cancelamento efetuado com sucesso!\n\n");
                                                    printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                                    printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                                    getch();
                                                    continuar = 1;
                                                break;
                                                default:
                                                    continuar = 1;
                                            };//bg fim
                                    }//bf fim
                                        else {
                                            printf("N�o h� reservas nesse quarto!");};
                                    break;
                                    default:
                                        printf("Op��o inv�lida");
                                        continuar = 1;
                                };//ba fim ok

                    break;
                    case 8:
                        printf("Seu quarto reservado foi o Quarto Suite.\n\n");
                        printf("Informe o n�mero do quarto reservado (4 ao 6):  ");
                        scanf("%d", &resp_minhas_reservas_num);
                        fflush(stdin);

                        switch (resp_minhas_reservas_num){//bh come�o
                        case 4:
                            if(cadastrados.ja_cadastrado_suite1 == 1){//bi come�o
                                    printf("Deseja cancelar sua reserva?\n");
                                    printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                                    printf("Digite [1] para confirmar o cancelamento.\n");
                                    printf("Digite [2] para N�O efetuar o cancelamento e voltar ao menu inicial.\n\n");
                                    scanf("%d", &resp_cancelamento);
                                    fflush(stdin);

                                    switch(resp_cancelamento){//BJ COME�O
                                    case 1:
                                        cadastrados.ja_cadastrado_suite1 = 0;
                                        printf("Cancelamento efetuado com sucesso!\n\n");
                                        printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                        printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                        getch();
                                        continuar = 1;
                                    break;
                                    default:
                                        continuar = 1;
                                    };//BJ FIM ok
                            }//bi fim ok
                                else {
                                    printf("N�o h� reservas nesse quarto!");};
                        break;
                        case 5:
                            if(cadastrados.ja_cadastrado_suite2 == 1){//BK COME�O
                                    printf("Deseja cancelar sua reserva?\n");
                                    printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                                    printf("Digite [1] para confirmar o cancelamento.\n");
                                    printf("Digite [2] para N�O efetuar o cancelamento e voltar ao menu inicial.\n\n");
                                    scanf("%d", &resp_cancelamento);
                                    fflush(stdin);

                                    switch(resp_cancelamento){//bl come�o
                                    case 1:
                                        cadastrados.ja_cadastrado_suite2 = 0;
                                        printf("Cancelamento efetuado com sucesso!\n\n");
                                        printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                        printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                        getch();
                                        continuar = 1;
                                    break;
                                    default:
                                        continuar = 1;
                                    };//bl fim ok
                            }//BK FIM ok
                                else {
                                    printf("N�o h� reservas nesse quarto!");};
                        break;
                        case 6:
                            if(cadastrados.ja_cadastrado_suite3 == 1){//bm come�o
                                    printf("Deseja cancelar sua reserva?\n");
                                    printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                                    printf("Digite [1] para confirmar o cancelamento.\n");
                                    printf("Digite [2] para N�O efetuar o cancelamento e voltar ao menu inicial.\n\n");
                                    scanf("%d", &resp_cancelamento);
                                    fflush(stdin);

                                    switch(resp_cancelamento){//bn come�o
                                    case 1:
                                        cadastrados.ja_cadastrado_suite3 = 0;
                                        printf("Cancelamento efetuado com sucesso!\n\n");
                                        printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                        getch();
                                        continuar = 1;
                                    break;
                                    default:
                                        continuar = 1;
                                    };//bn fim
                            }//bm fim
                            else {
                                    printf("N�o h� reservas nesse quarto!");};
                        break;
                        default:
                            printf("Op��o inv�lida");
                            continuar = 1;

                        }//bh fim ok
                break;
                case 9:
                    printf("Seu quarto reservado foi o Quarto Standard.\n\n");
                    printf("Informe o n�mero do quarto reservado (7 ao 9):  ");
                    scanf("%d", &resp_minhas_reservas_num);
                    fflush(stdin);

                    switch (resp_minhas_reservas_num){//bo come�o
                    case 7:
                       if(cadastrados.ja_cadastrado_standard1 == 1){//bp come�o
                            printf("Deseja cancelar sua reserva?\n");
                            printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                            printf("Digite [1] para confirmar o cancelamento.\n");
                            printf("Digite [2] para N�O efetuar o cancelamento e voltar ao menu inicial.\n\n");
                            scanf("%d", &resp_cancelamento);
                            fflush(stdin);

                            switch(resp_cancelamento){////bq come�o
                            case 1:
                                cadastrados.ja_cadastrado_standard1 = 0;
                                printf("Cancelamento efetuado com sucesso!\n\n");
                                printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                getch();
                                continuar = 1;
                            break;
                            default:
                                continuar = 1;
                            };//bq fim ok
                       }//bp fim
                        else {
                            printf("N�o h� reservas nesse quarto!");};
                    break;
                    case 8:
                        if(cadastrados.ja_cadastrado_standard2 == 1){//br come�o
                            printf("Deseja cancelar sua reserva?\n");
                            printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                            printf("Digite [1] para confirmar o cancelamento.\n");
                            printf("Digite [2] para N�O efetuar o cancelamento e voltar ao menu inicial.\n\n");
                            scanf("%d", &resp_cancelamento);
                            fflush(stdin);

                            switch(resp_cancelamento){//bs come�o
                            case 1:
                                cadastrados.ja_cadastrado_standard2 = 0;
                                printf("Cancelamento efetuado com sucesso!\n\n");
                                printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                getch();
                                continuar = 1;
                            break;
                            default:
                                continuar = 1;
                            };//bs fim ok
                        }//br fim
                         else {
                            printf("N�o h� reservas nesse quarto!");};
                    break;
                    case 9:
                        if(cadastrados.ja_cadastrado_standard3 == 1){//bt come�o
                            printf("Deseja cancelar sua reserva?\n");
                            printf("*N�o se esque�a de verificar nossas pol�ticas de cancelamento antes de finalizar seu cancelamento*\n\n");

                            printf("Digite [1] para confirmar o cancelamento.\n");
                            printf("Digite [2] para N�O efetuar o cancelamento e voltar ao menu inicial.\n\n");
                            scanf("%d", &resp_cancelamento);
                            fflush(stdin);

                            switch(resp_cancelamento){//bu come�o
                                case 1:
                                cadastrados.ja_cadastrado_standard3 = 0;
                                printf("Cancelamento efetuado com sucesso!\n\n");
                                printf("Analisaremos as condi��es de estorno e daremos um retorno via e-mail cadastrado na reserva!\n\n");
                                printf("Pressione qualquer tecla para retornar ao menu inicial!\n");
                                getch();
                                continuar = 1;
                            break;
                            default:
                                continuar = 1;
                            };//bu fim
                        }//bt fim
                            else {
                            printf("N�o h� reservas nesse quarto!");};

                    break;
                    default:
                        printf("Op��o inv�lida");
                        continuar = 1;

                    };//bo fim ok

            break;
            default:
                printf("Op��o inv�lida!");
                continuar = 1;

                };//d fim
///////////////////////////////////////////////// FIM MINHAS RESERVAS /////////////////////////////////////////////
            break;

            case 2:
                //op��o das novas reservas
                printf("Por gentileza, escolha o seu quarto\n");


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

                                        cadastro cads = cadastro_hospede();
                                        cadastrados.ja_cadastrado_luxo1 = 1;

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

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        } else
                                                    continuar = 1;

                                            break;
                                            case 2 :
                                            printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                            printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                            scanf("%d", &menu_voltar);
                                            fflush(stdin);

                                                if(menu_voltar == 0) {
                                                continuar = 1;
                                                    } else
                                                continuar = 1;

                                            break;
                                            case 3 :
                                                printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                                gets(numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                                gets(codigo_seguranca_cartao);

                                                printf("O valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                    switch (hosp_luxo.divisao_cartao){//n come�o
                                                        case 1 :
                                                            printf("\nParcelamento: � vista, R$ %f\n", hosp_luxo.total);

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

                                                break;
                                                default: {
                                                    printf("Op��o Inv�lida!");
                                                    continuar = 1;
                                                    };

                                        };//m fim

                                        printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                        if(menu_voltar == 0) {
                                            continuar = 1;
                                        } else
                                            continuar = 1;

                                    }//l fim
                                    else {
                                            printf("Quarto n�o dispon�vel.\n");};

                             };//k fim quarto 1 luxo

                             ////////////////////////////
                             /////////////////////////////
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

                                        cadastro cads = cadastro_hospede();
                                        cadastrados.ja_cadastrado_luxo2 = 1;

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

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                            else
                                                                continuar = 1;
                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");
                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                            else
                                                                continuar = 1;
                                            break;
                                            case 3:
                                                printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                                gets(numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                                gets(codigo_seguranca_cartao);

                                                printf("O valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_luxo.divisao_cartao){//r come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %f\n", hosp_luxo.total);

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

                                            break;
                                            default: {
                                                    printf("Op��o Inv�lida!");
                                                    continuar = 1;
                                                    };
                                        };//q fim

                                         printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                        if(menu_voltar == 0) {
                                                continuar = 1;
                                                    }
                                                else
                                                    continuar = 1;

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

                                        cadastro cads = cadastro_hospede();
                                        cadastrados.ja_cadastrado_luxo3 = 1;

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

                                                printf("==== Pagamento efetuado com sucesso! =====\n\n");

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                            else
                                                                continuar = 1;
                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                            else
                                                                continuar = 1;
                                            break;
                                            case 3:
                                                printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                                gets(numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                                gets(codigo_seguranca_cartao);

                                                printf("O valor total foi R$%.2f\n\n", hosp_luxo.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_luxo.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_luxo.divisao_cartao){//v come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %f\n", hosp_luxo.total);

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

                                            break;
                                            default: {
                                                     printf("Op��o Inv�lida!");
                                                        continuar = 1;};

                                        };//u fim

                                        printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                        if(menu_voltar == 0) {
                                            continuar = 1;
                                                }
                                            else
                                                continuar = 1;

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

                                        cadastro cads = cadastro_hospede();
                                        cadastrados.ja_cadastrado_suite1 = 1;

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

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                            else
                                                                continuar = 1;
                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                    } else
                                                            continuar = 1;
                                            break;
                                            case 3:
                                                printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                                gets(numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                                gets(codigo_seguranca_cartao);

                                                printf("O valor total foi R$%.2f\n\n", hosp_suite.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_suite.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_suite.divisao_cartao){//aa come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %f\n", hosp_suite.total);
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
                                            break;
                                            default: {
                                                printf("Op��o Inv�lida!");
                                                continuar = 1;};
                                        };//z fim

                                        printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                        if(menu_voltar == 0) {
                                            continuar = 1;
                                                }
                                            else
                                                continuar = 1;

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

                                        num_diarias_suite1 = days;

                                        cadastro cads = cadastro_hospede();
                                        cadastrados.ja_cadastrado_suite2 = 1;

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

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                            else
                                                                continuar = 1;
                                            break;
                                            case 2:
                                                printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                                scanf("%d", &menu_voltar);
                                                fflush(stdin);

                                                    if(menu_voltar == 0) {
                                                    continuar = 1;
                                                        }
                                                        else
                                                            continuar = 1;
                                            break;
                                            case 3:
                                                printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                                gets(numero_cartao);

                                                printf("Informe a data de validade: ");
                                                gets(data_validade);

                                                printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                                gets(codigo_seguranca_cartao);

                                                printf("O valor total foi R$%.2f\n\n", hosp_suite.total);
                                                printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                                printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                                scanf("%d", &hosp_suite.divisao_cartao);
                                                fflush(stdin);

                                                switch (hosp_suite.divisao_cartao){//ae come�o
                                                    case 1 :
                                                        printf("\nParcelamento: � vista, R$ %f\n", hosp_suite.total);

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
                                        break;
                                        default: {
                                            printf("Op��o Inv�lida!");
                                            continuar = 1;
                                            };

                                        };//ad fim

                                        printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                        printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                        if(menu_voltar == 0) {
                                            continuar = 1;
                                                }
                                            else
                                                continuar = 1;
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

                                    cadastro cads = cadastro_hospede();
                                    cadastrados.ja_cadastrado_suite3 = 1;

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

                                            printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                            scanf("%d", &menu_voltar);
                                            fflush(stdin);

                                                if(menu_voltar == 0) {
                                                continuar = 1;
                                                    }
                                                        else
                                                            continuar = 1;
                                        break;
                                        case 2:
                                            printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                            printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                            scanf("%d", &menu_voltar);
                                            fflush(stdin);

                                                if(menu_voltar == 0) {
                                                continuar = 1;
                                                    }
                                                        else
                                                            continuar = 1;
                                        break;
                                        case 3:
                                            printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                            gets(numero_cartao);

                                            printf("Informe a data de validade: ");
                                            gets(data_validade);

                                            printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                            gets(codigo_seguranca_cartao);

                                            printf("O valor total foi R$%.2f\n\n", hosp_suite.total);
                                            printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                            printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                            scanf("%d", &hosp_suite.divisao_cartao);
                                            fflush(stdin);

                                            switch (hosp_suite.divisao_cartao){//ai come�o
                                                case 1 :
                                                    printf("\nParcelamento: � vista, R$ %f\n", hosp_suite.total);

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

                                        break;
                                        default: {
                                            printf("Op��o Inv�lida!");
                                            continuar = 1;
                                        };

                                    };//ah fim

                                    printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                    printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                    printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                    scanf("%d", &menu_voltar);
                                    fflush(stdin);

                                    if(menu_voltar == 0) {
                                        continuar = 1;
                                            }
                                        else
                                            continuar = 1;

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

                                cadastro cads = cadastro_hospede();
                                cadastrados.ja_cadastrado_standard1 = 1;

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

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);

                                            if(menu_voltar == 0) {
                                            continuar = 1;
                                                }
                                                    else
                                                        continuar = 1;
                                    break;
                                    case 2:
                                        printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                            if(menu_voltar == 0) {
                                            continuar = 1;
                                                } else
                                                        continuar = 1;
                                    break;
                                    case 3:
                                        printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                        gets(numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                        gets(codigo_seguranca_cartao);

                                        printf("O valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                        switch (hosp_standart.divisao_cartao){//an come�o
                                            case 1 :
                                                printf("\nParcelamento: � vista, R$ %f\n", hosp_standart.total);

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
                                    break;
                                    default: {
                                        printf("Op��o Inv�lida!");
                                        continuar = 1;};

                                };//am fim

                                printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                scanf("%d", &menu_voltar);

                                if(menu_voltar == 0) {
                                    continuar = 1;
                                        }
                                    else
                                        continuar = 1;

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

                                cadastro cads = cadastro_hospede();
                                cadastrados.ja_cadastrado_standard2 = 1;

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

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                            if(menu_voltar == 0) {
                                            continuar = 1;
                                                } else
                                                        continuar = 1;
                                    break;
                                    case 2:
                                        printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                            if(menu_voltar == 0) {
                                            continuar = 1;
                                                } else
                                                        continuar = 1;
                                    break;
                                    case 3:
                                        printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                        gets(numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                        gets(codigo_seguranca_cartao);

                                        printf("O valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                         switch (hosp_standart.divisao_cartao){//ar come�o
                                             case 1 :
                                                printf("\nParcelamento: � vista, R$ %f\n", hosp_standart.total);
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
                                    break;
                                    default: {
                                        printf("Op��o Inv�lida!");
                                        continuar = 1; };

                                }//aq fim ok
                                printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                scanf("%d", &menu_voltar);
                                fflush(stdin);

                                if(menu_voltar == 0) {
                                    continuar = 1;
                                        }
                                    else
                                        continuar = 1;
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

                                cadastro cads = cadastro_hospede();
                                cadastrados.ja_cadastrado_standard3 = 1;

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

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                            if(menu_voltar == 0) {
                                            continuar = 1;
                                                }
                                                    else
                                                        continuar = 1;
                                    break;
                                    case 2:
                                        printf("==== Op��o de pagamento registrado ==== \n\nNesta op��o o pagamento dever� ser efetuado no ato do check-in\n\n");

                                        printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                        scanf("%d", &menu_voltar);
                                        fflush(stdin);

                                            if(menu_voltar == 0) {
                                            continuar = 1;
                                                }
                                                    else
                                                        continuar = 1;
                                    break;
                                    case 3:
                                        printf("Informe o n�mero do cart�o (16 d�gitos): ");
                                        gets(numero_cartao);

                                        printf("Informe a data de validade: ");
                                        gets(data_validade);

                                        printf("Informe o c�digo de seguran�a do cart�o: \n\n");
                                        gets(codigo_seguranca_cartao);

                                        printf("O valor total foi R$%.2f\n\n", hosp_standart.total);
                                        printf("Deseja dividir esse valor em quantas parcelas?\n\n");
                                        printf("[1] � vista \n[2] 2x sem juros \n[3] 3x sem juros\n");

                                        scanf("%d", &hosp_standart.divisao_cartao);
                                        fflush(stdin);

                                         switch (hosp_standart.divisao_cartao){//av come�o
                                             case 1 :
                                                printf("\nParcelamento: � vista, R$ %f\n", hosp_standart.total);

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

                                    break;
                                    default: {
                                            printf("Op��o Inv�lida!");
                                            continuar = 1;
                                        };

                                };//au fim

                                printf("\n\n====== Pagamento efetuado com sucesso =======\n\n");

                                printf("Esta transa��o est� assegurada pela Lei Geral de Prote��o de Dados (LGPD)\n\n");

                                printf("Por favor, digite [0] para voltar ao menu inicial\n");
                                scanf("%d", &menu_voltar);
                                fflush(stdin);

                                if(menu_voltar == 0) {
                                    continuar = 1;
                                        }
                                    else
                                        continuar = 1;
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

        break;
        case 3:
            printf("Op��o n�o finalizada\n\n");
            printf("Por favor, digite [0] para voltar ao menu inicial!\n");
            scanf("%d", &menu_voltar);
            fflush(stdin);
            if(menu_voltar == 0){
                continuar = 1;
            }else {
                continuar = 1;
            };

        break;
        case 4:
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

        break;
        case 5:
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

                        fat_total = fat_luxo + fat_suite + fat_standard;
                        printf("\n\nO Faturamento Total �: R$%.2f\n", fat_total);

                        continuar = 1;
                    break;
                    case 2:
                        printf("\n==== Relat�rio de Quartos Reservados ====\n\n");

                        if (cadastrados.ja_cadastrado_luxo1 == 1){
                            total_quartos_reservados_luxo += 1;};

                        if (cadastrados.ja_cadastrado_luxo2 == 1){
                            total_quartos_reservados_luxo += 1;};


                        if (cadastrados.ja_cadastrado_luxo3 == 1){
                            total_quartos_reservados_luxo += 1;};


                        if (cadastrados.ja_cadastrado_standard1 == 1){
                            total_quartos_reservados_standard += 1;};

                        if (cadastrados.ja_cadastrado_standard2 == 1){
                            total_quartos_reservados_standard += 1;};

                        if (cadastrados.ja_cadastrado_standard3 == 1){
                            total_quartos_reservados_standard += 1;};

                        if (cadastrados.ja_cadastrado_suite1 == 1){
                            total_quartos_reservados_suite += 1;};

                        if (cadastrados.ja_cadastrado_suite2 == 1){
                            total_quartos_reservados_suite += 1;};

                        if (cadastrados.ja_cadastrado_suite3 == 1){
                            total_quartos_reservados_suite += 1;};

                        total_quartos_reservados = total_quartos_reservados_luxo + total_quartos_reservados_standard + total_quartos_reservados_suite;

                        printf("Quantidade de Reservas no Quarto de Luxo: %d", total_quartos_reservados_luxo);
                        printf("\nQuantidade de Reservas no Quarto Suite: %d", total_quartos_reservados_suite);
                        printf("\nQuantidade de Reservas no Quarto Standard: %d", total_quartos_reservados_standard);

                        printf("\n\nQuantidade de Reservas totais: %d", total_quartos_reservados);

                        continuar = 1;
                    break;
                    default:
                        printf("Escolha inv�lida");
                        continuar = 1;
                };//aw fim

        break;
        case 6:
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


    printf("\n\nOs seus dados ent�o corretos?\nDigite [1] para sim \nDigite [2] para n�o");
    printf("\n\nNome: %s \nE-mail: %s \nG�nero: %s \nDocumento: %s \nTelefone: %s \nEmeg�ncia: %s \n\n", cads.nome, cads.email, cads.genero, cads.documento, cads.fone, cads.fone_emergencia);
    gets(cads.confirmacao);
    fflush(stdin);

    if(strcmp(cads.confirmacao, "1") == 0){

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
                printf("Cadastro finalizado com sucesso!");

                } else {
                    printf("Cadastro finalizado!");

                };
};
return;
}

