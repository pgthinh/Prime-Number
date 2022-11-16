#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void SieveofEratosthenes(int n){
    bool isPrime[100000];
    for(int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= n; j += i)
                 isPrime[j] = false;
        }
    }
}

void SieveofSundaram(int n){
    bool isPrime[100000];
    int totalPrimes = 0, TheseArePrime = 0;
    for (int i = 0; i <= n; i++)
        isPrime[i] = i + 1;
    
    for (int i = 1; i <= n; i++)
        for (int j = i;  j<= (n-i)/(2*i+1); j++)
            isPrime[i + j + 2 * i * j] = 0;
    
    if (n >= 2){
        isPrime[TheseArePrime++] = 2;
        totalPrimes++;
    }
    
    for (int i = 1; i < n; i++)
    if (isPrime[i] != 0){
        isPrime[TheseArePrime++]=i*2+1;
        totalPrimes++;
    }
}

void SieveOfAtkin(int n){
    bool isPrime[100000];
    for (int i = 0; i <= n; i++)
        isPrime[i] = false;
    
    if (n > 2)
        isPrime[2] = true;
    if (n > 3)
        isPrime[3] = true;
    
    for (int x = 1; x * x <= n; x++) {
        for (int y = 1; y * y <= n; y++) {
            
            int temp = (4 * x * x) + (y * y);
            if (temp <= n && (n % 12 == 1 || n % 12 == 5))
                isPrime[n] ^= true;
            
            temp = (3 * x * x) + (y * y);
            if (temp <= n && n % 12 == 7)
                isPrime[n] ^= true;
            
            temp = (3 * x * x) - (y * y);
            if (x > y && temp <= n && n % 12 == 11)
                isPrime[n] ^= true;
        }
    }
    
    for (int i = 5; i * i <= n; i++)
    if (isPrime[i])
        for (int j = i * i; j <= n; j += i * i)
            isPrime[j] = false;
}

int main() {
    ifstream in;
    in.open("Input.txt", ios::in);
    
    int a[1001];
    for (int i = 0; i < 1000; i++)
        in >> a[i];
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 1000; i++)
        SieveOfAtkin(a[i]);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << duration.count();
    in.close();
    return 0;
}
