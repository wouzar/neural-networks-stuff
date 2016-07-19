#include <bits/stdc++.h>
using namespace std;

const int ITERATIONS = 150000;
const double RATE = 0.05;

double sigmoid(double x)
{
    return 1.0/(1.0+exp(-x));
}

double table[4][3];

int main()
{
    srand(time(NULL));
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");
    int j;
    double x1,x2,w1,w2,delta,newW1,newW2;
    for (int i=0;i<4;i++)
    {
        inFile>>table[i][0]>>table[i][1]>>table[i][2];
    }
    w1 = (rand()%100)/100.0;
    w2 = (rand()%100)/100.0;
    for (int i=0;i<ITERATIONS;i++)
    {

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
    cout<<setprecision(8);
    outFile<<"W1: "<<w1<<"\nW2: "<<w2<<"\n";
    for (j=0;j<4;j++) outFile<<fixed<<j<<" calculated value: "<<sigmoid(table[j][0]*w1+table[j][1]*w2)<<" expected value: "<<table[j][2]<<endl;
    return 0;
}
