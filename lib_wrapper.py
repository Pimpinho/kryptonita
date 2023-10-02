import ctypes

# Carrega a biblioteca C
criptografia_rsa = ctypes.CDLL('./criptografia_rsa.so')

# Declare as funções da biblioteca C
gerar_dois_primos = criptografia_rsa.gerar_dois_primos
gerar_dois_primos.argtypes = [ctypes.c_int]
gerar_dois_primos.restype = ctypes.c_int

gerar_chave = criptografia_rsa.gerar_chave
gerar_chave.argtypes = [ctypes.c_int]
gerar_chave.restype = ctypes.c_int

encriptar = criptografia_rsa.encriptar
encriptar.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_int]
encriptar.restype = ctypes.c_char_p

desencriptar = criptografia_rsa.desencriptar
desencriptar.argtypes = [ctypes.c_int]
desencriptar.restype = ctypes.c_int