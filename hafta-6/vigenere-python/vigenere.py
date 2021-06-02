# kütüphaneleri çağır
import sys
from cs50 import get_string
# İçeriye alınan girdideki tüm karakterlerin
# alfabetik olup olmadığını kontrol eder
def is_valid(k):
    for ch in k:
        if not ch.isalpha():
            return False
    return True

def main():
    # Programın doğru çalıştırıldığını kontrol eder
    # yanlış çalıştıırldıysa doğrusunu gösterir
    if len(sys.argv) != 2 or not is_valid(sys.argv[1]):
        print("Usage: ./vigenere key")
        sys.exit(1)
    # argümanı değişken olarak alır ve
    # kullanıcıdan input(girdi) alır
    k = sys.argv[1]
    plaintext = get_string("plaintext: ")
    j = 0
    #şifrelenmiş mesajı yazmaya başla
    print("ciphertext: ", end="")
    # yazıdaki her bir karakter için tekrarla
    for ch in plaintext:
        #alfabetik karakter değilse değişim yapmadan ekle
        if not ch.isalpha():
            print(ch, end="")
            continue
        # ascii öteleme değeri karakter büyük harf ise 65, değil ise 97
        ascii_offset = 65 if ch.isupper() else 97
        # ord() fonksiyonu bir char(karakter) değeri alır ve ascii(integer) değerini geri döndürür
        # chr() fonksiyonu bir ascii değeri(integer olarak) alır ve char değerini döndürür
        pi = ord(ch) - ascii_offset
        kj = ord(k[j % len(k)].upper()) - 65
        ci = (pi + kj) % 26
        j += 1
        print(chr(ci + ascii_offset), end="")
    print()
    return 0

main()
