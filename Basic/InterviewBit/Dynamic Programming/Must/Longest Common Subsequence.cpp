https://www.techiedelight.com/longest-common-subsequence/

int LCSLength(string X, string Y, int m, int n)
{
	// return if we have reached the end of either sequence
	if (m == 0 || n == 0)
		return 0;

	// if last character of X and Y matches
	if (X[m - 1] == Y[n - 1])
		return LCSLength(X, Y, m - 1, n - 1) + 1;

	// else if last character of X and Y don't match
	return max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}

//Bottom Up
int LCSLength(string X, string Y)
{
	int m = X.length(), n = Y.length();

	// lookup table stores solution to already computed sub-problems
	// i.e. lookup[i][j] stores the length of LCS of substring
	// X[0..i-1] and Y[0..j-1]
	int lookup[m + 1][n + 1];

	// first column of the lookup table will be all 0
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;

	// first row of the lookup table will be all 0
	for (int j = 0; j <= n; j++)
		lookup[0][j] = 0;

	// fill the lookup table in bottom-up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// if current character of X and Y matches
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			// else if current character of X and Y don't match
			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}

	// LCS will be last entry in the lookup table
	return lookup[m][n];
}
