#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include<windows.h>
#include <mutex>
#include <condition_variable>

using namespace std;

int n; // buffer size
queue<int>q; // buffer
thread th[100];
mutex pm, m1, m2; // mutex for printing

struct node
{
    int id,data,opt;
};// for data input

vector<node>vc; // store data input here

class Semaphore {
public:
    Semaphore():
    cnt(1)
    ,fullCnt(0)
    ,emptCnt(n)
    {
        //Constructor
        //cout << "EMPTY COUNT: " << emptCnt << " FULL: " << fullCnt << endl;
    }

    inline void notify( int tid ) {
        unique_lock<mutex> lock(mtx);
        cnt++;
        cv.notify_one(); // notify condition variable
    }

    inline void wait( int tid ) {
        unique_lock<mutex> lock(mtx); // lock mutex
        while(cnt == 0) {
            cv.wait(lock); // unlock mutex and wait for notify
        }
        cnt--;
    }

    inline void producerWait (int tid){
        unique_lock<mutex> lock(mtxE); // lock mutex for producer
        while(emptCnt == 0){
            {
                lock_guard<mutex> lc(pm); // for printing
                cout << "Producer " << tid << " is waiting" << endl;
                //cout << "Producer waiting Empty: " << emptCnt << " Full: " << fullCnt << endl;
            }
            cvE.wait(lock);
        }
        emptCnt--;
    }

    inline void producerNotify (int tid){
        unique_lock<mutex> lock(mtxF);
        fullCnt++;
        {
            lock_guard<mutex> lc(pm);
            cout << "Producer " << tid << " is done" << endl;
            cout << "Empty space: " << emptCnt << " Full space: " << fullCnt << endl;
        }
        cvF.notify_one();
    }

    inline void consumerWait (int tid){
        unique_lock<mutex> lock(mtxF);
        while(fullCnt == 0){
            {
                lock_guard<mutex> lc(pm);
                cout << "Consumer " << tid << " is waiting" << endl;
                //cout << "Consumer waiting Empty: " << emptCnt << " Full: " << fullCnt << endl;
            }
            cvF.wait(lock);
        }
        fullCnt--;
    }

    inline void consumerNotify (int tid){
        unique_lock<mutex> lock(mtxE);
        emptCnt++;
        {
            lock_guard<mutex> lc(pm);
            cout << "Consumer " << tid << " is done" << endl;
            cout << "Empty space: " << emptCnt << " Full space: " << fullCnt << endl;
        }
        cvE.notify_one();
    }

    int getEmpty()
    {
        return emptCnt;
    }
    int getFull()
    {
        return fullCnt;
    }

private:
    condition_variable cv, cvF, cvE;
    int cnt,fullCnt,emptCnt;
    mutex mtx, mtxF, mtxE;
};

class producer{
    public:
    void produce(shared_ptr<Semaphore> semp, int id, int data)
    {
        this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            lock_guard<mutex> lc(m1);
            //printf("Producer %d empty = %d full = %d\n", id, semp->getEmpty(), semp->getFull());
            semp->producerWait(id); // wait for blank space in buffer
            semp->wait(id); // wait for mutex

            q.push(data);

            semp->notify(id);
            semp->producerNotify(id);

            /*cout << "Producer " << id << " is inserted in the buffer " << endl;
            cout << "Empty space: " << semp->getEmpty() << endl;
            cout << "Full space: " << semp->getFull() << endl;*/
        }
    }
};

class consumer{
    public:
    void consume(shared_ptr<Semaphore> semp, int id)
    {
        this_thread::sleep_for(std::chrono::milliseconds(100));
        {
            lock_guard<mutex> lc(m2);
            //printf("Consumer %d empty = %d full = %d\n", id, semp->getEmpty(), semp->getFull());
            semp->consumerWait(id);
            semp->wait(id);

            int a = q.front();
            q.pop();

            semp->notify(id);
            semp->consumerNotify(id);

            /*cout << "Consumer " << id << ": Consumed data " << a << " from buffer" << endl;
            cout << "Empty space: " << semp->getEmpty() << endl;
            cout << "Full space: " << semp->getFull() << endl;*/
        }
    }
};



int main()
{
    cout << "Input incident number: "  ;
    int tot;
    cin >> tot;
    cout << "Input buffer size: " ;
    cin >> n;
    int in = 0;
    shared_ptr<Semaphore> semp = make_shared<Semaphore>();
    //printf("%d %d", semp->getEmpty(), semp->getFull());

    for(int i=0;i<tot;i++)
    {
        node nd;
        cout << "Select your option\n1.Producer\n2.Consumer" << endl;
        cin >> nd.opt;
        if(nd.opt == 1)
        {
            cout << "Producer " ;
            cin >> nd.id;
            cout << ": Data to insert in the buffer";
            cout << "Data: " ;
            cin >> nd.data;
        }
        else
        {
            cout << "Consumer ";
            cin >> nd.id;
        }
        vc.push_back(nd);
        //thread thrd(&producer::produce, producer(), mute, empt);
        //thrd.join();

    }
    for(int i=0;i<tot;i++)
    {
        if(vc[i].opt == 1)
        {
            //cout << "ID --" << vc[i].id << endl;
            th[in] = thread(&producer::produce, producer(), semp, vc[i].id, vc[i].data);
            th[in].detach();
            in++;
        }
        else
        {
            th[in] = thread(&consumer::consume, consumer(), semp, vc[i].id);
            th[in].detach();
            in++;
        }
    }
    //this_thread::sleep_for(std::chrono::milliseconds(1000000000));
    int temp;
    cin >> temp; // exit the program
    return 0;
}
/*
6
3
1
1
10
1
2
20
1
3
30
1
4
40
2
5
2
6
*/

/*
7
3
2
1
2
2
1
3
10
1
4
20
1
5
30
1
6
40
2
7
*/
