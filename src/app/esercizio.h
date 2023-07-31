#include "./tipi.h"

float calcolo_chiamate(float costo_minuto_compagnia, float minuti_telefonate, float scatto_risposta_gestore, int n_telefonate);
float calcolo_sms(float costo_sms_gestore, int n_sms);
float calcolo_dati(float costo_gb_gestore, float consumo_gb);
float calcolo_tot_costi(float costo_chiamate, float costo_sms, float costo_dati);
Vincitore trova_compagnia_migliore(float costo_tim, float costo_windtre, float costo_vodafone);
