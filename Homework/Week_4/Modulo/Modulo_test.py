import os
import math
from random import randint

def Solve(t, a, b, c):
    if t == 1: return (a * b) % c
    elif t == 2:
        if b > c:
            b, c = c, b
        d = a // math.lcm(b, c)
        if a % b == a % c: 
            res = d * b + a % b
        else: 
            res = d * b + b - 1
        
        return res

def main():
    for i in range(40):
        dir_name = "Testcase/Test_"+str(i+1)
        os.mkdir(dir_name)
        
        inp = open(os.path.join(dir_name, "modulo.inp"), "w")
        out = open(os.path.join(dir_name, "modulo.out"), "w")

        inp_data = []
        out_data = []
        if i < 8:
            q = randint(1,10**5)
            if i < 3:
                q = 10**5
            for j in range(q):
                a,b,c = 0,0,0
                a = randint(1, 10**9)
                b = randint(1, 10**9)
                c = randint(1, 10**9)
                
                inp_data.append(["1",str(a),str(b),str(c)])
                out_data.append(Solve(1, a, b, c))
        elif i < 16:
            q = randint(1,10**3)
            if i < 10:
                q = 10**3
            for j in range(q):
                a = randint(1, 10**4)
                b = randint(1, min(a, 10**2))
                c = randint(1, min(a, 10**2))

                inp_data.append(["2",str(a),str(b),str(c)])
                out_data.append(Solve(2, a, b, c))
        elif i < 24:
            q = randint(1,10**5)
            if i < 20:
                q = 10**5
            for j in range(q):
                select = randint(1,2)
                a = randint(1, 10**9)
                b = randint(1, min(a, 10**5))
                c = randint(1, min(a, 10**5))

                inp_data.append([str(select),str(a),str(b),str(c)])
                out_data.append(Solve(select, a, b, c))
        else:
            q = randint(1,10**5)
            if i < 30:
                q = 10**5
            for j in range(q):
                select = randint(1,2)
                a = randint(1, 10**18)
                b = randint(1, min(a, 10**12))
                c = randint(1, min(a, 10**12))

                inp_data.append([str(select),str(a),str(b),str(c)])
                out_data.append(Solve(select, a, b, c))

        inp.write(str(q)+"\n")
        for j in range(q):
            input_data = ""
            for k in inp_data[j]:
                input_data += k + " "
            inp.write(input_data + "\n")
            out.write(str(out_data[j]) + "\n")
        print("Test_" + str(i+1) + " has created.")
        inp.close()
        out.close()

if __name__ == "__main__":
    main()