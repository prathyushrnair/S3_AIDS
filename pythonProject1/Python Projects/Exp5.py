import re
pattern=r'^[a-zA-Z0-9.&+-%]+@[a-zA-z0-9]+[a-zA-Z]{2,}$'
email=input("Enter your Email: ")
if re.match(email,pattern):
    #match successfull
    print("Match Successfull\n Email is verified \n")
else:
    print("Email Verification Failed\nTry again")

