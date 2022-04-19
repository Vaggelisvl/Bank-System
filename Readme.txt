This is a banking system where there are actions for 2 different catogories of users:
Admins can:
-can add costumer on Bank System.
-reset costumer data.

Users can:
-reset their data.
-transfer money to another account.
In class user there is a function fixmargin where it make sure to print at least n-lengh of "-" of the max lenght of string it has to be printed

I implement a linked list for costumers where each node holds a Personal Detail value for each costumer where:
Personal Details class has values:
first name,last name,iban ,street,password username,tax indefication number

when i read the answer if the user want to continue with actions
i convert the answer to lower case so as to compare no matter the answer
is in Uppercase or lowercase

there is a password policy that:
It contains at least one uppercase letter.
It contains at least one lowercase letter.
It contains at least one digit.
It has at least one character which is neither a letter nor a number.
Its length must be more than 8 characters.

All the transactions , log in details and changes are saved in out.txt for security reasons