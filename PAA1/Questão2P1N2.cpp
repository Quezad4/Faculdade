#include<bits/stdc++.h>
using namespace std;


long long int dp[100];
clock_t t1, t2, t3, t4;

long long int funcDP(long long int N){
	if(N == 1) return dp[N] = 0;
	if(N == 2) return dp[N] = 1;
	if(dp[N] != -1) return dp[N];
	return dp[N] = funcDP(N-1) + funcDP(N-2);
}


long long int f(long long int N){
	if(N == 1) return 0;
	if(N == 2) return 1;
	return f(N-1) + f(N-2);
}






int main(){

	memset(dp,-1,sizeof(dp));
	cout << "Calculo do Decimo Numero de Fibonnaci com DP: " << endl; 
	t1 = clock();
	cout << funcDP(10) << endl;
	t1 = clock() - t1;
	cout << "Tempo gasto: " << (float)t1/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << endl;
	
	cout << "Calculo do Centesimo Numero de Fibonnaci com DP: " << endl; 
	t2 = clock();
	cout << funcDP(93) << endl; // nao coloquei 100 por conta de 94 ja passar o valor de long long int
	t2 = clock() - t2;
	cout << "Tempo gasto: " << (float)t2/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << endl;
	
	cout << "Calculo do Decimo Numero de Fibonnaci sem DP: " << endl; 
	t1 = clock();
	cout << f(10) << endl;
	t1 = clock() - t1;
	cout << "Tempo gasto: " << (float)t1/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << endl;
	
	cout << "Calculo do Quinquagesimo Numero de Fibonnaci sem DP: " << endl; 
	t2 = clock();
	cout << f(50) << endl; // deixei 50 por conta de demorar demais (proximo dos 1 minuto e meio)
	t2 = clock() - t2;
	cout << "Tempo gasto: " << (float)t2/CLOCKS_PER_SEC << " segundos" <<endl;
	cout << endl;
}
