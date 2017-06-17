load "openssllib.ring"

salt =  randbytes(32)
password = "SecretPassWord@$%123"
see salt + nl
see sha256("test" + salt) + nl
