#include "../lib/unity.h"
#include "../app/esercizio.c"

void setUp()
{
}

void tearDown()
{
}

void calcolo_chiamate_caso_numeri_decimali()
{
    // Parametri
    // - float costo_minuto_compagnia
    // - float minuti_telefonate
    // - float scatto_risposta_gestore
    // - int n_telefonate
    TEST_ASSERT_EQUAL_FLOAT(178.42, calcolo_chiamate(10.1, 15.2, 8.3, 3));
    // Prima parte a zero
    TEST_ASSERT_EQUAL_FLOAT(24.9, calcolo_chiamate(10.1, 0, 8.3, 3));
    TEST_ASSERT_EQUAL_FLOAT(24.9, calcolo_chiamate(0, 15.2, 8.3, 3));
    // Seconda parte a zero
    TEST_ASSERT_EQUAL_FLOAT(153.52, calcolo_chiamate(10.1, 15.2, 0, 3));
    TEST_ASSERT_EQUAL_FLOAT(153.52, calcolo_chiamate(10.1, 15.2, 8.3, 0));
    // Entrambe le parti a zero
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_chiamate(0, 0, 0, 0));
}

void calcolo_sms_numeri_decimali()
{
    // Parametri
    // - float costo_sms_gestore
    // - int n_sms
    TEST_ASSERT_EQUAL_FLOAT(151.5, calcolo_sms(10.1, 15));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_sms(0, 15));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_sms(10.1, 0));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_sms(0, 0));
}

void calcolo_dati_numeri_decimali()
{
    // Parametri
    // - float costo_gb_gestore
    // - float consumo_gb
    TEST_ASSERT_EQUAL_FLOAT(152.51, calcolo_dati(10.1, 15.1));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_dati(0, 15.1));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_dati(10.1, 0));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_dati(.0, 0));
}

void calcolo_tot_costi_numeri_decimali()
{
    // Parametri
    // - float costo_chiamate
    // - float costo_sms
    // - float costo_dati
    TEST_ASSERT_EQUAL_FLOAT(60.6, calcolo_tot_costi(10.1, 20.2, 30.3));
    TEST_ASSERT_EQUAL_FLOAT(50.5, calcolo_tot_costi(0, 20.2, 30.3));
    TEST_ASSERT_EQUAL_FLOAT(40.4, calcolo_tot_costi(10.1, 0, 30.3));
    TEST_ASSERT_EQUAL_FLOAT(0, calcolo_tot_costi(0, 0, 0));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(calcolo_chiamate_caso_numeri_decimali);
    RUN_TEST(calcolo_sms_numeri_decimali);
    RUN_TEST(calcolo_dati_numeri_decimali);
    RUN_TEST(calcolo_tot_costi_numeri_decimali);
    UNITY_END();
}