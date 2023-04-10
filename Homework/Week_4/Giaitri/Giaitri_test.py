import os
import random

def main():
    for i in range(20):
        
        dir_name = "Testcase/Test_" + str(i+1)
        os.mkdir(dir_name)

        inp = open(os.path.join(dir_name,"giaitri.inp"), "w")
        out = open(os.path.join(dir_name,"giaitri.out"), "w")
        if i == 0:
            t = 1
            inp.write(str(t)+"\n")

            a = 1000
            b = 1000
            ans = a**b + b**a
            inp.write(str(a)+" "+str(b)+"\n")
            out.write(str(ans)+"\n")
        else:
            t = random.randint(1,200)
            if i <= 5:
                t = 200
            inp.write(str(t)+"\n")

            for j in range(t):
                a = random.randint(1,1000)
                b = random.randint(1,1000)
                ans = a**b + b**a
                inp.write(str(a)+" "+str(b)+"\n")
                out.write(str(ans)+"\n")
            
        print("Test_" + str(i) + " has created.")
        inp.close()
        out.close()

if __name__ == '__main__':
	main()