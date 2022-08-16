#include <iostream>
#include <algorithm>

using namespace std;

int a[200000];
int k;
int c = 1;

void convert(int l, int r){
 
	if (l >= r - 1){
		if (c == k)
			return;
	}

	else{
		if (c == k){
    		return;
        }

		int m = (l + r) / 2;

		swap(a[m - 1], a[m]);

		c = c + 2;

		if (c == k){
			return;
        }

		convert(l, m);
		convert(m, r);
	}
}

int main(){
	int n;
	cin >> n;

	cin >> k;

	int i = 0;

	while (i < n){
		a[i] = i + 1;
		i++;
	}

	if (k % 2 == 0 || k > 2 * n - 1){
		cout << "-1" << endl;
    }

	else{
		convert(0, n);

		i = 0;

		while (i < n){
			cout << a[i] << " ";
			i++;
		}

		cout << endl;
	}
}