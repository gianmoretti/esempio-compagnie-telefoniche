#include "./tipi.h"

float calcolo_chiamate(float costo_minuto_compagnia, float minuti_telefonate, float scatto_risposta_gestore, int n_telefonate)
{
    return (costo_minuto_compagnia * minuti_telefonate) + (scatto_risposta_gestore * n_telefonate);
}

float calcolo_sms(float costo_sms_gestore, int n_sms)
{
    return costo_sms_gestore * n_sms;
}

float calcolo_dati(float costo_gb_gestore, float consumo_gb)
{
    return costo_gb_gestore * consumo_gb;
}

float calcolo_tot_costi(float costo_chiamate, float costo_sms, float costo_dati)
{
    return costo_chiamate + costo_sms + costo_dati;
}

Vincitore trova_compagnia_migliore(float tot_tim, float tot_windtre, float tot_vodafone)
{
    if (tot_tim < tot_vodafone && tot_tim < tot_windtre)
    {
        return (Vincitore){
            .compagnia_vincitrice = "Tim",
            .costo_totale = tot_tim,
        };
    }
    else if (tot_windtre < tot_vodafone)
    {
        return (Vincitore){
            .compagnia_vincitrice = "WindTre",
            .costo_totale = tot_windtre,
        };
    }
    else
        return (Vincitore){
            .compagnia_vincitrice = "Vodafone",
            .costo_totale = tot_vodafone,
        };
}
