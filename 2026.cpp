v = list ()
w = list ()

def f (item, disp) :
    if (item == n or disp == 0) : return 0

    if (dp[item][disp] != -1) : return dp[item][disp]

    if (disp >= int (w[item])) : dp[item][disp] = max (int (v[item]) + f (item + 1, disp - int (w[item])), f (item + 1, disp))
    else : dp[item][disp] = f (item + 1, disp)

    return dp[item][disp]

K = 1

t = int (input ())

for j in range (0, t) :

    n = int (input ())
    m = int (input ())

    for i in range (0, n) :
        str = input ().split (' ')
        v.append (str[0])
        w.append (str[1])

    dp = [-1] * (n + 10)
    for i in range(0, n + 10): dp[i] = [-1] * (m + 10)

    print ("Galho %d:" % (K))
    print ("Numero total de enfeites:", f (0, m))

    v.clear ()
    w.clear ()
    K += 1
    print ("")
