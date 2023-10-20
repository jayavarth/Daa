#include <iostream>
#include <cstring>
//c++ program
//String matching/pattern matching
//kmp-Knuth Morris Pratt
using namespace std;
//A function to create the lps table
void LPSArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
// A function to compare the text and pattern
void KMP(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	LPSArray(pat, M, lps);
	int i=0,j=0;
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == M) {
			printf("pattern found at index : %d ", i - j);
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}
//Main function
int main()
{
	char txt[] = "Diffusion";
	char pat[] = "fus";
	KMP(pat, txt);
	return 0;
}
