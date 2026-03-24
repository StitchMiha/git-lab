#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>

using namespace std;

int main() {
    int n = 0;
    
    // Method 1: rand()
    srand(time(0));
    n += (rand() % 10);

    // Method 2: /dev/urandom
    ifstream urandom("/dev/urandom", ios::in | ios::binary);
    char buf;
    urandom.read(&buf, 1);
    n += (unsigned char)buf % 10;

    // Method 3: time()
    n += (time(NULL) % 10);

    // Method 4: std::random_device
    random_device rd;
    n += (rd() % 10);

    // Method 5: getpid()
    n += (getpid() % 10);

    cout << "Your number + 5 is: " << n + 5 << endl;
    return 0;
}
