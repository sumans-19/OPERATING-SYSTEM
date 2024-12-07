This code demonstrates the use of thread synchronization with Python's threading module. Specifically,
it uses a condition variable (Condition) to coordinate the execution of two threads (t1 and t2).


CODE =>
from threading import*
import time

cond = Condition()
done = 1

def task(name):
    global done
    with cond:
        if done == 1:
            done = 2
            print("waiting an condition variable cand :" , name)
            cond.wait()
            print("condition variable met : ", name)
        
        else:
            for i in range(10):
                print(".")
                time.sleep(1)
            print("signaling conditional variable cond " , name)
            cond.notify_all()
            print("Notification done",name)


if __name__ == '__main__':
    t1 = Thread(target=task, args=("t1",))
    t2 = Thread(target=task, args=("t2",))

    t1.start()
    t2.start()
    t1.join()
    t2.join()


