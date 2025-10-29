import tkinter as tk
from tkinter import ttk, messagebox
import numpy as np

class EquationSolver(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Risolutore di equazioni")
        self.geometry("500x400")
        
        # Selezione del grado dell'equazione
        self.degree_var = tk.StringVar(value="2")
        degree_label = tk.Label(self, text="Seleziona il grado dell'equazione:")
        degree_label.pack(pady=5)
        
        degree_combo = ttk.Combobox(self, textvariable=self.degree_var, values=["2", "3", "4"], state="readonly")
        degree_combo.pack(pady=5)
        degree_combo.bind("<<ComboboxSelected>>", self.update_inputs)
        
        # Frame per l'inserimento dei coefficienti
        self.coeff_frame = tk.Frame(self)
        self.coeff_frame.pack(pady=10)
        self.entries = []
        self.create_coeff_inputs(2)  # Impostazione iniziale per equazione di 2° grado
        
        # Bottone per risolvere l'equazione
        solve_button = tk.Button(self, text="Risolvi", command=self.solve)
        solve_button.pack(pady=10)
        
        # Area di testo per visualizzare le soluzioni
        self.result_text = tk.Text(self, height=10, width=50)
        self.result_text.pack(pady=10)

    def create_coeff_inputs(self, degree):
        """Crea dinamicamente gli input per i coefficienti in base al grado scelto."""
        for widget in self.coeff_frame.winfo_children():
            widget.destroy()
        self.entries = []
        # Per un'equazione in forma ax^n + bx^(n-1) + ... + c = 0
        for i in range(degree + 1):
            if i < degree:
                label_text = f"coefficiente per x^{degree - i}:"
            else:
                label_text = "coefficiente costante:"
            coeff_label = tk.Label(self.coeff_frame, text=label_text)
            coeff_label.grid(row=i, column=0, padx=5, pady=5, sticky="e")
            entry = tk.Entry(self.coeff_frame, width=10)
            entry.grid(row=i, column=1, padx=5, pady=5)
            self.entries.append(entry)

    def update_inputs(self, event):
        """Aggiorna dinamicamente gli input per i coefficienti quando viene cambiato il grado."""
        try:
            deg = int(self.degree_var.get())
            self.create_coeff_inputs(deg)
        except ValueError:
            messagebox.showerror("Errore", "Grado non valido.")

    def solve(self):
        """Legge i coefficienti, calcola e mostra le soluzioni dell'equazione."""
        try:
            deg = int(self.degree_var.get())
        except ValueError:
            messagebox.showerror("Errore", "Grado non valido.")
            return
        
        coeffs = []
        for entry in self.entries:
            try:
                coeff = float(entry.get())
                coeffs.append(coeff)
            except ValueError:
                messagebox.showerror("Errore", "Inserire solo numeri validi per i coefficienti.")
                return
        
        # Il coefficiente principale non può essere zero
        if coeffs[0] == 0:
            messagebox.showerror("Errore", "Il coefficiente principale non può essere zero.")
            return
        
        # Calcolo delle radici usando numpy.roots (richiede i coefficienti in ordine decrescente)
        roots = np.roots(coeffs)
        
        # Visualizzazione dei risultati
        self.result_text.delete("1.0", tk.END)
        self.result_text.insert(tk.END, "Soluzioni:\n")
        tol = 1e-10  # tolleranza per considerare una parte immaginaria nulla
        for i, r in enumerate(roots, start=1):
            if abs(r.imag) < tol:
                self.result_text.insert(tk.END, f"{i}: [{r.real:.5f}]\n")
            else:
                start_index = self.result_text.index(tk.END)
                segno = '+' if r.imag >= 0 else '-'
                solution = f"{i}: [{r.real:.5f} {segno} {abs(r.imag):.5f}i]\n"
                self.result_text.insert(tk.END, solution)
                self.result_text.tag_add("complesso", start_index, tk.END)
        self.result_text.tag_config("complesso", foreground="red")

if __name__ == "__main__":
    app = EquationSolver()
    app.mainloop()
