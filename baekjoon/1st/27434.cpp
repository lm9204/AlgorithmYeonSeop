// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <complex>

#define ll long long
using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

void fft(vector<cpx> &v, bool inv)
{
	ll S = v.size();

	for (ll i = 1, j = 0; i < S; ++i)
	{
		ll bit = S / 2;

		while (j >= bit)
		{
			j -= bit;
			bit /= 2;
		}
		j += bit;

		if (i < j) swap(v[i], v[j]);
	}

	for (ll k = 1; k < S; k *= 2)
	{
		double angle = ( inv ? PI / k : -PI / k);
		cpx w(cos(angle), sin(angle));

		for (ll i = 0; i < S; i += k * 2)
		{
			cpx z(1, 0);

			for (ll j = 0; j < k; ++j)
			{
				cpx even = v[i + j];
				cpx odd = v[i + j + k] * z;

				v[i + j] = even + odd;
				v[i + j + k] = even - odd;

				z *= w;
			}
		}
	}

	if (inv)
		for (ll i = 0; i < S; ++i) v[i] /= S;
}

vector<ll> mul(vector<ll> &v, vector<ll> &u)
{
	vector<cpx> vc(v.begin(), v.end());
	vector<cpx> uc(u.begin(), u.end());

	ll S = 2;
	while (S < v.size() + u.size()) S *= 2;

	vc.resize(S); fft(vc, false);
	uc.resize(S); fft(uc, false);

	for (ll i = 0; i < S; ++i) vc[i] *= uc[i];
	fft(vc, true);

	vector<ll> w(S);
	for (ll i = 0; i < S; ++i) w[i] = round(vc[i].real());

	return w;
}

vector<ll> res;
int len = 0;

vector<ll> fact(int n)
{
	if (n == 0 || n == 1)
	{
		len += 1;
		return {(ll)1};
	}

	vector<ll> num;
	int x = n;
	while (x > 0)
	{
		num.push_back(x % 10);
		x /= 10;
	}
	len += num.size();
	reverse(num.begin(), num.end());

	vector<ll> a = fact(n - 1);
	return mul(num, a);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	res = fact(n);

	for (int i = 0; i < len - 1; ++i)
		cout << res[i];
	return (0);
}