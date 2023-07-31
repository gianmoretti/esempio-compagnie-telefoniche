# Progetto

Questo è un esempio di programma C che computa la compagnia telefonica più conveniente

## Testo del problema

Con Vodafone 25 New le chiamate sono a 25 centesimi al minuto, con scatto alla risposta di 20 centesimi, SMS a 29 centesimi l'uno e 1,20 euro al giorno per ogni GB Internet consumato.

Con WIND3 la connessione dati viene tariffata a 0,99€ al giorno per 1 GB: tale costo viene addebitato solo in caso di effettivo utilizzo del traffico dati; WINDTRE Easy: chiamate a 30 cent/minuto, con uno scatto alla risposta di 20 cent, e sms a 30 cent l'uno.

TIM Base New : chiamate a 23 cent/minuto, con scatto alla risposta di 20 cent, 19 cent per sms e connessione Internet a 2€ al giorno per 500 MB.

Qual è la compagnia più conveniente dati i propri dati del traffico giornaliero?

## Svolgimento

### Ipotesi

- considero il tempo di chiamate in minuti, anche con numeri decimali
- considero il traffico dati che consuma l'utente espresso in MB,
- le costanti sono espresse in: cent/minuto, cent/sms, cent/GB
- considero che l'utente inserisca al massimo 2 cifre dopo la virgola
- ipotizzo che la durata di una chiamata sia maggiore di 0

### Analisi

#### Opzione 1

- Chiedo all'utente di scrivere i propri dati di traffico giornaliero nella forma: minuti totali di chiamate, numero chiamate, numeri di sms, MB di traffico
- Effettuo le conversioni, in modo da avere tutti i criteri con la stessa unità di misura
- Calcolo i vari costi, attraverso delle funzioni per ogni compagnia telefonica
- Comparo i vari costi, attraverso una funzione, in modo da trovare la compagnia più conveniente
- Restituisco in output la compagnia più conveniente con i costi per i vari servizi

### Opzione 2

- Chiedo all'utente di scrivere i propri dati di traffico giornaliero nella forma: minuti di chiamate, numeri di sms, MB di traffico
- Effettuo le conversioni, in modo da avere tutti i criteri con la stessa unità di misura
- Calcolo i vari costi, attraverso delle funzioni per topologia di traffico (rete, chiamate, sms)
- Comparo i vari costi, attraverso una funzione, in modo da trovare la compagnia più conveniente
- Restituisco in output la compagnia più conveniente con i costi per i vari servizi

### Formule

- Calcolo costo Chiamate

```
Calcolo_costo_Chiamate = (COSTO_MINUTO_GESTORE * minuti_telefonate) + (SCATTO_RISPOSTA_GESTORE*n_telefonate)
```

- Calcolo costo SMS

```
calcolo_costoSms = COSTO_SMS_GESTORE *n_sms
```

- Calcolo cambio MB -> GB

```
cambio_mb_gb: consumo_mb/1024;
```

- Calcolo costo dati

```
calcolo_costo_Dati: consumo_gb * COSTO_AL_GB
```

### Dati input

- minuti_telefonate (float) = durata in minuti delle chiamate effetuate (es 90 sec = 1.5 min)
- n_telefonate (float) = numero di telefonate che esegue l'utente
- n_sms (float) = numero di sms totali che invia l'utente
- consumo_mb (float) = consumo in MB che esegue l'utente al giorno

### Dati output

- migliore_compagnia (stringa) = compagnia più vantaggiosa

### Controllo input

- minuti_telefonate > 0
- n_telefonate > 0
- n_sms > 0
- consumo_MB > 0

### Variabili di supporto

???

### Costanti di supporto

- COSTO_MINUTO_GESTORE (float): costo al minuto per una telefonata
- SCATTO_RISPOSTA_GESTORE (float): costo dello scatto alla risposta
- COSTO_SMS_GESTORE (float): costo per 1 sms
- COSTO_AL_GB (float): costo al GB

### Test

???

## Come lanciare in locale

### Requisiti

- Installare un compilatore C
  Possibili guide: https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j

- Installare un IDE con compilatore C

### Avvio dei test

Dalla directory root di progetto, eseguire:

```
>  gcc ./src/lib/unity.c ./src/test/esercizioTest.c -o out/esercizioTest
> ./out/esercizioTest
```

### Avvio dell'applicazione

Dalla directory root di progetto, eseguire:

```
>  gcc ./src/app/esercizio.c ./src/app/main.c -o out/main
> ./out/main
```
