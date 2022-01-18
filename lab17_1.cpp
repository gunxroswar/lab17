#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void showData(double a[],int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if(i%M == (M-1)) cout << endl;
        else cout << " ";
    }
}
void randData(double a[],int N,int M){
    for(int i = 0; i < N*M; i++){
        a[i] = (rand()%101);
        a[i] = a[i]/100;
    }
}
void findRowSum(const double *A,double *B,int N,int M){
    int j=0;
    double sum=0;
    for(int i=0;i<N*M;i++){
        sum += *(A+i); 
        if((i+1)%M == 0) {
            *(B+j)=sum;sum=0;j++;
        } 
    }
}
void findColSum(const double *A,double *B,int N,int M){
    int j=0;
    for(int i=0;i<M;i++){
        *(B+i)=0;
    }
    for(int i=0;i<N*M;i++){
		*(B+j) += *(A+i);
		j++;
		if((i+1)%M == 0){
			j=0;
		}
    }
}
