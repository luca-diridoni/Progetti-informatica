## Descrizione
Risolutore di Equazioni è un programma con interfaccia grafica (GUI) realizzato in Python che permette di calcolare le soluzioni di equazioni polinomiali di secondo, terzo e quarto grado.
Utilizza la libreria Tkinter per la parte grafica e NumPy per il calcolo delle radici.

## Funzionalità
1. Scelta del grado dell’equazione (2°, 3° o 4°) tramite menu a tendina.
2. Inserimento dinamico dei coefficienti in base al grado selezionato.
3. Controllo degli input per evitare errori (es. coefficienti non numerici o coefficiente principale nullo).
4. Calcolo automatico delle soluzioni reali e complesse.
5. Visualizzazione dei risultati in un riquadro testuale:
	Le soluzioni reali vengono mostrate in nero.
	Le soluzioni complesse vengono evidenziate in rosso.
	
## Utilizzo
1. Seleziona il grado dell’equazione dal menu a tendina.
2. Inserisci i coefficienti (ad esempio per un’equazione di secondo grado ax² + bx + c = 0 inserisci i valori di a, b, c).
3. Premi "Risolvi" per calcolare le soluzioni.
4. I risultati appariranno nel riquadro inferiore.

## Requisiti
Python 3.x
numpy, tkinter