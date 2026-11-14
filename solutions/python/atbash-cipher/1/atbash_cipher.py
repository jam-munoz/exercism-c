def encode(plain_text):
    cipher = str.maketrans("abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba", " ,.")
    ciphertext = plain_text.lower().translate(cipher)
    return " ".join(ciphertext[i:i+5] for i in range(0, len(ciphertext), 5))
    
def decode(ciphered_text):
    deco = str.maketrans("zyxwvutsrqponmlkjihgfedcba", "abcdefghijklmnopqrstuvwxyz", " ")
    return ciphered_text.translate(deco)
