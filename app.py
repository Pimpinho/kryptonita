import tkinter as tk
import os
import ctypes
from tkinter import StringVar, IntVar
from PIL import Image, ImageTk
from lib_wrapper import gerar_chave, encriptar, desencriptar

class KryptoApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Krypto App")
        self.master.geometry("700x450")  # Define o tamanho da janela principal para 700x450

        # Carregue a imagem do ícone
        icon_path = "icons/logo_k_semfundo.png"
        if os.path.exists(icon_path):
            icon = Image.open(icon_path)
            icon = icon.convert("RGBA")
            self.icon = ImageTk.PhotoImage(icon)

            # Defina o ícone da janela
            self.master.iconphoto(True, self.icon)

        self.create_main_frame()
        
    def create_main_frame(self):
        main_frame = tk.Frame(self.master, width=700, height=450)
        main_frame.pack()

        title_label = tk.Label(main_frame, text="Krypto App", font=("Inter", 28, "bold"), anchor="center", fg='black')
        title_label.place(x=146, y=37)

        button1 = self.create_button(main_frame, "Chave pública", self.show_generate_public_key_screen)
        button1.place(x=263, y=202, width=174, height=47)

        button2 = self.create_button(main_frame, "Encriptar", self.show_generate_encrypt_screen)
        button2.place(x=49, y=202, width=174, height=47)

        button3 = self.create_button(main_frame, "Desencriptar", self.show_generate_decrypt_screen)
        button3.place(x=477, y=202, width=174, height=47)

    def create_button(self, parent, text, command):
        return tk.Button(parent, text=text, command=command)

    def clear_screen(self):
        # Limpa os elementos da tela anterior
        for widget in self.master.winfo_children():
            widget.destroy()

    def show_initial_screen(self):
        self.clear_screen()
        self.master.title("Krypto App")
        self.create_main_frame()

    def show_generate_public_key_screen(self):
        self.clear_screen()
        self.master.title("Tela 1 - Gerar chave pública")

        title_label = tk.Label(self.master, text="Gerar chave pública", font=("Inter", 16, "bold"), fg="black")
        title_label.place(x=280, y=20)

        self.q_var = IntVar()
        self.p_var = IntVar()
        self.expoente_var = IntVar()

        self.create_input_field("Entre com o valor de q:", 100, 200, self.q_var)
        self.create_input_field("Entre com o valor de p:", 100, 260, self.p_var)
        self.create_input_field("Entre com o valor do expoente:", 100, 320, self.expoente_var)

        # Chame a função gerar_chave e obtenha o resultado
        button_save = self.create_button(self.master, "Salvar Dados", lambda: gerar_chave(self.q_var.get(), self.p_var.get(), self.expoente_var.get()))
        button_save.place(x=450, y=400)

        button_back = self.create_button(self.master, "Voltar à tela inicial", self.show_initial_screen)
        button_back.place(x=300, y=400)

    def create_input_field(self, label_text, x, y, text_variable):
        label = tk.Label(self.master, text=label_text, font=("Inter", 12, "bold"), fg="black")
        label.place(x=x, y=y)

        entry = tk.Entry(self.master, textvariable=text_variable)
        entry.place(x=x, y=y + 30)
    
    def string_to_array(self, text):
        text_arr = []
        for letra in text:
            text_arr.append(letra)
        return text_arr
        

    def show_generate_encrypt_screen(self):
        self.clear_screen()
        self.master.title("Tela 2 - Criptografar")

        title_label = tk.Label(self.master, text="Gerar criptografia", font=("Inter", 16, "bold"), fg="black")
        title_label.place(x=280, y=20)

        self.texto = StringVar()
        self.expoente_var = IntVar()
        self.n_var = IntVar()

        self.create_input_field("Entre com o texto:", 100, 200, self.texto)
        self.create_input_field("Entre com o valor do expoente:", 100, 260, self.expoente_var)
        self.create_input_field("Entre com o valor do n:", 100, 320, self.n_var)

        def save_data():
            texto_inserido = self.texto.get()
            texto_c_char_p = ctypes.c_char_p(texto_inserido.encode())
            encriptar(texto_c_char_p, self.expoente_var.get(), self.n_var.get())

        button_save = self.create_button(self.master, "Salvar Dados", save_data)
        button_save.place(x=450, y=400)
        button_back = self.create_button(self.master, "Voltar à tela inicial", self.show_initial_screen)
        button_back.place(x=300, y=400)

    def show_generate_decrypt_screen(self):
        self.clear_screen()
        self.master.title("Tela 3 - Decriptografar")

        title_label = tk.Label(self.master, text="Desencriptar", font=("Inter", 16, "bold"), fg="black")
        title_label.place(x=280, y=20)

        self.q_var = IntVar()
        self.p_var = IntVar()
        self.expoente_var = IntVar()

        self.create_input_field("Entre com o valor de q:", 100, 200, self.q_var)
        self.create_input_field("Entre com o valor de p:", 100, 260, self.p_var)
        self.create_input_field("Entre com o valor do expoente:", 100, 320, self.expoente_var)

        button_save = self.create_button(self.master, "Salvar Dados", lambda: desencriptar(self.q_var.get(), self.p_var.get(), self.expoente_var.get()))
        button_save.place(x=450, y=400)
        button_back = self.create_button(self.master, "Voltar à tela inicial", self.show_initial_screen)
        button_back.place(x=300, y=400)

if __name__ == "__main__":
    root = tk.Tk()
    app = KryptoApp(root)
    root.mainloop()
