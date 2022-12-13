# Arduino-RGB-LED

Gestione semplice dei LED RGB per Arduino.

Autore: **Daniele Rossi**

Versione: **1.1.0 (13-Dic-2022)**

## Descrizione

La libreria prevede la gestione semplificata dei LED RGB sfruttando le uscite digitali senza modulazione PWM.
In questa modalità, i coli hanno profondità di 3 bit (ovvero 8 colori disponibili).

## Costruttore di Classe

> `RgbLed(rgb_led_t led_pin, led_driver_t led_driver_mode);`





## Definizioni

### `rgb_led_t`

Tipo struttura che contiene i numeri dei pin relativi ai canali rosso (R), verde (G) e blu (B) del LED:

```cpp
typedef struct {
    int r_led;
    int g_led;
    int b_led;
} rgb_led_t;
```

### `led_driver_t`

Tipo booleano che indica come viene comandato il LED:

```cpp
typedef enum {
    LS_DRIVER = 0,      // Low-Side Driver
    HS_DRIVER = 1       // High-Side Driver
} led_driver_t;
```

### `c8_color_t`

Tipo numerico che specifica i colori disponibili:

```cpp
typedef enum {
    C8_BLACK = 0,
    C8_RED,
    C8_GREEN,
    C8_YELLOW,
    C8_BLUE,
    C8_FUCHSIA,
    C8_CYAN,
    C8_WHITE,
} c8_color_t;
```

## Metodi

### `setColor(c8_color_t color)`

Imposta il LED con il colore `color`.
Per spegnere il LED, utilizzare il colore `C8_BLACK`.

### `setBlink(c8_color_t color1, c8_color_t color2, unsigned long time1, unsigned long time2)`

Imposta il lampeggio del LED su due colori: ciclicamente il LED si accende con il colore `color1` per la durata `time1` e
successivamente si accende con il colore `color2` per la durata `time2`.
Se si vuole un lampeggio su singolo colore, impostare uno dei due colori come `C8_BLACK`.
Questo metodo imposta solamente i colori e i timer, per eseguire il lampeggio va inserito il metodo `loop` all'interno del loop di esecuzione del programma.

### `loop(void)`

Gestisce il lampeggio del LED. I colori e i timer vanno impostati con il metodo `setBlink`.

## Cronologia Versioni

- `1.0.0` (13-Ott-2022) - Versione iniziale
- `1.1.0` (13-Dic-2022) - Aggiunti i metodi per il lampeggio