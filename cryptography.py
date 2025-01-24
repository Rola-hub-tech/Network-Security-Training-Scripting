## Program to encrypt a file ##
from cryptography.fernet import Fernet

# key = Fernet.generate_key()
# with open("fileKey.key", 'wb') as filekey:
#     filekey.write(key)
with open('filekey.key', 'rb') as filekey:
    key = filekey.read()
fernet = Fernet(key)

## file encryption ##
# with open(r"D:\secret.txt", "rb") as file:
#     original = file.read()
# encrypted = fernet.encrypt(original)
# with open(r"D:\secret.txt", "wb") as encryptedFile:
#     encryptedFile.write(encrypted)

## file decryption
with open(r"D:\secret.txt", "rb") as encryptedFile:
    encrypted = encryptedFile.read()

decrypted = fernet.decrypt(encrypted)
with open("D:\secret.txt", "wb") as decryptedFile:
    decryptedFile.write(decrypted)