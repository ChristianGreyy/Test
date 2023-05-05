#include <bits/stdc++.h>

using namespace std;

struct Flight{
	string id;
	float cost;
	int cnt;
};

void printID(Flight *a, int vt){
	cout << a[vt].id << " ";
}

void printOneFlight(Flight *a, int vt){
	cout << "Ma: " << a[vt].id << endl;
	cout << "Gia: " << a[vt].cost << endl;
	cout << "So ghe: " << a[vt].cnt << endl;
}

int giave(Flight *a, int n) {
	if(n < 1) return 0;
	else{
		if(a[n-1].cost < 700000) {
			cout << a[n-1].	id << " ";
			return giave(a, n-1) + 1;
		}
		else return giave(a, n-1);
	}
}

int findMin(Flight *a, int l, int r){
	if(l == r){
		return l;
	} else{
		int m = (l+r)/2;
		int lmin = findMin(a, l, m);
		int lmax = findMin(a, m+1, r);
		if(a[lmin].cost < a[lmax].cost){
			return lmin;
		} else{
			return lmax;
		}
	} 
}

void printlist(Flight *a, int k, int x[]){
	for(int i = 0; i < k; i++){
		cout << a[x[i]-1].id << " ";
	}
	cout << endl;
}

void Try(int k, int n, Flight *a, int x[], int start, int size) {
	if(size == k) {
		printlist(a, k, x);
	} else{
		//NHO HON N
		for(int i = start; i <= n; i++){
			x[size] = i;
			Try(k, n, a, x, i+1, size+1);
		}
	}
}

int main(){
	int n;
	n = 6;
	Flight *fl = new Flight[n];
	fl[0] = {"VN001", 2000000, 30};
	fl[1] = {"VN002", 100000, 40};
	fl[2] = {"VN003", 300000, 50};
	fl[3] = {"VN004", 5000000, 40};
	fl[4] = {"VN005", 300000, 20};
	fl[5] = {"VN006", 4000000, 60};
	
	cout << "\nChuyen bay co gia ve > 700000: ";
	if(giave(fl, n) == 0){
		cout << "Khong co chuyen bay nao";
	} 
	cout << "\nChuyen bay co gia ve thap nhat: \n";  
	int idmin = findMin(fl, 0, n-1);
	printOneFlight(fl, idmin);
	
	int k = 4;
	int x[k+1] = {0};
	cout << "Cac phuong an de chon 4 chuyen bay: \n";
	Try(k, n, fl, x, 1, 0);
}
