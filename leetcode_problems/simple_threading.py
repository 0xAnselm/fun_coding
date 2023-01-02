import threading
import time

a = 0

class myThread(threading.Thread):
    def __init__(self, iD, name):
        threading.Thread.__init__(self)
        self.iD = iD
        self.name = name

    def run(self):
        print("Start", self.iD, self.name)
        for i in range(10):
            self.inc()
            self.dec()
            time.sleep(1)
            print(a)
        
    def inc(self):
        global a
        if self.iD == 2:
            a += 1
    
    def dec(self):
        global a
        if self.iD == 1:
            a -= 1
def main():
    t1 = myThread(1, "dec")
    t2 = myThread(2, "inc")
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print("a is", a)

if __name__ == "__main__":
    main()