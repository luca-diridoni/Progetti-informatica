## Descrizione
Il seguente è un gioco che ho sviluppato in terza superiore, al primo anno di programmazione, ma lasciato incompleto.
Si svolge su una mappa bidimensionale di caratteri ASCII, tutte le entità (eroe, orchi, oggetti, muri, ecc.) sono rappresentate da simboli testuali.
L'obbiettivo in questo roguelike 2D sarebbe quello di progredire nei livelli arrivando al tesoro.
Tutto il gioco si muove in maniera dipendente dal protagonista, ad ogni pressione di un tasto il personaggio compierà un'azione, e uguale ogni altra entità del gioco compierà una sola azione (che nel caso degli orchi è un movimento casuale all'interno di un determinato range).
##### Per test si consiglia di seguire "Obbiettivi livello 1"

## Istruzioni
Si devono evitare gli orchi che si muovono (hashtag) e progredire nella mappa, si possono raccogliere oggetti come chiavi ("F") con cui aprire porte ("/") passandoci sopra, e spade ("%") con cui uccidere orchi (usando wasd per direzionare il colpo in prossimità di essi, ha effetto solo se adiacenti al nemico).

## Zainetto e stati
In basso è visualizzabile il numero di vite rimasto e lo zainetto (tutti gli oggetti raccolti e utilizzabili).
Durante il gioco, possono apparire messaggi come:
- "Porta sbloccata"
- "Chiave ottenuta"
- "Spada ottenuta"
- "Porta bloccata"

## Obbiettivi livello 1
1. Raccogli la chiave (F) per aprire la porta (/).
2. Raccogli la spada (%) per poter uccidere gli orchi.
- Evita il contatto diretto con gli orchi, altrimenti perdi una vita (♥).
- Se le vite scendono a zero → Game Over.

## Tasti
| **Freccia ↑**     | Muovi l’eroe verso l’alto                                                      |

| **Freccia ↓**     | Muovi l’eroe verso il basso                                                    |

| **Freccia ←**     | Muovi l’eroe verso sinistra                                                    |

| **Freccia →**     | Muovi l’eroe verso destra                                                      |

| **W / A / S / D** | Attacca con la spada in quella direzione *(solo se la spada è nello zainetto)* |

| **Q**             | Esci dal gioco                                                                 |

## Elementi mappa
| `@`     | Eroe                                 | Controllato dal giocatore                          |                        |

| `#`     | Orco                                 | Si muove casualmente, toccarlo fa perdere una vita |                        |

| `       | `                                    | Muro                                               | Impedisce il movimento |

| `-`     | Pavimento                            | Impedisce l’accesso a certe aree                   |                        |

| `/`     | Porta                                | Può essere aperta solo con una chiave              |                        |

| `F`     | Chiave                               | Serve per aprire una porta                         |                        |

| `%`     | Spada                                | Serve per uccidere orchi                           |                        |

| `♥`     | Vita residua (visualizzata in basso) |                                                    |                        |

## Cose mancanti
Il gioco è stato lasciato incompleto, tra le idee vi era:
- nuovi livelli e mappe più ampie
- aggiunta di nuovi oggetti
  - arco (attacco a distanza)
  - pozione vita
  - pozione scudo
- "intelligenza artificiale" migliorata per i nemici
- salvataggio progressi
- effetti sonori e colori dinamici
- missioni secondarie/enigmi
