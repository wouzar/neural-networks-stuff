#include <bits/stdc++.h>
using namespace std;
const int ITERATIONS = 15000;
const double RATE = 0.05;

double sigmoid(double x)
{
    return 1.0/(1.0+exp(-x));
}

double table[4][3] = {{0,0,0.1},{1,0,1.0},{0,1,0.3},{1,1,1.0}};

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int j;
    double x1,x2,w1,w2,delta,newW1,newW2;
    w1 = (rand()%100)/100.0;
    w2 = (rand()%100)/100.0;
    for (int i=0;i<ITERATIONS;i++)
    {
        cout<<setprecision(8);
        cout<<fixed<<"W1: "<<w1<<" W2: "<<w2<<endl;
        for (int k=0;k<2;k++)
        {
            int j = rand()%4;
            delta = table[j][2] - sigmoid(w1*table[j][0]+w2*table[j][1]);
            newW1 = w1+RATE*delta*sigmoid(w1*table[j][0]+w2*table[j][1])*(1-sigmoid(w1*table[j][0]+w2*table[j][1]))*table[j][0];
            newW2 = w2+RATE*delta*sigmoid(w1*table[j][0]+w2*table[j][1])*(1-sigmoid(w1*table[j][0]+w2*table[j][1]))*table[j][1];
            w1 = newW1;
            w2 = newW2;
        }
    }

    for (j=0;j<4;j++) cout<<fixed<<j<<" : "<<sigmoid(table[j][0]*w1+table[j][1]*w2)<<" exp: "<<table[j][2]<<endl;
    return 0;
}
