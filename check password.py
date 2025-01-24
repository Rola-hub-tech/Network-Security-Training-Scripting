# Check password strength ##
import re

password = str(input("Enter your password to check its strength: "))
length = False
digits = False
upper = False
lower = False
specialChar = False

if re.search("[0-9]", password):
    digits = True

if re.search("[A-Z]", password):
    upper = True

if re.search("[a-z]", password):
    lower = True

if re.search("[!,@,#,$,%,^,&,*,(),_,+,-,|,\\,?,/,>,<]", password):
    specialChar = True

if len(password) > 8:
    length = True
#
# for char in range(len(password)):
#     if password[char].isdigit():
#         digits = True
#     elif password[char].isupper():
#         upper = True
#     elif password[char].islower():
#         lower = True
#     else:
#         specialChar = True
#
if length == False:
    print("The password should contain at least 8 characters")
if digits == False:
    print("The password should contain at least 1 digit")
if upper == False:
    print("The password should contain at least 1 uppercase character")
if lower == False:
    print("The password should contain at least 1 lowercase character")
if specialChar == False:
    print("The password should contain at least 1 special character")

if(length == False or digits == False or upper == False or lower == False or specialChar == False):
    print("Your password is weak")
else:
    print("Your password is strong")

exit()