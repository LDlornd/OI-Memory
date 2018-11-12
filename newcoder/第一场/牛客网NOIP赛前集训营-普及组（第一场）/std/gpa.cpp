#include <bits/stdc++.h>

using namespace std;

int n;
double gpa[1000];
int sc[1000];

int main()
{
	cin >> n;
	for(int i = 0;i < n;i ++) 
		scanf("%lf %d", &gpa[i], &sc[i]);
	double ans = 0, sum = 0;
	for(int i = 0;i < n;i ++) ans += gpa[i] * sc[i], sum += sc[i];
	printf("%.1f\n", ans / sum);
	return 0;
}
