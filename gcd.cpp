#pragma once
// –екурсивный алгоритм ≈вклида
int gcd(int a, int b) {
	return b != 0 ? gcd(b, a % b) : a;
}
