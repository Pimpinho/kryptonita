import ctypes

# Carrega a biblioteca C
criptografia_rsa = ctypes.CDLL('./criptografia_rsa.so')

# Declare as funções da biblioteca C
criptografia_rsa.gerar_chave()
criptografia_rsa.encriptar()
criptografia_rsa.desencriptar()