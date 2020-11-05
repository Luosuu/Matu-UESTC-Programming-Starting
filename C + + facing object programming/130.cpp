void expand(char *s, char *t)
{
	int j = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
		case'\n': t[j++] = '\\';
			t[j++] = 'n';
			break;
		case'\t': t[j++] = '\\';
			t[j++] = 't';
			break;
		default: t[j++] = s[i];
			break;
		}
	}
	t[j] = '\0';
}