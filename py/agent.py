import paramiko
import os
import sys
import cred


try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()


def remote_tc(rel):
#rel = "[N] -> { [i, j, k, m, _v1 = 14] -> [i', j', i, j, _v2 = 14] : k > i and k < m < j and 0 <= i' < i and j < j' < N; [i, j, k, m, _v1 = 14] -> [i' = i, j' = j, o2, o3, _v2 = 14] : i >= 0 and j < N and k > i and k < m < j and o2 > k and o2 < o3 < j; [i, j, k, m, _v1 = 14] -> [i', j' = i + j - i', 0, 0, _v2] : k > i and k < m < j and i' >= 0 and -N + i + j < i' <= i and 23 <= _v2 <= 24 - i + i'; [i, j, k, m = 0, _v1 = 20] -> [i', j', 0, 0, _v2 = 24] : i < k <= -3 + j and 0 <= i' <= i and j <= j' <= 1 - i + j + i' and j' < N; [i, j, k, m, _v1 = 14] -> [i' = i, j' = j, o2, 0, _v2 = 17] : i >= 0 and j < N and k > i and k < m < j and k <= o2 <= -4 + j; [i, j, k, m = 0, _v1 = 17] -> [i', j', i, j, _v2 = 14] : i < k <= -4 + j and 0 <= i' < i and j < j' < N; [i, j, k, m = 0, _v1 = 17] -> [i' = i, j' = j, o2, o3, _v2 = 14] : i >= 0 and j < N and i < k <= -4 + j and o2 > k and o2 < o3 < j; [i, j, k, m, _v1 = 14] -> [i' = i, j' = j, k, o3, _v2 = 14] : i >= 0 and j < N and k > i and m > k and m < o3 < j; [i, j, k = 0, m = 0, _v1] -> [i', j', 0, 0, _v2 = 1 - i + _v1 + i'] : j > i and i' >= 0 and 24 - N + i + j - _v1 <= i' <= 23 + i - _v1 and 23 + i + j - _v1 - i' <= j' <= 24 + j - _v1 and j' <= i + j - i'; [i, j, k, m = 0, _v1 = 17] -> [i', j' = i + j - i', 0, 0, _v2] : i < k <= -4 + j and i' >= 0 and -N + i + j < i' <= i and 23 <= _v2 <= 24 - i + i'; [i, j, k, m = 0, _v1 = 20] -> [i' = i, j', j, 0, _v2 = 20] : i >= 0 and i < k <= -3 + j and 3 + j <= j' < N; [i, j, k, m = 0, _v1 = 20] -> [i' = i, j' = j, o2, 0, _v2 = 20] : i >= 0 and j < N and k > i and k < o2 <= -3 + j; [i, j, k, m = 0, _v1 = 20] -> [i', j' = j, -1 + i, 0, _v2 = 20] : j < N and i < k <= -3 + j and 0 <= i' <= -2 + i; [i, j, k, m = 0, _v1 = 20] -> [i' = -1 + i, j', j, 0, _v2 = 17] : i > 0 and i < k <= -3 + j and 4 + j <= j' < N; [i, j, k, m = 0, _v1 = 17] -> [i' = i, j' = j, o2, 0, _v2 = 17] : i >= 0 and j < N and k > i and k < o2 <= -4 + j; [i, j, k, m = 0, _v1 = 20] -> [i', j' = 1 + j, -1 + i, 0, _v2 = 17] : j <= -2 + N and i < k <= -3 + j and 0 <= i' <= -2 + i; [i, j, k = 0, m = 0, _v1 = 23] -> [i', j', i, j, _v2 = 14] : j > i and 0 <= i' < i and j < j' < N; [i, j, k = 0, m = 0, _v1 = 24] -> [i' = i, j', j, 0, _v2 = 20] : i >= 0 and j > i and 3 + j <= j' < N; [i, j, k = 0, m = 0, _v1 = 24] -> [i', j' = j, -1 + i, 0, _v2 = 20] : 2 + i <= j < N and 0 <= i' <= -2 + i; [i, j, k = 0, m = 0, _v1 = 24] -> [i' = -1 + i, j', j, 0, _v2 = 17] : i > 0 and j > i and 4 + j <= j' < N; [i, j, k = 0, m = 0, _v1 = 24] -> [i', j' = 1 + j, -1 + i, 0, _v2 = 17] : 2 + i <= j <= -2 + N and 0 <= i' <= -2 + i; [i, j, k = 0, m = 0, _v1 = 24] -> [i' = i, j' = 1 + j, 0, 0, _v2 = 24] : i >= 0 and i < j <= -2 + N };"
#isl.Map(rel)

    text_file = open('tmp/_rel.txt', 'w')
    text_file.write('R := ' + str(rel) + ';R^+;')
    text_file.close()

    privatekeyfile = os.path.expanduser(cred.cred_keyfile)
    mykey = paramiko.RSAKey.from_private_key_file(privatekeyfile)

    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

    ssh.connect(cred.cred_host, username=cred.cred_user, pkey = mykey)

    ftp = ssh.open_sftp()
    ftp.put('tmp/_rel.txt', '_rel.txt')
    ftp.close()

    stdin, stdout, stderr = ssh.exec_command("barvinok/iscc < _rel.txt")

    wynik = stdout.readlines()[0]

    sep = ', False)'
    exact = False
    if(sep not in wynik):
        sep = ', True)'
        exact = True


    wynik = wynik.split(sep)

    relp = wynik[0][1:]

    relp = isl.Map(relp)

    ssh.close()

    return relp, exact