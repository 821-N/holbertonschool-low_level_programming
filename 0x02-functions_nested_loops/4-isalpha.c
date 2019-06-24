/**
 * _isalpha - Checks if char is alphabetical
 * [a-zA-Z]
 *
 * @c: char
 * Return: 1 if @c is alphabetical, otherwise 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z'));
}
