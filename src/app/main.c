/*
    Name:
    Copyright:
    Author: Fontana Andrea 3ia
    Date: 10/07/23 18:24
*/

#include <stdio.h>
#include "./costanti.h"
#include "./esercizio.h"

void print_output(char compagnia[30], float costo_chiamate, float costo_sms, float costo_dati, float costo_totale)
{
    printf("Tariffa comapgnia \"%s\": \n", compagnia);
    printf(" - chiamate = %f\n", costo_chiamate);
    printf(" - sms = %f\n", costo_sms);
    printf(" - dati = %f\n", costo_dati);
    printf(" - totale = %f\n", costo_totale);
}

int main()
{
    float minuti_telefonate, consumo_gb;
    int n_telefonate, n_sms;

    float costo_chiamate_tim, costo_sms_tim, costo_dati_tim;
    float costo_chiamate_vodafone, costo_sms_vodafone, costo_dati_vodafone;
    float costo_chiamate_windtre, costo_sms_windtre, costo_dati_windtre;

    float tot_tim, tot_windtre, tot_vodafone;

    // RACCOLTA INPUT
    do
    {
        printf("Quanti minuti stai in chiamata? (possibilità di utilizzare anche le cifre decimali)\n");
        scanf("%f", &minuti_telefonate);
    } while (minuti_telefonate < 0);

    do
    {
        printf("Quante telefonate fai al giorno?\n");
        scanf("%d", &n_telefonate);
    } while (n_telefonate < 0);

    do
    {
        printf("Quanti messaggi invii al giorno?\n");
        scanf("%d", &n_sms);
    } while (n_sms < 0);

    do
    {
        printf("quanti GB consumi al giorno?\n");
        scanf("%f", &consumo_gb);
    } while (consumo_gb < 0);

    // ALGORITMO
    printf("\n\n**********************\n\n");
    printf("\n\n   CALCOLO TARIFFA\n\n");
    printf("\n\n**********************\n\n");

    // - TIM
    costo_chiamate_tim = calcolo_chiamate(COSTO_MINUTO_TIM, minuti_telefonate, COSTO_RISPOSTA_TIM, n_telefonate);
    costo_sms_tim = calcolo_sms(COSTO_SMS_TIM, n_sms);
    costo_dati_tim = calcolo_dati(COSTO_GB_TIM, consumo_gb);
    tot_tim = calcolo_tot_costi(costo_chiamate_tim, costo_sms_tim, costo_dati_tim);
    print_output("Tim", costo_chiamate_tim, costo_sms_tim, costo_dati_tim, tot_tim);

    // - WINDTRE
    costo_chiamate_windtre = calcolo_chiamate(COSTO_MINUTO_WINDTRE, minuti_telefonate, COSTO_RISPOSTA_WINDTRE, n_telefonate);
    costo_sms_windtre = calcolo_sms(COSTO_SMS_WINDTRE, n_sms);
    costo_dati_windtre = calcolo_dati(COSTO_GB_WINDTRE, consumo_gb);
    tot_windtre = calcolo_tot_costi(costo_chiamate_windtre, costo_sms_windtre, costo_dati_windtre);
    print_output("WindTre", costo_chiamate_windtre, costo_sms_windtre, costo_dati_windtre, tot_windtre);

    // - VODAFONE
    costo_chiamate_vodafone = calcolo_chiamate(COSTO_MINUTO_VODAFONE, minuti_telefonate, COSTO_RISPOSTA_VODAFONE, n_telefonate);
    costo_sms_vodafone = calcolo_sms(COSTO_SMS_VODAFONE, n_sms);
    costo_dati_vodafone = calcolo_dati(COSTO_GB_VODAFONE, consumo_gb);
    tot_vodafone = calcolo_tot_costi(costo_chiamate_vodafone, costo_sms_vodafone, costo_dati_vodafone);
    print_output("Vodafone", costo_chiamate_vodafone, costo_sms_vodafone, costo_dati_vodafone, tot_vodafone);

    // OUTPUT
    Vincitore compagnia_vincitrice = trova_compagnia_migliore(tot_tim, tot_windtre, tot_vodafone);
    printf("%s e' la compagnia migliore con un costo giornaliero di %.2f euro", compagnia_vincitrice.compagnia_vincitrice, compagnia_vincitrice.costo_totale);
}