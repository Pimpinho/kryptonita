import tkinter as tk

class App:
    def __init__(self, master):
        self.master = master
        self.master.title("Meu Aplicativo")
        self.master.geometry("600x600")  # Define o tamanho da janela principal para 600x600
        self.init_ui()

    def init_ui(self):
        # Crie um frame para conter os botões e centralizá-los
        button_frame = tk.Frame(self.master)
        button_frame.pack(expand=True, fill=tk.BOTH)

        # Configure o frame para centralizar os widgets horizontalmente e adicionar espaçamento
        button_frame.grid_rowconfigure(0, weight=1)
        button_frame.grid_columnconfigure(0, weight=1)
        button_frame.grid_columnconfigure(1, weight=1)
        button_frame.grid_columnconfigure(2, weight=1)

        self.button1 = tk.Button(button_frame, text="Tela 1", command=lambda: self.show_screen("Tela 1", "Criptografar"))
        self.button1.grid(row=0, column=0, padx=10, pady=10)

        self.button2 = tk.Button(button_frame, text="Tela 2", command=lambda: self.show_screen("Tela 2", "Gerar chave pública"))
        self.button2.grid(row=0, column=1, padx=10, pady=10)

        self.button3 = tk.Button(button_frame, text="Tela 3", command=lambda: self.show_screen("Tela 3", "Decriptografar"))
        self.button3.grid(row=0, column=2, padx=10, pady=10)

    def show_screen(self, screen_title, screen_label):
        # Limpa a tela anterior (se houver) antes de exibir a nova tela
        self.clear_screen()

        # Configura o título da janela
        self.master.title(screen_title)

        # Cria e exibe os elementos da nova tela
        self.label = tk.Label(self.master, text=screen_label)
        self.label.pack()

        # Adicione aqui quaisquer outros elementos que você deseja na tela

        # Adicione um botão "Voltar à tela inicial"
        self.button_back = tk.Button(self.master, text="Voltar à tela inicial", command=self.show_initial_screen)
        self.button_back.pack()

    def clear_screen(self):
        # Limpa os elementos da tela anterior
        for widget in self.master.winfo_children():
            widget.destroy()

    def show_initial_screen(self):
        # Função para voltar à tela inicial
        self.clear_screen()
        self.master.title("Meu Aplicativo")  # Restaura o título original
        self.init_ui()  # Recria os botões iniciais

root = tk.Tk()
app = App(root)
root.mainloop()
